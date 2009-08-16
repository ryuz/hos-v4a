/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rcv_dtq.c
 * @brief %jp{データキューへの送信}%en{Send to Data Queue}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/dtqobj.h"



#if _KERNEL_SPT_RCV_DTQ


/** %jp{データキューからの受信} */
ER rcv_dtq(ID dtqid, VP_INT *p_data)
{
	_KERNEL_T_DTQCB				*dtqcb;
	const _KERNEL_T_DTQCB_RO	*dtqcb_ro;
	_KERNEL_T_TSKHDL			tskhdl;
	_KERNEL_T_TCB				*tcb;
	_KERNEL_DTQ_T_DTQCNT		sdtqcnt;
	ER							ercd;
	
	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_RCV_DTQ_E_CTX
	if ( _KERNEL_SYS_SNS_DPN() )
	{
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif

	/* %jp{ID のチェック} */
#if _KERNEL_SPT_RCV_DTQ_E_ID
	if ( !_KERNEL_DTQ_CHECK_DTQID(dtqid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif

	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_RCV_DTQ_E_NOEXS
	if ( !_KERNEL_DTQ_CHECK_EXS(dtqid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{データキューコントロールブロック取得} */
	dtqcb = _KERNEL_DTQ_ID2DTQCB(dtqid);
	
	/* %jp{送信待ち行列先頭からタスク取り出し} */
	tskhdl = _KERNEL_DTQ_RMH_SQUE(dtqcb);
	if ( tskhdl != _KERNEL_TSKHDL_NULL )
	{
		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
		
		/* %jp{タスクを起す} */
		_KERNEL_TSK_SET_ERCD(tcb, E_OK);	/* %jp{エラーコード設定} */
		_KERNEL_DSP_WUP_TSK(tskhdl);		/* %jp{タスクの待ち解除} */
		_KERNEL_DTQ_RMV_STOQ(tskhdl);		/* %jp{タイムアウトキューからはずす} */
	}
	
	
#if _KERNEL_SPT_DTQ_DTQCNT_NONZERO		/* %jp{データキュー情報取得} */
	sdtqcnt = _KERNEL_DTQ_GET_SDTQCNT(dtqcb);
	if ( sdtqcnt > 0 )		/* %jp{キューにデータはあるか？} */
	{
		_KERNEL_DTQ_T_DTQCNT		dtqcnt;
		VP_INT						*dtq;
		_KERNEL_DTQ_T_DTQCNT		head;
		
		/* %jp{RO部取得} */
		dtqcb_ro = _KERNEL_DTQ_GET_DTQCB_RO(dtqid, dtqcb);
		
		/* %jp{データキュー取得} */
		dtq = _KERNEL_DTQ_GET_DTQ(dtqcb_ro);
		
		/* %jp{キューからデータを取り出し} */
		head   = _KERNEL_DTQ_GET_HEAD(dtqcb);
		dtqcnt = _KERNEL_DTQ_GET_DTQCNT(dtqcb_ro);
		*p_data = dtq[head];
		
		/* %jp{送信待ちタスクがあればデータを追加} */
		if ( tskhdl != _KERNEL_TSKHDL_NULL )
		{
			/* %jp{送信データ格納} */
			tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
			dtq[head] = (VP_INT)_KERNEL_TSK_GET_DATA(tcb);
		}
		else
		{
			/* %jp{送信待ちが無ければキューのデータ個数を減ずる} */
			sdtqcnt--;
			_KERNEL_DTQ_SET_SDTQCNT(dtqcb, sdtqcnt);
		}
		
		/* %jp{先頭位置をずらす} */
		if ( head + 1 < dtqcnt )
		{
			head++;
		}
		else
		{
			head = 0;
		}
		_KERNEL_DTQ_SET_HEAD(dtqcb, head);

		if ( tskhdl != _KERNEL_TSKHDL_NULL )
		{
			/* %jp{タスクディスパッチの実行} */
			_KERNEL_DSP_TSK();
		}
		
		ercd = E_OK;	/* %jp{正常終了}%en{Normal completion} */
	}
	else
#endif
	{
#if _KERNEL_SPT_DTQ_DTQCNT_ZERO
		if ( tskhdl != _KERNEL_TSKHDL_NULL )
		{
			/* %jp{送信データ取得} */
			tcb     = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
			*p_data = (VP_INT)_KERNEL_TSK_GET_DATA(tcb);	/* %jp{送信データ格納} */

			/* %jp{タスクディスパッチの実行} */
			_KERNEL_DSP_TSK();

			ercd = E_OK;	/* %jp{正常終了}%en{Normal completion} */
		}
		else
#endif
		{
			/* %jp{RO部取得} */
			dtqcb_ro = _KERNEL_DTQ_GET_DTQCB_RO(dtqid, dtqcb);
			
			/* %jp{実行中タスクを取得} */
			tskhdl = _KERNEL_SYS_GET_RUNTSK();			/* %jp{タスクハンドル取得} */
			tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);	/* %jp{TCB取得} */
			
			/* %jp{受信データ格納アドレス設定} */
			_KERNEL_TSK_SET_DATA(tcb, (VP_INT)p_data);
			
			/* %jp{タスクを待ち状態にする} */
			_KERNEL_TSK_SET_TSKWAIT(tcb, _KERNEL_TTW_RDTQ);		/* %jp{待ち要因設定} */
			_KERNEL_TSK_SET_WOBJID(tcb, dtqid);					/* %jp{待ちオブジェクトID設定} */
			_KERNEL_DSP_WAI_TSK(tskhdl);						/* %jp{待ち状態に設定} */
			_KERNEL_DTQ_ADD_RQUE(dtqcb, dtqcb_ro, tskhdl);		/* %jp{待ち行列に追加} */
			
			/* %jp{タスクディスパッチの実行} */
			_KERNEL_DSP_TSK();
			
			/* %jp{エラーコードの取得} */
			ercd = _KERNEL_TSK_GET_ERCD(tcb);
		}		
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;
}


#else	/* _KERNEL_SPT_RCV_DTQ */


#if _KERNEL_SPT_RCV_DTQ_E_NOSPT

/** %jp{データキューへの送信}%en{Send to Data Queue}
 * @param  dtqid    %jp{送信対象のデータキューのID番号}%en{ID number of the data queue to which the data element is sent}
 * @param  data     %jp{データキューへ送信するデータ}%en{Data element tobe sent}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER snd_dtq(ID dtqid, VP_INT data)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_RCV_DTQ */



/* end of file */
