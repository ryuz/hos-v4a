/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_exc.c
 * @brief %jp{CPU例外ハンドラ定義}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/excobj.h"


/** %jp{CPU例外ハンドラの定義}%en{Define CPU Exception Handler}
   @param  excno        %jp{CPU例外番号}%en{CPU exception handler number to be defined.}
 * @param  pk_dexc	%jp{CPU例外ハンドラの定義情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the CPU exception hander definition information.}
 * @return Error code or normal return code (E_OK).
 */
ER def_exc(EXCNO excno, const T_DEXC *pk_dexc)
{

#if !_KERNEL_SPT_DEF_EXC
	return E_NOSPT;  /* DEF_EXCをサポートしていない */
#else

	/* %jp{excnoが有効範囲外} */
	if ( ( excno < _KERNEL_TMIN_EXC_EXCNO ) ||
	    ( excno > _KERNEL_TMAX_EXC_EXCNO ) )
        {
	       return E_PAR;
        }


	/* %jp{例外ハンドラを設定する} */
	_KERNEL_EXC_SET_EXCHDR(excno, pk_dexc->exchdr);

	return E_OK;
#endif  /*  !_KERNEL_SPT_DEF_EXC  */
}


/* end of file */
