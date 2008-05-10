/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_setcursor.c
 * @brief %jp{PC/AT text mode driver}%en{PC/AT text mode driver}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"


void PcatTextDrv_SetCursor(C_PCATTEXTDRV *self, int iX, int iY)
{
	/* カーソル移動 */
	self->iCursorX = iX;
	self->iCursorY = iY;
}


/* end of file */
