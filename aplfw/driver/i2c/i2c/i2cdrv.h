/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  i2cdrv.h
 * @brief %jp{I2C デバイスドライバ 公開ヘッダファイル}
 *
 * Copyright (C) 2006-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__i2cdrv_h__
#define __HOS__i2cdrv_h__


#include "hosaplfw.h"

#define I2CDRV_IOCTL_ACCESS			0x3101

#define I2CDRV_ACCESS_FLAG_START	0x0001
#define I2CDRV_ACCESS_FLAG_STOP		0x0002
#define I2CDRV_ACCESS_FLAG_ACK		0x0004
#define I2CDRV_ACCESS_FLAG_NAK		0x0008


typedef struct t_i2cdrv_access
{
	int					iFlag;
	const unsigned char	*pubWriteBuf;
	int					iWriteLength;
	unsigned char		*pubReadBuf;
	int					iReadLength;
} T_I2CDRV_ACCESS;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR I2cDrv_ByteWrite(HANDLE hFile, unsigned char ubDev, unsigned char ubAddr, unsigned char ubData);
int      I2cDrv_ByteRead(HANDLE hFile, unsigned char ubDev, unsigned char ubAddr);
FILE_ERR I2cDrv_BurstWrite(HANDLE hFile, unsigned char ubDev, unsigned char ubAddr, const unsigned char *pubData, int iLength);
FILE_ERR I2cDrv_BurstRead(HANDLE hFile, unsigned char ubDev, unsigned char ubAddr, unsigned char *pubBuf, int iLength);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__i2cdrv_h__ */


/* end of file */
