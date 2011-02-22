// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Advance  configurator
//    ATT_ISR API
//                                                                            
//                                    Copyright (C) 1998-2010 by Project HOS
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

	m_iMinIntNo  =  0;	
	m_iMaxIntNo  = -1;
	m_pszRegBase = NULL;
}

// デストラクタ
CApiAttIsr::~CApiAttIsr()
{
	delete [] m_pszRegBase;
}


// 自動ID番号割り当て
int CApiAttIsr::AutoId(void)
{
	if ( m_iMaxIntNo ==  -1 )
	{
		m_iMinIntNo = _KERNEL_IRCATR_TMIN_INTNO;
		m_iMaxIntNo = _KERNEL_IRCATR_TMAX_INTNO;
	}
	
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
		int iId;

		if ( m_iMaxId > 0 )
		{
			return CFG_ERR_MULTIDEF;
		}

		if ( m_iResObj > 0 )
		{
			return CFG_ERR_DEF_CONFLICT;
		}

		if ( (iId = atoi(pszParams)) <= 0 )
		{
			return CFG_ERR_PARAM;
		}
		
		m_iMaxId = iId;
		
		return CFG_ERR_OK;
	}
	else if ( strcmp(pszApiName, "KERNEL_RSV_ISRID") == 0 )
	{
		int iId;

		if ( m_iMaxId > 0 )
		{
			return CFG_ERR_DEF_CONFLICT;
		}

		if ( (iId = atoi(pszParams)) <= 0 )
		{
			return CFG_ERR_PARAM;
		}

		m_iResObj += iId;

		return CFG_ERR_OK;
	}
	else if ( strcmp(pszApiName, "KERNEL_MIN_INTNO") == 0 )
	{
		m_iMinIntNo = atoi(pszParams);
		return CFG_ERR_OK;
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_INTNO") == 0 )
	{
		m_iMaxIntNo = atoi(pszParams);
		return CFG_ERR_OK;
	}
	else if ( strcmp(pszApiName, "KERNEL_IRC_REGBASE") == 0 )
	{
		if ( m_pszRegBase != NULL )
		{
			return CFG_ERR_MULTIDEF;
		}
		
		int len = strlen(pszParams);
		m_pszRegBase = new char[len + 1];
		strcpy(m_pszRegBase, pszParams);
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

	fprintf(
			fp,
			"\n"
			"const INTNO _kernel_min_intno = %d;\n"
			"const INTNO _kernel_max_intno = %d;\n",
			m_iMinIntNo, m_iMaxIntNo);
	
	// 割込み管理テーブル生成
	if ( m_iMaxIntNo - m_iMinIntNo + 1 > 0 )
	{
		fprintf(
			fp,
			"\n"
			"_KERNEL_T_INTINF _kernel_int_tbl[%d];\n\n",
			 m_iMaxIntNo - m_iMinIntNo + 1);
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

#if _KERNEL_IRCATR_REG_BASE
	if ( m_pszRegBase != NULL )
	{
		fprintf(
				fp,
				"const VP        _kernel_irc_reg_base = (VP)(%s);\n",
				m_pszRegBase);
	}
	else
	{
		fprintf(
				fp,
				"const VP        _kernel_irc_reg_base = (VP)(0x%x);\n",
				_KERNEL_IRCATR_REG_BASE_DEF);
	}
#endif
}


// cfgファイル初期化部書き出し
void  CApiAttIsr::WriteCfgIni(FILE* fp)
{
	int i;

	for ( i = 0; i < m_iObjs; i++ )
	{
		fprintf(
				fp,
				"\t{\n"
				"\t\tconst T_CISR\tcisr = {(ATR)(%s), (VP_INT)(%s), (INTNO)(%s), (FP)(%s)};\n"
				"\t\tacre_isr(&cisr);\n"
				"\t}\n",
				m_pParamPacks[i]->GetParam(ATTISR_ISRATR),
				m_pParamPacks[i]->GetParam(ATTISR_EXINF),
				m_pParamPacks[i]->GetParam(ATTISR_INTNO),
				m_pParamPacks[i]->GetParam(ATTISR_ISR)
			);
	}
}


// end of file
