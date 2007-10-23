/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  packetbuf.h
 * @brief %jp{パケットデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "packetbuf_local.h"


/** バッファのクリア */
void PacketBuf_Clear(C_PACKETBUF *self)
{
	self->uiHead = 	self->uiTail;
}



/* end of file */
