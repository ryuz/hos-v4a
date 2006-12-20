// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    HOS_KERNEL_HEAP API の処理                                              
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "knlheap.h"
#include "analyze.h"
#include "readcfg.h"

#define KNLHEP_HEPSZ		0
#define KNLHEP_HEP			1

// コンストラクタ
CApiKernelHeap::CApiKernelHeap()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParams = 2;
}


// デストラクタ
CApiKernelHeap::~CApiKernelHeap()
{
}


// 自動ID番号割り当て
int CApiKernelHeap::AutoId(void)
{
	return CFG_ERR_OK;
}


// APIの解析
int CApiKernelHeap::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "KERNEL_HEP_MEM") == 0 )
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
void  CApiKernelHeap::WriteCfgDef(FILE* fp)
{
	if ( m_iObjs <= 0 )
	{
		return;
	}

	if ( strcmp(m_pParamPacks[0]->GetParam(0), "0") == 0 )
	{
		return;
	}

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*                kernel heap                 */\n"
		"/* ------------------------------------------ */\n\n"
		, fp);

	// ヒープ領域生成
	if ( strcmp(m_pParamPacks[0]->GetParam(KNLHEP_HEP), "NULL") == 0 )
	{
		fprintf( 
			fp,
			"VP_INT _kernel_hep_memblk[((%s) + sizeof(VP_INT) - 1) / sizeof(VP_INT)];\n",
			m_pParamPacks[0]->GetParam(KNLHEP_HEPSZ));
	}
}


// cfgファイル起動部書き出し
void  CApiKernelHeap::WriteCfgIni(FILE* fp)
{
	if ( m_iObjs <= 0 )
	{
		return;
	}
	
	if ( strcmp(m_pParamPacks[0]->GetParam(KNLHEP_HEPSZ), "0") == 0 )
	{
		return;
	}
	
	if ( strcmp(m_pParamPacks[0]->GetParam(KNLHEP_HEP), "NULL") == 0 )
	{
		fputs("\t_KERNEL_SYS_INI_HEP(sizeof(_kernel_hep_memblk), _kernel_hep_memblk);\n", fp);
	}
	else
	{
		fprintf(fp,
			"\t_KERNEL_SYS_INI_HEP((SIZE)(%s), (VP)(%s));\n",
			m_pParamPacks[0]->GetParam(KNLHEP_HEPSZ),
			m_pParamPacks[0]->GetParam(KNLHEP_HEP));
	}
}



// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2006 by Project HOS                                    
// ---------------------------------------------------------------------------
