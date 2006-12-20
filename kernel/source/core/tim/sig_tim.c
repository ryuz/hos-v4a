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
#include "core/tim.h"


RELTIM _kernel_sig_tim(_KERNEL_T_TIMCB_PTR timcb, _KERNEL_T_TIMCB_RO_PTR timcb_ro)
{
	RELTIM tictim;
	RELTIM ticnxt;
	
	/* %jp{進めるティックを得る} */
	tictim = _KERNEL_TIM_GET_TICNXT(timcb);

	/* %jp{システム時刻を進める} */
	_KERNEL_TIM_ADD_SYSTIM(timcb, tictim);

	/* %jp{次回加算するタイムティックを算出} */
#if _KERNEL_FRACTIONAL_TIMTIC
	{
		RELTIM ticcnt;

		ticcnt = _KERNEL_TIM_GET_TICCNT(timcb);

		if ( ticcnt < _KERNEL_TIM_GET_TICMOD(timcb_ro) )
		{
			ticnxt = _KERNEL_TIM_GET_TICDIV(timcb_ro) + 1;	/* %jp{割り切れない分を補正} */
		}
		else
		{
			ticnxt = _KERNEL_TIM_GET_TICDIV(timcb_ro);
		}

		ticcnt++;
		if ( ticcnt >= _KERNEL_TIM_GET_TICDENO(timcb_ro) )
		{
			ticcnt = 0;
		}
		
		_KERNEL_TIM_SET_TICCNT(timcb, ticcnt);
	}
#else
	{
		ticnxt = _KERNEL_TIM_GET_TICDIV(timcb_ro);
	}
#endif

	/* %jp{次回加算するタイムティックを設定} */
	_KERNEL_TIM_SET_TICNXT(timcb, ticnxt);

	return tictim;
}

