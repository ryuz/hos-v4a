/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.c
 * @brief %jp{サンプルプログラム}%en{Sample program}
 *
 * @version $Id: sample.h,v 1.1 2006-08-16 16:27:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __sample_h__
#define __sample_h__


#ifdef __cplusplus
extern "C" {
#endif

void Sample_Initialize(VP_INT exinf);
void Sample_Task(VP_INT exinf);
void Sample_Print(VP_INT exinf);

#ifdef __cplusplus
}
#endif


#endif	/* __sample_h__ */


/* end of file */
