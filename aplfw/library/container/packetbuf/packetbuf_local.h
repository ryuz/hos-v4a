/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  packetbuf.h
 * @brief %jp{パケットデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__packetbuf_local_h__
#define __HOS__packetbuf_local_h__


#include "packetbuf.h"


#define PACKETBUF_DATASIZE(len)		((len + sizeof(int) - 1) & (~sizeof(int) - 1))				/**< データの利用メモリ範囲設定 */



#endif	/* __HOS__packetbuf_local_h__ */


/* end of file */
