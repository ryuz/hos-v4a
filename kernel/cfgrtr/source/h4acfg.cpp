
#include <stdio.h>
#include "debug.h"
#include "param.h"
#include "parser.h"


CParser Parser;

int main(int argc, char *argv[])
{
	FILE *fp;

	if ( (fp = fopen("system.i", "r")) == NULL )
	{
		return 1;
	}
	Parser.Analyze(fp);

#if 0
	CParamBlock param;
	CParamBlock *pParam2;

	param.AddString("aaaa");
	param.AddString("bbbb");
	pParam2 = param.AddParamBlock();
	pParam2->AddString("ccc");
	pParam2->AddString("ddd");
	param.AddString("eeeeeeeeeeeeeeee");

	CDebug::PrintParam(&param, 0);
#endif
	
	return 0;
}

