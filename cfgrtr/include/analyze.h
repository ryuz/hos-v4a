// ---------------------------------------------------------------------------
//  Hyper Operating System V4 Adcance コンフィギュレーター
//    構文解析クラス                                                          
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4ACFG__Analyze_h__
#define __HOSV4ACFG__Analyze_h__



// 構文解析クラス
class CAnalyze
{
public:
	static int  SplitState(char* pszApiName, char* pszParams, const char *pszState);	// ステートメントをAPI名とパラメーターに分割
	static int  SearchChar(char* pszBuf, const char* &pszText, char c);		// 特定文字のまでの切り出し
	static int  GetParameter(char* pszBuf, const char* &pszText);			// パラメーターの切り出し
	static int  DecodeText(char *pszBuf, const char* pszText);				// 文字列定数を展開する
	static void SpaceCut(char* pszText);			// 前後の空白を削除する
};


#endif	// __HOSV4ACFG__Analyze_h__


// end of file
