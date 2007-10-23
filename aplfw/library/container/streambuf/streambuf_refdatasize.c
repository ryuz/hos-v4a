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



/** バッファ内データ量の参照 */
unsigned int StreamBuf_RefDataSize(C_STREAMBUF *self)
{
	unsigned int uiHead;
	unsigned int uiTail;
	
	uiHead = self->uiHead;
	uiTail = self->uiTail;
	
	if ( uiHead <= uiTail )
	{
		return uiTail - uiHead;
	}
	else
	{
		return self->uiBufSize + uiTail - uiHead;
	}
}



/* end of file */
