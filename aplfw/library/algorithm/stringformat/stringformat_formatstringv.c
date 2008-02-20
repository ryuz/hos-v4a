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
} T_STRINGFORAMT_FORMATSTRING_INFO;


static int StringFormat_OutputFormatStringV(int c, void *Param);


/* vsprintfもどき */	
int StringFormat_FormatStringV(char *pszBuf, int iBufSize, const char *pszFormat, va_list argptr)
{
	T_STRINGFORAMT_FORMATSTRING_INFO Info;
	
	/* バッファ情報生成 */
	Info.pszBuf   = pszBuf;
	Info.iBufSize = iBufSize;

	return StringFormat_FormatV(StringFormat_OutputFormatStringV, (void *)&Info, pszFormat, argptr);
}


int StringFormat_OutputFormatStringV(int c, void *Param)
{
	T_STRINGFORAMT_FORMATSTRING_INFO *pInfo;
	
	pInfo = (T_STRINGFORAMT_FORMATSTRING_INFO *)Param;
	
	if ( pInfo->iBufSize <= 0 )
	{
		return 0;
	}
	
	*pInfo->pszBuf++ = (char)c;
	pInfo->iBufSize--;
	
	return 1;
}



/* end of file */
