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
#include "memtest.h"


static int MemTest_PatternTest(void *pAddrStart, void *pAddrEnd, unsigned long ulPattern);


int MemTest_Main(int argc, char *argv[])
{
	void			*pAddrStart;
	void			*pAddrEnd;
	int				iAuto = 0;
	unsigned long	ulSize;
	unsigned long	i;
	
	if ( argc < 3 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s addrress size\n\n",
				argv[0]
			);
		return 1;
	}
	
	/* コマンドライン解析 */
	pAddrStart = (void *)strtoul(argv[1], 0, 0);
	ulSize     = (int)strtol(argv[2], 0, 0);
	
	/* 自動確保 */
	if ( strcmp(argv[1], "auto") == 0 )
	{
		if ( (pAddrStart = (void *)Memory_Alloc(ulSize)) == NULL )
		{
			return 1;
		}
		iAuto = 1;
	}
	
	pAddrEnd = (char *)pAddrStart + ulSize - 1;
	
	StdIo_PrintFormat("[MemTest] 0x%08lx - 0x%08lx\n\n", (unsigned long)pAddrStart, (unsigned long)pAddrEnd);
	
	/* Word write & read */
	StdIo_PrintFormat("32bit read & write : ");
	{
		unsigned long *puwAddr;
		
		/* write */
		for ( puwAddr = pAddrStart, i = 0; puwAddr <= (unsigned long *)pAddrEnd; puwAddr++, i++ )
		{
			*puwAddr = i;
		}
		
		/* read */
		for ( puwAddr = pAddrStart, i = 0; puwAddr <= (unsigned long *)pAddrEnd; puwAddr++, i++ )
		{
			if ( *puwAddr != i )
			{
				StdIo_PrintFormat("NG (addr:0x%08lx)\n", (unsigned long)puwAddr);
				return 1;
			}
		}
	}
	StdIo_PrintFormat("OK\n");

	/* Halfword write & read */
	StdIo_PrintFormat("16bit read & write : ");
	{
		unsigned short *puhAddr;
		
		/* write */
		for ( puhAddr = pAddrStart, i = 0; puhAddr <= (unsigned short *)pAddrEnd; puhAddr++, i++ )
		{
			*puhAddr = (unsigned short)((i >> 16) ^ i);
		}
		
		/* read */
		for ( puhAddr = pAddrStart, i = 0; puhAddr <= (unsigned short *)pAddrEnd; puhAddr++, i++ )
		{
			if ( *puhAddr != (unsigned short)((i >> 16) ^ i) )
			{
				StdIo_PrintFormat("NG (addr:0x%08lx)\n", (unsigned long)puhAddr);
				return 1;
			}
		}
	}
	StdIo_PrintFormat("OK\n");
	
	/* byte write & read */
	StdIo_PrintFormat("8bit read & write : ");
	{
		unsigned char *pubAddr;
		
		/* write */
		for ( pubAddr = pAddrStart, i = 0; pubAddr <= (unsigned char *)pAddrEnd; pubAddr++, i++ )
		{
			*pubAddr = (unsigned char)((i >> 24) ^ (i >> 16) ^ (i >> 8) ^ i);
		}
		
		/* read */
		for ( pubAddr = pAddrStart, i = 0; pubAddr <= (unsigned char *)pAddrEnd; pubAddr++, i++ )
		{
			if ( *pubAddr != (unsigned char)((i >> 24) ^ (i >> 16) ^ (i >> 8) ^ i) )
			{
				StdIo_PrintFormat("NG (addr:0x%08lx)\n", (unsigned long)pubAddr);
				return 1;
			}
		}
	}
	StdIo_PrintFormat("OK\n");

	/* 0xaa write & read */
	if ( MemTest_PatternTest(pAddrStart, pAddrEnd, 0xaaaaaaaa) != 0 )
	{
		return 1;
	}

	/* 0x55 write & read */
	if ( MemTest_PatternTest(pAddrStart, pAddrEnd, 0x55555555) != 0 )
	{
		return 1;
	}
	
	/* 0xff write & read */
	if ( MemTest_PatternTest(pAddrStart, pAddrEnd, 0xffffffff) != 0 )
	{
		return 1;
	}

	/* 0x00 write & read */
	if ( MemTest_PatternTest(pAddrStart, pAddrEnd, 0x00000000) != 0 )
	{
		return 1;
	}

	if ( iAuto )
	{
		Memory_Free(pAddrStart);
	}
	
	return 0;
}


int MemTest_PatternTest(void *pAddrStart, void *pAddrEnd, unsigned long ulPattern)
{
	unsigned long *puwAddr;
	
	StdIo_PrintFormat("0x%08lx read & write : ", ulPattern);
		
	/* write */
	for ( puwAddr = pAddrStart; puwAddr <= (unsigned long *)pAddrEnd; puwAddr++)
	{
		*puwAddr = ulPattern;
	}
	
	/* read */
	for ( puwAddr = pAddrStart; puwAddr <= (unsigned long *)pAddrEnd; puwAddr++)
	{
		if ( *puwAddr != ulPattern )
		{
			StdIo_PrintFormat("NG (addr:0x%08lx)\n", (unsigned long)puwAddr);
			return 1;
		}
	}

	StdIo_PrintFormat("OK\n");
	
	return 0;
}



/* end of file */
