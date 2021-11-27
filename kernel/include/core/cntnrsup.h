/**
 *  Hyper Operating System V4 Advance
 *
 * @file  cntnrsup.h
 * @brief %jp{コンテナデータサポートマクロ}%en{Support macros for container data structures}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__cntnrsup_h__
#define _KERNEL__cntnrsup_h__

#ifndef _MACRO_ONLY

/**
   構造体に埋め込まれたデータ構造のオフセットアドレスを算出する
    @param[in] t データ構造を埋め込んでいる構造体の型
    @param[in] m データ構造のメンバの名前
 */
#define _KERNEL_CNTNR_OFFSET_OF(t, m)			\
	( (void *)( &( ( (t *)(0) )->m ) ) )

/**
   構造体に埋め込まれたデータ構造（リストなど)のアドレスから構造体へのポインタを得る
    @param[in] p データ構造のアドレス
    @param[in] t データ構造を埋め込んでいる構造体の型
    @param[in] m データ構造を埋め込んでいる構造体中のデータ構造体メンバの名前
 */
#define _KERNEL_CNTNR_CONTAINER_OF(p, t, m)			\
	( (t *)( ( (void *)(p) ) - _KERNEL_CNTR_OFFSET_OF(t, m) ) )

#endif  /*  !_MACRO_ONLY  */

#endif  /*  _KERNEL__cntnrsup_h__  */


/* end of file */
