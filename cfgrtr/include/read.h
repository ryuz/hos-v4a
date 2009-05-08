// ---------------------------------------------------------------------------
//  HOS V4 コンフィギュレーター Ver 1.00                                      
//    データ読み込みクラス                                                    
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------



#ifndef __HOSV4CFG_Read_h__
#define __HOSV4CFG_Read_h__


#define READ_MAX_PATH		1024	// 最大パス名
#define READ_MAX_STATE		4096	// １ステートの最大文字数


// データ読み込みクラス
class CRead
{
public:
	CRead(FILE *fp, const char *name);			// コンストラクタ
	~CRead();						// デストラクタ

	int ReadState(char *szState);	// １ステート読み込み
	int GetPhysicalLineNum(void)	// 実際に読み込み中のファイルの行番号取得
	{ return m_iPhysicalLineNum; }
	int GetLogicalLineNum(void)	// cppを通す前のファイルの行番号取得
	{ return m_iLogicalLineNum; }
	const char *GetLogicalInputFile(void)
	{ return m_szLogicalInputFile; }

protected:
       int SkipPreProcessorLine(char* szText, int iCount);     // プリプロセッサラインのスキップ
	int ReadString(int cDelimiter, char* szText, int& iCount);	// 文字列読み込み

	FILE *m_fpRead;					// 読み込み用ファイルポインタ
	int  m_iPhysicalLineNum;			// 実際に読み込み中のファイルの行番号
	int  m_iLogicalLineNum;				// cppを通す前のファイルの行番号
	bool m_blLineTop;				// 行の先頭
	char m_szLogicalInputFile[READ_MAX_PATH];	// cppを通す前のファイル名
};


#endif	// __HOSV4CFG_Read_h__


// end of file
