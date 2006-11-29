/**
 *  Hyper Operating System V4 Advance configurator
 *
 * @file  parser.h
 * @brief %jp{字句解析のクラス}%en{lexical analyzer class}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __parser_h__
#define __parser_h__


#include <stdio.h>
#include "param.h"
#include "srcinf.h"



// %jp{字句解析のクラス}%en{lexical analyzer class}
class CParser
{
public:
	bool Analyze(FILE *fp, const TSourceInfo *pSrcInf);

protected:
	int  GetChar(void);			// %jp{１文字読み込む}
	void UngetChar(int c);		// %jp{１文字戻す}

	bool AnalyzePreProc(void);								// %jp{プリプロセッサ文の解析}
	bool AnalyzeParam(CParamBlock *pBlock, int cEndChar);	// %jp{パラメータ部の分解}

	bool PreProc(void);
	bool ApiProc(void);

	void ParseError(int iType, int iCode);


	FILE*       m_fpInput;		// %jp{入力ファイル}
	TSourceInfo m_SrcInf;		// %jp{ソースコード情報}

	bool		m_blPreProc;	// %jp{プリプロセッサ文処理フラグ}
	bool		m_blNewLine;	// %jp{行頭フラグ}
	int			m_iPreState;	// %jp{プリプロセッサ文処理状態}
	int			m_iApiState;	// %jp{API部処理状態}

	string      m_strPre;		// %jp{プリプロセッサ行}
	string      m_strApiName;	// %jp{API名}
	CParamBlock m_ApiParam;		// %jp{APIのパラメータ}
};


#endif	//  __parser_h__


// end of file
