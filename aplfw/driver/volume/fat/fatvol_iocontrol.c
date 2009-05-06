/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "fatvol_local.h"


FILE_ERR FatVol_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_FATVOL	*self;
	C_FATFILE	*pFile;
	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;
	pFile = (C_FATFILE *)pFileObj;

	switch ( iFunc )
	{
	case FILE_IOCTL_DIR_READ:
		{
			T_FILE_FILEINF	*pFileInf;
			unsigned char	ubBuf[32];
			char			*p;
			int				i;
			
			pFileInf = (T_FILE_FILEINF *)pInBuf;
			
			do
			{
				/* 1エントリ読み出し */
				if ( FatVol_Read(pDrvObj, pFileObj, ubBuf, 32) != 32 )
				{
					return FILE_ERR_NG;
				}
				
				/* 探索終了 */
				if  ( ubBuf[0] == 0x00 )
				{
					return FILE_ERR_NG;
				}				
			} while ( ubBuf[0] == 0xe5 || ubBuf[0] == 0x2e || ubBuf[11] == 0x0f );
						
			/* ファイル名 */
			p = pFileInf->szFileName;
			for ( i = 0; i < 8; i++ )
			{
				if ( ubBuf[i] == ' ' || ubBuf[i] == '\0' )
				{
					break;
				}
				*p++ = ubBuf[i];
			}
			
			/* 拡張子 */
			*p++ = '.';
			for ( i = 0; i < 3; i++ )
			{
				if ( ubBuf[8+i] == ' ' || ubBuf[i] == '\0' )
				{
					break;
				}
				*p++ = ubBuf[8+i];
			}
			if ( *(p-1) == '.' )
			{
				p--;
			}			
			*p++ = '\0';
			
			/* 小文字化 */
			p = pFileInf->szFileName;			
			for ( i = 0; p[i] != '\0'; i++ )
			{
				if ( p[i] >= 'A' && p[i] <= 'Z' )
				{
					p[i] += ('a' - 'A');
				}
			}
			
			/* ファイルサイズ */
			pFileInf->FileSize = ubBuf[28] + (ubBuf[29] << 8) + (ubBuf[30] << 16) + (ubBuf[31] << 24);
			
			/* ファイル属性 */
			pFileInf->Attribute = ubBuf[11];
			
			/* 情報 */
			pFileInf->szInformation[0] = '\0';
			
			return FILE_ERR_OK;
		}
		break;
	}

	return FILE_ERR_NG;
}


/* end of file */
