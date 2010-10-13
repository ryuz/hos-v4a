/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv_iocontrol.c
 * @brief %jp{Jelly I2Cデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyi2cdrv_local.h"


FILE_ERR JellyI2cDrv_Access(C_JELLYI2CDRV *self, const T_I2CDRV_ACCESS *pAccess)
{
	int i;
	
	/* start */
	if ( pAccess->iFlag & I2CDRV_ACCESS_FLAG_START )
	{
		JELLYI2CDRV_REG_WRITE(self, JELLYI2CDRV_REG_I2C_CONTROL, JELLYI2CDRV_CONTROL_START);
		JELLYI2CDRV_WAIT_BUSY(self);
	}
	
	/* write data */
	for ( i = 0; i < pAccess->iWriteLength; i++ )
	{
		JELLYI2CDRV_REG_WRITE(self, JELLYI2CDRV_REG_I2C_SEND, pAccess->pubWriteBuf[i]);
		JELLYI2CDRV_WAIT_BUSY(self);
	}
	
	/* read data */
	for ( i = 0; i < pAccess->iReadLength; i++ )
	{
		/* read */
		JELLYI2CDRV_REG_WRITE(self, JELLYI2CDRV_REG_I2C_CONTROL, JELLYI2CDRV_CONTROL_RECV);
		JELLYI2CDRV_WAIT_BUSY(self);
		pAccess->pubReadBuf[i] = (unsigned char)JELLYI2CDRV_REG_READ(self, JELLYI2CDRV_REG_I2C_RECV);
		
		if ( i+1 < pAccess->iReadLength )
		{
			/* ack */
			JELLYI2CDRV_REG_WRITE(self, JELLYI2CDRV_REG_I2C_CONTROL, JELLYI2CDRV_CONTROL_ACK);
			JELLYI2CDRV_WAIT_BUSY(self);
		}
	}
	
	/* ACK */
	if ( pAccess->iFlag & I2CDRV_ACCESS_FLAG_ACK )
	{
		JELLYI2CDRV_REG_WRITE(self, JELLYI2CDRV_REG_I2C_CONTROL, JELLYI2CDRV_CONTROL_ACK);
		JELLYI2CDRV_WAIT_BUSY(self);
	}

	/* NAK */
	if ( pAccess->iFlag & I2CDRV_ACCESS_FLAG_NAK )
	{
		JELLYI2CDRV_REG_WRITE(self, JELLYI2CDRV_REG_I2C_CONTROL, JELLYI2CDRV_CONTROL_NAK);
		JELLYI2CDRV_WAIT_BUSY(self);
	}

	/* stop */
	if ( pAccess->iFlag & I2CDRV_ACCESS_FLAG_STOP )
	{
		JELLYI2CDRV_REG_WRITE(self, JELLYI2CDRV_REG_I2C_CONTROL, JELLYI2CDRV_CONTROL_STOP);
		JELLYI2CDRV_WAIT_BUSY(self);
	}

	return i;
}


/* end of file */
