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


void File_Close(HANDLE hFile)
{
	C_FILEPTR *pFilePtr;
	C_FILEOBJ *pFileObj;
	
	pFilePtr = (C_FILEPTR *)hFile;
	pFileObj = FilePtr_GetFileObj(pFilePtr);
	
	FileObj_GetMethods(pFileObj)->pfncClose(pFileObj, pFilePtr);
}



/* end of file */
