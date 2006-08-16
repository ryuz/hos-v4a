// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_MBX API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_CreMbx_h__
#define __HOSV4CFG_CreMbx_h__


#include "apidef.h"
#include "parpack.h"


// CRE_MBX 用
class CApiCreMbx : public CApiDef
{
public:
	CApiCreMbx();		// コンストラクタ
	~CApiCreMbx();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	void  WriteId(FILE* fp);					// ID 定義ファイル書き出し
	void  WriteCfgDef(FILE* fp);				// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);				// cfgファイル初期化部書き出し
	void  WriteCfgStart(FILE* fp);				// cfgファイル起動部書き出し

protected:
	void  WriteMbxcbRam(FILE *fp, int iObj);	// MBXCB情報書き出し(RAM部)
	void  WriteMbxcbRom(FILE *fp, int iObj);	// MBXCB情報書き出し(ROM部)
};


#endif	// __HOSV4CFG_CreMbx_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
