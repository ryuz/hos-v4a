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



static void Process_Entry(void);
static void Process_SignalHandler(void);


/** コンストラクタ */
PROCESS_ERR ProcessObj_Constructor(C_PROCESSOBJ *self, const T_OBJECT_METHODS *pMethods, const T_PROCESS_CREATE_INF *pInf)
{
	C_PROCESSPTR	*pPtr;

	SYS_ASSERT(pMethods != NULL);
	SYS_ASSERT(pInf != NULL);

	/* メンバ変数初期化 */
	self->iExitCode      = -1;					/* 終了コード */
	self->iSignal        = 0;					/* シグナル番号 */
	self->pfncSignalProc = NULL;				/* シグナルハンドラ */
	self->pfncEntry      = pInf->pfncEntry;		/* 起動アドレス */
	self->Param          = pInf->Param;			/* ユーザーパラメータ */
	self->pEnv           = NULL;				/* 環境変数用 */
	self->StackSize      = pInf->StackSize;		/* スタックサイズ */
	self->Priority       = pInf->Priority;		/* プロセス優先度 */
	self->SysMode        = 0;					/* システムモード */
	self->Exit           = 0;					/* 終了フラグ */
	self->hTerminal      = pInf->hTerminal;		/* ターミナル */
	self->hConsole       = pInf->hConsole;		/* コンソール入力 */
	self->hStdIn         = pInf->hStdIn;		/* 標準入力 */
	self->hStdOut        = pInf->hStdOut;		/* 標準出力 */
	self->hStdErr        = pInf->hStdErr;		/* 標準エラー出力 */
	
	/* 自ポインタメモリ確保 */
	if ( (pPtr = (C_PROCESSPTR *)SysMem_Alloc(sizeof(C_PROCESSPTR))) == NULL )
	{
		return PROCESS_ERR_NG;
	}
	
	/* コマンドラインコピー */
	if ( pInf->pszCommandLine != NULL )
	{
		if ( (self->pszCommandLine = (char *)SysMem_Alloc(strlen(pInf->pszCommandLine) + 1)) == NULL )
		{
			SysMem_Free(pPtr);
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
			SysMem_Free(pPtr);
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
		SysMem_Free(pPtr);
		return PROCESS_ERR_NG;
	}

	/* 待ち合わせ用イベント生成 */
	self->hEvt = SysEvt_Create(SYSEVT_ATTR_NORMAL);
	if ( self->hEvt == SYSEVT_HANDLE_NULL )
	{
		SysMem_Free(self->pStack);
		SysMem_Free(self->pszCommandLine);
		SysMem_Free(self->pszCurrentDir);
		SysMem_Free(pPtr);
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
		SysMem_Free(pPtr);
		return PROCESS_ERR_NG;
	}

	/* 親クラスコンストラクタ */
	if ( pMethods == NULL )
	{
		pMethods = &ProcessObj_Methods;
	}
	OwnerObj_Constructor(&self->OwnerObj, pMethods);
	
	/* ポインタ紐付け */
	ProcessPtr_Constructor(pPtr, &ProcessPtr_Methods, self);
	
	/* システムに登録 */
	self->ulProcessId = System_RegistryProcess(self);
	
	/* プロセス動作開始 */
	SysPrc_Start(self->hPrc);
	
	/* 起動完了待ち */
	SysEvt_Wait(self->hEvt);
	
	return PROCESS_ERR_OK;
}


/* プロセスエントリーポイント */
void Process_Entry(void)
{
	C_PROCESSOBJ	*self;
	int				(*pfncEntry)(VPARAM Param);
	VPARAM			ProcParam;
	int				iExitCode;
	
	self = (C_PROCESSOBJ *)SysPrc_GetParam(SysPrc_GetCurrentHandle());
	
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
			File_PutString(Process_GetStdErr(), "command is not found.\n");
		}
	}
	
	Process_Exit(iExitCode);
}


/* シグナル受信ポイント */
void Process_SignalHandler(void)
{
	C_PROCESSOBJ	*self;

	self = (C_PROCESSOBJ *)SysPrc_GetParam(SysPrc_GetCurrentHandle());
	
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