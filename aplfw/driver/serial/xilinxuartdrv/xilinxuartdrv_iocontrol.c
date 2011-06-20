/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_iocontrol.c
 * @brief %jp{XILINX UART driver I/O制御}%en{XILINX UART driver  I/O control}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "xilinxuartdrv_local.h"


FILE_ERR XilinxUartDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return SyncDrv_IoControl(pDrvObj, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */
