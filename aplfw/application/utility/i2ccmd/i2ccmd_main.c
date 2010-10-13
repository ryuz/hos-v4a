/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  i2ccmd_main.c
 * @brief %jp{I2Cコマンド}
 *
 * Copyright (C) 2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "i2ccmd.h"
#include "driver/i2c/i2c/i2cdrv.h"


int I2cCmd_Main(int argc, char *argv[])
{
	unsigned char	ubDev;
	unsigned char	ubAddr;
	unsigned char	ubData;
	const char		*pszRw   = NULL;
	const char		*pszDev  = NULL;
	const char		*pszAddr = NULL;
	const char		*pszData = NULL;
	const char		*pszDevName = "/dev/i2c0";
	HANDLE			hDev;
	int				i;

	if ( argc < 4 )
	{
		StdIo_PrintFormat(
			"usage : %s [option] <r|w> <dev> <addr> [data]\n"
			"  option:\n"
			"      -dev devicename\n"
			, argv[0]);
	}
	
	for ( i = 1; i < argc; i++ )
	{
		if ( argv[i][0] == '-' )
		{
			if ( strcmp(&argv[i][1], "dev") == 0 && i+1 < argc )
			{
				pszDevName = argv[++i];
			}
		}
		else
		{
			if ( pszRw == NULL )
			{
				pszRw = argv[i];
			}
			else if ( pszDev == NULL )
			{
				pszDev = argv[i];
			}
			else if ( pszAddr == NULL )
			{
				pszAddr = argv[i];
			}
			else if ( pszData == NULL )
			{
				pszData = argv[i];
			}
		}
	}

	if ( pszAddr == NULL )
	{
		return 1;
	}
	ubDev  = (unsigned char)strtoul(pszDev, 0, 0);
	ubAddr = (unsigned char)strtoul(pszAddr, 0, 0);


	if ( (hDev = File_Open(pszDevName, FILE_OPEN_EXIST)) == HANDLE_NULL )
	{
		StdIo_PrintFormat("open error : %s\n", pszDevName);
		return 1;
	}

	if ( strcmp(pszRw, "r") == 0 )
	{
		/* read */
		ubData = I2cDrv_ByteRead(hDev, ubDev, ubAddr);
		StdIo_PrintFormat("[I2C read] dev:%02x adr:%02x => %02x\n", ubDev, ubAddr, ubData);
	}
	else if ( strcmp(pszRw, "w") == 0 && pszData != NULL )
	{
		/* write */
		ubData = (unsigned char)strtoul(pszData, 0, 0);
		I2cDrv_ByteWrite(hDev, ubDev, ubAddr, ubData);
		StdIo_PrintFormat("[I2C write] dev:%02x adr:%02x <= %02x\n", ubDev, ubAddr, ubData);
	}

	File_Close(hDev);

	return 0;
}


/* end of file */
