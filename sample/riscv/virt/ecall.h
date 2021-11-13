/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  ecall.h
 * @brief RISC-V Environment call
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __ecall_h__
#define __ecall_h__

#include "kernel.h"

#ifdef __cplusplus
extern "C" {
#endif


/** %jp{RISC-V Environment call発行} */
int _riscv_ecall(int arg0, int arg1, int arg2, int arg3, int arg4,
    int arg5, int arg6, int arg7);


#ifdef __cplusplus
}
#endif


#endif	/* __ecall_h__ */


/* end of file */
