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


void PcatTextDrv_PutChar(C_PCATTEXTDRV *self, int c)
{
	int i, j;
	
	if ( c != '\n' )
	{
		/* 文字出力 */
		self->puhTextVram[(self->iCursorY * self->iScreenWidth) + self->iCursorX] = ((c & 0xff) | (self->ubCharAttr << 8));
		
		if ( self->iCursorX + 1 < self->iScreenWidth )
		{
			/* 改行不要 */
			PcatTextDrv_SetCursor(self, self->iCursorX + 1, self->iCursorY);
			return;
		}		
	}
	
	/* 改行処理 */
	if ( self->iCursorY + 1 < self->iScreenHeight )
	{
		/* 単純改行 */
		PcatTextDrv_SetCursor(self, 0, self->iCursorY + 1);
	}
	else
	{
		/* スクロール */
		for ( i = 0; i < self->iScreenHeight - 1; i++ )
		{
			for ( j = 0; j < self->iScreenWidth; j++ )
			{
				self->puhTextVram[(i * self->iScreenWidth) + j] = self->puhTextVram[((i + 1) * self->iScreenWidth) + j];
			}
		}
		
		/* 新しい行を初期化 */
		for ( j = 0; j < self->iScreenWidth; j++ )
		{
			self->puhTextVram[(self->iScreenHeight - 1) * self->iScreenWidth + j] = 0x0720;
		}
		
		PcatTextDrv_SetCursor(self, 0, self->iScreenHeight - 1);
	}
}


/* end of file */
