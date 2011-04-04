// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター
//    CRE_MBF API の処理
//
//                                    Copyright (C) 1998-2003 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "crembf.h"
#include "analyze.h"
#include "readcfg.h"


#define CREMBF_MBFID		0
#define CREMBF_MBFATR		1
#define CREMBF_MAXMSZ		2
#define CREMBF_MBFSZ		3
#define CREMBF_MBF			4


// コンストラクタ
CApiCreMbf::CApiCreMbf()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_MBFID;

	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 4;		// 4パラメーターのブロック
	m_iParams = 2;
}


// デストラクタ
CApiCreMbf::~CApiCreMbf()
{
}


// APIの解析
int CApiCreMbf::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_MBF") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_MBFID") == 0 )
	{
		int iId;

		if ( m_iMaxId >= 0 )
		{
			return CFG_ERR_MULTIDEF;
		}

		if ( m_iResObj >= 0 )
		{
			return CFG_ERR_DEF_CONFLICT;
		}

		if ( (iId = atoi(pszParams)) < 0 )
		{
			return CFG_ERR_PARAM;
		}

		m_iMaxId = iId;

		return CFG_ERR_OK;
	}
	else if ( strcmp(pszApiName, "KERNEL_RSV_MBFID") == 0 )
	{
		int iId;

		if ( m_iMaxId >= 0 )
		{
			return CFG_ERR_DEF_CONFLICT;
		}

		if ( (iId = atoi(pszParams)) < 0 )
		{
			return CFG_ERR_PARAM;
		}

		if ( m_iResObj < 0 )
		{
			m_iResObj = 0;
		}
		m_iResObj += iId;

		return CFG_ERR_OK;
	}

	return CFG_ERR_NOPROC;
}


// ID 定義ファイル書き出し
void CApiCreMbf::WriteId(FILE* fp)
{
	int i;

	// ID 直接指定でないオブジェクトが在るかどうかサーチ
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CREMBF_MBFID)) == 0 )
		{
			break;
		}
	}
	if ( i == m_iObjs )
	{
		return;
	}

	fputs("\n\n/* message buffer ID definetion */\n", fp);
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CREMBF_MBFID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CREMBF_MBFID),
				m_iId[i]);
		}
	}

	fprintf( fp,"\n#define TMAX_MBFID\t\t%d\n", m_iMaxId );
}


// cfgファイル定義部書き出し
void  CApiCreMbf::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	bool blOutput;
	int  i, j;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*      create message buffer objects         */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	// バッファ領域出力
	blOutput = false;
	for ( i = 0; i < m_iObjs; i++ )
	{
		pszParam = m_pParamPacks[i]->GetParam(CREMBF_MBF);
		if ( strcmp(pszParam, "NULL") == 0 )
		{
			if ( !blOutput )
			{
				fputs("\n/* message buffer area */\n", fp);
				blOutput = true;
			}

			fprintf(
				fp,
				"static VP kernel_mbf%d[(%s)];\n",
				m_iId[i],
				m_pParamPacks[i]->GetParam(CREMBF_MBFSZ));
		}
	}

	if ( m_iObjs > 0 )
	{
		fprintf(
			fp,
			"\n/* message buffer control block for rom area */\n"
			"const T_KERNEL_MBFCB_ROM kernel_mbfcb_rom[%d] =\n"
			"\t{\n",
			m_iObjs);

		// コントロールブロック(ROM部)出力
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(
				fp,
				"\t\t{(ATR)(%s), (UINT)(%s), (SIZE)(%s),",
				m_pParamPacks[i]->GetParam(CREMBF_MBFATR),
				m_pParamPacks[i]->GetParam(CREMBF_MAXMSZ),
				m_pParamPacks[i]->GetParam(CREMBF_MBFSZ));
			pszParam = m_pParamPacks[i]->GetParam(CREMBF_MBF);
			if ( strcmp(pszParam, "NULL") == 0 )
			{
				fprintf(
					fp,
					"(VP)kernel_mbf%d},\n",
					m_iId[i]);
			}
			else
			{
				fprintf(
					fp,
					"(VP)(%s)},\n",
					m_pParamPacks[i]->GetParam(CREMBF_MBF));
			}
		}
		fprintf(fp, "\t};\n");
	}

	// コントロールブロック(RAM部)出力
	if ( m_iObjs > 0 )
	{
		fprintf(
			fp,
			"\n/* message buffer control block for ram area */\n"
			"T_KERNEL_MBFCB_RAM kernel_mbfcb_ram[%d];\n",
			m_iObjs);
	}

	// コントロールブロックテーブル出力
	if ( m_iMaxId > 0 )
	{
		fprintf(
			fp,
			"\n/* message buffer control block table */\n"
			"T_KERNEL_MBFCB_RAM *kernel_mbfcb_ram_tbl[%d] =\n"
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
				fprintf(fp, "\t\t&kernel_mbfcb_ram[%d],\n", j);
			}
			else
			{
				// オブジェクトが無い場合
				fputs("\t\tNULL,\n", fp);
			}
		}
		fputs("\t};\n", fp);
	}

	// 個数情報出力
	fprintf(
		fp,
		"\n/* mail box control block count */\n"
		"const INT kernel_mbfcb_cnt = %d;\n",
		m_iMaxId);
}


// cfgファイル初期化部書き出し
void  CApiCreMbf::WriteCfgIni(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}

	// 初期化部出力
	fprintf(
		fp,
		"\t\n\t\n"
		"\t/* initialize message buffer control block */\n"
		"\tfor ( i = 0; i < %d; i++ )\n"
		"\t{\n"
		"\t\tkernel_mbfcb_ram[i].mbfcb_rom = &kernel_mbfcb_rom[i];\n"
		"\t}\n",
		m_iObjs);
}


// cfgファイル起動部書き出し
void  CApiCreMbf::WriteCfgStart(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}
}


// end of file
