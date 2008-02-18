/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxfile.h
 * @brief %jp{$OBJNAME_JP$ 公開ヘッダファイル}%en{$OBJNAME_EN$ public header file}
 *
 * $COPYRIGHT$
 */


#include "xxxxfile_local.h"


static const T_FILEOBJ_METHODS XxxxFile_FileObjMethods =
	{
		{File_Close},	/* デストラクタ */
	};


HANDLE XxxxFile_Create(C_XXXXDRV *pXxxxVol, int iMode)
{
	C_XXXXFILE *self;

	/* create file descriptor */
	if ( (self = (C_XXXXFILE *)SysMem_Alloc(sizeof(C_XXXXFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	XxxxFile_Constructor(self, &XxxxFile_FileObjMethods, pXxxxVol, iMode);
	
	return (HANDLE)self;
}


/* end of file */
