// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Advance  configurator
//    INCLUDE API
//                                                                            
//                                    Copyright (C) 1998-2010 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "apiinc.h"
#include "analyze.h"
#include "readcfg.h"


// コンストラクタ
CApiInclude::CApiInclude()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParams         = 1;
}


// デストラクタ
CApiInclude::~CApiInclude()
{
}



// APIの解析
int CApiInclude::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	char szBuf[4096];
	int  iErr;
	
	// API名チェック
	if ( strcmp(pszApiName, "INCLUDE") != 0 )
	{
		return CFG_ERR_NOPROC;
	}

	// パラメーター追加
	iErr = AddParams(pszParams);
	if ( iErr != CFG_ERR_OK )
	{
		return iErr;
	}

	// 文字列の展開
	iErr = CAnalyze::DecodeText(szBuf, m_pParamPacks[m_iObjs - 1]->GetParam(0));
	if ( iErr != CFG_ERR_OK )
	{
		return iErr;
	}
	m_pParamPacks[m_iObjs - 1]->SetParam(0, szBuf);

	return CFG_ERR_OK;
}


// 文字列を展開
int CApiInclude::AutoId(void)
{
	return CFG_ERR_OK;
}


// cfgファイル定義部書き出し
void  CApiInclude::WriteCfgDef(FILE* fp)
{
	int i;

	if ( m_iObjs == 0)
	{
		return;
	}

	fputs("\n", fp);

	for ( i = 0; i < m_iObjs; i++ )
	{
		fprintf(fp, "#include %s\n", m_pParamPacks[i]->GetParam(0));
	}
}


// end of file
