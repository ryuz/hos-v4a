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
#include "file_local.h"


FILE_ERR File_IoControl(HANDLE hFile, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_FILEPTR *pFilePtr;
	C_FILEOBJ *pFileObj;
	
	pFilePtr = (C_FILEPTR *)hFile;
	pFileObj = FilePtr_GetFileObj(pFilePtr);
	
	return FileObj_GetMethods(pFileObj)->pfncIoControl(pFileObj, pFilePtr, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */
