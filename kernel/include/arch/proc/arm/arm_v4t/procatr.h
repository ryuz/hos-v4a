/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  procatr.h
 * @brief %jp{プロセッサアーキテクチャ固有機能}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__arm__arm_v4t__procatr_h__
#define _KERNEL__arch__proc__arm__arm_v4t__procatr_h__


/* %jp{プロセッサアーキテクチャ定義のあるインクルードパス} */
#define _KERNEL_PROCATR_INC_PATH			"arm/arm_v4t"


/* %jp{プロセッサアーキテクチャに依存した属性} */
#define _KERNEL_PROCATR_CTX_STK				FALSE		/**< %jp{コンテキスト生成にスタック領域の指定が必要か？} */
#define _KERNEL_PROCATR_CTX_STKSZ			FALSE		/**< %jp{コンテキスト生成にスタックサイズの指定が必要か？} */
#define _KERNEL_PROCATR_CTX_ISP				TRUE		/**< %jp{コンテキスト生成に初期スタックポインタ値が必要か？} */
#define _KERNEL_PROCATR_CTX_DEL				FALSE		/**< %jp{別コンテキストからのコンテキスト削除が必要か？} */
#define _KERNEL_PROCATR_CTX_RST				TRUE		/**< %jp{自コンテキストのリスタートが可能か？} */

#define _KERNEL_PROCATR_TMIN_STKSZ			(4*16)		/**< %jp{最低限必要なスタックサイズ(byte単位)} */

#define _KERNEL_PROCATR_SPT_SMP				FALSE		/**< %jp{SMPに対応しているか？} */
#define _KERNEL_PROCATR_SPT_MULTINT			TRUE		/**< %jp{多重割込みに対応しているか？} */

#define _KERNEL_PROCATR_TMIN_INHNO			0			/**< %jp{割込みハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_INHNO			1			/**< %jp{割込みハンドラ番号の最大値} */

#define _KERNEL_PROCATR_TMIN_EXCNO			0			/**< %jp{CPU例外ハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_EXCNO			4			/**< %jp{CPU例外ハンドラ番号の最大値} */

#define _KERNEL_PROCATR_SYSSTK_NUM			2			/**< %jp{システムスタックは何本必要か？} */

#define _KERNEL_PROCATR_SIGNED_INT			0			/**< %jp{符号付整数と符号無し整数のどちらが得意か？(符号付き:1, 符号無し:-1, 同じ:0)} */
#define _KERNEL_PROCATR_TBIT_INT			32			/**< %jp{プロセッサに最適な整数型のビット数} */
#define _KERNEL_PROCATR_TBIT_PTR			32			/**< %jp{ポインタのビット数} */
#define _KERNEL_PROCATR_MEM_ALIGN			8			/**< %jp{適切なメモリのアライメント(byte単位)} */
#define _KERNEL_PROCATR_STK_ALIGN			8			/**< %jp{適切なスタックのアライメント(byte単位)} */
#define _KERNEL_PROCATR_ALLOW_UNALIGN		FALSE		/**< %jp{アンアラインアクセスは可能か？} */

#define _KERNEL_PROCATR_SYS_CTX				FALSE		/**< %jp{コンテキスト状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_LOC				FALSE		/**< %jp{CPUロック状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DSP				FALSE		/**< %jp{ディスパッチ禁止状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_SYS				FALSE		/**< %jp{システム状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DLY				FALSE		/**< %jp{遅延ディスパッチ保留状態管理をプロセッサで実施するか？} */


/* %jp{ARM固有の定数} */
#define _KERNEL_ARM_INHNO_IRQ				0			/**< %jp{IRQ割込みの割込みハンドラ番号} */
#define _KERNEL_ARM_INHNO_FIQ				1			/**< %jp{FIQ割込みの割込みハンドラ番号} */

#define _KERNEL_ARM_EXCNO_RST				0			/**< %jp{リセットのCPU例外ハンドラ番号} */
#define _KERNEL_ARM_EXCNO_UND				1			/**< %jp{無効命令例外のCPU例外ハンドラ番号} */
#define _KERNEL_ARM_EXCNO_SWI				2			/**< %jp{ソフトウェア割込みのCPU例外ハンドラ番号} */
#define _KERNEL_ARM_EXCNO_PRE				3			/**< %jp{プリフェッチアボートのCPU例外ハンドラ番号} */
#define _KERNEL_ARM_EXCNO_ABT				4			/**< %jp{データアボートのCPU例外ハンドラ番号} */



#endif	/* _KERNEL__arch__proc__arm__arm_v4t__procatr_h__ */


/* end of file */
