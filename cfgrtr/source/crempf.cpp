// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_MPF API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "crempf.h"
#include "analyze.h"


#define CREMPF_MPFID		0
#define CREMPF_MPFATR		1
#define CREMPF_BLKCNT		2
#define CREMPF_BLKSZ		3
#define CREMPF_MPF			4



// コンストラクタ
CApiCreMpf::CApiCreMpf()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 4;		// 4パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreMpf::~CApiCreMpf()
{
}



// APIの解析
int CApiCreMpf::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_MPF") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_MPFID") == 0 )
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
void CApiCreMpf::WriteId(FILE* fp)
{
}


// cfgファイル定義部書き出し
void  CApiCreMpf::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	bool blOutput;
	int  i, j;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*   create fixed size memory-pool objects    */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	fprintf(fp, "\n\n_KERNEL_T_MPFCB _kernel_mpfcb_tbl[64];\n");
	fprintf(fp, "\n\nconst ID _kernel_max_mpfid = 64;\n");
}


// cfgファイル初期化部書き出し
void  CApiCreMpf::WriteCfgIni(FILE* fp)
{

}


// cfgファイル起動部書き出し
void  CApiCreMpf::WriteCfgStart(FILE* fp)
{

}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS                                    
// ---------------------------------------------------------------------------
