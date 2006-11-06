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
#include "system/handle.h"

#define FILE_MAX_PATH				128			/* パス名の最大値 */
#define FILE_MAX_NAME				12			/* 名前の最大値 */


/* エラーコード定義 */
#define FILE_ERR_OK					0
#define FILE_ERR_NG					(-1)

#define FILE_EOF					(-1)

#define FILE_MODE_READ				0x01
#define FILE_MODE_WRITE				0x02


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
typedef int		FILEERR;		/* ファイルのエラー型 */
typedef long	FILEPOS;		/* ファイル位置の型定義 */
typedef int		FILESIZE;		/* 読み書き時のサイズ用の型定義 */


/* ファイルオブジェクトクラス基本メソッドテーブル */
typedef struct t_fileobj_methods
{
	FILEERR  (*pfncIoControl)(HANDLE hFile, int iFunc, const void *pInBuf, FILESIZE InSize, void *pOutBuf, FILESIZE OutSize);
	FILEPOS  (*pfncSeek)(HANDLE hFile, FILEPOS Offset, int iOrign);
	FILESIZE (*pfncRead)(HANDLE hFile, void *pBuf, FILESIZE Size);
	FILESIZE (*pfncWrite)(HANDLE hFile, const void *pData, FILESIZE Size);
} T_FILEOBJ_METHODS;


/* ファイルブジェクト基本クラス定義 */
typedef struct c_fileobj
{
	C_HANDLEOBJ             HandleObj;			/* ハンドルオブジェクトを継承 */
	const T_FILEOBJ_METHODS *pMethods;			/* メッソドテーブルへのポインタ */
} C_FILEOBJ;



/* デバイス情報 */
typedef struct t_sysfile_devinf
{
	char	szName[FILE_MAX_NAME];						/* ファイル名 */
	FILEERR	(*pfncCreate)(HANDLE hFile, void *pParam);	/* コンストラクタアドレス */
	int     ObjSize;									/* オブジェクトのサイズ */
	void    *pParam;									/* オブジェクトの生成パラメータ */
} T_SYSFILE_DEVINF;


/* ハンドル変換 */
#define FILE_HANDLE2OBJ(hFile)		((C_FILEOBJ *)hFile)



#ifdef __cplusplus
extern "C" {
#endif

/* ユーザーAPI */
HANDLE   File_Open(const char *pszName, int iMode);
void     File_Close(HANDLE hFile);
FILEERR  File_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILESIZE InSize, void *pOutBuf, FILESIZE OutSize);
FILEPOS  File_Seek(HANDLE hFile, FILEPOS Offset, int iOrign);
FILESIZE File_Read(HANDLE hFile, void *pBuf, FILESIZE Size);
FILESIZE File_Write(HANDLE hFile, const void *pData, FILESIZE Size);

int      File_GetChar(HANDLE hFile);
int      File_GetString(HANDLE hFile, char *pszString, int iSize);
int      File_PutChar(HANDLE hFile, int c);
int      File_PutString(HANDLE hFile, const char *pszString);
int      File_PrintFormatV(HANDLE hFile, const char *pszFormat, va_list argptr);
int      File_PrintFormat(HANDLE hFile, const char *pszFormat, ...);

FILEERR  File_Sync(HANDLE hFile);
FILEPOS  File_GetFileSize(HANDLE hFile);
FILESIZE File_GetReadSize(HANDLE hFile);
FILESIZE File_GetWriteSize(HANDLE hFile);
FILESIZE File_GetReadBuf(HANDLE hFile, void **ppBuf);
FILESIZE File_RelReadBuf(HANDLE hFile, void *pBuf, long lSize);
FILESIZE File_GetWriteBuf(HANDLE hFile, void **ppBuf);
FILESIZE File_SendWriteBuf(HANDLE hFile, void *pBuf, long lSize);
FILEERR  File_CanWriteBuf(HANDLE hFile, void *pBuf);



/* システムAPI */
void     SysFile_Initialize(void);													/* ファイルシステムの初期化 */
FILEERR  SysFile_AddDevice(const char *pszPath, const T_SYSFILE_DEVINF *pDevInf);	/* デバイスファイルの追加 */

void     FileObj_Create(C_FILEOBJ *self);
void     FileObj_Delete(C_FILEOBJ *self);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__file_h__ */


/* end of file */
