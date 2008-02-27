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



/* 符号付付き10進数出力 */
int StringFormat_Decimal(int (*pfncPut)(int c, void *Param), void *Param, long lNum, int iSigned, int iWidth, int iPadChar, int iFlag)
{
	unsigned long	ulNum;
	char			szBuf[10];
	int  			iLen = 0;
	int  			iSignChar;
	int				iPadSize;
	int  			iSign;
	int  			iSize;
	
	/* 符号チェック */
	if ( lNum < 0 && iSigned )
	{
		ulNum = -lNum;
		iSign = 1;
		iSignChar = '-';
	}
	else
	{
		ulNum = lNum;
		iSign = (iFlag == '+') ? 1 : 0;
		iSignChar = '+';
	}
	
	/* 文字列変換 */
	iSize = 0;
	do
	{
		szBuf[iSize++] = (char)((ulNum % 10) + '0');
		ulNum         /= 10;
	} while ( ulNum != 0 );
	
	/* パティングサイズ決定 */
	iPadSize = iWidth - iSize - iSign;
	
	/* 左詰属性が無ければ先にパディング */
	if ( iFlag != '-' )
	{
		while ( iWidth > iSize + iSign )
		{
			iWidth--;
			if ( pfncPut(iPadChar, Param) <= 0 )
			{
				return iLen;
			}
			iLen++;
		}
	}
	
	/* 符号出力 */
	if ( iSign )
	{
		if ( pfncPut(iSignChar, Param) <= 0 )
		{
			return iLen;
		}
		iLen++;
	}
	
	/* 数値出力 */
	do
	{
		 if ( pfncPut(szBuf[--iSize], Param) <= 0 )
		{
			return iLen;
		}
		iLen++;
	} while ( iSize > 0);
		
	/* 左詰属性なら後ろをパディング */
	if ( iFlag == '-' )
	{
		while ( iPadSize > 0 )
		{
			if ( pfncPut(' ', Param) <= 0 )
			{
				return iLen;
			}
			iLen++;

			iPadSize--;
		}
	}
	
	return iLen;
}


/* end of file */
