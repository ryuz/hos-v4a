
#ifndef __HOS__sysvol_local_h__
#define __HOS__sysvol_local_h__


#include "sysvolfile.h"
#include "system/file/fileobj_local.h"
#include "system/file/sysvol.h"
#include "system/sysapi/sysapi.h"



#ifdef __cplusplus
extern "C" {
#endif

void SysVolFile_Constructor(C_SYSVOLFILE *self, const T_FILEOBJ_METHODS *pMethods, struct c_sysvol *pSysVol, int iMode);
void SysVolFile_Destructor(C_SYSVOLFILE *self);

#ifdef __cplusplus
}
#endif


#endif


/* end of file */
