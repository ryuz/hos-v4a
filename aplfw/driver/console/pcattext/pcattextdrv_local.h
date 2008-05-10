/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_local.h
 * @brief %jp{PC/AT text mode driver ローカルヘッダファイル}%en{PC/AT text mode driver private header file}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pcattextdrv_local_h__
#define __HOS__pcattextdrv_local_h__


#include "pcattextdrv.h"
#include "system/file/drvobj_local.h"
#include "system/sysapi/sysapi.h"



/** %jp{ドライバクラス}%en{Device driver class} */
typedef struct c_pcattextdrv
{
	C_DRVOBJ				DrvObj;			/**< %jp{同期機能付きデバイスドライバを継承} */
	
	void					*pRegBase;
	volatile unsigned short	*puhTextVram;
	
	int						iOpenCount;		/**< %jp{オープンカウンタ} */

	unsigned char			ubCharAttr;		/**< %jp{文字属性} */

	int						iScreenWidth;
	int						iScreenHeight;
		
	int						iCursorX;
	int						iCursorY;
} C_PCATTEXTDRV;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  PcatTextDrv_Constructor(C_PCATTEXTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, void *pVramBase);	/**< %jp{コンストラクタ} */
void      PcatTextDrv_Destructor(C_PCATTEXTDRV *self);																		/**< %jp{デストラクタ} */

HANDLE    PcatTextDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      PcatTextDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  PcatTextDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  PcatTextDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE PcatTextDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE PcatTextDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  PcatTextDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      PcatTextDrv_PutChar(C_PCATTEXTDRV *self, int c);
void      PcatTextDrv_SetCursor(C_PCATTEXTDRV *self, int iX, int iY);
void      PcatTextDrv_ClearScreen(C_PCATTEXTDRV *self);


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pcattextdrv_local_h__ */


/* end of file */
