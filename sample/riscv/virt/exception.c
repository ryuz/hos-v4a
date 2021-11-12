/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  exception.c
 * @brief %jp{RISC-V CPU 例外処理}%en{CPU exception handlers for RISC-V}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "uart.h"
#include "exception.h"
#include "arch/proc/riscv/procatr.h"

#include "kernel_id.h"

/**
   レジスタの内容を16進数で表示
   @param[in] _reg レジスタ値
 */
#if __riscv_xlen == 32
#define PutRegister(_reg) do{Uart_PutHexWord((_reg));}while(0)
#else
#define PutRegister(_reg) do{Uart_PutHexDoubleWord((_reg));}while(0)
#endif

/**
   例外種別名
 */
static const char *mcause_string[]={
	"Instruction address misaligned",
	"Instruction access fault",
	"Illegal instruction",
	"Breakpoint",
	"Load address misaligned",
	"Load access fault",
	"Store/AMO address misaligned",
	"Store/AMO access fault",
	"Environment call from U-mode",
	"Environment call from S-mode",
	"Reserved(10)",
	"Environment call from M-mode",
	"Instruction page fault",
	"Load page fault",
	"Reserved(14)",
	"Store/AMO page fault",
};


/**
   例外コンテキスト表示
   @param[in] excno 例外番号
   @param[in] ictx 例外コンテキストのアドレス
 */
static void show_ictx(EXCNO excno, struct _kernel_riscv_ictx *ictx)
{

	Uart_PutString("excno: ");
	PutRegister(excno);
	Uart_PutString(" ");
	Uart_PutString(mcause_string[excno]);
	Uart_PutString("\n");

	Uart_PutString("ra: ");
	PutRegister(ictx->ra);
	Uart_PutString("\n");


	Uart_PutString("t0: ");
	PutRegister(ictx->t0);
	Uart_PutString(" ");
	Uart_PutString("t1: ");
	PutRegister(ictx->t1);
	Uart_PutString("\n");

	Uart_PutString("t2: ");
	PutRegister(ictx->t2);
	Uart_PutString(" ");
	Uart_PutString("t3: ");
	PutRegister(ictx->t3);
	Uart_PutString("\n");

	Uart_PutString("t4: ");
	PutRegister(ictx->t4);
	Uart_PutString(" ");
	Uart_PutString("t5: ");
	PutRegister(ictx->t5);
	Uart_PutString("\n");

	Uart_PutString("t6: ");
	PutRegister(ictx->t6);
	Uart_PutString("\n");


	Uart_PutString("a0: ");
	PutRegister(ictx->a0);
	Uart_PutString(" ");
	Uart_PutString("a1: ");
	PutRegister(ictx->a1);
	Uart_PutString("\n");

	Uart_PutString("a2: ");
	PutRegister(ictx->a2);
	Uart_PutString(" ");
	Uart_PutString("a3: ");
	PutRegister(ictx->a3);
	Uart_PutString("\n");

	Uart_PutString("a4: ");
	PutRegister(ictx->a4);
	Uart_PutString(" ");
	Uart_PutString("a5: ");
	PutRegister(ictx->a5);
	Uart_PutString("\n");

	Uart_PutString("a6: ");
	PutRegister(ictx->a6);
	Uart_PutString(" ");
	Uart_PutString("a7: ");
	PutRegister(ictx->a7);
	Uart_PutString("\n");

	Uart_PutString("epc: ");
	PutRegister(ictx->epc);
	Uart_PutString(" ");
	Uart_PutString("status: ");
	PutRegister(ictx->status);
	Uart_PutString("\n");

	Uart_PutString("\n");
}


/**
   CPU例外共通処理
   @param[in] excno 例外番号
   @param[in] ictx  例外コンテキストのアドレス
 */
static void riscv_exception_common(EXCNO excno, struct _kernel_riscv_ictx *ictx)
{

	if ( excno == 11 )
        {
		if ( ( ictx->a0 == TSKID_ECALL )
		    && ( ictx->a1 == 0x1 )
		    && ( ictx->a2 == 0x2 )
		    && ( ictx->a3 == 0x3 )
		    && ( ictx->a4 == 0x4 )
		    && ( ictx->a5 == 0x5 )
		    && ( ictx->a6 == 0x6 )
		    && ( ictx->a7 == 0x7 ) )
			Uart_PutString("OK");
		else
		{

			Uart_PutString("NG");
			show_ictx(excno, ictx);
		}
	}
	else
	{

		show_ictx(excno, ictx);
		while(1);  /* %jp{不正例外により停止} */
	}


	return;
}


/**
   命令アドレスアラインメント不正例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void InstructionAddressMisaligned(void *exinf)
{
	riscv_exception_common(0, (struct _kernel_riscv_ictx *)exinf);
}


/**
   命令アドレスアクセスフォルト例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void InstructionAccessFault(void *exinf)
{
	riscv_exception_common(1, (struct _kernel_riscv_ictx *)exinf);
}


/**
   不正命令例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void IllegalInstruction(void *exinf)
{
	riscv_exception_common(2, (struct _kernel_riscv_ictx *)exinf);
}


/**
   ブレークポイント例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void BreakPoint(void *exinf)
{
	riscv_exception_common(3, (struct _kernel_riscv_ictx *)exinf);
}


/**
   ロードアクセスフォルト例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void LoadAccessFault(void *exinf)
{
	riscv_exception_common(5, (struct _kernel_riscv_ictx *)exinf);
}


/**
   ストア/アトミックメモリ操作アラインメント不正例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void AMOAddressMisaligned(void *exinf)
{
	riscv_exception_common(6, (struct _kernel_riscv_ictx *)exinf);
}


/**
   ストア/アトミックメモリ操作アクセスフォルト例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void StoreAMOAccessFault(void *exinf)
{
	riscv_exception_common(7, (struct _kernel_riscv_ictx *)exinf);
}


/**
   環境呼出例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void EnvironmentCall(void *exinf)
{
	riscv_exception_common(11, (struct _kernel_riscv_ictx *)exinf);
	((struct _kernel_riscv_ictx *)exinf)->epc
		= (VP_INT)(((struct _kernel_riscv_ictx *)exinf)->epc) + 4;
	if ( ( sns_ctx() ) && ( !sns_loc() ) )
		((struct _kernel_riscv_ictx *)exinf)->a0 = -1;
	else
		((struct _kernel_riscv_ictx *)exinf)->a0 = 0;
}


/**
   命令ページフォルト例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void InstructionPageFault(void *exinf)
{
	riscv_exception_common(12, (struct _kernel_riscv_ictx *)exinf);
}


/**
   ロードページフォルト例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void LoadPageFault(void *exinf)
{
	riscv_exception_common(13, (struct _kernel_riscv_ictx *)exinf);
}


/**
   ストア/アトミックメモリ操作ページフォルト例外処理
   @param[in] exinf 例外コンテキストのアドレス
 */
void StoreAMOPageFault(void *exinf)
{
	riscv_exception_common(15, (struct _kernel_riscv_ictx *)exinf);
}


/* end of file */
