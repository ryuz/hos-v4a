/**
 *  Hyper Operating System V4 Advance configurator
 *
 * @file  parser.cpp
 * @brief %jp{字句解析のクラス}%en{lexical analyzer class}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <ctype.h>
#include "parser.h"
#include "error.h"
#include "debug.h"



// API部解析状態
#define PARSER_STATE_API_START					2000	// API探索中
#define PARSER_STATE_API_END					2001	// APIの終結探索
#define PARSER_STATE_API_NAME					2002	// API名部分解析中
#define PARSER_STATE_API_S_PARAM				2003	// 
#define PARSER_STATE_API_PARAM					2004	// 
#define PARSER_STATE_API_PARAM_STR				2005	// パラメータ内の文字列部読み込み中
#define PARSER_STATE_API_PARAM_STR_ESC			2006	// パラメータ内の文字列部読み込み中で且つESC
#define PARSER_STATE_API_PARAM_CHAR				2007	// パラメータ内の文字列部読み込み中
#define PARSER_STATE_API_PARAM_CHAR_ESC			2008	// パラメータ内の文字列部読み込み中で且つESC
#define PARSER_STATE_API_ERR_0					3000	// エラー発生 次の空白文字まで読み飛ばし
#define PARSER_STATE_API_ERR_1					3001	// エラー発生 API末尾の ";" まで読み飛ばし中

// 字句解析
bool CParser::Analyze(FILE *fp, const TSourceInfo *pSrcInf)
{
	int  c;

	// %jp{初期設定}
	m_fpInput   = fp;
	m_SrcInf    = *pSrcInf;
	m_blPreProc = false;
	m_blNewLine = true;
	m_iApiState = PARSER_STATE_API_START;


	while ( (c = GetChar()) != EOF )
	{
		if ( m_blPreProc )	// プリプロセッサ行の処理
		{
			AnalyzePreProc();
			continue;
		}

		// 通常のAPIの処理
		switch ( m_iApiState )
		{
		case PARSER_STATE_API_START:	// API探索中
			if ( isspace(c) )
			{
				// 空白文字ならスルー
			}
			else if ( iswalpha(c) || c == '_' )	// 有意文字ならAPI名開始とみなす
			{
				m_strApiName = c;
				m_iApiState = PARSER_STATE_API_NAME;
			}
			else
			{
				ParseError(ERRTYPE_ERROR, ERROR_SYNTAX); // エラー処理
				m_iApiState = PARSER_STATE_API_ERR_0;
			}
			break;

		case PARSER_STATE_API_NAME:		// API名読み込み中
			if ( isalnum(c) || c == '_' )
			{
				m_strApiName += c;
			}
			else if ( c == '(' )		// '(' ならパラメータ部の解析に移行
			{
				if ( AnalyzeParam(&m_ApiParam, ')') )
				{
					m_iApiState = PARSER_STATE_API_END;
				}
				else
				{
					m_iApiState = PARSER_STATE_API_ERR_1;
				}
			}
			else if ( isspace(c) )		// 空白文字ならパラメータ部の始まりを探す
			{
				m_iApiState = PARSER_STATE_API_S_PARAM;
			}
			else
			{
				ParseError(ERRTYPE_ERROR, ERROR_SYNTAX); // エラー処理
				m_iApiState = PARSER_STATE_API_ERR_0;
			}
			break;

		case PARSER_STATE_API_S_PARAM:
			if ( c == '(' )		// '(' ならパラメータ部の解析に移行
			{
				if ( AnalyzeParam(&m_ApiParam, ')') )
				{
					m_iApiState = PARSER_STATE_API_END;
				}
				else
				{
					m_iApiState = PARSER_STATE_API_ERR_1;
				}
			}
			if ( isspace(c) )	// 空白文字なら探索続行
			{
			}
			else
			{
				ParseError(ERRTYPE_ERROR, ERROR_SYNTAX); // エラー処理
				m_iApiState = PARSER_STATE_API_ERR_0;
			}
			break;

		case PARSER_STATE_API_END:
			if ( c == ';' )
			{
				ApiProc();
				m_iApiState = PARSER_STATE_API_START;
			}
			else if ( isspace(c) )
			{
			}
			else
			{
				ParseError(ERRTYPE_ERROR, ERROR_SYNTAX);	// エラー処理
				m_iApiState = PARSER_STATE_API_ERR_1;
			}
			break;

		case PARSER_STATE_API_ERR_0:	// 適当な区切りまで読み飛ばして継続
			if ( c == ';' || isspace(c) )
			{
				m_iApiState = PARSER_STATE_API_START;
			}
			break;

		case PARSER_STATE_API_ERR_1:	// ;まで読み飛ばしてから継続
			if ( c == ';' )
			{
				m_iApiState = PARSER_STATE_API_START;
			}
			break;
		}
	}
	
	// 解析途中でのEOFなら致命エラー
	if ( m_iApiState != PARSER_STATE_API_START )
	{
		ParseError(ERRTYPE_FATAL, FATAL_EOF);		// エラー処理
		return false;
	}
	
	return true;
}



// プリプロセッサ行の状態
#define PARSER_STATE_PRE_NORMAL					1000	// プリプロセッサ行読み込み中
#define PARSER_STATE_PRE_ESC					1001	// プリプロセッサ行読み込み中でエスケープ文字あり

// プリプロセッサ行の解析
bool CParser::AnalyzePreProc(void)
{
	int c;

	m_strPre    = '#';
	m_iPreState = PARSER_STATE_PRE_NORMAL;

	while ( (c = GetChar()) != EOF )
	{
		switch ( m_iPreState )
		{
		case PARSER_STATE_PRE_NORMAL:	// 通常
			if ( c == '\n' )		// 改行が来たらそこまでで１行として処理
			{
				PreProc();
				m_strPre    = "";
				m_blPreProc = false;
				return true;
			}
			else if ( c == '\\' )	// エスケープ文字
			{
				m_iPreState = PARSER_STATE_PRE_ESC;
			}
			else	// それ以外なら
			{
				m_strPre += c;	// 普通に読み込む
			}
			break;

		case PARSER_STATE_PRE_ESC:		// エスケープ文字の次の文字
			if ( c == '\n' )	// 改行なら空白と置換する
			{
				m_strPre += ' ';
				m_iPreState = PARSER_STATE_PRE_NORMAL;
			}
			else if ( c == '\\' )	// この場合はエスケープ続行(いいのかな？)
			{
				m_strPre += '\\';
			}
			else
			{
				m_strPre += '\\';
				m_strPre += c;
				m_iPreState = PARSER_STATE_PRE_NORMAL;
			}
			break;
		}
	}

	return false;
}



#define PARSER_STATE_PARAM_START			40000
#define PARSER_STATE_PARAM_NORMAL			40001
#define PARSER_STATE_PARAM_STR				40002
#define PARSER_STATE_PARAM_STR_ESC			40003
#define PARSER_STATE_PARAM_CHR				40004
#define PARSER_STATE_PARAM_CHR_ESC			40005

// APIパラメータ部の解析
bool CParser::AnalyzeParam(CParamBlock *pParam, int cEndChar)
{
	string strParam;
	int iParenNest = 0;
	int iState = PARSER_STATE_PARAM_START;
	int c;

	while ( (c = GetChar()) != EOF )
	{
		if ( m_blPreProc )	// プリプロセッサ行の処理
		{
			AnalyzePreProc();
			continue;
		}

		switch ( iState )
		{
		case PARSER_STATE_PARAM_START:
			if ( c == '{' )
			{
				AnalyzeParam(pParam->AddParamBlock(), '}');
			}
			else if ( c == ',' || c == cEndChar )
			{
	//			ParseError(ERRTYPE_WARNING, WARNING_PARAM_EMPTY);	// 警告(パラメータが空)
				
				pParam->AddString(strParam.c_str());
				if ( c == cEndChar )
				{
					return true;
				}
				strParam = "";
			}
			else if ( isspace(c) )	// 空白文字なら
			{
				// そのまま
			}
			else if ( c == ';' )
			{
				ParseError(ERRTYPE_ERROR, ERROR_SEMICOLON);			// エラーー
				UngetChar(c);
				return false;
			}
			else
			{
				UngetChar(c);
				iState = PARSER_STATE_PARAM_NORMAL;
			}
			break;

		case PARSER_STATE_PARAM_NORMAL:
			if ( (c == ',' || c == cEndChar) && iParenNest == 0 )	// パラメータ終端検出
			{
				pParam->AddString(strParam.c_str());
				if ( c == cEndChar )
				{
					return true;
				}
				strParam = "";
				iState =  PARSER_STATE_PARAM_START;
			}
			else if ( c == '\"' )	// 文字列の始まり
			{
				strParam += c;
				iState = PARSER_STATE_PARAM_STR;
			}
			else if ( c == '\'' )	// 文字の始まり
			{
				strParam += c;
				iState = PARSER_STATE_PARAM_CHR;
			}
			else if ( c == '(' )
			{
				strParam += c;
				iParenNest++;
			}
			else if ( c == ')' )
			{
				strParam += c;
				if ( iParenNest <= 0 )
				{
					ParseError(ERRTYPE_ERROR, ERROR_PAREN);		// エラー
					return false;
				}
				iParenNest--;
			}
			else if ( c == ';' )
			{
				ParseError(ERRTYPE_ERROR, ERROR_SEMICOLON);		// エラーー
				UngetChar(c);
				return false;
			}
			else
			{
				strParam += c;
			}
			break;

		case PARSER_STATE_PARAM_STR:
			strParam += c;
			if ( c == '\"' )
			{
				iState = PARSER_STATE_PARAM_NORMAL;
			}
			else if ( c == '\\' )
			{
				iState = PARSER_STATE_PARAM_STR_ESC;
			}
			break;

		case PARSER_STATE_PARAM_STR_ESC:
			strParam += c;
			iState = PARSER_STATE_PARAM_STR;
			break;

		case PARSER_STATE_PARAM_CHR:
			strParam += c;
			if ( c == '\'' )
			{
				iState = PARSER_STATE_PARAM_NORMAL;
			}
			else if ( c == '\\' )
			{
				iState = PARSER_STATE_PARAM_CHR_ESC;
			}
			break;

		case PARSER_STATE_PARAM_CHR_ESC:
			strParam += c;
			iState = PARSER_STATE_PARAM_CHR;
			break;
		}
	}

	// エラー
	ParseError(ERRTYPE_FATAL, FATAL_EOF);		// エラーー
	return false;
}


// プリプロセッサ行の処理
bool CParser::PreProc(void)
{
	printf("PRI : %s\n", m_strPre.c_str());
	return true;
}


bool CParser::ApiProc(void)
{
	printf("API : %s\n", m_strApiName.c_str());
	CDebug::PrintParam(&m_ApiParam, 0);
	m_ApiParam.Clear();
	return true;
}


// 1文字読む
int CParser::GetChar(void)
{
	int c;

	while ( (c = fgetc(m_fpInput)) == '\r' )
		;

	if ( c == '\n' )
	{
		m_SrcInf.iLineNum++;
		m_SrcInf.iColumnNum = 0;
	}
	else
	{
		m_SrcInf.iColumnNum++;
	}

	if ( c == '\n' )		// 改行文字なら
	{
		m_blNewLine = true;		// 行頭フラグON
	}
	else if ( isspace(c) )	// 空白文字なら
	{
		// 何もしない
	}
	else if ( c == '#' )	// 行頭に#がきたらプリプロセッサ行判定
	{
		if ( m_blNewLine )
		{
			m_blPreProc = true;
			m_blNewLine = false;
		}
	}
	else	// 通常の文字なら
	{
		m_blNewLine = false;	// 行頭フラグクリア
	}

	return c;
}


// 1文字戻す
void CParser::UngetChar(int c)
{
	ungetc(c, m_fpInput);
	if ( c == '\n' )
	{
		m_SrcInf.iLineNum--;
	}
	else
	{
		m_SrcInf.iColumnNum--;
	}
}



void CParser::ParseError(int iType, int iCode)
{
	printf("err\n");
#if 0
	const char *pszMsg;
	
	pszMsg = GetErrMessage(iType, iCode);
	
	switch ( iType )
	{
	case PARSER_ERRTYPE_WARNING:
		fprintf(stderr, "%s(%d) Warning(%d): %s\n", m_strFileName.c_str(), m_iLineNum, iCode, pszMsg);
		return;
	
	case PARSER_ERRTYPE_ERROR:
		fprintf(stderr, "%s(%d) Error(%d): %s\n", m_strFileName.c_str(), m_iLineNum, iCode, pszMsg);
		return;

	case PARSER_ERRTYPE_FATAL:
		fprintf(stderr, "%s(%d) Fatal(%d): %s\n", m_strFileName.c_str(), m_iLineNum, iCode, pszMsg);
		exit(2);
		return;
	}
#endif
}
