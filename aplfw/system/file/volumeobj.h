/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  driveobj.h
 * @brief %jp{ディレクトリオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__volumeobj_h__
#define __HOS__volumeobj_h__


#include "system/handle/handleobj.h"
#include "file.h"


/* ボリューム操作オブジェクトクラス基本メソッドテーブル */
typedef struct t_volumeobj_methods
{
	T_HANDLEOBJ_METHODS HandlObjMethods;
	
	HANDLE   (*pfncOpenFile)(HANDLE hVolume, const char *pszPath, int iMode);		/* ファイルを開く */
	FILE_ERR (*pfncMakeDir)(HANDLE hVolume, const char *pszPath);					/* サブディレクトリを作成 */
	FILE_ERR (*pfncRemove)(HANDLE hVolume, const char *pszPath);					/* ファイルを削除 */
} T_VOLUMEOBJ_METHODS;

typedef struct c_volumeobj
{
	C_HANDLEOBJ HandleObj;								/* ハンドルオブジェクトを継承 */
} C_VOLUMEOBJ;

/* ハンドル変換 */
#define VOLUME_HANDLE2OBJ(hVolume)		((C_VOLUMEOBJ *)hVolume)





#ifdef __cplusplus
extern "C" {
#endif

void    VolumeObj_Create(C_VOLUMEOBJ *self, const T_VOLUMEOBJ_METHODS *pVolumeObjMethods);
#define VolumeObj_GetMethods(self)		((T_VOLUMEOBJ_METHODS *)HandleObj_GetMethods(&(self)->HandleObj))


#ifdef __cplusplus
}
#endif



#endif	/* __HOS__volumeobj_h__ */


/* end of file */
