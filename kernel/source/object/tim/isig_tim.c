/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  isig_tim.c
 * @brief %jp{タイムティックの供給}%en{Supply Time Tick}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_ISIG_TIM


#if _KERNEL_SPT_DPC


static void _kernel_dpc_sig_tim(ID id, VP_INT param);


/** %jp{タイムティックの供給}%en{Supply Time Tick}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 */
ER isig_tim(void)
{
	return _KERNEL_SYS_REQ_DPC(_kernel_dpc_sig_tim, 0, 0);
}


/** %jp{タイムティックの供給}%en{Supply Time Tick} */
void _kernel_dpc_sig_tim(ID id, VP_INT param)
{
	RELTIM tictim;

	tictim = _KERNEL_SYS_SIG_TIM();

	/* %jp{タイムキューの処理を行う} */
#if _KERNEL_SPT_TMQ
	_KERNEL_SYS_SIG_TMQ(tictim);
#endif
	
	/* %jp{タイムアウトキューの処理を行う} */
#if _KERNEL_SPT_TOQ
	_KERNEL_SYS_SIG_TOQ(tictim);
#endif
}


#else	/* _KERNEL_SPT_DPC */


/** %jp{タイムティックの供給}%en{Supply Time Tick}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 */
ER isig_tim(void)
{
	RELTIM tictim;

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	tictim = _KERNEL_SYS_SIG_TIM();

	/* %jp{タイムキューの処理を行う} */
#if _KERNEL_SPT_TMQ
	_KERNEL_SYS_SIG_TMQ(tictim);
#endif

	/* %jp{タイムアウトキューの処理を行う} */
#if _KERNEL_SPT_TOQ
	_KERNEL_SYS_SIG_TOQ(tictim);
#endif
	
	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */

	return E_OK;	
}

#endif	/* _KERNEL_SPT_DPC */


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
