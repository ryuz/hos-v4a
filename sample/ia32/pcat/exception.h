/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  exception.h
 * @brief %jp{CPU例外ハンドラ}%en{CPU exception handlers}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __exception_h__
#define __exception_h__

#include "kernel.h"

#if !defined(_MACRO_ONLY)

#ifdef __cplusplus
extern "C" {
#endif

void ia32_handle_exception(void *exinf);

#ifdef __cplusplus
}
#endif

#endif  /* !_MACRO_ONLY */

#endif	/* __exception_h__ */


/* end of file */
