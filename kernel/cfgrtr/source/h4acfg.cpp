
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

	{
		list<int>           lst;
		list<int>::reverse_iterator it;
		
		lst.push_back(11);
		lst.push_back(22);
		lst.push_back(33);
		
		for ( it = lst.rbegin(); it != lst.rend();  it++ )
		{
			printf("%d\n", *it);
		}
		
		return 0;
	}

	// さしあたって適当にテスト
	if ( (fp = fopen("system.i", "r")) == NULL )
	{
		return 1;
	}

	SrcInf.strFileName = "system.i";
	SrcInf.iLineNum   = 1;
	SrcInf.iColumnNum = 1;
	Parser.Analyze(fp, &SrcInf);
	
	return 0;
}

