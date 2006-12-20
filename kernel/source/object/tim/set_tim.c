/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  set_tim.c
 * @brief %jp{システム時刻の設定}%en{Set System Time}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_SET_TIM

/** %jp{システム時刻の設定}%en{Set System Time}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @return E_PAR    %jp{パラメータエラー(p_systemが不正)}%en{Parameter error(p_system is invalid)}
 */
ER set_tim(const SYSTIM *p_system)
{
#if _KERNEL_SPT_SET_TIM_E_PAR
	if ( !_KERNEL_CHKPTR_CONST(p_system) )
	{
		return E_PAR;
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */

	_KERNEL_SYS_SET_TIM(p_system);

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */

	return E_OK;
}


#else	/* _KERNEL_SPT_SET_TIM */


#if _KERNEL_SPT_SET_TIM_E_NOSPT

/** %jp{システム時刻の設定}%en{Set System Time}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER set_tim(const SYSTIM *p_system)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_SET_TIM */



/* end of file */
