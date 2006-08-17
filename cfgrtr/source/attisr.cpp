// ---------------------------------------------------------------------------
//  Hyper Operating System V4a  コンフィギュレーター                           
//    ATT_ISR API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "attisr.h"
#include "analyze.h"
#include "readcfg.h"


#define ATTISR_ISRATR		0
#define ATTISR_EXINF		1
#define ATTISR_INTNO		2
#define ATTISR_ISR			3


// コンストラクタ
CApiAttIsr::CApiAttIsr()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 4;		// 4つのパラメーターブロック
	m_iParams         = 1;
}

// デストラクタ
CApiAttIsr::~CApiAttIsr()
{
}


// 自動ID番号割り当て
int CApiAttIsr::AutoId(void)
{
	return CFG_ERR_OK;
}


// APIの解析
int CApiAttIsr::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "ATT_ISR") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_ISRID") == 0 )
	{
		if ( m_iMaxId > 0 )
		{
			return CFG_ERR_MULTIDEF;
		}
		
		int iId;
		if ( (iId = atoi(pszParams)) <= 0 )
		{
			return CFG_ERR_PARAM;
		}
		
		m_iMaxId = iId;
		
		return CFG_ERR_OK;
	}

	return CFG_ERR_NOPROC;
}


// cfgファイル定義部書き出し
void  CApiAttIsr::WriteCfgDef(FILE* fp)
{
	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        interrupt control objects           */\n"
		"/* ------------------------------------------ */\n"
		, fp);
	
	// 割込み管理テーブル生成
	if ( _KERNEL_IRCATR_TMAX_INHNO - _KERNEL_IRCATR_TMIN_INHNO + 1 > 0 )
	{
		fprintf(
			fp,
			"\n"
			"_KERNEL_T_INTINF _kernel_int_tbl[%d];\n\n",
			_KERNEL_IRCATR_TMAX_INHNO - _KERNEL_IRCATR_TMIN_INHNO + 1);
	}

	if ( m_iMaxId > 0 )
	{
		fprintf(
			fp,
			"\n"
			"_KERNEL_T_ISRCB *_kernel_isrcb_tbl[%d];\n",
			m_iMaxId);
	}

	fprintf(
			fp,
		"const ID        _kernel_max_isrid = %d;\n",
		m_iMaxId);
}


// cfgファイル初期化部書き出し
void  CApiAttIsr::WriteCfgIni(FILE* fp)
{

}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
