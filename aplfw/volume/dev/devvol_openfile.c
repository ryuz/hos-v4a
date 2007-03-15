#include <stdio.h>
#include <string.h>
#include "devvol_local.h"
#include "system/sysapi/sysapi.h"


/* ファイルを開く */
HANDLE DevVol_OpenFile(HANDLE hVolume, const char *pszPath, int iMode)
{
	C_DEVVOL *self;
	HANDLE   hFile;
	int      i;

	self = (C_DEVVOL *)hVolume;
	
	
	/* 先頭の'/'を読み飛ばし */
	pszPath++;
	
	/* デバイスを検索 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		if ( strcmp(pszPath, self->DevTable[i].szName) == 0 )
		{
			break;
		}
	}
	if ( i >= DEVVOL_MAX_DEVICE )
	{
		return HANDLE_NULL;
	}
	
	/* メモリ確保 */
	hFile = (HANDLE)SysMem_Alloc(self->DevTable[i].ObjSize);
	if ( hFile == 0 )
	{
		return HANDLE_NULL;
	}
	
	/* ファイルハンドル生成 */
	if ( self->DevTable[i].pfncCreate(hFile, self->DevTable[i].pParam, iMode) != FILE_ERR_OK )
	{
		SysMem_Free((void *)hFile);
		return HANDLE_NULL;
	}

	return hFile;
}


/* end of file */

