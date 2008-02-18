/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxfile_destructor.c
 * @brief %jp{$OBJNAME_JP$ デストラクタ}%en{$OBJNAME_EN$  destructor}
 *
 * $COPYRIGHT$
 */


#include "xxxxfile_local.h"


void  XxxxFile_Destructor(C_XXXXFILE *self)
{
	/* 親クラスデストラクタ */		
	SyncFile_Destructor(&self->SyncFile);
}


/* end of file */
