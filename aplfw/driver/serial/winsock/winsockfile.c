/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scifile.c
 * @brief %jp{SCI用デバイスドライバ用ファイルI/Fクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include "winsockfile.h"


static void      WinSockFile_Delete(HANDLE hFile);				/**< デストラクタ */
static FILE_ERR  WinSockFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
static FILE_POS  WinSockFile_Seek(HANDLE hFile, FILE_POS Offset, int iOrign);
static FILE_SIZE WinSockFile_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
static FILE_SIZE WinSockFile_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);


const T_HANDLEOBJ_METHODS WinSockFile_HandleObjMethods =
{
	WinSockFile_Delete,			/* デストラクタ */
};

const T_FILEOBJ_METHODS WinSockFile_FileObjMethods =
{
	{ WinSockFile_Delete },		/* デストラクタ */
	WinSockFile_IoControl,		/* IoControl */
	NULL,						/* Seek */
	WinSockFile_Read,			/* Read */
	WinSockFile_Write,			/* Write */
};


/** コンストラクタ */
FILE_ERR WinSockFile_Create(HANDLE hFile, void *pParam, int iMode)
{
	C_WINSOCKFILE *self;

	self = (C_WINSOCKFILE *)hFile;
	
	/* 親クラスコンストラクタ呼び出し */
	FileObj_Create(&self->FileObj, &WinSockFile_FileObjMethods);
	
	/* デバイスドライバ本体と関連付け */
	self->pWinSockDrv = (C_WINSOCKDRV *)pParam;
	
	/* デバイスを開く */
	WinSockDrv_Open(self->pWinSockDrv);

	return FILE_ERR_OK;
}


/** デストラクタ */
void WinSockFile_Delete(HANDLE hFile)
{
	C_WINSOCKFILE *self;

	self = (C_WINSOCKFILE *)hFile;

	/* デバイスを閉じる */
	WinSockDrv_Close(self->pWinSockDrv);

	/* 親クラスデストラクタ呼び出し */
	FileObj_Delete(&self->FileObj);
}


FILE_ERR  WinSockFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize)
{
	return FILE_ERR_NG;
}


FILE_SIZE WinSockFile_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_WINSOCKFILE *self;

	self = (C_WINSOCKFILE *)hFile;

	return WinSockDrv_Read(self->pWinSockDrv, pBuf, Size);
}

FILE_SIZE WinSockFile_Write(HANDLE hFile, const void *pData, FILE_SIZE Size)
{
	C_WINSOCKFILE *self;

	self = (C_WINSOCKFILE *)hFile;

	return WinSockDrv_Write(self->pWinSockDrv, pData, Size);
}


/* end of file */
