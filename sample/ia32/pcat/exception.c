/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  exception.c
 * @brief %jp{RISC-V CPU 例外処理}%en{CPU exception handlers for RISC-V}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stddef.h>

#include "kernel.h"
#include "console.h"
#include "procatr.h"
#include "../../aplfw/library/algorithm/stringformat/stringformat.h"

#define IA32_NAMED_EXCEPTION_NR  (21)  /* %jp{例外種別名の数} */

/**
   例外種別名
 */
static const char *exc_string[]={
	"Divide Error",
	"Debug Exception Fault/Trap",
	"NMI Interrupt",
	"Breakpoint",
	"Overflow",
	"BOUND Range Exceeded",
	"Invalid Opcode (Undefined Opcode)",
	"Device Not Available (No Math Coprocessor)",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Invalid TSS",
	"Segment Not Present",
	"Stack-Segment Fault",
	"General Protection",
	"Page Fault",
	"Intel reserved",
	"x87 FPU Floating-Point Error (Math Fault)",
	"Alignment Check",
	"Machine Check",
	"SIMD Floating-Point Exception",
	"Virtualization Exception",
};

/**
   %jp{書式指定出力処理に使用するコンソールへの1文字出力}
   @param[in] c %jp{出力する文字}
   @param[in] Param %jp{拡張パラメタ}
   @return 出力文字数
 */
static int console_put(int c, void *Param)
{

	Console_PutChar(c);

	return 1;
}

/**
   %jp{CPU例外処理}
   @param[in] exinf %jp{例外コンテキストのアドレス}
 */
void ia32_handle_exception(void *exinf)
{
	struct _kernel_ia32_ictx *ctx = (struct _kernel_ia32_ictx *)exinf;

	/*
	 * %jp{例外コンテキストを表示する}
	 */
	if ( IA32_NAMED_EXCEPTION_NR > ctx->excno )
		StringFormat_Format(console_put, NULL,
		    "exception: %d [%s] errcode: 0x%x ictx=0x%08x\n",
		    ctx->excno, exc_string[ctx->excno], ctx->excd, exinf);
	else
		StringFormat_Format(console_put, NULL,
		    "exception: %d errcode: 0x%x ictx=0x%08x\n",
		    ctx->excno, ctx->excd, exinf);

	StringFormat_Format(console_put, NULL,
	    "ecx: 0x%08x edx: 0x%08x eax: 0x%08x\n",
	    ctx->ecx, ctx->edx, ctx->eax);
	StringFormat_Format(console_put, NULL,
	    "eip: 0x%08x cs: 0x%08x eflags: 0x%08x\n",
	    ctx->eip, ctx->xcs, ctx->eflags);

	if ( IA32_NAMED_EXCEPTION_NR > ctx->excno )
		while(1);  /* %jp{不正CPU例外とみなし, 停止する} */

	return;
}
