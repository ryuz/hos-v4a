
#include <string.h>
#include "hosaplfw.h"
#include "hello.h"


int Hello_Main(int argc, char *argv[])
{
	int i;

	StdIo_PutString("Hello!\r\n\r");

	StdIo_PrintFormat("argc = %d\r\n", argc);
	for ( i = 0; i < argc + 1; i++ )
	{
		if ( argv[i] == NULL )
		{
			StdIo_PrintFormat("argv[%d] = NULL\r\n", i);
		}
		else
		{
			StdIo_PrintFormat("argv[%d](%d) %s\r\n", i, (int)strlen(argv[i]), argv[i]);
		}
	}

	return 0;
}


