// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Advance コンフィギュレーター
//    CRE_CYC API の処理
//
//                                    Copyright (C) 1998-2009 by Project HOS
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#ifndef __HOSV4ACFG_CreCyc_h__
#define __HOSV4ACFG_CreCyc_h__


#include "apidef.h"
#include "parpack.h"


// CRE_CYC 用
class CApiCreCyc : public CApiDef
{
public:
	CApiCreCyc();		// コンストラクタ
	~CApiCreCyc();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	void  WriteId(FILE* fp);					// ID 定義ファイル書き出し
	void  WriteCfgDef(FILE* fp);				// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);				// cfgファイル初期化部書き出し
	void  WriteCfgStart(FILE* fp);				// cfgファイル起動部書き出し

protected:
	void  WriteCyccbRam(FILE *fp, int iObj);	// CYCCB情報書き出し(RAM部)
	void  WriteCyccbRom(FILE *fp, int iObj);	// CYCCB情報書き出し(ROM部)
};


#endif	// __HOSV4ACFG_CreCyc_h__


// end of file
