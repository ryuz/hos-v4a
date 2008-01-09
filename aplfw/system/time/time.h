/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  time.h
 * @brief %jp{時刻管理API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__time_h__
#define __HOS__time_h__


/* システム時刻型定義 */
typedef long		TIME_SYSTEM;


#ifdef __cplusplus
extern "C" {
#endif

void        Time_Wait(TIME_SYSTEM Millisecond);
TIME_SYSTEM Time_GetSystemTime(void);


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__time_h__ */


/* end of file */
