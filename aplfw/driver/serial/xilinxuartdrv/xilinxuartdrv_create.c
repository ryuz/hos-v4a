/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_create.c
 * @brief %jp{XILINX UART driver オブジェクト生成}%en{XILINX UART driver  create object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "xilinxuartdrv_local.h"


/** %jp{オブジェクト生成}%en{create object} */
HANDLE XilinxUartDrv_Create(void *pRegBase, int iIntNum, int iBufSize)
{
	C_XILINXUARTDRV *self;
	
	/* %jp{メモリ確保}%en{Memory allocate} */
	if ( (self = (C_XILINXUARTDRV *)SysMem_Alloc(sizeof(C_XILINXUARTDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* %jp{コンストラクタ呼び出し}%en{constructor} */
	if ( XilinxUartDrv_Constructor(self, NULL, pRegBase, iIntNum, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
