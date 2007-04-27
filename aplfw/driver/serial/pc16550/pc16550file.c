/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550file.c
 * @brief %jp{PC16550用デバイスドライバ用ファイルI/Fクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include "pc16550file.h"

static void      Pc16550File_Delete(HANDLE hFile);										/**< デストラクタ */
static FILE_ERR  Pc16550File_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
static FILE_SIZE Pc16550File_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
static FILE_SIZE Pc16550File_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);


const T_FILEOBJ_METHODS Pc16550File_FileObjMethods =
{
	{ Pc16550File_Delete },		/* デストラクタ */
	Pc16550File_IoControl,		/* IoControl */
	NULL,						/* Seek */
	Pc16550File_Read,			/* Read */
	Pc16550File_Write,			/* Write */
};


/** コンストラクタ */
FILE_ERR Pc16550File_Create(HANDLE hFile, void *pParam, int iMode)
{
	C_PC16550FILE *self;
	
	self = (C_PC16550FILE *)hFile;
	
	/* 親クラスコンストラクタ呼び出し */
	FileObj_Create(&self->FileObj, &Pc16550File_FileObjMethods);
	
	/* デバイスドライバ本体と関連付け */
	self->pPc16550Drv = (C_PC16550DRV *)pParam;
	
	/* デバイスを開く */
	Pc16550Drv_Open(self->pPc16550Drv);

	return FILE_ERR_OK;
}


/** デストラクタ */
void Pc16550File_Delete(HANDLE hFile)
{
	C_PC16550FILE *self;

	self = (C_PC16550FILE *)hFile;

	/* デバイスを閉じる */
	Pc16550Drv_Close(self->pPc16550Drv);

	/* 親クラスデストラクタ呼び出し */
	FileObj_Delete(&self->FileObj);
}


FILE_ERR  Pc16550File_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize)
{
	return FILE_ERR_NG;
}


FILE_SIZE Pc16550File_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_PC16550FILE *self;

	self = (C_PC16550FILE *)hFile;

	return Pc16550Drv_Read(self->pPc16550Drv, pBuf, Size);
}

FILE_SIZE Pc16550File_Write(HANDLE hFile, const void *pData, FILE_SIZE Size)
{
	C_PC16550FILE *self;

	self = (C_PC16550FILE *)hFile;

	return Pc16550Drv_Write(self->pPc16550Drv, pData, Size);
}


/* end of file */
