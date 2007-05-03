/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/process/process.h"
#include "system/file/stdfile.h"


static int System_ProcessEntry(VPARAM Param);


/* システムのブート */
void System_Boot(HANDLE hTerminal, HANDLE hConsole, const char *pszCommand, int iStackSize)
{
	T_PROCESS_INF	ProcInf;

	ProcInf.hTerminal = hTerminal;
	ProcInf.hConsole  = hConsole;
	ProcInf.hStdIn    = hConsole;
	ProcInf.hStdOut   = hConsole;
	ProcInf.hStdErr   = hConsole;
	Process_CreateEx(System_ProcessEntry, (VPARAM)pszCommand, iStackSize, PROCESS_PRIORITY_NORMAL, &ProcInf);	
}


/* システムプロセス */
int System_ProcessEntry(VPARAM Param)
{
	const char	*pszCommand;
	int			iExitCode;
	
	pszCommand = (const char *)Param;
	
	/* 起動メッセージ */
	StdIo_PutString(
			"\n\n"
			"================================================================\n"
			" Hyper Operating System  Application Flamework  --Alpha version\n"
			"\n"
			"                          Copyright (C) 1998-2006 by Project HOS\n"
			"                          http://sourceforge.jp/projects/hos/\n"
			"================================================================\n"
			"\n");
	
	/* 起動 */
	Command_Execute(pszCommand, &iExitCode);
	
	return iExitCode;
}


/* end of file */
