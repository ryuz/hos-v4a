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
#include "volume/dev/devvol.h"


C_FILE	 g_File;
C_DEVVOL g_DevVol;


void File_Initialize(void)
{
	const static T_FILE_VOLINF VolInf = {"dev", (HANDLE)&g_DevVol};

	C_FILE *self;

	self = &g_File;

	DevVol_Create(&g_DevVol);	
	File_AddVolume(&VolInf);

	self->hDevVol = (HANDLE)&g_DevVol;	
}

