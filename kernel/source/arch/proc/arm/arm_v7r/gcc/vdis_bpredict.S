/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2021 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v7r.inc"

              .text
              .align    2

/************************************************
  分岐予測無効化
  void 	vena_bpredict(void);
 ************************************************/
                .global vdis_bpredict
vdis_bpredict:
                mrc     p15, 0, r0, c1, c0, 1       /* Read ACTLR */
                orr     r0, r0, #0x1 << 17          /* Enable RSDIS bit 17 to disable the return stack */
                orr     r0, r0, #0x1 << 16          /* Clear BP bit 15 and set BP bit 16:*/
                bic     r0, r0, #0x1 << 15          /* Branch always not taken and history table updates disabled*/
                mcr     p15, 0, r0, c1, c0, 1       /* Write ACTLR */
                dsb
                bx      lr

                .end


/* end of file */
