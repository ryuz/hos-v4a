/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  get_tim.c
 * @brief %jp{システム時刻の参照}%en{Reference System Time}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_GET_TIM

/** %jp{システム時刻の参照}%en{Reference System Time}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @return E_PAR    %jp{パラメータエラー(p_systemが不正)}%en{Parameter error(p_system is invalid)}
 */
ER get_tim(SYSTIM *p_system)
{
#if _KERNEL_SPT_GET_TIM_E_PAR
	if ( !_KERNEL_CHKPTR_DATA(p_system) )
	{
		return E_PAR;
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */

	*p_system = *_KERNEL_SYS_GET_TIM();

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */

	return E_OK;
}


#else	/* _KERNEL_SPT_GET_TIM */


#if _KERNEL_SPT_SET_TIM_E_NOSPT

/** %jp{システム時刻の参照}%en{Reference System Time}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER get_tim(SYSTIM *p_system)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_GET_TIM */



/* end of file */
