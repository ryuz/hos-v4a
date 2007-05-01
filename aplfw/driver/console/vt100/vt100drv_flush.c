/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  vt100drv_open.c
 * @brief %jp{VT100 ターミナルドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "vt100drv_local.h"
#include "system/sysapi/sysapi.h"


FILE_ERR  Vt100Drv_Flush(struct c_drvobj *self, C_FILEOBJ *pFileObj)
{
	return  FILE_ERR_OK;
}


/* end of file */
