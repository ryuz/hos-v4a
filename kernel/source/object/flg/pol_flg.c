/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  pol_flg.c
 * @brief %jp{イベントフラグ待ち(ポーリング)}%en{Wait for Eventflag(Polling)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



#if _KERNEL_SPT_POL_FLG


#if _KERNEL_SPT_TWAI_FLG && (_KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED)	/* %jp{twai_flgありで、コードサイズ優先なら} */

/** %jp{イベントフラグ待ち(ポーリング)}%en{Wait for Eventflag(Polling)}
 * @param  flgid    %jp{待ち対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{待ちビットパターン}%en{Wait bit pattern}
 * @param  wfmode   %jp{待ちモード}%en{Wait mode}
 * @param  p_flgptn %jp{待ち解除時のビットパターンの返却アドレス}%en{Bit pattern causing a task to be released from waiting}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象イベントフラグが未登録)}%en{Non-existant object(specified eventflag is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(waiptn, wfmode, p_flgptnが不正)}%en{Parameter error(waiptn, wfmode, or p_flgptn is invalid)}
 * @retval E_TMOUT  %jp{ポーリング失敗}%en{Polling failure}
 * @retval E_DLT    %jp{待ちオブジェクトの削除(待ち状態の間に対象イベントフラグが削除)}%en{Waiting object deleted(eventflag is deleted waiting)}
 */
ER pol_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
	/* %jp{twai_flg で代用し、コードサイズを削減する} */
	return twai_flg(flgid, waiptn, wfmode, p_flgptn, TMO_POL);
}

#else

/** %jp{イベントフラグ待ち}%en{Wait for Eventflag}
 * @param  flgid    %jp{待ち対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{待ちビットパターン}%en{Wait bit pattern}
 * @param  wfmode   %jp{待ちモード}%en{Wait mode}
 * @param  p_flgptn %jp{待ち解除時のビットパターンの返却アドレス}%en{Bit pattern causing a task to be released from waiting}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象イベントフラグが未登録)}%en{Non-existant object(specified eventflag is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(waiptn, wfmode, p_flgptnが不正)}%en{Parameter error(waiptn, wfmode, or p_flgptn is invalid)}
 * @retval E_TMOUT  %jp{ポーリング失敗}%en{Polling failure}
 * @retval E_DLT    %jp{待ちオブジェクトの削除(待ち状態の間に対象イベントフラグが削除)}%en{Waiting object deleted(eventflag is deleted waiting)}
 */
ER pol_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
	_KERNEL_T_FLGCB          *flgcb;
	_KERNEL_T_FLGINF         flginf;
	ER                       ercd;

	/* %jp{ID のチェック} */
#if _KERNEL_SPT_POL_FLG_E_ID
	if ( !_KERNEL_FLG_CHECK_FLGID(flgid) )
	{
		return E_ID;	/* %jp{ID不正} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコール開始} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_POL_FLG_E_NOEXS
	if ( !_KERNEL_FLG_CHECK_EXS(flgid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	
	/* %jp{コントロールブロック取得} */
	flgcb = _KERNEL_FLG_ID2FLGCB(flgid);
	
	/* %jp{待ち条件設定} */
	flginf.waiptn = waiptn;
	flginf.wfmode = wfmode;
	
	/* %jp{フラグチェック} */
	if ( _kernel_chk_flg(flgcb, &flginf) )
	{
		/* %jp{既に条件を満たしているなら} */
		*p_flgptn = _KERNEL_FLG_GET_FLGPTN(flgcb);			/* %jp{解除時のフラグパターンを格納} */

#if _KERNEL_SPT_FLG_TA_CLR
		if ( _KERNEL_FLG_GET_FLGATR(_KERNEL_FLG_GET_FLGCB_RO(flgid, flgcb)) & TA_CLR )
		{
			_KERNEL_FLG_SET_FLGPTN(flgcb, 0);		/* %jp{クリア属性があればクリア} */
		}
#endif
		
		ercd = E_OK;
	}
	else
	{
		ercd = E_TMOUT;
	}
		
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
	
	return ercd;	/* 成功 */
}

#endif


#else	/* _KERNEL_SPT_POL_FLG */


#if _KERNEL_SPT_POL_FLG_E_NOSPT

/** %jp{イベントフラグ待ち}%en{Wait for Eventflag}
 * @param  flgid    %jp{待ち対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{待ちビットパターン}%en{Wait bit pattern}
 * @param  wfmode   %jp{待ちモード}%en{Wait mode}
 * @param  p_flgptn %jp{待ち解除時のビットパターンの返却アドレス}%en{Bit pattern causing a task to be released from waiting}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER pol_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
	return E_NOSPT;
}

#endif

#endif	/* _KERNEL_SPT_POL_FLG */


/* end of file */
