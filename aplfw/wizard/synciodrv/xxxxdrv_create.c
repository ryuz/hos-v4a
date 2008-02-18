/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_create.c
 * @brief %jp{$OBJNAME_JP$ オブジェクト生成}%en{$OBJNAME_EN$  create object}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/** %jp{オブジェクト生成}%en{create object} */
HANDLE XxxxDrv_Create(void *pRegBase, int iIntNum)
{
	C_XXXXDRV *self;
	
	/* %jp{メモリ確保}%en{Memory allocate} */
	if ( (self = (C_XXXXDRV *)SysMem_Alloc(sizeof(C_XXXXDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* %jp{コンストラクタ呼び出し}%en{constructor} */
	if ( XxxxDrv_Constructor(self, NULL, pRegBase, iIntNum) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
