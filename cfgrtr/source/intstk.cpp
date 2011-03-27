// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター
//    HOS_INT_STK API の処理
//
//                                    Copyright (C) 1998-2010 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "intstk.h"
#include "analyze.h"
#include "readcfg.h"


#define INTSTK_STKSZ		0
#define INTSTK_STK			1


#define DEFAULT_SIZE		"256"
#define DEFAULT_STACK		"NULL"


// コンストラクタ
CApiIntStack::CApiIntStack()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParams = 2;

	// スタックポインタ
	m_szStackPointer[0] = '\0';
}


// デストラクタ
CApiIntStack::~CApiIntStack()
{
}


// 自動ID番号割り当て
int CApiIntStack::AutoId(void)
{
	return CFG_ERR_OK;
}


// APIの解析
int CApiIntStack::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "KERNEL_INT_STK") == 0 )
	{
		if ( m_iObjs > 0 )
		{
			return CFG_ERR_MULTIDEF;
		}

		if ( m_szStackPointer[0] != '\0' )
		{
			return CFG_ERR_DEF_CONFLICT;
		}

		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// cfgファイル定義部書き出し
void  CApiIntStack::WriteCfgDef(FILE* fp)
{
	const char* pszSize;
	const char* pszStack;

	// パラメータ読み出し
	if ( m_iObjs <= 0 )
	{
		pszSize  = DEFAULT_SIZE;
		pszStack = DEFAULT_STACK;
	}
	else
	{
		pszSize  = m_pParamPacks[0]->GetParam(INTSTK_STKSZ);
		pszStack = m_pParamPacks[0]->GetParam(INTSTK_STK);
	}


	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*             interrupt stack                */\n"
		"/* ------------------------------------------ */\n\n"
		, fp);

	if ( strcmp(pszStack, "NULL") == 0 )
	{
		fprintf(
				fp,
				"VP       _kernel_int_stkblk[((%s) + sizeof(VP) - 1) / sizeof(VP)];\n"
				"const VP _kernel_int_isp = &_kernel_int_stkblk[((%s) + sizeof(VP) - 1) / sizeof(VP)];\n",
				pszSize, pszSize);
	}
	else
	{
		fprintf(
				fp,
				"const VP _kernel_int_isp = (VP)((VB *)(%s) + (SIZE)(%s));\n",
				pszStack, pszSize);
	}
}


// cfgファイル起動部書き出し
void CApiIntStack::WriteCfgIni(FILE* fp)
{
	const char* pszSize;
	const char* pszStack;

	// パラメータ読み出し
	if ( m_iObjs <= 0 )
	{
		pszSize  = DEFAULT_SIZE;
		pszStack = DEFAULT_STACK;
	}
	else
	{
		pszSize  = m_pParamPacks[0]->GetParam(INTSTK_STKSZ);
		pszStack = m_pParamPacks[0]->GetParam(INTSTK_STK);
	}


	if ( strcmp(pszStack, "NULL") == 0 )
	{
		fprintf(
			fp,
			"\t_KERNEL_SYS_INI_INTSTK((SIZE)sizeof(_kernel_int_stkblk), (VP)(_kernel_int_stkblk));\n");
	}
	else
	{
		fprintf(
			fp,
			"\t_KERNEL_SYS_INI_INTSTK((SIZE)(%s), (VP)(%s));\n",
			pszSize, pszStack);
	}
}

void CApiIntStack::WriteStackMemory(FILE* fp)
{
	const char* pszSize;
	const char* pszStack;

	// パラメータ読み出し
	if ( m_iObjs <= 0 )
	{
		pszSize  = DEFAULT_SIZE;
		pszStack = DEFAULT_STACK;
	}
	else
	{
		pszSize  = m_pParamPacks[0]->GetParam(INTSTK_STKSZ);
		pszStack = m_pParamPacks[0]->GetParam(INTSTK_STK);
	}

	if ( strcmp(pszStack, "NULL") == 0 )
	{
		fprintf(fp, "extern VP       _kernel_int_stkblk[((%s) + sizeof(VP) - 1) / sizeof(VP)];\n", pszSize);
	}
}


void CApiIntStack::WriteStackPointer(FILE* fp)
{
	const char* pszSize;
	const char* pszStack;

	// パラメータ読み出し
	if ( m_iObjs <= 0 )
	{
		pszSize  = DEFAULT_SIZE;
		pszStack = DEFAULT_STACK;
	}
	else
	{
		pszSize  = m_pParamPacks[0]->GetParam(INTSTK_STKSZ);
		pszStack = m_pParamPacks[0]->GetParam(INTSTK_STK);
	}

	if ( strcmp(pszStack, "NULL") == 0 )
	{
		fprintf(fp, "&_kernel_int_stkblk[((%s) + sizeof(VP) - 1) / sizeof(VP)]", pszSize);
	}
	else
	{
		fprintf(fp, "(VB *)(%s) + (SIZE)(%s)", pszStack, pszSize);
	}
}



// ---------------------------------------------------------------------------
//  end of file
// ---------------------------------------------------------------------------
