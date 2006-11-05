/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scihdl.c
 * @brief %jp{SCI用ハードウェアアクセス層}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scihal.h"


#define SCIHAL_REG_SMR(self)	((volatile unsigned char*)(self)->pRegBase + 0)
#define SCIHAL_REG_BRR(self)	((volatile unsigned char*)(self)->pRegBase + 1)
#define SCIHAL_REG_SCR(self)	((volatile unsigned char*)(self)->pRegBase + 2)
#define SCIHAL_REG_TDR(self)	((volatile unsigned char*)(self)->pRegBase + 3)
#define SCIHAL_REG_SSR(self)	((volatile unsigned char*)(self)->pRegBase + 4)
#define SCIHAL_REG_RDR(self)	((volatile unsigned char*)(self)->pRegBase + 5)


/** コンストラクタ */
void SciHal_Create(C_SCIHAL *self, void *pRegAddr, long lSysClock)
{
	self->pRegBase  = pRegAddr;
	self->lSysClock = lSysClock;
}

/** デストラクタ */
void SciHal_Delete(C_SCIHAL *self)
{
}

/* %jp{SCIの初期化} */
void SciHal_Setup(C_SCIHAL *self, long bps)
{
	*SCIHAL_REG_SCR(self) = 0;
	*SCIHAL_REG_SMR(self) = 0;
	*SCIHAL_REG_BRR(self) = self->lSysClock / (32 * bps) - 1;		/* %jp{ボーレート設定} */
	*SCIHAL_REG_SCR(self) = 0x30;									/* %jp{送受信許可} */
}

/* %jp{SCIの停止} */
void SciHal_Stop(C_SCIHAL *self)
{
	*SCIHAL_REG_SCR(self) = 0;										/* %jp{停止} */
}


/* %jp{1文字送信} */
int SciHal_SendChar(C_SCIHAL *self, int c)
{
	/* 送信可能かチェック */
	if ( !(*SCIHAL_REG_SSR(self) & 0x80) )
	{
		return -1;
	}
	
	*SCIHAL_REG_TDR(self) = (unsigned char)c;
	
	*SCIHAL_REG_SSR(self) &= 0x7f;

	return c;
}


/* %jp{1文字受信} */
int SciHal_RecvChar(C_SCIHAL *self)
{
	unsigned char ssr;
	int c;
	
	ssr = *SCIHAL_REG_SSR(self);
	
	/* エラーチェック */
	if ( ssr & 0x38 )
	{
		*SCIHAL_REG_SSR(self) = (ssr & ~0x38);
		return -1;
	}
	
	/* 受信データチェック */
	if ( !(ssr & 0x40) )
	{
		return -1;
	}
	
	/* 受信 */
	c = *SCIHAL_REG_RDR(self);
	
	*SCIHAL_REG_SSR(self) &= ~0x40;
	
	return c;
}


/** %jp{割り込み許可} */
void SciHal_EnableInterrupt(C_SCIHAL *self, unsigned char flag)
{
	unsigned char scr;

	scr   = *SCIHAL_REG_SCR(self);
	scr  &= ~(SCIHAL_INT_TIE | SCIHAL_INT_RIE| SCIHAL_INT_TEIE);
	flag &= (SCIHAL_INT_TIE | SCIHAL_INT_RIE | SCIHAL_INT_TEIE);
	scr  |= flag;
	*SCIHAL_REG_SCR(self) = scr;
}


/* end of file */
