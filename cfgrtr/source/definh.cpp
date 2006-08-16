// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    DEF_INH API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "definh.h"
#include "analyze.h"
#include "readcfg.h"


#define ATTINI_INIATR		0
#define ATTINI_EXINF		1
#define ATTINI_INIRTN		2


// コンストラクタ
CApiDefInh::CApiDefInh()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 2;		// 2個のパラメーターブロック
	m_iParams         = 2;
}


// デストラクタ
CApiDefInh::~CApiDefInh()
{
}



// APIの解析
int CApiDefInh::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "DEF_INH") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// 文字列を展開
int CApiDefInh::AutoId(void)
{
	return CFG_ERR_OK;
}

// cfgファイル定義部書き出し
void  CApiDefInh::WriteCfgDef(FILE* fp)
{
	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        define interrupt handler            */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	fprintf(fp,
		"\n\n"
#if !_KERNEL_SPT_DEF_INH
		"const "
#endif
		"_KERNEL_T_INHINF _kernel_inh_tbl[%d];\n\n",
		KERNEL_TMAX_INH_INHNO - KERNEL_TMIN_INH_INHNO + 1);

}


// cfgファイル定義部書き出し
void  CApiDefInh::WriteCfgStart(FILE* fp)
{
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
