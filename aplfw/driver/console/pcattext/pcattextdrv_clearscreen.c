/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_cleanscreen.c
 * @brief %jp{PC/AT text mode driver 画面クリア}%en{PC/AT text mode driver}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"


void PcatTextDrv_ClearScreen(C_PCATTEXTDRV *self)
{
	int i;
	
	/* Text-VRAM初期化 */
	for ( i = 0; i < self->iScreenWidth * self->iScreenHeight; i++ )
	{
		self->puhTextVram[i] = 0x0720;
	}
	
	/* カーソル初期化 */
	PcatTextDrv_SetCursor(self, 0, 0);
}


/* end of file */
