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


FILE_ERR I2cDrv_BurstRead(HANDLE hFile, unsigned char ubDev, unsigned char ubAddr, unsigned char *pubBuf, int iLength)
{
	T_I2CDRV_ACCESS	Access;
	unsigned char	ubWriteBuf[2];
	unsigned char	ubReadBuf[1];
	
	Access.iFlag        = (I2CDRV_ACCESS_FLAG_START);
	ubWriteBuf[0]       = (unsigned char)((ubDev << 1) | 0x00);
	ubWriteBuf[1]       = ubAddr;
	Access.pubWriteBuf  = ubWriteBuf;
	Access.iWriteLength = 2;
	Access.pubReadBuf   = ubReadBuf;
	Access.iReadLength  = 0;
	File_IoControl(hFile, I2CDRV_IOCTL_ACCESS, NULL, 0, &Access, sizeof(Access));
	
	Access.iFlag        = (I2CDRV_ACCESS_FLAG_START | I2CDRV_ACCESS_FLAG_STOP);
	ubWriteBuf[0] = (unsigned char)((ubDev << 1) | 0x01);
	Access.pubWriteBuf  = ubWriteBuf;
	Access.iWriteLength = 1;
	Access.pubReadBuf   = pubBuf;
	Access.iReadLength  = iLength;
	File_IoControl(hFile, I2CDRV_IOCTL_ACCESS, NULL, 0, &Access, sizeof(Access));
	
	return (int)ubReadBuf[0];
}


/* end of file */
