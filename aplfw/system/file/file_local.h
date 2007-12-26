/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.h
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__file_local_h__
#define __HOS__file_local_h__


#include "file.h"
#include "sysvol.h"


typedef struct c_file
{
	HANDLE	hRootVol;		/**< ルートボリューム(ルートディレクトリ) */
	HANDLE	hDevVol;		/**< デバイスボリューム(/dev ディレクトリ) */
} C_FILE;

extern C_FILE	g_File;


#endif	/* __HOS__file_local_h__ */


/* end of file */
