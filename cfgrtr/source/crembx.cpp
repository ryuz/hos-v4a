// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター
//    CRE_MBX API の処理
//
//                                    Copyright (C) 1998-2003 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "crembx.h"
#include "analyze.h"
#include "readcfg.h"


#define CREMBX_MBXID		0
#define CREMBX_MBXATR		1
#define CREMBX_MAXPRI		2
#define CREMBX_MPRIHD		3



// コンストラクタ
CApiCreMbx::CApiCreMbx()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_MBXID;

	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 3;		// 3パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreMbx::~CApiCreMbx()
{
}



// APIの解析
int CApiCreMbx::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_MBX") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_MBXID") == 0 )
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
	else if ( strcmp(pszApiName, "KERNEL_RSV_MBXID") == 0 )
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
void CApiCreMbx::WriteId(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}

}


// cfgファイル定義部書き出し
void  CApiCreMbx::WriteCfgDef(FILE* fp)
{
	int  i;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*         create mailbox objects             */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	if ( m_iMaxId > 0 )
	{
#if _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_BLKARRAY
#if _KERNEL_MBXCB_SPLIT_RO
	// %jp{ブロック配列＆ROM分離}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_MBXCB _kernel_mbxcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteMbxcbRam(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{0},\n");
			}
		}
		fprintf(fp, "\t};\n");

		// %jp{ROM部出力}
		fprintf(fp, "\nconst _KERNEL_T_MBXCB_RO _kernel_mbxcb_ro_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteMbxcbRom(fp, iObjNum);
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
	// %jp{ブロック配列＆統合MBXCB}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_MBXCB _kernel_mbxcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteMbxcbRam(fp, iObjNum);
				WriteMbxcbRom(fp, iObjNum);
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
#elif _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_PTRARRAY
#if _KERNEL_MBXCB_SPLIT_RO
	// %jp{ポインタ配列＆ROM分離}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "const _KERNEL_T_MBXCB_RO _kernel_mbxcb_ro_blk_%d = {", m_iId[i]);
			WriteMbxcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_MBXCB _kernel_mbxcb_blk_%d = {", m_iId[i]);
			WriteMbxcbRam(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_MBXCB *_kernel_mbxcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_mbxcb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#else
	// %jp{ポインタ配列＆統合MBXCB}
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_MBXCB _kernel_mbxcb_blk_%d = {", m_iId[i]);
			WriteMbxcbRam(fp, i);
			WriteMbxcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_MBXCB *_kernel_mbxcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_mbxcb_blk_%d,\n", i);
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
		"\nconst ID	_kernel_max_mbxid = %d;\n",
		m_iMaxId);
}


void CApiCreMbx::WriteMbxcbRam(FILE *fp, int iObj)
{
#if _KERNEL_MBXCB_QUE
	fprintf(fp, "{0}, ");			/* %jp{キュー} */
#endif

#if _KERNEL_MBXCB_MSGQUE
	fprintf(fp, "NULL, ");			/* %jp{セマフォの資源数} */
#endif
}


void CApiCreMbx::WriteMbxcbRom(FILE *fp, int iObj)
{
#if _KERNEL_MBXCB_MBXATR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREMBX_MBXATR));		/* %jp{メールボックス属性} */
#endif

#if _KERNEL_MBXCB_MAXMPRI
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREMBX_MAXPRI));		/* %jp{送信されるメッセージの優先度の最大値} */
#endif
}



// %jp{cfgファイル初期化部書き出し}
void CApiCreMbx::WriteCfgIni(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}
}


// cfgファイル起動部書き出し
void  CApiCreMbx::WriteCfgStart(FILE* fp)
{
	if ( m_iMaxId <= 0 )
	{
		return;
	}
}


// end of file
