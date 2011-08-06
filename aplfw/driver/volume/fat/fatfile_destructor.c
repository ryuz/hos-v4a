/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatfile_local.h"


void  FatFile_Destructor(C_FATFILE *self)
{
	/* 親クラスデストラクタ */		
	FilePtr_Destructor(&self->FilePtr);
}


/* end of file */
