// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    HOS_KERNEL_HEAP API の処理                                              
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_KernelHeap_h__
#define __HOSV4CFG_KernelHeap_h__


#include "apidef.h"
#include "parpack.h"


// HOS_KERNEL_HEAP 用
class CApiKernelHeap : public CApiDef
{
public:
	CApiKernelHeap();		// コンストラクタ
	~CApiKernelHeap();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);		// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);		// cfgファイル起動部書き出し
};


#endif	// __HOSV4CFG_KernelHeap_h__



// end of file
