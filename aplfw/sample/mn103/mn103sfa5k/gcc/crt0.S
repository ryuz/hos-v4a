/* ------------------------------------------------------------------------ */
/*  Hyper Operating System                                                  */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.extern		__kernel_int_hdr
				.extern		___data
				.extern		___data_end
				.extern		___bss
				.extern		___bss_end
				.extern		_main


#define stack	0x00002000

#define IVAR0	0x00008000
#define IVAR1	0x00008004
#define IVAR2	0x00008008
#define IVAR3	0x0000800C
#define IVAR4	0x00008010
#define IVAR5	0x00008014
#define IVAR6	0x00008018
#define IAGR	0x00008a00



				.text

		/* リセットハンドラ */
reset_hdr:
				mov		startup, a0
				jmp		(A0)

		/* NMI ハンドラ */
nmi_hdr:
				bra		nmi_hdr
				nop
				nop
				nop
				nop

		/* 割込みハンドラ */
int_hdr:
				jmp		__kernel_int_hdr


		/* スタートアップ */
startup:
				mov		stack, a0
				mov		a0, sp
				
		/* 割り込みハンドラ登録 */
				mov		int_hdr, d0
				movhu	d0, (IVAR0)
				movhu	d0, (IVAR1)
				movhu	d0, (IVAR2)
				movhu	d0, (IVAR3)
				movhu	d0, (IVAR4)
				movhu	d0, (IVAR5)
				movhu	d0, (IVAR6)

		/* BSSクリア */
				mov		___bss_end, d1
				sub		___bss, d1
				cmp		0, d1
				ble		bss_clear_end
				mov		___bss, a0
				clr		d0
bss_clear_loop:
				mov		d0, (a0) 
				inc4	a0
				add		-4, d1
				bgt		bss_clear_loop
bss_clear_end:


		/* DATAコピー
				mov		___data_end - ___data, d1
				cmp		0, d1
				ble		data_copy_end
				mov		___data_rom, a0
				mov		___data, a1
data_copy_loop:
				mov		(a0), d0
				inc4	a0
				mov		d0, (a1)
				inc4	a1
				add		-4, d1
				bne		data_copy_loop
data_copy_end:


		/* main関数コール */
				call	_main,[],0


_exit_loop:		
				bra		_exit_loop
				nop
				nop
				nop
				nop


				.end


/* end of file */
