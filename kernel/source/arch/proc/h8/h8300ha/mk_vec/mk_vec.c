#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *fp;
	char fname[64];
	int  i;
	
	for ( i = 1; i <= 11; i++ )
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
			"				.SECTION P, CODE, ALIGN=2\n"
			"\n"
			"__kernel_vector_%03d:\n"
			"				push.l	er0\n"
			"				mov.b	#%d, r0l\n"
			"				bra		__kernel_exc_hdr\n"
			"\n"
			"\n"
			"				.END\n"
			"\n"
			"\n"
			"; end of file\n",
			i, i, i);
		
		fclose(fp);
	}
	
	
	for ( i = 12; i <= 63; i++ )
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
			"				.SECTION P, CODE, ALIGN=2\n"
			"\n"
			"__kernel_vector_%03d:\n"
			"				push.l	er0\n"
			"				mov.b	#%d, r0l\n"
			"				bra		__kernel_int_hdr\n"
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
			"				.SECTION P, CODE, ALIGN=2\n"
			"\n"
			"__kernel_vector_dmy:\n"
			"				rte\n"
			"\n"
			"\n"
			"				.END\n"
			"\n"
			"\n"
			"; end of file\n",
			i, i);
		
		fclose(fp);
	}
	
	return 0;
}

