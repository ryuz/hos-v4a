/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_delete.c
 * @brief %jp{XILINX UART driver オブジェクト削除}%en{XILINX UART driver  delete object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "xilinxuartdrv_local.h"


/** 削除 */
void XilinxUartDrv_Delete(HANDLE hDriver)
{
	C_XILINXUARTDRV	*self;
	
	/* upper cast */
	self = (C_XILINXUARTDRV *)hDriver;

	/* %jp{デストラクタ呼び出し}%en{destructor} */
	XilinxUartDrv_Destructor(self);
	
	/* %jp{メモリ開放}%en{free memory} */
	SysMem_Free(self);
}


/* end of file */
