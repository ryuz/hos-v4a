/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include <stdio.h>
#include "fatvol_local.h"


FILE_POS FatVol_GetFileSize(HANDLE hDir, int iDirEntry)
{
	unsigned char ubBuf[4];

	File_Seek(hDir, 32*iDirEntry+28, FILE_SEEK_SET);
	File_Read(hDir, ubBuf, 4);

	return ubBuf[0] + (ubBuf[1] << 8) + (ubBuf[2] << 16) + (ubBuf[3] << 24);
}


/* end of file */
