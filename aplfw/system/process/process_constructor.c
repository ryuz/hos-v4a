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


static const T_HANDLEOBJ_METHODS Process_Methods =
	{
		Process_Delete,
	};


static void Process_Entry(VPARAM Param);


/** コンストラクタ */
PROCESS_ERR Process_Constructor(C_PROCESS *self, const T_HANDLEOBJ_METHODS *pMethods, const T_PROCESS_CREATE_INF *pInf)
{
	if ( pMethods == NULL )
	{
		pMethods = &Process_Methods;
	}

	/* メンバ変数初期化 */
	self->iExitCode   = -1;					/* 終了コード */
	self->pHandleList = NULL;				/* 所有するハンドルのリスト(終了時に開放) */
	self->pfncEntry = pInf->pfncEntry; 		/* 起動アドレス */
	self->Param     = pInf->Param;			/* ユーザーパラメータ */
	self->StackSize = pInf->StackSize;		/* スタックサイズ */
	self->Priority  = pInf->Priority;		/* プロセス優先度 */
	self->hTerminal = pInf->hTerminal;		/* ターミナル */
	self->hConsole  = pInf->hConsole;		/* コンソール */
	self->hStdIn    = pInf->hStdIn;			/* 標準入力 */
	self->hStdOut   = pInf->hStdOut;		/* 標準出力 */
	self->hStdErr   = pInf->hStdErr;		/* 標準エラー出力 */
	strncpy(self->szCurrentDir, pInf->szCurrentDir, FILE_MAX_PATH);	/* カレントディレクトリ */
	
	
	/* 待ち合わせ用イベント生成 */
	self->hEvt = SysEvt_Create(SYSEVT_ATTR_NORMAL);
	if ( self->hEvt == SYSEVT_HANDLE_NULL )
	{
		return PROCESS_ERR_NG;
	}
	SysEvt_Clear(self->hEvt);
	
	/* プロセス生成 */
	self->hPrc = SysPrc_Create(Process_Entry, (VPARAM)self, self->StackSize, self->Priority, SYSPRC_ATTR_NORMAL);
	if ( self->hPrc == SYSPRC_HANDLE_NULL )
	{
		SysEvt_Delete(self->hEvt);
		return PROCESS_ERR_NG;
	}
	
	/* 親クラスコンストラクタ */
	HandleObj_Constructor(&self->HandleObj, pMethods);
	
	/* 起動完了待ち */
	SysEvt_Wait(self->hEvt);
	
	return PROCESS_ERR_OK;
}


/* プロセスエントリーポイント */
void Process_Entry(VPARAM Param)
{
	C_PROCESS	*self;
	int			(*pfncEntry)(VPARAM Param);
	VPARAM		ProcParam;
	int			iExitCode;

	self = (C_PROCESS *)Param;

	pfncEntry = self->pfncEntry;
	ProcParam = self->Param;

	SysEvt_Set(self->hEvt);
	
	iExitCode = pfncEntry(ProcParam);
	
	Process_Exit(iExitCode);
}


/* end of file */
