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
#include "readcfg.h"



#define CREDTQ_DTQID		0
#define CREDTQ_DTQATR		1
#define CREDTQ_DTQCNT		2
#define CREDTQ_DTQ			3



// コンストラクタ
CApiCreDtq::CApiCreDtq()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_DTQID;

	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 3;		// 3パラメーターのブロック
	m_iParams         = 2;
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
	else if ( strcmp(pszApiName, "KERNEL_MAX_DTQID") == 0 )
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
	else if ( strcmp(pszApiName, "KERNEL_RSV_DTQID") == 0 )
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
void CApiCreDtq::WriteId(FILE* fp)
{
	int i;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// %jp{コメントを出力}
	fputs("\n\n/* Data queue object ID definetion */\n\n", fp);


	// %jp{ID定義を出力}
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

	// %jp{ID最大値定義を出力}
	fprintf( fp,
		"\n"
		"#ifdef  TMAX_DTQID\n"
		"#undef  TMAX_DTQID\n"
		"#endif\n"
		"\n"
		"#define TMAX_DTQID\t\t%d\n\n", m_iMaxId );

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
}


// cfgファイル定義部書き出し
void  CApiCreDtq::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	int  i;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// %jp{コメント出力}
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        create data queue objects           */\n"
		"/* ------------------------------------------ */\n\n\n"
		, fp);


	// %jp{データキュー領域出力}
	for ( i = 0; i < m_iObjs; i++ )
	{
		pszParam = m_pParamPacks[i]->GetParam(CREDTQ_DTQ);
		if ( strcmp(pszParam, "NULL") == 0 )
		{
			pszParam = m_pParamPacks[i]->GetParam(CREDTQ_DTQCNT);
			if ( strcmp(pszParam, "0") != 0 )
			{
				fprintf(
					fp,
					"static VP_INT _kernel_dtq%d_dtq[(%s)];\n",
					m_iId[i],
					m_pParamPacks[i]->GetParam(CREDTQ_DTQCNT));
			}
		}
	}


	if ( m_iMaxId > 0 )
	{
#if _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_BLKARRAY
#if _KERNEL_DTQCB_SPLIT_RO
	// %jp{ブロック配列＆ROM分離}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_DTQCB _kernel_dtqcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteDtqcbRam(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{0},\n");
			}
		}
		fprintf(fp, "\t};\n");

		// %jp{ROM部出力}
		fprintf(fp, "\nconst _KERNEL_T_DTQCB_RO _kernel_dtqcb_ro_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteDtqcbRom(fp, iObjNum);
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
	// %jp{ブロック配列＆統合DTQCB}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_DTQCB _kernel_dtqcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteDtqcbRam(fp, iObjNum);
				WriteDtqcbRom(fp, iObjNum);
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
#elif _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_PTRARRAY
#if _KERNEL_DTQCB_SPLIT_RO
	// %jp{ポインタ配列＆ROM分離}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "const _KERNEL_T_DTQCB_RO _kernel_dtqcb_ro_blk_%d = {", m_iId[i]);
			WriteDtqcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_DTQCB _kernel_dtqcb_blk_%d = {", m_iId[i]);
			WriteDtqcbRam(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_DTQCB *_kernel_dtqcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_dtqcb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#else
	// %jp{ポインタ配列＆統合DTQCB}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_DTQCB _kernel_dtqcb_blk_%d = {", m_iId[i]);
			WriteDtqcbRam(fp, i);
			WriteDtqcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_DTQCB *_kernel_dtqcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_dtqcb_blk_%d,\n", i);
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
		"\nconst ID	_kernel_max_dtqid = %d;\n",
		m_iMaxId);
}


void CApiCreDtq::WriteDtqcbRam(FILE *fp, int iObj)
{
#if _KERNEL_DTQCB_SQUE
	fprintf(fp, "{0}, ");													/* %jp{データキュー送信待ちタスクキュー} */
#endif

#if _KERNEL_DTQCB_RQUE
	fprintf(fp, "{0}, ");													/* %jp{データキュー受信待ちタスクキュー} */
#endif

#if _KERNEL_DTQCB_SDTQCNT
	fprintf(fp, "0, ");														/* %jp{データキューに入っているデータの数}%en{The number of data elemnts int the data queue} */
#endif

#if _KERNEL_DTQCB_HEAD
	fprintf(fp, "0, ");														/* %jp{データキューのデータ先頭位置} */
#endif
}


void CApiCreDtq::WriteDtqcbRom(FILE *fp, int iObj)
{
#if _KERNEL_DTQCB_DTQATR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREDTQ_DTQATR));	/* %jp{データキュー属性}%en{Data queue attribute} */
#endif

#if _KERNEL_DTQCB_DTQCNT
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREDTQ_DTQCNT));	/* %jp{データキュー領域の容量(データの個数)}%en{Capacity of the data queue area(the number of data elements)} */
#endif

#if _KERNEL_DTQCB_DTQ		/* %jp{データキュー領域の先頭番地}%en{Start address of the data queue area} */
	if ( strcmp(m_pParamPacks[iObj]->GetParam(CREDTQ_DTQCNT), "0") == 0 )
	{
		fprintf(fp, "NULL, ");
	}
	else
	{
		if ( strcmp(m_pParamPacks[iObj]->GetParam(CREDTQ_DTQCNT), "NULL") == 0 )
		{
			fprintf(fp, "_kernel_dtq%d_dtq, ", m_iId[iObj]);
		}
		else
		{
			fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREDTQ_DTQ));
		}
	}
#endif
}



// cfgファイル初期化部書き出し
void  CApiCreDtq::WriteCfgIni(FILE* fp)
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


// cfgファイル起動部書き出し
void  CApiCreDtq::WriteCfgStart(FILE* fp)
{
	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}

	if ( m_iMaxId <= 0 )
	{
		return;
	}
}


// end of file
