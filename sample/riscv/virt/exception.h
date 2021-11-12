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

#ifdef __cplusplus
extern "C" {
#endif

void InstructionAddressMisaligned(void *exinf);
void InstructionAccessFault(void *exinf);
void IllegalInstruction(void *exinf);
void BreakPoint(void *exinf);
void LoadAccessFault(void *exinf);
void AMOAddressMisaligned(void *exinf);
void StoreAMOAccessFault(void *exinf);
void  EnvironmentCall(void *exinf);
void InstructionPageFault(void *exinf);
void LoadPageFault(void *exinf);
void StoreAMOPageFault(void *exinf);

#ifdef __cplusplus
}
#endif


#endif	/* __exception_h__ */


/* end of file */
