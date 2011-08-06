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



FILE_SIZE File_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_FILEPTR *pFilePtr;
	C_FILEOBJ *pFileObj;
	
	pFilePtr = (C_FILEPTR *)hFile;
	pFileObj = FilePtr_GetFileObj(pFilePtr);
	
	return FileObj_GetMethods(pFileObj)->pfncRead(pFileObj, pFilePtr, pBuf, Size);
}



/* end of file */
