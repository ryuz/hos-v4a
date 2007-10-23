/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streambuf.h
 * @brief %jp{ストリームデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "streambuf_local.h"


/** バッファ空き容量の参照 */
unsigned int StreamBuf_RefFreeSize(C_STREAMBUF *self)
{
	return StreamBuf_RefMaxSize(self) - StreamBuf_RefDataSize(self);
}


/* end of file */
