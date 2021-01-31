/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  main.c
 * @brief %jp{メイン関数}%en{main}
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "arch/proc/arm/arm_v7r/proc.h"
#include "arch/irc/arm/pl390/irc.h"


/** %jp{メイン関数} */
int main()
{
    /* %jp{カーネルの動作開始} */
    vsta_knl();
    
    return 0;
}


/* end of file */
