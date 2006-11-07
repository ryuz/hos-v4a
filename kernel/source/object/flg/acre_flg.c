/**
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_flg.c
 * @brief %jp{イベントフラグの生成(ID番号自動割付)}%en{Create Eventflag(ID Number Automatic Assignment)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



#if _KERNEL_SPT_ACRE_FLG


/** %jp{イベントフラグの生成(ID番号自動割付)}%en{Create Eventflag(ID Number Automatic Assignment)}
 * @param  pk_cflg	      %jp{イベントフラグ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the eventflag creation information}
 * @retval %jp{正の値}%en{positiv-value} %jp{生成したイベントフラグのID番号}%en{ID number of the created eventflag}
 * @retval E_NOID  %jp{ID番号不足(割付可能なイベントフラグIDが無い)}%en{No ID number available(there id no eventflag ID assignable)}
 * @retval E_RSATR %jp{予約属性(flgatrが不正あるいは使用できない)}%en{Reserved attribute(flgatr is invalid or unusable)}
 */
ER_ID acre_flg(const T_CFLG *pk_cflg)
{
	ID    flgid;
	ER_ID erid;
	
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
	
	/* %jp{空きID探索} */
	for ( flgid = _KERNEL_FLG_TMAX_ID; flgid >= _KERNEL_FLG_TMIN_ID; flgid-- )
	{
		if ( !_KERNEL_FLG_CHECK_EXS(flgid) )
		{
			break;
		}
	}

	/* %jp{空きID探索チェック} */
#if _KERNEL_SPT_ACRE_SEM_E_NOID
	if ( flgid < _KERNEL_FLG_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;				/* %jp{ID番号不足}%en{No ID number available} */
	}
#endif
	
	/* %jp{イベントフラグ生成} */
	erid = (ER_ID)_kernel_cre_flg(flgid, pk_cflg);
	if ( erid == E_OK )
	{
		erid = (ER_ID)flgid;
	}

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}


#else	/* _KERNEL_SPT_ACRE_FLG */


#if _KERNEL_SPT_ACRE_FLG_E_NOSPT

/** %jp{イベントフラグの生成(ID番号自動割付)}%en{Create Eventflag(ID Number Automatic Assignment)}
 * @param  pk_cflg	      %jp{イベントフラグ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the eventflag creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER_ID acre_flg(const T_CFLG *pk_cflg)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ACRE_FLG */



/* end of file */
