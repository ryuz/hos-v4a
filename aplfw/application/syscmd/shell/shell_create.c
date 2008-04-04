/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  shell_create.c
 * @brief %jp{シェル}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "shell_local.h"


/* コンストラクタ */
C_SHELL *Shell_Create(int iCommandBufSize, int iHistoryMax, int iExecSimple, int iExecTime)
{
	C_SHELL *self;

	/* オブジェクト生成 */
	if ( (self = Memory_Alloc(sizeof(C_SHELL))) == NULL )
	{
		StdIo_PutString("Memory error\n");
		return NULL;
	}
	
	/* メンバ初期化 */
	self->iScreenWidth    = 80;
	self->pBackGround     = NULL;
	self->ExecSimple      = (iExecSimple != 0);
	self->ExecTime        = (iExecTime != 0);
	self->iCommandBufSize = iCommandBufSize;
	self->iHistoryMax     = iHistoryMax;
	self->pszCommanBuf    = NULL;
	self->ppszHistory     = NULL;
	
	/* メモリ確保 */
	if ( (self->pszCommanBuf = (char *)Memory_Alloc(sizeof(char) * self->iCommandBufSize)) == NULL )
	{
		return NULL;
	}
	if ( self->iHistoryMax > 0 )
	{
		if ( (self->ppszHistory = (char **)Memory_Alloc(sizeof(char *) * self->iHistoryMax)) == NULL )
		{
			Memory_Free(self->pszCommanBuf);
			return NULL;
		}
		memset(self->ppszHistory, 0, sizeof(char *) * self->iHistoryMax);
	}
	
	return self;
}


/* end of file */
