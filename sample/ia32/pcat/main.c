/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  main.c
 * @brief %jp{メイン関数}%en{main}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "console.h"


extern VP _kernel_inh_tbl[224];

/** %jp{メイン関数} */
int main()
{
	Console_Initialize();

	/* 9600bps */
	_kernel_outpb(0x3fb, 0x83);
	_kernel_outpb(0x3f8, 0x0c);
	_kernel_outpb(0x3f9, 0x00);
	_kernel_outpb(0x3fb, 0x03);

/*	_kernel_outpb(0x3f8, 'A');
	_kernel_outpb(0x3f8, 'B');
	_kernel_outpb(0x3f8, 'C');
	*/
	
	
	
	Debug_PrintFormat("Debug start\n");
	Debug_PrintFormat("hoge : %08x\n", _debug_getflag());
/*	Debug_PrintFormat("hoge : %08x\n", (int)_kernel_inh_tbl);	*/

#if 0
	{
		int i;
		UW *p = 0x8000;
		for ( 0x8000; ; )
		{
		}
	}
	for ( ; ; )
	{
		Debug_PrintFormat("Debug HOS\n");
	}
#endif

#if 0
	for ( ; ; )
	{
		Console_PutString("Hello HOS world!\n");
	}
#endif


/*
	volatile char	*tvram = (volatile char *)0xb8000;
	const char		msg[] = "Hello Wold!";
	int				i;
	
	for ( i = 0; msg[i] != '\0'; i++ )
	{
		tvram[i*2] = msg[i];
	}
*/

	/* %jp{カーネルの動作開始} */
	vsta_knl();
	
	return 0;
}



/* end of file */
