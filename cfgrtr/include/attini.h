// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    ATT_INI API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_ApiAttIni_h__
#define __HOSV4CFG_ApiAttIni_h__


#include "apidef.h"
#include "parpack.h"


// ATT_INI 用
class CApiAttIni : public CApiDef
{
public:
	CApiAttIni();		// コンストラクタ
	~CApiAttIni();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	int   AutoId(void);							// 自動ID番号割り当て
	void  WriteCfgStart(FILE* fp);				// cfgファイル定義部書き出し
};


#endif	// __HOSV4CFG_ApiAttIni_h__



// end of file
