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
void ProcessObj_Destructor(C_PROCESSOBJ *self)
{
	/* システムから登録解除 */
	System_UnregistryProcess(self->ulProcessId);

	/* プロセス削除 */
	SysPrc_Delete(self->hPrc);
	
	/* 待ち合わせ用イベント削除 */
	SysEvt_Delete(self->hEvt);
	
	/* スタック用メモリ開放 */
	SysMem_Free(self->pStack);

	/* コマンドライン用メモリ開放 */
	SysMem_Free(self->pszCommandLine);

	/* カレントディレクトリ用メモリ開放 */
	SysMem_Free(self->pszCurrentDir);
	
	/* 環境変数削除 */
	if ( self->pEnv != NULL )
	{
		Assoc_Delete(self->pEnv);
	}
}


/* end of file */
