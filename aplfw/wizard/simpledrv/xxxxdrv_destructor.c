/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_destructor.c
 * @brief %jp{$OBJNAME_JP$ デストラクタ}%en{$OBJNAME_EN$  destructor}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/** デストラクタ */
void XxxxDrv_Destructor(C_XXXXDRV *self)
{
	/* 親クラスデストラクタ */
	FileObj_Destructor(&self->FileObj);
}


/* end of file */
