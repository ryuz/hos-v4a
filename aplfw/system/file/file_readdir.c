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


FILE_ERR File_ReadDir(HANDLE hFile, T_FILE_FILEINF *pFileInf)
{
	return File_IoControl(hFile, FILE_IOCTL_DIR_READ, pFileInf, sizeof(T_FILE_FILEINF), NULL, 0);
}


/* end of file */
