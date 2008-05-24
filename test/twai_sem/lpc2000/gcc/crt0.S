/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    Sample program for ADuC7000 series                                    */
/*                                                                          */
/*                                  Copyright (C) 1998-2007 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.extern		__kernel_int_isp
				.extern		___data
				.extern		___data_end
				.extern		___bss
				.extern		___bss_end
				.extern		main

				.global		_reset_handler
				.global		__main


				.text

#define Mode_USR		0x10
#define Mode_IRQ		0x12
#define Mode_FIQ		0x11
#define Mode_SVC		0x13
#define Mode_UND		0x1b
#define Mode_SYS		0x1f
#define I_Bit			0x80
#define F_Bit			0x40
#define T_Bit			0x20


/************************************************
  リセットハンドラ
************************************************/
				.align		4
_reset_handler:	
				/* モード設定 */
				msr		cpsr_c, #(Mode_SYS | F_Bit | I_Bit)
				
				/* スタック仮設定 */
				ldr		r0, =_kernel_int_isp
				ldr 	sp, [r0]
				
				
				/* DATA領域のコピー */
				ldr		r0, =___data_rom
				ldr		r1, =___data
				ldr		r2, =___data_end
data_loop:		
				cmp		r1, r2
				ldrcc	r3, [r0], #4
				strcc	r3, [r1], #4
				bcc		data_loop
				
				
				/* BSS領域の初期化 */
				ldr		r0, =___bss
				ldr		r1, =___bss_end
				mov		r2, #0
bss_loop:		
				cmp		r0, r1
				strcc	r2, [r0], #4
				bcc		bss_loop
				
				
				/* main関数の呼び出し */
				bl		main
end_loop:
				b		end_loop


__main:
				bx		lr



				.end


/* end of file */
