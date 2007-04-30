/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバオブジェクトの基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__drvobj_h__
#define __HOS__drvobj_h__


#include "system/file/fileobj.h"

struct c_drvobj;

/* デバイスドライバオブジェクト基本クラス メソッドテーブル */
typedef struct t_drvobj_methods
{
	HANDLE    (*pfncOpen)(struct c_drvobj *self, const char *pszPath, int iMode);
	FILE_ERR  (*pfncClose)(struct c_drvobj *self, C_FILEOBJ *pFileObj);
	FILE_ERR  (*pfncIoControl)(struct c_drvobj *self, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
	FILE_POS  (*pfncSeek)(struct c_drvobj *self, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
	FILE_SIZE (*pfncRead)(struct c_drvobj *self, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
	FILE_SIZE (*pfncWrite)(struct c_drvobj *self, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
	FILE_ERR  (*pfncFlush)(struct c_drvobj *self, C_FILEOBJ *pFileObj);
} T_DRVOBJ_METHODS;


/* デバイスドライバオブジェクト基本クラス */
typedef struct c_drvobj
{
	const T_DRVOBJ_METHODS *pMethods;
} C_DRVOBJ;


#ifdef __cplusplus
extern "C" {
#endif

void     DrvObj_Create(C_DRVOBJ *self, const T_DRVOBJ_METHODS *pMethods);		/**< コンストラクタ */
void     DrvObj_Delete(C_DRVOBJ *self);											/**< デストラクタ */

#define  DrvObj_Open(self, pszPath, iMode)				((self)->pMethods->pfncOpen((self), (pszPath), (iMode)))
#define  DrvObj_Close(self, pFileObj)					((self)->pMethods->pfncClose((self), (pFileObj)))
#define  DrvObj_IoControl(self, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize)	\
														((self)->pMethods->pfncIoControl((self), (pFileObj), (iFunc), (pInBuf), (InSize), (pOutBuf), (OutSize)))
#define  DrvObj_Seek(self, pFileObj, Offset, iOrign)	((self)->pMethods->pfncSeek((self), (pFileObj), (Offset), (iOrign)))
#define  DrvObj_Read(self, pFileObj, pBuf, Size)		((self)->pMethods->pfncRead((self), (pFileObj), (pBuf), (Size)))
#define  DrvObj_Write(self, pFileObj, pData, Size)		((self)->pMethods->pfncWrite((self), (pFileObj), (pData), (Size)))
#define  DrvObj_Flush(self, pFileObj)					((self)->pMethods->pfncFlush((self), (pFileObj)))

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvobj_h__ */


/* end of file */
