/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ipether.h
 * @brief %jp{Ether上にIPプロトコルを実装(つまりMAC層近辺)}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "ipether_local.h"


/**< デストラクタ */
void IpEther_Destructor(C_IPETHER *self)
{
	/* 親クラスデストラクタ呼び出し */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* endof file */
