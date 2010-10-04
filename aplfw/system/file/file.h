/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.h
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__file_h__
#define __HOS__file_h__


#include <stdarg.h>
#include "system/handle/handleobj.h"


#define FILE_MAX_PATH						128			/* パス名の最大値 */
#define FILE_MAX_NAME						13			/* 名前の最大値 */


/* エラーコード定義 */
#define FILE_ERR_OK							0			/* 正常終了*/
#define FILE_ERR_NG							(-1)		/* エラー */
#define FILE_ERR_BUSY						(-2)		/* 他のプロセスが利用中(ブロッキングモード以外でポーリング失敗) */
#define FILE_ERR_BACKGROUND					(-3)		/* バックグラウンドで処理受付成功 */
#define FILE_ERR_TIMEOUT					(-4)		/* タイムアウト */

/* 定数定義 */
#define FILE_EOF							(-1)

/* Openモード定義 */
#define FILE_OPEN_READ						0x0001		/* 読込み許可 */
#define FILE_OPEN_WRITE						0x0002		/* 書込み許可 */
#define FILE_OPEN_CREATE					0x0004		/* 常に新規作成 */
#define FILE_OPEN_EXIST						0x0008		/* 存在しなければエラー */
#define FILE_OPEN_APPEND					0x0010		/* 存在しなければエラー */
#define FILE_OPEN_TEXT						0x0080		/* テキストモード */
#define FILE_OPEN_SHARE_READ				0x0100		/* 読込み共有許可 */
#define FILE_OPEN_SHARE_WRITE				0x0200		/* 書込み共有許可 */
#define FILE_OPEN_DIR						0x0800		/* ディレクトリをオープン */

/* シーク */
#define FILE_SEEK_SET						0
#define FILE_SEEK_CUR						1
#define FILE_SEEK_END						2


/* 同期モード */
#define FILE_SYNCMODE_BLOCKING				0x00		/* ブロッキングモード */
#define FILE_SYNCMODE_POLING				0x01		/* ポーリングモード */
#define FILE_SYNCMODE_BACKGROUND			0x02		/* バックグラウンド実行 */

/* 同期通知タイプ */
#define FILE_SYNCTYPE_NONE					0x00		/* 同期通知なし */
#define FILE_SYNCTYPE_EVENT					0x01		/* イベント通知 */
#define FILE_SYNCTYPE_CALLBACK				0x02		/* コールバック通知 */


/* IoControl機能コード(共通) */
#define FILE_IOCTL_GETDEVINF				0x0000		/* デバイス情報を得る */
#define FILE_IOCTL_SYNC						0x0001		/* 同期する */
#define FILE_IOCTL_GETSIZE					0x0010		/* ファイルサイズを取得 */
#define FILE_IOCTL_GETREADSIZE				0x0010		/* 読み込み可能サイズ(受信バッファ内のデータ量)を取得 */
#define FILE_IOCTL_GETWRITESIZE				0x0011		/* 書き込み可能サイズ(送信バッファ内の空きサイズ)を取得 */
#define FILE_IOCTL_GETREADBUF				0x0020		/* リードバッファ取得(省コピー版Read) */
#define FILE_IOCTL_RELREADBUF				0x0021		/* リードバッファ返却(省コピー版Read) */
#define FILE_IOCTL_GETWRITEBUF				0x0030		/* ライトバッファ取得(省コピー版Write) */
#define FILE_IOCTL_SENDWRITEBUF				0x0031		/* ライトバッファ送信(省コピー版Write) */
#define FILE_IOCTL_CANWRITEBUF				0x0032		/* ライトバッファ破棄(省コピー版Write) */


/* IoControl機能コード(同期制御) */
#define FILE_IOCTL_SET_WRITE_SYNCMODE		0x0081		/* 書込みの同期モードを設定 */
#define FILE_IOCTL_SET_READ_SYNCMODE		0x0082		/* 読込みの同期モードを設定 */
#define FILE_IOCTL_SET_IOCTL_SYNCMODE		0x0083		/* I/O制御の同期モードを設定 */

#define FILE_IOCTL_SET_WRITE_SYNCINF		0x0091		/* 書込みの同期情報を設定 */
#define FILE_IOCTL_SET_READ_SYNCINF			0x0092		/* 読込みの同期情報を設定 */
#define FILE_IOCTL_SET_IOCTL_SYNCINF		0x0093		/* I/O制御の同期情報を設定 */


/* IoControl機能コード(ディレクトリ) */
#define FILE_IOCTL_DIR_READ					0x0101		/* ディレクトリ情報を得る */


/* IoControl機能コード(コンソール) */
#define FILE_IOCTL_CON_GETCH				0x0201		/* 文字読込み */

/* IoControl機能コード(シリアル通信) */
#define FILE_IOCTL_COM_GETSPEED				0x2101		/* BPS取得 */
#define FILE_IOCTL_COM_SETSPEED				0x2101		/* BPS設定 */

/* IoControl機能コード(Ether) */
#define FILE_IOCTL_ETHER_GETPHA				0x2201		/* 物理アドレス取得 */
#define FILE_IOCTL_ETHER_SETPHA				0x2202		/* 物理アドレス設定 */

/* IoControl機能コード(IP層) */
#define FILE_IOCTL_IP_GETIP					0x2301		/* IPアドレス取得 */
#define FILE_IOCTL_IP_SETIP					0x2302		/* IPアドレス設定 */
#define FILE_IOCTL_IP_GETMASK				0x2303		/* IPサブネットマスク取得 */
#define FILE_IOCTL_IP_SETMASK				0x2304		/* IPサブネットマスク設定 */

#define FILE_IOCTL_IP_GETMASK				0x2303		/* IPサブネットマスク取得 */
#define FILE_IOCTL_IP_SETMASK				0x2304		/* IPサブネットマスク設定 */

/* IoControl機能コード(ユーザー定義) */
#define FILE_IOCTL_USER						0x6000		/* 0x6000〜0x7fff */


/* ファイル属性 */
#define FILE_ATTR_READONLY					0x01
#define FILE_ATTR_HIDDEN					0x02
#define FILE_ATTR_SYSTEM					0x04
#define FILE_ATTR_DIR						0x10
#define FILE_ATTR_ARCHIVE					0x20
#define FILE_ATTR_DEVICE					0x80


/* 型定義 */
typedef char			FILE_ATTR;						/* ファイル属性 */
typedef int				FILE_ERR;						/* ファイルのエラー型 */
typedef _HOS_SINT64		FILE_POS;						/* ファイル位置の型定義 */
typedef long			FILE_SIZE;						/* 読み書き時のサイズ用の型定義 */
typedef unsigned long	FILE_TIME;						/* 読み書き時のサイズ用の時刻型定義 */

struct c_drvobj;


/* ファイル情報 */
typedef struct t_file_fileinf
{
	char		szFileName[FILE_MAX_NAME];
	FILE_ATTR	Attribute;
	FILE_POS	FileSize;

/*
	FILE_TIME	timeCreate;
	FILE_TIME	timeAceess;
	FILE_TIME	timeWrite;
*/

	char		szInformation[64];
} T_FILE_FILEINF;


/* 同期情報 */
typedef struct t_file_syncinf
{
	int			Type;
	union
	{
		struct
		{
			void	(*pfncProc)(VPARAM Param, FILE_ERR ErrCode);
			VPARAM	Param;
		} Proc;
		HANDLE hEvent;
	} Sync;
} T_FILE_SYNCINF;


#include "fileobj.h"
#include "drvobj.h"


#ifdef __cplusplus
extern "C" {
#endif

/* システム */
void      File_Initialize(void);											/* ファイルシステムの初期化 */

FILE_ERR  File_AddDevice(const char *pszName, HANDLE hDriver);				/* デバイスドライバの登録 */
FILE_ERR  File_RemoveDevice(const char *pszName);							/* デバイスドライバの削除 */
HANDLE    File_GetDevice(const char *pszName);								/* デバイスドライバの取得 */

FILE_ERR  File_AddVolume(const char *pszName, HANDLE hVolume);				/* ボリュームのマウント */
FILE_ERR  File_RemoveVolume(const char *pszName);							/* ボリュームのアンマウント */
HANDLE    File_GetVolume(const char *pszName);								/* ボリュームの取得 */


/* 基本API */
HANDLE    File_Open(const char *pszPath, int iMode);
void      File_Close(HANDLE hFile);
FILE_ERR  File_IoControl(HANDLE hFile, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  File_Seek(HANDLE hFile, FILE_POS Offset, int iOrign);
FILE_SIZE File_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
FILE_SIZE File_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);
FILE_ERR  File_Flush(HANDLE hFile);

/* デバイスドライバ直接制御 */
HANDLE    File_DriverOpen(HANDLE hDriver, const char *pszPath, int iMode);				/* 名無しファイルのオープン */
FILE_ERR  File_GetDriverInformation(HANDLE hDriver, char *pszInformation, int iLen);	/* デバイスドライバ情報取得 */


/* 同期制御API */
FILE_ERR  File_SetWriteMode(HANDLE hFile, int iWriteMode);
FILE_ERR  File_GetWriteStatus(HANDLE hFile);
FILE_ERR  File_SetWriteEvent(HANDLE hFile, HANDLE hEvent);
FILE_ERR  File_SetReadMode(HANDLE hFile, int iReadMode);
FILE_ERR  File_GetReadStatus(HANDLE hFile);
FILE_ERR  File_SetReadEvent(HANDLE hFile, HANDLE hEvent);
FILE_ERR  File_SetIoMode(HANDLE hFile, int iReadMode);
FILE_ERR  File_GetIoStatus(HANDLE hFile);
FILE_ERR  File_SetIoEvent(HANDLE hFile, HANDLE hEvent);


/* 文字列用API */
int       File_GetChar(HANDLE hFile);
int       File_GetString(HANDLE hFile, char *pszString, int iSize);
int       File_PutChar(HANDLE hFile, int c);
int       File_PutString(HANDLE hFile, const char *pszString);

/* 書式付き文字列用API */
int       File_PrintFormatV(HANDLE hFile, const char *pszFormat, va_list argptr);
int       File_PrintFormat(HANDLE hFile, const char *pszFormat, ...);

int       File_PrintHexNibble(HANDLE hFile, unsigned char c);							/* 4bitの16進数を出力 */

int       File_PrintFormatDecimal(HANDLE hFile, long lNum, int iWidth, int iPadChar);	/* 書式付き10進数出力 */
int       File_PrintFormatVL(HANDLE hFile, const char *pszFormat, va_list argptr);		/* 書式付き出力軽量版 */


/* ディレクトリ読み出し */
FILE_ERR  File_ReadDir(HANDLE hFile, T_FILE_FILEINF *pFileInf);


/* 拡張操作 */
FILE_POS  File_GetFileSize(HANDLE hFile);
FILE_SIZE File_GetReadSize(HANDLE hFile);
FILE_SIZE File_GetWriteSize(HANDLE hFile);

FILE_SIZE File_GetReadBuf(HANDLE hFile, void **ppBuf);
FILE_SIZE File_RelReadBuf(HANDLE hFile, void *pBuf, FILE_SIZE Size);
FILE_SIZE File_GetWriteBuf(HANDLE hFile, void **ppBuf);
FILE_SIZE File_SendWriteBuf(HANDLE hFile, void *pBuf, FILE_SIZE Size);
FILE_ERR  File_CanWriteBuf(HANDLE hFile, void *pBuf);

/* ディレクトリ操作 */
HANDLE    File_OpenDir(const char *pszName);											/**< ディレクトリを開く */
FILE_ERR  File_ReadDir(HANDLE hDir, T_FILE_FILEINF *pFileInf);							/**< ディレクトリからファイルを検索 */
HANDLE    File_MakeDir(const char *pszName);											/**< サブディレクトリを作成 */
HANDLE    File_Remove(const char *pszName);												/**< ファイルを削除 */
FILE_ERR  File_RelPathToAbsPath(char *pszDstPath, const char *pszSrcPath, int iMaxLen);	/**< 相対パスを絶対パスに変換 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__file_h__ */


/* end of file */
