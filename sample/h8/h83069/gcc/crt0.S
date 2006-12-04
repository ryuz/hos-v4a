
				.h8300h
				
				
				.global __reset_handler
				.global __kernel_int_isp
				
				.text

__reset_handler:	
				mov.l	@(__kernel_int_isp), sp

		; data セクションコピー
				mov.l	#___data_rom, er0
				mov.l	#___data_end, er1
				mov.l	#___data, er2
data_copy_loop:	
				mov.w	@er0, r3
				mov.w	r3, @er2
				adds	#2, er0
				adds	#2, er2
				cmp.l	er1, er2
				blo		data_copy_loop

		; bssセクション初期化
				mov.l	#___bss, er0
				mov.l	#___bss_end, er1
				mov.w	#0, r2
bss_init_loop:
				mov.w	r2, @er0
				adds	#2, er0
				cmp.l	er1, er0
				blo		bss_init_loop

		; main関数へ分岐
				jsr		@___main
				jsr		@_main
	;			jsr		@_exit

				.end
