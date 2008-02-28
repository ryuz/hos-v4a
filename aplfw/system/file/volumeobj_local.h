/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  volumeobj.h
 * @brief %jp{ボリュームオブジェクト基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__volumeobj_local_h__
#define __HOS__volumeobj_local_h__


#include "volumeobj.h"
#include "system/file/drvobj_local.h"



#ifdef __cplusplus
extern "C" {
#endif

void VolumeObj_Constructor(C_VOLUMEOBJ *self, const T_VOLUMEOBJ_METHODS *pMethods);		/**< コンストラクタ */
void VolumeObj_Destructor(C_VOLUMEOBJ *self);											/**< デストラクタ */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__volumeobj_h__ */


/* end of file */
