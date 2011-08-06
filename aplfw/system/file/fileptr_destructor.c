/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "file_local.h"


void FilePtr_Destructor(C_FILEPTR *self)
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
	PointerObj_Destructor(&self->PointerObj);
}


/* end of file */
