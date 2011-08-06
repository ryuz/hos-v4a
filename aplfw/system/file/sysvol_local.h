
#ifndef __HOS__sysvolfile_local_h__
#define __HOS__sysvolfile_local_h__


#include "sysvol.h"
#include "system/file/volumeobj_local.h"
#include "system/file/sysvolfile.h"
#include "system/sysapi/sysapi.h"




#ifdef __cplusplus
extern "C" {
#endif

void      SysVol_Constructor(C_SYSVOL *self, const T_VOLUMEOBJ_METHODS *pMethods);
void      SysVol_Destructor(C_FILEOBJ *self);

HANDLE    SysVol_Open(struct c_fileobj *self, const char *pszPath, int iMode);			/* ファイルを開く */
void      SysVol_Close(struct c_fileobj *self, struct c_fileptr *pFilePtr);
FILE_ERR  SysVol_IoControl(struct c_fileobj *self, struct c_fileptr *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);

#ifdef __cplusplus
}
#endif


#endif
