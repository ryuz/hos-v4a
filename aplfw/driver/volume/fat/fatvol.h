/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.h
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fatvol_h__
#define __HOS__fatvol_h__


#include "system/sysapi/sysapi.h"
#include "system/file/volumeobj.h"


#define FATVOL_ERR_OK		0
#define FATVOL_ERR_NG		(-1)


/* 型定義 */
typedef	int				FATVOL_ERR;
typedef	_HOS_SINT64		FATVOL_INT;
typedef _HOS_UINT64		FATVOL_UINT;

#ifdef __cplusplus
extern "C" {
#endif

HANDLE FatVol_Create(const char *pszPath);
void   FatVol_Delete(HANDLE hVolume);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__fatdrive_h__ */

