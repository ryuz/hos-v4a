/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.h
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__file_local_h__
#define __HOS__file_local_h__


#include "file.h"
#include "system/handle/handle_local.h"
/* #include "sysvol.h" */


typedef struct c_file
{
	HANDLE	hRootVol;		/**< ルートボリューム(ルートディレクトリ) */
	HANDLE	hDevVol;		/**< デバイスボリューム(/dev ディレクトリ) */
} C_FILE;

extern C_FILE	g_File;




struct c_fileobj;
struct c_fileptr;

/* デバイスドライバオブジェクト基本クラス メソッドテーブル */
typedef struct t_fileobj_methods
{
	T_OBJECT_METHODS	ObjectMethods;		/**< ハンドルオブジェクトを継承 */
	
	HANDLE    (*pfncOpen)(struct c_fileobj *self, const char *pszPath, int iMode);
	void      (*pfncClose)(struct c_fileobj *self, struct c_fileptr *pFilePtr);
	FILE_ERR  (*pfncIoControl)(struct c_fileobj *self, struct c_fileptr *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
	FILE_POS  (*pfncSeek)(struct c_fileobj *self, struct c_fileptr *pFilePtr, FILE_POS Offset, int iOrign);
	FILE_SIZE (*pfncRead)(struct c_fileobj *self, struct c_fileptr *pFilePtr, void *pBuf, FILE_SIZE Size);
	FILE_SIZE (*pfncWrite)(struct c_fileobj *self, struct c_fileptr *pFilePtr, const void *pData, FILE_SIZE Size);
	FILE_ERR  (*pfncFlush)(struct c_fileobj *self, struct c_fileptr *pFilePtr);
	FILE_ERR  (*pfncGetInformation)(struct c_fileobj *self, char *pszInformation, int iLen);
} T_FILEOBJ_METHODS;


/* デバイスドライバオブジェクト基本クラス */
typedef struct c_fileobj
{
	C_TARGETOBJ		TargetObj;				/**< 親クラスを継承 */
} C_FILEOBJ;

struct c_fileobj;


/* ファイルポインタクラス定義 */
typedef struct c_fileptr
{
	C_POINTEROBJ	PointerObj;				/* 親クラスを継承 */
	
	int				iMode;					/* オープン時のモード */
	void			*pReadBuf;				/* リードバッファ */
	void			*pWriteBuf;				/* ライトバッファ */	
} C_FILEPTR;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE    FileObj_Create(const T_FILEOBJ_METHODS *pMethods);							/**< 生成 */
void      FileObj_Delete(HANDLE hDriver);												/**< 削除 */

#define   FileObj_GetMethods(self)						((const T_FILEOBJ_METHODS *)(self)->TargetObj.Object.pMethods)

void      FileObj_Constructor(C_FILEOBJ *self, const T_FILEOBJ_METHODS *pMethods);		/**< コンストラクタ */
void      FileObj_Destructor(C_FILEOBJ *self);											/**< デストラクタ */

HANDLE    FileObj_Open(C_FILEOBJ *self, const char *pszPath, int iMode);
void      FileObj_Close(C_FILEOBJ *self, struct c_fileptr *pFilePtr);
FILE_ERR  FileObj_IoControl(C_FILEOBJ *self, struct c_fileptr *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  FileObj_Seek(C_FILEOBJ *self, struct c_fileptr *pFilePtr, FILE_POS Offset, int iOrign);
FILE_SIZE FileObj_Read(C_FILEOBJ *self, struct c_fileptr *pFilePtr, void *pBuf, FILE_SIZE Size);
FILE_SIZE FileObj_Write(C_FILEOBJ *self, struct c_fileptr *pFilePtr, const void *pData, FILE_SIZE Size);
FILE_ERR  FileObj_Flush(C_FILEOBJ *self, struct c_fileptr *pFilePtr);


HANDLE    FilePtr_Create(struct c_fileobj *pFileObj, int iMode);
void      FilePtr_Delete(HANDLE Handle);
void      FilePtr_Constructor(C_FILEPTR *self, const T_FILEOBJ_METHODS *pMethods, struct c_fileobj *pFileObj, int iMode);	/**< コンストラクタ */
void      FilePtr_Destructor(C_FILEPTR *self);																				/**< デストラクタ */
#define   FilePtr_GetFileObj(self)		((C_FILEOBJ *)PointerObj_GetTargetObj((C_POINTEROBJ *)(self)))
#define   FilePtr_GetMode(self)			((self)->iMode)


/* ハンドル変換 */
//#define   FILE_HANDLE2OBJ(hFile)							((C_FILEPTR *)(hFile))


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__file_local_h__ */


/* end of file */
