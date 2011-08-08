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
void ProcessObj_Delete(HANDLE hProcess)
{
	C_PROCESSOBJ *self;
	
	/* オブジェクトへキャスト */
	self = (C_PROCESSOBJ *)hProcess;
	
	/* 所有ハンドルはすべて閉じる */
	OwnerObj_CloseChildAdll(&self->OwnerObj);
	
	/* 参照オブジェクトがいればフラグを立てて削除保留 */
	if ( TargetObj_GetRefCounter(self) > 0 )
	{
		TargetObj_SetDeleteFlag(self);
		return;
	}
	
	/* デストラクタ呼び出し */
	ProcessObj_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */
