// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Advance Configulator
//    CRE_TSK API
//
//                                    Copyright (C) 1998-2006 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "cretsk.h"
#include "analyze.h"
#include "readcfg.h"

// parameter
#define CRETSK_TSKID		0
#define CRETSK_TSKATR		1
#define CRETSK_EXINF		2
#define CRETSK_TASK			3
#define CRETSK_ITSKPRI		4
#define CRETSK_STKSZ		5
#define CRETSK_STK			6



// %jp{コンストラクタ}%en{constructor}
CApiCreTsk::CApiCreTsk()
{
	// %jp{デフォルトの最大ID設定}
	m_iDefaultMaxId = _KERNEL_DEF_TMAX_TSKID;

	// %jp{パラメーター構文設定}
	m_iParamSyntax[0] = 0;		// %jp{単独パラメーター}
	m_iParamSyntax[1] = 6;		// %jp{6パラメーターのブロック}
	m_iParams = 2;
}


// %jp{デストラクタ}%en{destructor}
CApiCreTsk::~CApiCreTsk()
{
}


// %jp{APIの解析}
int CApiCreTsk::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_TSK") == 0 )
	{
		return AddParams(pszParams);				// %jp{APIとしてパラメータ分解を行う}
	}
	else if ( strcmp(pszApiName, "KERNEL_MAX_TSKID") == 0 )
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
	else if ( strcmp(pszApiName, "KERNEL_RSV_TSKID") == 0 )
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


// %jp{ID 定義ファイル書き出し}
void CApiCreTsk::WriteId(FILE* fp)
{
	int i;

	// %jp{コメントを出力}
	fputs("\n\n/* Task object ID definetion */\n\n", fp);

	// %jp{ID定義を出力}
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CRETSK_TSKID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CRETSK_TSKID),
				m_iId[i]);
		}
	}

	// %jp{ID最大値定義を出力}
	fprintf( fp,
		"\n"
		"#ifdef  TMAX_TSKID\n"
		"#undef  TMAX_TSKID\n"
		"#endif\n"
		"\n"
		"#define TMAX_TSKID\t\t%d\n\n", m_iMaxId );
}



// %jp{cfgファイル定義部書き出し}
void CApiCreTsk::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	int         i;

	// %jp{コメント出力}
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*          create task objects               */\n"
		"/* ------------------------------------------ */\n\n"
		, fp);


	// %jp{スタック領域出力}
	for ( i = 0; i < m_iObjs; i++ )
	{
		pszParam = m_pParamPacks[i]->GetParam(CRETSK_STK);
		if ( strcmp(pszParam, "NULL") == 0 )
		{
			fprintf(
				fp,
				"static VP _kernel_tsk%d_stk[((%s) + sizeof(VP) - 1) / sizeof(VP)];\n",
				m_iId[i],
				m_pParamPacks[i]->GetParam(CRETSK_STKSZ));
		}
	}


#if _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_BLKARRAY
#if _KERNEL_TCB_SPLIT_RO
	// %jp{ブロック配列＆ROM分離}
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_TCB _kernel_tcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteTcbRam(fp, iObjNum);
				fprintf(fp, "},\n");
			}
			else
			{
				fprintf(fp, "\t\t{{0}, },\n");
			}
		}
		fprintf(fp, "\t};\n");

		// %jp{ROM部出力}
		fprintf(fp, "\nconst _KERNEL_T_TCB_RO _kernel_tcb_ro_tbl[%d] =\n\t{\n", m_iMaxId);
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
	// ブロック配列＆統合TCB
	{
		// %jp{RAM部出力}
		fprintf(fp, "\n_KERNEL_T_TCB _kernel_tcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t{");
				WriteTcbRam(fp, iObjNum);
				WriteTcbRom(fp, iObjNum);
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
#elif _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY
#if _KERNEL_TCB_SPLIT_RO
	// ポインタ配列＆ROM分離
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "const _KERNEL_T_TCB_RO _kernel_tcb_ro_blk_%d = {", m_iId[i]);
			WriteTcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_TCB _kernel_tcb_blk_%d = {", m_iId[i]);
			WriteTcbRam(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_TCB *_kernel_tcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_tcb_blk_%d,\n", i);
			}
			else
			{
				fprintf(fp, "\t\tNULL,\n");
			}
		}
		fprintf(fp, "\t};\n");
	}
#else
	// ポインタ配列＆統合TCB
	{
		fprintf(fp, "\n");
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(fp, "_KERNEL_T_TCB _kernel_tcb_blk_%d = {", m_iId[i]);
			WriteTcbRam(fp, i);
			WriteTcbRom(fp, i);
			fprintf(fp, "};\n");
		}
		fprintf(fp, "\n");
		fprintf(fp, "\n_KERNEL_T_TCB *_kernel_tcb_tbl[%d] =\n\t{\n", m_iMaxId);
		for ( i = 1; i <= m_iMaxId; i++ )
		{
			int iObjNum = IdToObjNum(i);
			if ( iObjNum >= 0 )
			{
				fprintf(fp, "\t\t&_kernel_tcb_blk_%d,\n", i);
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
		"\nconst ID	_kernel_max_tskid = %d;\n",
		m_iMaxId);
}



void CApiCreTsk::WriteTcbRam(FILE *fp, int iObj)
{
#if _KERNEL_TCB_CTXCB
	fprintf(fp, "{0}, ");				/* %jp{タスクのコンテキスト} */
#endif

#if _KERNEL_TCB_QUE
	fprintf(fp, "NULL, ");				/* %jp{属しているキュー} */
#endif

#if _KERNEL_TCB_QUEOBJ
#if _KERNEL_QUE_ALGORITHM == _KERNEL_QUE_ALG_ONEWAYLIST
	fprintf(fp, "0, ");					/* %jp{キューに接続する為のオブジェクト} */
#elif _KERNEL_QUE_ALGORITHM == _KERNEL_QUE_ALG_TWOWAYLIST
	fprintf(fp, "0, 0, ");				/* %jp{キューに接続する為のオブジェクト} */
#endif
#endif

#if _KERNEL_TCB_TOQOBJ
	fprintf(fp, "0, 0, 0, ");			/* %jp{タイムアウトキュー} */
#endif

#if _KERNEL_TCB_TSKSTAT
	fprintf(fp, "0, ");					/* %jp{タスク状態} */
#endif

#if _KERNEL_TCB_TSKPRI
	fprintf(fp, "0, ");					/* %jp{タスクの現在優先度} */
#endif

#if _KERNEL_TCB_TSKBPRI
	fprintf(fp, "0, ");					/* %jp{タスクのベース優先度} */
#endif

#if _KERNEL_TCB_TSKWAIT
	fprintf(fp, "0, ");					/* %jp{待ち要因} */
#endif

#if _KERNEL_TCB_WOBJID
	fprintf(fp, "0, ");					/* %jp{待ち対象のオブジェクトのID番号} */
#endif

#if _KERNEL_TCB_ACTCNT
	fprintf(fp, "0, ");					/* %jp{起動要求キューイング回数} */
#endif

#if _KERNEL_TCB_WUPCNT
	fprintf(fp, "0, ");					/* %jp{起床要求キューイング回数} */
#endif

#if _KERNEL_TCB_SUSCNT
	fprintf(fp, "0, ");					/* %jp{強制待ち要求ネスト回数} */
#endif

#if _KERNEL_TCB_MTXHDL
	fprintf(fp, "0, ");					/* %jp{所有するミューテックスのリスト} */
#endif

#if _KERNEL_TCB_ERCD
	fprintf(fp, "0, ");					/* ercd */
#endif

#if _KERNEL_TCB_DATA
	fprintf(fp, "0, ");					/* data */
#endif

#if _KERNEL_TCB_TSKID
	fprintf(fp, "0, ");					/* tskid */
#endif

#if _KERNEL_TCB_TEXSTAT
	fprintf(fp, "0, ");					/* texstat %jp{タスク例外処理状態} */
#endif

#if _KERNEL_TCB_RASPTN
	fprintf(fp, "0, ");					/**< rasptn %jp{タスク例外処理要因} */
#endif
}


void CApiCreTsk::WriteTcbRom(FILE *fp, int iObj)
{
#if _KERNEL_TCB_TSKATR
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRETSK_TSKATR));	/**< %jp{タスク属性} */
#endif

#if _KERNEL_TCB_EXINF	/* exinf */
	fprintf(fp, "(_KERNEL_TSK_T_EXINF)(%s), ", m_pParamPacks[iObj]->GetParam(CRETSK_EXINF));		/* %jp{タスクの拡張情報} */
#endif

#if _KERNEL_TCB_TASK
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRETSK_TASK));		/* %jp{タスクの起動番地} */
#endif

#if _KERNEL_TCB_ITSKPRI
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRETSK_ITSKPRI));	/* %jp{タスクの起動時優先度} */
#endif

#if _KERNEL_TCB_STKSZ
	fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRETSK_STKSZ));		/* %jp{タスクのスタックのサイズ（バイト数）} */
#endif

#if _KERNEL_TCB_STK
	if ( strcmp(m_pParamPacks[iObj]->GetParam(CRETSK_STK), "NULL") == 0 )
	{
		fprintf(fp, "_kernel_tsk%d_stk, ", m_iId[iObj];
	}
	else
	{
		fprintf(fp, "(%s), ", m_pParamPacks[iObj]->GetParam(CRETSK_STK));	/* %jp{タスクのスタック領域の先頭番地} */
	}
#endif

#if _KERNEL_TCB_ISP
	if ( strcmp(m_pParamPacks[iObj]->GetParam(CRETSK_STK), "NULL") == 0 )
	{
		fprintf(fp, "((VB*)_kernel_tsk%d_stk + sizeof(_kernel_tsk%d_stk)), ", m_iId[iObj], m_iId[iObj]);
	}
	else
	{
		fprintf(fp, "(VP)((VB *)(%s) + (SIZE)(%s)), ", m_pParamPacks[iObj]->GetParam(CRETSK_STK), m_pParamPacks[iObj]->GetParam(CRETSK_STKSZ));
	}
#endif

#if _KERNEL_TCB_TEXATR
	fprintf(fp, "0, ");					/**< texatr %jp{タスク例外処理ルーチン属性} */
#endif

#if _KERNEL_TCB_TEXRTN
	fprintf(fp, "0, ");					/**< texrtn %jp{タスク例外処理ルーチンの起動番地} */
#endif
}



// cfgファイル初期化部書き出し
void  CApiCreTsk::WriteCfgIni(FILE* fp)
{
#if _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY && _KERNEL_TCB_SPLIT_RO
	if ( m_iObjs <= 0 )
	{
		return;
	}

	fprintf(fp, "\n\t/* Tasks */\n");
	for ( int i = 0; i < m_iObjs; i++ )
	{
		fprintf(fp, "\t_kernel_tcb_blk_%d.tcb_ro = &_kernel_tcb_ro_blk_%d;\n", m_iId[i], m_iId[i]);
	}
#endif
}


// cfgファイル起動部書き出し
void  CApiCreTsk::WriteCfgStart(FILE* fp)
{
	int i;

	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( strstr(m_pParamPacks[i]->GetParam(CRETSK_TSKATR), "TA_ACT") != NULL )
		{
			fprintf(fp,
				"\tact_tsk(%s);\n",
				m_pParamPacks[i]->GetParam(CRETSK_TSKID));
		}
	}
}



// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2006 by Project HOS
// ---------------------------------------------------------------------------
