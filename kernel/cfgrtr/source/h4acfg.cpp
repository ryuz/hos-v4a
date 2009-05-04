
#include <stdio.h>
#include "debug.h"
#include "param.h"
#include "parser.h"

#include <list>
using namespace std;


int main(int argc, char *argv[])
{
	CParser     Parser;
	FILE        *fp;
	TSourceInfo SrcInf;
	
	// さしあたって適当にテスト
	if ( (fp = fopen("system.i", "r")) == NULL )
	{
		return 1;
	}

	SrcInf.strFileName = "system.i";
	SrcInf.iLineNum    = 1;
	SrcInf.iColumnNum  = 1;
	Parser.Analyze(fp, &SrcInf);
	
	getchar();

	return 0;
}

