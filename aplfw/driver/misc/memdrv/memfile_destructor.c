/** 
 * Hyper Operating System  Application Framework
 *
 * @file  memfile_destructor.c
 * @brief %jp{memory file デストラクタ}%en{Memory File  destructor}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "memfile_local.h"


void  MemFile_Destructor(C_MEMFILE *self)
{
	/* 親クラスデストラクタ */		
	FilePtr_Destructor(&self->FilePtr);
}


/* end of file */
