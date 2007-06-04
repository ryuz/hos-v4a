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


void IpEther_Delete(C_DRVOBJ *pDrvObj)
{
	C_IPETHER			*self;
	
	/* upper cast */
	self = (C_IPETHER *)pDrvObj;

	/* 親クラスデストラクタ呼び出し */
	ChrDrv_Delete(&self->ChrDrv);
}


/* endof file */
