/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scihdl.c
 * @brief %jp{PC16550用ハードウェアアクセス層}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550hal.h"

/* レジスタアドレスの算出 */
#define PC16550HAL_REG_ADDR(self, offset)	((volatile unsigned char *)(self)->pRegBase + ((offset) << (self)->uiRegStep))

/* レジスタ読み書き */
#define PC16550HAL_WRITE_REG(addr, data)	do { *(volatile unsigned char *)(addr) = (unsigned char)(data); } while (0)
#define PC16550HAL_READ_REG(addr)			(*(volatile unsigned char *)(addr))

/* PC16550レジスタ操作 */
#define PC16550HAL_READ_RBR(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 0))
#define PC16550HAL_WRITE_THR(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 0), (x))
#define PC16550HAL_READ_IER(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 1))
#define PC16550HAL_WRITE_IER(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 1), (x))
#define PC16550HAL_READ_IIR(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 2))
#define PC16550HAL_WRITE_FCR(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 2), (x))
#define PC16550HAL_READ_LCR(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 3))
#define PC16550HAL_WRITE_LCR(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 3), (x))
#define PC16550HAL_READ_MCR(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 4))
#define PC16550HAL_WRITE_MCR(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 4), (x))
#define PC16550HAL_READ_LSR(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 5))
#define PC16550HAL_WRITE_LSR(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 5), (x))
#define PC16550HAL_READ_MSR(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 6))
#define PC16550HAL_WRITE_MSR(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 6), (x))
#define PC16550HAL_READ_SCR(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 7))
#define PC16550HAL_WRITE_SCR(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 7), (x))
#define PC16550HAL_READ_DLL(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 0))
#define PC16550HAL_WRITE_DLL(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 0), (x))
#define PC16550HAL_READ_DLM(self)		PC16550HAL_READ_REG(PC16550HAL_REG_ADDR((self), 1))
#define PC16550HAL_WRITE_DLM(self, x)	PC16550HAL_WRITE_REG(PC16550HAL_REG_ADDR((self), 1), (x))

#define PC16550HAL_TXFIFO_SIZE		16		/* 送信FIFOのサイズ */



/** コンストラクタ */
void Pc16550Hal_Create(C_PC16550HAL *self, void *pRegAddr, unsigned int uiRegStep, unsigned long ulBaseClock)
{
	self->pRegBase    = pRegAddr;
	self->uiRegStep   = uiRegStep;
	self->ulBaseClock = ulBaseClock;
}


/** デストラクタ */
void Pc16550Hal_Delete(C_PC16550HAL *self)
{
}


/** %jp{PC16550の初期化} */
void Pc16550Hal_Setup(C_PC16550HAL *self)
{
	self->iTxFree = PC16550HAL_TXFIFO_SIZE;
	PC16550HAL_WRITE_IER(self, 0x00);		/* 割込み全停止 */
	PC16550HAL_WRITE_LCR(self, 0x03);		/* 8bit,ノンパリ,ストップビット1bit*/
	PC16550HAL_WRITE_MCR(self, 0x03);		/* DTR/RTS ON */
	PC16550HAL_WRITE_FCR(self, 0xc1);		/* FIFO 有効化/トリガ14 */
	PC16550HAL_WRITE_FCR(self, 0xc7);		/* FIFO リセット */
}

/* %jp{PC16550の停止} */
void Pc16550Hal_Stop(C_PC16550HAL *self)
{
	Pc16550Hal_EnableInterrupt(self, 0);
}


/* %jp{BPS設定} */
void Pc16550Hal_SetSpeed(C_PC16550HAL *self, unsigned long ulSpeed)
{
	unsigned short uhDiv;

	uhDiv = (unsigned short)(((self->ulBaseClock / 16) + (ulSpeed / 2)) / ulSpeed);
	
	PC16550HAL_WRITE_LCR(self, PC16550HAL_READ_LCR(self) | 0x80);
	PC16550HAL_WRITE_DLL(self, uhDiv & 0xff);
	PC16550HAL_WRITE_DLM(self, uhDiv >> 8);
	PC16550HAL_WRITE_LCR(self, PC16550HAL_READ_LCR(self) & 0x7f);
}


/* %jp{1文字送信} */
int Pc16550Hal_SendChar(C_PC16550HAL *self, int c)
{
	if ( PC16550HAL_READ_LSR(self) & 0x20  )	
	{
		self->iTxFree = PC16550HAL_TXFIFO_SIZE;
	}

	/* 送信可能かチェック */
	if ( self->iTxFree <= 0 )
	{
		return -1;
	}
	self->iTxFree--;
	
	PC16550HAL_WRITE_THR(self, c);

	return (unsigned char)c;
}


/* %jp{1文字受信} */
int Pc16550Hal_RecvChar(C_PC16550HAL *self)
{
	if ( !(PC16550HAL_READ_LSR(self) & 0x01) )
	{
		return -1;
	}

	return PC16550HAL_READ_RBR(self);
}


/** %jp{割り込み許可} */
void Pc16550Hal_EnableInterrupt(C_PC16550HAL *self, unsigned char flag)
{
	PC16550HAL_WRITE_IER(self, flag);
}


/** %jp{割込み状態取得} */
int Pc16550Hal_GetInterruptStatus(C_PC16550HAL *self)
{
	return (PC16550HAL_READ_IIR(self) & 0x0f);
}


int Pc16550Hal_GetStatus(C_PC16550HAL *self)
{
	return PC16550HAL_READ_LSR(self);
}	




/* end of file */
