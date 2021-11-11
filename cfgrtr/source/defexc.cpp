// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    DEF_EXC API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "defexc.h"
#include "analyze.h"
#include "readcfg.h"


#define DEFEXC_EXCNO		0  /* %jp{第1パラメータ:CPU例外番号} */
#define DEFEXC_EXCATR		1  /* %jp{パラメーターブロック 第1パラメータ:CPU例外ハンドラ属性} */
#define DEFEXC_EXCHDR		2  /* %jp{パラメーターブロック 第2パラメータ:CPU例外ハンドラの先頭番地} */


// %jp{コンストラクタ}
CApiDefExc::CApiDefExc()
{
	// %jp{パラメーター構文設定}
	m_iParamSyntax[0] = 0;		// %jp{単独パラメーター}
	m_iParamSyntax[1] = 2;		// %jp{2個のパラメーターブロック}
	m_iParams         = 2;

	m_iMaxExcNo = -1;  //%jp{最大例外番号を負の値で初期化}
	m_iMinExcNo = -1;  //%jp{最小例外番号を負の値で初期化}
}


// %jp{デストラクタ}
CApiDefExc::~CApiDefExc()
{
}


// %jp{自動ID番号割り当て}
int CApiDefExc::AutoId(void)
{
	return CFG_ERR_OK;
}


// %jp{APIの解析}
int CApiDefExc::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "DEF_EXC") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "HOS_MAX_EXCNO") == 0 )
	{
		int iExcNo;

		//%jp{最大例外番号指定処理}

		if ( m_iMaxExcNo >= 0 )
		{
			return CFG_ERR_MULTIDEF;  //%jp{多重定義}
		}

		if ( (iExcNo = atoi(pszParams)) < 0 )
		{
			return CFG_ERR_PARAM;  //%jp{パラメタが指定されていない}
		}

		m_iMaxExcNo = iExcNo;

		return CFG_ERR_OK;
	}
	else if ( strcmp(pszApiName, "HOS_MIN_EXCNO") == 0 )
	{
		int iExcNo;

		//%jp{最小例外番号指定処理}
		if ( m_iMinExcNo >= 0 )
		{
			return CFG_ERR_MULTIDEF;  //%jp{多重定義}
		}

		if ( (iExcNo = atoi(pszParams)) < 0 )
		{
			return CFG_ERR_PARAM;  //%jp{パラメタが指定されていない}
		}

		m_iMinExcNo = iExcNo;

		return CFG_ERR_OK;
	}

	return CFG_ERR_NOPROC;
}


// %jp{cfgファイル定義部書き出し}
void  CApiDefExc::WriteCfgDef(FILE* fp)
{
#if !(defined(_KERNEL_PROCATR_ARM_ARMV6M) || defined(_KERNEL_PROCATR_ARM_ARMV7M))
	int i, j;

	// %jp{最大例外番号未設定時は, _KERNEL_TMAX_EXC_EXCNOを反映}
	if ( m_iMaxExcNo < 0 )
		m_iMaxExcNo = _KERNEL_TMAX_EXC_EXCNO;

	// %jp{最小例外番号未設定時は, _KERNEL_TMIN_EXC_EXCNOを反映}
	if ( m_iMinExcNo < 0 )
		m_iMinExcNo = _KERNEL_TMIN_EXC_EXCNO;


	// %jp{コメント出力}
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*    Define CPU exception handlers           */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	/* %jp{CPU例外ハンドラ管理テーブル生成} */
	fprintf(fp,
		"\n\n"
#if !_KERNEL_SPT_DEF_EXC
		"const "
#endif
		"_KERNEL_T_EXCINF _kernel_exc_tbl[%d] =\n"
		"\t{\n",
		_KERNEL_TMAX_EXC_EXCNO - _KERNEL_TMIN_EXC_EXCNO + 1);

	// %jp{CPU例外ハンドラの起動番地を検索}
	for ( i = _KERNEL_TMIN_EXC_EXCNO; i <= _KERNEL_TMAX_EXC_EXCNO; i++ )
	{
		for ( j = 0; j < m_iObjs; j++ )
		{
			if ( atoi(m_pParamPacks[j]->GetParam(DEFEXC_EXCNO)) == i )
			{
				break;
			}
		}

		// %jp{CPU例外ハンドラの起動番地を設定}
		if ( j < m_iObjs )
		{
			fprintf(fp, "\t\t{(FP)(%s)},\n", m_pParamPacks[j]->GetParam(DEFEXC_EXCHDR));
		}
		else
		{
			fprintf(fp, "\t\t{(FP)NULL},\n");
		}
	}
	fprintf(fp, "\t};\n\n");

	// %jp{CPU例外ハンドラの個数, CPU例外ハンドラ番号の最小値/最大値を出力}
	fprintf(
		fp,
		"const INT      kernel_exc_cnt = %d;\t\t/* CPU exception handler control block count */\n"
		"const EXCNO    kernel_min_excno = %d;\t\t/* minimum CPU exception handler number */\n"
		"const EXCNO    kernel_max_excno = %d;\t\t/* maximum CPU exception handler number */\n",
		m_iMaxExcNo - m_iMinExcNo + 1,
		m_iMinExcNo,
		m_iMaxExcNo);
#endif
}


// %jp{cfgファイル初期化部書き出し}
void  CApiDefExc::WriteCfgIni(FILE* fp)
{
	int i;

	// %jp{オブジェクト存在チェック}
	if ( m_iObjs == 0 )
	{
		return;
	}

	// %jp{コメント出力}
	fputs("\n\t/* initialize CPU exception handler table */\n", fp);
	
	// %jp{初期化部出力}
	for ( i = 0; i < m_iObjs; i++ )
	{
		fprintf(
			fp,
			"\t_kernel_exc_tbl[%s].exchdr = (FP)(%s);\n",
			m_pParamPacks[i]->GetParam(DEFEXC_EXCNO),
			m_pParamPacks[i]->GetParam(DEFEXC_EXCHDR));
	}
}



// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS                                    
// ---------------------------------------------------------------------------
