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
  Dキャッシュ有効化
  void 	vena_dcache(void);
 ************************************************/
                .global vena_dcache
vena_dcache:
                mrc     p15, 0, r1, c1, c0, 0   /* Read System Control Register configuration data */
                orr     r1, r1, #0x1 << 2
                dsb
                mcr     p15, 0, r0, c15, c5, 0  /* Invalidate entire data cache */
                mcr     p15, 0, r1, c1, c0, 0   /* enabled data cache */
                bx      lr

                .end


/* end of file */
