/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  twai_flg.c
 * @brief %jp{イベントフラグ待ち(タイムアウトあり)}%en{Wait for Eventflag(with Timeout)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



#if _KERNEL_SPT_TWAI_FLG


/** %jp{イベントフラグ待ち(タイムアウトあり)}%en{Wait for Eventflag(with Timeout)}
 * @param  flgid    %jp{待ち対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{待ちビットパターン}%en{Wait bit pattern}
 * @param  wfmode   %jp{待ちモード}%en{Wait mode}
 * @param  p_flgptn %jp{待ち解除時のビットパターンの返却アドレス}%en{Bit pattern causing a task to be released from waiting}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_CTX    %jp{コンテキストエラー}%en{Context error}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象イベントフラグが未登録)}%en{Non-existant object(specified eventflag is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(waiptn, wfmode, p_flgptnが不正)}%en{Parameter error(waiptn, wfmode, or p_flgptn is invalid)}
 * @retval E_ILUSE  %jp{サービスコール不正使用（TA_WSGL属性が指定されたイベントフラグで待ちタスクあり}%en{Illegal service call use(there is already a task waiting for an eventflag with tahe TA_WSGL attribute)}
 * @retval E_RLWAI  %jp{待ち状態の強制解除(待ち状態の間にrel_waiを受付)}%en{Forced release from waiting(accept rel_wai while waiting)}
 * @retval E_DLT    %jp{待ちオブジェクトの削除(待ち状態の間に対象イベントフラグが削除)}%en{Waiting object deleted(eventflag is deleted waiting)}
 */
ER twai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn, TMO tmout)
{
	_KERNEL_T_FLGINF flginf;
	_KERNEL_T_FLGHDL flghdl;
	_KERNEL_T_TSKHDL tskhdl;
	ER               ercd;

	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_WAI_FLG_E_CTX
	if ( _KERNEL_SYS_SNS_DPN() && tmout != TMO_POL )
	{
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif

	/* %jp{ID のチェック} */
#ifdef _KERNEL_SPT_TWAI_FLG_E_ID
	if ( !_KERNEL_FLG_CHECK_FLGID(flgid) )
	{
		return E_ID;	/* %jp{ID不正} */
	}
#endif
	
	/* %jp{パラメータのチェック} */
#ifdef _KERNEL_SPT_TWAI_FLG_E_PAR
	if ( waiptn == 0 )
	{
		return E_PAR;	/* %jp{パラメータ不正} */
	}
#endif


	_KERNEL_ENTER_SVC();		/* %jp{サービスコール開始} */
	
	/* %jp{オブジェクト存在チェック} */
#ifdef _KERNEL_SPT_TWAI_FLG_E_NOEXS
	if ( !_KERNEL_FLG_CHECK_EXS(flgid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{イベントフラグハンドル取得} */
	flghdl = _KERNEL_FLG_ID2FLGHDL(flgid);

#if _KERNEL_SPT_TWAI_FLG_E_ILUSE
	if ( !(_KERNEL_FLG_GET_FLGATR(flghdl) & TA_WMUL) && _kernel_ref_que(pk_que) != _KERNEL_TSKHDL_NULL && tmout != TMO_POL )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_ILUSE;
	}
#endif

	/* %jp{待ち条件設定} */
	flginf.waiptn = waiptn;
	flginf.wfmode = wfmode;
	
	/* %jp{フラグチェック} */
	if ( _kernel_chk_flg(flghdl, &flginf) )
	{
		/* %jp{既に条件を満たしているなら} */
		*p_flgptn = _KERNEL_FLG_GET_FLGPTN(flghdl);		/* %jp{解除時のフラグパターンを格納} */

#if _KERNEL_SPT_FLG_TA_CLR
		if ( _KERNEL_FLG_GET_FLGATR(flghdl) & TA_CLR )
		{
			_KERNEL_FLG_SET_FLGPTN(flghdl, 0);			/* %jp{クリア属性があればクリア} */
		}
#endif
		
		ercd = E_OK;
	}
	else
	{
		if ( tmout != TMO_POL )
		{
			/* %jp{タスクを待ち状態にする} */
			tskhdl = _KERNEL_SYS_GET_RUNTSK();
			_KERNEL_DSP_WAI_TSK(tskhdl);
			_KERNEL_TSK_SET_TSKSTAT(tskhdl, _KERNEL_TTS_WAI);
			_KERNEL_TSK_SET_TSKWAIT(tskhdl, _KERNEL_TTW_SEM);
			_KERNEL_TSK_SET_WOBJID(tskhdl, flgid);
			_KERNEL_TSK_SET_DATA(tskhdl, (VP_INT)&flginf);
			_KERNEL_FLG_ADD_QUE(flghdl, tskhdl);				/* %jp{待ち行列に追加} */

			if ( tmout != TMO_FEVR )
			{
				_KERNEL_ADD_TOQ(tskhdl, tmout);					/* %jp{タイムアウトキューに追加} */
			}
	
			/* %jp{タスクディスパッチの実行} */
			_KERNEL_DSP_TSK();

			/* %jp{エラーコードの取得} */
			ercd = _KERNEL_TSK_GET_ERCD(tskhdl);

			/* %jp{条件を満たして解除されたのなら} */
			if ( ercd == E_OK )
			{
				if ( p_flgptn != NULL )
				{
					*p_flgptn = flginf.waiptn;			/* %jp{解除時のフラグパターンを格納} */
				}
			}
		}
		else
		{
			ercd = E_TMOUT;  /* %jp{タイムアウト}%en{Timeout} */
		}
	}
		
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
	
	return ercd;	/* 成功 */
}


#else	/* _KERNEL_SPT_TWAI_FLG */


#if _KERNEL_SPT_TWAI_FLG_E_NOSPT

/** %jp{イベントフラグ待ち}%en{Wait for Eventflag}
 * @param  flgid    %jp{待ち対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{待ちビットパターン}%en{Wait bit pattern}
 * @param  wfmode   %jp{待ちモード}%en{Wait mode}
 * @param  p_flgptn %jp{待ち解除時のビットパターンの返却アドレス}%en{Bit pattern causing a task to be released from waiting}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER twai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn, TMO tmout)
{
	return E_NOSPT;
}

#endif

#endif	/* _KERNEL_SPT_TWAI_FLG */


/* end of file */
