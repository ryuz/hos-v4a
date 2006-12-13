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
#include "object/timobj.h"


#if _KERNEL_SPT_ISIG_TIM

static void _kernel_sig_tim(void);


#if _KERNEL_SPT_DPC

/** %jp{タイムティックの供給}%en{Supply Time Tick}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 */
ER isig_tim(void)
{
	ER ercd;

	_KERNEL_SYS_LOC_DPC();	/* %jp{多重割り込み対策でロックをかける} */

	if (  _KERNEL_SYS_RFR_DPC() >= 1 )
	{
		_KERNEL_SYS_SND_DPC((VP_INT)_kernel_sig_tim);
		ercd = E_OK;		/* %jp{正常終了}%en{Normal completion} */
	}
	else
	{
		ercd = E_NOMEM;		/* %jp{遅延実行用のキューイングメモリ不足}%en{Insufficient memory to store a service call for delayed execution} */
	}
	
	_KERNEL_SYS_UNL_DPC();	/* jp{ロック解除} */
	
	return ercd;
}

#else	/* _KERNEL_SPT_DPC */

/** %jp{タイムティックの供給}%en{Supply Time Tick}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 */
ER isig_tim(void)
{
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	_kernel_sig_tim();
	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */

	return E_OK;	
}

#endif	/* _KERNEL_SPT_DPC */

/** %jp{タイムティックの供給}%en{Supply Time Tick} */
void _kernel_sig_tim(void)
{
	RELTIM tictim;

	/* %jp{加算するタイムティックを算出} */
#if _KERNEL_CFG_FRACTIONAL_TIMTIC
	{
		RELTIM ticcnt;

		ticcnt = _KERNEL_TIM_GET_TICCNT();
		if ( ticcnt <= 0 )
		{
			ticcnt = _KERNEL_TIM_GET_TICDENO();
		}
		ticcnt--;

		if ( ticcnt < _KERNEL_TIM_GET_TICMOD() )
		{
			tictim = _KERNEL_TIM_GET_TICDIV() + 1;	/* %jp{割り切れない分を補正} */
		}
		else
		{
			tictim = _KERNEL_TIM_GET_TICDIV();
		}
		
		_KERNEL_TIM_SET_TICCNT(ticcnt);
	}
#else
	tictim = _KERNEL_TIM_GET_TICDIV();
#endif


	/* %jp{システム時刻を進める} */
	_KERNEL_TIM_ADD_SYSTIM(tictim);


	/* %jp{タイムキューの処理を行う} */
#if _KERNEL_SPT_TMQ
	_KERNEL_SYS_SIG_TMQ(tictim);
#endif


	/* %jp{タイムアウトキューの処理を行う} */
#if _KERNEL_SPT_TOQ
	_KERNEL_SYS_SIG_TOQ(tictim);
#endif
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
