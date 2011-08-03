/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include <string.h>
#include "process_local.h"


const char *Process_GetCurrentDir(void)
{
	C_PROCESSOBJ *self;

	/* オブジェクトを取得 */
	self = Process_GetCurrentProcessObj();

	return self->pszCurrentDir;
}



/* end of file */
