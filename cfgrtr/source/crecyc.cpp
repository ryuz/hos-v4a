// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_CYC API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "crecyc.h"
#include "analyze.h"



#define CRECYC_CYCID		0
#define CRECYC_CYCATR		1
#define CRECYC_EXINF		2
#define CRECYC_CYCHDR		3
#define CRECYC_CYCTIM		4
#define CRECYC_CYCPHS		5



// コンストラクタ
CApiCreCyc::CApiCreCyc()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 5;		// 5パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreCyc::~CApiCreCyc()
{
}


// APIの解析
int CApiCreCyc::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_CYC") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "HOS_MAX_CYCID") == 0 )
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
	else if ( strcmp(pszApiName, "HOS_RES_CYCOBJ") == 0 )
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

	return CFG_ERR_NOPROC;
}


// ID 定義ファイル書き出し
void CApiCreCyc::WriteId(FILE* fp)
{
	int i;

	// ID 直接指定でないオブジェクトが在るかどうかサーチ
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CRECYC_CYCID)) == 0 )
		{
			break;
		}
	}
	if ( i == m_iObjs )
	{
		return;
	}

	fputs("\n\n/* cyclic handler ID definetion */\n", fp);
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CRECYC_CYCID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CRECYC_CYCID),
				m_iId[i]);
		}
	}

	fprintf( fp,"\n#define TMAX_CYCID\t\t%d\n", m_iMaxId );
}


// cfgファイル定義部書き出し
void  CApiCreCyc::WriteCfgDef(FILE* fp)
{
	int  i, j;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*       create cyclic handler objects        */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	if ( m_iObjs > 0 )
	{
		fprintf(
			fp,
			"\n/* cyclic handler control block for rom area */\n"
			"const T_KERNEL_CYCCB_ROM kernel_cyccb_rom[%d] =\n"
			"\t{\n",
			m_iObjs);

		// コントロールブロック(ROM部)出力
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(
				fp,
				"\t\t{(ATR)(%s), (VP_INT)(%s), (FP)(%s), (RELTIM)(%s)},\n",
				m_pParamPacks[i]->GetParam(CRECYC_CYCATR),
				m_pParamPacks[i]->GetParam(CRECYC_EXINF),
				m_pParamPacks[i]->GetParam(CRECYC_CYCHDR),
				m_pParamPacks[i]->GetParam(CRECYC_CYCTIM));
		}
		fprintf(fp, "\t};\n");
	}

	// コントロールブロック(RAM部)出力
	if ( m_iObjs > 0 )
	{
		fprintf(
			fp,
			"\n/* cyclic handler control block for ram area */\n"
			"T_KERNEL_CYCCB_RAM kernel_cyccb_ram[%d];\n",
			m_iObjs);
	}

	// コントロールブロックテーブル出力
	if ( m_iMaxId > 0 )
	{
		fprintf(
			fp,
			"\n/* cyclic handler control block table */\n"
			"T_KERNEL_CYCCB_RAM *kernel_cyccb_ram_tbl[%d] =\n"
			"\t{\n",
			m_iMaxId);

		for ( i = 0; i < m_iMaxId; i++ )
		{
			// ID検索
			for ( j = 0; j < m_iObjs; j++ )
			{
				if ( m_iId[j] == i + 1 )
				{
					break;
				}
			}
			if ( j < m_iObjs )
			{
				// オブジェクトが存在した場合
				fprintf(fp, "\t\t&kernel_cyccb_ram[%d],\n", j);
			}
			else
			{
				// オブジェクトが無い場合
				fputs("\t\tNULL,\n", fp);
			}
		}
		fputs("\t};\n", fp);
	}

	// テーブルサイズ情報出力
	fprintf(
		fp,
		"\n/* cyclic handler control block count */\n"
		"const INT kernel_cyccb_cnt = %d;\n",
		m_iMaxId);
}


// cfgファイル初期化部書き出し
void  CApiCreCyc::WriteCfgIni(FILE* fp)
{
	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}

	// 初期化部出力
	fprintf(
		fp,
		"\t\n\t\n"
		"\t/* initialize cyclic handler control block */\n"
		"\tfor ( i = 0; i < %d; i++ )\n"
		"\t{\n"
		"\t\tkernel_cyccb_ram[i].cyccb_rom = &kernel_cyccb_rom[i];\n"
		"\t}\n",
		m_iObjs);
}


// cfgファイル起動部書き出し
void  CApiCreCyc::WriteCfgStart(FILE* fp)
{
	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}

	fputs("\tkernel_ini_cyc();\t\t/* initialize cyclic handler */\n", fp);
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS                                    
// ---------------------------------------------------------------------------
