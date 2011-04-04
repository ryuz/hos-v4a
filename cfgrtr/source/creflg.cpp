// ---------------------------------------------------------------------------
//  Hyper Operating System V4a  コンフィギュレーター
//    CRE_FLG API の処理
//
//                                    Copyright (C) 1998-2009 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "creflg.h"
#include "analyze.h"
#include "readcfg.h"


#define CREFLG_FLGID		0
#define CREFLG_FLGATR		1
#define CREFLG_IFLGPTN		2



// コンストラクタ
CApiCreFlg::CApiCreFlg()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_FLGID;

	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 2;		// 2パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreFlg::~CApiCreFlg()
{
}


// APIの解析
int CApiCreFlg::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_FLG") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_FLGID") == 0 )
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
	else if ( strcmp(pszApiName, "KERNEL_RSV_FLGID") == 0 )
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
void CApiCreFlg::WriteId(FILE* fp)
{
	int i;

	if ( m_iMaxId <= 0 )
	{
		return;
	}

	// %jp{コメントを出力}
	fputs("\n\n/* event flag ID definetion */\n", fp);

	// %jp{ID定義を出力}
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CREFLG_FLGID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CREFLG_FLGID),
				m_iId[i]);
		}
	}

	// %jp{ID最大値定義を出力}
	fprintf( fp,
		"\n"
		"#ifdef  TMAX_FLGID\n"
		"#undef  TMAX_FLGID\n"
		"#endif\n"
		"\n"
		"#define TMAX_FLGID\t\t%d\n\n", m_iMaxId);
}


// cfgファイル定義部書き出し
void  CApiCreFlg::WriteCfgDef(FILE* fp)
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
		"/*        create eventflag objects            */\n"
		"/* ------------------------------------------ */\n"
		, fp);


	if ( m_iMaxId > 0 )
	{
#if _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_BLKARRAY
#if _KERNEL_FLGCB_ROM
	// %jp{ブロック配列＆ROM分離}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_FLGCB _kernel_flgcb_tbl[%d] =\n\t{\n", m_iMaxId);
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
				fprintf(fp, "\t\t{{0}, },\n");
			}
		}
		fprintf(fp, "\t};\n");

		// %jp{ROM部出力}
		fprintf(fp, "\nconst _KERNEL_T_FLGCB_ROM _kernel_flgcb_rom_tbl[%d] =\n\t{\n", m_iMaxId);
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
	// ブロック配列＆統合TCB
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_FLGCB _kernel_flgcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteFlgcbRam(fp, iObjNum);
				WriteFlgcbRom(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{0},\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#endif
#elif _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_PTRARRAY
#if _KERNEL_FLGCB_ROM
	// ポインタ配列＆ROM分離
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "const _KERNEL_T_FLGCB_RO _kernel_flgcb_ro_blk_%d = {", m_iId[i]);
			WriteFlgcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_FLGCB _kernel_flgcb_blk_%d = {", m_iId[i]);
			WriteFlgcbRam(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_FLGCB *_kernel_flgcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_flgcb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");		}
#else
	// ポインタ配列＆統合FLGCB
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_FLGCB _kernel_flgcb_blk_%d = {", m_iId[i]);
			WriteFlgcbRam(fp, i);
			WriteFlgcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_FLGCB *_kernel_flgcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_flgcb_blk_%d,\n", i);
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
		"\nconst ID	_kernel_max_flgid = %d;\n",
		m_iMaxId);
}



void CApiCreFlg::WriteFlgcbRam(FILE *fp, int iObj)
{
#if _KERNEL_FLGCB_QUE
	fprintf(fp, "{0}, ");														/* %jp{キュー} */
#endif

#if _KERNEL_FLGCB_FLGPTN
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREFLG_IFLGPTN));		/* %jp{} */
#endif
}


void CApiCreFlg::WriteFlgcbRom(FILE *fp, int iObj)
{
#if _KERNEL_FLGCB_FLGATR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CREFLG_FLGATR));		/* %jp{イベントフラグ属性} */
#endif
}



// cfgファイル初期化部書き出し
void  CApiCreFlg::WriteCfgIni(FILE* fp)
{
}


// cfgファイル起動部書き出し
void  CApiCreFlg::WriteCfgStart(FILE* fp)
{
}


// end of file
