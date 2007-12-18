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
#include "sysvol.h"


C_FILE	 g_File;


void File_Initialize(void)
{
	C_FILE *self;

	self = &g_File;
	
	/* ルートボリューム生成 */
	self->hRootVol = SysVol_Create();
	
	/* デバイスボリューム生成 */
	self->hDevVol = SysVol_Create();
	
	/* ルートディレクトリの下に /dev ディレクトリを登録 */
	SysVol_AddDevice(self->hRootVol, "dev", self->hDevVol, FILE_ATTR_DIR);
}


/* end of file */
