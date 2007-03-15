/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scifile.c
 * @brief %jp{SCI用デバイスドライバ用ファイルI/Fクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include "confile.h"

static void      ConsoleFile_Delete(HANDLE hFile);				/**< デストラクタ */
static FILE_ERR  ConsoleFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
static FILE_SIZE ConsoleFile_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
static FILE_SIZE ConsoleFile_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);


const T_FILEOBJ_METHODS ConsoleFile_FileObjMethods =
{
	{ ConsoleFile_Delete },		/* デストラクタ */
	NULL,						/* IoControl */
	NULL,						/* Seek */
	ConsoleFile_Read,			/* Read */
	ConsoleFile_Write,			/* Write */
};


/** コンストラクタ */
FILE_ERR ConsoleFile_Create(HANDLE hFile, void *pParam, const char *pszName, int iMode)
{
	C_CONSOLEFILE *self;

	self = (C_CONSOLEFILE *)hFile;

	/* 親クラスコンストラクタ呼び出し */
	FileObj_Create(&self->FileObj, &ConsoleFile_FileObjMethods);

	/* ターミナル保存 */
	self->hTty = (HANDLE)pParam;

	return FILE_ERR_OK;
}


/**< デストラクタ */
void ConsoleFile_Delete(HANDLE hFile)
{
}


FILE_SIZE ConsoleFile_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_CONSOLEFILE *self;
	FILE_SIZE i;
	char *pcBuf;
	int c;

	self = (C_CONSOLEFILE *)hFile;

	/* '\r' -> '\n' へ変換 */
	pcBuf = (char *)pBuf;
	i = 0;
	while ( i < Size )
	{
		if ( (c = File_GetChar(self->hTty)) == FILE_EOF )
		{
			break;
		}
		if ( c == '\r' )
		{
			pcBuf[i++] = '\n';
		}
		else if ( c != '\n' )
		{
			pcBuf[i++] = (char)c;
		}
	}

	return i;
}


FILE_SIZE ConsoleFile_Write(HANDLE hFile, const void *pData, FILE_SIZE Size)
{
	C_CONSOLEFILE *self;
	FILE_SIZE i;
	const char *pcBuf;

	self = (C_CONSOLEFILE *)hFile;

	/* '\n' -> '\r\n' へ変換 */
	pcBuf = (const char *)pData;
	for ( i = 0; i < Size; i++ )
	{
		if ( pcBuf[i] == '\n' )
		{
			File_Write(self->hTty, "\r\n", 2);
		}
		else
		{
			File_Write(self->hTty, &pcBuf[i], 1);
		}
	}

	return i;
}
