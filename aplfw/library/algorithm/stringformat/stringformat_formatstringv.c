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


typedef struct t_stringformat_formatstring_info
{
	char	*pszBuf;
	int		iBufSize;
} T_STRINGFORAMT_FORMATSTRING_INF;


static int StringFormat_OutputFormatStringV(int c, void *Param);


/* vsprintfもどき */	
int StringFormat_FormatStringV(char *pszBuf, int iBufSize, const char *pszFormat, va_list argptr)
{
	T_STRINGFORAMT_FORMATSTRING_INF	Inf;
	int 							iLen;
	
	/* バッファ情報生成 */
	Inf.pszBuf   = pszBuf;
	Inf.iBufSize = iBufSize;
	iLen = StringFormat_FormatV(StringFormat_OutputFormatStringV, (void *)&Inf, pszFormat, argptr);
	if ( iLen >= 0 && iLen < iBufSize )
	{
		pszBuf[iLen] = '\0';
	}
	
	return iLen;
}


int StringFormat_OutputFormatStringV(int c, void *Param)
{
	T_STRINGFORAMT_FORMATSTRING_INF *pInf;
	
	pInf = (T_STRINGFORAMT_FORMATSTRING_INF *)Param;
	
	if ( pInf->iBufSize <= 0 )
	{
		return 0;
	}
	
	*pInf->pszBuf++ = (char)c;
	pInf->iBufSize--;
	
	return 1;
}



/* end of file */
