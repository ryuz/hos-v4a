/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  main.c
 * @brief %jp{メイン関数}%en{main}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"


#define REG_SYSPLLCTRL			((volatile UW *)0x40048008)
#define REG_SYSPLLSTAT			((volatile UW *)0x4004800C)
#define REG_SYSOSCCTRL			((volatile UW *)0x40048020)
#define REG_SYSPLLCLKSEL		((volatile UW *)0x40048040)
#define REG_SYSPLLCLKUEN		((volatile UW *)0x40048044)
#define REG_MAINCLKSEL			((volatile UW *)0x40048070)
#define REG_MAINCLKUEN			((volatile UW *)0x40048074)
#define REG_SYSAHBCLKDIV		((volatile UW *)0x40048078)
#define REG_SYSAHBCLKCTRL		((volatile UW *)0x40048080)
#define REG_SSP0CLKDIV			((volatile UW *)0x40048094)
#define REG_UARTCLKDIV			((volatile UW *)0x40048098)
#define REG_SSP1CLKDIV			((volatile UW *)0x4004809C)
#define REG_PDRUNCFG			((volatile UW *)0x40048238)

#define REG_GPIO0DATA(mask)		((volatile UW *)(0x50000000 + (((mask) & 0xfff) << 2)))
#define REG_GPIO0DIR			((volatile UW *)0x50008000)

/** %jp{メイン関数} */
int main()
{
	volatile int v;
	
	/* %jp{ハードウェアの初期化} */
	*REG_PDRUNCFG   &= 0xffffffdf;
	*REG_SYSOSCCTRL  = 0x00000000;
	for ( v = 0; v < 200; v++ )
		;
	*REG_SYSPLLCLKSEL = 0x00000000;
	*REG_SYSPLLCLKUEN = 0x00000001;
	*REG_SYSPLLCLKUEN = 0x00000000;
	*REG_SYSPLLCLKUEN = 0x00000001;
	while ( !(*REG_SYSPLLCLKUEN & 0x00000001) )
		;
	*REG_SYSPLLCTRL  = 0x00000023;
	*REG_PDRUNCFG   &= 0xffffff7f;
	while ( !(*REG_SYSPLLSTAT & 0x00000001) )
		;
	*REG_MAINCLKSEL = 0x00000003;
	*REG_MAINCLKUEN = 0x00000001;
	*REG_MAINCLKUEN = 0x00000000;
	*REG_MAINCLKUEN = 0x00000001;
	while ( !(*REG_MAINCLKUEN & 0x00000001) )
		;
	*REG_SYSAHBCLKDIV  = 0x00000001;
	*REG_SYSAHBCLKCTRL = 0x0001ffff;
	*REG_SSP0CLKDIV    = 0x00000001;
	*REG_UARTCLKDIV    = 0x00000001;
	*REG_SSP1CLKDIV    = 0x00000001;
	
	/* LEDをつけてみる */
	*REG_GPIO0DIR        |= 0x080;
	*REG_GPIO0DATA(0x80)  = 0x000;
	
	/* %jp{カーネルの動作開始} */
	vsta_knl();
	
	return 0;
}

/* dummy */
void _sbrk(void)
{
}


/* end of file */
