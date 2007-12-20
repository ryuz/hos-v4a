// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_MTX API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_CreMtx_h__
#define __HOSV4CFG_CreMtx_h__


#include "apidef.h"
#include "parpack.h"


// CRE_MTX 用
class CApiCreMtx : public CApiDef
{
public:
	CApiCreMtx();		// コンストラクタ
	~CApiCreMtx();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	void  WriteId(FILE* fp);					// ID 定義ファイル書き出し
	void  WriteCfgDef(FILE* fp);				// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);				// cfgファイル初期化部書き出し
	void  WriteCfgStart(FILE* fp);				// cfgファイル起動部書き出し

protected:
	void  WriteMtxcbRam(FILE *fp, int iObj);	// MTXCB情報書き出し(RAM部)
	void  WriteMtxcbRom(FILE *fp, int iObj);	// MTXCB情報書き出し(ROM部)
};


#endif	// __HOSV4CFG_CreMtx_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2007 by Project HOS                                    
// ---------------------------------------------------------------------------
