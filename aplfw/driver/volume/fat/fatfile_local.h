/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.h
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fatfile_local_h__
#define __HOS__fatfile_local_h__


#include "fatfile.h"
#include "system/sysapi/sysapi.h"


#ifdef __cplusplus
extern "C" {
#endif

void  FatFile_Constructor(C_FATFILE *self, const T_FILEOBJ_METHODS *pMethods, C_FATVOL *pFatVol, FATVOL_UINT uiStartCluster, FATVOL_UINT uiDirCluster, FATVOL_UINT uiDirEntryPos, FILE_POS FileSize, int iMode);
void  FatFile_Destructor(C_FATFILE *self);

#ifdef __cplusplus
}
#endif



#endif	/*  __HOS__fatfile_local_h__ */


/* end of file */
