// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    パラメーター格納クラス                                                  
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG__ParamPack_h__
#define __HOSV4CFG__ParamPack_h__


#define PARAMPACK_MAX	16


// パラメーター格納クラス
class CParamPack
{
public:
	CParamPack();		// コンストラクタ
	~CParamPack();		// デストラクタ

	void        SetParam(int iIndex, const char *pszParam);	// パラメーター設定
	const char* GetParam(int iIndex);						// パラメーター取得

protected:
	char *m_pszParam[PARAMPACK_MAX];
};


#endif	// __HOSV4CFG__ParamPack_h__



// end of file
