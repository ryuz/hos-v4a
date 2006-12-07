/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list_local.h
 * @brief %jp{リストクラス ローカルメンバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__list_local_h__
#define __HOS__list_local_h__


#include "list.h"


/* リストオブジェクト */
typedef struct t_list_obj
{
	struct t_list_obj *pPrev;
	struct t_list_obj *pNext;
} T_LIST_OBJ;




#endif	/* __HOS__list_local_h__ */
