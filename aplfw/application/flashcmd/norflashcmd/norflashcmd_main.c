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
#include "filelist.h"


typedef struct t_norflashcmd_blockinf
{
	unsigned long	ulSize;
	unsigned long	ulNum;
} T_NORFLASHCMD_BLOCKINF;


int NorFlashCmd_Main(int argc, char *argv[])
{
	T_NORFLASHCMD_BLOCKINF	BlockInf;
	unsigned long			uwAddr;
	unsigned char			ubQry[3];
	unsigned char			ubDevSize;
	unsigned char			ubBlockNum;
	int						i;
	
	if ( argc < 2 )
	{
		return 1;
	}

	uwAddr = strtoul(argv[1], 0, NULL);
	
	{
		unsigned short uhData;
		
		/* クエリ要求 */
		*(unsigned short *)(uwAddr + 0xaa) = 0x0098;
		
		/* クエリチェック */
		uhData = *(unsigned short *)(uwAddr + 0x10*2);
		ubQry[0] = uhData;
		uhData = *(unsigned short *)(uwAddr + 0x11*2);
		ubQry[1] = uhData;
		uhData = *(unsigned short *)(uwAddr + 0x12*2);
		ubQry[2] = uhData;
		if ( ubQry[0] != 'Q' || ubQry[1] != 'R' || ubQry[2] != 'Y' )
		{
			StdIo_PrintFormat("%08lx is not NOR Flash-ROM\n", uwAddr);
			return 1;
		}

		/* デバイスサイズ */
		uhData = *(unsigned short *)(uwAddr + 0x27*2);
		ubDevSize = uhData;

		/* 消去ブロック数 */
		uhData = *(unsigned short *)(uwAddr + 0x2c*2);
		ubBlockNum = uhData;

		StdIo_PrintFormat("memory size     : %lu bytes\n", (unsigned long)(1 << ubDevSize));
		StdIo_PrintFormat("erase block num : %d\n",  (int)ubBlockNum);
		
		for ( i = 0; i < ubBlockNum; i++ )
		{
			uhData = *(unsigned short *)(uwAddr + (0x2d + 4*i + 0)*2);
			BlockInf.ulNum  = ((unsigned char)uhData << 0);
			uhData = *(unsigned short *)(uwAddr + (0x2d + 4*i + 1)*2);
			BlockInf.ulNum |= ((unsigned char)uhData << 8);

			uhData = *(unsigned short *)(uwAddr + (0x2d + 4*i + 2)*2);
			BlockInf.ulSize  = ((unsigned char)uhData << 0);
			uhData = *(unsigned short *)(uwAddr + (0x2d + 4*i + 3)*2);
			BlockInf.ulSize |= ((unsigned char)uhData << 8);
			
			BlockInf.ulSize *= 256;
			if ( BlockInf.ulSize == 0 )
			{
				BlockInf.ulSize = 128;
			}
			BlockInf.ulNum += 1;
			
			StdIo_PrintFormat("block %d : %lu bytes x %lu\n",  i, BlockInf.ulSize, BlockInf.ulNum);
		}
		
	}		
		
	
	return 0;
}


/* end of file */
