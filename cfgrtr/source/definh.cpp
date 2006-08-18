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


#define DEFINH_INHNO		0
#define DEFINH_INHATR		1
#define DEFINH_INTHDR		2


// %jp{コンストラクタ}
CApiDefInh::CApiDefInh()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 2;		// 2個のパラメーターブロック
	m_iParams         = 2;
}


// %jp{デストラクタ}
CApiDefInh::~CApiDefInh()
{
}


// %jp{APIの解析}
int CApiDefInh::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "DEF_INH") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// %jp{文字列を展開}
int CApiDefInh::AutoId(void)
{
	return CFG_ERR_OK;
}


// %jp{cfgファイル定義部書き出し}
void  CApiDefInh::WriteCfgDef(FILE* fp)
{
	int i, j;

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
		"_KERNEL_T_INHINF _kernel_inh_tbl[%d] =\n"
		"{\n",
		KERNEL_TMAX_INH_INHNO - KERNEL_TMIN_INH_INHNO + 1);
	
	for ( i = KERNEL_TMIN_INH_INHNO; i <= KERNEL_TMAX_INH_INHNO; i++ )
	{
		for ( j = 0; j < m_iObjs; j++ )
		{
			if ( atoi(m_pParamPacks[j]->GetParam(DEFINH_INHNO)) == i )
			{
				break;
			}
		}
		if ( j < m_iObjs )
		{
			fprintf(fp, "\t(FP)(%s),\n", m_pParamPacks[j]->GetParam(DEFINH_INTHDR));
		}
#if _KERNEL_SPT_ISR
		else if ( i >= _KERNEL_IRCATR_TMIN_INHNO && i <= _KERNEL_IRCATR_TMAX_INHNO )
		{
			fprintf(fp, "\t(FP)_KERNEL_EXE_IRC,\n");
		}
#endif
		else
		{
			fprintf(fp, "\tNULL,\n");
		}
	}
	fprintf(fp, "};\n\n");
}


// %jp{cfgファイル定義部書き出し}
void  CApiDefInh::WriteCfgStart(FILE* fp)
{
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2006 by Project HOS                                    
// ---------------------------------------------------------------------------
