// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_FLG API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_CreFlg_h__
#define __HOSV4CFG_CreFlg_h__


#include "apidef.h"
#include "parpack.h"


// CRE_FLG 用
class CApiCreFlg : public CApiDef
{
public:
	CApiCreFlg();		// コンストラクタ
	~CApiCreFlg();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	void  WriteId(FILE* fp);					// ID 定義ファイル書き出し
	void  WriteCfgDef(FILE* fp);				// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);				// cfgファイル初期化部書き出し
	void  WriteCfgStart(FILE* fp);				// cfgファイル起動部書き出し

protected:
	void  WriteFlgcbRam(FILE *fp, int iObj);
	void  WriteFlgcbRom(FILE *fp, int iObj);
};


#endif	// __HOSV4CFG_CreFlg_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
