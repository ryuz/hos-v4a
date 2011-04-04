// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Advance  configurator
//    CRE_CYC API
//
//                                    Copyright (C) 1998-2010 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "crecyc.h"
#include "analyze.h"
#include "readcfg.h"



#define CRECYC_CYCID		0
#define CRECYC_CYCATR		1
#define CRECYC_EXINF		2
#define CRECYC_CYCHDR		3
#define CRECYC_CYCTIM		4
#define CRECYC_CYCPHS		5



// コンストラクタ
CApiCreCyc::CApiCreCyc()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_CYCID;

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
	else if ( strcmp(pszApiName, "KERNEL_MAX_CYCID") == 0 )
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
	else if ( strcmp(pszApiName, "KERNEL_RSV_CYCID") == 0 )
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
void CApiCreCyc::WriteId(FILE* fp)
{
	int i;

	// %jp{コメントを出力}
	fputs("\n\n/* Semaphore object ID definetion */\n\n", fp);


	// %jp{ID定義を出力}
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

	// %jp{ID最大値定義を出力}
	fprintf( fp,
		"\n"
		"#ifdef  TMAX_CYCID\n"
		"#undef  TMAX_CYCID\n"
		"#endif\n"
		"\n"
		"#define TMAX_CYCID\t\t%d\n\n", m_iMaxId );
}


// cfgファイル定義部書き出し
void  CApiCreCyc::WriteCfgDef(FILE* fp)
{
	int  i;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*       create cyclic handler objects        */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	if ( m_iMaxId > 0 )
	{
#if _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_BLKARRAY
#if _KERNEL_CYCCB_SPLIT_RO
	// %jp{ブロック配列＆ROM分離}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_CYCCB _kernel_cyccb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteSemcbRam(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{0},\n");
			}
		}
		fprintf(fp, "\t};\n");

		// %jp{ROM部出力}
		fprintf(fp, "\nconst _KERNEL_T_CYCCB_RO _kernel_cyccb_ro_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteSemcbRom(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{0},\n");
			}
		}
		fprintf(fp, "\t};\n\n");
	}
#else
	// %jp{ブロック配列＆統合CYCCB}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_CYCCB _kernel_cyccb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteCyccbRam(fp, iObjNum);
				WriteCyccbRom(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{{0}, },\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#endif
#elif _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_PTRARRAY
#if _KERNEL_CYCCB_SPLIT_RO
	// %jp{ポインタ配列＆ROM分離}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "const _KERNEL_T_CYCCB_RO _kernel_cyccb_ro_blk_%d = {", m_iId[i]);
			WriteCyccbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_CYCCB _kernel_cyccb_blk_%d = {", m_iId[i]);
			WriteCyccbRam(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_CYCCB *_kernel_cyccb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_cyccb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#else
	// %jp{ポインタ配列＆統合CYCCB}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_CYCCB _kernel_cyccb_blk_%d = {", m_iId[i]);
			WriteCyccbRam(fp, i);
			WriteCyccbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_CYCCB *_kernel_cyccb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_cyccb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#endif
#endif
	}

	// テーブルサイズ情報出力
	fprintf(
		fp,
		"\nconst ID	_kernel_max_cycid = %d;\n",
		m_iMaxId);
}



void CApiCreCyc::WriteCyccbRam(FILE *fp, int iObj)
{
#if _KERNEL_CYCCB_TIMOBJ
	fprintf(fp, "{0}, ");														/* %jp{タイムオブジェクト} */
#endif
}


void CApiCreCyc::WriteCyccbRom(FILE *fp, int iObj)
{
#if _KERNEL_CYCCB_CYCATR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRECYC_CYCATR));	/**< %jp{周期ハンドラ属性} */
#endif

#if _KERNEL_CYCCB_EXINF
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRECYC_EXINF));		/**< %jp{周期ハンドラの拡張情報} */
#endif

#if _KERNEL_CYCCB_CYCHDR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRECYC_CYCHDR));	/**< %jp{周期ハンドラ} */
#endif

#if _KERNEL_CYCCB_CYCTIM
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRECYC_CYCTIM));	/**< %jp{周期ハンドラの起動周期} */
#endif

#if _KERNEL_CYCCB_CYCPHS
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRECYC_CYCPHS));	/**< %jp{周期ハンドラの起動位相} */
#endif
}



// cfgファイル初期化部書き出し
void  CApiCreCyc::WriteCfgIni(FILE* fp)
{
#if _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_PTRARRAY && _KERNEL_CYCCB_SPLIT_RO
	if ( m_iObjs <= 0 )
	{
		return;
	}

	fprintf(fp, "\n\t/* cycaphores */\n");
	for ( int i = 0; i < m_iObjs; i++ )
	{
		fprintf(fp, "\t_kernel_cyccb_blk_%d.cyccb_ro = &_kernel_cyccb_ro_blk_%d;\n", m_iId[i], m_iId[i]);
	}
#endif
}


// cfgファイル起動部書き出し
void  CApiCreCyc::WriteCfgStart(FILE* fp)
{
}


// end of file
