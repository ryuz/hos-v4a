/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streampipe.c
 * @brief %jp{ストリームパイプ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "streampipe_local.h"


/** デストラクタ */
void StreamPipe_Delete(HANDLE hDriver)
{
	C_STREAMPIPE	*self;
	
	/* upper cast */
	self = (C_STREAMPIPE *)hDriver;
	
	/* デストラクタ呼び出し */
	StreamPipe_Destructor(self);

	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */
