/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ipsnd_dt.c
 * @brief %jp{データキューへの送信(ポーリング 非タスクコンテキスト用)}%en{Send to Data Queue}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/dtqobj.h"



#if _KERNEL_SPT_IPSND_DTQ

#if _KERNEL_SPT_DPC

static void _kernel_dpc_psnd_dtq(ID dtqid, VP_INT data);

/** %jp{データキューへの送信}%en{Send to Data Queue}
 * @param  dtqid    %jp{送信対象のデータキューのID番号}%en{ID number of the data queue to which the data element is sent}
 * @param  data     %jp{データキューへ送信するデータ}%en{Data element tobe sent}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(dtqidが不正あるいは使用できない)}%en{Invalid ID number(dtqid is invalid or unusable)}
 * @retval E_NOMEM  %jp{遅延実行用のキューイングメモリ不足}%en{Insufficient memory to store a service call for delayed execution}
 */
ER ipsnd_dtq(ID dtqid, VP_INT data)
{
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_IPSND_DTQ_E_ID
	if ( !_KERNEL_DTQ_CHECK_DTQID(dtqid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	return _KERNEL_SYS_REQ_DPC(_kernel_dpc_psnd_dtq, dtqid, data);
}


void _kernel_dpc_psnd_dtq(ID dtqid, VP_INT data)
{
	_KERNEL_T_DTQCB  *dtqcb;
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;
	

	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_SND_DTQ_E_NOEXS
	if ( !_KERNEL_DTQ_CHECK_EXS(dtqid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return;					/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{データキューコントロールブロック取得} */
	dtqcb = _KERNEL_DTQ_ID2DTQCB(dtqid);
	
	/* %jp{受信待ち行列先頭からタスク取り出し} */
	tskhdl = _KERNEL_DTQ_RMH_RQUE(dtqcb);
	if ( tskhdl != _KERNEL_TSKHDL_NULL )
	{
		VP_INT *p_data;

		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
		_KERNEL_TSK_SET_ERCD(tcb, E_OK);			/* %jp{エラーコード設定} */
		p_data = (VP_INT *)_KERNEL_TSK_GET_DATA(tcb);
		*p_data = data;
		_KERNEL_DSP_WUP_TSK(tskhdl);				/* %jp{タスクの待ち解除} */
		_KERNEL_DTQ_RMV_RTOQ(tskhdl);
	}
	else
	{
		const _KERNEL_T_DTQCB_RO *dtqcb_ro;
		_KERNEL_DTQ_T_DTQCNT     sdtqcnt;
		_KERNEL_DTQ_T_DTQCNT     dtqcnt;
		
		/* %jp{RO部取得} */
		dtqcb_ro = _KERNEL_DTQ_GET_DTQCB_RO(dtqid, dtqcb);

		/* %jp{データキューカウンタ取得} */
		sdtqcnt = _KERNEL_DTQ_GET_SDTQCNT(dtqcb);
		dtqcnt  = _KERNEL_DTQ_GET_DTQCNT(dtqcb_ro);

		if ( sdtqcnt < dtqcnt )		/* %jp{キューに空きはあるか？} */
		{
			_KERNEL_DTQ_T_DTQCNT head;
			VP_INT               *dtq;

			/* %jp{データキュー情報取得} */
			head = _KERNEL_DTQ_GET_HEAD(dtqcb);
			dtq  = _KERNEL_DTQ_GET_DTQ(dtqcb_ro);

			/* %jp{データキュー末尾に追加} */
			if ( head < dtqcnt - sdtqcnt - 1 )
			{
				dtq[head + sdtqcnt] = data;
			}
			else
			{
				dtq[head + sdtqcnt - dtqcnt] = data;
			}
			
			/* %jp{データ個数加算} */
			sdtqcnt++;
			_KERNEL_DTQ_SET_SDTQCNT(dtqcb, sdtqcnt);
		}
	}
}


#else	/* _KERNEL_SPT_DPC */

/** %jp{データキューへの送信(ポーリング 非タスクコンテキスト用)}%en{Send to Data Queue}
 * @param  dtqid    %jp{送信対象のデータキューのID番号}%en{ID number of the data queue to which the data element is sent}
 * @param  data     %jp{データキューへ送信するデータ}%en{Data element tobe sent}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(dtqidが不正あるいは使用できない)}%en{Invalid ID number(dtqid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象データキューが未登録)}%en{Non-existant object(specified data queue is not registerd)}
 * @retval E_TMOUT  %jp{ポーリング失敗}%en{Polling failure}
 */
ER ipsnd_dtq(ID dtqid, VP_INT data)
{
	return psnd_dtq(dtqid, data);
}

#endif	/* _KERNEL_SPT_DPC */




#else	/* _KERNEL_SPT_IPSND_DTQ */


#if _KERNEL_SPT_SND_DTQ_E_NOSPT

/** %jp{データキューへの送信}%en{Send to Data Queue}
 * @param  dtqid    %jp{送信対象のデータキューのID番号}%en{ID number of the data queue to which the data element is sent}
 * @param  data     %jp{データキューへ送信するデータ}%en{Data element tobe sent}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER ipsnd_dtq(ID dtqid, VP_INT data)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_SIPSND_DTQ */



/* end of file */
