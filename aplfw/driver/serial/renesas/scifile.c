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
#include "scifile.h"

static void      SciFile_Delete(HANDLE hFile);				/**< デストラクタ */
static FILE_ERR  SciFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
static FILE_POS  SciFile_Seek(HANDLE hFile, FILE_POS Offset, int iOrign);
static FILE_SIZE SciFile_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
static FILE_SIZE SciFile_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);


const T_HANDLEOBJ_METHODS SciFile_HandleObjMethods =
{
	SciFile_Delete,			/* デストラクタ */
};

const T_FILEOBJ_METHODS SciFile_FileObjMethods =
{
	{ SciFile_Delete },		/* デストラクタ */
	SciFile_IoControl,		/* IoControl */
	NULL,					/* Seek */
	SciFile_Read,			/* Read */
	SciFile_Write,			/* Write */
};


/** コンストラクタ */
FILE_ERR SciFile_Create(HANDLE hFile, void *pParam)
{
	C_SCIFILE *self;

	self = (C_SCIFILE *)hFile;
	
	/* 親クラスコンストラクタ呼び出し */
	FileObj_Create(&self->FileObj, &SciFile_FileObjMethods);
	
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


FILE_ERR  SciFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize)
{
	return FILE_ERR_NG;
}


FILE_SIZE SciFile_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_SCIFILE *self;

	self = (C_SCIFILE *)hFile;

	return SciDrv_Read(self->pSciDrv, pBuf, Size);
}

FILE_SIZE SciFile_Write(HANDLE hFile, const void *pData, FILE_SIZE Size)
{
	C_SCIFILE *self;

	self = (C_SCIFILE *)hFile;

	return SciDrv_Write(self->pSciDrv, pData, Size);
}


/* end of file */
