/**
 * Hyper Operating System V4 Advance
 *
 * @file  regoff.c
 * @brief %jp{アセンブラ用レジスタオフセット定義生成ファイル}%en{register offset definitions}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "asm_offset_helper.h"

#include "itron.h"
#include "proc.h"
#include "procatr.h"
#include "core/cntnrsup.h"

int main(int argc, char *argv[])
{

	/*
	 * %jp{割込みコンテキスト定義}
	 */

	/* %jp{割込みコンテキストサイズ(単位:バイト)}  */
	DEFINE_VAL(_KERNEL_IA32_PROC_ICTX_SIZE, sizeof(struct _kernel_ia32_ictx));
	/* %jp{例外/割込みコンテキスト確保サイズ(単位:バイト)}  */
	DEFINE_VAL(_KERNEL_IA32_PROC_ICTX_ALCSIZE,
	    _KERNEL_CNTNR_OFFSET_OF(struct _kernel_ia32_ictx, excno));
	/* %jp{例外/割込みコンテキスト解放サイズ(単位:バイト)}  */
	DEFINE_VAL(_KERNEL_IA32_PROC_ICTX_RELSIZE,
	    _KERNEL_CNTNR_OFFSET_OF(struct _kernel_ia32_ictx, eip));

	/*  %jp{汎用レジスタオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_IA32_PROC_ICTX_EBX, _kernel_ia32_ictx, ebx);
	OFFSET(_KERNEL_IA32_PROC_ICTX_ECX, _kernel_ia32_ictx, ecx);
	OFFSET(_KERNEL_IA32_PROC_ICTX_EDX, _kernel_ia32_ictx, edx);
	OFFSET(_KERNEL_IA32_PROC_ICTX_ESI, _kernel_ia32_ictx, esi);
	OFFSET(_KERNEL_IA32_PROC_ICTX_EDI, _kernel_ia32_ictx, edi);
	OFFSET(_KERNEL_IA32_PROC_ICTX_EBP, _kernel_ia32_ictx, ebp);
	OFFSET(_KERNEL_IA32_PROC_ICTX_EAX, _kernel_ia32_ictx, eax);

	/*  %jp{例外/割込み番号オフセット(単位:バイト)}  */
	OFFSET(_KERNEL_IA32_PROC_ICTX_EXCNO, _kernel_ia32_ictx, excno);
	/*  %jp{例外エラーコードオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_IA32_PROC_ICTX_EXCD, _kernel_ia32_ictx, excd);
	/*  %jp{例外/割込み元アドレスオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_IA32_PROC_ICTX_EIP, _kernel_ia32_ictx, eip);
	/*  %jp{コードセグメントオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_IA32_PROC_ICTX_XCS, _kernel_ia32_ictx, xcs);
	/*  %jp{EFLAGS(プログラムステータスワード)オフセット(単位:バイト)}  */
	OFFSET(_KERNEL_IA32_PROC_ICTX_EFLAGS, _kernel_ia32_ictx, eflags);

	/*
	 * %jp{タスクコンテキスト定義}
	 */
	/* %jp{タスクコンテキストサイズ(単位:バイト)}  */
	DEFINE_VAL(_KERNEL_IA32_PROC_TSKCTX_SIZE, sizeof(struct _kernel_ia32_tskswctx));
	OFFSET(_KERNEL_IA32_PROC_TSKCTX_EBP, _kernel_ia32_tskswctx, ebp);
	OFFSET(_KERNEL_IA32_PROC_TSKCTX_EDI, _kernel_ia32_tskswctx, edi);
	OFFSET(_KERNEL_IA32_PROC_TSKCTX_ESI, _kernel_ia32_tskswctx, esi);
	OFFSET(_KERNEL_IA32_PROC_TSKCTX_EBX, _kernel_ia32_tskswctx, ebx);
	OFFSET(_KERNEL_IA32_PROC_TSKCTX_EFLAGS, _kernel_ia32_tskswctx, eflags);
	OFFSET(_KERNEL_IA32_PROC_TSKCTX_RETADDR, _kernel_ia32_tskswctx, retaddr);

	/*
	 * %jp{割込みコンテキスト制御ブロック}
	 */
	/* %jp{割込みスタックのオフセット} */
	OFFSET(_KERNEL_IA32_PROC_ICTXCB_INTCNT, _kernel_t_ictxcb, intcnt);
	/* %jp{割込みスタックのオフセット} */
	OFFSET(_KERNEL_IA32_PROC_ICTXCB_ISP, _kernel_t_ictxcb, isp);

	return 0;
}



/* end of file */
