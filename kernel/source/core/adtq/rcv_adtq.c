#include "core/core.h"
#include "core/adtq.h"



BOOL _kernel_adtq_rcv_dat(_KERNEL_T_ADTQCB *adtqcb, VP_INT *p_data)
{
	_KERNEL_ADTQ_T_POSITION head;
	VP_INT                  *adtq;

	/* %jp{先頭位置取得} */
	head = _KERNEL_ADTQ_GET_HEAD(adtqcb);

	/* %jp{データチェック} */
	if ( head == _KERNEL_ADTQ_GET_TAIL(adtqcb) )
	{
		return FALSE;	/* %jp{データ無し} */
	}

	/* %jp{データ取り出し} */
	adtq = _KERNEL_ADTQ_GET_ADTQ(adtqcb);
	*p_data = adtq[tail];

	/* %jp{次の末尾位置計算} */
	head++;
	if ( head >= _KERNEL_ADTQ_GET_ADTQCNT(adtqcb) )
	{
		head = 0;
	}

	/* %jp{先頭位置更新} */
	_KERNEL_ADTQ_SET_HEAD(adtqcb, head);
}

