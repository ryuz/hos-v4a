/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 *  %jp{ルートディレクトリや /dev ディレクトリなど、システム上の仮想ボリュームを管理}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__sysvolfile_h__
#define __HOS__sysvolfile_h__


#include "system/file/fileobj.h"
#include "library/container/assoc/assoc.h"

struct c_sysvol;

/* システムボリュームのディレクトリファイル */
typedef struct c_sysvolfile
{
	C_FILEOBJ	FileObj;			/* ディレクトリオブジェクトを継承 */
	ASSOC_POS	posRead;

/*	int			iReadPtr;	*/		/* リードポインタ */
} C_SYSVOLFILE;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE   SysVolFile_Create(struct c_sysvol *pSysVol, int iMode);
void     SysVolFile_Delete(HANDLE hFile);

#ifdef __cplusplus
}
#endif

#endif	/* __HOS__sysvol_h__ */



/* end of file */
