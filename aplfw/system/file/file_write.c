/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "file_local.h"
#include "file_local.h"


FILE_SIZE File_Write(HANDLE hFile, const void *pData, FILE_SIZE Size)
{
	C_FILEPTR *pFilePtr;
	C_FILEOBJ *pFileObj;
	
	pFilePtr = (C_FILEPTR *)hFile;
	pFileObj = FilePtr_GetFileObj(pFilePtr);
	
	return FileObj_GetMethods(pFileObj)->pfncWrite(pFileObj, pFilePtr, pData, Size);
}



/* end of file */
