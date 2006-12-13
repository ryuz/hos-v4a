

#include <ctype.h>
#include <string>
#include <vector>
using namespace std;



#define TYPE_INT	1000


#define TYPE_PLUS	2007	// "+"
#define TYPE_MINUS	2008	// "-"
#define TYPE_MUL	2009	// "*"
#define TYPE_DIV	2010	// "/"
#define TYPE_MOD	2011	// "%"
#define TYPE_EQ		2001	// "=="
#define TYPE_NE		2002	// "!="		
#define TYPE_LT		2003	// "<""
#define TYPE_LE		2005	// "<="
#define TYPE_SL		2020	// "<<"
#define TYPE_GT		2004	// ">"
#define TYPE_GE		2006	// ">="
#define TYPE_SR		2019	// ">>"
#define TYPE_LNOT	2012	// "!"
#define TYPE_AND	2016	// "&"
#define TYPE_LAND	2013	// "&&"
#define TYPE_OR		2015	// "|"
#define TYPE_LOR	2014	// "||"
#define TYPE_XOR	2017	// "^"
#define TYPE_NOT	2018	// "~"
#define TYPE_LP		2021	// "("
#define TYPE_RP		2022	// ")"


struct TTerm
{
	int iType;
	int iValue;
};


/* 定数式計算クラス */
class CExpression
{
public:
	static bool Calc(const char *pszExpression, int &piValue);					// 計算する

protected:
	static bool Scanner(vector<TTerm> &vectTerm, const char *pszExpression);	// レキシカルアナライザ
	static bool Parser(vector<TTerm> &vectTerm, int iIndex);					// パーサー
};


// 計算する
bool CExpression::Calc(const char *pszExpression, int &piValue)
{

}

bool CExpression::Calc(vector<TTerm> &vectTerm, const char *pszExpression, int &piValue)
{

}

	vector<TTerm> vectTerm;
	TTerm Term;
	int   c;

	/* 字句解析 */
	while ( (c = *pszExpression++) != '\0' )
	{
		if ( c == '0' )		/* HEX or OCT */
		{
			c = *pszExpression++;
			if ( (c == 'x' || c == 'X') && isxdigit(*pszExpression) )	/* HEX */
			{
				Term.iType  = TYPE_INT;
				Term.iValue = 0;
				for ( ; ; )
				{
					c = *pszExpression++;
					if ( !isxdigit(c) )
					{
						vectTerm.push_back(Term);
						pszExpression--;
						break;
					}
					Term.iValue *= 16;
					if ( c >= 'a' && c <= 'f' )
					{
						Term.iValue += c - 'a' + 10;
					}
					else if ( c >= 'A' && c <= 'F' )
					{
						Term.iValue += c - 'A' + 10;
					}
					else
					{
						Term.iValue += c - '0';
					}
				}
				continue;
			}
			else if ( c >= '0' && c <= '9' )	/* OCT */
			{
				Term.iType  = TYPE_INT;
				Term.iValue = 0;
				for ( ; ; )
				{
					c = *pszExpression++;
					if ( c < '0' || c > '7' )
					{
						vectTerm.push_back(Term);
						pszExpression--;
						break;
					}
					Term.iValue *= 8;
					Term.iValue += c - '0';
				}
				continue;
			}
			else
			{
				return false;
			}
		}
		else if ( isdigit(c) )		/* DEC */
		{
			Term.iType  = TYPE_INT;
			Term.iValue = c - '0';
			for ( ; ; )
			{
				c = *pszExpression++;
				if ( !isdigit(c) )
				{
					vectTerm.push_back(Term);
					pszExpression--;
					break;
				}
				Term.iValue *= 10;
				Term.iValue += c - '0';
			}
			continue;
		}
		else if ( c == '+' )
		{
			Term.iType  = TYPE_PLUS;
			vectTerm.push_back(Term);		// "+"
		}
		else if ( c == '-' )
		{
			Term.iType  = TYPE_MINUS;		// "-"
			vectTerm.push_back(Term);
		}
		else if ( c == '*' )
		{
			Term.iType  = TYPE_MUL;			// "*"
			vectTerm.push_back(Term);
		}
		else if ( c == '/' )
		{
			Term.iType  = TYPE_DIV;			// "/"
			vectTerm.push_back(Term);
		}
		else if ( c == '%' )
		{
			Term.iType  = TYPE_MOD;			// "%"
			vectTerm.push_back(Term);
		}
		else if ( c == '=' )
		{
			c = *pszExpression++;
			if ( c == '=' )
			{
				Term.iType  = TYPE_EQ;		// "=="
				vectTerm.push_back(Term);
			}
			else
			{
				return false;
			}
		}
		else if ( c == '!' )
		{
			c = *pszExpression++;
			if ( c == '=' )
			{
				Term.iType  = TYPE_NE;		// " !="
				vectTerm.push_back(Term);
			}
			else
			{
				pszExpression--;
				Term.iType  = TYPE_LNOT;	// "!"
				vectTerm.push_back(Term);
			}
		}
		else if ( c == '<' )
		{
			c = *pszExpression++;
			if ( c == '=' )
			{
				Term.iType  = TYPE_LE;		// "<="
				vectTerm.push_back(Term);
			}
			else if ( c == '<' )
			{
				Term.iType  = TYPE_SL;		// "<<"
				vectTerm.push_back(Term);
			}
			else
			{
				pszExpression--;
				Term.iType  = TYPE_LT;		// "<""
				vectTerm.push_back(Term);
			}
		}
		else if ( c == '>' )
		{
			c = *pszExpression++;
			if ( c == '=' )
			{
				Term.iType  = TYPE_GE;		// ">="
				vectTerm.push_back(Term);
			}
			else if ( c == '>' )
			{
				Term.iType  = TYPE_SR;		// ">>"
				vectTerm.push_back(Term);
			}
			else
			{
				pszExpression--;
				Term.iType  = TYPE_GT;		// ">"
				vectTerm.push_back(Term);
			}
		}
		else if ( c == '&' )
		{
			c = *pszExpression++;
			if ( c == '&' )
			{
				Term.iType  = TYPE_LAND;	// "&&"
				vectTerm.push_back(Term);
			}
			else
			{
				pszExpression--;
				Term.iType  = TYPE_AND;		// "&"
				vectTerm.push_back(Term);
			}
		}
		else if ( c == '|' )
		{
			c = *pszExpression++;
			if ( c == '|' )
			{
				Term.iType  = TYPE_LOR;		// "||"
				vectTerm.push_back(Term);
			}
			else
			{
				pszExpression--;
				Term.iType  = TYPE_OR;		// "|"
				vectTerm.push_back(Term);
			}
		}
		else if ( c == '^' )
		{
			Term.iType  = TYPE_XOR;			// "^"
			vectTerm.push_back(Term);			
		}
		else if ( c == '~' )
		{
			Term.iType  = TYPE_NOT;			// "^"
			vectTerm.push_back(Term);			
		}
		else if ( c == '(' )
		{
			Term.iType  = TYPE_LP;			// "("
			vectTerm.push_back(Term);			
		}
		else if ( c == ')' )
		{
			Term.iType  = TYPE_RP;			// ")"
			vectTerm.push_back(Term);			
		}
		else if ( isspace(c) )
		{
		}
		else
		{
			return false;
		}
	}

	return true;
}
