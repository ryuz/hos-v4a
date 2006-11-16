
#include <string.h>
#include "command.h"
#include "system/sysapi/sysapi.h"
#include "library/container/assoc/assoc.h"


C_ASSOC Command_Assoc;


void Command_Initialize(void)
{
	/* システムメモリを使う連想配列を生成 */
	Assoc_CreateEx(&Command_Assoc, SysMem_GetMemIf());
}

/* コマンドを登録する */
void Command_AddCommand(const char *pszName, COMMAND_FUNC pfncMain)
{
	Assoc_Add(&Command_Assoc, pszName, &pfncMain, sizeof(pfncMain));
}


/* コマンドを実行する */
int Command_Execute(const char *pszCommandLine)
{
	const COMMAND_FUNC *ppfncMain;
	char *pszBuf;
	char **ppszArgv;
	int  iLen;
	int  iArgc = 0;
	int  iRet = 0;
	int  i;

	iLen = strlen(pszCommandLine);
	pszBuf   = (char *)SysMem_Alloc(iLen+1);
	ppszArgv = (char **)SysMem_Alloc(iLen/2+1 * sizeof(char *));

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
			iRet = (*ppfncMain)(iArgc, ppszArgv);
		}
		else
		{
			iRet = 1;
		}
	}

	SysMem_Free(pszBuf);
	SysMem_Free(ppszArgv);

	return iRet;
}

