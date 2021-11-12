/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  uart.h
 * @brief %jp{UARTへの出力}%en{UART device driver}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __uart_h__
#define __uart_h__

#define UART_RHR     (0x00)   /* %jp{受信レジスタ}        */
#define UART_THR     (0x00)   /* %jp{送信レジスタ}        */
#define UART_INTR    (0x01)   /* %jp{割り込み許可}        */
#define UART_FIFO    (0x02)   /* %jp{FIFO}                */
#define UART_IIR     (0x02)   /* %jp{割り込みID}          */
#define UART_LCTRL   (0x03)   /* %jp{ラインコントロール}  */
#define UART_MCTRL   (0x04)   /* %jp{モデムコントロール}  */
#define UART_LSR     (0x05)   /* %jp{ラインステータス}    */
#define UART_MSR     (0x06)   /* %jp{モデムステータス}    */

/*
 *  %jp{割り込み関連}
 */
#define UART_IIR_NO_INT	(0x01)	/* %jp{割り込み未発生} */
#define UART_IIR_IDMASK	(0x06)	/* %jp{割り込みIDマスク} */
#define UART_IIR_MSI	(0x00)	/* %jp{モデムステータス} */
#define UART_IIR_THRI	(0x02)	/* %jp{送信完了(バッファエンプティ)} */
#define UART_IIR_RDI	(0x04)	/* %jp{受信完了} */
#define UART_IIR_RLSI	(0x06)	/* %jp{受信回線状態更新} */

/*
 *  %jp{モデムコントロール関連}
 */
#define UART_MCTL_DTR_LOW     (0x1)
#define UART_MCTL_RTS_LOW     (0x2)
#define UART_MCTL_OUT1_LOW    (0x4)
#define UART_MCTL_ENINTR      (0x8)
#define UART_MCTL_LOOPBAK     (0x10)
#define UART_MCTL_CONST       (UART_MCTL_DTR_LOW|UART_MCTL_RTS_LOW)

/*
 * %jp{ラインステータス}
 */
#define UART_LSR_RXRDY       (0x01)
#define UART_LSR_TXHOLD      (0x20)

/*
 * Interrupt Enable Register
 */
#define UART_INTR_DIS   (0x00) /*< %jp{割込み通知を禁止}   */
#define UART_INTR_RDA   (0x01) /*< %jp{受信割込みを有効化} */
#define UART_INTR_TXE   (0x02) /*< %jp{送信割込みを有効化} */

/**
   %jp{UARTレジスタ読み込み}
   base %jp{UARTレジスタベースアドレス}
   reg  %jp{UARTレジスタオフセットアドレス}
   %jp{返り値 読取り値}
 */
#define RISCV_VIRT_UART_READ_REG(base, reg) \
	(*((volatile UB *)((base) + (reg))))

/**
   %jp{UARTレジスタ書込み}
   base %jp{UARTレジスタベースアドレス}
   reg  %jp{UARTレジスタオフセットアドレス}
   v    %jp{書き込む値}
 */
#define RISCV_VIRT_UART_WRITE_REG(base, reg, v)			\
	do{ *((volatile UB *)((base) + (reg))) = (v); }while(0)

/**
   %jp{モデムコントロール設定値算出}
   func    %jp{設定する機能}
 */
#define RISCV_VIRT_UART_MK_MCTL(func)    ( (func) | UART_MCTL_CONST )

/**
   %jp{割込みID取得}
   val %jp{割込みIDレジスタ値}
   %jp{返り値 割込みID}
 */
#define RISCV_VIRT_UART_GETIIR(val) ( (val) & (UART_IIR_IDMASK) )

#ifdef __cplusplus
extern "C" {
#endif

void Uart_Initialize(void);		    /* %jp{UART の初期化} */
void Uart_PutChar(int c);		    /* %jp{1文字出力} */
void Uart_PutString(const char *text);	    /* %jp{文字列出力} */
void Uart_PutHexByte(char c);		    /* %jp{16進バイト出力} */
void Uart_PutHexHalfWord(unsigned short h); /* %jp{16進ハーフワード出力} */
void Uart_PutHexWord(unsigned long w);      /* %jp{16進ワード出力} */
void Uart_PutHexDoubleWord(unsigned long long d); /* %jp{16進ダブルワード出力} */

#ifdef __cplusplus
}
#endif


#endif	/* __uart_h__ */


/* end of file */
