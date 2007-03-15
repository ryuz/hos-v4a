/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fileobj.h"


void FileObj_Create(C_FILEOBJ *self, const T_FILEOBJ_METHODS* pMethods)
{
	HandleObj_Create(&self->HandleObj, &pMethods->HandlObjMethods);
}


/* end of file */
