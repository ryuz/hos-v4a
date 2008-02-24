/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ext_tsk.c
 * @brief %jp{タスクの終了}%en{Exit Task}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"


/** %jp{タスクの強制終了}
 * @return void
 */
ER ter_tsk(ID tskid)
{
	_KERNEL_T_TSKHDL		tskhdl;
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TCB_RO_PTR	tcb_ro;
	_KERNEL_TSK_T_ACTCNT	actcnt;
	
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_TER_TSK_E_ID
	if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
	{
		return E_ID;	/* %jp{ID不正} */
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */

	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_TER_TSK_E_NOEXS
	if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールを出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif


	/* %jp{コントロールブロック取得} */
	tcb    = _KERNEL_TSK_ID2TCB(tskid);
    tskhdl = _KERNEL_TSK_GET_TSKHDL(tskid, tcb);

	/* %jp{実行中タスクならエラー} */
#if _KERNEL_SPT_TER_TSK_E_ILUSE
	if ( tskhdl == _KERNEL_SYS_GET_RUNTSK() )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールを出る}%en{leave service-call} */
		return E_ILUSE;				/* %jp{サービスコール不正使用} */
	}
#endif
	
	
	/* 状態チェック */
#if _KERNEL_SPT_TER_TSK_E_OBJ
	if ( _KERNEL_TSK_GET_TSKSTAT(tcb) == _KERNEL_TTS_DMT )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールを出る}%en{leave service-call} */
		return E_OBJ;				/* %jp{オブジェクト状態エラー} */
	}

#endif
	
	
	/* タスクを終了させる */
	_KERNEL_DSP_TER_TSK(tskhdl);
	
	
	/* %jp{所有ミューテックスがあれば開放} */
#if _KERNEL_SPT_MTX
	{
		_KERNEL_T_MTXHDL mtxhdl;
		while ( (mtxhdl = _KERNEL_TSK_GET_MTXHDL(tcb)) != _KERNEL_MTXHDL_NULL )
		{
			_kernel_rmv_mtx(mtxhdl, tskhdl);
		}
	}
#endif
	
	/* %jp{起動要求ネストのチェック} */
	actcnt = _KERNEL_TSK_GET_ACTCNT(tcb);	
	if ( actcnt > 0 )	/* %jp{起動要求ネストがあるなら再生成} */
	{
		_KERNEL_TSK_T_TPRI itskpri;

		tcb_ro = _KERNEL_TSK_GET_TCB_RO(tskid, tcb);
		_KERNEL_TSK_SET_ACTCNT(tcb, actcnt - 1);
		itskpri = _KERNEL_TSK_GET_ITSKPRI(tcb_ro);
		_KERNEL_TSK_SET_TSKPRI(tcb, itskpri);
		_KERNEL_TSK_SET_TSKBPRI(tcb, itskpri);
		
		/* %jp{レディーキュー再接続} */
		_KERNEL_DSP_STA_TSK(tskhdl);						
	}
	else				/* %jp{起動要求ネストがなければ終了} */
	{
		_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_DMT);
	}
	
	/* %jp{タスクディスパッチの実行}%en{task dispatch} */
	_KERNEL_DSP_TSK();
	
	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールを出る}%en{leave service-call} */

	return E_OK;
}


/* end of file */
