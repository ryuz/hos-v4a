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
	DrvObj_Destructor(&self->DrvObj);
}


/* end of file */
