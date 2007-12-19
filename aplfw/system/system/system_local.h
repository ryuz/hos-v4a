/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__system_local_h__
#define __HOS__system_local_h__


#include "system.h"
#include "system/sysapi/sysapi.h"



#define SYSTEM_PROCQUE_SIZE		64		/* システムプロシージャ要求キューイング数 */


/* システムプロシージャ情報 */
typedef struct t_system_procinf
{
	void		(*pfncProc)(VPARAM Param1, VPARAM Param2);
	VPARAM		Param1;
	VPARAM		Param2;
} T_SYSTEM_PROCINF;


/* システムクラス */
typedef struct c_system
{
	SYSPRC_HANDLE		hPrcProc;
	SYSEVT_HANDLE		hEvtProc;
	volatile int		iProcHead;
	volatile int		iProcTail;
	T_SYSTEM_PROCINF	ProcQue[SYSTEM_PROCQUE_SIZE];
} C_SYSTEM;


extern C_SYSTEM g_System;


#ifdef __cplusplus
extern "C" {
#endif

void System_Process(VPARAM Param);		/* システムプロセス */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__system_h__ */


/* end of file */
