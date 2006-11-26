// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Advance コンフィギュレーター                           
//    KERNEL_DPC_QUE API の処理                                                  
//                                                                            
//                                    Copyright (C) 1998-2006 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "dpcque.h"
#include "analyze.h"
#include "readcfg.h"


#define DPCQUE_QUECNT		0
#define DPCQUE_QUE			1


// コンストラクタ
CApiDpcQue::CApiDpcQue()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParams = 2;
}


// デストラクタ
CApiDpcQue::~CApiDpcQue()
{
}


// 自動ID番号割り当て
int CApiDpcQue::AutoId(void)
{
	return CFG_ERR_OK;
}


// APIの解析
int CApiDpcQue::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "KERNEL_DPC_QUE") == 0 )
	{
		if ( m_iObjs > 0 )
		{
			return CFG_ERR_MULTIDEF;
		}

		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// cfgファイル定義部書き出し
void  CApiDpcQue::WriteCfgDef(FILE* fp)
{
	const char* pszQue;
	const char* pszQueCnt;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*                 DPC queue                  */\n"
		"/* ------------------------------------------ */\n\n"
		, fp);

	// パラメータ読み出し
	if ( m_iObjs > 0 )
	{
		pszQueCnt = m_pParamPacks[0]->GetParam(DPCQUE_QUECNT);
		pszQue    = m_pParamPacks[0]->GetParam(DPCQUE_QUE);
	}
	else
	{
		pszQueCnt = "32";		// 指定が無ければデフォルトサイズ
		pszQue    = "NULL";		// 指定が無ければNULL(自動生成)
	}

	if ( strcmp(pszQue, "NULL") == 0 )
	{
		fprintf(
			fp,
			"VP_INT _kernel_dpc_queblk[(%s)];\n\n",
			pszQueCnt);
	}
}


// cfgファイル起動部書き出し
void  CApiDpcQue::WriteCfgIni(FILE* fp)
{
	const char* pszQue;
	const char* pszQueCnt;

	// パラメータ読み出し
	if ( m_iObjs > 0 )
	{
		pszQueCnt = m_pParamPacks[0]->GetParam(DPCQUE_QUECNT);
		pszQue    = m_pParamPacks[0]->GetParam(DPCQUE_QUE);
	}
	else
	{
		pszQueCnt = "32";		// 指定が無ければデフォルトサイズ
		pszQue    = "NULL";		// 指定が無ければNULL(自動生成)
	}
	
	if ( strcmp(pszQue, "NULL") == 0 )
	{
		fprintf(
			fp,
			"\n\t_KERNEL_SYS_INI_DPC((VP)(_kernel_dpc_queblk), (UINT)sizeof(_kernel_dpc_queblk) / szieof(VP_INT));\n");
	}
	else
	{
		fprintf(
			fp,
			"\n\t_KERNEL_SYS_INI_DPC((VP)(%s), (UINT)(%s));\n",
			pszQue, pszQueCnt);
	}
}


// end of file
