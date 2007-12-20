/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdump.h
 * @brief %jp{メモリダンプコマンド}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "memdump.h"


int MemDump_Main(int argc, char *argv[])
{
	void			*pAddr;
	int				iWidth = 'b';
	unsigned long	ulSize = 256;
	unsigned long	i;
	
	
	if ( argc < 2 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s addrress [size] [b|h|w]\n\n",
				argv[0]
			);
		return 1;
	}
	
	/* コマンドライン解析 */
	pAddr = (void *)strtoul(argv[1], 0, 0);
	if ( argc >= 3 )
	{
		ulSize = (int)strtoul(argv[2], 0, 0);
	}
	if ( argc >= 4 )
	{
		iWidth = argv[3][0];
	}
	
	switch ( iWidth )
	{
	case 'b':
		{
			unsigned char *pubAddr;
			pubAddr = (unsigned char *)pAddr;
			for ( i = 0; i < ulSize; i++ )
			{
				if ( i % 16 == 0 )
				{
					StdIo_PrintFormat("%08lx: ", (unsigned long)pubAddr);
				}
				StdIo_PrintFormat("%02x ", *pubAddr);
				pubAddr++;
				if ( i % 16 == 15 )
				{
					StdIo_PrintFormat("\n");
				}
			}
		}
		break;

	case 'h':
		{
			unsigned short *puhAddr;
			puhAddr = (unsigned short *)pAddr;
			ulSize = (ulSize + 1) / 2;
			for ( i = 0; i < ulSize; i++ )
			{
				if ( i % 8 == 0 )
				{
					StdIo_PrintFormat("%08lx: ", (unsigned long)puhAddr);
				}
				StdIo_PrintFormat("%04x ", *puhAddr);
				puhAddr++;
				if ( i % 8 == 7 )
				{
					StdIo_PrintFormat("\n");
				}
			}
		}
		break;

	case 'w':
		{
			unsigned long *puwAddr;
			puwAddr = (unsigned long *)pAddr;
			ulSize = (ulSize + 3) / 4;
			for ( i = 0; i < ulSize; i++ )
			{
				if ( i % 4 == 0 )
				{
					StdIo_PrintFormat("%08lx: ", (unsigned long)puwAddr);
				}
				StdIo_PrintFormat("%08x ", *puwAddr);
				puwAddr++;
				if ( i % 4 == 3 )
				{
					StdIo_PrintFormat("\n");
				}
			}
		}
		break;
	}

	StdIo_PrintFormat("\n");


	return 0;
}


