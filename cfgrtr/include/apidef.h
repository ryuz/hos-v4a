// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Adcance コンフィギュレーター
//    API定義クラス
//
//                                    Copyright (C) 1998-2009 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/
// ---------------------------------------------------------------------------


#ifndef __HOSV4ACFG_ApiDef_h__
#define __HOSV4ACFG_ApiDef_h__


#include "parpack.h"


#define API_MAX_OBJS		1024		// 最大オブジェクト数
#define API_MAX_PARAM		4096		// 最大パラメータ文字数


// API定義クラス
class CApiDef
{
public:
	CApiDef();				// コンストラクタ
	virtual ~CApiDef();		// デストラクタ

	virtual int   AnalyzeApi(const char* pszApiName, const char* pszParams) = 0;	// APIの解析
	virtual int   AutoId(void);							// 自動ID番号割り当て
	virtual void  WriteId(FILE* fp);					// ID 定義ファイル書き出し
	virtual void  WriteCfgDef(FILE* fp);				// cfgファイル定義部書き出し
	virtual void  WriteCfgIni(FILE* fp);				// cfgファイル初期化部書き出し
	virtual void  WriteCfgStart(FILE* fp);				// cfgファイル起動部書き出し

protected:
	virtual int   AddParams(const char* pszParams);		// パラメーター追加
	virtual int   IdToObjNum(int iId);					// IDをオブジェクト番号に変換

	CParamPack* m_pParamPacks[API_MAX_OBJS];			// パラメーターリスト
	int         m_iId[API_MAX_OBJS];					// ID番号リスト
	int         m_iObjs;								// オブジェクト数
	int         m_iResObj;								// 予約オブジェクト数
	int         m_iMaxId;								// 最大ID 番号
	int         m_iDefaultMaxId;						// デフォルトのMaxID
	int         m_iParams;								// パラメーター数
	int         m_iParamSyntax[PARAMPACK_MAX];			// パラメーター構文
};


#endif	// __HOSV4ACFG_ApiDef_h__



// end of file
