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
	/* バッファを確保していれば開放 */
	if ( self->pReadBuf != NULL )
	{
		SysMem_Free(self->pReadBuf);
	}
	if ( self->pWriteBuf != NULL )
	{
		SysMem_Free(self->pWriteBuf);
	}
	
	/* 親クラスデストラクタ呼び出し */
	HandleObj_Destructor(&self->HandleObj);
}


/* end of file */
