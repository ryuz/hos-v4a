// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    データ読み込みクラス                                                    
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "defercd.h"
#include "read.h"


// コンストラクタ
CRead::CRead(FILE *fp, const char *name)
{
	m_fpRead    = fp;
	m_iPhysicalLineNum = m_iLogicalLineNum = 1;
	m_blLineTop = true;
	strncpy(m_szLogicalInputFile, name, READ_MAX_PATH - 1);
	m_szLogicalInputFile[READ_MAX_PATH - 1] = '\0';
}


// デストラクタ
CRead::~CRead()
{
}


// １ステート読み込み
int CRead::ReadState(char *szState)
{
	bool blEsc   = false;
	bool blSpace = true;	// true で始めて先頭の空白を読み飛ばす
	int  iCount = 0;
	int  iErr;
	int  c;

	for ( ; ; )
	{
		// １文字読み込み
		if ( (c = fgetc(m_fpRead)) == EOF )
		{
			if ( blEsc || iCount != 0 )
			{
				iErr = CFG_ERR_EOF;	// 予期せぬEOF
			}
			else
			{
				iErr = CFG_ERR_COMPLETE;	// 完了
			}
			break;
		}

		// サイズチェック
		if ( iCount >= READ_MAX_STATE - 1 )
		{
			iErr = CFG_ERR_STATE_LEN;
			break;
		}

		// 行頭が # ならスキップ
		if ( m_blLineTop && c == '#' )
		{
                       iErr = SkipPreProcessorLine(szState, iCount);
			if ( iErr != CFG_ERR_OK )
			{
				break;
			}
			continue;
		}

		// 改行文字の処理
		if ( c == '\n' )
		{
			m_iPhysicalLineNum++;
			m_iLogicalLineNum++;
			m_blLineTop = true;
		}
		else
		{
			m_blLineTop = false;
		}

		// 空白文字のスキップ
		if ( isspace(c) || c == '\n' )
		{
			if ( !blSpace )
			{
				szState[iCount++] = ' ';
				blSpace = true;
			}
			continue;
		}
		blSpace = false;

		// 文字列の処理
		if ( c == '\"' || c == '\'' )
		{
			szState[iCount++] = c;
			iErr = ReadString(c, szState, iCount);
			if ( iErr != CFG_ERR_OK )
			{
				break;
			}
			continue;
		}

		// ステート完了文字なら
		if ( c == ';' )
		{
			iErr = CFG_ERR_OK;
			break;
		}

		// 文字の読み込み
		szState[iCount++] = c;
	}

	// 末尾の空白文字削除
	if ( iCount > 0 && szState[iCount - 1] == ' ' )
	{
		iCount--;
	}

	szState[iCount] = '\0';

	return iErr;
}


// プリプロセッサラインのスキップ
int CRead::SkipPreProcessorLine(char* szText, int iCountOrg)
{
	int  c;
	int iCount = iCountOrg;
	long tmpLineNum;
	char *p1, *p2;

	for ( ; ; )
	{
		// １文字読み込み
		if ( (c = fgetc(m_fpRead)) == EOF )
		{
			return CFG_ERR_OK;
		}

		// サイズチェック
		if ( iCount >= READ_MAX_STATE - 1 )
		{
			return CFG_ERR_STATE_LEN;
		}

		// 行末のチェック
		if ( c == '\n' )
		{
			m_iPhysicalLineNum++;
			m_iLogicalLineNum++;

			szText[iCount] = '\0';

			// #line 123 "filename"
			// # 123 "filename"
			// の形式のどちらでも受け付ける
			if (strncmp(&szText[iCountOrg], "line", 4) == 0)
				iCountOrg += 4;

			// #line123
			// #12
			// などを排除
			if (!isspace(szText[iCountOrg]))
				return CFG_ERR_OK;

			// 行番号読み込み
			tmpLineNum = strtol(&szText[iCountOrg], &p1, 10);
			if (p1 == &szText[iCountOrg])
				return CFG_ERR_OK;

			// # 123a
			// など行番号の後ろに余分なものがついている場合を排除
			if (!isspace(*p1) && *p1 != '\0')
				return CFG_ERR_OK;

			// 読み込んだ行番号を反映
			m_iLogicalLineNum = tmpLineNum;

			// ファイル名を探す
			while (isspace(*p1))
				p1++;
			if (*p1 != '\"')
				return CFG_ERR_OK;
			p1++;
			p2 = strchr(p1, '\"');
			if (p2 == NULL)
				return CFG_ERR_OK;
			*p2 = '\0';

			// ファイル名を反映
			strncpy(m_szLogicalInputFile, p1, READ_MAX_PATH - 1);
			m_szLogicalInputFile[READ_MAX_PATH - 1] = '\0';

			return CFG_ERR_OK;
		}

		// 文字の読み込み
		szText[iCount++] = c;
	}
}


// 文字列読み込み
int CRead::ReadString(int cDelimiter, char* szText, int& iCount)
{
	bool blEsc  = false;
	int c;

	for ( ; ; )
	{
		// １文字読み込み
		if ( (c = fgetc(m_fpRead)) == EOF )
		{
			return CFG_ERR_EOF;	// 予期せぬEOF
		}

		// サイズチェック
		if ( iCount >= READ_MAX_STATE - 1 )
		{
			return CFG_ERR_STATE_LEN;
		}

		// 改行チェック
		if ( c == '\n' )
		{
			return CFG_ERR_CR;		// 不正な改行
		}

		// 文字の設定
		szText[iCount++] = c;

		// \ の次は無条件にスキップ
		if ( blEsc )
		{
			blEsc  = false;
			continue;
		}

		// \ のチェック
		if ( c == '\\' )
		{
			blEsc  = true;
			continue;
		}

		blEsc  = false;

		// デリミタ文字なら完了
		if ( c == cDelimiter )
		{
			return CFG_ERR_OK;
		}
	}
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
