
#ifndef __HOS__sysvol_local_h__
#define __HOS__sysvol_local_h__


#include "sysvol.h"
#include "system/file/fileobj.h"


/* システムボリュームのディレクトリファイル */
typedef struct c_sysvoldir
{
	C_FILEOBJ	FileObj;			/* ディレクトリオブジェクトを継承 */
	
	int			iReadPtr;		/* リードポインタ */
} C_SYSVOLDIR;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE    SysVol_Open(struct c_drvobj *self, const char *pszPath, int iMode);		/* ファイルを開く */
void      SysVol_Close(struct c_drvobj *self, struct c_fileobj *pFileObj);
FILE_ERR  SysVol_IoControl(struct c_drvobj *self, struct c_fileobj *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);

#ifdef __cplusplus
}
#endif


#endif
