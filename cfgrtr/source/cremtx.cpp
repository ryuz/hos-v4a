// ---------------------------------------------------------------------------
//  Hyper Operating System V4a Advance configurator
//    CRE_MTX API の処理
//
//                                    Copyright (C) 1998-2009 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "cremtx.h"
#include "analyze.h"
#include "readcfg.h"


#define CREMTX_MTXID		0
#define CREMTX_MTXATR		1
#define CREMTX_CEILPRI		2



// %jp{コンストラクタ}
CApiCreMtx::CApiCreMtx()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_MTXID;

	// %jp{パラメーター構文設定}
	m_iParamSyntax[0] = 0;		// %jp{単独パラメーター}
	m_iParamSyntax[1] = 2;		// %jp{2パラメーターのブロック}
	m_iParams         = 2;
}


// デストラクタ
CApiCreMtx::~CApiCreMtx()
{
}


// APIの解析
int CApiCreMtx::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_MTX") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_MTXID") == 0 )
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
	else if ( strcmp(pszApiName, "KERNEL_RSV_MTXID") == 0 )
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
void CApiCreMtx::WriteId(FILE* fp)
{
	int i;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// %jp{コメントを出力}
	fputs("\n\n/* Mtxaphore object ID definetion */\n\n", fp);

	// %jp{ID定義を出力}
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CREMTX_MTXID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CREMTX_MTXID),
				m_iId[i]);
		}
	}

	// %jp{ID最大値定義を出力}
	fprintf( fp,
		"\n"
		"#ifdef  TMAX_MTXID\n"
		"#undef  TMAX_MTXID\n"
		"#endif\n"
		"\n"
		"#define TMAX_MTXID\t\t%d\n\n", m_iMaxId );
}


// cfgファイル定義部書き出し
void  CApiCreMtx::WriteCfgDef(FILE* fp)
{
	int  i;


	if ( m_iMaxId <= 0 )
	{
#if _KERNEL_SPT_MTX
		m_iMaxId = 1;
#else
		return;
#endif
	}

	// %jp{コメント出力}
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*         create mtxaphore objects           */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	if ( m_iMaxId > 0 )
	{
#if _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_BLKARRAY
#if _KERNEL_MTXCB_SPLIT_RO
	// %jp{ブロック配列＆ROM分離}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_MTXCB _kernel_mtxcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteMtxcbRam(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{0},\n");
			}
		}
		fprintf(fp, "\t};\n");

		// %jp{ROM部出力}
		fprintf(fp, "\nconst _KERNEL_T_MTXCB_RO _kernel_mtxcb_ro_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteMtxcbRom(fp, iObjNum);
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
	// %jp{ブロック配列＆統合MTXCB}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_MTXCB _kernel_mtxcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteMtxcbRam(fp, iObjNum);
				WriteMtxcbRom(fp, iObjNum);
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
#elif _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_PTRARRAY
#if _KERNEL_MTXCB_SPLIT_RO
	// %jp{ポインタ配列＆ROM分離}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "const _KERNEL_T_MTXCB_RO _kernel_mtxcb_ro_blk_%d = {", m_iId[i]);
			WriteMtxcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_MTXCB _kernel_mtxcb_blk_%d = {", m_iId[i]);
			WriteMtxcbRam(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_MTXCB *_kernel_mtxcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_mtxcb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#else
	// %jp{ポインタ配列＆統合MTXCB}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_MTXCB _kernel_mtxcb_blk_%d = {", m_iId[i]);
			WriteMtxcbRam(fp, i);
			WriteMtxcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_MTXCB *_kernel_mtxcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_mtxcb_blk_%d,\n", i);
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
		"\nconst ID	_kernel_max_mtxid = %d;\n",
		m_iMaxId);
}


void CApiCreMtx::WriteMtxcbRam(FILE *fp, int iObj)
{
#if _KERNEL_MTXCB_QUE
	fprintf(fp, "{0}, ");													/* %jp{キュー} */
#endif

#if _KERNEL_MTXCB_TSKHDL
	fprintf(fp, "_KERNEL_TSKHDL_NULL, ");									/**< %jp{ミューテックスを所持するタスクのハンドル} */
#endif

#if _KERNEL_MTXCB_NEXT
	fprintf(fp, "_KERNEL_MTXHDL_NULL, ");									/**< %jp{次のミューテックスハンドル} */
#endif

#if _KERNEL_MTXCB_PREV
	fprintf(fp, "_KERNEL_MTXHDL_NULL, ");									/**< %jp{前のミューテックスハンドル} */
#endif
}


void CApiCreMtx::WriteMtxcbRom(FILE *fp, int iObj)
{
#if _KERNEL_MTXCB_MTXATR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREMTX_MTXATR));	/**< %jp{ミューテックス属性} */
#endif

#if _KERNEL_MTXCB_CEILPRI
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREMTX_CEILPRI));	/**< %jp{ミューテックスの上限優先度} */
#endif
}



// cfgファイル初期化部書き出し
void  CApiCreMtx::WriteCfgIni(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}

#if _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_PTRARRAY && _KERNEL_MTXCB_SPLIT_RO
	if ( m_iObjs <= 0 )
	{
		return;
	}

	fprintf(fp, "\n\t/* mutex */\n");
	for ( int i = 0; i < m_iObjs; i++ )
	{
		fprintf(fp, "\t_kernel_mtxcb_blk_%d.mtxcb_ro = &_kernel_mtxcb_ro_blk_%d;\n", m_iId[i], m_iId[i]);
	}
#endif
}


// cfgファイル起動部書き出し
void  CApiCreMtx::WriteCfgStart(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}
}


// end of file

