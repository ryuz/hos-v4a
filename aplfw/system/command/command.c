
#include <string.h>
#include "command.h"
#include "system/sysapi/sysapi.h"
#include "library/container/assoc/assoc.h"


C_ASSOC Command_Assoc;


void Command_Initialize(void)
{
	/* システムメモリを使う連想配列を生成 */
	Assoc_Constructor(&Command_Assoc, SysMem_GetMemHeap());
}

/* コマンドを登録する */
void Command_AddCommand(const char *pszName, COMMAND_FUNC pfncMain)
{
	Assoc_Add(&Command_Assoc, pszName, &pfncMain, sizeof(pfncMain));
}


/* コマンドを実行する */
COMMAND_ERR Command_Execute(const char *pszCommandLine, int *piExitCode)
{
	const COMMAND_FUNC *ppfncMain;
	COMMAND_ERR Ret = COMMAND_ERR_NG;
	int  iExitCode;
	char *pszBuf;
	char **ppszArgv;
	int  iLen;
	int  iArgc = 0;
	int  i;
	
	/* メモリ確保 */
	iLen = strlen(pszCommandLine);
	if ( (pszBuf = (char *)SysMem_Alloc(iLen+1)) == NULL )
	{
		return COMMAND_ERR_NG;
	}
	if ( (ppszArgv = (char **)SysMem_Alloc((iLen/2+1) * sizeof(char *))) == NULL )
	{
		SysMem_Free(pszBuf);
		return COMMAND_ERR_NG;
	}

	/* パラメータ分解 */
	strcpy(pszBuf, pszCommandLine);
	for ( i = 0; ; )
	{
		/* 空白読み飛ばし */
		while ( pszBuf[i] == ' ' )
		{
			i++;
		}

		if ( pszBuf[i] == '\0' )
		{
			break;
		}
		
		/* パラメータ設定 */
		ppszArgv[iArgc++] = &pszBuf[i];

		/* 空白読み飛ばし */
		while ( pszBuf[i] != ' ' && pszBuf[i] != '\0' )
		{
			i++;
		}
		
		if ( pszBuf[i] == '\0' )
		{
			break;
		}

		pszBuf[i++] = '\0';
	}
	ppszArgv[iArgc] = NULL;
	
	if ( iArgc > 0 )
	{
		ppfncMain = (const COMMAND_FUNC *)Assoc_Get(&Command_Assoc, ppszArgv[0]);
		if ( ppfncMain != NULL )
		{
			iExitCode = (*ppfncMain)(iArgc, ppszArgv);
			if ( piExitCode != NULL )
			{
				*piExitCode = iExitCode;
			}
			Ret = COMMAND_ERR_OK;
		}
	}

	SysMem_Free(pszBuf);
	SysMem_Free(ppszArgv);

	return Ret;
}


COMMAND_PTR Command_GetFirstCommand(void)
{
	ASSOC_POS Pos;
	
	Pos = Assoc_GetFirst(&Command_Assoc);
	
	return (COMMAND_PTR)Pos;
}


COMMAND_PTR Command_GetNextCommand(COMMAND_PTR Ptr, const char **ppszName)
{
	ASSOC_POS Pos;
	
	Pos = (ASSOC_POS)Ptr;
	
	Assoc_GetAt(&Command_Assoc, Pos, ppszName);
	
	Pos = Assoc_GetNext(&Command_Assoc, Pos);

	return (COMMAND_PTR)Pos;
}


COMMAND_FUNC Command_GetCommandAddr(const char *pszName)
{
	const COMMAND_FUNC *ppfncMain;

	ppfncMain = (const COMMAND_FUNC *)Assoc_Get(&Command_Assoc, pszName);
	
	return *ppfncMain;
}



