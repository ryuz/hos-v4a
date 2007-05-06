/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scihdl_local.h
 * @brief %jp{SCI用ハードウェアアクセス層 ローカルヘッダ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__renesas__scihal_local_h__
#define __HOS__renesas__scihal_local_h__


#include "scihal.h"


#define SCIHAL_REG_SMR(self)	((volatile unsigned char*)(self)->pRegBase + 0)
#define SCIHAL_REG_BRR(self)	((volatile unsigned char*)(self)->pRegBase + 1)
#define SCIHAL_REG_SCR(self)	((volatile unsigned char*)(self)->pRegBase + 2)
#define SCIHAL_REG_TDR(self)	((volatile unsigned char*)(self)->pRegBase + 3)
#define SCIHAL_REG_SSR(self)	((volatile unsigned char*)(self)->pRegBase + 4)
#define SCIHAL_REG_RDR(self)	((volatile unsigned char*)(self)->pRegBase + 5)


#endif	/* __HOS__renesas__scihal_local_h__ */


/* end of file */
