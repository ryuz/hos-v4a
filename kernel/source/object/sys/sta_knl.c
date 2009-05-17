/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_knl.c
 * @brief %en{Start Kernel}%jp{OSの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/**** 暫定の手抜き(ここから) *****/
#if _KERNEL_SPT_DPC
_KERNEL_T_DPCMSG dpc_buf[32];
#endif
/**** 暫定の手抜き(ここまで) *****/




static void _kernel_sys_sta(void);		/** %jp{システムコンテキストの開始} */


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
	
	/* %jp{初期化ハンドラ実行} */
	_kernel_cfg_ini();

#if _KERNEL_SPT_DPC
	_KERNEL_SYS_INI_DPC(dpc_buf, 32);
#endif
	
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
	
	
	_KERNEL_LEAVE_SVC();
	
	/* %jp{初期化ハンドラ実行} */
	_kernel_cfg_sta();
	
	_KERNEL_ENTER_SVC();
	
	
	/* %jp{初期コンテキストの開始} */
	_kernel_sta_ctx(_KERNEL_SYS_GET_SYSCTXCB());
	
	return E_OK;	/* %jp{成功} */
}


/** %jp{システムコンテキストの開始} */
void _kernel_sys_sta(void)
{
	/* %jp{タスク状態に遷移} */
	_KERNEL_SYS_CLR_CTX();
	_KERNEL_SYS_CLR_LOC();
	_KERNEL_SYS_CLR_DSP();
	_KERNEL_SYS_CLR_SYS();
	
	/* %jp{DPC対応ならここで割込み許可} */
#if _KERNEL_SPT_DPC
	_KERNEL_ENA_INT();
#endif
	
	/* %jp{タスクディスパッチ開始} */
	_KERNEL_DSP_TSK();
	
	/* %jp{以降システムコンテキストをアイドルとして利用} */
	_KERNEL_LEAVE_SVC();
	_kernel_idl_lop();
}


/* end of file */
