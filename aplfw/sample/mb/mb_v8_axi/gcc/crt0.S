/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    Sample program for MicroBlaze                                         */
/*                                                                          */
/*                                  Copyright (C) 1998-2011 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.extern		_kernel_int_isp
				.extern		___data
				.extern		___data_end
				.extern		___bss
				.extern		___bss_end
				.extern		main

				.global		_reset_handler

				.text



/************************************************
  リセットハンドラ
************************************************/
				.align		2
_reset_handler:	
				/* キャッシュON */
				addik	r3, r0, 0x000000a0
				mts  	rmsr, r3
				
				/* BIPクリア(念の為) */
				addik	r3, r0, bip_clear
				rtbd	r3, 0
bip_clear:		
				
				/* スタック設定 */
				lwi		r1, r0, _kernel_int_isp
				
				addik	r3, r0, ___data
				addik	r4, r0, ___data_end
				addik	r5, r0, ___data_ro
				
				/* DATA領域のコピー */
				cmpu	r18, r4, r3
				bgei	r18, data_loop_end
data_loop:		
				lwi		r6, r5, 0
				swi		r6, r3, 0
				addik	r3, r3, 4
				cmpu	r18, r4, r3
				bltid	r18, data_loop
				addik	r5, r5, 4
data_loop_end:

				/* BSS領域の初期化 */
				addik	r3, r0, ___bss
				addik	r4, r0, ___bss_end
				cmpu	r18,r4, r3
				bgei	r18, bss_loop_end
bss_loop:
				swi		r0, r3, 0
				addik	r3, r3, 4
				cmpu	r18, r4, r3
				blti	r18, bss_loop
bss_loop_end:
				
				
				/* main関数の呼び出し */
				brlid	r15, main
				nop
				
exit_loop:
				bri		exit_loop



/* end of file */
