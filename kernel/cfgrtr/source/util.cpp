

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
using namespace std;


// パラメータ文字列を正規化する(余分空白文字の削除)
string RegularizeParam(const char *pszString)
{
	string str;
	bool   blSpace = false;
	int    iLen;
	int    i;

	// 先頭の空白を読み飛ばし
	while ( isspace(*pszString) )
	{
		pszString++;
	}

	// 後半の空白も除外
	iLen = strlen(pszString);
	while ( iLen > 0 && isspace(pszString[iLen - 1]) )
	{
		iLen--;
	}

	// 正規化
	for ( i = 0; i < iLen; i++ )
	{
		if ( blSpace )	// 空白の続きなら
		{
			if ( !isspace(pszString[i]) )	// 空白が続く限り読み飛ばし
			{
				str += pszString[i];
				blSpace = false;
			}
		}
		else
		{
			if ( isspace(pszString[i]) )
			{
				str += ' ';			// 空白文字はシングルスペースに置換
				blSpace = true;
			}
			else
			{
				str += pszString[i];
			}
		}
	}

	return str;
}


// 文字列定数の展開
string AnalyzeConstantString(const char *pszString)
{
	bool   blEsc = false;
	string str;
	int    c;
	
	// 文字列開始まで読み飛ばし
	while ( (c = *pszString++) != '\0' )
	{
		if ( c == '\"' )
		{
			break;
		}
	}
	if ( c == '\0' )
	{
		return "";	// エラー
	}
	
	// 文字列展開
	while ( (c = *pszString++) != '\0' )
	{
		if ( blEsc )
		{
			if ( c == 'a' )
			{
				str += '\a';
			}
			else if ( c == 'b' )
			{
				str += '\b';
			}
			else if ( c == 'f' )
			{
				str += '\f';
			}
			else if ( c == 'n' )
			{
				str += '\n';
			}
			else if ( c == 'r' )
			{
				str += '\r';
			}
			else if ( c == 't' )
			{
				str += '\t';
			}
			else if ( c == 'v' )
			{
				str += '\v';
			}
			else if ( c == 'x' )
			{
				char *next;
				c = (char)strtol(pszString, &next, 16);
				pszString = (const char*)next;
				str += c;
			}
			else if ( c == '0' )
			{
				char *next;
				c = (char)strtol(pszString, &next, 8);
				pszString = (const char*)next;
				str += c;
			}
			else
			{
				str += c;
			}
			blEsc = false;
		}
		else
		{
			if ( c == '\"' )
			{
				break;
			}
			else if ( c == '\\' )
			{
				blEsc = true;
			}
			else
			{
				str += c;
			}
		}
	}
	if ( c == '\0' )
	{
		return "";	// エラー
	}

	return str;
}


// 整数値として有効かチェック
bool CheckNumber(const char *pszString)
{
	char *end;
	
	errno = 0;
	strtol(pszString, &end, 0);
	if ( errno != 0 || *end != '\0' )
	{
		return false;
	}

	return true;
}

// 識別子として有効かチェック
bool CheckIdentifier(const char *pszString)
{
	int c;

	// 先頭は英文字もしくは '_' でなければ違反
	c = *pszString++;
	if ( !(isalpha(c) || c == '_') )
	{
		return false;
	}

	// 後続は英数字または '_' でなければ違反
	while ( (c = *pszString++) != '\0' )
	{
		if ( !(isalnum(c) || c == '_' ) )
		{
			return false;
		}
	}

	return true;	// OK
}

