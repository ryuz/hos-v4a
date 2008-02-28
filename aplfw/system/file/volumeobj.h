/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  volumeobj.h
 * @brief %jp{ボリュームオブジェクト基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__volumeobj_h__
#define __HOS__volumeobj_h__


#include "system/handle/handleobj.h"
#include "system/file/drvobj.h"


/* ボリューム操作オブジェクトクラス基本メソッドテーブル */
struct c_volumeobj;
typedef struct t_volumeobj_methods
{
	T_DRVOBJ_METHODS	DrvObjMethods;			/* DrvObjを継承 */

	FILE_ERR (*pfncShutdown)(struct c_volumeobj *self);							/* デバイスのシャットダウン */
	FILE_ERR (*pfncMakeDir)(struct c_volumeobj *self, const char *pszPath);		/* サブディレクトリを作成 */
	FILE_ERR (*pfncRemove)(struct c_volumeobj *self, const char *pszPath);		/* ファイルを削除 */
} T_VOLUMEOBJ_METHODS;

typedef struct c_volumeobj
{
	C_DRVOBJ	DrvObj;							/* DrvObjを継承 */
} C_VOLUMEOBJ;


/* ハンドル変換 */
#define VOLUME_HANDLE2OBJ(hVolume)		((C_VOLUMEOBJ *)hVolume)


#ifdef __cplusplus
extern "C" {
#endif

HANDLE   VolumeObj_Create(void);												/**< 生成 */
void     VolumeObj_Delete(HANDLE hVolume);										/**< 削除 */

FILE_ERR VolumeObj_Shutdown(C_VOLUMEOBJ *self);									/**< シャットダウン */
FILE_ERR VolumeObj_MakeDir(C_VOLUMEOBJ *self, const char *pszPath);				/**< サブディレクトリを作成 */
FILE_ERR VolumeObj_Remove(C_VOLUMEOBJ *self, const char *pszPath);				/**< ファイルを削除 */

#ifdef __cplusplus
}
#endif

#define VolumeObj_GetMethods(self)		((T_VOLUMEOBJ_METHODS *)HandleObj_GetMethods(&(self)->DrvObj))



#endif	/* __HOS__volumeobj_h__ */


/* end of file */
