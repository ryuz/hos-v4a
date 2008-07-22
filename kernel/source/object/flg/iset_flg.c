/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  iset_flg.c
 * @brief %jp{イベントフラグのセット}%en{Set Eventflag}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"


#if _KERNEL_SPT_ISET_FLG

#if _KERNEL_SPT_DPC

static void _kernel_dpc_set_flg(ID flgid, VP_INT param);

/** %jp{イベントフラグのセット}%en{Set Eventflag}
 * @param  flgid    %jp{セット対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{セットするビットパターン}%en{Bit pattern to set}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_NOMEM  %jp{遅延実行用のキューイングメモリ不足}%en{Insufficient memory to store a service call for delayed execution}
 */
ER iset_flg(ID flgid, FLGPTN setptn)
{
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_ISET_FLG_E_ID
	if ( !_KERNEL_FLG_CHECK_FLGID(flgid) )
	{
		return E_ID;		/* %jp{ID不正} */
	}
#endif

	return _KERNEL_SYS_REQ_DPC(_kernel_dpc_set_flg, flgid, (VP_INT)setptn);
}


/** %jp{set_flgの遅延実行}%en{service call for delayed execution(set_flg)} */
void _kernel_dpc_set_flg(ID flgid, VP_INT param)
{
	_KERNEL_T_QUE    *pk_que;
	_KERNEL_T_FLGCB  *flgcb;
	_KERNEL_T_FLGINF *pk_flginf;
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TCB    *tcb;
	FLGPTN           setptn;
	
	/* %jp{パラメータ変換} */
	setptn = (FLGPTN) param;
	
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_ISET_FLG_E_NOEXS
	if ( !_KERNEL_FLG_CHECK_EXS(flgid) )
	{
		return;			/* %jp{オブジェクト未生成} */
	}
#endif

	/* %jp{コントロールブロック取得} */
	flgcb = _KERNEL_FLG_ID2FLGCB(flgid);

	/* %jp{待ち行列取得} */
	pk_que = _KERNEL_FLG_GET_QUE(flgcb);
	
	/* %jp{フラグセット} */
	_KERNEL_FLG_SET_FLGPTN(flgcb, _KERNEL_FLG_GET_FLGPTN(flgcb) | setptn);

	/* %jp{待ちタスクがあれば起床チェック} */
	tskhdl = _KERNEL_REF_QUE(pk_que);
	while ( tskhdl != _KERNEL_TSKHDL_NULL )
	{
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);					/* %jp{TCB取得} */

		tskhdl_next = _KERNEL_NXT_QUE(pk_que, tskhdl);			/* %jp{次の待ちタスクを取得} */

		/* %jp{フラグチェック} */
		pk_flginf = (_KERNEL_T_FLGINF *)_KERNEL_TSK_GET_DATA(tcb);
		if ( _kernel_chk_flg(flgcb, pk_flginf) )
		{
			/* %jp{起床条件を満たしているなら} */
			pk_flginf->waiptn = _KERNEL_FLG_GET_FLGPTN(flgcb);	/* %jp{現在のフラグパターンを格納} */
			
			/* %jp{待ち解除} */
			_KERNEL_TSK_SET_ERCD(tcb, E_OK);		/* %jp{エラーコード設定} */
			_KERNEL_RMV_QUE(pk_que, tskhdl);		/* %jp{待ち行列から取り外す} */
			_KERNEL_FLG_RMV_TOQ(tskhdl);			
			_KERNEL_DSP_WUP_TSK(tskhdl);			/* %jp{タスクの待ち解除} */
			
			/* %jp{待ち解除発生をマーク} */
			_KERNEL_SYS_SET_DLY();

#if _KERNEL_SPT_FLG_TA_CLR
			{
				const _KERNEL_T_FLGCB_RO *flgcb_ro;
				flgcb_ro = _KERNEL_FLG_GET_FLGCB_RO(flgid, flgcb);

				if ( _KERNEL_FLG_GET_FLGATR(flgcb_ro) & TA_CLR )
				{
					_KERNEL_FLG_SET_FLGPTN(flgcb, 0);			/* %jp{クリア属性があればクリア} */
					break;
				}
			}
#endif
		}
		tskhdl = tskhdl_next;	/* 次のタスクに進める */
	}
}

#else	/* _KERNEL_SPT_DPC */

/** %jp{イベントフラグ資源の返却}%en{Release Flgaphore Resource}
 * @param  flgid    %jp{イベントフラグ資源返却対象のイベントフラグのID番号}%en{ID number of the Eventflag to which resource is released}
 */
ER iset_flg(ID flgid, FLGPTN setptn)
{
	return set_flg(flgid, setptn);
}

#endif	/* _KERNEL_SPT_DPC */


#else	/* _KERNEL_SPT_SET_FLG */


#if _KERNEL_SPT_ISET_FLG_E_NOSPT

/** %jp{イベントフラグ資源の返却}%en{Release Flgaphore Resource}
 * @param  flgid    %jp{イベントフラグ資源返却対象のイベントフラグのID番号}%en{ID number of the Eventflag to which resource is released}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER iset_flg(ID flgid, FLGPTN setptn)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_SET_FLG */



/* end of file */
