#include "core/core.h"
#include "core/adtq.h"



_KERNEL_ADTQ_T_ADTQCNT _kernel_adtq_ref_fdtqnt(_KERNEL_T_ADTQCB *adtqcb)
{
	_KERNEL_ADTQ_T_POSITION head;
	_KERNEL_ADTQ_T_POSITION tail;

	head = _KERNEL_ADTQ_GET_HEAD(adtqcb);
	tail = _KERNEL_ADTQ_GET_TAIL(adtqcb);

	if ( tail < head )
	{
		return head - tail - 1;
	}
	else
	{
		return _KERNEL_ADTQ_GET_ADTQCNT(adtqcb) + head - tail - 1;
	}
}


