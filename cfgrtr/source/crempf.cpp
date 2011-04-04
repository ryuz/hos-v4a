// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター
//    CRE_MPF API の処理
//
//                                    Copyright (C) 1998-2003 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "crempf.h"
#include "analyze.h"
#include "readcfg.h"


#define CREMPF_MPFID		0
#define CREMPF_MPFATR		1
#define CREMPF_BLKCNT		2
#define CREMPF_BLKSZ		3
#define CREMPF_MPF			4



// コンストラクタ
CApiCreMpf::CApiCreMpf()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_MPFID;

	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 4;		// 4パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreMpf::~CApiCreMpf()
{
}



// APIの解析
int CApiCreMpf::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_MPF") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_MPFID") == 0 )
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
	else if ( strcmp(pszApiName, "KERNEL_RSV_MPFID") == 0 )
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
void CApiCreMpf::WriteId(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}
}


// cfgファイル定義部書き出し
void  CApiCreMpf::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	int         i;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*   create fixed size memory-pool objects    */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	// %jp{メモリプール領域出力}
	for ( i = 0; i < m_iObjs; i++ )
	{
		pszParam = m_pParamPacks[i]->GetParam(CREMPF_MPF);
		if ( strcmp(pszParam, "NULL") == 0 )
		{
			fprintf(
				fp,
				"static VP _kernel_mpf%d_mpfblk[TSZ_MPF((%s), (%s)) + (sizeof(VP) - 1) / sizeof(VP)];\n",
				m_iId[i],
				m_pParamPacks[i]->GetParam(CREMPF_BLKCNT),
				m_pParamPacks[i]->GetParam(CREMPF_BLKSZ));
		}
	}


#if _KERNEL_MPFCB_ALGORITHM == _KERNEL_MPFCB_ALG_BLKARRAY
#if _KERNEL_MPFCB_SPLIT_RO
	// %jp{ブロック配列＆ROM分離}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_MPFCB _kernel_mpfcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteMpfcbRam(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{{0}, },\n");
			}
		}
		fprintf(fp, "\t};\n");

		// %jp{ROM部出力}
		fprintf(fp, "\nconst _KERNEL_T_MPFCB_RO _kernel_mpfcb_ro_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteTcbRom(fp, iObjNum);
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
	// ブロック配列＆統合MPFCB
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_MPFCB _kernel_mpfcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteMpfcbRam(fp, iObjNum);
				WriteMpfcbRom(fp, iObjNum);
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
#elif _KERNEL_MPFCB_ALGORITHM == _KERNEL_MPFCB_ALG_PTRARRAY
#if _KERNEL_MPFCB_SPLIT_RO
	// ポインタ配列＆ROM分離
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "const _KERNEL_T_MPFCB_RO _kernel_tcb_ro_blk_%d = {", m_iId[i]);
			WriteTcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_MPFCB _kernel_mpfcb_blk_%d = {", m_iId[i]);
			WriteTcbRam(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_MPFCB *_kernel_mpfcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_mpfcb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#else
	// ポインタ配列＆統合MPFCB
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_MPFCB _kernel_mpfcb_blk_%d = {", m_iId[i]);
			WriteMpfcbRam(fp, i);
			WriteMpfcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_MPFCB *_kernel_mpfcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_mpfcb_blk_%d,\n", i);
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

	// %jp{タスク情報出力}
	fprintf(
		fp,
		"\nconst ID	_kernel_max_mpfid = %d;\n",
		m_iMaxId);

}


void CApiCreMpf::WriteMpfcbRam(FILE *fp, int iObj)
{
#if _KERNEL_MPFCB_QUE
	fprintf(fp, "{0}, ");		/* %jp{キュー} */
#endif

#if _KERNEL_MPFCB_FREBLK
	fprintf(fp, "0, ");			/* %jp{空きブロック} */
#endif

#if _KERNEL_MPFCB_FBLKCNT
	fprintf(fp, "0, ");			/* %jp{空きブロック数} */
#endif
}


void CApiCreMpf::WriteMpfcbRom(FILE *fp, int iObj)
{
#if _KERNEL_MPFCB_MPFATR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREMPF_MPFATR));		/* %jp{固定長メモリプール属性} */
#endif

#if _KERNEL_MPFCB_BLKCNT
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREMPF_BLKCNT));		/* %jp{獲得できるメモリブロック数(個数)} */
#endif

#if _KERNEL_MPFCB_BLKSZ
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREMPF_BLKSZ));			/* %jp{メモリブロックのサイズ(バイト数)} */
#endif

#if _KERNEL_MPFCB_MPF
	if ( strcmp(m_pParamPacks[iObj]->GetParam(CREMPF_MPF), "NULL") == 0 )
	{
		fprintf(fp, "_kernel_mpf%d_mpfblk, ", m_iId[iObj]);		/* %jp{固定長メモリプール領域の先頭番地} */
	}
	else
	{
		fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREMPF_MPF));		/* %jp{固定長メモリプール領域の先頭番地} */
	}
#endif
}


// cfgファイル初期化部書き出し
void  CApiCreMpf::WriteCfgIni(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}
}


// cfgファイル起動部書き出し
void  CApiCreMpf::WriteCfgStart(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS
// ---------------------------------------------------------------------------
