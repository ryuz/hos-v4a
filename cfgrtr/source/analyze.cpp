/**
 *  Hyper Operating System V4 Advance Configurator
 *
 * @file  analyze.cpp
 * @brief  %jp{構文解析クラス}%en{lexer cless}
 *
 * Copyright (C) 1998-2014 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "defercd.h"
#include "analyze.h"



// ステートメントをAPI名とパラメーターに分割
int CAnalyze::SplitState(char* pszApiName, char* pszParams, const char *pszState)
{
	int iErr;

	// コマンド名の切り出し
	while ( *pszState != '(' )
	{
		if ( *pszState == '\0' )
		{
			return CFG_ERR_SYNTAX;
		}
		*pszApiName++ = *pszState++;
	}
	*pszApiName = '\0';
	pszState++;

	// パラメーター部の切り出し
	iErr = SearchChar(pszParams, pszState, ')');
	if ( iErr != CFG_ERR_OK )
	{
		return iErr;
	}

	// 後続チェック
	if ( *pszState != '\0' )
	{
		return CFG_ERR_SEMICOLON;
	}

	return CFG_ERR_OK;
}


// 特定文字のまでの切り出し
int CAnalyze::SearchChar(char* pszBuf, const char* &pszText, char c)
{
	char cDelimiter = 0;
	bool blText = false;
	bool blEsc  = false;
	int  iErr;

	for ( ; ; )
	{
		// 終端チェック
		if ( *pszText == '\0' )
		{
			iErr = CFG_ERR_SYNTAX;
			break;
		}

		// 文字チェック
		if ( *pszText == c )
		{
			pszText++;
			iErr = CFG_ERR_OK;
			break;
		}

		// '\' の次の文字は無条件にエスケープ
		if ( blEsc )
		{
			*pszBuf++ = *pszText++;
			blEsc = false;
			continue;
		}
		blEsc = false;

		// '\' チェック
		if ( *pszBuf == '\\' )
		{
			*pszBuf++ = *pszText++;
			blEsc = true;
			continue;
		}

		// 文字列開始チェック
		if ( (!blText && *pszText == '\"') || *pszText == '\'' )
		{
			cDelimiter = *pszText;
			*pszBuf++ = *pszText++;
			blText = true;
			continue;
		}

		// 文字列内部
		if ( blText )
		{
			if ( *pszText == cDelimiter )
			{
				*pszBuf++ = *pszText++;
				blText = false;
			}
			else
			{
				*pszBuf++ = *pszText++;
			}
			continue;
		}

		// '{' チェック
		if ( *pszText == '{' )
		{
			*pszBuf++ = *pszText++;
			iErr = SearchChar(pszBuf, pszText, '}');
			if ( iErr != CFG_ERR_OK )
			{
				iErr = CFG_ERR_BRACE;
			}
			pszBuf  += strlen(pszBuf);
			*pszBuf++ = '}';
			continue;
		}

		// '(' チェック
		if ( *pszText == '(' )
		{
			*pszBuf++ = *pszText++;
			iErr = SearchChar(pszBuf, pszText, ')');
			if ( iErr != CFG_ERR_OK )
			{
				iErr = CFG_ERR_PAREN;
			}
			pszBuf  += strlen(pszBuf);
			*pszBuf++ = ')';
			continue;
		}

		*pszBuf++ = *pszText++;
	}

	*pszBuf = '\0';

	return iErr;
}


// パラメーターの切り出し
int CAnalyze::GetParameter(char* pszBuf, const char* &pszText)
{
	int iErr;

	// コンマまで切り出す
	iErr = SearchChar(pszBuf, pszText, ',');
	if ( iErr == CFG_ERR_SYNTAX )
	{
		// 括弧対応OKで終端ならコンマが見つからなくても可
		iErr = CFG_ERR_OK;
	}

	return iErr;
}


// 文字列定数を展開する
int CAnalyze::DecodeText(char *pszBuf, const char* pszText)
{
	bool blEsc = false;

	if ( *pszText++ != '\"') 
	{
		return CFG_ERR_TEXT;
	}

	for ( ; ; )
	{
		if ( *pszText == '\0' )
		{
			return CFG_ERR_TEXT;
		}

		// 前の文字が '\' なら読み飛ばし
		if ( blEsc )
		{
			*pszBuf++ = *pszText++;
			blEsc = false;
			continue;
		}

		// エスケープ文字チェック
		if ( *pszText == '\\' )
		{
			pszText++;
			blEsc = true;
			continue;
		}

		// 終端チェック
		if ( *pszText == '\"' )
		{
			pszText++;
			break;
		}

		*pszBuf++ = *pszText++;
	}

	// 完結していなければエラー
	if ( *pszText != '\0' )
	{
			return CFG_ERR_TEXT;
	}

	*pszBuf = '\0';

	return CFG_ERR_OK;
}


// 前後の空白を削除する
void CAnalyze::SpaceCut(char* pszText)
{
	char *pszTmp;
	int  i = 0;

	pszTmp = pszText;

	// 先頭の空白を読み飛ばす
	while ( *pszTmp == ' ' )
	{
		pszTmp++;
	}

	// コピー
	while ( *pszTmp != '\0' )
	{
		pszText[i++] = *pszTmp++;
	}

	// 末尾の空白を削除
	while ( i > 0 && pszText[i - 1] == ' ' )
	{
		i--;
	}

	pszText[i] = '\0';
}


// end of file
