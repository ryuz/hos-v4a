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
#include "arch/irc/arm/pl390/irc.h"


/** %jp{メイン関数} */
int main()
{
	int i;
	
	/* ICD(Distributor) setup */
	UB targetcpu = 0x01;
	vdis_icd();
	
	/* set TTC0-1 */
	vchg_icdiptr(74, targetcpu);   /* set ICDIPTR */

	/* PL */
	for ( i = 0; i < 8; ++i ) {
		vchg_icdiptr(121 + i, targetcpu);  						/* set ICDIPTR */
		vchg_icdicfr(121 + i, _KERNEL_ARM_PL390_ICDICFR_EDGE);  /* set ICDICFR */
	}
	for ( i = 0; i < 8; ++i ) {
		vchg_icdiptr(136 + i, targetcpu);  						/* set ICDIPTR */
		vchg_icdicfr(136 + i, _KERNEL_ARM_PL390_ICDICFR_EDGE);  /* set ICDICFR */
	}

	vena_icd();	/* enable IDC */

	/* %jp{カーネルの動作開始} */
	vsta_knl();
	
	return 0;
}


/* end of file */
