/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cfghok.h
 * @brief %jp{カーネルフックのコンフィギュレーション用ヘッダファイル}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


/*
%jp{
  本ファイルにて、カーネルフック機構のコンフィギュレーションを行う。
  
  また、本ファイルはセンブリ言語の前処理にも使う事を想定しているので、
C言語構文(例えばtypedefなど)はこの中には記載せず、マクロ定義などの
プリプロセッサディレクティブのみを記載する事とする。}
*/



#ifndef _KERNEL__config__cfghok_h__
#define _KERNEL__config__cfghok_h__


/* 以下予定 */
#define _KERNEL_CFG_HOK_SVCCAL		FALSE		/**< サービスコールの呼び出し */
#define _KERNEL_CFG_HOK_SVCRET		FALSE		/**< サービスコールのリターン */

#define _KERNEL_CFG_HOK_TSKSWI		FALSE		/**< タスクスイッチのフック */

#define _KERNEL_CFG_HOK_INHSTA		FALSE		/**< 割込みハンドラ開始のフック */
#define _KERNEL_CFG_HOK_INHEND		FALSE		/**< 割込みハンドラ終了のフック */

#define _KERNEL_CFG_HOK_ISRSTA		FALSE		/**< 割込みサービスルーチン開始のフック */
#define _KERNEL_CFG_HOK_ISREND		FALSE		/**< 割込みサービスルーチン終了のフック */

#define _KERNEL_CFG_HOK_MTXPRI		FALSE		/**< ミューテックスの優先度変化のフック */


#endif	/* _KERNEL__config__cfghok_h__ */


/* end of file */
