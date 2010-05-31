/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  norflashcmd.h
 * @brief %jp{NOR Flash-ROM 制御コマンド}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "norflashcmd.h"



#define NORFLASH_DEVTYPE_8BIT			0			/**< 8bit */
#define NORFLASH_DEVTYPE_16BIT			1			/**< 16bit */

#define NORFLASH_BUSWIDTH_8BIT			0			/**< 8bit */
#define NORFLASH_BUSWIDTH_16BIT			1			/**< 16bit */
#define NORFLASH_BUSWIDTH_32BIT			2			/**< 32bit */

#define NORFLASH_TIMEOUT				10000000


typedef struct t_norflash_blockinf
{
	unsigned long	ulSize;
	unsigned long	ulNum;
} T_NORFLASH_BLOCKINF;


typedef struct c_norflash
{
	unsigned long		uwBaseAddr;		/**< ベースアドレス */
	int					iDevType;		/**< 接続タイプ */
	int					iBusWidth;		/**< バス幅タイプ */

	unsigned char		ubDevSize;		/**< デバイスのサイズ */
	unsigned char		ubBlockNum;		/**< ブロック数 */
	T_NORFLASH_BLOCKINF	*pBlockInf;		/**< ブロック情報 */
} C_NORFLASH;


void NorFlash_Reset(C_NORFLASH *self);

/* コンストラクタ */
int NorFlash_Constructor(C_NORFLASH *self, unsigned long uwBaseAddr, int iDevType, int iBusWidth)
{
	unsigned char	ubQry[3];
	int				i;
	
	/* メンバ初期化 */
	self->iDevType   = iDevType;		/**< 接続タイプ */
	self->iBusWidth  = iBusWidth;		/**< バス幅タイプ */
	self->uwBaseAddr = uwBaseAddr;		/**< ベースアドレス */
	self->ubDevSize  = 0;				/**< デバイスのサイズ */
    self->ubBlockNum = 0;				/**< ブロック数 */
    self->pBlockInf  = NULL;			/**< ブロック情報 */
    
    
    /* クエリ要求 */
	switch ( self->iBusWidth )
	{
	case NORFLASH_BUSWIDTH_16BIT:
		{
			volatile unsigned short *puhBaseAddr;
			unsigned short uhData;
			
			/* ベースアドレスキャスト */
			puhBaseAddr = (volatile unsigned short *)self->uwBaseAddr;
			
			/* クエリ要求 */
			puhBaseAddr[0x55] = 0x9898;
			
			/* クエリチェック */
			uhData = puhBaseAddr[0x10];
			ubQry[0] = (unsigned char)uhData;
			uhData = puhBaseAddr[0x11];
			ubQry[1] = (unsigned char)uhData;
			uhData = puhBaseAddr[0x12];
			ubQry[2] = (unsigned char)uhData;
			if ( ubQry[0] != 'Q' || ubQry[1] != 'R' || ubQry[2] != 'Y' )
			{
				return 1;
			}
			
			/* デバイスサイズ */
			uhData = puhBaseAddr[0x27];
			self->ubDevSize = (unsigned char)uhData;
			
			/* 消去ブロック数 */
			uhData = puhBaseAddr[0x2c];
			self->ubBlockNum = (unsigned char)uhData;
			
			/* メモリ確保 */
			if ( self->ubBlockNum > 0 )
			{
				if ( (self->pBlockInf = Memory_Alloc(sizeof(T_NORFLASH_BLOCKINF)*self->ubBlockNum)) == NULL )
				{
					return 1;
				}
				
				for ( i = 0; i < self->ubBlockNum; i++ )
				{
					uhData = puhBaseAddr[0x2d + 4*i + 0];
					self->pBlockInf[i].ulNum  = ((unsigned char)uhData << 0);
					uhData = puhBaseAddr[0x2d + 4*i + 1];
					self->pBlockInf[i].ulNum |= ((unsigned char)uhData << 8);
					
					uhData = puhBaseAddr[0x2d + 4*i + 2];
					self->pBlockInf[i].ulSize  = ((unsigned char)uhData << 0);
					uhData = puhBaseAddr[0x2d + 4*i + 3];
					self->pBlockInf[i].ulSize |= ((unsigned char)uhData << 8);
					
					self->pBlockInf[i].ulSize *= 256;
					if ( self->pBlockInf[i].ulSize == 0 )
					{
						self->pBlockInf[i].ulSize = 128;
					}
					self->pBlockInf[i].ulNum += 1;
				}
			}
		}
		break;
		
	default:
		return 1;
	}
	
	/* デバイスリセット */
	NorFlash_Reset(self);
	
	return 0;
}


/* デストラクタ */
void NorFlash_Destructor(C_NORFLASH *self)
{
	if ( self->pBlockInf )
	{
		Memory_Free(self->pBlockInf);
	}
}

/* デバイスサイズ取得 */
unsigned long NorFlash_GetDevSize(C_NORFLASH *self)
{
	return (1 << self->ubDevSize);
}

/* 消去ブロック数取得 */
int NorFlash_GetBlockNum(C_NORFLASH *self)
{
	return self->ubBlockNum;
}


/* セクタサイズ取得 */
unsigned long  NorFlash_GetSectorSize(C_NORFLASH *self, int iNum)
{
	if ( iNum >= self->ubBlockNum )
	{
		return 0;
	}
	
	return self->pBlockInf[iNum].ulSize;
}

/* セクタ数取得 */
unsigned long  NorFlash_GetSectorNum(C_NORFLASH *self, int iNum)
{
	if ( iNum >= self->ubBlockNum )
	{
		return 0;
	}
	
	return self->pBlockInf[iNum].ulNum;
}


void NorFlash_Reset(C_NORFLASH *self)
{
	/* リセットコマンド発行 */
	switch ( self->iBusWidth )
	{
	case NORFLASH_BUSWIDTH_8BIT:
		*(volatile unsigned char *)self->uwBaseAddr = 0xf0;
		break;
	
	case NORFLASH_BUSWIDTH_16BIT:
		*(volatile unsigned short *)self->uwBaseAddr = 0xf0f0;
		break;

	case NORFLASH_BUSWIDTH_32BIT:
		*(volatile unsigned long *)self->uwBaseAddr = 0xf0f0f0f0;
		break;
	}
}



/* セクタ消去 */
int NorFlash_EraseSector(C_NORFLASH *self, unsigned long uwOffset)
{
	if ( self->ubDevSize == 0 )
	{
		return 1;
	}

	switch ( self->iBusWidth )
	{
	case NORFLASH_BUSWIDTH_16BIT:
		{
			volatile unsigned short *puhBaseAddr;
			unsigned short			uhData[2];
			int						iTimeOut;
			
			/* ベースアドレスキャスト */
			puhBaseAddr = (volatile unsigned short *)self->uwBaseAddr;
			
			/* 消去コマンド発行 */
			puhBaseAddr[0x555]        = 0xaaaa;
			puhBaseAddr[0x2aa]        = 0x5555;
			puhBaseAddr[0x555]        = 0x8080;
			puhBaseAddr[0x555]        = 0xaaaa;
			puhBaseAddr[0x2aa]        = 0x5555;
			puhBaseAddr[uwOffset / 2] = 0x3030;
			
			/* 消去完了待ち */
			iTimeOut = 0;
			do
			{
				if ( iTimeOut++ > NORFLASH_TIMEOUT )
				{
					return 1;
				}
			
				uhData[0] = puhBaseAddr[uwOffset / 2];
				uhData[1] = puhBaseAddr[uwOffset / 2];
			} while ( uhData[0] != 0xffff || uhData[1] != 0xffff );
		}
		break;
	}
	
	return 0;
}


/* 全消去 */
int NorFlash_EraseAll(C_NORFLASH *self)
{
	if ( self->ubDevSize == 0 )
	{
		return 1;
	}
	
	switch ( self->iBusWidth )
	{
	case NORFLASH_BUSWIDTH_8BIT:
		{
			volatile unsigned char	*pubBaseAddr;
			unsigned char			ubData[2];
			int						iTimeOut;
			
			/* ベースアドレスキャスト */
			pubBaseAddr = (volatile unsigned char *)self->uwBaseAddr;
			
			/* 消去コマンド発行 */
			pubBaseAddr[0x555] = 0xaa;
			pubBaseAddr[0x2aa] = 0x55;
			pubBaseAddr[0x555] = 0x80;
			pubBaseAddr[0x555] = 0xaa;
			pubBaseAddr[0x2aa] = 0x55;
			pubBaseAddr[0x555] = 0x10;
			
			/* 消去完了待ち */
			iTimeOut = 0;
			do
			{
				if ( iTimeOut++ > NORFLASH_TIMEOUT )
				{
					return 1;
				}
			
				ubData[0] = pubBaseAddr[0];
				ubData[1] = pubBaseAddr[0];
			} while ( ubData[0] != 0xff || ubData[1] != 0xff );
		}
		break;

	case NORFLASH_BUSWIDTH_16BIT:
		{
			volatile unsigned short *puhBaseAddr;
			unsigned short			uhData[2];
			int						iTimeOut;
			
			/* ベースアドレスキャスト */
			puhBaseAddr = (volatile unsigned short *)self->uwBaseAddr;
			
			/* 消去コマンド発行 */
			puhBaseAddr[0x555] = 0xaaaa;
			puhBaseAddr[0x2aa] = 0x5555;
			puhBaseAddr[0x555] = 0x8080;
			puhBaseAddr[0x555] = 0xaaaa;
			puhBaseAddr[0x2aa] = 0x5555;
			puhBaseAddr[0x555] = 0x1010;
			
			/* 消去完了待ち */
			iTimeOut = 0;
			do
			{
				if ( iTimeOut++ > NORFLASH_TIMEOUT )
				{
					return 1;
				}
			
				uhData[0] = puhBaseAddr[0];
				uhData[1] = puhBaseAddr[0];
			} while ( uhData[0] != 0xffff || uhData[1] != 0xffff );
		}
		break;

	case NORFLASH_BUSWIDTH_32BIT:
		{
			volatile unsigned long *puwBaseAddr;
			unsigned long			uwData[2];
			int						iTimeOut;
			
			/* ベースアドレスキャスト */
			puwBaseAddr = (volatile unsigned long *)self->uwBaseAddr;
			
			/* 消去コマンド発行 */
			puwBaseAddr[0x555] = 0xaaaaaaaa;
			puwBaseAddr[0x2aa] = 0x55555555;
			puwBaseAddr[0x555] = 0x80808080;
			puwBaseAddr[0x555] = 0xaaaaaaaa;
			puwBaseAddr[0x2aa] = 0x55555555;
			puwBaseAddr[0x555] = 0x10101010;
			
			/* 消去完了待ち */
			iTimeOut = 0;
			do
			{
				if ( iTimeOut++ > NORFLASH_TIMEOUT )
				{
					return 1;
				}
			
				uwData[0] = puwBaseAddr[0];
				uwData[1] = puwBaseAddr[0];
			} while ( uwData[0] != 0xffffffff || uwData[1] != 0xffffffff );
		}
		break;
		
	default:
		return 1;
	}
	
	return 0;
}




/* 16bit書込み */
int NorFlash_Write16(C_NORFLASH *self, unsigned long uwOffset, unsigned short uhWriteData)
{
	volatile unsigned short *puhBaseAddr;
	unsigned short			uhData[2];
	int						iTimeOut;
			
	/* ベースアドレスキャスト */
	puhBaseAddr = (volatile unsigned short *)self->uwBaseAddr;
			
	/* 書込みコマンド発行 */
	puhBaseAddr[0x555]        = 0xaaaa;
	puhBaseAddr[0x2aa]        = 0x5555;
	puhBaseAddr[0x555]        = 0xa0a0;
	puhBaseAddr[uwOffset / 2] = uhWriteData;

	/* 書込み完了待ち */
	iTimeOut = 0;
	do
	{
		if ( iTimeOut++ > NORFLASH_TIMEOUT )
		{
			return 1;
		}
			
		uhData[0] = puhBaseAddr[uwOffset / 2];
		uhData[1] = puhBaseAddr[uwOffset / 2];
	} while ( uhData[0] != uhWriteData || uhData[1] != uhWriteData );
	
	return 0;
}


/* 書込み */
int NorFlash_Write(C_NORFLASH *self, unsigned long uwOffset, const unsigned long *puwWriteData)
{
	if ( self->ubDevSize == 0 )
	{
		return 1;
	}

	switch ( self->iBusWidth )
	{
	case NORFLASH_BUSWIDTH_16BIT:
		{
			unsigned short	uhData[2];
			
			uhData[0] = *((unsigned short *)puwWriteData + 0);
			uhData[1] = *((unsigned short *)puwWriteData + 1);

			if ( NorFlash_Write16(self, uwOffset + 0, uhData[0]) != 0 )
			{
				return 1;
			}

			if ( NorFlash_Write16(self, uwOffset + 2, uhData[1]) != 0 )
			{
				return 1;
			}
			
		}
		break;
	}
	
	return 0;
}






void NorFlashCmd_PrintUsage(void);


int NorFlashCmd_Main(int argc, char *argv[])
{
	C_NORFLASH		NorFlash;
	unsigned long	uwBaseAddr;
	unsigned long	uwOffset;
	unsigned long	uwData;
	int				iDevType  = NORFLASH_DEVTYPE_16BIT;
	int				iBusWidth = NORFLASH_BUSWIDTH_16BIT;
	int				iCmdArg;
	int				i;
	
	/* オプション解析 */
	for ( i = 1; i < argc; i++ )
	{
		if ( argv[i][0] != '-' )
		{
			break;
		}
		
		if ( strcmp(&argv[i][1], "b8") == 0 )
		{
			iBusWidth = NORFLASH_BUSWIDTH_8BIT;
		}
		else if ( strcmp(&argv[i][1], "b16") == 0 )
		{
			iBusWidth = NORFLASH_BUSWIDTH_16BIT;
		}
		else if ( strcmp(&argv[i][1], "b32") == 0 )
		{
			iBusWidth = NORFLASH_BUSWIDTH_32BIT;
		}
		else if ( strcmp(&argv[i][1], "d8") == 0 )
		{
			iDevType = NORFLASH_DEVTYPE_8BIT;
		}
		else if ( strcmp(&argv[i][1], "d16") == 0 )
		{
			iDevType = NORFLASH_DEVTYPE_16BIT;
		}
		else
		{
			StdIo_PrintFormat("unknown option %s\n", argv[i]);
		}
	}
	iCmdArg = i;
	
	if ( argc < iCmdArg + 2 )
	{
		NorFlashCmd_PrintUsage();
		return 1;
	}


	/* ベースアドレス取得 */
	uwBaseAddr = strtoul(argv[iCmdArg + 1], NULL, 0);
	
	/* 制御クラス生成 */
	if ( NorFlash_Constructor(&NorFlash, uwBaseAddr, iDevType, iBusWidth) != 0 )
	{
		StdIo_PrintFormat("0x%08lx is not NOR Flash-ROM\n", uwBaseAddr);
		return 1;
	}
	
	if ( strcmp(argv[iCmdArg], "info") == 0 )
	{
	    /* 情報表示 */
		StdIo_PrintFormat("memory size     : %lu bytes\n", NorFlash_GetDevSize(&NorFlash));
		StdIo_PrintFormat("erase block num : %d\n", NorFlash_GetBlockNum(&NorFlash));
		for ( i = 0; i < NorFlash_GetBlockNum(&NorFlash); i++ )
		{
			StdIo_PrintFormat("block %d : %lu bytes x %lu\n",  i, NorFlash_GetSectorSize(&NorFlash, i), NorFlash_GetSectorNum(&NorFlash, i));
		}
	}
	else if ( strcmp(argv[iCmdArg], "erase-all") == 0 )
	{
		/* 全消去 */
		StdIo_PrintFormat("erase-all ");
		if ( NorFlash_EraseAll(&NorFlash) == 0 )
		{
			StdIo_PutString("OK\n");
		}
		else
		{
			StdIo_PutString("NG\n");
		}
	}
	else if ( strcmp(argv[iCmdArg], "erase") == 0 && argc > iCmdArg + 2 )
	{
		/* セクタ消去 */
		uwOffset = strtoul(argv[iCmdArg + 2], NULL, 0);
		StdIo_PrintFormat("erase 0x%08lx  ",  uwOffset);
		if ( NorFlash_EraseSector(&NorFlash, uwOffset) == 0 )
		{
			StdIo_PutString("OK\n");
		}
		else
		{
			StdIo_PutString("NG\n");
		}
	}
	else if ( strcmp(argv[iCmdArg], "write") == 0 && argc > iCmdArg + 3 )
	{
		/* 書込み */
		uwOffset = strtoul(argv[iCmdArg + 2], NULL, 0);
		uwData   = strtoul(argv[iCmdArg + 3], NULL, 0);
		
		StdIo_PrintFormat("write 0x%08lx <= 0x%08lx  ",  uwOffset, uwData);
		if ( NorFlash_Write(&NorFlash, uwOffset, &uwData) == 0 )
		{
			StdIo_PutString("OK\n");
		}
		else
		{
			StdIo_PutString("NG\n");
		}
	}
	else if ( strcmp(argv[iCmdArg], "write-file") == 0 && argc > iCmdArg + 3 )
	{
		/* ファイル書込み */

		HANDLE			hFile;
		unsigned long	ulBuf;
		unsigned long	ulSize = 0;
		
		uwOffset = strtoul(argv[iCmdArg + 2], NULL, 0);
		
		if ( (hFile = File_Open(argv[iCmdArg + 3], FILE_OPEN_READ | FILE_OPEN_EXIST)) == HANDLE_NULL )
		{
			StdIo_PrintFormat("open error : %s\n", argv[iCmdArg + 3]);
		}
		else
		{
			StdIo_PrintFormat("file write : 0x%08lx <= %s\n",  uwOffset, argv[iCmdArg + 3]);
			
			for ( ; ; )
			{
				ulBuf = 0xffffffff;
				
				if ( File_Read(hFile, &ulBuf, 4) <= 0 )
				{
					break;
				}
				
				if ( NorFlash_Write(&NorFlash, uwOffset, &ulBuf) != 0 )
				{
					StdIo_PrintFormat("write error : 0x%08lx\n", uwOffset);
					break;
				}
				
				uwOffset += 4;
				ulSize   += 4;
			}
			StdIo_PrintFormat("write %ld bytes OK\n", ulSize);
			
			File_Close(hFile);
		}
	}
	else
	{
		StdIo_PutString("parameter error\n");
	}
	
	
	/* 制御クラス削除 */
	NorFlash_Destructor(&NorFlash);
	
	
	return 0;
}



void NorFlashCmd_PrintUsage(void)
{
	StdIo_PrintFormat(
			"<usage>\n"
			"  norflash [options] info       <base_address>\n"
			"  norflash [options] erase      <base_address> <sector_offset>\n"
			"  norflash [options] erase-all  <base_address>\n"
			"  norflash [options] write      <base_address> <offset> <data>\n"
			"  norflash [options] write-file <base_address> <offset> <filename>\n"
		);
}



/* end of file */
