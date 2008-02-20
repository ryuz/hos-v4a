/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  stringformat.c
 * @brief %jp{文字列フォーマット生成ライブラリ}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "stringformat_local.h"



#define STRINGFORMAT_FORMAT_NORMAL		0
#define STRINGFORMAT_FORMAT_ESC			1



/* 書式付き出力(リスト渡し) */
int StringFormat_FormatV(int (*pfncPut)(int c, void *Param), void *Param, const char *pszFormat, va_list argptr)
{
	int	iState = STRINGFORMAT_FORMAT_NORMAL;
	int	iLong;
	int	iPadChar;
	int	iWidth;
	int iFlag;
	int iTmpLen;
	int	iLen = 0;
	int	c;
	
	while ( (c = *pszFormat++) != '\0' )
	{
		switch ( iState )
		{
		case STRINGFORMAT_FORMAT_NORMAL:
			if ( c == '%' )
			{
				iLong     = 0;
				iWidth    = 0;
				iFlag     = ' ';
				iPadChar  = ' ';
				iState    = STRINGFORMAT_FORMAT_ESC;
			}
			else
			{
				/* 1文字出力 */
				if ( pfncPut(c, Param) <= 0 )
				{
					return iLen;
				}
				iLen++;
			}
			break;

		case STRINGFORMAT_FORMAT_ESC:
			if ( c == '%' )
			{
				/* 1文字出力 */
				if ( pfncPut(c, Param) <= 0 )
				{
					return iLen;
				}
				iLen++;
				iState = STRINGFORMAT_FORMAT_NORMAL;
			}
			else if ( c == '+' || c == '-' )
			{
				iFlag = c;	
			}
			else if ( c >= '0' && c <= '9' )
			{
				/* 表示読込み */
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
				
				/* 引数取り出し */
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
					/* 符号付き10進数出力 */
					iTmpLen = StringFormat_Decimal(pfncPut, Param, lNum, 1, iWidth, iPadChar, iFlag);
					if ( iTmpLen <= 0 )
					{
						return iLen;
					}
					iLen += iTmpLen;
				}
				else
				{
					/* 16進数出力 */
					iTmpLen = StringFormat_Hexadecimal(pfncPut, Param, lNum, iWidth, iPadChar, iFlag);
					if ( iTmpLen <= 0 )
					{
						return iLen;
					}
					iLen += iTmpLen;
				}
				
				iState = STRINGFORMAT_FORMAT_NORMAL;
			}
			else if ( c == 'u' )
			{
				unsigned long ulNum;
				
				
				/* 引数取り出し */
				if ( iLong )
				{
					ulNum = va_arg(argptr, unsigned long);
				}
				else
				{
					ulNum = va_arg(argptr, unsigned int);
				}

				/* 符号無し10進数出力 */
				iTmpLen = StringFormat_Decimal(pfncPut, Param, (long)ulNum, 0, iWidth, iPadChar, iFlag);
				if ( iTmpLen <= 0 )
				{
					return iLen;
				}
				iLen += iTmpLen;
				
				iState = STRINGFORMAT_FORMAT_NORMAL;				
			}
			else if ( c == 's' )
			{
				const char *pszStr;
				
				/* 引数取り出し */
				pszStr  = va_arg(argptr, const char *);
				
				/* 文字列出力 */
				iTmpLen = StringFormat_String(pfncPut, Param, pszStr, iWidth, iFlag);
				if ( iTmpLen <= 0 )
				{
					return iLen;
				}
				iLen += iTmpLen;
				
				
				iState  = STRINGFORMAT_FORMAT_NORMAL;
			}
			else
			{
				/* 1文字出力 */
				if ( pfncPut(c, Param) <= 0 )
				{
					return iLen;
				}
				iLen++;
				iState = STRINGFORMAT_FORMAT_NORMAL;
			}
			break;
		}
	}

	return iLen;
}



/* end of file */
