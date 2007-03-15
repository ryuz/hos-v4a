
#include <stdio.h>
#include "devvol_local.h"


const T_VOLUMEOBJ_METHODS DevVol_VolumeObjMethods =
{
	{ DevVol_Delete },			/* デストラクタ */
	DevVol_OpenFile,
	NULL,
	NULL,
};


void DevVol_Create(C_DEVVOL *self)
{
	int i;
	
	/* 親クラスコンストラクタ呼び出し */
	VolumeObj_Create(&self->VolumeObj, &DevVol_VolumeObjMethods);	
	
	/* 初期化 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		self->DevTable[i].ObjSize = 0;
	}
}


