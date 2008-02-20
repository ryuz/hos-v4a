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



/* 4bitの16進数を出力 */
int StringFormat_Nibble(int (*pfncPut)(int c, void *Param), void *Param, unsigned char n)
{
	n &= 0xf;
	if ( n < 10 )
	{
		n = n + '0';
	}
	else
	{
		n = n - 10 + 'a';
	}
	return pfncPut((int)n, Param);
}


/* end of file */
