/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  wintimer.h
 * @brief %jp{Windows用のタイマ}%en{Windows timer object}
 *
 * @version $Id: wintimer.h,v 1.1 2006-11-06 15:02:57 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __wintimer_h__
#define __wintimer_h__


#ifdef __cplusplus
extern "C" {
#endif

void WinTimer_Start(INHNO inhno, int iInterval);	/** %jp{タイマ動作開始} */

#ifdef __cplusplus
}
#endif



#endif	/* __wintimer_h__ */



/* end of file */
