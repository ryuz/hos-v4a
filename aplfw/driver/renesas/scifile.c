/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scifile.c
 * @brief %jp{SCI用デバイスドライバ用ファイルI/Fクラス}
 *
 * @version $Id: scifile.c,v 1.1 2006-11-05 16:11:07 ryuz Exp $
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include "scifile.h"

static void     SciFile_Delete(HANDLE hFile);				/**< デストラクタ */
static FILEERR  SciFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILESIZE InSize, void *pOutBuf, FILESIZE OutSize);
static FILEPOS  SciFile_Seek(HANDLE hFile, FILEPOS Offset, int iOrign);
static FILESIZE SciFile_Read(HANDLE hFile, void *pBuf, FILESIZE Size);
static FILESIZE SciFile_Write(HANDLE hFile, const void *pData, FILESIZE Size);


const T_HANDLEOBJ_METHODS SciFile_HandleObjMethods =
{
	SciFile_Delete,			/* デストラクタ */
};

const T_FILEOBJ_METHODS SciFile_FileObjMethods =
{
	SciFile_IoControl,		/* IoControl */
	NULL,					/* Seek */
	SciFile_Read,			/* Read */
	SciFile_Write,			/* Write */
};


/** コンストラクタ */
FILEERR SciFile_Create(HANDLE hFile, void *pParam)
{
	C_SCIFILE *self;

	self = (C_SCIFILE *)hFile;

	/* メソッドテーブル初期化 */
	self->FileObj.HandleObj.pMethods = &SciFile_HandleObjMethods;
	self->FileObj.pMethods           = &SciFile_FileObjMethods;

	/* 親クラスコンストラクタ呼び出し */
	FileObj_Create(&self->FileObj);
	
	/* デバイスドライバ本体と関連付け */
	self->pSciDrv = (C_SCIDRV *)pParam;
	
	/* デバイスを開く */
	SciDrv_Open(self->pSciDrv);

	return FILE_ERR_OK;
}


/** デストラクタ */
void SciFile_Delete(HANDLE hFile)
{
	C_SCIFILE *self;

	self = (C_SCIFILE *)hFile;

	/* デバイスを閉じる */
	SciDrv_Close(self->pSciDrv);

	/* 親クラスデストラクタ呼び出し */
	FileObj_Delete(&self->FileObj);
}


FILEERR  SciFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILESIZE InSize, void *pOutBuf, FILESIZE OutSize)
{
	return FILE_ERR_NG;
}


FILESIZE SciFile_Read(HANDLE hFile, void *pBuf, FILESIZE Size)
{
	C_SCIFILE *self;

	self = (C_SCIFILE *)hFile;

	return SciDrv_Read(self->pSciDrv, pBuf, Size);
}

FILESIZE SciFile_Write(HANDLE hFile, const void *pData, FILESIZE Size)
{
	C_SCIFILE *self;

	self = (C_SCIFILE *)hFile;

	return SciDrv_Write(self->pSciDrv, pData, Size);
}


/* end of file */
