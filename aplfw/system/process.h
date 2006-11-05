/* */

#ifndef __HOS__process_h__
#define __HOS__process_h__

#include "system/handle.h"
#include "system/file.h"


/* (とりあえず適当、そのうちTSSとか真面目にやるときの為にひとまず) */
#define PROCESS_PRIORITY_IDLE		14
#define PROCESS_PRIORITY_LOW		13
#define PROCESS_PRIORITY_NORMAL		12
#define PROCESS_PRIORITY_HIGH		11


/* プロセスオブジェクト基本クラス定義 */
typedef struct c_processobj
{
	C_HANDLEOBJ HandleObj;						/* ハンドルオブジェクトを継承(そのうちC_FILEOBJからの継承に拡張してもいいかも？) */
	
	int         (*pfncEntry)(void *pParam);		/* エントリーアドレス */
	HANDLE      hTty;							/* ターミナル入出力 */
	HANDLE      hStdIn;							/* 標準入力 */
	HANDLE      hStdOut;						/* 標準出力 */
	HANDLE      hStdErr;						/* 標準エラー出力 */

#if 0	/* まあ、そのうちやりたいなっと */
	int         iExitCode;						/* 終了コード */
	HANDLE		*pHandleList;					/* 所有するハンドルのリスト(終了時に開放) */
	char		szCurrentDir[FILE_MAX_PATH];	/* カレントディレクトリ */
#endif
} C_PROCESSOBJ;



#ifdef __cplusplus
extern "C" {
#endif

/* ユーザーAPI */
HANDLE Process_Create(int (*pfncEntry)(void *pParam), void *pParam, long StackSize, int Priority);
void   Process_Exit(int iExitCode);
HANDLE Process_GetCurrentHandle(void);


/* 内部のもの(とりあえず.. そのうちヘッダ分けまふ）*/
void   ProcessObj_Create(C_PROCESSOBJ *self, const T_HANDLEOBJ_METHODS *pMethods);	/* コンストラクタ */
void   ProcessObj_Delete(C_PROCESSOBJ *self);											/* デストラクタ */

void Handle_Close(HANDLE handle);			/* ハンドルを閉じる */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__process_h__ */


/* end of file */
