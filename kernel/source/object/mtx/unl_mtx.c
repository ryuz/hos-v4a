/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  unl_mtx.c
 * @brief %jp{ミューテックスのロック解除}%en{Unlock mutex}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"



#if _KERNEL_SPT_UNL_MTX


/** %jp{ミューテックスのロック解除} */
ER unl_mtx(ID mtxid)
{
	_KERNEL_T_MTXCB_PTR		mtxcb;
	_KERNEL_T_MTXHDL		mtxhdl;
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TSKHDL		tskhdl;
		
	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_UNL_MTX_E_CTX
	if ( _KERNEL_SYS_SNS_CTX() )
	{
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_UNL_MTX_E_ID
	if ( !_KERNEL_MTX_CHECK_MTXID(mtxid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_UNL_MTX_E_NOEXS
	if ( !_KERNEL_MTX_CHECK_EXS(mtxid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif
	
	/* %jp{ミューテックスコントロールブロック取得} */
	mtxcb = _KERNEL_MTX_ID2MTXCB(mtxid);

	/* %jp{実行中のタスクハンドルを取得} */
	tskhdl = _KERNEL_SYS_GET_RUNTSK();
		
	/* %jp{自分が所有しているかチェック} */
#if _KERNEL_SPT_UNL_MTX_E_ILUSE
	if ( tskhdl != tskhdl )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_ILUSE;			/*  */
	}
#endif
	
	tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	mtxhdl = _KERNEL_MTX_GET_MTXHDL(mtxid, mtxcb);
	
	/* %jp{ミューテックを取り外し} */
	_kernel_rmv_mtx( mtxhdl, tcb);
	
	/* %jp{所有ミューテックスが無くなったら} */
	if ( _KERNEL_TSK_GET_MTXHDL(tcb) == _KERNEL_MTXHDL_NULL )
	{
		_KERNEL_TSK_T_TPRI tskpri;
		_KERNEL_TSK_T_TPRI tskbpri;

		tskpri  = _KERNEL_TSK_GET_TSKPRI(tcb);	
		tskbpri = _KERNEL_TSK_GET_TSKBPRI(tcb);	
		
		/* %jp{優先度格上げが行われていればベース優先度に戻す} */
		if ( tskpri != tskbpri )
		{
			_kernel_chg_pri(tskhdl, tskbpri);
		}
	}
	
	/* %jp{タスクディスパッチの実行} */
	_KERNEL_DSP_TSK();

	_KERNEL_LEAVE_SVC();	/* %jp{オブジェクト未生成}%en{Non-existant object} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_UNL_MTX */


#if _KERNEL_SPT_UNL_MTX_E_NOSPT

/** %jp{ミューテックスのロック解除} */
ER unl_mtx(ID mtxid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_LOC_MTX */



/* end of file */
