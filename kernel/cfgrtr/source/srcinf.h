
#ifndef __srcinf_h__
#define __srcinf_h__


#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif

#include <string>
using namespace std;


// ソースファイルの情報
struct TSourceInfo
{
	string m_strFileName;	// 入力ファイル名
	int    m_iLineNum;		// 処理中の行番号
	int    m_iColumnNum;	// 処理中の桁番号
};


#endif	// __srcinf_h__
