/**
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{割込みコントローラ固有属性定義}%jp{Interrupt controler attribute}
 *  %jp{割込みハンドラと割込みサービスルーチンが単純対応する場合}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc_none_h__
#define _KERNEL__arch__irc_none_h__


#ifdef __cplusplus
extern "C" {
#endif

void _kernel_exe_isr(INTNO intno);

#ifdef __cplusplus
}
#endif


#define _KERNEL_INI_IRC()			do {} while (0)						/**< %jp{IRCの初期化ハンドラ} */
#define _KERNEL_EXE_IRC(inhno)		_kernel_exe_isr((INTNO)(inhno))		/**< %jp{IRCの処理ルーチン} */


#endif	/* _KERNEL__arch__irc_none_h__ */


/* end of file */
