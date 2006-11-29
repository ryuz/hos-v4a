

#ifndef __parser_h__
#define __parser_h__

#include <stdio.h>
#include "param.h"
#include "srcinf.h"


// レキシカルアナライザなクラス
class CParser
{
public:
	bool Analyze(FILE *fp);

protected:
	int   GetChar(void);
	void  UngetChar(int c);

	bool AnalyzePreProc(void);
	bool AnalyzeParam(CParamBlock *pBlock, int cEndChar);

	bool PreProc(void);
	bool ApiProc(void);

	void ParseError(int iType, int iCode);


	FILE *m_fpInput;			// 入力ファイル

	TSourceInfo m_SrcInf;

	bool m_blPreProc;
	bool m_blNewLine;
	int  m_iPreState;
	int  m_iApiState;


	string      m_strPre;		// プリプロセッサ行
	string      m_strParam;		// API名
	string      m_strApiName;	// API名
	CParamBlock m_ApiParam;		// APIのパラメータ
};

#endif	//  __parser_h__