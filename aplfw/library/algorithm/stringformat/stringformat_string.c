/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  stringformat.c
 * @brief %jp{文字列フォーマット生成ライブラリ}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "stringformat_local.h"



/* 文字列を出力 */
int StringFormat_String(int (*pfncPut)(int c, void *Param), void *Param, const char *pszStr, int iWidth, int iFlag)
{
	int	iLen = 0;
	int	iSize = 0;
	int	iPadSize;
	
	/* 最低限表示に必要なサイズを算出 */
	iSize = strlen(pszStr);
	
	/* パティングサイズ決定 */
	iPadSize = iWidth - iSize;
	
	/* 左詰属性が無ければ先にパディング */
	if ( iFlag != '-' )
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
	
	/* 文字列出力 */
	while ( iSize > 0 )
	{
		if ( pfncPut(*pszStr++, Param) <= 0 )
		{
			return iLen;
		}
		iLen++;
	
		iSize--;
	}
	
	
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
