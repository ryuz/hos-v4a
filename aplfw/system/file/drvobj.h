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


#include "system/file/file.h"


struct c_drvobj;

/* デバイスドライバオブジェクト基本クラス メソッドテーブル */
typedef struct t_drvobj_methods
{
	T_HANDLEOBJ_METHODS HandlObjMethods;
	FILE_ERR  (*pfncClose)(struct c_drvobj *self, HANDLE hFile);
	FILE_ERR  (*pfncIoControl)(struct c_drvobj *self, HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
	FILE_POS  (*pfncSeek)(struct c_drvobj *self, HANDLE hFile, FILE_POS Offset, int iOrign);
	FILE_SIZE (*pfncRead)(struct c_drvobj *self, HANDLE hFile, void *pBuf, FILE_SIZE Size);
	FILE_SIZE (*pfncWrite)(struct c_drvobj *self, HANDLE hFile, const void *pData, FILE_SIZE Size);
	FILE_ERR  (*pfncFlush)(struct c_drvobj *self, HANDLE hFile);
} T_DRVOBJ_METHODS;


/* デバイスドライバオブジェクト基本クラス */
typedef struct c_drvobj
{
	const T_DRVOBJ_METHODS *pMethods;
} C_DRVOBJ;


#ifdef __cplusplus
extern "C" {
#endif

void    DrvObj_Create(C_DRVOBJ *self, const T_DRVOBJ_METHODS *pMethods);		/**< コンストラクタ */
void    DrvObj_Delete(C_DRVOBJ *self);											/**< デストラクタ */

HANDLE  DrvObj_Open(C_DRVOBJ *self, int iMode);
#define DrvObj_Close(self, hFile)						(self)->pMethods->pfncClose((self), (hFile))
#define DrvObj_IoControl(self, hFile, iFunc, pInBuf, InSize, pOutBuf, OutSize)	\
														(self)->pMethods->pfncIoControl((self), (hFile), (iFunc), (pInBuf), (InSize), (pOutBuf), (OutSize))
#define DrvObj_Seek(self, hFile, Offset, iOrign)		(self)->pMethods->pfncSeek((self), (hFile), (Offset), (iOrign))
#define DrvObj_Read(self, hFile, pBuf, Size)			(self)->pMethods->pfncRead((self), (hFile), (pBuf), (Size))
#define DrvObj_Write(self, hFile, pData, Size)			(self)->pMethods->pfncWrite((self), (hFile), (pData), (Size))	
#define DrvObj_Flush(self, hFile)						(self)->pMethods->pfncFlush((self), (hFile))


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvobj_h__ */


/* end of file */
