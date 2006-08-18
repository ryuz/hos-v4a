/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  isig_tim.c
 * @brief %jp{タイムティックの供給}%en{Supply Time Tick}
 *
 * @version $Id: isig_tim.c,v 1.2 2006-08-18 08:43:31 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_SPT_ISIG_TIM

/** %jp{タイムティックの供給}%en{Supply Time Tick}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 */
ER isig_tim(void)
{
	RELTIM tictim;
	
	/* %jp{加算するタイムティックを算出} */
#if _KERNEL_SPT_TIC_NUME
	_kernel_tic_cnt--;
	if ( _kernel_tic_cnt < _kernel_tic_mod )
	{
		tictim = _kernel_tic_div + 1;	/* %jp{割り切れない分を補正} */
	}
	else
	{
		tictim = _kernel_tic_div;
	}
	if ( _kernel_tic_cnt == 0 )
	{
		_kernel_tic_cnt = kernel_tic_deno;
	}
#else
	tictim = 1;
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */

/*	_kernel_sig_tmq(tictim);	*/

	_kernel_sig_toq(tictim);

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */

	return E_OK;
}


#else	/* _KERNEL_SPT_ISIG_TIM */


#if _KERNEL_SPT_ISIG_TIM_E_NOSPT

/** %jp{タイムティックの供給}%en{Supply Time Tick}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER isig_tim(void)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ISIG_TIM */



/* end of file */
