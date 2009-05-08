// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    DEF_EXC API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_DefExc_h__
#define __HOSV4CFG_DefExc_h__


#include "apidef.h"
#include "parpack.h"


// DEF_EXC 用
class CApiDefExc : public CApiDef
{
public:
	CApiDefExc();		// コンストラクタ
	~CApiDefExc();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);	// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);	// cfgファイル初期化部書き出し

protected:
	int m_iMaxExcNo;
	int m_iMinExcNo;
};


#endif	// __HOSV4CFG_DefExc_h__


// end of file
