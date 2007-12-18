/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "fileobj_local.h"


void FileObj_Destructor(C_FILEOBJ *self)
{
	/* 親クラスデストラクタ呼び出し */
	HandleObj_Destructor(&self->HandleObj);
}


/* end of file */
