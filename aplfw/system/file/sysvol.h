/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 *  %jp{ルートディレクトリや /dev ディレクトリなど、システム上の仮想ボリュームを管理}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__sysvol_h__
#define __HOS__sysvol_h__


#include "system/file/file.h"
#include "system/file/volumeobj.h"


#define DEVVOL_MAX_DEVICE		16


/* デバイス情報 */
struct c_drvobj;
typedef struct t_sysvol_devinf
{
	char			szName[FILE_MAX_NAME];			/* デバイス名 */
	struct c_drvobj	*pDrvObj;						/* デバイスドライバへの参照 */
	int				iAttr;							/* デバイスの属性 */
} T_SYSVOL_DEVINF;


/* システムボリュームクラス */
typedef struct c_sysvol
{
	C_VOLUMEOBJ		VolumeObj;		/* ボリュームオブジェクトを継承 */
	
	T_SYSVOL_DEVINF DevTable[DEVVOL_MAX_DEVICE];
} C_SYSVOL;


#ifdef __cplusplus
extern "C" {
#endif

void     SysVol_Create(C_SYSVOL *self);
void     SysVol_Delete(C_DRVOBJ *self);

FILE_ERR SysVol_AddDevice(C_SYSVOL *self, const char *pszName, struct c_drvobj *pDrvObj, int iAttr);

#ifdef __cplusplus
}
#endif

#endif	/* __HOS__sysvol_h__ */



/* end of file */
