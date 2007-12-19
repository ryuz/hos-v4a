/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streampipe.c
 * @brief %jp{ストリームパイプ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "streampipe_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS StreamPipe_Methods = 
	{
		{ StreamPipe_Delete },
		StreamPipe_Open,
		StreamPipe_Close,
		StreamPipe_IoControl,
		StreamPipe_Seek,
		StreamPipe_Read,
		StreamPipe_Write,
		StreamPipe_Flush,
	};


/** コンストラクタ */
HANDLE StreamPipe_Create(int iBufSize)
{
	C_STREAMPIPE *self;
	
	/* メモリ確保 */
	if ( (self = (C_STREAMPIPE *)SysMem_Alloc(sizeof(C_STREAMPIPE))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( StreamPipe_Constructor(self, &StreamPipe_Methods, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
