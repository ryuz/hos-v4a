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



/* 16進数を出力 */
int StringFormat_Hexadecimal(int (*pfncPut)(int c, void *Param), void *Param, unsigned long ulNum, int iWidth, int iPadChar, int iFlag)
{
	unsigned long	ulTmp;
	int				iLen = 0;
	int				iSize = 0;
	int				iPadSize;
	
	
	/* 最低限表示に必要なサイズを算出 */
	ulTmp = ulNum;
	do
	{
		iSize++;
		ulTmp >>= 4;
	} while ( ulTmp != 0 );
	
	/* パティングサイズ決定 */
	iPadSize = iWidth - iSize;
	
	/* 左詰属性が無ければ先にパディング */
	if ( iFlag != '-' )
	{
		while ( iPadSize > 0 )
		{
			if ( pfncPut(iPadChar, Param) <= 0 )
			{
				return iLen;
			}
			iLen++;

			iPadSize--;
		}
	}
	
	/* 上位桁から順に出力 */
	iSize = (iSize - 1) * 4;
	do
	{
		if ( StringFormat_Nibble(pfncPut, Param, (unsigned char)(ulNum >> iSize)) <= 0 )
		{
			return iLen;
		}
		iLen++;
		
		iSize -= 4;
	} while ( iSize >= 0 );
	
	
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
