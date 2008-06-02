/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memfill_main.c
 * @brief %jp{メモリフィルコマンド}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "memfill.h"


int MemFill_Main(int argc, char *argv[])
{
	void			*pAddr;
	unsigned long	ulSize;
	unsigned long	ulData;
	int				iWidth = 'b';
	
	if ( argc < 4 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s addrress size data [b|h|w]\n\n",
				argv[0]
			);
		return 1;
	}
	
	
	/* コマンドライン解析 */
	pAddr  = (void *)strtoul(argv[1], 0, 0);
	ulSize = strtoul(argv[2], 0, 0);
	ulData = (unsigned long)strtol(argv[3], 0, 0);
	if ( argc >= 5 )
	{
		iWidth = argv[4][0];
	}
	
	switch ( iWidth )
	{
	case 'b':
		{
			unsigned char *pubAddr;
			pubAddr = (unsigned char *)pAddr;
			while ( (void *)pubAddr < (void*)((char *)pAddr + ulSize) )
			{
				*pubAddr++ = (unsigned char)ulData;
			}
		}
		break;
	
	case 'h':
		{
			unsigned short *puhAddr;
			puhAddr = (unsigned short *)pAddr;
			while ( (void *)puhAddr < (void*)((char *)pAddr + ulSize) )
			{
				*puhAddr++ = (unsigned short)ulData;
			}
		}
		break;
	
	case 'w':
		{
			unsigned long *puwAddr;
			puwAddr = (unsigned long *)pAddr;
			while ( (void *)puwAddr < (void*)((char *)pAddr + ulSize) )
			{
				*puwAddr++ = ulData;
			}
		}
		break;
	}
	
	return 0;
}


/* end of file */
