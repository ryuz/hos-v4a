/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__system_h__
#define __HOS__system_h__


#include "system/type/type.h"


#ifdef __cplusplus
extern "C" {
#endif

void System_Initialize(void *pMem, MEMSIZE Size);
void System_Boot(HANDLE hTerminal, HANDLE hConsole, const char *pszCommand, int iStackSize);
int  System_RequestProc(void (*pfncProc)(VPARAM Param1, VPARAM Param2), VPARAM Param1, VPARAM Param2);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__system_h__ */


/* end of file */
