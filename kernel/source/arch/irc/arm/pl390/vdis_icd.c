/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  vena_icd.c
 * @brief %jp{ARM GIC PL390}%en{ARM GIC PL390}
 * 
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* disable ICD */
ER vdis_icd(void)
{
	*_KERNEL_IRC_ICDDCR = 0;
	return E_OK;
}

/* end of file */
