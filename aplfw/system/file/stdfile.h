/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.h
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__stdfile_h__
#define __HOS__stdfile_h__

#include "system/file/file.h"
#include "system/process/process.h"


#ifdef __cplusplus
extern "C" {
#endif

#define StdIo_GetChar(c)		File_GetChar(Process_GetStdIn(), (c));
#define StdIo_GetString(str)	File_GetString(Process_GetStdIn(), (str));

#define StdIo_PutChar(c)		File_PutChar(Process_GetStdOut(), (c));
#define StdIo_PutString(str)	File_PutString(Process_GetStdOut(), (str));
int     StdIo_PrintFormat(const char *pszFormat, ...);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__stdfile_h__ */


/* end of file */
