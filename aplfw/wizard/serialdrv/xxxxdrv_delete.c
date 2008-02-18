/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_delete.c
 * @brief %jp{$OBJNAME_JP$ オブジェクト削除}%en{$OBJNAME_EN$  delete object}
 *
 * $COPYRIGHT$
 */



#include "xxxxdrv_local.h"


/** 削除 */
void XxxxDrv_Delete(HANDLE hDriver)
{
	C_XXXXDRV	*self;
	
	/* upper cast */
	self = (C_XXXXDRV *)hDriver;

	/* %jp{デストラクタ呼び出し}%en{destructor} */
	XxxxDrv_Destructor(self);
	
	/* %jp{メモリ開放}%en{free memory} */
	SysMem_Free(self);
}


/* end of file */
