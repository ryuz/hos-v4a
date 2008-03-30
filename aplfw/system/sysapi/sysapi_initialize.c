/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "sysapi_local.h"
#include "kernel.h"


SYSMTX_HANDLE		SysMem_hMtx;			/* システムメモリ管理用ミューテックス */
C_MEMPOL			SysMem_MemPol;			/* システムヒープメモリ */
T_SYSPRC_INF		*SysPrc_InfTbl;			/* プロセス管理用テーブル */
T_SYSISR_INF		*SysIsr_InfTbl;			/* ISR管理用テーブル */


/* システムの初期化 */
void SysApi_Initialize(void *pMem, MEMSIZE Size)
{
	/* メモリ管理の初期化 */
	SysMem_hMtx = SysMtx_Create(SYSMTX_ATTR_NORMAL);	/* メモリ管理用排他制御用ミューテックス生成 */
	MemPol_Create(&SysMem_MemPol, pMem, Size);			/* メモリプール生成 */
	
	/* プロセス管理テーブルメモリ確保 */
	SysPrc_InfTbl = (T_SYSPRC_INF *)SysMem_Alloc(sizeof(T_SYSPRC_INF) * (_kernel_max_tskid + 1));
	memset(SysPrc_InfTbl, 0, sizeof(T_SYSPRC_INF) * _kernel_max_tskid);

	/* ISR管理テーブルメモリ確保 */
	SysIsr_InfTbl = (T_SYSISR_INF *)SysMem_Alloc(sizeof(T_SYSPRC_INF) * (_kernel_max_intno - _kernel_min_intno + 1));
	memset(SysIsr_InfTbl, 0, sizeof(T_SYSPRC_INF) * (_kernel_max_intno - _kernel_min_intno + 1));
}


/* end of file */
