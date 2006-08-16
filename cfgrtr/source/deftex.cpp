// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    DEF_TEX API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "deftex.h"
#include "analyze.h"
#include "readcfg.h"


#define DEFTEX_TSKID		0
#define DEFTEX_TEXATR		1
#define DEFTEX_TEXRTN		2



// コンストラクタ
CApiDefTex::CApiDefTex()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 2;		// 2パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiDefTex::~CApiDefTex()
{
}


// APIの解析
int CApiDefTex::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "DEF_TEX") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// 自動ID番号割り当て
int CApiDefTex::AutoId(void)
{
	return CFG_ERR_OK;
}


// cfgファイル定義部書き出し
void  CApiDefTex::WriteCfgDef(FILE* fp)
{
	int  i;

	if ( m_iObjs <= 0 )
	{
		return;
	}

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*          task exception objects            */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	fprintf(
		fp,
		"\n/* task exception control block */\n"
		"const T_KERNEL_TEXCB_RAM kernel_texcb_ram[%d] =\n"
		"\t{\n",
		m_iObjs);

	// コントロールブロック(ROM部)出力
	for ( i = 0; i < m_iObjs; i++ )
	{
		fprintf(
			fp,
			"\t\t{0, (FP)(%s)},\n",
			m_pParamPacks[i]->GetParam(DEFTEX_TEXRTN));
	}
	fprintf(fp, "\t};\n");
}


// cfgファイル初期化部書き出し
void  CApiDefTex::WriteCfgIni(FILE* fp)
{
	int i;

	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}

	// 初期化部出力
	fputs(
		"\t\n\t\n"
		"\t/* initialize task exception handler */\n",
		fp);

	for ( i = 0; i < m_iObjs; i++ )
	{
		fprintf(
			fp,
			"\tkernel_tcb_ram_tbl[(%s) - TMIN_TSKID]->texcb = &kernel_texcb_rom[%d];\n",
			m_pParamPacks[i]->GetParam(DEFTEX_TSKID),
			i);
	}
}



// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
