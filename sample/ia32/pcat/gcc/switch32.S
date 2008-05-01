/** 
 * Hyper Operating System V4 Advance
 *
 *  Sample program for PC/AT
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


LOAD_ADDR = 0x8000


				.code16
				.text

				.global		_switch32

/************************************************
  起動ハンドラ
************************************************/
_switch32:		
				/* 画面のクリア */
		//		call	bios_clr_disp
				
				/* メッセージ出力 */
				movw    $boot_message, %si
				call	bios_puts
				
				/* メモリマップ取得 */
/*				movl	0xe820, %eax
				movl	0x0000, %ebx	*/
				
				
				/* GDT設定 */
				lgdt	gdtr
				
				/* プロテクトモードへ移行 */
				movl	%cr0, %eax
				orl		$0x00000001, %eax
				movl	%eax, %cr0
				
				/* パイプラインフラッシュ */
				jmp		_pipeline_flush
_pipeline_flush:
				
				
				/* CS設定 */
				.byte	0x66, 0xea
				.long	_start_32bit + LOAD_ADDR
				.word	0x0008

				.code32

				movw	0x0010, %ax
				movw	%ax, %ss
				movl	$LOAD_ADDR, %esp
				
				movw	%ax, %ds
				movw	%ax, %es
				movw	%ax, %fs
				movw	%ax, %gs
				
_start_32bit:
				jmp		_start_32bit


				.code16
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
				.long	gdt_base + LOAD_ADDR



/************************************************
  メモリマップテーブル
************************************************/
memory_map:



				.end


/* end of file */
