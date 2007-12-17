/**
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550hal.h
 * @brief %jp{16550用ハードウェアアクセス層}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pc16550hal_local_h__
#define __HOS__pc16550hal_local_h__


#include "pc16550hal.h"
#include "system/sysapi/sysapi.h"


/* レジスタアドレスの算出 */
#define PC16550HAL_REG_ADDR(self, offset)	((volatile unsigned char *)(self)->pRegBase + ((offset) << (self)->uiRegStep))

/* レジスタ読み書き */
/*
#define PC16550HAL_WRITE_REG(addr, data)	do { *(volatile unsigned char *)(addr) = (unsigned char)(data); } while (0)
#define PC16550HAL_READ_REG(addr)			(*(volatile unsigned char *)(addr))
*/
#define PC16550HAL_WRITE_REG(addr, data)	SysIo_OutPortB((addr), (data))
#define PC16550HAL_READ_REG(addr)			SysIo_InPortB((addr))


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


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550hal_local_h__ */


/* end of file */
