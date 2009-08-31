/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  hashtable_get.c
 * @brief %jp{ハッシュテーブルクラス}%en{hash table class}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "hosaplfw.h"
#include "hashtable_local.h"


/** %jp{生成}%en{Create} */
C_HASHTABLE *HashTable_Create(int iTableSize)
{
	return HashTable_CreateEx(iTableSize, Memory_GetMemHeap());
}


/* end of file */
