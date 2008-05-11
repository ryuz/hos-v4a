/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.h
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__stdfile_h__
#define __HOS__stdfile_h__


#include "system/file/file.h"
#include "system/process/process.h"


#ifdef __cplusplus
extern "C" {
#endif

#define StdIo_Read(buf, len)	File_Read(Process_GetStdIn(HANDLE_NULL), (buf), (len));
#define StdIo_GetChar()			File_GetChar(Process_GetStdIn(HANDLE_NULL));
#define StdIo_GetString(str)	File_GetString(Process_GetStdIn(HANDLE_NULL), (str));

#define StdIo_Write(buf, len)	File_Write(Process_GetStdIn(HANDLE_NULL), (buf), (len));
#define StdIo_PutChar(c)		File_PutChar(Process_GetStdOut(HANDLE_NULL), (c));
#define StdIo_PutString(str)	File_PutString(Process_GetStdOut(HANDLE_NULL), (str));
int     StdIo_PrintFormat(const char *pszFormat, ...);

#define StdCon_GetCh()			Console_GetCh(Process_GetConIn(HANDLE_NULL));
#define StdCon_GetChar()		File_GetChar(Process_GetConIn(HANDLE_NULL));

#define StdCon_PutChar(c)		File_PutChar(Process_GetConOut(HANDLE_NULL), (c));
#define StdCon_PutString(str)	File_PutString(Process_GetConOut(HANDLE_NULL), (str));

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__stdfile_h__ */


/* end of file */
