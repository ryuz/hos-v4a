// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Advance configurator
//    CRE_SEM API の処理
//
//                                    Copyright (C) 1998-2006 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "cresem.h"
#include "analyze.h"
#include "readcfg.h"


#define CRESEM_SEMID		0
#define CRESEM_SEMATR		1
#define CRESEM_SEMCNT		2
#define CRESEM_MAXSEM		3



// %jp{コンストラクタ}
CApiCreSem::CApiCreSem()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_SEMID;

	// %jp{パラメーター構文設定}
	m_iParamSyntax[0] = 0;		// %jp{単独パラメーター}
	m_iParamSyntax[1] = 3;		// %jp{3パラメーターのブロック}
	m_iParams         = 2;
}

// デストラクタ
CApiCreSem::~CApiCreSem()
{
}


// APIの解析
int CApiCreSem::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_SEM") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_SEMID") == 0 )
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
	else if ( strcmp(pszApiName, "KERNEL_RSV_SEMID") == 0 )
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
void CApiCreSem::WriteId(FILE* fp)
{
	int i;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// %jp{コメントを出力}
	fputs("\n\n/* Semaphore object ID definetion */\n\n", fp);


	// %jp{ID定義を出力}
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CRESEM_SEMID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CRESEM_SEMID),
				m_iId[i]);
		}
	}

	// %jp{ID最大値定義を出力}
	fprintf( fp,
		"\n"
		"#ifdef  TMAX_SEMID\n"
		"#undef  TMAX_SEMID\n"
		"#endif\n"
		"\n"
		"#define TMAX_SEMID\t\t%d\n\n", m_iMaxId );
}


// cfgファイル定義部書き出し
void  CApiCreSem::WriteCfgDef(FILE* fp)
{
	int  i;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// %jp{コメント出力}
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*         create semaphore objects           */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	if ( m_iMaxId > 0 )
	{
#if _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_BLKARRAY
#if _KERNEL_SEMCB_SPLIT_RO
	// %jp{ブロック配列＆ROM分離}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_SEMCB _kernel_semcb_tbl[%d] =\n\t{\n", m_iMaxId);
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
		fprintf(fp, "\nconst _KERNEL_T_SEMCB_RO _kernel_semcb_ro_tbl[%d] =\n\t{\n", m_iMaxId);
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
	// %jp{ブロック配列＆統合SEMCB}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_SEMCB _kernel_semcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteSemcbRam(fp, iObjNum);
				WriteSemcbRom(fp, iObjNum);
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
#elif _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_PTRARRAY
#if _KERNEL_SEMCB_SPLIT_RO
	// %jp{ポインタ配列＆ROM分離}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "const _KERNEL_T_SEMCB_RO _kernel_semcb_ro_blk_%d = {", m_iId[i]);
			WriteSemcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_SEMCB _kernel_semcb_blk_%d = {", m_iId[i]);
			WriteSemcbRam(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_SEMCB *_kernel_semcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_semcb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#else
	// %jp{ポインタ配列＆統合SEMCB}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_SEMCB _kernel_semcb_blk_%d = {", m_iId[i]);
			WriteSemcbRam(fp, i);
			WriteSemcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_SEMCB *_kernel_semcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_semcb_blk_%d,\n", i);
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
		"\nconst ID	_kernel_max_semid = %d;\n",
		m_iMaxId);
}


void CApiCreSem::WriteSemcbRam(FILE *fp, int iObj)
{
#if _KERNEL_SEMCB_QUE
	fprintf(fp, "{0}, ");														/* %jp{キュー} */
#endif

#if _KERNEL_SEMCB_SEMCNT
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRESEM_SEMCNT));		/* %jp{セマフォの資源数} */
#endif
}


void CApiCreSem::WriteSemcbRom(FILE *fp, int iObj)
{
#if _KERNEL_SEMCB_SEMATR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRESEM_SEMATR));		/* %jp{セマフォ属性} */
#endif

#if _KERNEL_SEMCB_MAXSEM
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRESEM_MAXSEM));		/* %jp{セマフォの最大資源数} */
#endif
}



// cfgファイル初期化部書き出し
void  CApiCreSem::WriteCfgIni(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}

#if _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_PTRARRAY && _KERNEL_SEMCB_SPLIT_RO
	if ( m_iObjs <= 0 )
	{
		return;
	}

	fprintf(fp, "\n\t/* semaphores */\n");
	for ( int i = 0; i < m_iObjs; i++ )
	{
		fprintf(fp, "\t_kernel_semcb_blk_%d.semcb_ro = &_kernel_semcb_ro_blk_%d;\n", m_iId[i], m_iId[i]);
	}
#endif
}


// cfgファイル起動部書き出し
void  CApiCreSem::WriteCfgStart(FILE* fp)
{
}


// end of file
