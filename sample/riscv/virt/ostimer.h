/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  ostimer.h
 * @brief %jp{OSタイマ}%en{OS timer}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __ostimer_h__
#define __ostimer_h__

#include "kernel.h"

#if !defined(_MACRO_ONLY)

#ifdef __cplusplus
extern "C" {
#endif

/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf);
/** %jp{タイマレジスタ参照} */
UD _riscv_get_time(void);
#ifdef __cplusplus
}
#endif

#endif  /* !_MACRO_ONLY */

#endif	/* __ostimer_h__ */


/* end of file */
