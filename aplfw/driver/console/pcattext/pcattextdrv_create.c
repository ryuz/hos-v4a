/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_create.c
 * @brief %jp{PC/AT text mode driver オブジェクト生成}%en{PC/AT text mode driver  create object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"



/** %jp{オブジェクト生成}%en{create object} */
HANDLE PcatTextDrv_Create(void *pRegBase, void *pVramBase)
{
	C_PCATTEXTDRV *self;
	
	/* %jp{メモリ確保}%en{Memory allocate} */
	if ( (self = (C_PCATTEXTDRV *)SysMem_Alloc(sizeof(C_PCATTEXTDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* %jp{コンストラクタ呼び出し}%en{constructor} */
	if ( PcatTextDrv_Constructor(self, NULL, pRegBase, pVramBase) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
