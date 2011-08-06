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


FILE_ERR XilinxUartDrv_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return SyncDrv_IoControl(pFileObj, pFilePtr, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */
