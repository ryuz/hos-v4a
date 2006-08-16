// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_MPF API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_CreMpf_h__
#define __HOSV4CFG_CreMpf_h__


#include "apidef.h"
#include "parpack.h"


// CRE_MPF 用
class CApiCreMpf : public CApiDef
{
public:
	CApiCreMpf();		// コンストラクタ
	~CApiCreMpf();		// デストラクタ

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// APIの解析
	void  WriteId(FILE* fp);					// ID 定義ファイル書き出し
	void  WriteCfgDef(FILE* fp);				// cfgファイル定義部書き出し
	void  WriteCfgIni(FILE* fp);				// cfgファイル初期化部書き出し
	void  WriteCfgStart(FILE* fp);				// cfgファイル起動部書き出し

protected:
	void  WriteMpfcbRam(FILE *fp, int iObj);	// MPFCB情報書き出し(RAM部)
	void  WriteMpfcbRom(FILE *fp, int iObj);	// MPFCB情報書き出し(ROM部)

};


#endif	// __HOSV4CFG_CreMpf_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
