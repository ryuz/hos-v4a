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
#include "file_local.h"
#include "fileobj.h"
#include "system/sysapi/sysapi.h"
#include "system/memory/memory.h"


int File_PrintFormatV(HANDLE hFile, const char *pszFormat, va_list argptr)
{
	char *pBuf;
	int  iRet = 0;
	
	pBuf = (char *)Memory_Alloc(128);
	if ( pBuf != NULL )
	{
	/*	iRet = vsprintf(pBuf, pszFormat, argptr);	*/	/* 肥大化するのでちと保留 */
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
	iRet = File_PrintFormatVL(hFile, pszFormat, argptr);
	va_end(argptr);

	return iRet;
}


/* 4bitの16進数を出力 */
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

/* n桁の16進数を出力 */
int File_PrintHex(HANDLE hFile, unsigned long ulData, int n)
{
	int iLen = 0;
	int i;

	for ( i = (n - 1) * 4 ; i >= 0; i-- )
	{
		if ( File_PrintHexNibble(hFile, (unsigned char)(ulData >> i)) == FILE_EOF )
		{
			break;
		}
		iLen++;
	}
	
	if ( iLen == 0 )
	{
		return FILE_EOF;
	}
	return iLen;
}


/* 書式付き10進数出力 */
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

	iWidth -= (sizeof(szBuf) - i - 1);
	while ( iWidth > 0 )
	{
		File_PutChar(hFile, iPadChar);
		iWidth--;
		iLen++;
	}
	
	iLen += File_PutString(hFile, &szBuf[i]);

	return iLen;
}


int File_PrintFormatHex(HANDLE hFile, long lNum, int iWidth, int iPadChar)
{
	char szBuf[9];
	int  iLen = 0;
	int  i;
	
	/* 文字列変換 */
	i = sizeof(szBuf);
	szBuf[--i] = '\0';
	do
	{
		szBuf[--i]   = (lNum & 0xf) < 10 ? (lNum & 0xf) + '0' : (lNum & 0xf) - 10 + 'a';
		lNum = ((unsigned long)lNum >> 4);
	} while ( lNum != 0 );
	
	iWidth -= (sizeof(szBuf) - i - 1);
	while ( iWidth > 0 )
	{
		File_PutChar(hFile, iPadChar);
		iWidth--;
		iLen++;
	}
	
	iLen += File_PutString(hFile, &szBuf[i]);
	
	return iLen;
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
