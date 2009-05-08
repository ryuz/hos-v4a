// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    HOS_MAX_TPRI API の処理                                                 
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_ApiMaxTpri_h__
#define __HOSV4CFG_ApiMaxTpri_h__


#include "apidef.h"
#include "parpack.h"


// HOS_MAX_TPRI 用
class CApiMaxTpri : public CApiDef
{
public:
	CApiMaxTpri();		// コンストラクタ
	~CApiMaxTpri();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	int   AutoId(void);							// 自動ID番号割り当て
	void  WriteCfgDef(FILE* fp);				// cfgファイル定義部書き出し

protected:
	int m_iMaxPri;
};


#define DEFAULT_MAXTPRI	16


#endif	// __HOSV4CFG_ApiMaxTpri_h__


// end of file
