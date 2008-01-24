/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "process_local.h"


/* プロセス削除 */
void Process_Delete(HANDLE hProcess)
{
	C_PROCESS *self;
	
	self = (C_PROCESS *)hProcess;

	/* デストラクタ呼び出し */
	Process_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */
