/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  clr_flg.c
 * @brief %jp{イベントフラグのクリア}%en{Clear Eventflag}
 *
 * @version $Id: clr_flg.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



#if _KERNEL_SPT_CLR_FLG


/** %jp{イベントフラグのクリア}%en{Clear Eventflag}
 * @param  flgid    %jp{クリア対象のイベントフラグのID番号}%en{ID number of the eventflag to be cleared}
 * @param  clrptn   %jp{クリアするビットパターン(ビットごとの反転値)}%en{Bit pattern to clear(bit-wise negated)}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象イベントフラグが未登録)}%en{Non-existant object(specified eventflag is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(setptnが不正)}%en{Parameter error(setptn is invalid)}
 */
ER clr_flg(ID flgid, FLGPTN clrptn)
{
	_KERNEL_T_FLGHDL flghdl;
	
	/* %jp{ID のチェック} */
#ifdef _KERNEL_SPT_CLR_FLG_E_ID
	if ( !_KERNEL_FLG_CHECK_FLGID(flgid) )
	{
		return E_ID;	/* %jp{ID不正} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコール開始} */
	
	/* %jp{オブジェクト存在チェック} */
#ifdef _KERNEL_SPT_CLR_FLG_E_NOEXS
	if ( !_KERNEL_FLG_CHECK_EXS(flgid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	flghdl = _KERNEL_FLG_ID2FLGHDL(flgid);
	
	/* フラグクリア */
	_KERNEL_FLG_SET_FLGPTN(flghdl, _KERNEL_FLG_GET_FLGPTN(flghdl) & clrptn);

	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
	
	return E_OK;	/* 成功 */
}


#else	/* _KERNEL_SPT_CLR_FLG */


#if _KERNEL_SPT_CLR_FLG_E_NOSPT

/** %jp{イベントフラグのクリア}%en{Clear Eventflag}
 * @param  flgid    %jp{クリア対象のイベントフラグのID番号}%en{ID number of the eventflag to be cleared}
 * @param  clrptn   %jp{クリアするビットパターン(ビットごとの反転値)}%en{Bit pattern to clear(bit-wise negated)}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER clr_flg(ID flgid, FLGPTN clrptn)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_CLR_FLG */


/* end of file */
