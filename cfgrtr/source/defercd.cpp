// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    エラーコード管理                                                        
//                                                                            
//                                    Copyright (C) 1998-2003 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include "defercd.h"


static const char *szErrMsg[] =
	{
		"unanticipated EOF.",		// 予期せぬEOF
		"illegal CR.",				// 不正な改行
		"status too long.",			// １ステートが長すぎる
		"syntax error."	,			// 構文エラー
		"expect \')\' but found.",	// ()の不整合
		"expect \'}\' but found.",	// {}の不整合
		"expect \';\' but found.",	// セミコロンが無い
		"illegal text.",			// 不正な文字列定数
		"conflict ID.",				// ID衝突
		"illegal parameter.",		 // パラメーター不正
		"multiple definition.",		// 唯一であるべきAPI定義が複数
		"conflict definition.",		 // 定義衝突
	};


// エラー文字列取得
const char* GetErrMessage(int iErr)
{
	if ( iErr < 1 || iErr > (int)(sizeof(szErrMsg)/sizeof(char *)) )
	{
		return "unknown expression error.";
	}

	return szErrMsg[iErr - 1];
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2003 by Project HOS                                    
// ---------------------------------------------------------------------------
