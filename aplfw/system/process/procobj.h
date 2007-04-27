/* */

#ifndef __HOS__procobj_h__
#define __HOS__procobj_h__


#include "system/process/process.h"
#include "system/sysapi/sysapi.h"


/* プロセスオブジェクト基本クラス定義 */
typedef struct c_processobj
{
	C_HANDLEOBJ    HandleObj;					/* ハンドルオブジェクトを継承(そのうちC_FILEOBJからの継承に拡張してもいいかも？) */
	SYSPRC_HANDLE  hSysPrc;

	int            (*pfncEntry)(VPARAM pParam);	/* エントリーアドレス */
	VPARAM         Param;						/* 起動パラメータ */
	
	T_PROCESS_INF  Info;

	int         iExitCode;						/* 終了コード */

#if 0	/* まあ、そのうちやりたいなっと */
	HANDLE		*pHandleList;					/* 所有するハンドルのリスト(終了時に開放) */
	char		szCurrentDir[FILE_MAX_PATH];	/* カレントディレクトリ */
#endif
} C_PROCESSOBJ;



#ifdef __cplusplus
extern "C" {
#endif

/* 内部のもの(とりあえず.. そのうちヘッダ分けまふ）*/
void   ProcessObj_Create(C_PROCESSOBJ *self);		/* コンストラクタ */
void   ProcessObj_Delete(C_PROCESSOBJ *self);		/* デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__process_h__ */


/* end of file */
