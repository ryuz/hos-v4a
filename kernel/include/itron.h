/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  itron.h
 * @brief %en{uITRON4.0 standard header file}%jp{μITRON4.0用の標準ヘッダファイル}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__itron_h__
#define _KERNEL__itron_h__



/* ------------------------------------ */
/*             Constants                */
/* ------------------------------------ */

/* %jp{一般}%en{General Constants} */
#ifndef NULL
#ifdef __cplusplus
#define NULL					0						/**< %jp{無効ポインタ}%en{Invalid pointer} */
#else
#define NULL					((void *)0)				/**< %jp{無効ポインタ}%en{Invalid pointer} */
#endif
#endif


#define TRUE					1						/**< %jp{真}%en{True} */
#define FALSE					0						/**< %jp{偽}%en{Flase} */
#define E_OK					0						/**< %jp{正常終了}%en{Normal completion} */


/* %jp{オブジェクト属性}%en{Object Attributes} */
#define TA_NULL					0						/**< %jp{オブジェクト属性を指定しない}%en{Object attribute unspecified} */
#define TA_HLNG					0x00					/**< %jp{高級言語用のインターフェースで処理単位を起動}%en{Start a processing unit through a high-level language interface} */
#define TA_ASM					0x01					/**< %jp{アセンブリ言語用のインターフェースで処理単位を起動}%en{Start a processing unit through an assembly language interface} */

#define TA_TFIFO				0x00					/**< %jp{タスクの待ち行列をFIFO順に}%en{Task wait queue is in FIFO order} */
#define TA_TPRI					0x01					/**< %jp{タスクの待ち行列をタスクの優先度順に}%en{Task wait queue is in task priority order} */

#define TA_MFIFO				0x00					/**< %jp{メッセージの待ち行列をFIFO順に}%en{Message queue is in FIFO order} */
#define TA_MPRI					0x02					/**< %jp{メッセージの待ち行列をメッセージの優先度順に}%en{Message queue is in message priority order} */

#define TA_ACT					0x02					/**< %jp{タスクを起動された状態で生成}%en{Task is activated after the creation} */
#define TA_RSTR					0x04					/**< %jp{制約タスク}%en{Restricted task} */

#define TA_WSGL					0x00					/**< %jp{イベントフラグを複数のタスクが待つことを許さない}%en{Only one task is allowed to be in the waiting state for the eventflag} */
#define TA_WMUL					0x02					/**< %jp{イベントフラグを複数のタスクが待つことを許す}%en{Multiple tasks are allowed to be in the waiting state for the eventflag} */
#define TA_CLR					0x04					/**< %jp{待ち解除時にイベントフラグをクリア}%en{Eventflag's bit pattern is cleared when a task is released from the waiting state for that eventflag} */

#define TA_INHERIT				0x02					/**< %jp{ミューテックスが優先度継承プロトコルをサポート}%en{Mutex uses the priority inheritance protocol} */
#define TA_CEILING				0x03					/**< %jp{ミューテックスが優先度上限プロトコルをサポート}%en{Mutex uses the priority ceiling protocol} */

#define TA_STA					0x02					/**< %jp{周期ハンドラを動作している状態で生成}%en{Cyclic handler is in an operational state after the creation} */
#define TA_PHS					0x04					/**< %jp{周期ハンドラの位相を保存}%en{Cyclic handler is activated preserving the activation phase} */


/* %jp{タイムアウト指定} */
#define TMO_POL					0						/**< %jp{ポーリング}%en{Polling} */
#define TMO_FEVR				(-1)					/**< %jp{永久待ち}%en{Waiting forever} */
#define TMO_NBLK				(-2)					/**< %jp{ノンブロッキング}%en{Non-blocking} */


/* %jp{サービスコールの動作モード}%en{Service Call Operational Mode} */
#define TWF_ANDW				0x00					/**< %jp{イベントフラグのAND待ち}%en{AND waiting condition for eventflag} */
#define TWF_ORW					0x01					/**< %jp{イベントフラグのOR待ち}%en{OR waiting condition for eventflag} */


/* %jp{オブジェクトの状態}%en{Object State} */
#define TTS_RUN					0x01					/**< %jp{実行状態}%en{RUNNING state} */
#define TTS_RDY					0x02					/**< %jp{実行可能状態}%en{READY state} */
#define TTS_WAI					0x04					/**< %jp{待ち状態}%en{WAITING state} */
#define TTS_SUS					0x08					/**< %jp{強制待ち状態}%en{SUSPENDED state} */
#define TTS_WAS					0x0c					/**< %jp{二重待ち状態}%en{WAITING-SUSPENDED state} */
#define TTS_DMT					0x10					/**< %jp{休止状態}%en{DORMANT state} */

#define TTW_SLP					0x0001					/**< %jp{起床待ち状態}%en{} */
#define TTW_DLY					0x0002					/**< %jp{時間経過待ち状態}%en{} */
#define TTW_SEM					0x0004					/**< %jp{セマフォ資源の獲得待ち状態}%en{} */
#define TTW_FLG					0x0008					/**< %jp{イベントフラグ待ち状態}%en{} */
#define TTW_SDTQ				0x0010					/**< %jp{データキューへの送信待ち状態}%en{} */
#define TTW_RDTQ				0x0020					/**< %jp{データキューからの受信待ち状態}%en{} */
#define TTW_MBX					0x0040					/**< %jp{メールボックスからの受信待ち状態}%en{} */
#define TTW_MTX					0x0080					/**< %jp{ミューテックスのロック待ち状態}%en{} */
#define TTW_SMBF				0x0100					/**< %jp{メッセージバッファへの送信待ち状態}%en{} */
#define TTW_RMBF				0x0200					/**< %jp{メッセージバッファからの受信待ち状態}%en{} */
#define TTW_CAL					0x0400					/**< %jp{ランデブの呼び出し待ち状態}%en{} */
#define TTW_ACP					0x0800					/**< %jp{ランデブの受付待ち状態}%en{} */
#define TTW_RDV					0x1000					/**< %jp{ランデブの終了待ち状態}%en{} */
#define TTW_MPF					0x2000					/**< %jp{固定長メモリブロックの獲得待ち状態}%en{} */
#define TTW_MPL					0x4000					/**< %jp{可変長メモリブロックの獲得待ち状態}%en{} */

#define TTEX_ENA				0x00					/**< %jp{タスクの例外処理許可状態}%en{} */
#define TTEX_DIS				0x01					/**< %jp{タスク例外処理禁止状態}%en{} */

#define TCYC_STP				0x00					/**< %jp{周期ハンドラが動作していない}%en{} */
#define TCYC_STA				0x01					/**< %jp{周期ハンドラが動作している}%en{} */

#define TALM_STP				0x00					/**< %jp{アラームハンドラが動作していない}%en{} */
#define TALM_STA				0x00					/**< %jp{アラームハンドラが動作している} */

#define TOVR_STP				0x00					/**< %jp{上限プロセッサ時間が設定されていない}%en{} */
#define TOVR_STA				0x01					/**< %jp{上限プロセッサ時間が設定されている}%en{} */

/* %jp{その他の定数}%en{Other constants} */
#define TSK_SELF				0						/**< %jp{自タスク指定}%en{} */
#define TSK_NONE				0						/**< %jp{該当するタスクが無い}%en{} */

#define TPRI_SELF				0						/**< %jp{自タスクのベース優先度の指定}%en{} */
#define TPRI_INI				0						/**< %jp{タスクの起動時優先度の指定}%en{} */


/* %jp{エラーコード}%en{Error code} */
#define E_SYS					(-5)					/**< %jp{システムエラー}%en{System error} */
#define E_NOSPT					(-9)					/**< %jp{未サポート機能}%en{Unsupported function} */
#define E_RSFN					(-10)					/**< %jp{予約機能コード}%en{Reserved function code} */
#define E_RSATR					(-11)					/**< %jp{予約属性}%en{Reserved attribute} */
#define E_PAR					(-17)					/**< %jp{パラメータエラー}%en{Parameter error} */
#define E_ID					(-18)					/**< %jp{不正ID番号}%en{Invalid ID number} */
#define E_CTX					(-25)					/**< %jp{コンテキストエラー}%en{Context error} */
#define E_MACV					(-26)					/**< %jp{メモリアクセス違反}%en{} */
#define E_OACV					(-27)					/**< %jp{オブジェクトアクセス違反}%en{} */
#define E_ILUSE					(-28)					/**< %jp{サービスコール不正使用}%en{} */
#define E_NOMEM					(-33)					/**< %jp{メモリ不足}%en{} */
#define E_NOID					(-34)					/**< %jp{ID番号不足}%en{} */
#define E_OBJ					(-41)					/**< %jp{オブジェクト状態エラー}%en{} */
#define E_NOEXS					(-42)					/**< %jp{オブジェクト未生成}%en{} */
#define E_QOVR					(-43)					/**< %jp{キューイングオーバーフロー}%en{} */
#define E_RLWAI					(-49)					/**< %jp{待ち状態の強制解除}%en{} */
#define E_TMOUT					(-50)					/**< %jp{ポーリング失敗またはタイムアウト}%en{} */
#define E_DLT					(-51)					/**< %jp{待ちオブジェクトの削除}%en{} */
#define E_CLS					(-52)					/**< %jp{待ちオブジェクトの状態変化}%en{} */
#define E_WBLK					(-57)					/**< %jp{ノンブロッキング受付け}%en{} */
#define E_BOVR					(-58)					/**< %jp{バッファオーバーフロー}%en{} */



#define TMIN_TPRI				1
#define TMIN_MPRI				1




/* ------------------------------------ */
/*     Include configulation file       */
/* ------------------------------------ */

#include "core/basetyp.h"
#include "config/cfgsys.h"
#include "parser/parssys.h"




/* ------------------------------------ */
/*             Data type                */
/* ------------------------------------ */

/* %jp{プリミティブ型を定義する} */
typedef _KERNEL_T_B				B;						/**< %jp{符号付き 8ビット整数}%en{Signed  8-bit integer} */
typedef _KERNEL_T_H				H;						/**< %jp{符号付き16ビット整数}%en{Signed 16-bit integer} */
typedef _KERNEL_T_W				W;						/**< %jp{符号付き32ビット整数}%en{Signed 32-bit integer} */
#if _KERNEL_ENABLE64
typedef _KERNEL_T_D				D;						/**< %jp{符号付き64ビット整数}%en{Signed 64-bit integer} */
#endif

typedef _KERNEL_T_UB			UB;						/**< %jp{符号無し 8ビット整数}%en{Unsigned  8-bit integer} */
typedef _KERNEL_T_UH			UH;						/**< %jp{符号無し16ビット整数}%en{Unsigned 16-bit integer} */
typedef _KERNEL_T_UW			UW;						/**< %jp{符号無し32ビット整数}%en{Unsigned 32-bit integer} */
#if _KERNEL_ENABLE64
typedef _KERNEL_T_UD			UD;						/**< %jp{符号付き64ビット整数}%en{Signed 64-bit integer} */
#endif

typedef B						VB;						/**< %jp{データタイプが定まらない 8ビットの値}%en{ 8-bit value with unknown data type} */
typedef H						VH;						/**< %jp{データタイプが定まらない16ビットの値}%en{16-bit value with unknown data type} */
typedef W						VW;						/**< %jp{データタイプが定まらない32ビットの値}%en{32-bit value with unknown data type} */
#if _KERNEL_ENABLE64
typedef D						VD;						/**< %jp{データタイプが定まらない64ビットの値}%en{64-bit value with unknown data type} */
#endif



/* %jp{INT型を定義する} */
#if _KERNEL_TBIT_INT == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		INT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Signed integer for the processor} */
#define _KERNEL_TMIN_INT		_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_INT		_KERNEL_TMAX_PROC_INT

#elif _KERNEL_TBIT_INT == 8			/* 8-bit */

typedef _KERNEL_T_B				INT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Signed integer for the processor} */
#define _KERNEL_TMIN_INT		_KERNEL_TMIN_B
#define _KERNEL_TMAX_INT		_KERNEL_TMAX_B

#elif _KERNEL_TBIT_INT == 16			/* 16-bit */

typedef _KERNEL_T_H				INT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Signed integer for the processor} */
#define _KERNEL_TMIN_INT		_KERNEL_TMIN_H
#define _KERNEL_TMAX_INT		_KERNEL_TMAX_H

#elif _KERNEL_TBIT_INT == 32			/* 32-bit */

typedef _KERNEL_T_W				INT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Signed integer for the processor} */
#define _KERNEL_TMIN_INT		_KERNEL_TMIN_W
#define _KERNEL_TMAX_INT		_KERNEL_TMAX_W

#elif _KERNEL_TBIT_INT == 64			/* 64-bit */

typedef _KERNEL_T_D				INT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Signed integer for the processor} */
#define _KERNEL_TMIN_INT		_KERNEL_TMIN_D
#define _KERNEL_TMAX_INT		_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_INT

#endif



/* %jp{UINT型を定義する} */
#if _KERNEL_TBIT_UINT == _KERNEL_TBIT_PROC_UINT

typedef _KERNEL_T_PROC_UINT		UINT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Unsigned integer for the processor}  */
#define _KERNEL_TMIN_UINT		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_UINT		_KERNEL_TMAX_PROC_UINT

#elif _KERNEL_TBIT_UINT == 8			/* 8-bit */

typedef _KERNEL_T_UB			UINT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Unsigned integer for the processor}  */
#define _KERNEL_TMIN_UINT		_KERNEL_TMIN_UB
#define _KERNEL_TMAX_UINT		_KERNEL_TMAX_UB

#elif _KERNEL_TBIT_UINT == 16		/* 16-bit */

typedef _KERNEL_T_UH			UINT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Unsigned integer for the processor} */
#define _KERNEL_TMIN_UINT		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_UINT		_KERNEL_TMAX_UH

#elif _KERNEL_TBIT_UINT == 32		/* 32-bit */

typedef _KERNEL_T_UW			UINT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Unsigned integer for the processor} */
#define _KERNEL_TMIN_UINT		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_UINT		_KERNEL_TMAX_UW

#elif _KERNEL_TBIT_UINT == 64		/* 64-bit */

typedef _KERNEL_T_UD			UINT;					/**< %jp{プロセッサに自然なサイズの符号付き整数}%en{Unsigned integer for the processor} */
#define _KERNEL_TMIN_UINT		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_UINT		_KERNEL_TMAX_UD

#else								/* error */

#error Illegal value : _KERNEL_TBIT_UINT

#endif



/* %jp{ポインタ型} */
typedef _KERNEL_T_VP			VP;						/**< %jp{データタイプが定まらないものへのポインタ}%en{Pointer to an unknown data type} */



/* %jp{関数ポインタ型} */
typedef void					(*FP)();				/**< %jp{プログラムの起動番地(ポインタ)}%en{Processing unit start address(pointer to a function)} */
#define _KERNEL_TBIT_FP			_KERNEL_TBIT_VP



/* %jp{ポインタを格納できる整数型} */
#if _KERNEL_VP_INT_PTR		/* %jp{VP_INTをポインタ型にするなら} */

typedef _KERNEL_T_VP			VP_INT;					/**< %jp{データタイプが定まらないものへのポインタまたはプロセッサに自然なサイズの符号付き整数}%en{Pointer to an unknown data type, or a signed integer for the processor} */
#define _KERNEL_TBIT_VP_INT		_KERNEL_TBIT_VP

#else						/* %jp{VP_INTを整数型にするなら} */

#if (_KERNEL_TMIN_INTPTR >= _KERNEL_TMIN_INT) && (_KERNEL_TMAX_INTPTR <= _KERNEL_TMAX_INT)
typedef INT						VP_INT;					/**< %jp{データタイプが定まらないものへのポインタまたはプロセッサに自然なサイズの符号付き整数}%en{Pointer to an unknown data type, or a signed integer for the processor} */
#define _KERNEL_TMIN_VP_INT		_KERNEL_TMIN_INT
#define _KERNEL_TMAX_VP_INT		_KERNEL_TMAX_INT
#define _KERNEL_TBIT_VP_INT		_KERNEL_TBIT_INT
#else
typedef _KERNEL_T_INTPTR		VP_INT;					/**< %jp{データタイプが定まらないものへのポインタまたはプロセッサに自然なサイズの符号付き整数}%en{Pointer to an unknown data type, or a signed integer for the processor} */
#define _KERNEL_TMIN_VP_INT		_KERNEL_TMIN_INTPTR
#define _KERNEL_TMAX_VP_INT		_KERNEL_TMAX_INTPTR
#define _KERNEL_TBIT_VP_INT		_KERNEL_TBIT_INTPTR
#endif

#endif



/* %jp{BOOL型を定義する} */
#if _KERNEL_TBIT_BOOL == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		BOOL;					/**< %jp{真偽値}%en{Boolean value(TRUE or FALSE)} */
#define _KERNEL_TMIN_BOOL		_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_BOOL		_KERNEL_TMAX_PROC_INT

#elif _KERNEL_TBIT_BOOL == 8			/* 8-bit */

typedef _KERNEL_T_B				BOOL;					/**< %jp{真偽値}%en{Boolean value(TRUE or FALSE)} */
#define _KERNEL_TMIN_BOOL		_KERNEL_TMIN_B
#define _KERNEL_TMAX_BOOL		_KERNEL_TMAX_B

#elif _KERNEL_TBIT_BOOL == 16		/* 16-bit */

typedef _KERNEL_T_H				BOOL;					/**< %jp{真偽値}%en{Boolean value(TRUE or FALSE)} */
#define _KERNEL_TMIN_BOOL		_KERNEL_TMIN_H
#define _KERNEL_TMAX_BOOL		_KERNEL_TMAX_H

#elif _KERNEL_TBIT_BOOL == 32		/* 32-bit */

typedef _KERNEL_T_W				BOOL;					/**< %jp{真偽値}%en{Boolean value(TRUE or FALSE)} */
#define _KERNEL_TMIN_BOOL		_KERNEL_TMIN_W
#define _KERNEL_TMAX_BOOL		_KERNEL_TMAX_W

#elif _KERNEL_TBIT_BOOL == 64		/* 64-bit */

typedef _KERNEL_T_D				BOOL;					/**< %jp{真偽値}%en{Boolean value(TRUE or FALSE)} */
#define _KERNEL_TMIN_BOOL		_KERNEL_TMIN_D
#define _KERNEL_TMAX_BOOL		_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_BOOL

#endif



/* %jp{機能コードを定義する}%en{Function code} */
#if _KERNEL_TBIT_FN == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		FN;						/**< %jp{機能コード}%en{Function code(signed integer)} */
#define _KERNEL_TMIN_FN			_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_FN			_KERNEL_TMAX_PROC_INT

#elif _KERNEL_TBIT_FN == 8				/* 8-bit */

typedef _KERNEL_T_B				FN;						/**< %jp{機能コード}%en{Function code(signed integer)} */
#define _KERNEL_TMIN_FN			_KERNEL_TMIN_B
#define _KERNEL_TMAX_FN			_KERNEL_TMAX_B

#elif _KERNEL_TBIT_FN == 16			/* 16-bit */

typedef _KERNEL_T_H				FN;						/**< %jp{機能コード}%en{Function code(signed integer)} */
#define _KERNEL_TMIN_FN			_KERNEL_TMIN_H
#define _KERNEL_TMAX_FN			_KERNEL_TMAX_H

#elif _KERNEL_TBIT_FN == 32			/* 32-bit */

typedef _KERNEL_T_W				FN;						/**< %jp{機能コード}%en{Function code(signed integer)} */
#define _KERNEL_TMIN_FN			_KERNEL_TMIN_W
#define _KERNEL_TMAX_FN			_KERNEL_TMAX_W

#elif _KERNEL_TBIT_FN == 64			/* 64-bit */

typedef _KERNEL_T_D				FN;						/**< %jp{機能コード}%en{Function code(signed integer)} */
#define _KERNEL_TMIN_FN			_KERNEL_TMIN_D
#define _KERNEL_TMAX_FN			_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_CFG_TBIT_FN

#endif



/* %jp{エラーコード}%en{Error code(signed integer)} */
#if _KERNEL_TBIT_ER == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		ER;						/**< %jp{エラーコード}%en{Error code(signed integer)} */
#define _KERNEL_TMIN_ER			_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_ER			_KERNEL_TMAX_PROC_INT


#elif _KERNEL_TBIT_ER == 8			/* 8-bit */

typedef _KERNEL_T_B				ER;						/**< %jp{エラーコード}%en{Error code(signed integer)} */
#define _KERNEL_TMIN_ER			_KERNEL_TMIN_B
#define _KERNEL_TMAX_ER			_KERNEL_TMAX_B

#elif _KERNEL_TBIT_ER == 16			/* 16-bit */

typedef _KERNEL_T_H				ER;						/**< %jp{エラーコード}%en{Error code(signed integer)} */
#define _KERNEL_TMIN_ER			_KERNEL_TMIN_H
#define _KERNEL_TMAX_ER			_KERNEL_TMAX_H

#elif _KERNEL_TBIT_ER == 32			/* 32-bit */

typedef _KERNEL_T_W				ER;						/**< %jp{エラーコード}%en{Error code(signed integer)} */
#define _KERNEL_TMIN_ER			_KERNEL_TMIN_W
#define _KERNEL_TMAX_ER			_KERNEL_TMAX_W

#elif _KERNEL_TBIT_ER == 64			/* 64-bit */

typedef _KERNEL_T_D				ER;						/**< %jp{エラーコード}%en{Error code(signed integer)} */
#define _KERNEL_TMIN_ER			_KERNEL_TMIN_D
#define _KERNEL_TMAX_ER			_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_ER

#endif



/* %jp{オブジェクトID番号}%en{Object ID number(signed integer)} */
#if _KERNEL_TBIT_ID == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		ID;						/**< %jp{オブジェクトID番号}%en{Object ID number(signed integer)} */
#define _KERNEL_TMIN_ID			_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_ID			_KERNEL_TMAX_PROC_INT

#elif _KERNEL_TBIT_ID == 8			/* 8-bit */

typedef _KERNEL_T_B				ID;						/**< %jp{オブジェクトID番号}%en{Object ID number(signed integer)} */
#define _KERNEL_TMIN_ID			_KERNEL_TMIN_B
#define _KERNEL_TMAX_ID			_KERNEL_TMAX_B

#elif _KERNEL_TBIT_ID == 16			/* 16-bit */

typedef _KERNEL_T_H				ID;						/**< %jp{オブジェクトID番号}%en{Object ID number(signed integer)} */
#define _KERNEL_TMIN_ID			_KERNEL_TMIN_H
#define _KERNEL_TMAX_ID			_KERNEL_TMAX_H

#elif _KERNEL_TBIT_ID == 32			/* 32-bit */

typedef _KERNEL_T_W				ID;						/**< %jp{オブジェクトID番号}%en{Object ID number(signed integer)} */
#define _KERNEL_TMIN_ID			_KERNEL_TMIN_W
#define _KERNEL_TMAX_ID			_KERNEL_TMAX_W

#elif _KERNEL_TBIT_ID == 64			/* 8-bit */

typedef _KERNEL_T_D				ID;						/**< %jp{オブジェクトID番号}%en{Object ID number(signed integer)} */
#define _KERNEL_TMIN_ID			_KERNEL_TMIN_D
#define _KERNEL_TMAX_ID			_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_ID

#endif



/* %jp{オブジェクト属性}%en{Object attribute(unsigned integer)} */
#if _KERNEL_TBIT_ATR == _KERNEL_TBIT_PROC_UINT

typedef _KERNEL_T_PROC_UINT		ATR;					/**< %jp{オブジェクト状態}%en{Object state(unsigned integer)} */			
#define _KERNEL_TMIN_ATR		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_ATR		_KERNEL_TMAX_PROC_UINT

#elif _KERNEL_TBIT_ATR == 8			/* 8-bit */

typedef _KERNEL_T_UB			ATR;					/**< %jp{オブジェクト属性}%en{Object attribute(unsigned integer)} */
#define _KERNEL_TMIN_ATR		_KERNEL_TMIN_UB
#define _KERNEL_TMAX_ATR		_KERNEL_TMAX_UB

#elif _KERNEL_TBIT_ATR == 16		/* 16-bit */

typedef _KERNEL_T_UH			ATR;					/**< %jp{オブジェクト属性}%en{Object attribute(unsigned integer)} */
#define _KERNEL_TMIN_ATR		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_ATR		_KERNEL_TMAX_UH

#elif _KERNEL_TBIT_ATR == 32		/* 32-bit */

typedef _KERNEL_T_UW			ATR;					/**< %jp{オブジェクト属性}%en{Object attribute(unsigned integer)} */
#define _KERNEL_TMIN_ATR		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_ATR		_KERNEL_TMAX_UW

#elif _KERNEL_TBIT_ATR == 64		/* 64-bit */

typedef _KERNEL_T_UD			ATR;					/**< %jp{オブジェクト属性}%en{Object attribute(unsigned integer)} */
#define _KERNEL_TMIN_ATR		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_ATR		_KERNEL_TMAX_UD

#else								/* error */

#error Illegal value : _KERNEL_TBIT_ATR

#endif



/* %jp{オブジェクト状態}%en{Object state(unsigned integer)} */
#if _KERNEL_TBIT_STAT == _KERNEL_TBIT_PROC_UINT

typedef _KERNEL_T_PROC_UINT		STAT;					/**< %jp{オブジェクト状態}%en{Object state(unsigned integer)} */			
#define _KERNEL_TMIN_STAT		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_STAT		_KERNEL_TMAX_PROC_UINT

#elif _KERNEL_TBIT_STAT == 8		/* 8-bit */

typedef _KERNEL_T_UB			STAT;					/**< %jp{オブジェクト状態}%en{Object state(unsigned integer)} */			
#define _KERNEL_TMIN_STAT		_KERNEL_TMIN_UB
#define _KERNEL_TMAX_STAT		_KERNEL_TMAX_UB

#elif _KERNEL_TBIT_STAT == 16		/* 16-bit */

typedef _KERNEL_T_UH			STAT;					/**< %jp{オブジェクト状態}%en{Object state(unsigned integer)} */
#define _KERNEL_TMIN_STAT		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_STAT		_KERNEL_TMAX_UH

#elif _KERNEL_TBIT_STAT == 32		/* 32-bit */

typedef _KERNEL_T_UW			STAT;					/**< %jp{オブジェクト状態}%en{Object state(unsigned integer)} */
#define _KERNEL_TMIN_STAT		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_STAT		_KERNEL_TMAX_UW

#elif _KERNEL_TBIT_STAT == 64		/* 8-bit */

typedef _KERNEL_T_UD			STAT;					/**< %jp{オブジェクト状態}%en{Object state(unsigned integer)} */
#define _KERNEL_TMIN_STAT		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_STAT		_KERNEL_TMAX_UD

#else								/* error */

#error Illegal value : _KERNEL_CFG_TBIT_STAT

#endif



/* %jp{サービスコールの動作モード}%en{Service call operational mode(unsigned integer)} */
#if _KERNEL_TBIT_MODE == _KERNEL_TBIT_PROC_UINT

typedef _KERNEL_T_PROC_UINT		MODE;					/**< %jp{サービスコールの動作モード}%en{Service call operational mode(unsigned integer)} */
#define _KERNEL_TMIN_MODE		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_MODE		_KERNEL_TMAX_PROC_UINT

#elif _KERNEL_TBIT_MODE == 8		/* 8-bit */

typedef _KERNEL_T_UB			MODE;					/**< %jp{サービスコールの動作モード}%en{Service call operational mode(unsigned integer)} */
#define _KERNEL_TMIN_MODE		_KERNEL_TMIN_UB
#define _KERNEL_TMAX_MODE		_KERNEL_TMAX_UB

#elif _KERNEL_TBIT_MODE == 16		/* 16-bit */

typedef _KERNEL_T_UH			MODE;					/**< %jp{サービスコールの動作モード}%en{Service call operational mode(unsigned integer)} */
#define _KERNEL_TMIN_MODE		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_MODE		_KERNEL_TMAX_UH

#elif _KERNEL_TBIT_MODE == 32		/* 32-bit */

typedef _KERNEL_T_UW			MODE;					/**< %jp{サービスコールの動作モード}%en{Service call operational mode(unsigned integer)} */
#define _KERNEL_TMIN_MODE		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_MODE		_KERNEL_TMAX_UW

#elif _KERNEL_TBIT_MODE == 64		/* 8-bit */

typedef _KERNEL_T_UD			MODE;					/**< %jp{サービスコールの動作モード}%en{Service call operational mode(unsigned integer)} */
#define _KERNEL_TMIN_MODE		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_MODE		_KERNEL_TMAX_UD

#else								/* error */

#error Illegal value : _KERNEL_TBIT_MODE

#endif



/* %jp{優先度}%en{Priority(signed integer)} */
#if _KERNEL_TBIT_PRI == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		PRI;					/**< %jp{優先度(符号付き整数)}%en{Priority(signed integer)} */
#define _KERNEL_TMIN_PRI		_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_PRI		_KERNEL_TMAX_PROC_INT

#elif _KERNEL_CFG_TBIT_PRI == 8		/* 8-bit */

typedef _KERNEL_T_B				PRI;					/**< %jp{優先度(符号付き整数)}%en{Priority(signed integer)} */
#define _KERNEL_TMIN_PRI		_KERNEL_TMIN_B
#define _KERNEL_TMAX_PRI		_KERNEL_TMAX_B

#elif _KERNEL_CFG_TBIT_PRI == 16	/* 16-bit */

typedef _KERNEL_T_H				PRI;					/**< %jp{優先度(符号付き整数)}%en{Priority(signed integer)} */
#define _KERNEL_TMIN_PRI		_KERNEL_TMIN_H
#define _KERNEL_TMAX_PRI		_KERNEL_TMAX_H

#elif _KERNEL_CFG_TBIT_PRI == 32	/* 32-bit */

typedef _KERNEL_T_W				PRI;					/**< %jp{優先度(符号付き整数)}%en{Priority(signed integer)} */
#define _KERNEL_TMIN_PRI		_KERNEL_TMIN_W
#define _KERNEL_TMAX_PRI		_KERNEL_TMAX_W

#elif _KERNEL_CFG_TBIT_PRI == 64	/* 8-bit */

typedef _KERNEL_T_D				PRI;					/**< %jp{優先度(符号付き整数)}%en{Priority(signed integer)} */
#define _KERNEL_TMIN_PRI		_KERNEL_TMIN_D
#define _KERNEL_TMAX_PRI		_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_PRI

#endif



/* %jp{メモリ領域のサイズ(符号無し整数)}%en{Memory area size(unsigned integer)} */
#if _KERNEL_TBIT_SIZE == _KERNEL_TBIT_PROC_UINT

typedef _KERNEL_T_PROC_UINT		SIZE;					/**< %jp{メモリ領域のサイズ(符号無し整数)}%en{Memory area size(unsigned integer)} */
#define _KERNEL_TMIN_SIZE		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_SIZE		_KERNEL_TMAX_PROC_UINT

#elif _KERNEL_TBIT_SIZE == 8		/* 8-bit */

typedef _KERNEL_T_UB			SIZE;					/**< %jp{メモリ領域のサイズ(符号無し整数)}%en{Memory area size(unsigned integer)} */		
#define _KERNEL_TMIN_SIZE		_KERNEL_TMIN_UB
#define _KERNEL_TMAX_SIZE		_KERNEL_TMAX_UB

#elif _KERNEL_TBIT_SIZE == 16		/* 16-bit */

typedef _KERNEL_T_UH			SIZE;					/**< %jp{メモリ領域のサイズ(符号無し整数)}%en{Memory area size(unsigned integer)} */
#define _KERNEL_TMIN_SIZE		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_SIZE		_KERNEL_TMAX_UH

#elif _KERNEL_TBIT_SIZE == 32		/* 32-bit */

typedef _KERNEL_T_UW			SIZE;					/**< %jp{メモリ領域のサイズ(符号無し整数)}%en{Memory area size(unsigned integer)} */
#define _KERNEL_TMIN_SIZE		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_SIZE		_KERNEL_TMAX_UW

#elif _KERNEL_TBIT_SIZE == 64		/* 8-bit */

typedef _KERNEL_T_UD			SIZE;					/**< %jp{メモリ領域のサイズ(符号無し整数)}%en{Memory area size(unsigned integer)} */
#define _KERNEL_TMIN_SIZE		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_SIZE		_KERNEL_TMAX_UD

#else								/* error */

#error Illegal value : _KERNEL_TBIT_SIZE

#endif



/* %jp{タイムアウト}%en{Timeout} */
#if _KERNEL_TBIT_TMO == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		TMO;					/**< %jp{タイムアウト}%en{Timeout} */
#define _KERNEL_TMIN_TMO		_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_TMO		_KERNEL_TMAX_PROC_INT

#elif _KERNEL_TBIT_TMO == 8			/* 8-bit */

typedef _KERNEL_T_B				TMO;					/**< %jp{タイムアウト}%en{Timeout} */
#define _KERNEL_TMIN_TMO		_KERNEL_TMIN_B
#define _KERNEL_TMAX_TMO		_KERNEL_TMAX_B

#elif _KERNEL_TBIT_TMO == 16		/* 16-bit */

typedef _KERNEL_T_H				TMO;					/**< %jp{タイムアウト}%en{Timeout} */
#define _KERNEL_TMIN_TMO		_KERNEL_TMIN_H
#define _KERNEL_TMAX_TMO		_KERNEL_TMAX_H

#elif _KERNEL_TBIT_TMO == 32			/* 32-bit */

typedef _KERNEL_T_W				TMO;					/**< %jp{タイムアウト}%en{Timeout} */
#define _KERNEL_TMIN_TMO		_KERNEL_TMIN_W
#define _KERNEL_TMAX_TMO		_KERNEL_TMAX_W

#elif _KERNEL_TBIT_TMO == 64			/* 8-bit */

typedef _KERNEL_T_D				TMO;					/**< %jp{タイムアウト}%en{Timeout} */
#define _KERNEL_TMIN_TMO		_KERNEL_TMIN_D
#define _KERNEL_TMAX_TMO		_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_TMO

#endif



/* %jp{相対時間(符号無し整数, 時間単位は実装定義)}%en{Relative time(unsigned integer, unit of time is implementation-defined)} */
#if _KERNEL_TBIT_RELTIM == _KERNEL_TBIT_PROC_UINT

typedef _KERNEL_T_PROC_UINT		RELTIM;					/**< %jp{相対時間(符号無し整数, 時間単位は実装定義)}%en{Relative time(unsigned integer, unit of time is implementation-defined)} */
#define _KERNEL_TMIN_RELTIM		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_RELTIM		_KERNEL_TMAX_PROC_UINT

#elif _KERNEL_TBIT_RELTIM == 8		/* 8-bit */

typedef _KERNEL_T_UB			RELTIM;					/**< %jp{相対時間(符号無し整数, 時間単位は実装定義)}%en{Relative time(unsigned integer, unit of time is implementation-defined)} */		
#define _KERNEL_TMIN_RELTIM		_KERNEL_TMIN_UB
#define _KERNEL_TMAX_RELTIM		_KERNEL_TMAX_UB

#elif _KERNEL_TBIT_RELTIM == 16		/* 16-bit */

typedef _KERNEL_T_UH			RELTIM;					/**< %jp{相対時間(符号無し整数, 時間単位は実装定義)}%en{Relative time(unsigned integer, unit of time is implementation-defined)} */
#define _KERNEL_TMIN_RELTIM		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_RELTIM		_KERNEL_TMAX_UH

#elif _KERNEL_TBIT_RELTIM == 32		/* 32-bit */

typedef _KERNEL_T_UW			RELTIM;					/**< %jp{相対時間(符号無し整数, 時間単位は実装定義)}%en{Relative time(unsigned integer, unit of time is implementation-defined)} */
#define _KERNEL_TMIN_RELTIM		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_RELTIM		_KERNEL_TMAX_UW

#elif _KERNEL_TBIT_RELTIM == 64		/* 8-bit */

typedef _KERNEL_T_UD			RELTIM;					/**< %jp{相対時間(符号無し整数, 時間単位は実装定義)}%en{Relative time(unsigned integer, unit of time is implementation-defined)} */
#define _KERNEL_TMIN_RELTIM		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_RELTIM		_KERNEL_TMAX_UD

#else								/* error */

#error Illegal value : _KERNEL_TBIT_RELTIM

#endif



/* %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */
#if _KERNEL_SYSTIM_STRUCT

#if _KERNEL_TBIT_SYSTIM == 16		/* 16-bit */

/** %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */
typedef struct t_systim
{
	UH ltime;				/**< %jp{下位 16bit}%en{lower 16bit} */
} SYSTIM;

#define _KERNEL_SYSTIM_ADD(t, n)	do { (t)->ltime += n; } while(0)

#elif _KERNEL_TBIT_SYSTIM == 32		/* 32-bit */

/** %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */
typedef struct t_systim
{
	UW ltime;				/**< %jp{下位 32bit}%en{lower 32bit} */
} SYSTIM;

#define _KERNEL_SYSTIM_ADD(t, n)	do { (t)->ltime += n; } while(0)

#elif _KERNEL_CFG_TBIT_SYSTIM == 48	/* 48-bit */

/** %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */
typedef struct t_systim		
{
	UW ltime;				/**< %jp{下位 32bit}%en{lower 32bit} */
	UH utime;				/**< %jp{上位 16bit}%en{upper 16bit} */
} SYSTIM;


#define _KERNEL_SYSTIM_ADD(t, n)	do { if ( (t)->ltime + (n) < (t)->ltime ) { (t)->utime++; } (t)->ltime += (n); } while(0)

#elif _KERNEL_TBIT_SYSTIM == 64		/* 64-bit */

/** %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */
typedef struct t_systim
{
	UW ltime;				/**< %en{lower}%jp{下位 32bit} */
	UW utime;				/**< %en{upper}%jp{上位 32bit} */
} SYSTIM;

#define _KERNEL_SYSTIM_ADD(t, n)	do { if ( (t)->ltime + (n) < (t)->ltime ) { (t)->utime++; } (t)->ltime += (n); } while(0)

#elif _KERNEL_TBIT_SYSTIM == 96		/* 96-bit */

/** %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */
typedef struct t_systim
{
	UD ltime;				/**< %en{lower}%jp{下位 64bit} */
	UW utime;				/**< %en{upper}%jp{上位 32bit} */
} SYSTIM;

#define _KERNEL_SYSTIM_ADD(t, n)	do { if ( (t)->ltime + (n) < (t)->ltime ) { (t)->utime++; } (t)->ltime += (n); } while(0)

#elif _KERNEL_TBIT_SYSTIM == 128	/* 128-bit */

/** %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */
typedef struct t_systim
{
	UD ltime;				/**< %en{lower}%jp{下位 64bit} */
	UD utime;				/**< %en{upper}%jp{上位 32bit} */
} SYSTIM;

#define _KERNEL_SYSTIM_ADD(t, n)	do { if ( (t)->ltime + (n) < (t)->ltime ) { (t)->utime++; } (t)->ltime += (n); } while(0)

#else

#error Illegal value : _KERNEL_TBIT_SYSTIM

#endif

#else

#if _KERNEL_CFG_TBIT_SYSTIM == _KERNEL_TBIT_PROC_UINT		/* default */

typedef _KERNEL_T_PROC_UINT		SYSTIM;					/**< %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */

#elif _KERNEL_TBIT_SYSTIM == 16	/* 16-bit */

typedef _KERNEL_T_UH			SYSTIM;					/**< %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */

#elif _KERNEL_TBIT_SYSTIM == 32	/* 32-bit */

typedef _KERNEL_T_UW			SYSTIM;					/**< %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */

#elif _KERNEL_TBIT_SYSTIM == 64	/* 64-bit */

typedef _KERNEL_T_UD			SYSTIM;					/**< %jp{システム時刻(符号無し整数, 時間単位は実装定義)}%en{System time(unsigned integer, unit of time is implementation-defined)} */

#else							/* error */

#error Illegal value : _KERNEL_TBIT_SYSTIM

#endif

#define _KERNEL_SYSTIM_ADD(t, n)	do { *(t) += n; } while(0)

#endif



/* %jp{エラーコードまたは真偽値}%en{Error code or a boolean value} */
#if _KERNEL_TBIT_ER_BOOL == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		ER_BOOL;				/**< %jp{エラーコードまたは真偽値}%en{Error code or a boolean value} */
#define _KERNEL_TMIN_ER_BOOL	_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_ER_BOOL	_KERNEL_TMAX_PROC_INT

#elif _KERNEL_TBIT_ER_BOOL == 8		/* 8-bit */

typedef _KERNEL_T_B				ER_BOOL;				/**< %jp{エラーコードまたは真偽値}%en{Error code or a boolean value} */
#define _KERNEL_TMIN_ER_BOOL	_KERNEL_TMIN_B
#define _KERNEL_TMAX_ER_BOOL	_KERNEL_TMAX_B

#elif _KERNEL_TBIT_ER_BOOL == 16	/* 16-bit */

typedef _KERNEL_T_H				ER_BOOL;				/**< %jp{エラーコードまたは真偽値}%en{Error code or a boolean value} */
#define _KERNEL_TMIN_ER_BOOL	_KERNEL_TMIN_H
#define _KERNEL_TMAX_ER_BOOL	_KERNEL_TMAX_H

#elif _KERNEL_TBIT_ER_BOOL == 32	/* 32-bit */

typedef _KERNEL_T_W				ER_BOOL;				/**< %jp{エラーコードまたは真偽値}%en{Error code or a boolean value} */
#define _KERNEL_TMIN_ER_BOOL	_KERNEL_TMIN_W
#define _KERNEL_TMAX_ER_BOOL	_KERNEL_TMAX_W

#elif _KERNEL_TBIT_ER_BOOL == 64	/* 8-bit */

typedef _KERNEL_T_D				ER_BOOL;				/**< %jp{エラーコードまたは真偽値}%en{Error code or a boolean value} */
#define _KERNEL_TMIN_ER_BOOL	_KERNEL_TMIN_D
#define _KERNEL_TMAX_ER_BOOL	_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_ER_BOOL

#endif



/* %jp{エラーコードまたはID番号}%en{Error code or an object ID number} */
#if _KERNEL_TBIT_ER_ID == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		ER_ID;					/**< %jp{エラーコードまたはID番号}%en{Error code or an object ID number} */
#define _KERNEL_TMIN_ER_ID		_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_ER_ID		_KERNEL_TMAX_PROC_INT

#elif _KERNEL_TBIT_ER_ID == 8		/* 8-bit */

typedef _KERNEL_T_B				ER_ID;					/**< %jp{エラーコードまたはID番号}%en{Error code or an object ID number} */
#define _KERNEL_TMIN_ER_ID		_KERNEL_TMIN_B
#define _KERNEL_TMAX_ER_ID		_KERNEL_TMAX_B

#elif _KERNEL_TBIT_ER_ID == 16		/* 16-bit */

typedef _KERNEL_T_H				ER_ID;					/**< %jp{エラーコードまたはID番号}%en{Error code or an object ID number} */
#define _KERNEL_TMIN_ER_ID		_KERNEL_TMIN_H
#define _KERNEL_TMAX_ER_ID		_KERNEL_TMAX_H

#elif _KERNEL_TBIT_ER_ID == 32		/* 32-bit */

typedef _KERNEL_T_W				ER_ID;					/**< %jp{エラーコードまたはID番号}%en{Error code or an object ID number} */
#define _KERNEL_TMIN_ER_ID		_KERNEL_TMIN_W
#define _KERNEL_TMAX_ER_ID		_KERNEL_TMAX_W

#elif _KERNEL_TBIT_ER_ID == 64		/* 8-bit */

typedef _KERNEL_T_D				ER_ID;					/**< %jp{エラーコードまたはID番号}%en{Error code or an object ID number} */
#define _KERNEL_TMIN_ER_ID		_KERNEL_TMIN_D
#define _KERNEL_TMAX_ER_ID		_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_ER_ID

#endif



/* %jp{エラーコードまたは符号無し整数(符号無し整数の有効ビット数はUINTより1ビット短い)}%en{Error code or an unsigned integer} */
#if _KERNEL_TBIT_ER_UINT == _KERNEL_TBIT_PROC_INT

typedef _KERNEL_T_PROC_INT		ER_UINT;				/**< %jp{エラーコードまたは符号無し整数(符号無し整数の有効ビット数はUINTより1ビット短い)}%en{Error code or an unsigned integer} */
#define _KERNEL_TMIN_ER_UINT	_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_ER_UINT	_KERNEL_TMAX_PROC_INT

#elif _KERNEL_TBIT_ER_UINT == 8		/* 8-bit */

typedef _KERNEL_T_B				ER_UINT;				/**< %jp{エラーコードまたは符号無し整数(符号無し整数の有効ビット数はUINTより1ビット短い)}%en{Error code or an unsigned integer} */
#define _KERNEL_TMIN_ER_UINT	_KERNEL_TMIN_B
#define _KERNEL_TMAX_ER_UINT	_KERNEL_TMAX_B

#elif _KERNEL_TBIT_ER_UINT == 16	/* 16-bit */

typedef _KERNEL_T_H				ER_UINT;				/**< %jp{エラーコードまたは符号無し整数(符号無し整数の有効ビット数はUINTより1ビット短い)}%en{Error code or an unsigned integer} */
#define _KERNEL_TMIN_ER_UINT	_KERNEL_TMIN_H
#define _KERNEL_TMAX_ER_UINT	_KERNEL_TMAX_H

#elif _KERNEL_TBIT_ER_UINT == 32	/* 32-bit */

typedef _KERNEL_T_W				ER_UINT;				/**< %jp{エラーコードまたは符号無し整数(符号無し整数の有効ビット数はUINTより1ビット短い)}%en{Error code or an unsigned integer} */
#define _KERNEL_TMIN_ER_UINT	_KERNEL_TMIN_W
#define _KERNEL_TMAX_ER_UINT	_KERNEL_TMAX_W

#elif _KERNEL_TBIT_ER_UINT == 64	/* 8-bit */

typedef _KERNEL_T_D				ER_UINT;				/**< %jp{エラーコードまたは符号無し整数(符号無し整数の有効ビット数はUINTより1ビット短い)}%en{Error code or an unsigned integer} */
#define _KERNEL_TMIN_ER_UINT	_KERNEL_TMIN_D
#define _KERNEL_TMAX_ER_UINT	_KERNEL_TMAX_D

#else								/* error */

#error Illegal value : _KERNEL_TBIT_ER_UINT

#endif



/* 以下まだ力尽きて未対応 */

typedef UH						TEXPTN;		/**< %jp{タスク例外要因のパターン(符号無し整数)}%en{Bit pattern for the task exception code(unsigned integer)} */
typedef UH						FLGPTN;		/**< %jp{フラグパターン(符号無し整数)}%en{Bit pattern of eventflag(unsigned integer)} */

/** %jp{フラグパターン(符号無し整数)}%en{Message header for a mailbox} */
typedef struct t_msg
{
	struct t_msg	*pk_next;
} T_MSG;

typedef struct t_msg_pri
{
	T_MSG			msgque;
	PRI 			msgpri;
} T_MSG_PRI;


typedef UINT					RDVPTN;
typedef INT						RDVNO;
typedef INT						OVRTIM;

typedef INT						INHNO;		/**< %jp{割込みハンドラ番号}%en{} */
typedef INT						INTNO;		/**< %jp{割込み番号}%en{} */

typedef INT						EXCNO;		/**< %jp{CPU例外ハンドラ番号}%en{} */



/* ------------------------------------ */
/*         macro definition             */
/* ------------------------------------ */

/* %jp{エラーコード生成・分解マクロ} */
#define	ERCD(mercd, sercd)		(((mercd) & 0xff) | ((sercd) << 8))		/**< %jp{エラーコードからメインエラーコードを取り出す} */
#define	MERCD(ercd)				((ER)((B)(ercd)))						/**< %jp{エラーコードからメインエラーコードを取り出す} */
#define	SERCD(ercd)				((ercd) >> 8)							/**< %jp{エラーコードからサブエラーコードを取り出す} */



#endif /* _KERNEL__itron_h__ */


/* end of file */

