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
				
				/* SCTLR.V クリア(例外ベクタを0番地に戻す) */
				mrc		p15, 0, r0, c1, c0, 0
				mvn		r1, #0x2000
				and		r0, r0, r1
				mcr		p15, 0, r0, c1, c0, 0
				
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
				
				/* MPU設定 */
#if 0
				mov     r0, #0
				mcr     p15, 0, r0, c6, c2, 0	/* RGNR */
				ldr     r0, =0x00000000
				mcr     p15, 0, r0, c6, c1, 0	/* MPU Region Base Address Register */
				ldr     r0, =0x0000030b
				mcr     p15, 0, r0, c6, c1, 4	/* MPU Region Access Control Register */
				ldr     r0, =0x0000003d
				mcr     p15, 0, r0, c6, c1, 2	/* Data MPU Region Size and Enable Register */
				
				mov     r0, #1
				mcr     p15, 0, r0, c6, c2, 0	/* RGNR */
				ldr     r0, =0xc0000000
				mcr     p15, 0, r0, c6, c1, 0	/* MPU Region Base Address Register */
				ldr     r0, =0x0000030b
				mcr     p15, 0, r0, c6, c1, 4	/* MPU Region Access Control Register */
				ldr     r0, =0x0000003b
				mcr     p15, 0, r0, c6, c1, 2	/* Data MPU Region Size and Enable Register */
#endif
				
				/* 分岐予測有効化(ACTLR設定) */
				mrc     p15, 0, r0, c1, c0, 1
				ldr		r1, =0xfffc7fff		/* RSDIS=0, BP=0 */
				and		r0, r0, r1
				ldr		r1, =0x00004000		/* DBWR=1 (errata 780125) */
				orr		r0, r0, r1
				mcr		p15, 0, r0, c1, c0, 1
				
				/* Iキャッシュ/Dキャッシュ有効(SCTLR) */
				mrc 	p15, 0, r1, c1, c0, 0
				ldr		r0, =0x00001005		/* I=1, C=1, M=1 */
				orr 	r1, r1, r0
				dsb
				mcr		p15, 0, r1, c1, c0, 0
				isb
				
				
				/* main関数の呼び出し */
				bl		main
end_loop:
				b		end_loop


__main:
				bx		lr



				.end


/* end of file */
