
#include <string.h>
#include "hosaplfw.h"
#include "hello.h"


int Hello_Main(int argc, char *argv[])
{
	int i;

	StdIo_PutString("Hello!\r\n");
	StdIo_PrintFormat("argc = %d\r\n", argc);
	for ( i = 0; i < argc; i++ )
	{
		StdIo_PrintFormat("argv[%d](%d) %s\r\n", i, strlen(argv[i]), argv[i]);
	}

	return 0;
}


