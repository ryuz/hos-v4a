/**
 *  Hyper Operating System  Application Framework
 *
 * @file  memwrite.h
 * @brief %jp{メモリ書込みコマンド}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "memwrite.h"


int MemWrite_Main(int argc, char *argv[])
{
	void			*pAddr;
	unsigned long	ulData;
	int				iWidth = 'b';

	if ( argc < 3 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s addrress data [b|h|w]\n\n",
				argv[0]
			);
		return 1;
	}

	/* コマンドライン解析 */
	pAddr  = (void *)strtoul(argv[1], 0, 0);
	ulData = strtoul(argv[2], 0, 0);
	if ( argc >= 4 )
	{
		iWidth = argv[3][0];
	}

	switch ( iWidth )
	{
	case 'b':
		{
			unsigned char *pubAddr;
			unsigned char ubData;
			pubAddr = (unsigned char *)pAddr;
			ubData  = (unsigned char)ulData;
			*pubAddr = ubData;
			StdIo_PrintFormat("[memwrite] (unsigned char *)0x%08lx <= 0x%02x (%d)\n", (unsigned long)pubAddr, ubData, (int)(signed char)ubData);
		}
		break;

	case 'h':
		{
			unsigned short *puhAddr;
			unsigned short uhData;
			puhAddr = (unsigned short *)pAddr;
			uhData  = (unsigned short)ulData;
			*puhAddr = uhData;
			StdIo_PrintFormat("[memwrite] (unsigned short *)0x%08lx <= 0x%04x (%d)\n", (unsigned long)puhAddr, uhData, (int)(signed short)uhData);
		}
		break;

	case 'w':
		{
			unsigned long *puwAddr;
			puwAddr = (unsigned long *)pAddr;
			*puwAddr = ulData;
			StdIo_PrintFormat("[memwrite] (unsigned long *)0x%08lx <= 0x%08lx (%ld)\n", (unsigned long)puwAddr, ulData, (signed long)ulData);
		}
		break;
	}

	return 0;
}


/* end of file */
