/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "file.h"
#include "sysapi.h"


#define FILE_MAX_DEVICE		16


/* デバイスの登録テーブル */
static T_SYSFILE_DEVINF SysFile_DevTable[FILE_MAX_DEVICE];


/* ファイルシステムの初期化 */
void SysFile_Initialize(void)
{
}

void FileObj_Create(C_FILEOBJ *self)
{
}

void FileObj_Delete(C_FILEOBJ *self)
{
}


/* デバイスファイルの追加 */
FILEERR SysFile_AddDevice(const char *pszPath, const T_SYSFILE_DEVINF *pDevInf)
{
	int i;

	/* テーブルの空きを検索 */
	for ( i = 0; i < FILE_MAX_DEVICE; i++ )
	{
		if ( SysFile_DevTable[i].ObjSize == 0 )
		{
			SysFile_DevTable[i] = *pDevInf;
			return FILE_ERR_OK;
		}
	}

	return FILE_ERR_NG;
}



/* ファイルのオープン */
HANDLE File_Open(const char *pszName, int iMode)
{
	HANDLE hFile;
	int i;

	/* さしあたって、/dev 以下の事だけ考える */
	/* そのうちまともなファイルシステムにして遊ぶ */
	if ( strncmp(pszName, "/dev/", 5) != 0 )
	{
		return HANDLE_NULL;
	}
	pszName += 5;
	
	/* デバイスを検索 */
	for ( i = 0; i < FILE_MAX_DEVICE; i++ )
	{
		if ( strcmp(pszName, SysFile_DevTable[i].szName) == 0 )
		{
			break;
		}
	}
	if ( i >= FILE_MAX_DEVICE )
	{
		return HANDLE_NULL;
	}

	/* メモリ確保 */
	hFile = SysMem_Alloc(SysFile_DevTable[i].ObjSize);
	if ( hFile == 0 )
	{
		return HANDLE_NULL;
	}

	/* ファイルハンドル生成 */
	if ( SysFile_DevTable[i].pfncCreate(hFile, SysFile_DevTable[i].pParam) != FILE_ERR_OK )
	{
		SysMem_Free((void *)hFile);
		return HANDLE_NULL;
	}

	return hFile;
}



FILEERR File_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILESIZE InSize, void *pOutBuf, FILESIZE OutSize)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( self->pMethods->pfncIoControl != NULL )
	{
		return self->pMethods->pfncIoControl(hFile, iFunc, pInBuf, InSize, pOutBuf, OutSize);
	}

	return FILE_ERR_NG;
}


FILEPOS  File_Seek(HANDLE hFile, FILEPOS Offset, int iOrign)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( self->pMethods->pfncSeek != NULL )
	{
		return self->pMethods->pfncSeek(hFile, Offset, iOrign);
	}

	return FILE_ERR_NG;
}


FILESIZE File_Write(HANDLE hFile, const void *pData, FILESIZE Size)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( self->pMethods->pfncWrite != NULL )
	{
		return self->pMethods->pfncWrite(hFile, pData, Size);
	}

	return FILE_ERR_NG;
}


FILESIZE File_Read(HANDLE hFile, void *pBuf, FILESIZE Size)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( self->pMethods->pfncRead != NULL )
	{
		return self->pMethods->pfncRead(hFile, pBuf, Size);
	}

	return FILE_ERR_NG;
}



/* end of file */
