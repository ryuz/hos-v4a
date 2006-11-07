/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  chkptr.h
 * @brief %jp{ポインタチェックヘッダファイル}%en{pointer check header file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__core__ptrchk_h__
#define _KERNEL__core__ptrchk_h__


/** %jp{関数ポインタの正当性チェック} */
#define _KERNEL_CHKPTR_FUNC(ptr)		((ptr) != NULL)

/** %jp{データポインタの正当性チェック} */
#define _KERNEL_CHKPTR_DATA(ptr)		((ptr) != NULL)

/** %jp{constデータポインタの正当性チェック} */
#define _KERNEL_CHKPTR_CONST(ptr)		((ptr) != NULL)


#endif	/* _KERNEL__core__ptrchk_h__ */


/* end of file */
