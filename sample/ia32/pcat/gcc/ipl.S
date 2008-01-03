/** 
 * Hyper Operating System V4 Advance
 *
 *  Sample program for PC/AT
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



IPL_SEG   = 0x07c0			/* ロードされるセグメントアドレス */
INIT_SEG  = 0x8000			/* 初期化コード用セグメントアドレス */
LOAD_SEG  = 0x9000			/* 本体をロードするセグメントアドレス */


				.code16
				.text
				.org	0

				.global	ipl_top

		/***** IPL部 *****/
ipl_top:
				cli
				jmpl	$IPL_SEG, $ipl_start	/* CSの初期化 */
ipl_start:
				/* コードのコピー */
				movw	$IPL_SEG, %ax
				movw	%ax, %ds
				movw	$INIT_SEG, %ax
				movw	%ax, %es
				xorw	%si, %si
				xorw	%di, %di
				movw	$512, %cx
				cld
				rep		movsw
				
				/* コピー先に移動 */
				movw	%ax, %ds
				movw	%ax, %ss
				xorw	%sp, %sp
				jmpl	$INIT_SEG, $init_start


		/***** 初期化部 *****/
init_start:
				/* 画面のクリア */
		;		call	bios_clr_disp
				
				/* メッセージ出力 */
				movw    $boot_message, %si
				call	bios_puts
				
				/* 本体のロード */
				movw	$LOAD_SEG, %ax
				movw	%ax, %es
				xorw	%bx, %bx			/* 読込先アドレス */
				movb	$0x02, %ah
				movb	$0x06, %al			/* セクタ数 */
				movw	$0x0002, %cx		/* シリンダ・セクタ番号 */
				movb	$0x00, %dh			/* ヘッド番号 */
				movb	$0x00, %dl			/* ドライブ番号 */
				int     $0x13

end_loop:
				jmp		end_loop
				
				/* ロード先に移動 */
				movw	$LOAD_SEG, %ax
				movw	%ax, %ds
				movw	%ax, %ss
				xorw	%sp, %sp
				jmpl	$LOAD_SEG, $0x0000
				
				
				
				/* 画面のクリア */
bios_clr_disp:
				movb    $0x3, %al
				movb    $0, %ah
				int     $0x10
				ret


				/* １文字出力 */
bios_putc:
				movb    $0x0e, %ah
				movb    $0, %bh
				int     $0x10
				ret
				
				/* 文字列出力 */
bios_puts:
				lodsb
				cmpb	$0, %al
				jz		bios_puts_end
				call	bios_putc
				jmp		bios_puts
bios_puts_end:
				ret


				
				/* 起動メッセージ */
boot_message:
		        .ascii	"HOS-Loader\r\nNow Loading...\r\n\0"


				/* マジックナンバー */
				.org	510
				.word	0xaa55



/* end of file  */
