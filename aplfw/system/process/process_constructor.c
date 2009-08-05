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
#include "hosaplfw.h"
#include "process_local.h"
#include "system/system/system_local.h"



static const T_HANDLEOBJ_METHODS Process_Methods =
	{
		Process_Delete,
	};


static void Process_Entry(void);
static void Process_SignalHandler(void);


/** コンストラクタ */
PROCESS_ERR Process_Constructor(C_PROCESS *self, const T_HANDLEOBJ_METHODS *pMethods, const T_PROCESS_CREATE_INF *pInf)
{
	if ( pMethods == NULL )
	{
		pMethods = &Process_Methods;
	}

	/* メンバ変数初期化 */
	self->iExitCode     = -1;					/* 終了コード */
	self->iSignal        = 0;					/* シグナル番号 */
	self->pfncSignalProc = NULL;				/* シグナルハンドラ */
	self->pHandleList    = NULL;				/* 所有するハンドルのリスト(終了時に開放) */
	self->pfncEntry      = pInf->pfncEntry;		/* 起動アドレス */
	self->Param          = pInf->Param;			/* ユーザーパラメータ */
	self->pEnv           = NULL;				/* 環境変数用 */
	self->StackSize      = pInf->StackSize;		/* スタックサイズ */
	self->Priority       = pInf->Priority;		/* プロセス優先度 */
	self->SysMode        = 0;					/* システムモード */
	self->Exit           = 0;					/* 終了フラグ */
	self->hTerminal      = pInf->hTerminal;		/* ターミナル */
	self->hConIn         = pInf->hConIn;		/* コンソール入力 */
	self->hConOut        = pInf->hConOut;		/* コンソール出力 */
	self->hStdIn         = pInf->hStdIn;		/* 標準入力 */
	self->hStdOut        = pInf->hStdOut;		/* 標準出力 */
	self->hStdErr        = pInf->hStdErr;		/* 標準エラー出力 */
	
	/* コマンドラインコピー */
	if ( pInf->pszCommandLine != NULL )
	{
		if ( (self->pszCommandLine = (char *)SysMem_Alloc(strlen(pInf->pszCommandLine) + 1)) == NULL )
		{
			return PROCESS_ERR_NG;
		}
		strcpy(self->pszCommandLine, pInf->pszCommandLine);
	}
	else
	{
		self->pszCommandLine = NULL;
	}
	
	/* 起動ディレクトリコピー */
	if ( pInf->pszCurrentDir != NULL )
	{
		if ( (self->pszCurrentDir = (char *)SysMem_Alloc(strlen(pInf->pszCurrentDir) + 1)) == NULL )
		{
			SysMem_Free(self->pszCommandLine);
			return PROCESS_ERR_NG;
		}
		strcpy(self->pszCurrentDir, pInf->pszCurrentDir);
	}
	else
	{
		self->pszCurrentDir = NULL;
	}
	
	/* スタック用メモリ確保 */
	if ( (self->pStack = SysMem_Alloc(self->StackSize)) == NULL )
	{
		SysMem_Free(self->pszCommandLine);
		SysMem_Free(self->pszCurrentDir);
		return PROCESS_ERR_NG;
	}

	/* 待ち合わせ用イベント生成 */
	self->hEvt = SysEvt_Create(SYSEVT_ATTR_NORMAL);
	if ( self->hEvt == SYSEVT_HANDLE_NULL )
	{
		SysMem_Free(self->pStack);
		SysMem_Free(self->pszCommandLine);
		SysMem_Free(self->pszCurrentDir);
		return PROCESS_ERR_NG;
	}
	SysEvt_Clear(self->hEvt);
	
	/* プロセス生成 */
	self->hPrc = SysPrc_Create(Process_Entry, (VPARAM)self, self->pStack, self->StackSize, self->Priority, SYSPRC_ATTR_NORMAL);
	if ( self->hPrc == SYSPRC_HANDLE_NULL )
	{
		SysEvt_Delete(self->hEvt);
		SysMem_Free(self->pStack);
		SysMem_Free(self->pszCommandLine);
		SysMem_Free(self->pszCurrentDir);
		return PROCESS_ERR_NG;
	}
	
	/* システムに登録 */
	System_RegistryProcess(self);
	
	/* 親クラスコンストラクタ */
	HandleObj_Constructor(&self->HandleObj, pMethods);
	
	/* プロセス動作開始 */
	SysPrc_Start(self->hPrc);
	
	/* 起動完了待ち */
	SysEvt_Wait(self->hEvt);
	
	return PROCESS_ERR_OK;
}


/* プロセスエントリーポイント */
void Process_Entry(void)
{
	C_PROCESS	*self;
	int			(*pfncEntry)(VPARAM Param);
	VPARAM		ProcParam;
	int			iExitCode;
	
	self = (C_PROCESS *)SysPrc_GetParam(SysPrc_GetCurrentHandle());
	
	SysPrc_SetSignalHandler(SysPrc_GetCurrentHandle(), Process_SignalHandler);
	
	pfncEntry = self->pfncEntry;
	ProcParam = self->Param;

	SysEvt_Set(self->hEvt);
	
	if ( pfncEntry != NULL )
	{
		iExitCode = pfncEntry(ProcParam);
	}
	else
	{
		if ( Command_Execute(self->pszCommandLine, &iExitCode) != COMMAND_ERR_OK )
		{
			File_PutString(Process_GetStdErr(HANDLE_NULL), "command is not found.\n");
		}
	}
	
	Process_Exit(iExitCode);
}


/* シグナル受信ポイント */
void Process_SignalHandler(void)
{
	C_PROCESS	*self;

	self = (C_PROCESS *)SysPrc_GetParam(SysPrc_GetCurrentHandle());
	
	if ( self->pfncSignalProc != NULL )
	{
		self->pfncSignalProc(self->iSignal);
		return;
	}

	if ( self->iSignal == PROCESS_SIGNAL_KILL )
	{
		Process_Exit(-1);
	}
}


/* end of file */
