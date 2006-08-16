// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_DTQ API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "credtq.h"
#include "analyze.h"



#define CREDTQ_DTQID		0
#define CREDTQ_DTQATR		1
#define CREDTQ_DTQCNT		2
#define CREDTQ_DTQ			3



// コンストラクタ
CApiCreDtq::CApiCreDtq()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 3;		// 3パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreDtq::~CApiCreDtq()
{
}


// APIの解析
int CApiCreDtq::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_DTQ") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "HOS_MAX_DTQID") == 0 )
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
	else if ( strcmp(pszApiName, "HOS_RES_DTQOBJ") == 0 )
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
void CApiCreDtq::WriteId(FILE* fp)
{
	int i;

	// ID 直接指定でないオブジェクトが在るかどうかサーチ
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CREDTQ_DTQID)) == 0 )
		{
			break;
		}
	}
	if ( i == m_iObjs )
	{
		return;
	}

	fputs("\n\n/* data queue ID definetion */\n", fp);
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CREDTQ_DTQID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CREDTQ_DTQID),
				m_iId[i]);
		}
	}

	fprintf( fp,"\n#define TMAX_DTQID\t\t%d\n", m_iMaxId );
}


// cfgファイル定義部書き出し
void  CApiCreDtq::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	bool blOutput;
	int  i, j;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        create data queue objects           */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	// データキュー領域出力
	blOutput = false;
	for ( i = 0; i < m_iObjs; i++ )
	{
		pszParam = m_pParamPacks[i]->GetParam(CREDTQ_DTQ);
		if ( strcmp(pszParam, "NULL") == 0 )
		{
			if ( !blOutput )
			{
				fputs("\n/* data que area */\n", fp);
				blOutput = true;
			}

			fprintf(
				fp,
				"static VP_INT kernel_dtq%d_dtq[%s];\n",
				m_iId[i],
				m_pParamPacks[i]->GetParam(CREDTQ_DTQCNT));
		}
	}

	if ( m_iObjs > 0 )
	{
		fprintf(
			fp,
			"\n/* data queue control block for rom area */\n"
			"const T_KERNEL_DTQCB_ROM kernel_dtqcb_rom[%d] =\n"
			"\t{\n",
			m_iObjs);

		// コントロールブロック(ROM部)出力
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(
				fp,
				"\t\t{(ATR)(%s), (UINT)(%s), ",
				m_pParamPacks[i]->GetParam(CREDTQ_DTQATR),
				m_pParamPacks[i]->GetParam(CREDTQ_DTQCNT));
			pszParam = m_pParamPacks[i]->GetParam(CREDTQ_DTQ);
			if ( strcmp(pszParam, "NULL") == 0 )
			{
				fprintf(fp,	"kernel_dtq%d_dtq},\n", m_iId[i]);
			}
			else
			{
				fprintf(fp,	"(VP_INT *)(%s)},\n", pszParam);
			}
		}
		fprintf(fp, "\t};\n");
	}

	// コントロールブロック(RAM部)出力
	if ( m_iObjs > 0 )
	{
		fprintf(
			fp,
			"\n/* data queue control block for ram area */\n"
			"T_KERNEL_DTQCB_RAM kernel_dtqcb_ram[%d];\n",
			m_iObjs);
	}

	// コントロールブロックテーブル出力
	if ( m_iMaxId > 0 )
	{
		fprintf(
			fp,
			"\n/* data queue control block table */\n"
			"T_KERNEL_DTQCB_RAM *kernel_dtqcb_ram_tbl[%d] =\n"
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
				fprintf(fp, "\t\t&kernel_dtqcb_ram[%d],\n", j);
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
		"\n/* data queue control block count */\n"
		"const INT kernel_dtqcb_cnt = %d;\n",
		m_iMaxId);
}


// cfgファイル初期化部書き出し
void  CApiCreDtq::WriteCfgIni(FILE* fp)
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
		"\t/* initialize data queue control block */\n"
		"\tfor ( i = 0; i < %d; i++ )\n"
		"\t{\n"
		"\t\tkernel_dtqcb_ram[i].dtqcb_rom = &kernel_dtqcb_rom[i];\n"
		"\t}\n",
		m_iObjs);
}


// cfgファイル起動部書き出し
void  CApiCreDtq::WriteCfgStart(FILE* fp)
{
	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}

	fputs("\tkernel_ini_dtq();\t\t/* initialize data queue */\n", fp);
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS                                    
// ---------------------------------------------------------------------------
