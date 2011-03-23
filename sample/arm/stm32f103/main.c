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


#define REG_RCC_APB2ENR		((volatile UW *)0x40021018)
#define REG_GPIOC_CRL		((volatile UW *)0x40011000)
#define REG_GPIOC_ODR		((volatile UW *)0x4001100c)


/** %jp{メイン関数} */
int main()
{
	/* LED ON */
	*REG_RCC_APB2ENR = 0x00000010;
	*REG_GPIOC_CRL   = 0x42444444;
	*REG_GPIOC_ODR   = 0x00000040;


	/* %jp{カーネルの動作開始} */
	vsta_knl();

	return 0;
}

/* dummy */
void _sbrk(void)
{
}


/* end of file */
