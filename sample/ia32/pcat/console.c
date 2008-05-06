/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  puts.c
 * @brief %jp{モニタへの出力}%en{console output}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "console.h"


#define TEXTVRAM	((volatile UH *)0x000b8000)


static int		Console_x;
static int		Console_y;



/* %jp{初期化} */
void Console_Initialize(void)
{
	int i;
	
	/* COM1の初期化 */
	_kernel_outpb(0x3fb, 0x83);
	_kernel_outpb(0x3f8, 0x0c);		/* 9600bps */
	_kernel_outpb(0x3f9, 0x00);
	_kernel_outpb(0x3fb, 0x03);
	
	
	/* Text-VRAM初期化 */
	Console_x = 0;
	Console_y = 0;
	for ( i = 0; i < 80*25; i++ )
	{
		TEXTVRAM[i] = 0x0720;
	}
}


/* %jp{1文字出力} */
void Console_PutChar(int c)
{
	int i, j;
	
	/* Text-VRAM出力 */
	if ( c == '\n' )
	{
		Console_x = 0;
		if ( Console_y < 24 )
		{
			Console_y++;
		}
		else
		{
			for ( i = 0; i < 24; i++ )
			{
				for ( j = 0; j < 80; j++ )
				{
					TEXTVRAM[(i*80)+j] = TEXTVRAM[((i+1)*80)+j];
				}
			}
			for ( j = 0; j < 80; j++ )
			{
				TEXTVRAM[(24*80+j)] = 0x0720;
			}
		}
	}
	else
	{
		TEXTVRAM[(Console_y*80)+Console_x] = ((c & 0xff) | 0x0700);
		Console_x++;
	}
	
	/* COM出力 */
	if ( c == '\n' )
	{
		c = '\r';
	}
	while ( !(_kernel_inpb(0x3fd) & 0x20) )
		;
	_kernel_outpb(0x3f8, c);
}


/* %jp{文字列出力} */
void Console_PutString(const char *text)
{
	while ( *text != '\0' )
	{
		Console_PutChar(*text);
		text++;
	}
}





/* 以下デバッグ用出力 */
#include "../../aplfw/library/algorithm/stringformat/stringformat.h"


int Debug_Put(int c, void *Param)
{
	Console_PutChar(c);
	
	return 1;
}


int Debug_PutChar(int c)
{
	return Debug_Put(c, 0);
}


int Debug_PutHex(int num)
{
	return Debug_PrintFormat("%08x", num);
}


int Debug_PrintFormat(const char *pszFormat, ...)
{
	va_list	argptr;
	int		iRet;
	
	va_start(argptr, pszFormat);
	iRet = StringFormat_FormatV(Debug_Put, 0, pszFormat, argptr);
	va_end(argptr);
	
	return iRet;
}


/* %jp{文字列出力} */
void Debug_PutString(int y, int x, const char *text)
{
	int i;
	
	for ( i = 0; text[i]; i++ )
	{
		TEXTVRAM[(y*80+x+i)*2] = text[i];
	}
}



/* end of file */
