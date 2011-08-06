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


FILE_POS File_Seek(HANDLE hFile, FILE_POS Offset, int iOrign)
{
	C_FILEPTR *pFilePtr;
	C_FILEOBJ *pFileObj;
	
	pFilePtr = (C_FILEPTR *)hFile;
	pFileObj = FilePtr_GetFileObj(pFilePtr);
	
	return FileObj_GetMethods(pFileObj)->pfncSeek(pFileObj, pFilePtr, Offset, iOrign);
}



/* end of file */
