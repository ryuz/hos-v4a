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

/* デバイス情報 */
struct c_drvobj;
typedef struct t_devvol_devinf
{
	char			szName[FILE_MAX_NAME];			/* デバイス名 */
	struct c_drvobj	*pDrvObj;						/* デバイスドライバへの参照 */
} T_DEVVOL_DEVINF;


/*  */
typedef struct c_devvol
{
	C_VOLUMEOBJ		VolumeObj;		/* ボリュームオブジェクトを継承 */
	
	T_DEVVOL_DEVINF DevTable[DEVVOL_MAX_DEVICE];
} C_DEVVOL;


#ifdef __cplusplus
extern "C" {
#endif

void     DevVol_Create(C_DEVVOL *self);
FILE_ERR DevVol_AddDevice(C_DEVVOL *self, const char *pszName, struct c_drvobj *pDrvObj);

#ifdef __cplusplus
}
#endif

#endif	/* __HOS__devdir_h__ */



/* end of file */
