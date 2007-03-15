/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.h
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__file_h__
#define __HOS__file_h__


#include <stdarg.h>
#include "system/handle/handleobj.h"


#define FILE_MAX_PATH				128			/* パス名の最大値 */
#define FILE_MAX_NAME				12			/* 名前の最大値 */


/* エラーコード定義 */
#define FILE_ERR_OK					0
#define FILE_ERR_NG					(-1)

/* 定数定義 */
#define FILE_EOF					(-1)

/* Openモード定義 */
#define FILE_MODE_READ				0x01		/* 読込み許可 */
#define FILE_MODE_WRITE				0x02		/* 書込み許可 */
#define FILE_MODE_CREATE			0x04		/* 常に新規作成 */
#define FILE_MODE_EXIST				0x08		/* 存在しなければエラー */
#define FILE_MODE_SHARE_READ		0x10		/* 読込み共有許可 */
#define FILE_MODE_SHARE_WRITE		0x20		/* 書込み共有許可 */
#define FILE_MODE_TEXT				0x40		/* テキストモード */
#define FILE_MODE_DIR				0x80		/* ディレクトリをオープン */

/* シーク */
#define FILE_SEEK_SET				0
#define FILE_SEEK_CUR				1
#define FILE_SEEK_END				2

/* IoControl機能コード(共通) */
#define FILE_IOCTL_GETDEVTYPE		0x0000		/* デバイスタイプを得る */
#define FILE_IOCTL_SYNC				0x0001		/* 同期する */
#define FILE_IOCTL_GETSIZE			0x0010		/* ファイルサイズを取得 */
#define FILE_IOCTL_GETREADSIZE		0x0010		/* 読み込み可能サイズ(受信バッファ内のデータ量)を取得 */
#define FILE_IOCTL_GETWRITESIZE		0x0011		/* 書き込み可能サイズ(送信バッファ内の空きサイズ)を取得 */
#define FILE_IOCTL_GETREADBUF		0x0020		/* リードバッファ取得(省コピー版Read) */
#define FILE_IOCTL_RELREADBUF		0x0021		/* リードバッファ返却(省コピー版Read) */
#define FILE_IOCTL_GETWRITEBUF		0x0030		/* ライトバッファ取得(省コピー版Write) */
#define FILE_IOCTL_SENDWRITEBUF		0x0031		/* ライトバッファ送信(省コピー版Write) */
#define FILE_IOCTL_RELWRITEBUF		0x0032		/* ライトバッファ破棄(省コピー版Write) */

/* IoControl機能コード(シリアル通信) */
#define FILE_IOCTL_COM_GETSPEED		0x2101		/* BPS取得 */
#define FILE_IOCTL_COM_SETSPEED		0x2101		/* BPS設定 */

/* IoControl機能コード(Ether) */
#define FILE_IOCTL_ETHER_GETPHA		0x2201		/* 物理アドレス取得 */
#define FILE_IOCTL_ETHER_SETPHA		0x2202		/* 物理アドレス設定 */

/* IoControl機能コード(IP層) */
#define FILE_IOCTL_IP_GETIP			0x2301		/* IPアドレス取得 */
#define FILE_IOCTL_IP_SETIP			0x2302		/* IPアドレス設定 */
#define FILE_IOCTL_IP_GETMASK		0x2303		/* IPサブネットマスク取得 */
#define FILE_IOCTL_IP_SETMASK		0x2304		/* IPサブネットマスク設定 */

/* IoControl機能コード(ユーザー定義) */
#define FILE_IOCTL_USER				0x6000		/* 0x6000〜0x7fff あたりを使ってね */



/* 型定義 */
typedef char			FILE_ATTR;				/* ファイル属性 */
typedef int				FILE_ERR;				/* ファイルのエラー型 */
typedef long			FILE_POS;				/* ファイル位置の型定義 */
typedef int				FILE_SIZE;				/* 読み書き時のサイズ用の型定義 */
typedef unsigned long	FILE_TIME;				/* 読み書き時のサイズ用の時刻型定義 */


/* ボリューム情報 */
typedef struct t_file_volinf
{
	char		szName[FILE_MAX_NAME];
	HANDLE		hVolume;
} T_FILE_VOLINF;


/* デバイス情報 */
typedef struct t_file_devinf
{
	char		szName[FILE_MAX_NAME];									/* ファイル名 */
	FILE_ERR	(*pfncCreate)(HANDLE hFile, void *pParam, int iMode);	/* コンストラクタアドレス */
	int     	ObjSize;												/* オブジェクトのサイズ */
	void    	*pParam;												/* オブジェクトの生成パラメータ */
} T_FILE_DEVINF;


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
} T_FILE_FILEINF;



#ifdef __cplusplus
extern "C" {
#endif

/* システム */
void     File_Initialize(void);									/* ファイルシステムの初期化 */

FILE_ERR File_AddVolume(const T_FILE_VOLINF *pVolInf);			/* ボリュームのマウント */
FILE_ERR File_RemoveVolume(const T_FILE_VOLINF *pVolInf);		/* ボリュームのマウント */

FILE_ERR File_AddDevice(const T_FILE_DEVINF *pDevInf);			/* デバイスファイルの追加 */
FILE_ERR File_RemoveDevice(const char *pszName);				/* デバイスファイルの削除 */


/* 基本API */
HANDLE    File_Open(const char *pszPatah, int iMode);
#define   File_Close(hFile)		Handle_Close(hFile)
FILE_ERR  File_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  File_Seek(HANDLE hFile, FILE_POS Offset, int iOrign);
FILE_SIZE File_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
FILE_SIZE File_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);

/* 文字列用API */
int       File_GetChar(HANDLE hFile);
int       File_GetString(HANDLE hFile, char *pszString, int iSize);
int       File_PutChar(HANDLE hFile, int c);
int       File_PutString(HANDLE hFile, const char *pszString);

/* 書式付き文字列用API */
int       File_PrintFormatV(HANDLE hFile, const char *pszFormat, va_list argptr);
int       File_PrintFormat(HANDLE hFile, const char *pszFormat, ...);

int       File_PrintHexNibble(HANDLE hFile, unsigned char c);		/* 4bitの16進数を出力 */

int       File_PrintFormatDecimal(HANDLE hFile, long lNum, int iWidth, int iPadChar);		/* 書式付き10進数出力 */
int       File_PrintFormatVL(HANDLE hFile, const char *pszFormat, va_list argptr);		/* 書式付き出力軽量版 */


/* 拡張操作 */
FILE_ERR  File_Sync(HANDLE hFile);
FILE_POS  File_GetFileSize(HANDLE hFile);
FILE_SIZE File_GetReadSize(HANDLE hFile);
FILE_SIZE File_GetWriteSize(HANDLE hFile);
FILE_SIZE File_GetReadBuf(HANDLE hFile, void **ppBuf);
FILE_SIZE File_RelReadBuf(HANDLE hFile, void *pBuf, long lSize);
FILE_SIZE File_GetWriteBuf(HANDLE hFile, void **ppBuf);
FILE_SIZE File_SendWriteBuf(HANDLE hFile, void *pBuf, long lSize);
FILE_ERR  File_CanWriteBuf(HANDLE hFile, void *pBuf);

/* ディレクトリ操作 */
HANDLE    File_OpenDir(const char *pszName);						/* ディレクトリを開く */
FILE_ERR  File_FindNext(HANDLE hDir, T_FILE_FILEINF *pFileInf);		/* ディレクトリからファイルを検索 */
HANDLE    File_MakeDir(const char *pszName);						/* サブディレクトリを作成 */
HANDLE    File_Remove(const char *pszName);							/* ファイルを削除 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__file_h__ */


/* end of file */
