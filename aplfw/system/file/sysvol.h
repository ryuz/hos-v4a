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
	HANDLE			hDriver;						/* デバイスドライバのハンドル */
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

HANDLE   SysVol_Create(void);
void     SysVol_Delete(HANDLE hVolume);

FILE_ERR SysVol_AddDevice(HANDLE hSysVol, const char *pszName, HANDLE hDriver, int iAttr);

#ifdef __cplusplus
}
#endif

#endif	/* __HOS__sysvol_h__ */



/* end of file */
