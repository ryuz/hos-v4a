/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_knl.c
 * @brief %en{Start Kernel}%jp{OSの起動}
 *
 * @version $Id: sta_knl.c,v 1.1 2006-08-16 16:27:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/isrobj.h"



_KERNEL_T_SYSCB _kernel_syscb;

extern VP   _kernel_idl_stk;
extern SIZE _kernel_idl_stksz;


static void _kernel_sys_sta(void);


/** %jp{カーネルの開始(独自サービスコール)}%en{Start Kernel}
 * @return void
 */
ER vsta_knl(void)
{
	/* %jp{システムの初期化} */
	_KERNEL_SYS_INI_SYS();
	
	/* %jp{プロセッサ固有の初期化} */
	_KERNEL_INI_PRC();

	
	_KERNEL_ENTER_SVC();
	
	/* %jp{初期化ルーチンは非タスク部扱い} */
	_KERNEL_SYS_SET_CTX();
	_KERNEL_SYS_SET_LOC();
	
	/* %jp{IRC固有の初期化} */
	_KERNEL_INI_IRC();
	
	
	_kernel_syscb.proccb[0].sysstk   = _kernel_idl_stk;
	_kernel_syscb.proccb[0].sysstksz = _kernel_idl_stksz;
	
	
	/* %jp{システムコンテキストの生成} */
	_KERNEL_CRE_CTX(
			_KERNEL_SYS_GET_SYSCTXCB(),
			_KERNEL_SYS_GET_SYSSTKSZ(),
			_KERNEL_SYS_GET_SYSSTK(),
			_KERNEL_SYS_GET_SYSISP(),
			(FP)_kernel_sys_sta,
			(VP_INT)0,
			(VP_INT)0
		);
	
	/* %jp{初期化ハンドラ実行} */
	_kernel_cfg_ini();

	_KERNEL_LEAVE_SVC();

	/* %jp{初期化ハンドラ実行} */
	_kernel_cfg_sta();

	_KERNEL_ENTER_SVC();

	
	/* %jp{初期コンテキストの開始} */
	_kernel_sta_ctx(_KERNEL_SYS_GET_SYSCTXCB());
	
	return E_OK;	/* %jp{成功} */
}


void _kernel_sys_sta(void)
{
	_KERNEL_SYS_CLR_CTX();
	_KERNEL_SYS_CLR_LOC();
	_KERNEL_SYS_CLR_DLY();

	_KERNEL_DSP_TSK();
	
	_KERNEL_LEAVE_SVC();
	
	_kernel_idl_lop();
}


/* end of file */
