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
  キャッシュ有効化
  void 	vena_cache(void);
 ************************************************/
                .global vena_cache
vena_cache:
                mrc     p15, 0, r1, c1, c0, 0   /* Read System Control Register configuration data */
                orr     r1, r1, #0x1 << 12      /* instruction cache enable */
                orr     r1, r1, #0x1 << 2       /* data cache enable */
                dsb
                mcr     p15, 0, r0, c15, c5, 0  /* Invalidate entire data cache */
                mcr     p15, 0, r0, c7, c5, 0   /* Invalidate entire instruction cache */
                mcr     p15, 0, r1, c1, c0, 0   /* enabled cache RAMs */
                isb
                bx      lr

                .end


/* end of file */
