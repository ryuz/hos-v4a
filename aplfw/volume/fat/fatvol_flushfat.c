
#include <string.h>
#include "fatvol_local.h"


/** FATのフラッシュ */
void FatVol_FlushFat(C_FATVOL *self)
{
	unsigned long i;
	
	/* FAT先頭へ移動 */
	File_Seek(self->hBlockFile, self->uiFatStartSector * self->uiBytesPerSector, FILE_SEEK_SET);
	
	for ( i = 0; i < self->uiFatNum; i++ )
	{
		int j;
		
		for ( j = 0; j < self->uiSectorPerFat; j++ )
		{
			if ( self->pubFatDirty[j] )
			{
				File_Write(self->hBlockFile, &self->pubFatBuf[j * self->uiBytesPerSector], self->uiBytesPerSector);
			}
			else
			{
				File_Seek(self->hBlockFile, self->uiBytesPerSector, FILE_SEEK_CUR);
			}
		}
	}

	/* 更新フラグクリア */
	memset(self->pubFatDirty, 0, self->uiSectorPerFat);
}


/* end of file */
