/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ne2000hdl.c
 * @brief %jp{NE2000互換Ether用ハードウェアアクセス層}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "ne2000hal.h"


/* レジスタアクセス定義 */
#define NE2000HAL_WRITE_REG(self, addr, data)		do { (self)->pubRegBase[(addr)] = (data); } while(0)
#define NE2000HAL_READ_REG(self, addr)				((self)->pubRegBase[(addr)])


/* レジスタ定義 */
#define NE2000HAL_REG_CR		0x00
#define NE2000HAL_REG_DMA		0x10
#define NE2000HAL_REG_RESET		0x18

#define NE2000HAL_REG_CLDA0		0x01
#define NE2000HAL_REG_CLDA1		0x02
#define NE2000HAL_REG_TSR		0x04
#define NE2000HAL_REG_NCR		0x05
#define NE2000HAL_REG_FIFO		0x06
#define NE2000HAL_REG_CRDA0		0x08
#define NE2000HAL_REG_CRDA1		0x09
#define NE2000HAL_REG_RSR		0x0c
#define NE2000HAL_REG_CNTR0		0x0d
#define NE2000HAL_REG_CNTR1		0x0e
#define NE2000HAL_REG_CNTR2		0x0f

#define NE2000HAL_REG_PSTART	0x01
#define NE2000HAL_REG_PSTOP		0x02
#define NE2000HAL_REG_BNRY		0x03
#define NE2000HAL_REG_TPSR		0x04
#define NE2000HAL_REG_TBCR0		0x05
#define NE2000HAL_REG_TBCR1		0x06
#define NE2000HAL_REG_ISR		0x07
#define NE2000HAL_REG_RSAR0		0x08
#define NE2000HAL_REG_RSAR1		0x09
#define NE2000HAL_REG_RBCR0		0x0a
#define NE2000HAL_REG_RBCR1		0x0b
#define NE2000HAL_REG_RCR		0x0c
#define NE2000HAL_REG_TCR		0x0d
#define NE2000HAL_REG_DCR		0x0e
#define NE2000HAL_REG_IMR		0x0f

#define NE2000HAL_REG_PAR0		0x01
#define NE2000HAL_REG_PAR1		0x02
#define NE2000HAL_REG_PAR2		0x03
#define NE2000HAL_REG_PAR3		0x04
#define NE2000HAL_REG_PAR4		0x05
#define NE2000HAL_REG_PAR5		0x06
#define NE2000HAL_REG_CURR		0x07
#define NE2000HAL_REG_MAR0		0x08
#define NE2000HAL_REG_MAR1		0x09
#define NE2000HAL_REG_MAR2		0x0a
#define NE2000HAL_REG_MAR3		0x0b
#define NE2000HAL_REG_MAR4		0x0c
#define NE2000HAL_REG_MAR5		0x0d
#define NE2000HAL_REG_MAR6		0x0e
#define NE2000HAL_REG_MAR7		0x0f


/* ローカル関数 */
void Ne2000Hal_ReadPhysicalAddr(C_NE2000HAL *self, unsigned char ubPhysicalAddr[6]);					/* %jp{物理アドレスの読み出し} */
void Ne2000Hal_ReadMem(C_NE2000HAL *self, void *pBuf, int iAddr, int iSize);							/* %jp{リモートDMA読み出し} */
void Ne2000Hal_WriteMem(C_NE2000HAL *self, const void *pData, int iAddr, int iDataSize, int iDmySize);	/* %jp{リモートDMA書き込み} */


/** コンストラクタ */
void Ne2000Hal_Create(C_NE2000HAL *self, void *pRegAddr)
{
	self->pubRegBase = (volatile unsigned char *)pRegAddr;
	memset(self->ubPhysicalAddr, 0, sizeof(self->ubPhysicalAddr));
}

/** デストラクタ */
void Ne2000Hal_Delete(C_NE2000HAL *self)
{
}


/** %jp{初期設定} */
void Ne2000Hal_Setup(C_NE2000HAL *self)
{
	/* %jp{ソフトウェアリセット} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RESET, NE2000HAL_READ_REG(self, NE2000HAL_REG_RESET));
	
	/* %jp{CR初期化} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x21);
	
	/* %jp{DCR設定} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_DCR, 0xc2);
	
	/* %jp{リモートDMA転送サイズクリア} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RBCR0, 0);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RBCR1, 0);
	
	/* %jp{受信モニタモードにする} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RCR, 0x20);
	
	/* %jp{送信をループバックモードにする} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_TCR, 0x02);
	
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_TPSR, 0x40);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_PSTART, 0x46);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_BNRY, 0x46);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_PSTOP, 0x60);
	
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_IMR, 0x00);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_ISR, 0xff);
	
	/* %jp{物理アドレス読み出し} */
	Ne2000Hal_ReadPhysicalAddr(self, self->ubPhysicalAddr);
	
	/* %jp{物理アドレス設定} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x61);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_PAR0, self->ubPhysicalAddr[0]);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_PAR1, self->ubPhysicalAddr[1]);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_PAR2, self->ubPhysicalAddr[2]);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_PAR3, self->ubPhysicalAddr[3]);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_PAR4, self->ubPhysicalAddr[4]);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_PAR5, self->ubPhysicalAddr[5]);
	
	/* %jp{受信パケット格納アドレス設定} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CURR, 0x47);
	
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x21);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RCR, 0x04);
	
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x22);
	
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_TCR, 0);
}


/* 停止 */
void Ne2000Hal_Stop(C_NE2000HAL *self)
{
}


/** %jp{物理アドレスの読み出し} */
void Ne2000Hal_ReadPhysicalAddr(C_NE2000HAL *self, unsigned char ubPhysicalAddr[6])
{
	unsigned char ubDmy;
	int i;
	
	/* %jp{転送バイト数設定(12バイト)} */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RBCR0, 12);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RBCR1, 0);
	
	/* DMA転送アドレス */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RSAR0, 0);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RSAR1, 0);
	
	/* DMA開始 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x0a);
	
	/* 奇数番地を読み飛ばす */
	for ( i = 0; i < 6; i++ )
	{
		ubPhysicalAddr[i] = NE2000HAL_READ_REG(self, NE2000HAL_REG_DMA);
		ubDmy             = NE2000HAL_READ_REG(self, NE2000HAL_REG_DMA);
	}
}


/* リモートDMA読み出し */
void Ne2000Hal_ReadMem(C_NE2000HAL *self, void *pBuf, int iAddr, int iSize)
{
	unsigned char *pubBuf;
	int i;
	
	pubBuf = (unsigned char *)pBuf;
	
	/* ページ0 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x22);
	
	/* DMAサイズ設定 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RBCR0, (iSize >> 0) & 0xff);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RBCR1, (iSize >> 8) & 0xff);
	
	/* DMAアドレス設定 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RSAR0, (iAddr >> 0) & 0xff);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RSAR1, (iAddr >> 8) & 0xff);
	
	/* DMA開始 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x0a);
	
	/* データ取り出し */
	for ( i = 0; i < iSize; i++ )
	{
		*pubBuf++ = NE2000HAL_READ_REG(self, NE2000HAL_REG_DMA);
	}
}

/* リモートDMA書き込み */
void Ne2000Hal_WriteMem(C_NE2000HAL *self, const void *pData, int iAddr, int iDataSize, int iDmySize)
{
	const unsigned char *pubData;
	int iSize;
	int i;
	
	pubData = (unsigned char *)pData;
	
	/* ページ0 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x22);
	
	/* ISRDMAビットクリア */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_ISR, 0x40);
	
	/* DMAサイズ設定 */
	iSize = iDataSize + iDmySize;
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RBCR0, (iSize >> 0) & 0xff);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RBCR1, (iSize >> 8) & 0xff);
	
	/* DMAアドレス設定 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RSAR0, (iAddr >> 0) & 0xff);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_RSAR1, (iAddr >> 8) & 0xff);
	
	/* DMA開始 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x12);
	
	/* データ書き込み */
	for ( i = 0; i < iDataSize; i++ )
	{
		NE2000HAL_WRITE_REG(self, NE2000HAL_REG_DMA, *pubData++);
	}
	
	/* ダミーデータ書き込み */
	for ( i = 0; i < iDmySize; i++ )
	{
		NE2000HAL_WRITE_REG(self, NE2000HAL_REG_DMA, 0);
	}
	
	/* DMA完了待ち */
	while ( !(NE2000HAL_READ_REG(self, NE2000HAL_REG_ISR) & 0x40) )
		;
}



/* %jp{次のページアドレス取得} */
unsigned char Ne2000Hal_GetNextPage(C_NE2000HAL *self, unsigned char ubPtr)
{
	if ( ubPtr >= 0x5f )
	{
		return 0x46;
	}
	return ubPtr + 1;
}


/* パケット受信 */
int Ne2000Hal_Recv(C_NE2000HAL *self, void *pBuf, int iSize)
{
	unsigned char *pubBuf;
	unsigned char ubBnry;
	unsigned char ubCurr;
	unsigned char ubRead;
	unsigned char ubHeader[4];
	int           iReadAddr;
	int           iPacketSize;
	int           iPStopSize;
	
	pubBuf = (unsigned char *)pBuf;
	
	/* BNRY読み出し */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x22);
	ubBnry = NE2000HAL_READ_REG(self, NE2000HAL_REG_BNRY);
	
	/* CURR読み出し */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x42);
	ubCurr = NE2000HAL_READ_REG(self, NE2000HAL_REG_CURR);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x22);
	
	/* 読み出し位置 */
	ubRead = Ne2000Hal_GetNextPage(self, ubBnry);
	
	/* データ量チェック */
	if ( ubRead == ubCurr )
	{
		return 0;
	}
	
	iReadAddr = ubRead * 256;
	
	/* ヘッダ読み出し */
	Ne2000Hal_ReadMem(self, ubHeader, iReadAddr, 4);
	iReadAddr += 4;
	
	/* ヘッダからサイズ読み出し */
	iPacketSize = ubHeader[2] + (ubHeader[3] << 8);
	
	/* 折り返し位置までのサイズ */
	iPStopSize = 0x6000 - iReadAddr;
	
	if ( (ubHeader[0] & 1) && iPacketSize <= iSize )	/* 正常なら */
	{
		if ( iPacketSize <= iPStopSize )
		{
			Ne2000Hal_ReadMem(self, pubBuf, iReadAddr, iPacketSize);
			iReadAddr += iPacketSize - 1;
		}
		else
		{
			Ne2000Hal_ReadMem(self, pubBuf, iReadAddr, iPStopSize);
			pubBuf    += iPStopSize;
			iReadAddr  = 0x4000;
			Ne2000Hal_ReadMem(self, pubBuf, iReadAddr, iPacketSize - iPStopSize);
			iReadAddr += (iPacketSize - iPStopSize) - 1;
		}
	}
	else	/* 異常なら */
	{
		/* 読み捨ててポインタのみ進める */
		if ( iPacketSize <= iPStopSize )
		{
			iReadAddr += iPacketSize - 1;
		}
		else
		{
			iReadAddr = 0x4000 + (iPacketSize - iPStopSize) - 1;
		}
		iPacketSize = 0;
	}
	
	/* ポインタを更新 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_BNRY, ((iReadAddr >> 8) & 0xff));
	
	return iPacketSize;
}



/* パケット送信 */
int Ne2000Hal_Send(C_NE2000HAL *self, const void *pData, int iSize)
{
	int iDmySize;
	int iSendSize;
	
	/* TXPビットチェック */
	if ( NE2000HAL_READ_REG(self, NE2000HAL_REG_CR) & 0x04 )
	{
		return 0;
	}
	
	if ( iSize >= 60 )
	{
		iDmySize  = 0;				/* ダミーなし */
		iSendSize = iSize + 4;		/* FCSのサイズを加算 */
	}
	else
	{
		iDmySize  = 60 - iSize;		/* セキュリティーの為ゴミを乗せずに60バイトまで0埋めする */
		iSendSize = 64;				/* 送信サイズ */
	}
	
	/* メモリ書き込み */
	Ne2000Hal_WriteMem(self, pData, 0x4000, iSize, iDmySize);
	
	/* 送信サイズ設定 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x22);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_TBCR0, (iSendSize >> 0) & 0xff);
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_TBCR1, (iSendSize >> 8) & 0xff);
	
	/* 送信開始 */
	NE2000HAL_WRITE_REG(self, NE2000HAL_REG_CR, 0x26);

	return iSendSize;
}


/* end of file */
