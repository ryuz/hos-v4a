// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター
//    HOS_INT_STK API の処理
//
//                                    Copyright (C) 1998-2002 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_IntStack_h__
#define __HOSV4CFG_IntStack_h__


#include "apidef.h"
#include "parpack.h"


// HOS_KERNEL_HEAP 用
class CApiIntStack : public CApiDef
{
public:
	CApiIntStack();		// コンストラクタ
	~CApiIntStack();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);		// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);

	void  WriteStackMemory(FILE* fp);
	void  WriteStackPointer(FILE* fp);

protected:
	char  m_szStackPointer[API_MAX_PARAM];
};


#endif	// __HOSV4CFG_IntStack_h__



// end of file
