/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"



SYSTIM_CPUTIME		SysHos_OldTime;
ID					SysHos_TaskId;


/** 割込み計測タイマを初期化 */
void SysInt_SetIntTime(int iIntNum, SYSTIM_CPUTIME Time)
{
	if ( SysInt_InfTbl == NULL )
	{
		return;
	}

	if ( iIntNum < _kernel_min_intno || iIntNum > _kernel_max_intno )
	{
		return;
	}

	SysInt_InfTbl[iIntNum - _kernel_min_intno].ExecTime = Time;
}


/** 割込み計測タイマを取得 */
SYSTIM_CPUTIME SysInt_GetIntTime(int iIntNum)
{
	if ( SysInt_InfTbl == NULL )
	{
		return 0;
	}

	if ( iIntNum < _kernel_min_intno || iIntNum > _kernel_max_intno )
	{
		return 0;
	}
	
	return SysInt_InfTbl[iIntNum - _kernel_min_intno].ExecTime;
}


/** プロセス実行時間計測タイマを初期化 */
void SysPrc_SetExecTime(SYSPRC_HANDLE hPrc, SYSTIM_CPUTIME Time)
{
	if ( SysPrc_InfTbl == NULL )
	{
		return;
	}
	
	SysPrc_InfTbl[(ID)hPrc].ExecTime = Time;
}


/** プロセス実行時間計測タイマを取得 */
SYSTIM_CPUTIME SysPrc_GetExecTime(SYSPRC_HANDLE hPrc)
{
	if ( SysPrc_InfTbl == NULL )
	{
		return 0;
	}
	
	return SysPrc_InfTbl[(ID)hPrc].ExecTime;
}


/** %jp{タスクスイッチのフック} */
void _kernel_tsk_swi(ID tskid_old, ID tskid_new)
{
	SYSTIM_CPUTIME NewTime;
	SYSTIM_CPUTIME PastTime;
	
	/* 現在時刻を取得 */
	NewTime  = SysTim_GetCpuTime();
	PastTime = NewTime - SysHos_OldTime;
	
	/* 実行時間を累算 */
	if ( SysPrc_InfTbl != NULL )
	{
		SysPrc_InfTbl[tskid_old].ExecTime += PastTime;
	}
	
	/* 次回計測を設定 */
	SysHos_OldTime = NewTime;
	SysHos_TaskId  = tskid_new;
}


/** %jp{割込みサービスルーチン開始のフック} */
void _kernel_isr_sta(INHNO inhno)
{
	SYSTIM_CPUTIME NewTime;
	SYSTIM_CPUTIME PastTime;
	
	/* 現在時刻を取得 */
	NewTime  = SysTim_GetCpuTime();
	PastTime = NewTime - SysHos_OldTime;
	
	/* 実行時間を累算 */
	if ( SysPrc_InfTbl != NULL )
	{
		SysPrc_InfTbl[SysHos_TaskId].ExecTime += PastTime;
	}

	/* 次回計測を設定 */
	SysHos_OldTime = NewTime;	
}


/**< %jp{割込みサービスルーチン終了のフック} */
void _kernel_isr_end(INTNO intno)
{
	SYSTIM_CPUTIME NewTime;
	SYSTIM_CPUTIME PastTime;
	
	/* 現在時刻を取得 */
	NewTime  = SysTim_GetCpuTime();
	PastTime = NewTime - SysHos_OldTime;
	
	/* 実行時間を累算 */
	if ( SysInt_InfTbl != NULL )
	{
		SysInt_InfTbl[intno - _kernel_min_intno].ExecTime += PastTime;
	}
}


/* end of file */
