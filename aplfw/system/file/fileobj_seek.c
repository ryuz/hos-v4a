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


FILE_POS FileObj_Seek(C_FILEOBJ *self, struct c_fileptr *pFilePtr, FILE_POS Offset, int iOrign)
{
	return FILE_ERR_NG;
}


/* end of file */
