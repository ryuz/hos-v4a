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
	C_FILE *self;

	self = &g_File;
	
	/* ルートボリューム生成 */
	SysVol_Create(&self->RootVol);
	
	/* デバイスボリューム生成 */
	SysVol_Create(&self->DevVol);
	
	/* ルートディレクトリの下に /dev ディレクトリを登録 */
	SysVol_AddDevice(&self->RootVol, "dev", (C_DRVOBJ *)&self->DevVol, FILE_ATTR_DIR);
}


/* end of file */
