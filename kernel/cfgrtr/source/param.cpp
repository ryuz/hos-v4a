

#include <stdio.h>
#include <ctype.h>
#include "param.h"



// コンストラクタ
CParamBlock::CParamBlock()
{
}


// コピーコンストラクタ
CParamBlock::CParamBlock(CParamBlock& block)
{
	*this = block;
}


// デストラクタ
CParamBlock::~CParamBlock()
{
	Clear();
}


// 代入演算子
CParamBlock& CParamBlock::operator=(CParamBlock& block)
{
	int i;
	for ( i = 0; i < block.GetSize(); i++ )
	{
		if ( block.GetType(i) == PARAM_TYPE_STRING )
		{
			AddString(block.GetString(i));
		}
		else
		{
			CParamBlock *pBlock;
			pBlock = AddParamBlock();
			*pBlock = block;
		}
	}

	return block;
}


// クリア
void CParamBlock::Clear(void)
{
	int i;
	for ( i = 0; i < GetSize(); i++ )
	{
		if ( m_vectParam[i].iType == PARAM_TYPE_STRING )
		{
			delete m_vectParam[i].pstrString;
		}
		else
		{
			delete m_vectParam[i].pvctBlock;
		}
	}
	m_vectParam.clear();
}


// 文字列パラメータ追加
void CParamBlock::AddString(const char *pszString)
{
	TParam param;
	param.iType = PARAM_TYPE_STRING;
	param.pstrString = new string(pszString);
	m_vectParam.push_back(param);
}


// パラメータブロックの追加
CParamBlock* CParamBlock::AddParamBlock(void)
{
	TParam param;
	param.iType = PARAM_TYPE_BLOCK;
	param.pvctBlock = new CParamBlock();
	m_vectParam.push_back(param);

	return param.pvctBlock;
}


// end of file
