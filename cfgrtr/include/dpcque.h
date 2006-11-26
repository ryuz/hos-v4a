// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Advance コンフィギュレーター                           
//    KERNEL_DPC_QUE API の処理                                                    
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_DpcQue_h__
#define __HOSV4CFG_DpcQue_h__


#include "apidef.h"
#include "parpack.h"


// HOS_KERNEL_HEAP 用
class CApiDpcQue : public CApiDef
{
public:
	CApiDpcQue();		// コンストラクタ
	~CApiDpcQue();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);		// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);
};


#endif	// __HOSV4CFG_IdleStack_h__

