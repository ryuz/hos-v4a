
#include "debug.h"


void CDebug::PrintParam(CParamBlock *pParam, int iIndent)
{
	int i, j;

	for ( i = 0; i < pParam->GetSize(); i++ )
	{
		if ( pParam->GetType(i) == PARAM_TYPE_STRING )
		{
			for ( j = 0; j < iIndent; j++ ) {	putchar(' '); }
			printf("%s\n", pParam->GetString(i));
		}
		else
		{
			for ( j = 0; j < iIndent; j++ ) {	putchar(' '); }
			printf("{\n");
			PrintParam(pParam->GetParamBlock(i), iIndent+2);
			for ( j = 0; j < iIndent; j++ ) {	putchar(' '); }
			printf("}\n");
		}
	}
}
