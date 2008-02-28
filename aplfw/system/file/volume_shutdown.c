/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  volume.h
 * @brief %jp{ボリュームオブジェクト}
 *
 * %jp{ディスクドライブなどの単位をボリュームとして扱う}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "volume.h"
#include "volumeobj_local.h"


/* シャットダウンする */
FILE_ERR Volume_Shutdown(HANDLE hVolume)
{
	C_VOLUMEOBJ *self;
	
	self = (C_VOLUMEOBJ *)hVolume;
	
	return ((T_VOLUMEOBJ_METHODS *)self->DrvObj.HandleObj.pMethods)->pfncShutdown(self);
}


/* end of file */
