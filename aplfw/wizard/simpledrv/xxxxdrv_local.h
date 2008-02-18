/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_local.h
 * @brief %jp{$OBJNAME_JP$ ローカルヘッダファイル}%en{$OBJNAME_EN$ private header file}
 *
 * $COPYRIGHT$
 */


#ifndef __ZZZZ__xxxxdrv_local_h__
#define __ZZZZ__xxxxdrv_local_h__


#include "xxxxdrv.h"
#include "system/file/drvobj_local.h"
#include "system/sysapi/sysapi.h"



/** %jp{ドライバクラス}%en{Device driver class} */
typedef struct c_xxxxdrv
{
	C_DRVOBJ		DrvObj;			/**< %jp{同期機能付きデバイスドライバを継承} */

	int				iOpenCount;		/**< %jp{オープンカウンタ} */
} C_XXXXDRV;




#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  XxxxDrv_Constructor(C_XXXXDRV *self, const T_DRVOBJ_METHODS *pMethods);		/**< %jp{コンストラクタ} */
void      XxxxDrv_Destructor(C_XXXXDRV *self);											/**< %jp{デストラクタ} */

HANDLE    XxxxDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      XxxxDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  XxxxDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  XxxxDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE XxxxDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE XxxxDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  XxxxDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

#ifdef __cplusplus
}
#endif


#endif	/* __ZZZZ__xxxxdrv_local_h__ */


/* end of file */
