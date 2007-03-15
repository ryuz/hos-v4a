

#include <string.h>
#include "fatfile_local.h"


/* 読み出し */
FILE_SIZE FatFile_Read(
			HANDLE    hFile,
			void      *pBuf,
			FILE_SIZE Size)
{
	C_FATFILE     *self;
	void          *pClusterBuf;
	FATVOL_UINT   ulBlock;
	FILE_SIZE     ReadSize;
	
	/* ハンドル取得 */
	self = (C_FATFILE *)hFile;
	
	/* サイズオーバーするなら */
	if ( self->FilePos + Size > self->FileSize )
	{
		/* サイズ更新されていないかディレクトリテーブルを参照 */
		if ( self->hDir != NULL )
		{
		}
	}
	
	/* サイズクリップ */
	if ( Size > self->FileSize - self->FilePos )
	{
		Size = self->FileSize - self->FilePos;
	}
	
	/* 要求読み出し量保存 */
	ReadSize = Size;
	
	/* 読み出し */
	while ( Size > 0 && self->FilePos < self->FileSize )
	{
		FILE_POS      ReadStart;
		FILE_SIZE     ReadSize;
		unsigned char *pubClusterBuf;
		
		/* 転送位置計算 */
		ReadStart = self->FilePos % self->uiClusterSize;
		ReadSize  = self->uiClusterSize - ReadStart;
		if ( ReadSize > Size )
		{
			ReadSize = Size;
		}
		
		/* バッファ取得 */
		if ( FatVol_GetClusterBuf(self->pFatVol, self->uiCurrentCluster, &pClusterBuf, 1) != FATVOL_ERR_OK )
		{
			break;
		}
		
		/* 転送 */
		memcpy(pBuf, (char *)pClusterBuf + ReadStart, ReadSize);

		/* バッファ開放 */
		FatVol_RelClusterBuf(self->pFatVol, pClusterBuf, 0);
		
		/* サイズ更新 */
		self->FilePos += ReadSize;
		pBuf =  (char *)pBuf + ReadSize;
		Size -= ReadSize;
		
		/* 次のクラスタに進む */
		self->uiCurrentCluster = FatVol_GetNextCluster(self->pFatVol, self->uiCurrentCluster);
	}
	
	return ReadSize - Size;
}


/* end of file */
