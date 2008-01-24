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
#include "library/container/mempol/mempol.h"


/* HOS-V4a 内部変数の参照(インチキ) */
extern const ID		_kernel_max_tskid;
extern const INTNO	_kernel_min_intno;
extern const INTNO	_kernel_max_intno;


/* プロセス固有情報管理 */
typedef struct t_sysprc_inf
{
	VPARAM				Param;				/* プロセス固有パラメータ */
	SYSTIM_CPUTIME		ExecTime;			/* プロセス実行時間計測 */
} T_SYSPRC_INF;


/* ISR固有情報管理 */
typedef struct t_sysisr_inf
{
	SYSTIM_CPUTIME		ExecTime;			/* ISR実行時間計測 */
} T_SYSISR_INF;

extern SYSMTX_HANDLE	SysMem_hMtx;		/* システムメモリ管理用ミューテックス */
extern C_MEMPOL			SysMem_MemPol;		/* システムヒープメモリ */
extern T_SYSPRC_INF		*SysPrc_InfTbl;		/* プロセス管理用テーブル */
extern T_SYSISR_INF		*SysIsr_InfTbl;		/* ISR管理用テーブル */


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__sysapi_local_h__ */


/* end of file */
