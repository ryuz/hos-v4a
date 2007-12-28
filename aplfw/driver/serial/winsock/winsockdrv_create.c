/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "winsockdrv_local.h"


/**  生成 */
HANDLE WinSockDrv_Create(int iPortNum, int iIntNum, int iBufSize)
{
	C_WINSOCKDRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_WINSOCKDRV *)SysMem_Alloc(sizeof(C_WINSOCKDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( WinSockDrv_Constructor(self, NULL, iPortNum, iIntNum, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
