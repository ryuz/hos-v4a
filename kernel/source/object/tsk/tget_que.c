/**
 *  Hyper Operating System V4 Advance
 *
 * @file  tget_que.c
 * @brief %jp{TCBアドレスをIDに変換}%en{TCB-address to ID}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/semobj.h"
#include "object/flgobj.h"



#if !_KERNEL_TCB_QUE && _KERNEL_TCB_TSKWAIT && _KERNEL_TCB_WOBJID

_KERNEL_T_QUE *_kernel_tsk_get_que(_KERNEL_T_TSKHDL tskhdl)
{
	switch ( _KERNEL_TSK_GET_TSKWAIT(tskhdl) )
	{
#if _KERNEL_SPT_SEM
	case _KERNEL_TTW_SEM:
		return _KERNEL_SEM_GET_QUE(_KERNEL_SEM_ID2SEMHDL(_KERNEL_TSK_GET_WOBJID(tskhdl)));
#endif

#if _KERNEL_SPT_FLG
	case _KERNEL_TTW_FLG:
		return _KERNEL_FLG_GET_QUE(_KERNEL_FLG_ID2FLGHDL(_KERNEL_TSK_GET_WOBJID(tskhdl)));
#endif

#if _KERNEL_SPT_DTQ
	case _KERNEL_TTW_SDTQ:
		return _KERNEL_DTQ_GET_SQUE(_KERNEL_DTQ_ID2DTQHDL(_KERNEL_TSK_GET_WOBJID(tskhdl)));

	case _KERNEL_TTW_RDTQ:
		return _KERNEL_DTQ_GET_RQUE(_KERNEL_DTQ_ID2DTQHDL(_KERNEL_TSK_GET_WOBJID(tskhdl)));
#endif

#if _KERNEL_SPT_MBX
	case _KERNEL_TTW_MBX:
		return _KERNEL_MBX_GET_QUE(_KERNEL_MBX_ID2MBXHDL(_KERNEL_TSK_GET_WOBJID(tskhdl)));
#endif

#if _KERNEL_SPT_MTX
	case _KERNEL_TTW_MTX:
		return _KERNEL_MTX_GET_RQUE(_KERNEL_MTX_ID2MTXHDL(_KERNEL_TSK_GET_WOBJID(tskhdl)));
#endif

#if _KERNEL_SPT_MBF
	case _KERNEL_TTW_SMBF:
		break;

	case _KERNEL_TTW_RMBF:
		break;
#endif

#if 0
	case _KERNEL_TTW_CAL:	
		break;

	case _KERNEL_TTW_ACP:	
		break;

	case _KERNEL_TTW_RDV:	
		break;

	case _KERNEL_TTW_MPF:	
		break;

	case _KERNEL_TTW_MPL:	
		break;
#endif
	}
	
	return NULL;
}

#endif


/* end of file */
