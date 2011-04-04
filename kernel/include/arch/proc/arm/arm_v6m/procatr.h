/**
 *  Hyper Operating System V4 Advance
 *
 * @file  procatr.h
 * @brief %jp{ARMv6-M}%en{ARMv6-M}
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__arm__arm_v6m__procatr_h__
#define _KERNEL__arch__proc__arm__arm_v6m__procatr_h__


#define _KERNEL_PROCATR_ARM_ARMV6M


/* %jp{プロセッサアーキテクチャ定義のあるインクルードパス} */
#define _KERNEL_PROCATR_INC_PATH			"arm/arm_v6m"


/* %jp{プロセッサアーキテクチャに依存した属性} */
#define _KERNEL_PROCATR_CTX_STK				FALSE		/**< %jp{コンテキスト生成にスタック領域の指定が必要か？} */
#define _KERNEL_PROCATR_CTX_STKSZ			FALSE		/**< %jp{コンテキスト生成にスタックサイズの指定が必要か？} */
#define _KERNEL_PROCATR_CTX_ISP				TRUE		/**< %jp{コンテキスト生成に初期スタックポインタ値が必要か？} */
#define _KERNEL_PROCATR_CTX_DEL				FALSE		/**< %jp{別コンテキストからのコンテキスト削除が必要か？} */
#define _KERNEL_PROCATR_CTX_RST				TRUE		/**< %jp{自コンテキストのリスタートが可能か？} */

#define _KERNEL_PROCATR_TMIN_STKSZ			(4*16)		/**< %jp{最低限必要なスタックサイズ(byte単位)} */
#define _KERNEL_PROCATR_DEF_SYSSTKSZ		64
#define _KERNEL_PROCATR_DEF_INTSTKSZ		256

#define _KERNEL_PROCATR_SPT_SMP				FALSE		/**< %jp{SMPに対応しているか？} */
#define _KERNEL_PROCATR_SPT_MULTINT			TRUE		/**< %jp{多重割込みに対応しているか？} */

#define _KERNEL_PROCATR_TMIN_INHNO			0			/**< %jp{割込みハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_INHNO			47			/**< %jp{割込みハンドラ番号の最大値} */

#define _KERNEL_PROCATR_TMIN_EXCNO			0			/**< %jp{CPU例外ハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_EXCNO			15			/**< %jp{CPU例外ハンドラ番号の最大値} */

#define _KERNEL_PROCATR_SYSSTK_NUM			1			/**< %jp{システムスタックは何本必要か？} */

#define _KERNEL_PROCATR_SIGNED_INT			0			/**< %jp{符号付整数と符号無し整数のどちらが得意か？(符号付き:1, 符号無し:-1, 同じ:0)} */
#define _KERNEL_PROCATR_TBIT_INT			32			/**< %jp{プロセッサに最適な整数型のビット数} */
#define _KERNEL_PROCATR_TBIT_PTR			32			/**< %jp{ポインタのビット数} */
#define _KERNEL_PROCATR_MEM_ALIGN			4			/**< %jp{適切なメモリのアライメント(byte単位)} */
#define _KERNEL_PROCATR_STK_ALIGN			8			/**< %jp{適切なスタックのアライメント(byte単位)} */
#define _KERNEL_PROCATR_ALLOW_UNALIGN		FALSE		/**< %jp{アンアラインアクセスは可能か？} */

#define _KERNEL_PROCATR_SYS_CTX				TRUE		/**< %jp{コンテキスト状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_LOC				FALSE		/**< %jp{CPUロック状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DSP				FALSE		/**< %jp{ディスパッチ禁止状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_SYS				FALSE		/**< %jp{システム状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DLY				TRUE		/**< %jp{遅延ディスパッチ保留状態管理をプロセッサで実施するか？} */



#endif	/* _KERNEL__arch__proc__arm__arm_v6m__procatr_h__ */


/* end of file */
