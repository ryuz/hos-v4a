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


FILE_ERR  DrvObj_IoControl(C_DRVOBJ *self, struct c_fileobj *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return FILE_ERR_NG;
}


/* end of file */
