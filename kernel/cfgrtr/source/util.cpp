
#include <stdlib.h>


#include <string>
using namespace std;


// パラメータ文字列を正規化する
void RegularizeParam(string &strSrc)
{
	string strDst;

}

// 数値として有効かチェック
bool CheckNumber(const char *pszStr)
{
	char *end;
	
	errno = 0;
	strtol(pszStr, &end, 0);
	if ( errno != 0 || *end != '\0' )
	{
		return false;
	}

	return true;
}


// 識別子として有効かチェック
bool CheckIdentifier(const char *pszStr)
{
	return true;
}