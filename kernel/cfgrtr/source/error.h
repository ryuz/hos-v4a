

#ifndef __error_h__
#define __error_h__


#define ERRTYPE_WARNING			1		// 警告
#define ERRTYPE_ERROR			2		// エラー
#define ERRTYPE_FATAL			3		// 致命エラー

#define FATAL_EOF				1		// 予期せぬEOF

#define ERROR_SYNTAX			1		// 予期せぬ文字
#define ERROR_SEMICOLON			2		// 予期せぬ ';'
#define ERROR_PAREN				3		// 括弧'()'が合わない
#define ERROR_BRACKET			4		// 中括弧'{}'が合わない
#define ERROR_FEW_PARAM			5		// パラメータが足りない
#define ERROR_ID_CONFRICT		10		// ID番号の衝突

#define WARNING_PARAM_EMPTY		1		// パラメータが空
#define WARNING_UNKNOWN_API		2		// 未知のAPIなので無視した
#define WARNING_MUCH_PARAM		3		// パラメータが多すぎるので後半を無視した
#define WARNING_DUPLEX			4		// 二重定義があったので最初のもの以外を無視した
#define WARNING_DEF_CONFRICT	5		// 矛盾する定義があったので最初のもの以外を無視した


class CError
{
public:
	static void PrintError(int iType, int iCode, const char *pszFile, int iLine, const char *pszApi);

protected:
	static const char *GetMessage(int iType, int iCode);
};


#endif	/* __error_h__ */

