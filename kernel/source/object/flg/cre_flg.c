/**
 *  Hyper Operating System V4 Advance
 *
 * @file  cre_flg.c
 * @brief %jp{イベントフラグの生成}%en{Create Eventflag}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



#if _KERNEL_SPT_CRE_FLG


/** %jp{イベントフラグの生成}%en{Create Eventflag}
 * @param  flgid    %jp{生成対象のイベントフラグのID番号}%en{ID number of the eventflag to be created}
 * @param  pk_cflg	%jp{イベントフラグ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the eventflag creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_RSATR  %jp{予約属性(flgatrが不正あるいは使用できない)}%en{Reserved attribute(flgatr is invalid or unusable)}
 * @retval E_OBJ    %jp{オブジェクト状態エラー(対象イベントフラグが登録済み)}%en{Object state error(specified eventflag is already registerd)}
 */
ER cre_flg(ID flgid, const T_CFLG *pk_cflg)
{
	ER ercd;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_CRE_FLG_E_ID
	if ( !_KERNEL_FLG_CHECK_FLGID(flgid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif

	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_ACRE_FLG_E_RSATR
	if ( ((pk_cflg->flgatr & TA_TPRI) == 0 && !_KERNEL_SPT_FLG_TA_TFIFO)
		|| ((pk_cflg->flgatr & TA_TPRI) != 0 && !_KERNEL_SPT_FLG_TA_TPRI)
		|| ((pk_cflg->flgatr & TA_WMUL) == 0 && !_KERNEL_SPT_FLG_TA_WSGL)
		|| ((pk_cflg->flgatr & TA_WMUL) != 0 && !_KERNEL_SPT_FLG_TA_WMUL)
		|| ((pk_cflg->flgatr & TA_CLR)  != 0 && !_KERNEL_SPT_FLG_TA_CLR) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_CRE_FLG_E_OBJ
	if ( _KERNEL_FLG_CHECK_EXS(flgid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;			/* %jp{オブジェクト状態エラー}%en{Object state error} */
	}
#endif
	
	/* %jp{イベントフラグ生成} */
	ercd = _kernel_cre_flg(flgid, pk_cflg);

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;
}


#else	/* _KERNEL_SPT_CRE_FLG */


#if _KERNEL_SPT_CRE_FLG_E_NOSPT

/** %jp{イベントフラグの生成}%en{Create Eventflag}
 * @param  flgid    %jp{生成対象のイベントフラグのID番号}%en{ID number of the eventflag to be created}
 * @param  pk_cflg	%jp{イベントフラグ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the eventflag creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER cre_flg(const T_CFLG *pk_cflg)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_CRE_FLG */



/* end of file */
