/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stddef.h>
#include "fatvol_local.h"


/** クラスタバッファ開放 */
void FatVol_RelClusterBuf(C_FATVOL *self, T_FATVOL_CLUSTERBUF *pClusterBuf, int iDirty)
{
	if ( iDirty )
	{
		pClusterBuf->iDirty = iDirty;
	}
}


/* end of file */
