/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  procatr.h
 * @brief %jp{プロセッサアーキテクチャ固有機能}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__ia32__i386__procatr_h__
#define _KERNEL__arch__proc__ia32__i386__procatr_h__


/* %jp{プロセッサアーキテクチャ定義のあるインクルードパス} */
#define _KERNEL_PROCATR_INC_PATH			"ia32/i386"


/* %jp{プロセッサアーキテクチャに依存した属性} */
#define _KERNEL_PROCATR_CTX_STK				FALSE		/**< %jp{コンテキスト生成にスタック領域の指定が必要か？} */
#define _KERNEL_PROCATR_CTX_STKSZ			FALSE		/**< %jp{コンテキスト生成にスタックサイズの指定が必要か？} */
#define _KERNEL_PROCATR_CTX_ISP				TRUE		/**< %jp{コンテキスト生成に初期スタックポインタ値が必要か？} */
#define _KERNEL_PROCATR_CTX_DEL				FALSE		/**< %jp{別コンテキストからのコンテキスト削除が必要か？} */
#define _KERNEL_PROCATR_CTX_RST				TRUE		/**< %jp{自コンテキストのリスタートが可能か？} */

#define _KERNEL_PROCATR_TMIN_STKSZ			(4*16)		/**< %jp{最低限必要なスタックサイズ(byte単位)} */

#define _KERNEL_PROCATR_SPT_SMP				FALSE		/**< %jp{SMPに対応しているか？} */
#define _KERNEL_PROCATR_SPT_MULTINT			TRUE		/**< %jp{多重割込みに対応しているか？} */

#define _KERNEL_PROCATR_TMIN_INHNO			32			/**< %jp{割込みハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_INHNO			255			/**< %jp{割込みハンドラ番号の最大値} */

#define _KERNEL_PROCATR_TMIN_EXCNO			0			/**< %jp{CPU例外ハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_EXCNO			31			/**< %jp{CPU例外ハンドラ番号の最大値} */

#define _KERNEL_PROCATR_SYSSTK_NUM			1			/**< %jp{システムスタックは何本必要か？} */

#define _KERNEL_PROCATR_SIGNED_INT			0			/**< %jp{符号付整数と符号無し整数のどちらが得意か？(符号付き:1, 符号無し:-1, 同じ:0)} */
#define _KERNEL_PROCATR_TBIT_INT			32			/**< %jp{プロセッサに最適な整数型のビット数} */
#define _KERNEL_PROCATR_TBIT_PTR			32			/**< %jp{ポインタのビット数} */
#define _KERNEL_PROCATR_MEM_ALIGN			8			/**< %jp{適切なメモリのアライメント(byte単位)} */
#define _KERNEL_PROCATR_STK_ALIGN			8			/**< %jp{適切なスタックのアライメント(byte単位)} */
#define _KERNEL_PROCATR_ALLOW_UNALIGN		TRUE		/**< %jp{アンアラインアクセスは可能か？} */

#define _KERNEL_PROCATR_SYS_CTX				FALSE		/**< %jp{コンテキスト状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_LOC				FALSE		/**< %jp{CPUロック状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DSP				FALSE		/**< %jp{ディスパッチ禁止状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_SYS				FALSE		/**< %jp{システム状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DLY				FALSE		/**< %jp{遅延ディスパッチ保留状態管理をプロセッサで実施するか？} */

/**< %jp{eflagsの初期値} */
#define _KERNEL_IA32_INITIAL_EFLAGS ( ( 1 << 1) | ( 1 << 3) | ( 1 << 5 ) )

#ifndef _MACRO_ONLY

#include "itron.h"

#ifdef __cplusplus
extern "C" {
#endif

/** %jp{割込みコンテキスト} */
typedef struct _kernel_ia32_ictx{
	UW    ebx;
	UW    ecx;
	UW    edx;
	UW    esi;
	UW    edi;
	UW    ebp;
	UW    eax;
	UW  excno;
	UW   excd;
	UW    eip;
	UW    xcs;
	UW eflags;
}kernel_ia32_ictx;

/** %jp{タスクスイッチコンテキスト} */
typedef struct _kernel_ia32_tskswctx{
	UW       ebp;
	UW       edi;
	UW       esi;
	UW       ebx;
	UW    eflags;
	UW   retaddr;
}kernel_ia32_tskswctx;

#ifdef __cplusplus
}
#endif

#endif  /* !_MACRO_ONLY */

#if !defined(_IN_ASM_OFFSET)
#include "regoff.h"  /* %jp{コンテキスト中のレジスタオフセット定義読み込み} */
#endif  /*  !defined(_IN_ASM_OFFSET)  */


#endif	/* _KERNEL__arch__proc__ia32__i386__procatr_h__ */


/* end of file */
