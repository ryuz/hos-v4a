/**
 *  Hyper Operating System V4 Advance
 *
 * @file  procatr.h
 * @brief %jp{プロセッサアーキテクチャ固有機能}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__riscv__procatr_h__
#define _KERNEL__arch__proc__riscv__procatr_h__


/* %jp{プロセッサアーキテクチャ定義のあるインクルードパス} */
#define _KERNEL_PROCATR_INC_PATH			"riscv"


/* %jp{プロセッサアーキテクチャに依存した属性} */
#define _KERNEL_PROCATR_CTX_STK				FALSE		/**< %jp{コンテキスト生成にスタック領域の指定が必要か？} */
#define _KERNEL_PROCATR_CTX_STKSZ			FALSE		/**< %jp{コンテキスト生成にスタックサイズの指定が必要か？} */
#define _KERNEL_PROCATR_CTX_ISP				TRUE		/**< %jp{コンテキスト生成に初期スタックポインタ値が必要か？} */
#define _KERNEL_PROCATR_CTX_DEL				FALSE		/**< %jp{別コンテキストからのコンテキスト削除が必要か？} */
#define _KERNEL_PROCATR_CTX_RST				TRUE		/**< %jp{自コンテキストのリスタートが可能か？} */

#define _KERNEL_PROCATR_SPT_SMP				FALSE		/**< %jp{SMPに対応しているか？} */
#define _KERNEL_PROCATR_SPT_MULTINT			TRUE		/**< %jp{多重割込みに対応しているか？} */

#define _KERNEL_PROCATR_TMIN_INHNO			0			/**< %jp{割込みハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_INHNO			3			/**< %jp{割込みハンドラ番号の最大値(CLIC:3)} */

#define _KERNEL_PROCATR_TMIN_EXCNO			0			/**< %jp{CPU例外ハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_EXCNO			63			/**< %jp{CPU例外ハンドラ番号の最大値} */

#define _KERNEL_PROCATR_SYSSTK_NUM			1			/**< %jp{システムスタックは何本必要か？} */

#define _KERNEL_PROCATR_SIGNED_INT			0			/**< %jp{符号付整数と符号無し整数のどちらが得意か？(符号付き:1, 符号無し:-1, 同じ:0)} */


#define _KERNEL_PROCATR_ALLOW_UNALIGN		        FALSE		/**< %jp{アンアラインアクセスは可能か？} */


/* %jp{RISC-V固有の定数} */
/* TODO: PLIC/CLICの割込み数を定義 */
#define _KERNEL_PROCATR_SYS_CTX				FALSE		/**< %jp{コンテキスト状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_LOC				FALSE		/**< %jp{CPUロック状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DSP				FALSE		/**< %jp{ディスパッチ禁止状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_SYS				FALSE		/**< %jp{システム状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DLY				FALSE		/**< %jp{遅延ディスパッチ保留状態管理をプロセッサで実施するか？} */

/** %jp{RISC-V C API Specificationに準拠したコンパイラの場合, __riscv_xlenによってレジスタ長を判定可能} */
#ifdef __riscv


#define _KERNEL_RISCV_XLEN                         __riscv_xlen    /**< %jp{bit長} */
/**< %jp{レジスタ長(単位:バイト)} */
#define _KERNEL_RISCV_REGSIZE                      (__riscv_xlen/8)


#if __riscv_xlen == 32
#define _KERNEL_PROCATR_TMIN_STKSZ			(4*32)		/**< %jp{最低限必要なスタックサイズ(byte単位).} */
#define _KERNEL_PROCATR_TBIT_INT			32			/**< %jp{プロセッサに最適な整数型のビット数} */
#define _KERNEL_PROCATR_TBIT_PTR			32			/**< %jp{ポインタのビット数} */
#define _KERNEL_PROCATR_MEM_ALIGN			4			/**< %jp{適切なメモリのアライメント(byte単位)} */
#define _KERNEL_PROCATR_STK_ALIGN			16			/**< %jp{適切なスタックのアライメント(byte単位)} */

#define _KERNEL_RISCV_PROC_LD                      lw    /**< %jp{32bitレジスタ} */
#define _KERNEL_RISCV_PROC_ST                      sw    /**< %jp{32bitレジスタ} */

#if !defined(_MACRO_ONLY)
#define _KERNEL_RISCV_PROC_REGTYPE                 UW    /**< %jp{32bitレジスタ} */
#endif  /*  !_MACRO_ONLY  */

#elif __riscv_xlen == 64
#define _KERNEL_PROCATR_TMIN_STKSZ			(8*32)		/**< %jp{最低限必要なスタックサイズ(byte単位).} */
#define _KERNEL_PROCATR_TBIT_INT			64			/**< %jp{プロセッサに最適な整数型のビット数} */
#define _KERNEL_PROCATR_TBIT_PTR			64			/**< %jp{ポインタのビット数} */
#define _KERNEL_PROCATR_MEM_ALIGN			8			/**< %jp{適切なメモリのアライメント(byte単位)} */
#define _KERNEL_PROCATR_STK_ALIGN			16			/**< %jp{適切なスタックのアライメント(byte単位)} */

#define _KERNEL_RISCV_PROC_LD                      ld    /**< %jp{64bitレジスタ} */
#define _KERNEL_RISCV_PROC_ST                      sd    /**< %jp{64bitレジスタ} */

#if !defined(_MACRO_ONLY)
#define _KERNEL_RISCV_PROC_REGTYPE                 UD    /**< %jp{64bitレジスタ} */
#endif  /*  !_MACRO_ONLY  */

#else   /* !__riscv_xlen == 64 */
#error "target is not supported"
#endif  /* !__riscv_xlen == 32 */


#if !defined(_MACRO_ONLY)

#ifdef __cplusplus
extern "C" {
#endif  /*  __cplusplus  */

/** %jp{割込みコンテキスト: riscv64でのサイズは144バイト} */
typedef struct _kernel_riscv_ictx{
	_KERNEL_RISCV_PROC_REGTYPE      ra;  /* %jp{riscv64でのオフセット: 0 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t0;  /* %jp{riscv64でのオフセット: 8 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t1;  /* %jp{riscv64でのオフセット: 16 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t2;  /* %jp{riscv64でのオフセット: 24 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t3;  /* %jp{riscv64でのオフセット: 32 バイト} */

	_KERNEL_RISCV_PROC_REGTYPE      t4;  /* %jp{riscv64でのオフセット: 40 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t5;  /* %jp{riscv64でのオフセット: 48 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t6;  /* %jp{riscv64でのオフセット: 56 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a0;  /* %jp{riscv64でのオフセット: 64 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a1;  /* %jp{riscv64でのオフセット: 72 バイト} */

	_KERNEL_RISCV_PROC_REGTYPE      a2;  /* %jp{riscv64でのオフセット: 80 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a3;  /* %jp{riscv64でのオフセット: 88 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a4;  /* %jp{riscv64でのオフセット: 96 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a5;  /* %jp{riscv64でのオフセット: 104 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a6;  /* %jp{riscv64でのオフセット: 112 バイト} */

	_KERNEL_RISCV_PROC_REGTYPE      a7;  /* %jp{riscv64でのオフセット: 120 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE     epc;  /* %jp{riscv64でのオフセット: 128 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE  status;  /* %jp{riscv64でのオフセット: 136 バイト} */
}kernel_riscv_ictx;


/** %jp{タスクスイッチコンテキスト: riscv64でのサイズは112バイト} */
typedef struct _kernel_riscv_tskswctx{
	_KERNEL_RISCV_PROC_REGTYPE      ra;  /* %jp{riscv64でのオフセット:  0 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s0;  /* %jp{riscv64でのオフセット:  8 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s1;  /* %jp{riscv64でのオフセット:  16 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s2;  /* %jp{riscv64でのオフセット:  24 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s3;  /* %jp{riscv64でのオフセット:  32 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s4;  /* %jp{riscv64でのオフセット:  40 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s5;  /* %jp{riscv64でのオフセット:  48 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s6;  /* %jp{riscv64でのオフセット:  56 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s7;  /* %jp{riscv64でのオフセット:  64 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s8;  /* %jp{riscv64でのオフセット:  72 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s9;  /* %jp{riscv64でのオフセット:  80 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE     s10;  /* %jp{riscv64でのオフセット:  88 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE     s11;  /* %jp{riscv64でのオフセット:  96 バイト} */
}kernel_riscv_tskswctx;


#ifdef __cplusplus
}
#endif  /*  __cplusplus  */

#endif  /*  !_MACRO_ONLY  */

#endif  /*  __riscv  */

#if !defined(_IN_ASM_OFFSET)
#include "regoff.h"  /* %jp{コンテキスト中のレジスタオフセット定義読み込み} */
#endif  /*  !defined(_IN_ASM_OFFSET)  */

#endif	/* _KERNEL__arch__proc__riscv__procatr_h__ */


/* end of file */
