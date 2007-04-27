/**
 *  Hyper Operating System  Application Framework
 *
 * @file  drvfile_seek.c
 * @brief %jp{デバイスドライバファイルの基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "drvfile_local.h"


/* シーク制御 */
FILE_POS  DrvFile_Seek(HANDLE hFile, FILE_POS Offset, int iOrign)
{
	C_DRVFILE *self;

	self = DRVFILE_HANDLE2OBJ(hFile);
	
	return DrvObj_Seek(self->pDrvObj, hFile, Offset, iOrign);
}


/* end of file */
