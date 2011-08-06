/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file_local.h
 * @brief %jp{デバイスドライバオブジェクトの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "file_local.h"


FILE_ERR  FileObj_IoControl(C_FILEOBJ *self, struct c_fileptr *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return FILE_ERR_NG;
}


/* end of file */
