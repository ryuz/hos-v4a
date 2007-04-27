
#include <string.h>
#include "hosaplfw.h"
#include "hello.h"


int Hello_Main(int argc, char *argv[])
{
	int i;

	{
		HANDLE hTty;
		StdIo_PutString("\nKeyTest\n");
		hTty = Process_GetTty();
		for ( ; ; )
		{
			int c;
			c = File_GetChar(hTty);
			File_PrintFormat(hTty, "%02x  ", c);
			if ( c >= 0x20 )
			{
				File_PutChar(hTty, c);
			}
			File_PrintFormat(hTty, "\r\n");			
		}
	}

	StdIo_PutString("\nHello!\n");

	StdIo_PrintFormat("argc = %d\n", argc);
	for ( i = 0; i < argc + 1; i++ )
	{
		if ( argv[i] == NULL )
		{
			StdIo_PrintFormat("argv[%d] = NULL\n", i);
		}
		else
		{
			StdIo_PrintFormat("argv[%d](%d) %s\n", i, (int)strlen(argv[i]), argv[i]);
		}
	}

	return 0;
}


