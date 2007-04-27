/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  console.h
 * @brief %jp{コンソール}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "vt100con_local.h"


void      Vt100Con_Delete(HANDLE hFile);										/**< デストラクタ */
FILE_SIZE Vt100Con_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
FILE_SIZE Vt100Con_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);
int       Vt100Con_GetCh(HANDLE hCon);


const T_CONSOLEOBJ_METHODS Vt100Con_ConsoleObjMethods =
{
	{
		{ Vt100Con_Delete },		/* デストラクタ */
		NULL,						/* IoControl */
		NULL,						/* Seek */
		Vt100Con_Read,				/* Read */
		Vt100Con_Write,				/* Write */
		NULL,						/* Flush */
	},
	Vt100Con_GetCh,					/* GetCh */
};


/** コンストラクタ */
FILE_ERR Vt100Con_Create(HANDLE hFile, void *pParam, int iMode)
{
	C_VT100CON *self;
	
	self = (C_VT100CON *)hFile;
	
	/* 親クラスコンストラクタ呼び出し */
/*	ConsoleObj_Create(&self->ConObj, &Vt100Con_ConsoleObjMethods);	*/
	FileObj_Create(&self->ConObj, &Vt100Con_ConsoleObjMethods);
	
	/* デバイスドライバ本体と関連付け */
	self->pVt100Drv = (C_VT100DRV *)pParam;
	
	/* デバイスを開く */
/*	Vt100Drv_Open(self->pVt100Drv);	*/
	
	return FILE_ERR_OK;
}


/** デストラクタ */
void Vt100Con_Delete(HANDLE hFile)
{
	C_VT100CON *self;

	self = (C_VT100CON *)hFile;

	/* デバイスを閉じる */
/*	Vt100Drv_Close(self->pVt100Drv);	*/

	/* 親クラスデストラクタ呼び出し */
/*	FileObj_Delete(&self->ConObj); */
}



FILE_SIZE Vt100Con_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_VT100CON *self;

	self = (C_VT100CON *)hFile;

	return Vt100Drv_Read(self->pVt100Drv, pBuf, Size);
}

FILE_SIZE Vt100Con_Write(HANDLE hFile, const void *pData, FILE_SIZE Size)
{
	C_VT100CON *self;

	self = (C_VT100CON *)hFile;

	return Vt100Drv_Write(self->pVt100Drv, pData, Size);
}


int Vt100Con_GetCh(HANDLE hCon)
{
	C_VT100CON *self;

	self = (C_VT100CON *)hCon;

	return Vt100Drv_GetCh(self->pVt100Drv);
}

/* end of file */
