// ---------------------------------------------------------------------------
//  Hyper Operating System V4a  コンフィギュレーター
//    DEF_INH API の処理
//
//                                    Copyright (C) 1998-2011 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "definh.h"
#include "analyze.h"
#include "readcfg.h"


#define DEFINH_INHNO		0
#define DEFINH_INHATR		1
#define DEFINH_INTHDR		2


// %jp{コンストラクタ}
CApiDefInh::CApiDefInh()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 2;		// 2個のパラメーターブロック
	m_iParams         = 2;
}


// %jp{デストラクタ}
CApiDefInh::~CApiDefInh()
{
}


// %jp{APIの解析}
int CApiDefInh::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "DEF_INH") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// %jp{文字列を展開}
int CApiDefInh::AutoId(void)
{
	return CFG_ERR_OK;
}


// %jp{cfgファイル定義部書き出し}
void  CApiDefInh::WriteCfgDef(FILE* fp)
{
#if !(defined(_KERNEL_PROCATR_ARM_ARMV6M) || defined(_KERNEL_PROCATR_ARM_ARMV7M))
	int i, j;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        define interrupt handler            */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	fprintf(fp,
		"\n\n"
#if !_KERNEL_SPT_DEF_INH
		"const "
#endif
		"_KERNEL_T_INHINF _kernel_inh_tbl[%d] =\n"
		"\t{\n",
		_KERNEL_TMAX_INH_INHNO - _KERNEL_TMIN_INH_INHNO + 1);

	for ( i = _KERNEL_TMIN_INH_INHNO; i <= _KERNEL_TMAX_INH_INHNO; i++ )
	{
		for ( j = 0; j < m_iObjs; j++ )
		{
			if ( atoi(m_pParamPacks[j]->GetParam(DEFINH_INHNO)) == i )
			{
				break;
			}
		}
		if ( j < m_iObjs )
		{
			fprintf(fp, "\t\t{(FP)(%s)},\n", m_pParamPacks[j]->GetParam(DEFINH_INTHDR));
		}
		else
		{
			fprintf(fp, "\t\t{(FP)NULL},\n");
		}
	}
	fprintf(fp, "\t};\n\n");

#endif
}


// %jp{cfgファイル定義部書き出し}
void  CApiDefInh::WriteCfgStart(FILE* fp)
{
}


void  CApiDefInh::WriteVecter(FILE* fp, CApiIntStack *pIntStack)
{
#if defined(_KERNEL_PROCATR_ARM_ARMV6M) || defined(_KERNEL_PROCATR_ARM_ARMV7M)
	int i, j;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        define interrupt handler            */\n"
		"/* ------------------------------------------ */\n\n"
		, fp);

	pIntStack->WriteStackMemory(fp);

	fprintf(fp,
		"\n\n"
#if !_KERNEL_SPT_DEF_INH
		"const "
#endif
		"_KERNEL_T_INHINF _kernel_inh_tbl[%d] =\n"
		"\t{\n",
		_KERNEL_TMAX_INH_INHNO - _KERNEL_TMIN_INH_INHNO + 1);

	for ( i = _KERNEL_TMIN_INH_INHNO; i <= _KERNEL_TMAX_INH_INHNO; i++ )
	{
		switch ( i )
		{
		case 0:
			fprintf(fp, "\t\t{(FP)(");
			pIntStack->WriteStackPointer(fp);
			fprintf(fp, ")},\t\t/* stack pointer */\n");
			break;

		case 1:
			fprintf(fp, "\t\t{(FP)(_kernel_reset_handler)},\t\t/* reset handler */\n");
			break;

		case 2:
			fprintf(fp, "\t\t{(FP)(_kernel_nmi_handler)},\t\t/* non maskable intterupt handler */\n");
			break;

		case 3:
			fprintf(fp, "\t\t{(FP)(_kernel_hw_fault_handler)},\t\t/* hard fault handler */\n");
			break;

		case 14:
			fprintf(fp, "\t\t{(FP)(_kernel_pendsv_handler)},\t\t/* hard fault handler */\n");
			break;

		default:
			for ( j = 0; j < m_iObjs; j++ )
			{
				if ( atoi(m_pParamPacks[j]->GetParam(DEFINH_INHNO)) == i )
				{
					break;
				}
			}
			if ( j < m_iObjs )
			{
				fprintf(fp, "\t\t{(FP)(%s)},\n", m_pParamPacks[j]->GetParam(DEFINH_INTHDR));
			}
			else
			{
				fprintf(fp, "\t\t{(FP)NULL},\n");
			}
			break;
		}
	}
	fprintf(fp, "\t};\n\n");

#endif
}



// ---------------------------------------------------------------------------
//  end of file
// ---------------------------------------------------------------------------
