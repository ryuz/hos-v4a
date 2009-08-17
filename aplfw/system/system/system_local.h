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
#include "system/file/file_local.h"
#include "system/process/process_local.h"
#include "library/container/assoc/assoc.h"


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
	C_PROCESS			Process;		/**< システムプロセス */

	C_PROCESS			*pRunProcess;	/**< 実行中プロセスのリスト */
		
	HANDLE				hBootProcess;
	
	C_ASSOC				*paWhiteBoard;	/**< ホワイトボード */
	
	SYSMTX_HANDLE		hMtxSys;
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

int    System_Process(VPARAM Param);					/* システムプロセス */

HANDLE System_GetSystemProcess(void);
void   System_RegistryProcess(C_PROCESS *pProcess);		/* プロセスの登録 */
void   System_UnregistryProcess(C_PROCESS *pProcess);	/* プロセスの登録解除 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__system_h__ */


/* end of file */
