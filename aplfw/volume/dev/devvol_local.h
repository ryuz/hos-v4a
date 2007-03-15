
#ifndef __HOS__devvol_local_h__
#define __HOS__devvol_local_h__


#include "devvol.h"

#ifdef __cplusplus
extern "C" {
#endif

void   DevVol_Delete(HANDLE hVolume);
HANDLE DevVol_OpenFile(HANDLE hVolume, const char *pszPath, int iMode);		/* ファイルを開く */

#ifdef __cplusplus
}
#endif


#endif
