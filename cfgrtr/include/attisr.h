// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    ATT_ISR API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_AttIsr_h__
#define __HOSV4CFG_AttIsr_h__


#include "apidef.h"
#include "parpack.h"


// ATT_ISR 用
class CApiAttIsr : public CApiDef
{
public:
	CApiAttIsr();		// コンストラクタ
	~CApiAttIsr();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);	// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);	// cfgファイル初期化部書き出し

protected:
	int   m_iMinIntNo;	
	int   m_iMaxIntNo;
	char* m_pszRegBase;
};


#endif	// __HOSV4CFG_AttIsr_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
