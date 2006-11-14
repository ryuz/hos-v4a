/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "system/sysapi/sysapi.h"
#include "library/container/mempol/mempol.h"
#include "kernel.h"


static SYSMTX_HANDLE System_hMtx;
static SYSMTX_HANDLE SysMem_hMtx;
static C_MEMPOL      SysMem_MemPol;


/* システムの初期化 */
void System_Initialize(void *pMem, long lSize)
{
	/* システムロックの作成 */
	System_hMtx = SysMtx_Create();					/* システムロック用ミューテックス生成 */

	/* メモリ管理の初期化 */
	SysMem_hMtx = SysMtx_Create();					/* メモリ管理用排他制御用ミューテックス生成 */
	MemPol_Create(&SysMem_MemPol, pMem, lSize);		/* メモリプール生成 */
}

/* システム全体のロック */
void System_Lock(void)
{
	SysMtx_Lock(System_hMtx);
}

/* システム全体のロック解除 */
void System_Unlock(void)
{
	SysMtx_Unlock(System_hMtx);
}


/* システムメモリの割り当て */
void *SysMem_Alloc(long lSize)
{
	void *pMem;
	
	SysMtx_Lock(SysMem_hMtx);
	pMem = MemPol_Alloc(&SysMem_MemPol, lSize);
	SysMtx_Unlock(SysMem_hMtx);

	return pMem;
}

/* システムメモリの返却 */
void  SysMem_Free(void *pMem)
{
	SysMtx_Lock(SysMem_hMtx);
	MemPol_Free(&SysMem_MemPol, pMem);
	SysMtx_Unlock(SysMem_hMtx);
}


void SysInt_Enable(int iIntNum)
{
	ena_int((INTNO)iIntNum);
}

void SysInt_Disable(int iIntNum)
{
	dis_int((INTNO)iIntNum);
}

void SysInt_Clear(int iIntNum)
{
	vclr_int((INTNO)iIntNum);
}


SYSISR_HANDLE SysIsr_Create(int iIntNum, void (*pfncIsr)(VPARAM Param), VPARAM Param)
{
	T_CISR cisr;
	ER_ID  erid;

	cisr.isratr = TA_HLNG;
	cisr.exinf  = (VP_INT)Param;
	cisr.intno  = (INTNO)iIntNum;
	cisr.isr    = (FP)pfncIsr;
	erid = acre_isr(&cisr);
	if ( erid < 0 )
	{
		return SYSISR_HANDLE_NULL;
	}

	return (SYSISR_HANDLE)erid;
}

void SysIsr_Delete(SYSISR_HANDLE hIsr)
{
/*	del_isr((ID)hIsr);	*/
}


/* プロセス生成 */
SYSPRC_HANDLE SysPrc_Create(int (*pfncEntry)(VPARAM Param), VPARAM Param, long StackSize, int Priority)
{
	T_CTSK ctsk;
	ER_ID  erid;
	
	ctsk.tskatr  = TA_HLNG | TA_ACT;
	ctsk.exinf   = (VP_INT)Param;
	ctsk.task    = (FP)pfncEntry;
	ctsk.itskpri = (PRI)Priority;
	ctsk.stksz   = (SIZE)StackSize;
	ctsk.stk     = NULL;
	erid = acre_tsk(&ctsk);
	if ( erid < 0 )
	{
		return SYSPRC_HANDLE_NULL;
	}

	return (SYSPRC_HANDLE)erid;
}

void SysPrc_Delete(SYSPRC_HANDLE hPrc)
{
/*	del_tsk((ID)hPrc);	*/
}


void SysPrc_Exit(void)
{
	ext_tsk();
}



/* システム用ミューテックス生成 */
SYSMTX_HANDLE SysMtx_Create(void)
{
	T_CSEM csem;
	ER_ID  erid;

	/* ロック用セマフォ生成 */
	csem.sematr  = TA_TFIFO;
	csem.isemcnt = 1;
	csem.maxsem  = 1;
	erid = acre_sem(&csem);
	if ( erid < 0 )
	{
		return SYSMTX_HANDLE_NULL;
	}

	return (SYSMTX_HANDLE)erid;
}

/* システム用ミューテックス削除 */
void SysMtx_Delete(SYSMTX_HANDLE hMtx)
{
	del_sem((ID)hMtx);
}

/* システム用ミューテックスロック*/
void SysMtx_Lock(SYSMTX_HANDLE hMtx)
{
	wai_sem((ID)hMtx);
}

/* システム用ミューテックスロック解除*/
void SysMtx_Unlock(SYSMTX_HANDLE hMtx)
{
	sig_sem((ID)hMtx);
}


/* システム用イベント生成 */
SYSEVT_HANDLE SysEvt_Create(void)
{
	T_CFLG cflg;
	ER_ID  erid;

	/* ロック用セマフォ生成 */
	cflg.flgatr  = TA_TFIFO;
	cflg.iflgptn = 0;
	erid = acre_flg(&cflg);
	if ( erid < 0 )
	{
		return SYSEVT_HANDLE_NULL;
	}

	return (SYSMTX_HANDLE)erid;
}

/* システム用イベント削除 */
void SysEvt_Delete(SYSEVT_HANDLE hEvt)
{
	del_flg((ID)hEvt);
}

/* システム用イベント待ち*/
void SysEvt_Wait(SYSEVT_HANDLE hEvt)
{
	wai_flg((ID)hEvt, 1, TWF_ANDW, NULL);
}

/* システム用イベントセット */
void SysEvt_Set(SYSEVT_HANDLE hEvt)
{
	if ( sns_ctx() )
	{
		iset_flg((ID)hEvt, 1);
	}
	else
	{
		set_flg((ID)hEvt, 1);
	}
}
		
/* システム用イベントクリア */
void SysEvt_Clear(SYSEVT_HANDLE hEvt)
{
	clr_flg((ID)hEvt, 0);
}



/* end of file */
