/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバオブジェクトの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "drvobj_local.h"


FILE_POS DrvObj_Seek(C_DRVOBJ *self, struct c_fileobj *pFileObj, FILE_POS Offset, int iOrign)
{
	return FILE_ERR_NG;
}


/* end of file */
