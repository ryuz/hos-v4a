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



/** %jp{メイン関数} */
int main()
{
	volatile char	*tvram = (volatile char *)0xb8000;
	const char		msg[] = "Hello Wold!";
	int				i;
	
	for ( i = 0; msg[i] != '\0'; i++ )
	{
		tvram[i*2] = msg[i];
	}
	
	for ( ; ; )
	{
	}
	
	/* %jp{カーネルの動作開始} */
/*	vsta_knl();	*/
	
	return 0;
}



/* end of file */
