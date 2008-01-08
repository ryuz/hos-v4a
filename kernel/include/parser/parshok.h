/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  parshok.h
 * @brief %jp{カーネルフックのコンフィギュレーション解析}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__parser__parshok_h__
#define _KERNEL__parser__parshok_h__


#ifdef _KERNEL_HOK_TSK
#define _KERNEL_SPT_HOK_TSKSWI		TRUE						/**< タスクスイッチのフック */
#else
#define _KERNEL_SPT_HOK_TSKSWI		_KERNEL_CFG_HOK_TSKSWI		/**< タスクスイッチのフック */
#endif

#ifdef _KERNEL_HOK_INH
#define _KERNEL_SPT_HOK_INHSTA		TRUE						/**< 割込みハンドラ開始のフック */
#define _KERNEL_SPT_HOK_INHEND		TRUE						/**< 割込みハンドラ終了のフック */
#else
#define _KERNEL_SPT_HOK_INHSTA		_KERNEL_CFG_HOK_INHSTA		/**< 割込みハンドラ開始のフック */
#define _KERNEL_SPT_HOK_INHEND		_KERNEL_CFG_HOK_INHEND		/**< 割込みハンドラ終了のフック */
#endif

#ifdef _KERNEL_HOK_ISR
#define _KERNEL_SPT_HOK_ISRSTA		TRUE						/**< 割込みサービスルーチン開始のフック */
#define _KERNEL_SPT_HOK_ISREND		TRUE						/**< 割込みサービスルーチン終了のフック */
#else
#define _KERNEL_SPT_HOK_ISRSTA		_KERNEL_CFG_HOK_ISRSTA		/**< 割込みサービスルーチン開始のフック */
#define _KERNEL_SPT_HOK_ISREND		_KERNEL_CFG_HOK_ISREND		/**< 割込みサービスルーチン終了のフック */
#endif


#endif	/* _KERNEL__parser__parshok_h__ */


/* end of file */
