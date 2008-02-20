/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  fsnd_dtq.c
 * @brief %jp{データキューへの強制送信}%en{Forced Send to Data Queue}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/dtqobj.h"



#if _KERNEL_SPT_FSND_DTQ


/** %jp{データキューへの強制送信}%en{Forced Send to Data Queue}
 * @param  dtqid    %jp{送信対象のデータキューのID番号}%en{ID number of the data queue to which the data element is sent}
 * @param  data     %jp{データキューへ送信するデータ}%en{Data element tobe sent}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(dtqidが不正あるいは使用できない)}%en{Invalid ID number(dtqid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象データキューが未登録)}%en{Non-existant object(specified data queue is not registerd)}
 */
ER fsnd_dtq(ID dtqid, VP_INT data)
{
	_KERNEL_T_DTQCB          *dtqcb;
	const _KERNEL_T_DTQCB_RO *dtqcb_ro;
	_KERNEL_T_TSKHDL         tskhdl;
	_KERNEL_T_TCB            *tcb;
	_KERNEL_DTQ_T_DTQCNT     dtqcnt;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_FSND_DTQ_E_ID
	if ( !_KERNEL_DTQ_CHECK_DTQID(dtqid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif

	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_FSND_DTQ_E_NOEXS
	if ( !_KERNEL_DTQ_CHECK_EXS(dtqid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{データキューコントロールブロック取得} */
	dtqcb    = _KERNEL_DTQ_ID2DTQCB(dtqid);
	dtqcb_ro = _KERNEL_DTQ_GET_DTQCB_RO(dtqid, dtqcb);	/* %jp{RO部取得} */

	/* %jp{データキュー領域の容量取得} */
	dtqcnt = _KERNEL_DTQ_GET_DTQCNT(dtqcb_ro);

#if _KERNEL_SPT_FSND_DTQ_E_ILUSE
	if ( dtqcnt == 0 )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_ILUSE;			/* %jp{サービスコール不正使用} */
	}
#endif
	
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
		
		/* %jp{タスクディスパッチの実行} */
		_KERNEL_DSP_TSK();
	}
	else
	{
		_KERNEL_DTQ_T_DTQCNT sdtqcnt;
		_KERNEL_DTQ_T_DTQCNT head;
		VP_INT               *dtq;
		
		/* %jp{データキュー情報取得} */
		sdtqcnt = _KERNEL_DTQ_GET_SDTQCNT(dtqcb);
		head    = _KERNEL_DTQ_GET_HEAD(dtqcb);
		dtq     = _KERNEL_DTQ_GET_DTQ(dtqcb_ro);

		if ( sdtqcnt < dtqcnt )		/* %jp{キューに空きはあるか？} */
		{
			/* %jp{データキューに追加} */
			if ( head < dtqcnt - sdtqcnt - 1 )
			{
				dtq[head + sdtqcnt] = data;
			}
			else
			{
				dtq[head + sdtqcnt - dtqcnt] = data;
			}
			sdtqcnt++;
			_KERNEL_DTQ_SET_SDTQCNT(dtqcb, sdtqcnt);
		}
		else
		{
			/* %jp{データキューに強制追加} */
			dtq[head] = data;

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
		}		
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;	/* %jp{正常終了}%en{Normal completion} */
}


#else	/* _KERNEL_SPT_FSND_DTQ */


#if _KERNEL_SPT_FSND_DTQ_E_NOSPT

/** %jp{データキューへの強制送信}%en{Forced Send to Data Queue}
 * @param  dtqid    %jp{送信対象のデータキューのID番号}%en{ID number of the data queue to which the data element is sent}
 * @param  data     %jp{データキューへ送信するデータ}%en{Data element tobe sent}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER fsnd_dtq(ID dtqid, VP_INT data)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_FSND_DTQ */



/* end of file */
