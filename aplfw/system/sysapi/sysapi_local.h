/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義 HOS-V4a 専用}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__sysapi_local_h__
#define __HOS__sysapi_local_h__


#include "kernel.h"
#include "sysapi.h"
#include "system/sysmem/sysmemheap_local.h"
#include "library/container/valmemheap/valmemheap_local.h"


/* #define _HOS_SYSPAI_USEMTX */


/* HOS-V4a 内部変数の参照(インチキ) */
extern const ID		_kernel_max_tskid;
extern const INTNO	_kernel_min_intno;
extern const INTNO	_kernel_max_intno;


/* プロセス固有情報管理 */
typedef struct t_sysprc_inf
{
	VPARAM				Param;					/* プロセス固有パラメータ */
	SYSTIM_CPUTIME		ExecTime;				/* プロセス実行時間計測 */
} T_SYSPRC_INF;


/* ISR固有情報管理 */
typedef struct t_sysint_inf
{
	SYSTIM_CPUTIME		ExecTime;				/* INT実行時間計測 */
} T_SYSINT_INF;

extern C_SYSMEMHEAP		SysMem_SysMemHeap;		/* システムメモリ */
extern C_VALMEMHEAP		SysMem_ValMemHeap;		/* システムヒープメモリ */
extern SYSMTX_HANDLE	SysIo_hMtx;				/* I/O用ヒープメモリ管理用ミューテックス */
extern C_VALMEMHEAP		*SysIo_pValMemHeap;		/* I/O用ヒープメモリ */
extern T_SYSPRC_INF		*SysPrc_InfTbl;			/* プロセス管理用テーブル */
extern T_SYSINT_INF		*SysInt_InfTbl;			/* ISR管理用テーブル */
extern SYSTIM_CPUTIME	SysTim_TimeCounter;		/* デフォルトのタイマカウンタ */



#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__sysapi_local_h__ */


/* end of file */
