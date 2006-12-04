#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *fp;
	char fname[64];
	int  i;
	
	for ( i = 4; i <= 63; i++ )
	{
		sprintf(fname ,"../vect_%03d.src", i);
		if ( (fp = fopen(fname, "w")) == NULL )
		{
			return 1;
		}
		
		fprintf(fp, 
			"; --------------------------------------------------------------------------- \n"
			";  Hyper Operating System V4 Advance\n"
			"; \n"
			";                                   Copyright (C) 1998-2006 by Project HOS\n"
			";                                   http://sourceforge.jp/projects/hos/\n"
			"; --------------------------------------------------------------------------- \n"
			"\n"
			"\n"
			"				.EXPORT	__kernel_vector_%03d\n"
			"				.IMPORT	__kernel_exc_hdr\n"
			"\n"
			"\n"
			"				.SECTION P, CODE, ALIGN=4\n"
			"\n"
			"__kernel_vector_%03d:\n"
			"				mov.l	r4, @-r15\n"
			"				mov.l	addr_exc_hdr, r4\n"
			"				jmp		@r4\n"
			"				mov		#%d, r4\n"
			"\n"
			"\n"
			"				.ALIGN	4\n"
			"addr_exc_hdr:\n"
			"				.DATA.L	__kernel_exc_hdr\n"
			"\n"
			"\n"
			"				.END\n"
			"\n"
			"\n"
			"; end of file\n",
			i, i, i);
		
		fclose(fp);
	}
	
	
	for ( i = 64; i <= 255; i++ )
	{
		sprintf(fname ,"../vect_%03d.src", i);
		if ( (fp = fopen(fname, "w")) == NULL )
		{
			return 1;
		}
		
		fprintf(fp, 
			"; --------------------------------------------------------------------------- \n"
			";  Hyper Operating System V4 Advance\n"
			"; \n"
			";                                   Copyright (C) 1998-2006 by Project HOS\n"
			";                                   http://sourceforge.jp/projects/hos/\n"
			"; --------------------------------------------------------------------------- \n"
			"\n"
			"\n"
			"				.EXPORT	__kernel_vector_%03d\n"
			"				.IMPORT	__kernel_int_hdr\n"
			"\n"
			"\n"
			"				.SECTION P, CODE, ALIGN=4\n"
			"\n"
			"__kernel_vector_%03d:\n"
			"				mov.l	r4, @-r15\n"
			"				mov.l	addr_int_hdr, r4\n"
			"				jmp		@r4\n"
			"				mov		#%d, r4\n"
			"\n"
			"\n"
			"				.ALIGN	4\n"
			"addr_int_hdr:\n"
			"				.DATA.L	__kernel_int_hdr\n"
			"\n"
			"\n"
			"				.END\n"
			"\n"
			"\n"
			"; end of file\n",
			i, i, i);
		
		fclose(fp);
	}
	
	{
			sprintf(fname ,"../vect_dmy.src", i);
		if ( (fp = fopen(fname, "w")) == NULL )
		{
			return 1;
		}
		
		fprintf(fp, 
			"; --------------------------------------------------------------------------- \n"
			";  Hyper Operating System V4 Advance\n"
			"; \n"
			";                                   Copyright (C) 1998-2006 by Project HOS\n"
			";                                   http://sourceforge.jp/projects/hos/\n"
			"; --------------------------------------------------------------------------- \n"
			"\n"
			"\n"
			"				.EXPORT	__kernel_vector_dmy\n"
			"				.IMPORT	__kernel_int_hdr\n"
			"\n"
			"\n"
			"				.SECTION P, CODE, ALIGN=4\n"
			"\n"
			"__kernel_vector_dmy:\n"
			"				rte\n"
			"				nop\n"
			"\n"
			"\n"
			"				.END\n"
			"\n"
			"\n"
			"; end of file\n",
			i, i, i);
		
		fclose(fp);
	}
	
	return 0;
}

