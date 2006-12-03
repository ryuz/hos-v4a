/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  サンプルプログラム                           */
/*    スタートアップモジュール (日立 SH2 gcc 用)                            */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.extern		_main
				.extern		__kernel_int_isp
				.extern		_DATA_ROM
				.extern		_DATA_START
				.extern		_DATA_END
				.extern		_BSS_START
				.extern		_BSS_END

				.global		_reset_handler
				.global		___main


				.text


/************************************************
  リセットハンドラ
************************************************/
				.align		4
_reset_handler:
				mov.l	l_int_isp, r0
				mov.l	@r0, r15
				
				/* DATA領域のコピー */
				mov.l	l_data_rom, r0
				mov.l	l_data_start, r1
				mov.l	l_data_end, r2
				cmp/hs	r2, r1
				bt		data_end
data_loop:		
				mov.l	@r0+, r3
				mov.l	r3, @r1
				add		#4, r1
				cmp/hs	r2, r1
				bf		data_loop
data_end:		
				
				/* BSS領域の初期化 */
				mov.l	l_bss_start, r0
				mov.l	l_bss_end, r1
				cmp/hs	r1, r0
				bt		bss_end
				mov		#0, r2
bss_loop:		
				mov.l	r2, @r0
				add		#4, r0
				cmp/hs	r1, r0
				bf		bss_loop
bss_end:		
				
				/* main関数の呼び出し */
				mov.l	l_main, r8
				jsr		@r8
				nop
end_loop:
				bra		end_loop
				nop

				/* __main */
___main:
				rts		/* 何もしない */
				nop

				.align	2
l_int_isp:		
				.long	__kernel_int_isp
l_data_rom:		
				.long	___data_rom
l_data_start:	
				.long	___data
l_data_end:		
				.long	___data_end
l_bss_start:
				.long	___bss
l_bss_end:
				.long	___bss_end
l_main:			
				.long	_main



/************************************************
  カーネル用スタックポインタ定義
************************************************/
				.global		_kernel_int_sp
				.section	.rodata
				.align		4
_kernel_int_sp:
				.long	_stack		/* 割り込み時の er7 保存用 */



/************************************************
  スタック領域
************************************************/
				.section	.stack
				.global		_stack

				.align		4
_stack:			.long		1



				.end


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
