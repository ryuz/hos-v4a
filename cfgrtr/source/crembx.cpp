// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_MBX API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "crembx.h"
#include "analyze.h"


#define CREMBX_MBXID		0
#define CREMBX_MBXATR		1
#define CREMBX_MAXPRI		2
#define CREMBX_MPRIHD		3



// コンストラクタ
CApiCreMbx::CApiCreMbx()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 3;		// 3パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreMbx::~CApiCreMbx()
{
}



// APIの解析
int CApiCreMbx::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_MBX") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_MBXID") == 0 )
	{
		int iId;

		if ( m_iMaxId > 0 )
		{
			return CFG_ERR_MULTIDEF;
		}

		if ( (iId = atoi(pszParams)) <= 0 )
		{
			return CFG_ERR_PARAM;
		}

		m_iMaxId = iId;

		return CFG_ERR_OK;
	}

	return CFG_ERR_NOPROC;
}


// ID 定義ファイル書き出し
void CApiCreMbx::WriteId(FILE* fp)
{

}


// cfgファイル定義部書き出し
void  CApiCreMbx::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	bool blOutput;
	int  i, j;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*         create mailbox objects             */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	fprintf(fp, "\n\n_KERNEL_T_MBXCB _kernel_mbxcb_tbl[64];\n");
	fprintf(fp, "\n\nconst ID _kernel_max_mbxid = 64;\n");
}


// cfgファイル初期化部書き出し
void  CApiCreMbx::WriteCfgIni(FILE* fp)
{

}


// cfgファイル起動部書き出し
void  CApiCreMbx::WriteCfgStart(FILE* fp)
{

}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS                                    
// ---------------------------------------------------------------------------
