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


/** バッファのクリア */
void StreamBuf_Clear(C_STREAMBUF *self)
{
	self->uiHead = self->uiTail;
}


/* end of file */
