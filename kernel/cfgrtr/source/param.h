

#ifndef __param_h__
#define __param_h__

#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif

#include <string>
#include <vector>
using namespace std;


// パラメータタイプ
#define PARAM_TYPE_STRING			0
#define PARAM_TYPE_BLOCK			1

class CParamBlock;

// パラメータ情報
struct TParam
{
	int iType;						// パラメータのタイプ
	union
	{
		string*      pstrString;	// 文字列
		CParamBlock* pvctBlock;		// パラメータブロック
	};
};


// パラメータブロック格納クラス
class CParamBlock
{
public:
	CParamBlock();
	CParamBlock(CParamBlock& block); 
	~CParamBlock();
	CParamBlock& operator=(CParamBlock& block);
	void         Clear(void);

	int          GetSize(void) const { return m_vectParam.size(); }
	
	void         AddString(const char *pszString);
	CParamBlock* AddParamBlock(void);

	int          GetType(int iIndex)		{ return m_vectParam.at(iIndex).iType; }
	const char*  GetString(int iIndex)		{ return m_vectParam.at(iIndex).pstrString->c_str(); }
	CParamBlock* GetParamBlock(int iIndex)	{ return m_vectParam.at(iIndex).pvctBlock; }

protected:
	vector<TParam> m_vectParam;		// パラメータ配列
};


#endif	/* __param_h__ */
