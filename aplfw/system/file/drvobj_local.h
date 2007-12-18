/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバオブジェクトの基本クラス ローカルメンバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__drvobj_local_h__
#define __HOS__drvobj_local_h__


#include "drvobj.h"
#include "system/handle/handleobj_local.h"


#ifdef __cplusplus
extern "C" {
#endif

void      DrvObj_Constructor(C_DRVOBJ *self, const T_DRVOBJ_METHODS *pMethods);		/**< コンストラクタ */
void      DrvObj_Destructor(C_DRVOBJ *self);										/**< デストラクタ */

HANDLE    DrvObj_Open(C_DRVOBJ *self, const char *pszPath, int iMode);
void      DrvObj_Close(C_DRVOBJ *self, struct c_fileobj *pFileObj);
FILE_ERR  DrvObj_IoControl(C_DRVOBJ *self, struct c_fileobj *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  DrvObj_Seek(C_DRVOBJ *self, struct c_fileobj *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE DrvObj_Read(C_DRVOBJ *self, struct c_fileobj *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE DrvObj_Write(C_DRVOBJ *self, struct c_fileobj *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  DrvObj_Flush(C_DRVOBJ *self, struct c_fileobj *pFileObj);


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvobj_local_h__ */


/* end of file */
