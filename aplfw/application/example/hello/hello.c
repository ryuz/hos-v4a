/* hello world */

#include <string.h>
#include "hosaplfw.h"
#include "hello.h"



int Hello_Main(int argc, char *argv[])
{
	int i;

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


