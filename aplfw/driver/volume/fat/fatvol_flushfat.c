
#include <string.h>
#include "fatvol_local.h"


/** FATのフラッシュ */
void FatVol_FlushFat(C_FATVOL *self)
{
	unsigned long i;
	
	/* FAT先頭へ移動 */
	File_Seek(self->hBlockFile, self->FatStartSector * self->BytesPerSector + self->Offset, FILE_SEEK_SET);
	
	for ( i = 0; i < self->FatNum; i++ )
	{
		int j;
		
		for ( j = 0; j < self->SectorPerFat; j++ )
		{
			if ( self->pubFatDirty[j] )
			{
				File_Write(self->hBlockFile, &self->pubFatBuf[j * self->BytesPerSector], self->BytesPerSector);
			}
			else
			{
				File_Seek(self->hBlockFile, self->BytesPerSector, FILE_SEEK_CUR);
			}
		}
	}

	/* 更新フラグクリア */
	memset(self->pubFatDirty, 0, self->SectorPerFat);
}


/* end of file */
