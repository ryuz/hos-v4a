/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  isig_tim.c
 * @brief %jp{タイムティックの供給}%en{Supply Time Tick}
 *
 * @version $Id: isig_tim.c,v 1.1 2006-08-16 16:27:04 ryuz Exp $
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

	tictim = 1;
	
/*	_kernel_sig_tmq(tictim);	*/

	_kernel_sig_toq(tictim);
	
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
