/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.h
 * @brief %jp{サンプルプログラム}%en{Sample program}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __sample_h__
#define __sample_h__

#if !defined(_MACRO_ONLY)

#ifdef __cplusplus
extern "C" {
#endif

void Sample_Initialize(VP_INT exinf);
void Sample_Task(VP_INT exinf);
void Sample_Print(VP_INT exinf);

void Ecall_Task(VP_INT exinf);

#ifdef __cplusplus
}
#endif

#endif  /* !_MACRO_ONLY */

#endif	/* __sample_h__ */


/* end of file */
