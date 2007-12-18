/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ipether.h
 * @brief %jp{Ether上にIPプロトコルを実装(つまりMAC層近辺)}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "ipether_local.h"


/* 仮想関数テーブル */
static const T_DRVOBJ_METHODS IpEther_Methods = 
	{
		IpEther_Delete,
		IpEther_Open,
		IpEther_Close,
		IpEther_IoControl,
		IpEther_Seek,
		IpEther_Read,
		IpEther_Write,
		IpEther_Flush,
	};


/**< 生成 */
HANDLE IpEther_Create(const char *pszEther, const T_IPETHER_INF *pInf)
{
	C_IPETHER *self;
	
	/* メモリ確保 */
	if ( (self = (C_IPETHER *)SysMem_Alloc(sizeof(C_IPETHER))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( IpEther_Constructor(self, &IpEther_Methods, pszEther, pInf) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* endof file */
