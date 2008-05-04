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


#define TEXTVRAM	((volatile UB *)0x000b8000)



static int		Console_x;
static int		Console_y;



/* %jp{1文字出力} */
void Console_PutChar(int c)
{
	int i, j;
	
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
					TEXTVRAM[(i*80+j)*2] = TEXTVRAM[((i+1)*80+j)*2];
				}
			}
			for ( j = 0; j < 80; j++ )
			{
				TEXTVRAM[(24*80+j)*2] = ' ';
			}
		}
	}
	else
	{
		TEXTVRAM[(Console_y*80+Console_x)*2] = c;
		Console_x++;
	}
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


/* end of file */
