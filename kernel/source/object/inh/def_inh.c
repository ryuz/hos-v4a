/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_inte.c
 * @brief %jp{割り込み処理開始}
 *
 * @version $Id: def_inh.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"


ER def_inh(INHNO inhno, const T_DINH *pk_dinh)
{
	_KERNEL_INH_SET_INTHDR(inhno, pk_dinh->inthdr);

	return E_OK;
}


/* end of file */
