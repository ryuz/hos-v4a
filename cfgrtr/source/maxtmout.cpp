// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    HOS_MAX_TIMOUT API の処理                                               
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "maxtmout.h"
#include "analyze.h"
#include "readcfg.h"


// コンストラクタ
CApiMaxTimout::CApiMaxTimout()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParams         = 1;

	m_iMaxTimout = 0;
}


// デストラクタ
CApiMaxTimout::~CApiMaxTimout()
{
}



// APIの解析
int CApiMaxTimout::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	// API名チェック
	if ( strcmp(pszApiName, "HOS_MAX_TIMOUT") != 0 )
	{
		return CFG_ERR_NOPROC;
	}

	if ( m_iMaxTimout > 0 )
	{
		return CFG_ERR_MULTIDEF;
	}

	if ( atoi(pszParams) <= 0 )
	{
		return CFG_ERR_PARAM;
	}
	m_iMaxTimout = atoi(pszParams);

	return CFG_ERR_OK;
}


// 文字列を展開
int CApiMaxTimout::AutoId(void)
{
	return CFG_ERR_OK;
}


// cfgファイル定義部書き出し
void  CApiMaxTimout::WriteCfgDef(FILE* fp)
{
	if ( m_iMaxTimout == 0 )
	{
		m_iMaxTimout = DEFAULT_MAXTIMOUT;
	}

	fprintf(
		fp,
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*          create time-out queue             */\n"
		"/* ------------------------------------------ */\n"
		"\n"
		"T_MKNL_TIMOUT mknl_timout[%d];\n"
		"const INT     mknl_timout_size = %d;\n",
		m_iMaxTimout,
		m_iMaxTimout);
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS                                    
// ---------------------------------------------------------------------------
