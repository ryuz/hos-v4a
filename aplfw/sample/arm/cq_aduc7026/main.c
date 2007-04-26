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


#define	POWKEY1		((volatile UB *)0xffff0404)
#define	POWKEY2		((volatile UB *)0xffff040c)
#define	POWCON		((volatile UB *)0xffff0408)


/** %jp{メイン関数} */
int main()
{
	/* %jp{41.78MHzに設定} */
	*POWKEY1 = 0x01;
	*POWCON  = 0x00;
	*POWKEY2 = 0xf4;
	
	/* %jp{カーネルの動作開始} */
	vsta_knl();
	
	return 0;
}



/* end of file */
