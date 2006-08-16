/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  main.c
 * @brief %jp{メイン関数}%en{main}
 *
 * @version $Id: main.c,v 1.1 2006-08-16 16:27:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"


/** %jp{メイン関数} */
int main()
{
	/** %jp{カーネルの動作開始} */
	vsta_knl();
	
	return 0;
}


void *_kernel_int_isp = (void *)0x00ffff00;

/* end of file */
