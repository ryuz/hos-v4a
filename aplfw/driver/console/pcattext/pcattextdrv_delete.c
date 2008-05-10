/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_delete.c
 * @brief %jp{PC/AT text mode driver オブジェクト削除}%en{PC/AT text mode driver  delete object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "pcattextdrv_local.h"


/** 削除 */
void PcatTextDrv_Delete(HANDLE hDriver)
{
	C_PCATTEXTDRV	*self;
	
	/* upper cast */
	self = (C_PCATTEXTDRV *)hDriver;

	/* %jp{デストラクタ呼び出し}%en{destructor} */
	PcatTextDrv_Destructor(self);
	
	/* %jp{メモリ開放}%en{free memory} */
	SysMem_Free(self);
}


/* end of file */
