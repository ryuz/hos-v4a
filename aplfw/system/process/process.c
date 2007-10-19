

#include <stdio.h>
#include <string.h>
#include "procobj.h"
#include "system/sysapi/sysapi.h"


#define PROCESS_MAX_PROCESS		32


C_PROCESSOBJ *Process_pProcTable[PROCESS_MAX_PROCESS];

static void Process_Entry(VPARAM Param);


HANDLE Process_Create(int (*pfncEntry)(VPARAM Param), VPARAM Param, MEMSIZE StackSize, int Priority, const T_PROCESS_INF *pInf)
{
	C_PROCESSOBJ *self;
	int          i;

	/* メモリ確保 */
	if ( (self = (C_PROCESSOBJ *)SysMem_Alloc(sizeof(C_PROCESSOBJ))) == NULL )
	{
		return HANDLE_NULL;
	}

	/* プロセス生成 */
	self->hSysPrc = SysPrc_Create(Process_Entry, (VPARAM)self, StackSize, Priority);
	if ( self->hSysPrc == SYSPRC_HANDLE_NULL )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}

	self->pfncEntry = pfncEntry;
	self->Param     = Param;
	
	/* プロセスオブジェクト生成 */
	ProcessObj_Create(self);

	/* ハンドルの継承 */
	if ( pInf == NULL )
	{
		pInf = Process_GetInf(Process_GetCurrentHandle());
	}
	self->Inf = *pInf;

	/* テーブルに登録 */
	for ( i = 0; i < PROCESS_MAX_PROCESS; i++ )
	{
		if ( Process_pProcTable[i] == NULL )
		{
			Process_pProcTable[i] = self;
			break;
		}
	}
	
	/* プロセス動作開始 */
	SysPrc_Start(self->hSysPrc);
	
	return (HANDLE)self;
}

void Process_Entry(VPARAM Param)
{
	C_PROCESSOBJ *self;

	self = (C_PROCESSOBJ *)Param;

	self->iExitCode = self->pfncEntry(self->Param);
}



/* 現在のプロセスハンドル取得 */
HANDLE Process_GetCurrentHandle(void)
{
	SYSPRC_HANDLE hSysPrc;
	int i;
	
	hSysPrc = SysPrc_GetCurrentHandle();

	for ( i = 0; i < PROCESS_MAX_PROCESS; i++ )
	{
		if ( Process_pProcTable[i]->hSysPrc == hSysPrc )
		{
			return (HANDLE)Process_pProcTable[i];
		}
	}
	
	return HANDLE_NULL;
}


int Process_GetExitCode(HANDLE hProcess)
{
	C_PROCESSOBJ *self;

	self = (C_PROCESSOBJ *)hProcess;

	return self->iExitCode;
}


const T_PROCESS_INF *Process_GetInf(HANDLE hProcess)
{
	C_PROCESSOBJ *self;

	self = (C_PROCESSOBJ *)hProcess;
	return &self->Inf;
}


int Process_SetCurrentDir(const char *pszPath)
{
	C_PROCESSOBJ *self;

	self = (C_PROCESSOBJ *)Process_GetCurrentHandle();
	
	strncpy(self->szCurrentDir, pszPath, FILE_MAX_PATH);
	self->szCurrentDir[FILE_MAX_PATH-1] = '\0';
	
	return strlen(self->szCurrentDir);
}


int Process_GetCurrentDir(char *pszBuf, int iBufSize)
{
	C_PROCESSOBJ *self;

	self = (C_PROCESSOBJ *)Process_GetCurrentHandle();

	strncpy(pszBuf, self->szCurrentDir, iBufSize);
	pszBuf[iBufSize-1] = '\0';

	return strlen(pszBuf);
}


