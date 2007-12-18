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


void IpEther_Delete(HANDLE hDriver)
{
	C_IPETHER *self;
	
	/* upper cast */
	self = (C_IPETHER *)hDriver;

	/* デストラクタ呼び出し */
	IpEther_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}


/* endof file */
