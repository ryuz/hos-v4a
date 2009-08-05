/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <string.h>
#include "process_local.h"
#include "system/system/system_local.h"


/** デストラクタ */
void Process_Destructor(C_PROCESS *self)
{
	/* プロセス削除 */
	SysPrc_Delete(self->hPrc);
	
	/* 待ち合わせ用イベント生成 */
	SysEvt_Delete(self->hEvt);
	
	/* スタック用メモリ開放 */
	SysMem_Free(self->pStack);

	/* コマンドライン用メモリ開放 */
	SysMem_Free(self->pszCommandLine);

	/* カレントディレクトリ用メモリ開放 */
	SysMem_Free(self->pszCurrentDir);
	
	/* システムから登録解除 */
	System_UnregistryProcess(self);
	
	/* 環境変数削除 */
	if ( self->pEnv != NULL )
	{
		Assoc_Delete(self->pEnv);
	}
	
	/* 親クラスデストラクタ呼び出し */
	HandleObj_Destructor(&self->HandleObj);
}


/* end of file */
