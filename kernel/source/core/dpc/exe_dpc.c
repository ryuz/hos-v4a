/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dpc.h
 * @brief %jp{遅延プロシージャーコールヘッダファイル}%en{Deferred Procedure Call header file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "core/dpc.h"


#if _KERNEL_SPT_DPC

/* サービスコール退出時の処理 */
void _kernel_exe_dpc(void)
{
	FP fncSvc;

	/* 遅延プロシージャ呼び出し */
	while ( _KERNEL_SYS_RDT_DPC() > 0 )
	{
		fncSvc = (FP)_KERNEL_SYS_RCV_DPC();
		fncSvc();
	}

	/* タスクディスパッチの実施 */
	_KERNEL_DSP_TSK();
}


#endif	/* _KERNEL_SPT_DPC */


/* end of file */
