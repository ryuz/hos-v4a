/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  stringformat.h
 * @brief %jp{文字列フォーマット生成ライブラリ}
 *
 * %jp{浮動小数点などの機能制限をつけた軽量版 printf 作成を目指す}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__stringformat_h__
#define __HOS__stringformat_h__


#include <stdarg.h>


#ifdef __cplusplus
extern "C" {
#endif

int StringFormat_FormatString(char *pszBuf, int iBufSize, const char *pszFormat, ...);
int StringFormat_FormatStringV(char *pszBuf, int iBufSize, const char *pszFormat, va_list argptr);

int StringFormat_Format(int (*pfncPut)(int c, void *Param), void *Param, const char *pszFormat, ...);										/* 書式付き出力 */	
int StringFormat_FormatV(int (*pfncPut)(int c, void *Param), void *Param, const char *pszFormat, va_list argptr);							/* 書式付き出力(リスト渡し) */

int StringFormat_Nibble(int (*pfncPut)(int c, void *Param), void *Param, unsigned char n);													/* 4bitの16進数を出力 */
int StringFormat_Hexadecimal(int (*pfncPut)(int c, void *Param), void *Param, unsigned long ulNum, int iWidth, int iPadChar, int iFlag);	/* 16進数を出力 */
int StringFormat_Decimal(int (*pfncPut)(int c, void *Param), void *Param, long lNum, int iSigned, int iWidth, int iPadChar, int iFlag);		/* 10進数出力 */
int StringFormat_String(int (*pfncPut)(int c, void *Param), void *Param, const char *pszStr, int iWidth, int iFlag);						/* 文字列出力 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__stringformat_h__ */


/* end of file */
