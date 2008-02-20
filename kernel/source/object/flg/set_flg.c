/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  set_flg.c
 * @brief %jp{イベントフラグのセット}%en{Set Eventflag}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



#if _KERNEL_SPT_SET_FLG


/** %jp{イベントフラグのセット}%en{Set Eventflag}
 * @param  flgid    %jp{セット対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{セットするビットパターン}%en{Bit pattern to set}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象イベントフラグが未登録)}%en{Non-existant object(specified eventflag is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(setptnが不正)}%en{Parameter error(setptn is invalid)}
 */
ER set_flg(ID flgid, FLGPTN setptn)
{
	_KERNEL_T_QUE    *pk_que;
	_KERNEL_T_FLGCB  *flgcb;
	_KERNEL_T_FLGINF *pk_flginf;
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TCB    *tcb;
	BOOL             wupflg = FALSE;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_SET_FLG_E_ID
	if ( !_KERNEL_FLG_CHECK_FLGID(flgid) )
	{
		return E_ID;	/* %jp{ID不正} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコール開始} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_SET_FLG_E_NOEXS
	if ( !_KERNEL_FLG_CHECK_EXS(flgid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
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
			wupflg = TRUE;

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
	
	/* タスクディスパッチの実行 */
	if ( wupflg )
	{
		_KERNEL_DSP_TSK();
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
	
	return E_OK;	/* 成功 */
}


#else	/* _KERNEL_SPT_SET_FLG */


#if _KERNEL_SPT_SET_FLG_E_NOSPT

/** %jp{イベントフラグのセット}%en{Set Eventflag}
 * @param  flgid    %jp{セット対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{セットするビットパターン}%en{Bit pattern to set}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER set_flg(ID flgid, FLGPTN setptn)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_SET_FLG */


/* end of file */
