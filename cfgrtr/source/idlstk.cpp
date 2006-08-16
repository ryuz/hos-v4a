// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    HOS_IDL_STK API の処理                                                  
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "idlstk.h"
#include "analyze.h"
#include "readcfg.h"


#define IDLSTK_STKSZ		0
#define IDLSTK_STK			1


// コンストラクタ
CApiIdleStack::CApiIdleStack()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParams = 2;
}


// デストラクタ
CApiIdleStack::~CApiIdleStack()
{
}


// 自動ID番号割り当て
int CApiIdleStack::AutoId(void)
{
	return CFG_ERR_OK;
}


// APIの解析
int CApiIdleStack::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "KERNEL_IDL_STK") == 0 )
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
void  CApiIdleStack::WriteCfgDef(FILE* fp)
{
	const char* pszSize;
	const char* pszStack;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*                 idle stack                 */\n"
		"/* ------------------------------------------ */\n\n"
		, fp);

	// パラメータ読み出し
	if ( m_iObjs > 0 )
	{
		pszSize  = m_pParamPacks[0]->GetParam(IDLSTK_STKSZ);
		pszStack = m_pParamPacks[0]->GetParam(IDLSTK_STK);
	}
	else
	{
		pszSize  = "128";		// 指定が無ければデフォルトサイズ
		pszStack = "NULL";		// 指定が無ければNULL(自動生成)
	}

	// アイドルループ用スタック出力
	if ( strcmp(pszStack, "NULL") == 0 )
	{
		fprintf(
			fp,
			"VP         _kernel_idl_stkblk[((%s) + sizeof(VP) - 1) / sizeof(VP)];\t/* idle stack block*/\n"
			"const VP   _kernel_idl_stk   = (VP)(_kernel_idl_stkblk);\t/* idle stack */\n"
			"const SIZE _kernel_idl_stksz = (SIZE)sizeof(_kernel_idl_stkblk);\t/* idle stack size */\n",
			pszSize);
	}
	else
	{
		fprintf(
			fp,
			"const VP   _kernel_idl_stk   = (VP)(%s);\t/* idle stack */\n"
			"const SIZE _kernel_idl_stksz = (SIZE)(%s);\t/* idle stack */\n",
			pszStack,pszSize);
	}
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS                                    
// ---------------------------------------------------------------------------
