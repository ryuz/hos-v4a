/** 
 * Hyper Operating System V4 Advance
 *
 *  Sample program for PC/AT
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.extern		_main
				.extern		__kernel_int_isp
				.extern		_BSS_START
				.extern		_BSS_END

				.global		_boot_handler
				.global		___main


				.code16
				.text

/************************************************
  起動ハンドラ
************************************************/
				.align		4
_boot_handler:	
				jmp			_boot_handler
				
				/* 画面のクリア */
				call	bios_clr_disp
				
				/* メッセージ出力 */
				movw    $boot_message, %si
				call	bios_puts
				
_boot_end:
				jmp			_boot_end
				
				
				
				
				lgdt	gdtr
				lidt	idtr

				movl	$0x11, %eax
				movl	%eax, %cr0
				jmp		_go_protect_mode
				
_go_protect_mode:
				.byte	0x66, 0xea
				.long	_start_32bit + 0x90000
				.word	0x0001

				.code32
_start_32bit:
				jmp		_start_32bit


/************************************************
  BIOSサービス
************************************************/

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
		        .ascii	"Hyper Operation System V4 Advance\r\n\0"




/************************************************
  グローバルディスクリプタテーブル
************************************************/

gdt_base:
gdt_000:		/* ヌルセグメント */
				.word	0x0000
				.word	0x0000
				.byte	0x00
				.byte	0x00
				.byte	0x00
				.byte	0x00

gdt_001:		/* コードセグメント用 */
				.word   0xffff		/* リミット[15:0]:0xffff */
				.word   0x0000		/* ベース[15:0]:0x0000 */
				.byte   0x00		/* ベース[23:16] */
				.byte   0x9a		/* P:1, DPL:0, S:1, TYPE:5, A:0 */
				.byte   0xcf		/* G:1, D=1, リミット[19:15]:0xf */
				.byte   0x00		/* ベース[32:24]:0x00 */

gdt_002:		/* データセグメント用 */		
				.word	0xffff		/* リミット[15:0]:0xffff */
				.word	0x0000		/* ベース[15:0]:0x0000 */
				.byte	0x00		/* ベース[23:16] */
				.byte	0x92		/* P:1, DPL:0, S:1, TYPE:1, A:0 */
				.byte	0xcf		/* G:1, D=1, リミット[19:15]:0xf */
				.byte	0x00		/* ベース[32:24]:0x00 */
gdt_end:


				/* lgdt命令用領域 */
gdtr:			.word	gdt_end - gdt_base - 1
				.long	0



/************************************************
  割込みディスクリプタテーブル
************************************************/

idt_base:
idt_000:		/* INT0 #DE 除算エラー */
				.word	0x0000		/* オフセット[15:0] */
				.word	0x0001		/* セグメントセレクタ */
				.byte	0x00		/* 予約 */
				.byte	0x8e		/* P:1, DPL:0 */
				.word	0x00		/* オフセット[31:16] */

idt_001:		/* INT1 #DB 予約 */
				.word	0x0000		/* オフセット[15:0] */
				.word	0x0001		/* セグメントセレクタ */
				.byte	0x00		/* 予約 */
				.byte	0x8e		/* P:1, DPL:0 */
				.word	0x00		/* オフセット[31:16] */

idt_002:		/* INT2 NMI */
				.word	0x0000		/* オフセット[15:0] */
				.word	0x0001		/* セグメントセレクタ */
				.byte	0x00		/* 予約 */
				.byte	0x8e		/* P:1, DPL:0 */
				.word	0x00		/* オフセット[31:16] */

idt_003:		/* INT5 #BP ブレークポイント */
				.word	0x0000		/* オフセット[15:0] */
				.word	0x0001		/* セグメントセレクタ */
				.byte	0x00		/* 予約 */
				.byte	0x8e		/* P:1, DPL:0 */
				.word	0x00		/* オフセット[31:16] */

idt_004:		/* INT4 #OF オーバーフロー */
				.word	0x0000		/* オフセット[15:0] */
				.word	0x0001		/* セグメントセレクタ */
				.byte	0x00		/* 予約 */
				.byte	0x8e		/* P:1, DPL:0 */
				.word	0x00		/* オフセット[31:16] */


idt_end:


				/* lidt命令用領域 */
idtr:			.word	idt_end - idt_base - 1
				.long	0




				.end


/* end of file */
