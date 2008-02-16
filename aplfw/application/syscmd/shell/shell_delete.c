/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  shell_delete.c
 * @brief %jp{シェル}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "shell_local.h"


/* デストラクタ */
void Shell_Delete(C_SHELL *self)
{
	int i;
	
	if ( self->ppszHistory != NULL )
	{
		for ( i = 0; i < self->iHistoryMax; i++ )
		{
			if ( self->ppszHistory[i] != NULL )
			{
				Memory_Free(self->ppszHistory[i]);
			}
		}
		Memory_Free(self->ppszHistory);
	}
	Memory_Free(self->pszCommanBuf);
	

	Memory_Free(self);
}



/* end of file */
