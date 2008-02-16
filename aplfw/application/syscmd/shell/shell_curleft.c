/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  shell_main.c
 * @brief %jp{シェル}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "shell_local.h"



/* カーソル左移動 */
void Shell_CurLeft(C_SHELL *self)
{
	if ( self->iCurScreenX == 0 )
	{
		self->iCurScreenX = self->iScreenWidth - 1;
		StdCon_PutString("\x1b[1A\x1b[80C");
	}
	else
	{
		self->iCurScreenX--;
		StdCon_PutString("\x1b[1D");		/* カーソル左 */
	}
}


/* end of file */
