/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  vt100drv_open.c
 * @brief %jp{VT100 ターミナルドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "vt100drv_local.h"
#include "system/sysapi/sysapi.h"


FILE_POS  Vt100Drv_Seek(struct c_drvobj *self, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign)
{
	return  FILE_ERR_NG;
}


/* end of file */
