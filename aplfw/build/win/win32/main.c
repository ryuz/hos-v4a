/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  main.c
 * @brief %jp{メイン関数}%en{main}
 *
 * @version $Id: main.c,v 1.1 2006-11-06 15:02:57 ryuz Exp $
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


/* end of file */
