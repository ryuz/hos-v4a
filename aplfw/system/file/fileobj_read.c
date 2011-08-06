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


FILE_SIZE FileObj_Read(C_FILEOBJ *self, struct c_fileptr *pFilePtr, void *pBuf, FILE_SIZE Size)
{
	return FILE_ERR_NG;
}


/* end of file */
