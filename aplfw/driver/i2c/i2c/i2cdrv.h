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

#define I2CDRV_IOCTL_ACCESS		0x3101


typedef struct t_i2cdrv_access
{
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

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__i2cdrv_h__ */


/* end of file */
