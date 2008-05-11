/** 
 * Hyper Operating System V4 Advance
 *
 *  Sample program for PC/AT
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



IPL_SEG   = 0x07c0			/* ロードされるセグメントアドレス */
LOAD_SEG  = 0x0800			/* 本体をロードするセグメントアドレス */
IPL_ADDR  = (IPL_SEG << 4)
LOAD_ADDR = (LOAD_SEG << 4)

LOAD_SEC_NUM = 128


				.code16
				.text
				.org	0

				.global	ipl_top

		/***** IPL部 *****/
ipl_top:
				cli
				jmpl	$IPL_SEG, $ipl_start	/* CSの初期化 */
ipl_start:
				movw	$IPL_SEG, %ax
				movw	%ax, %ds				/* DSの初期化 */
				movw	%ax, %ss				/* SSの初期化 */
				movw	$0x200, %ax
				movw	%ax, %sp				/* SPの初期化 */

		/***** 初期化部 *****/
init_start:
				/* 画面のクリア */
				call	bios_clr_disp
				
				/* メッセージ出力 */
				movw    $boot_message, %si
				call	bios_puts
				
				/* 本体のロード */
				movw	$LOAD_SEG, %ax
				movw	%ax, %es
				xorw	%bx, %bx			/* 読込先アドレス */
				movw	$1, %ax				/* 読み込み論理セクタ番号 */
read_loop:		
				pushw	%ax
				pushw	%bx
				pushw	%es
				call	read_sector
				popw	%es
				popw	%bx
				popw	%ax
				
				addw	$1, %ax
				addw	$512, %bx
				cmp		$LOAD_SEC_NUM, %ax
				jnz		read_loop
				
				/* ネイティブモードへ移行 */
				jmp		switch_32bit
				
				
				/* エラー */
disk_error:		
				movw    $error_message, %si
				call	bios_puts
error_end:		
				nop
				jmp		error_end


read_sector:
				/* FDDから１セクタ読み込み */
				pushw	%bx
				mov		$18, %bl
				div		%bl
				popw	%bx
				
				xorw	%cx, %cx
				movb	%ah, %cl
				incb	%cl					/* セクタ設定 */
				
				movb	%al, %dh			/* ヘッド番号 */
				andb	$0x01, %dh
				
				shrb	$1, %al
				mov		%al, %ch			/* シリンダ番号 */
				
				movb	$0x00, %dl			/* ドライブ番号 */
				
				movb	$0x02, %ah			/* 機能コード */
				movb	$1, %al				/* セクタ数 */
				int		$0x13
				jc		disk_error
				cmp		$1, %al
				jnz		disk_error
				ret
				
				
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


switch_32bit:
				cli
				
				/* GDT設定 */
				lgdt	gdtr
				
				/* プロテクトモードへ移行 */
				movl	%cr0, %eax
				orl		$0x00000001, %eax
				movl	%eax, %cr0
				
				/* パイプラインフラッシュ */
				.byte	0xe9, 0x00, 0x00
				
				/* CS設定 */
				.byte	0xea
				.word	_start_32bit + IPL_ADDR
				.word	0x0008
				
				.code32
_start_32bit:	
				movw	$0x0010, %ax
				movw	%ax, %ss
				movw	%ax, %ds
				movw	%ax, %es
				movw	%ax, %fs
				movw	%ax, %gs
				
				movl	$LOAD_ADDR, %eax
				jmp		%eax



				/* 起動メッセージ */
boot_message:
		        .ascii	"HOS-Loader\r\nNow loading...\r\n\0"

				/* エラーメッセージ */
error_message:
		        .ascii	"disk error\r\n\0"



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
				.long	gdt_base + IPL_ADDR


				/* マジックナンバー */
				.org	510
				.word	0xaa55



/* end of file  */
