/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cfgsys.h
 * @brief %jp{ITRONシステムのコンフィギュレーション用ヘッダファイル}%en{ITRON system configuration heder file}
 *
 * @version $Id: cfgsys.h,v 1.2 2006-08-18 12:00:12 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


/*
%jp{
  本ファイルにて、ITRONシステムのコンフィギュレーションを行う。
  コンフィギュレーションの結果により、基本型などアプリケーションで
利用する定義も変化する為、本ファイルの変更後はカーネルのみならず、
itron.h や kernel.h を利用している、アプリケーション側も含めて
システム全体をリビルドする必要がある。
  また、本ファイルはセンブリ言語の前処理にも使う事を想定しているので、
C言語構文(例えばtypedefなど)はこの中には記載せず、マクロ定義などの
プリプロセッサディレクティブのみを記載する事とする。
}
*/



#ifndef _KERNEL__config__cfgsys_h__
#define _KERNEL__config__cfgsys_h__


/* %jp{メモリのアラインサイズ}%jp{Memory alignment size} */
#define _KERNEL_CFG_MEM_ALIGN			(-1)				/**< メモリのアラインサイズ(-1の時デフォルト値)}%en{Memory alignment size (-1:default)} */


/* %jp{ITRON仕様共通データ型}%en{ITRON General Data Type} */
#define _KERNEL_CFG_TBIT_INT			(-1)				/**< %jp{INT     のビット数 (-1の時デフォルト値)}%en{Number of bits in INT     (-1:default)} */
#define _KERNEL_CFG_TBIT_UINT			(-1)				/**< %jp{UINT    のビット数 (-1の時デフォルト値)}%en{Number of bits in UINT    (-1:default)} */
#define _KERNEL_CFG_TBIT_BOOL			(-1)				/**< %jp{BOOL    のビット数 (-1の時デフォルト値)}%en{Number of bits in BOOL    (-1:default)} */
#define _KERNEL_CFG_TBIT_FN				(-1)				/**< %jp{FN      のビット数 (-1の時デフォルト値)}%en{Number of bits in FN      (-1:default)} */
#define _KERNEL_CFG_TBIT_ER				(-1)				/**< %jp{ER      のビット数 (-1の時デフォルト値)}%en{Number of bits in ER      (-1:default)} */
#define _KERNEL_CFG_TBIT_ID				(-1)				/**< %jp{ID      のビット数 (-1の時デフォルト値)}%en{Number of bits in ID      (-1:default)} */
#define _KERNEL_CFG_TBIT_ATR			(-1)				/**< %jp{ATR     のビット数 (-1の時デフォルト値)}%en{Number of bits in ATR     (-1:default)} */
#define _KERNEL_CFG_TBIT_STAT			(-1)				/**< %jp{STAT    のビット数 (-1の時デフォルト値)}%en{Number of bits in STAT    (-1:default)} */
#define _KERNEL_CFG_TBIT_MODE			(-1)				/**< %jp{MODE    のビット数 (-1の時デフォルト値)}%en{Number of bits in MODE    (-1:default)} */
#define _KERNEL_CFG_TBIT_PRI			(-1)				/**< %jp{PRI     のビット数 (-1の時デフォルト値)}%en{Number of bits in PRI     (-1:default)} */
#define _KERNEL_CFG_TBIT_SIZE			(-1)				/**< %jp{SIZE    のビット数 (-1の時デフォルト値)}%en{Number of bits in SIZE    (-1:default)} */
#define _KERNEL_CFG_TBIT_TMO			(-1)				/**< %jp{TMO     のビット数 (-1の時デフォルト値)}%en{Number of bits in TMO     (-1:default)} */
#define _KERNEL_CFG_TBIT_RELTIM			(-1)				/**< %jp{RELTIM  のビット数 (-1の時デフォルト値)}%en{Number of bits in RELTIM  (-1:default)} */
#define _KERNEL_CFG_SYSTIM_STRUCT		FALSE				/**< %jp{SYSTIM型を構造体にするかどうか} */
#define _KERNEL_CFG_TBIT_SYSTIM			32					/**< %jp{SYSTIM型のビット数} */
#define _KERNEL_CFG_VP_INT_PTR			FALSE				/**< %jp{VP_INT型をポインタ型にするかどうか} */
#define _KERNEL_CFG_TBIT_VP_INT			(-1)				/**< %jp{VP_INT  のビット数 (-1の時デフォルト値)}%en{Number of bits in VP_INT  (-1:default)} */
#define _KERNEL_CFG_TBIT_ER_BOOL		(-1)				/**< %jp{ER_BOOL のビット数 (-1の時デフォルト値)}%en{Number of bits in ER_BOOL (-1:default)} */
#define _KERNEL_CFG_TBIT_ER_ID			(-1)				/**< %jp{ER_ID   のビット数 (-1の時デフォルト値)}%en{Number of bits in ER_ID   (-1:default)} */
#define _KERNEL_CFG_TBIT_ER_UINT		(-1)				/**< %jp{ER_UINT のビット数 (-1の時デフォルト値)}%en{Number of bits in ER_UINT (-1:default)} */

/* %jp{カーネルのデータ型}%en{Kernel Data Type} */
#define _KERNEL_CFG_TBIT_TEXPTN			(-1)				/**< %jp{タスク例外要因のビット数(-1の時デフォルト値)} */
#define _KERNEL_CFG_TBIT_FLGPTN			(-1)				/**< %jp{イベントフラグのビット数(-1の時デフォルト値)} */
#define _KERNEL_CFG_TBIT_RDVPTN			(-1)				/**< %jp{ランデブ条件のビット数(-1の時デフォルト値)} */
#define _KERNEL_CFG_TBIT_RDVNO			(-1)
#define _KERNEL_CFG_TBIT_OVRTIM			(-1)
#define _KERNEL_CFG_TBIT_INHNO			(-1)
#define _KERNEL_CFG_TBIT_INTNO			(-1)
#define _KERNEL_CFG_TBIT_EXCNO			(-1)


/* %jp{優先度の範囲}%en{Priority Range} */
#define _KERNEL_CFG_TMAX_TPRI			255					/**< %jp{タスク優先度の最大値(-1の時デフォルト値)}%en{Maximum task priority} */
#define _KERNEL_CFG_TMAX_MPRI			255					/**< %jp{メッセージ優先度の最大値(-1の時デフォルト値)}%en{Maximum message priority} */

/* %jp{キューイング／ネスト回数の最大値}%en{Maximum Nesting/Queueing Count} */
#define _KERNEL_CFG_TMAX_ACTCNT			255					/**< %jp{タスク起動要求キューイング数の最大値(-1の時デフォルト値)} */
#define _KERNEL_CFG_TMAX_WUPCNT			255					/**< %jp{タスク起床要求キューイング数の最大値(-1の時デフォルト値)} */
#define _KERNEL_CFG_TMAX_SUSCNT			255					/**< %jp{タスク強制待ち要求ネスト数の最大値(-1の時デフォルト値)} */

/* %jp{ビットパターンのビット数} %en{Number of Bits in Bitpatterns}*/
#define _KERNEL_CFG_TEX_TBIT_TEXPTN		(-1)				/**< %jp{タスク例外要因のビット数(-1の時デフォルト値)} */
#define _KERNEL_CFG_FLG_TBIT_FLGPTN		(-1)				/**< %jp{イベントフラグのビット数(-1の時デフォルト値)} */
#define _KERNEL_CFG_RDV_TBIT_RDVPTN		(-1)				/**< %jp{ランデブ条件のビット数(-1の時デフォルト値)} */

/* %jp{セマフォの最大値}%en{Maximum value of the maximum definable semaphore resource count} */
#define _KERNEL_CFG_TMAX_MAXSEM			(-1)


/* %jp{HOS独自拡張機能} */
#define _KERNEL_CFG_RTST_EXINF			FALSE				/**< %jp{T_RTSTに exinf を含めるか} */
#define _KERNEL_CFG_RTSK_EXINF			FALSE				/**< %jp{T_RTSKに exinf を含めるか} */



#endif	/* _KERNEL__config__cfgsys_h__ */



/* end of file */
