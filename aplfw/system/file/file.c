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

	if ( FileObj_GetMethods(self)->pfncIoControl != NULL )
	{
		return FileObj_GetMethods(self)->pfncIoControl(hFile, iFunc, pInBuf, InSize, pOutBuf, OutSize);
	}

	return FILE_ERR_NG;
}


FILEPOS  File_Seek(HANDLE hFile, FILEPOS Offset, int iOrign)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( FileObj_GetMethods(self)->pfncSeek != NULL )
	{
		return FileObj_GetMethods(self)->pfncSeek(hFile, Offset, iOrign);
	}

	return FILE_ERR_NG;
}


FILESIZE File_Write(HANDLE hFile, const void *pData, FILESIZE Size)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( FileObj_GetMethods(self)->pfncWrite != NULL )
	{
		return FileObj_GetMethods(self)->pfncWrite(hFile, pData, Size);
	}

	return FILE_ERR_NG;
}


FILESIZE File_Read(HANDLE hFile, void *pBuf, FILESIZE Size)
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


int File_PrintFormatV(HANDLE hFile, const char *pszFormat, va_list argptr)
{
	char *pBuf;
	int  iRet = 0;
	
	pBuf = (char *)Memory_Alloc(128);
	if ( pBuf != NULL )
	{
/*		iRet = vsprintf(pBuf, pszFormat, argptr);	*/	/* 肥大化するのでちと保留 */
		if ( iRet > 0 )
		{
			iRet = File_Write(hFile, pBuf, iRet);
		}
		Memory_Free(pBuf);
	}

	return iRet;
}


int File_PrintFormat(HANDLE hFile, const char *pszFormat, ...)
{
	va_list argptr;
	int iRet;

	va_start(argptr, pszFormat);
	iRet = File_PrintFormatV(hFile, pszFormat, argptr);
	va_end(argptr);

	return iRet;
}


int File_PrintHexNibble(HANDLE hFile, unsigned char c)
{
	c &= 0xf;
	if ( c < 10 )
	{
		c = c + '0';
	}
	else
	{
		c = c - 10 + 'a';
	}
	return File_PutChar(hFile, c);
}

void File_PrintHexByte(HANDLE hFile, unsigned char ubData)
{
	File_PrintHexNibble(hFile, (unsigned char)(ubData >> 4));
	File_PrintHexNibble(hFile, (unsigned char)(ubData >> 0));
}

void File_PrintHexHalfWord(HANDLE hFile, unsigned short uhData)
{
	File_PrintHexByte(hFile, (unsigned char)(uhData >> 8));
	File_PrintHexByte(hFile, (unsigned char)(uhData >> 0));
}

void File_PrintHexWord(HANDLE hFile, unsigned long uwData)
{
	File_PrintHexHalfWord(hFile, (unsigned short)(uwData >> 16));
	File_PrintHexHalfWord(hFile, (unsigned short)(uwData >> 0));
}




int File_PrintFormatDecimal(HANDLE hFile, long lNum, int iWidth, int iPadChar)
{
	char szBuf[12];
	int  iLen = 0;
	int  iSign = 0;
	int  i;

	/* 符号チェック */
	if ( lNum < 0 )
	{
		lNum  = -lNum;
		iSign = 1;
	}

	/* 文字列変換 */
	i = sizeof(szBuf);
	szBuf[--i] = '\0';
	do
	{
		szBuf[--i] = lNum % 10 + '0';
		lNum       = lNum / 10;
	} while ( lNum != 0 );
	
	/* 符号付加 */
	if ( iSign )
	{
		szBuf[--i] = '-';
	}

	iWidth -= (sizeof(szBuf) - i);
	while ( iWidth > 0 )
	{
		File_PutChar(hFile, iPadChar);
		iWidth--;
		iLen++;
	}
	
	iLen += File_PutString(hFile, szBuf);

	return iLen;
}


/* */
int File_PrintFormatHex(HANDLE hFile, long lNum, int iWidth, int iPadChar)
{
	return 0;
}


#define FILE_PRTFMT_NORMAL		0
#define FILE_PRTFMT_ESC			1
#define FILE_PRTFMT_WIDTH		2

/* 書式付き出力軽量版 */
int File_PrintFormatVL(HANDLE hFile, const char *pszFormat, va_list argptr)
{
	int iState = FILE_PRTFMT_NORMAL;
	int iLong;
	int iPadChar;
	int iWidth;
	int iLen = 0;
	int c;
	
	while ( (c = *pszFormat++) != '\0' )
	{
		switch ( iState )
		{
		case FILE_PRTFMT_NORMAL:
			if ( c == '%' )
			{
				iLong    = 0;
				iWidth   = 0;
				iPadChar = ' ';
				iState   = FILE_PRTFMT_ESC;
			}
			else
			{
				iLen += (File_PutChar(hFile, c) != FILE_EOF);
			}
			break;

		case FILE_PRTFMT_ESC:
			if ( c == '%' )
			{
				iLen += (File_PutChar(hFile, c) != FILE_EOF);
				iState = FILE_PRTFMT_NORMAL;
			}
			else if ( c >= '0' && c <= '9' )
			{
				c -= '0';
				iWidth = (iWidth * 10) + c;
				if ( iWidth == 0 )
				{
					iPadChar = '0';
				}
			}
			else if ( c == 'l' )
			{
				iLong = 1;
			}
			else if ( c == 'd' || c == 'x' || c == 'X' )
			{
				long lNum;
				if ( iLong )
				{
					lNum = va_arg(argptr, long);
				}
				else
				{
					lNum = va_arg(argptr, int);
				}

				if ( c == 'd' )
				{
					iLen += File_PrintFormatDecimal(hFile, lNum, iWidth, iPadChar);
				}
				else
				{
					iLen += File_PrintFormatHex(hFile, lNum, iWidth, iPadChar);
				}
				iState = FILE_PRTFMT_NORMAL;
			}
			else if ( c == 's' )
			{
				const char *pszStr;
				pszStr  = va_arg(argptr, const char *);
				iLen   += File_PutString(hFile, pszStr);
				iState  = FILE_PRTFMT_NORMAL;
			}
			else
			{
				iLen += (File_PutChar(hFile, c) != FILE_EOF);
				iState = FILE_PRTFMT_NORMAL;
			}
			break;
		}
	}

	return iLen;
}




/* end of file */
