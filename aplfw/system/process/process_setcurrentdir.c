/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include <string.h>
#include "process_local.h"



int Process_SetCurrentDir(HANDLE hProcess, const char *pszPath)
{
	C_PROCESS	*self;
	char		*pcBuf;
	int			iLen;
	
	/* ハンドルからオブジェクト本体を取得 */
	self = ProcessHandle_GetProcess(hProcess);
	
	iLen = strlen(pszPath);
	if ( iLen >= FILE_MAX_PATH )
	{
		return 0;
	}
	
	if ( (pcBuf = SysMem_Alloc(iLen + 1)) == NULL )
	{
		return 0;
	}
	
	/* 古いバッファを開放 */
	SysMem_Free(self->pszCurrentDir);
	strcpy(pcBuf, pszPath);
	self->pszCurrentDir = pcBuf;
		
	return iLen;
}



/* end of file */
