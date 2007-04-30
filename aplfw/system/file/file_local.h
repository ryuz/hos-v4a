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

#define FILE_MAX_VOLUME		16



typedef struct c_file
{
	T_FILE_VOLINF VolumeTable[FILE_MAX_VOLUME];
	HANDLE        hDevVol;
} C_FILE;

extern C_FILE	g_File;


#endif	/* __HOS__file_local_h__ */


/* end of file */
