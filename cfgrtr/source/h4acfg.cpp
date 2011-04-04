/**
 *  Hyper Operating System V4 Advance Configurator
 *
 * @file  hos4cfg.cpp
 * @brief %jp{メインルーチン}%en{main}
 *
 * Copyright (C) 1998-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readcfg.h"
#include "defercd.h"
#include "read.h"
#include "analyze.h"
#include "apiinc.h"
#include "dpcque.h"
#include "idlstk.h"
#include "intstk.h"
#include "knlheap.h"
#include "maxtpri.h"
#include "cretsk.h"
#include "deftex.h"
#include "cresem.h"
#include "creflg.h"
#include "credtq.h"
#include "crembx.h"
#include "cremtx.h"
#include "crembf.h"
#include "crempf.h"
#include "timtic.h"
#include "crecyc.h"
#include "crealm.h"
#include "definh.h"
#include "attisr.h"
#include "attini.h"
#include "defexc.h"


#define DEFAULT_INPUTFILE		"system.i"
#define DEFAULT_IDFILE			"kernel_id.h"
#define DEFAULT_CFGFILE			"kernel_cfg.c"
#define DEFAULT_VECTORFILE		"kernel_vct.c"


int  ReadConfigFile(FILE* fpConfig);	// コンフィギュレーションファイル読み込み
void WriteIdFile(FILE* fp);				// ID 定義ヘッダファイル出力
void WriteCfgFile(FILE* fp);			// C 言語ソース出力
void WriteVctFile(FILE* fp);			// C 言語ソース出力
void PrintUsage(void);


CApiInclude    g_ApiInclude;
CApiKernelHeap g_ApiKernelHeap;
CApiDpcQue     g_ApiDpcQue;
CApiIdleStack  g_ApiIdleStack;
CApiMaxTpri    g_ApiMaxTpri;
CApiIntStack   g_ApiIntStack;
CApiCreTsk     g_ApiCreTsk;
CApiDefTex     g_ApiDefTex;
CApiCreSem     g_ApiCreSem;
CApiCreFlg     g_ApiCreFlg;
CApiCreDtq     g_ApiCreDtq;
CApiCreMbx     g_ApiCreMbx;
CApiCreMtx     g_ApiCreMtx;
CApiCreMbf     g_ApiCreMbf;
CApiCreMpf     g_ApiCreMpf;
CApiTimTic     g_ApiTimTic;
CApiCreCyc     g_ApiCreCyc;
CApiCreAlm     g_ApiCreAlm;
CApiDefInh     g_ApiDefInh;
CApiAttIsr     g_ApiAttIsr;
CApiAttIni     g_ApiAttIni;
CApiDefExc     g_ApiDefExc;

static const char *s_szPhysicalInputFile  = NULL;
static const char *s_szIdFile             = DEFAULT_IDFILE;
static const char *s_szCfgFile            = DEFAULT_CFGFILE;
static const char *s_szVctFile            = DEFAULT_VECTORFILE;

// API定義リスト
static CApiDef* g_ApiList[] =
	{
		&g_ApiInclude,
		&g_ApiKernelHeap,
		&g_ApiDpcQue,
		&g_ApiIdleStack,
		&g_ApiIntStack,
		&g_ApiCreTsk,
//		&g_ApiDefTex,
		&g_ApiCreSem,
		&g_ApiCreFlg,
		&g_ApiCreDtq,
		&g_ApiCreMbx,
		&g_ApiCreMtx,
//		&g_ApiCreMbf,
		&g_ApiCreMpf,
		&g_ApiTimTic,
		&g_ApiCreCyc,
//		&g_ApiCreAlm,
		&g_ApiDefInh,
		&g_ApiAttIsr,
		&g_ApiAttIni,
//		&g_ApiDefExc,
	};

#define API_COUNT	((int)(sizeof(g_ApiList) / sizeof(CApiDef*)))		// API個数




// メイン関数
int main(int argc, char *argv[])
{
	FILE* fpInput;
	FILE* fpCfg;
	FILE* fpId;
	int  iErr;
	int  i;

	// コマンドライン解析
	for ( i = 1; i < argc; i++ )
	{
		if ( strcmp(argv[i], "-c") == 0 )
		{
			i++;
			if ( i >= argc )
			{
				fprintf(stderr, "option error \"-c\"\n");
				PrintUsage();
				return 1;
			}
			s_szCfgFile = argv[i];
		}
		else if ( strcmp(argv[i], "-i") == 0 )
		{
			i++;
			if ( i >= argc )
			{
				fprintf(stderr, "option error \"-i\"\n");
				PrintUsage();
				return 1;
			}
			s_szIdFile = argv[i];
		}
		else if ( strcmp(argv[i], "-vct") == 0 )
		{
			i++;
			if ( i >= argc )
			{
				fprintf(stderr, "option error \"-vct\"\n");
				PrintUsage();
				return 1;
			}
			s_szVctFile = argv[i];
		}
		else if ( strcmp(argv[i], "-help") == 0 )
		{
			PrintUsage();
			return 0;
		}
		else if ( argv[i][0] == '-' && argv[i][1] != '\0' )
		{
			fprintf(stderr, "unknown option \"%s\"\n", argv[i]);
			PrintUsage();
			return 1;
		}
		else
		{
			if ( s_szPhysicalInputFile != NULL )
			{
				fprintf(stderr, "too many input files\n");
				PrintUsage();
				return 1;
			}
			s_szPhysicalInputFile = argv[i];
		}
	}

	// 入力ファイル省略時のデフォルト設定
	if ( s_szPhysicalInputFile == NULL )
	{
		s_szPhysicalInputFile = DEFAULT_INPUTFILE;
	}

	// 入力ファイルオープン
	if ( strcmp(s_szPhysicalInputFile, "-") == 0) {
		s_szPhysicalInputFile = "stdin";
		fpInput = stdin;
	}
	else if ( (fpInput = fopen(s_szPhysicalInputFile, "r")) == NULL )
	{
               fprintf(stderr, "could not open file \"%s\"\n", s_szPhysicalInputFile);
		return 1;
	}

	// コンフィギュレーションファイル読み込み
	iErr = ReadConfigFile(fpInput) != 0;
	fclose(fpInput);
	if ( iErr != 0 )
	{
		return 1;
	}

	// 自動ID番号割り当て
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->AutoId();
	}

	// ID 定義ファイルオープン
	if ( (fpId = fopen(s_szIdFile, "w")) == NULL )
	{
		fprintf(stderr, "could not open file \"%s\"\n", s_szIdFile);
		return 1;
	}

	WriteIdFile(fpId);

	fclose(fpId);


	// Cfgファイルオープン
	if ( (fpCfg = fopen(s_szCfgFile, "w")) == NULL )
	{
		fprintf(stderr, "could not open file \"%s\"\n", s_szCfgFile);
		return 1;
	}

	WriteCfgFile(fpCfg);

	fclose(fpCfg);

#if defined(_KERNEL_PROCATR_ARM_ARMV6M) || defined(_KERNEL_PROCATR_ARM_ARMV7M)
	// ベクタファイルオープン
	FILE* fpVct;
	if ( (fpVct = fopen(s_szVctFile, "w")) == NULL )
	{
		fprintf(stderr, "could not open file \"%s\"\n", s_szVctFile);
		return 1;
	}
	WriteVctFile(fpVct);

	fclose(fpVct);
#endif


	return 0;
}


// コンフィギュレーションファイル読み込み
int ReadConfigFile(FILE* fpConfig)
{
	char szState[READ_MAX_STATE];
	char szApiName[READ_MAX_STATE];
	char szParams[READ_MAX_STATE];
	int  iErr;
	int  i;

	CRead read(fpConfig, s_szPhysicalInputFile);	// 読み出しオブジェクト生成

	// 読み込み
	while (	(iErr = read.ReadState(szState)) != CFG_ERR_COMPLETE )
	{
		// 読み込みエラーチェック
		if ( iErr != CFG_ERR_OK )
		{
			fprintf(stderr, "%s line(%d) : %s\n",
				read.GetLogicalInputFile(),
				read.GetLogicalLineNum(), GetErrMessage(iErr));
			return 1;
		}

		// 構文解析
		iErr = CAnalyze::SplitState(szApiName, szParams, szState);
		if ( iErr != CFG_ERR_OK )
		{
			fprintf(stderr, "%s line(%d) : %s\n",
				read.GetLogicalInputFile(),
				read.GetLogicalLineNum(), GetErrMessage(iErr));
			return 1;
		}
		CAnalyze::SpaceCut(szApiName);
		CAnalyze::SpaceCut(szParams);

		// API検索
		iErr = CFG_ERR_SYNTAX;
		for ( i = 0; i < API_COUNT; i++ )
		{
			iErr = g_ApiList[i]->AnalyzeApi(szApiName, szParams);
			if ( iErr != CFG_ERR_NOPROC )
			{
				break;
			}
		}
		if ( iErr != CFG_ERR_OK )
		{
			if ( iErr != CFG_ERR_NOPROC )
			{
				fprintf(stderr, "%s line(%d) : %s\n",
						read.GetLogicalInputFile(),
						read.GetLogicalLineNum(), GetErrMessage(iErr));
				return 1;
			}
			else
			{
				fprintf(stderr, "%s line(%d) : Warning!  Ignore unknown API(%s)\n",
						read.GetLogicalInputFile(),
						read.GetLogicalLineNum(),
						szApiName);
			}
		}
	}

	return 0;
}


// ID定義ヘッダファイル出力
void WriteIdFile(FILE* fp)
{
	int i;

	/* ヘッダ出力 */
	fputs(
		"/* ------------------------------------------------------------------------ */\n"
		"/*  HOS-V4a  kernel configuration                                           */\n"
		"/*    kernel object ID definition                                           */\n"
		"/*                                                                          */\n"
		"/* ------------------------------------------------------------------------ */\n"
		"\n\n"
		"#ifndef __KERNEL__kernel_id_h__\n"
		"#define __KERNEL__kernel_id_h__\n"
		"\n"
		, fp);

	// ID 定義ファイル出力
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->WriteId(fp);
	}

	// フッタ出力
	fputs(
		"\n\n\n"
		"#endif\t/* __KERNEL__kernel_id_h__ */\n"
		"\n\n"
		"/* ------------------------------------------------------------------------ */\n"
		"/*  End of file                                                             */\n"
		"/* ------------------------------------------------------------------------ */\n"
		, fp);
}


// C 言語ソース出力
void WriteCfgFile(FILE* fp)
{
	int i;

	/* ヘッダ出力 */
	fprintf(
		fp,
		"/* ------------------------------------------------------------------------ */\n"
		"/*  HOS-V4a  kernel configuration                                           */\n"
		"/*    kernel object create and initialize                                   */\n"
		"/*                                                                          */\n"
		"/* ------------------------------------------------------------------------ */\n"
		"\n\n");

	fprintf(fp, "#include \"kernel.h\"\n");
	fprintf(fp, "#include \"arch/proc/%s/procatr.h\"\n", _KERNEL_PROCATR_INC_PATH);
	fprintf(fp, "#include \"arch/proc/%s/proc.h\"\n",    _KERNEL_PROCATR_INC_PATH);
	fprintf(fp, "#include \"arch/irc/%s/ircatr.h\"\n",   _KERNEL_IRCATR_INC_PATH);
	fprintf(fp, "#include \"arch/irc/%s/irc.h\"\n",      _KERNEL_IRCATR_INC_PATH);
	fprintf(fp, "#include \"config/cfgknl.h\"\n");
	fprintf(fp, "#include \"parser/parsknl.h\"\n");
	fprintf(fp, "#include \"core/objid.h\"\n");
	fprintf(fp, "#include \"core/objhdl.h\"\n");
	fprintf(fp, "#include \"object/tskobj.h\"\n");
	fprintf(fp, "#include \"object/semobj.h\"\n");
	fprintf(fp, "#include \"object/flgobj.h\"\n");
	fprintf(fp, "#include \"object/dtqobj.h\"\n");
	fprintf(fp, "#include \"object/mbxobj.h\"\n");
	fprintf(fp, "#include \"object/mtxobj.h\"\n");
	fprintf(fp, "#include \"object/mpfobj.h\"\n");
	fprintf(fp, "#include \"object/inhobj.h\"\n");
	fprintf(fp, "#include \"object/isrobj.h\"\n");
	fprintf(fp, "#include \"object/cycobj.h\"\n");

//	fprintf(fp, "#include \"%s\"\n", s_szIdFile);
	fprintf(fp, "#include \"kernel_id.h\"\n");


	// 定義部出力
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->WriteCfgDef(fp);
	}

	// 初期化関数コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*          initialize functions              */\n"
		"/* ------------------------------------------ */\n",
		fp);

	// 初期化関数出力
	fputs(
		"\n/* object initialize */\n"
		"void _kernel_cfg_ini(void)\n"
		"{\n",
		fp);
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->WriteCfgIni(fp);
	}
	fputs("}\n", fp);

	// 初期化関数出力
	fputs(
		"\n/* start up */\n"
		"void _kernel_cfg_sta(void)\n"
		"{\n",
		fp);
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->WriteCfgStart(fp);
	}
	fputs("}\n", fp);

	// フッタ出力
	fputs(
		"\n\n"
		"/* ------------------------------------------------------------------------ */\n"
		"/*  End of file                                                             */\n"
		"/* ------------------------------------------------------------------------ */\n"
		, fp);
}



// C 言語ソース出力
void WriteVctFile(FILE* fp)
{
	/* ヘッダ出力 */
	fprintf(
		fp,
		"/* ------------------------------------------------------------------------ */\n"
		"/*  HOS-V4a  kernel configuration                                           */\n"
		"/*                                                                          */\n"
		"/* ------------------------------------------------------------------------ */\n"
		"\n\n");

	fprintf(fp, "#include \"kernel.h\"\n");
	fprintf(fp, "#include \"arch/proc/%s/procatr.h\"\n", _KERNEL_PROCATR_INC_PATH);
	fprintf(fp, "#include \"arch/proc/%s/proc.h\"\n",    _KERNEL_PROCATR_INC_PATH);
	fprintf(fp, "#include \"arch/irc/%s/ircatr.h\"\n",   _KERNEL_IRCATR_INC_PATH);
	fprintf(fp, "#include \"arch/irc/%s/irc.h\"\n",      _KERNEL_IRCATR_INC_PATH);
	fprintf(fp, "#include \"config/cfgknl.h\"\n");
	fprintf(fp, "#include \"parser/parsknl.h\"\n");
	fprintf(fp, "#include \"core/objid.h\"\n");
	fprintf(fp, "#include \"core/objhdl.h\"\n");
	fprintf(fp, "#include \"object/tskobj.h\"\n");
	fprintf(fp, "#include \"object/semobj.h\"\n");
	fprintf(fp, "#include \"object/flgobj.h\"\n");
	fprintf(fp, "#include \"object/dtqobj.h\"\n");
	fprintf(fp, "#include \"object/mbxobj.h\"\n");
	fprintf(fp, "#include \"object/mtxobj.h\"\n");
	fprintf(fp, "#include \"object/mpfobj.h\"\n");
	fprintf(fp, "#include \"object/inhobj.h\"\n");
	fprintf(fp, "#include \"object/isrobj.h\"\n");
	fprintf(fp, "#include \"object/cycobj.h\"\n");
	fprintf(fp, "#include \"kernel_id.h\"\n");

	g_ApiInclude.WriteCfgDef(fp);
	g_ApiDefInh.WriteVecter(fp, &g_ApiIntStack);

	// フッタ出力
	fputs(
		"\n\n"
		"/* ------------------------------------------------------------------------ */\n"
		"/*  End of file                                                             */\n"
		"/* ------------------------------------------------------------------------ */\n"
		, fp);
}


// 使い方表示
void PrintUsage(void)
{
       fprintf(stderr,
               "usage: hos4cfg [options] [input-file]\n"
               "options are:\n"
               "   -i FILE    specify auto-assginment headerfile (default: " DEFAULT_IDFILE ")\n"
               "   -c FILE    specify kernel configuration file  (default: " DEFAULT_CFGFILE ")\n"
               "   -help      show this help\n"
               "\n"
               "input-file (default: " DEFAULT_INPUTFILE ")\n");
}


// end of file
