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
#include "fileobj.h"
#include "filesys.h"
#include "system/sysapi/sysapi.h"
#include "system/memory/memory.h"



#define FILE_MAX_DEVICE		16

/* デバイスの登録テーブル */
static T_SYSFILE_DEVINF SysFile_DevTable[FILE_MAX_DEVICE];


/* ファイルシステムの初期化 */
void SysFile_Initialize(void)
{
}

void FileObj_Create(C_FILEOBJ *self, const T_FILEOBJ_METHODS* pMethods)
{
	HandleObj_Create(&self->HandleObj, &pMethods->HandlObjMethods);
}

void FileObj_Delete(C_FILEOBJ *self)
{
	HandleObj_Delete(&self->HandleObj);
}

/* デバイスファイルの追加 */
FILE_ERR SysFile_AddDevice(const char *pszPath, const T_SYSFILE_DEVINF *pDevInf)
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



FILE_ERR File_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( FileObj_GetMethods(self)->pfncIoControl != NULL )
	{
		return FileObj_GetMethods(self)->pfncIoControl(hFile, iFunc, pInBuf, InSize, pOutBuf, OutSize);
	}

	return FILE_ERR_NG;
}


FILE_POS  File_Seek(HANDLE hFile, FILE_POS Offset, int iOrign)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( FileObj_GetMethods(self)->pfncSeek != NULL )
	{
		return FileObj_GetMethods(self)->pfncSeek(hFile, Offset, iOrign);
	}

	return FILE_ERR_NG;
}


FILE_SIZE File_Write(HANDLE hFile, const void *pData, FILE_SIZE Size)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( FileObj_GetMethods(self)->pfncWrite != NULL )
	{
		return FileObj_GetMethods(self)->pfncWrite(hFile, pData, Size);
	}

	return FILE_ERR_NG;
}


FILE_SIZE File_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( FileObj_GetMethods(self)->pfncRead != NULL )
	{
		return FileObj_GetMethods(self)->pfncRead(hFile, pBuf, Size);
	}

	return FILE_ERR_NG;
}



int File_GetChar(HANDLE hFile)
{
	char c;
	if ( File_Read(hFile, &c, 1) != 1 )
	{
		return FILE_EOF;
	}
	return c;
}

int File_GetString(HANDLE hFile, char *pszString, int iSize)
{
	int i;
	int c;

	for ( i = 0; i < iSize - 1; i++ )
	{
		c = File_GetChar(hFile);
		if ( c == FILE_EOF )
		{
			if ( i == 0 )
			{
				return FILE_EOF;
			}
			break;
		}
	
		pszString[i] = c;

		if ( c == '\n' )
		{
			break;
		}
	}
	pszString[i] = '\0';

	return i;
}


int File_PutChar(HANDLE hFile, int c)
{
	char b;
	b = (char)c;
	if ( File_Write(hFile, &b, 1) == 1 )
	{
		return b;
	}
	return FILE_EOF;
}


int File_PutString(HANDLE hFile, const char *pszString)
{
	return File_Write(hFile, pszString, strlen(pszString));
}





/* end of file */
