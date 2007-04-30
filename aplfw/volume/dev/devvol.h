/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  devvol.h
 * @brief %jp{デバイスドライバをファイルとして管理するボリューム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__devvol_h__
#define __HOS__devvol_h__


#include "system/file/file.h"
#include "system/file/volumeobj.h"


#define DEVVOL_MAX_DEVICE		16


/*  */
typedef struct c_devvol
{
	C_VOLUMEOBJ		VolumeObj;		/* ボリュームオブジェクトを継承 */
	
	T_FILE_DEVINF DevTable[DEVVOL_MAX_DEVICE];
} C_DEVVOL;


#ifdef __cplusplus
extern "C" {
#endif

void     DevVol_Create(C_DEVVOL *self);
FILE_ERR DevVol_AddDevice(C_DEVVOL *self, const T_FILE_DEVINF *pDevInf);

#ifdef __cplusplus
}
#endif

#endif	/* __HOS__devdir_h__ */



/* end of file */
