/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  i2cdrv_bytewrite.c
 * @brief %jp{I2Cデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "i2cdrv_local.h"


FILE_ERR I2cDrv_BurstWrite(HANDLE hFile, unsigned char ubDev, unsigned char ubAddr, const unsigned char *pubData, int iLength)
{
	T_I2CDRV_ACCESS	Access;
	unsigned char	ubWriteBuf[2];
	
	ubWriteBuf[0] = (unsigned char)((ubDev << 1) | 0x00);
	ubWriteBuf[1] = ubAddr;
	
	Access.iFlag        = I2CDRV_ACCESS_FLAG_START;
	Access.pubWriteBuf  = ubWriteBuf;
	Access.iWriteLength = 2;
	Access.pubReadBuf   = NULL;
	Access.iReadLength  = 0;
	File_IoControl(hFile, I2CDRV_IOCTL_ACCESS, NULL, 0, &Access, sizeof(Access));
	
	Access.iFlag        = I2CDRV_ACCESS_FLAG_STOP;
	Access.pubWriteBuf  = pubData;
	Access.iWriteLength = iLength;
	Access.pubReadBuf   = NULL;
	Access.iReadLength  = 0;
	File_IoControl(hFile, I2CDRV_IOCTL_ACCESS, NULL, 0, &Access, sizeof(Access));
	
	return FILE_ERR_OK;
}



/* end of file */
