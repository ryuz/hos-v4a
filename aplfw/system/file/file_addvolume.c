/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "file_local.h"


/* デバイスファイルの追加 */
FILE_ERR File_AddVolume(const T_FILE_VOLINF *pVolInf)
{
	C_FILE *self;
	int i;

	self = &g_File; 

	/* テーブルの空きを検索 */
	for ( i = 0; i < FILE_MAX_VOLUME; i++ )
	{
		if ( self->VolumeTable[i].hVolume == HANDLE_NULL )
		{
			self->VolumeTable[i] = *pVolInf;
			return FILE_ERR_OK;
		}
	}
	
	return FILE_ERR_NG;
}


/* endof file */
