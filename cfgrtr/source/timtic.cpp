// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    HOS_TIM_TIC API の処理                                                  
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "timtic.h"
#include "analyze.h"
#include "readcfg.h"


#define TIMTIC_NUME		0
#define TIMTIC_DENO		1


// コンストラクタ
CApiTimTic::CApiTimTic()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 0;		// 単独パラメーター
	m_iParams         = 2;

	m_iNume = _KERNEL_TIC_NUME;
	m_iDeno = _KERNEL_TIC_DENO;
}


// デストラクタ
CApiTimTic::~CApiTimTic()
{
}



// APIの解析
int CApiTimTic::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	int iNume;
	int iDeno;
	int iErr;

	// API名チェック
	if ( strcmp(pszApiName, "KERNEL_TIM_TIC") == 0 )
	{
		if ( m_iObjs > 0 )
		{
			return CFG_ERR_MULTIDEF;
		}

		iErr = AddParams(pszParams);
		if ( iErr != CFG_ERR_OK )
		{
			return iErr;
		}
	
		iNume = atoi(m_pParamPacks[m_iObjs - 1]->GetParam(TIMTIC_NUME));
		iDeno = atoi(m_pParamPacks[m_iObjs - 1]->GetParam(TIMTIC_DENO));
		if ( iNume <= 0 || iDeno <= 0 )
		{
			return CFG_ERR_PARAM;
		}

		m_iNume = iNume;
		m_iDeno = iDeno;
		
		return CFG_ERR_OK;
	}

	return CFG_ERR_NOPROC;
}


// 文字列を展開
int CApiTimTic::AutoId(void)
{
	return CFG_ERR_OK;
}


// ID 定義ファイル書き出し
void CApiTimTic::WriteId(FILE* fp)
{
	fprintf(
		fp,
		"\n\n"
		"/* time tic */\n"
		"#define TIC_NUME\t\t(%d)\n"
		"#define TIC_DENO\t\t(%d)\n",
		m_iNume,
		m_iDeno);
}


// cfgファイル定義部書き出し
void  CApiTimTic::WriteCfgDef(FILE* fp)
{
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*                 system                     */\n"
		"/* ------------------------------------------ */\n"
		"\n"
		"const _KERNEL_T_SYSCB_RO _kernel_syscb_ro =\n"
		"\t{\n"
		"\t\t{\n"
#ifdef _KERNEL_TIMCB_TICDIV
		"\t\t\tTIC_NUME / TIC_DENO,\n"
#endif
#ifdef _KERNEL_TIMCB_TICMOD
		"\t\t\tTIC_NUME % TIC_DENO,\n"
#endif
#ifdef _KERNEL_TIMCB_TICDENO
		"\t\t\tTIC_DENO,\n"
#endif		
		"\t\t},\n"
		"\t};\n\n",
		fp);

#if _KERNEL_TIMCB_SYSTIM || _KERNEL_TIMCB_TICCNT
	fputs("_KERNEL_T_SYSCB _kernel_syscb;\n\n", fp);
#endif
}


// end of file
