/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatmount_main.c
 * @brief %jp{FATボリューム マウントコマンド}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "hosaplfw.h"
#include "fatmount.h"
#include "driver/volume/fat/fatvol.h"



/* FATボリューム マウントコマンド */
int FatMount_Main(int argc, char *argv[])
{
	HANDLE	hVolume;
	char	*pszMountName = NULL;
	char	*pszDevName   = NULL;
	int		iUnmount = 0;
	int		i;
		
	/* オプション解析 */
	for ( i = 1; i < argc; i++ )
	{
		if ( argv[i][0] == '-' )
		{
			if ( argv[i][1] == 'u' && argv[i][2] == '\0' )
			{
				iUnmount = 1;
			}
		}
		else
		{
			if ( pszMountName == NULL )
			{
				pszMountName = argv[i];
			}
			else if ( pszDevName == NULL )
			{
				pszDevName = argv[i];
			}
		}
	}
	
	/* システムモード移行 */
	if ( Process_EnterSystemMode() != PROCESS_ERR_OK )
	{
		return 1;	/* システム権限無し */
	}
	
	if ( !iUnmount )	/* FATボリュームマウント */
	{
		/* パラメータチェック */
		if ( pszMountName == NULL || pszDevName == NULL )
		{
			Process_LeaveSystemMode();
			return 1;
		}
		
		/* FATボリューム生成 */
		hVolume = FatVol_Create(pszDevName);
		if ( hVolume == HANDLE_NULL )
		{
			StdIo_PrintFormat("device open error\n");
			Process_LeaveSystemMode();
			return 1;
		}
		
		/* システムに登録 */
		File_AddVolume(pszMountName, hVolume);		
	}
	else	/* FATボリュームアンマウント */
	{
		if ( pszMountName == NULL )
		{
			Process_LeaveSystemMode();
			return 1;
		}
		
		/* デバイスを得る */
		hVolume = File_GetVolume(pszMountName);
		if ( hVolume ==  HANDLE_NULL )
		{
			Process_LeaveSystemMode();
			return 1;
		}
		
		/* シャットダウン */
		if ( Volume_Shutdown(hVolume) != FILE_ERR_OK )
		{
			StdIo_PrintFormat("shutdown failed\n");
			Process_LeaveSystemMode();
			return 1;
		}
		
		/* システムから取り外し */
		File_RemoveVolume(pszMountName);
		
		/* ボリューム削除 */
		FatVol_Delete(hVolume);
	}
	
	/* システムモードを抜ける */
	Process_LeaveSystemMode();
	
	return 0;
}


/* end of file */
