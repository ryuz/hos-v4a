/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    Sample program for ADuC7000 series                                    */
/*                                                                          */
/*                                  Copyright (C) 1998-2007 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


                .extern     __kernel_int_isp
                .extern     ___data
                .extern     ___data_end
                .extern     ___bss
                .extern     ___bss_end
                .extern     ___ctors
                .extern     ___ctors_end
                .extern     ___dtors
                .extern     ___dtors_end

                .extern     hw_setup
                .extern     main

                .global     _reset_handler
                .global     __main


                .text

#define Mode_USR        0x10
#define Mode_IRQ        0x12
#define Mode_FIQ        0x11
#define Mode_SVC        0x13
#define Mode_UND        0x1b
#define Mode_SYS        0x1f
#define I_Bit           0x80
#define F_Bit           0x40
#define T_Bit           0x20


/************************************************
  リセットハンドラ
************************************************/
                .align      4
_reset_handler: 
                /* モード設定 */
                msr     cpsr_c, #(Mode_SYS | F_Bit | I_Bit)
                
                /* SCTLR.V クリア(例外ベクタを0番地に戻す) */
                mrc     p15, 0, r0, c1, c0, 0
                mvn     r1, #0x2000
                and     r0, r0, r1
                mcr     p15, 0, r0, c1, c0, 0
                
                /* スタック仮設定 */
                ldr     r0, =_kernel_int_isp
                ldr     sp, [r0]

                /* Disable DBWR for errata 780125 */
                mrc     p15, 0, r0, c1, c0, 1       /* Read ACTLR */
                orr     r0, r0, #0x1 << 14          /* Disable DBWR for errata 780125 */
                mcr     p15, 0, r0, c1, c0, 1       /* Write ACTLR */
                
                /* enable VFP */
                mrc     p15, 0, r0, c1, c0, 2
                orr     r0, r0, #(0xf << 20)
                mcr     p15, 0, r0, c1, c0, 2
                isb

                /* enable FPU access  */
                vmrs    r3, FPEXC
                orr     r1, r3, #(0x1 << 30)
                vmsr    FPEXC, r1

                /* Disable MPU and caches */
                mrc     p15, 0, r0, c1, c0, 0   /* Read CP15 Control Register*/
                bic     r0, r0, #0x05           /* Disable MPU (M bit) and data cache (C bit) */
                bic     r0, r0, #0x1000         /* Disable instruction cache (I bit) */
                dsb                             /* Ensure all previous loads/stores have completed */
                mcr     p15, 0, r0, c1, c0, 0   /* Write CP15 Control Register */
                isb     

                /* Disable Branch prediction, TCM ECC checks */
                mrc     p15, 0, r0, c1, c0, 1       /* Read ACTLR */
                orr     r0, r0, #(0x1 << 17)        /* Enable RSDIS bit 17 to disable the return stack */
                orr     r0, r0, #(0x1 << 16)        /* Clear BP bit 15 and set BP bit 16:*/
                bic     r0, r0, #(0x1 << 15)        /* Branch always not taken and history table updates disabled*/
                orr     r0, r0, #(0x1 << 27)        /* Enable B1TCM ECC check */
                orr     r0, r0, #(0x1 << 26)        /* Enable B0TCM ECC check */
                orr     r0, r0, #(0x1 << 25)        /* Enable ATCM ECC check */
                bic     r0, r0, #(0x1 << 5)         /* Generate abort on parity errors, with [5:3]=b 000*/
                bic     r0, r0, #(0x1 << 4)
                bic     r0, r0, #(0x1 << 3)
                mcr     p15, 0, r0, c1, c0, 1       /* Write ACTLR*/
                dsb                                 /* Complete all outstanding explicit memory operations*/

                /* Invalidate caches */
                mov     r0, #0                      /* r0 = 0  */
                dsb
                mcr     p15, 0, r0, c7, c5, 0       /* invalidate icache */
                mcr     p15, 0, r0, c15, c5, 0      /* Invalidate entire data cache*/
                isb

                /* H/W 初期化 */
                bl      hw_setup

                /* DATA領域のコピー */
                ldr     r0, =___data_rom
                ldr     r1, =___data
                ldr     r2, =___data_end
data_loop:      
                cmp     r1, r2
                ldrcc   r3, [r0], #4
                strcc   r3, [r1], #4
                bcc     data_loop
                
                
                /* BSS領域の初期化 */
                ldr     r0, =___bss
                ldr     r1, =___bss_end
                mov     r2, #0
bss_loop:       
                cmp     r0, r1
                strcc   r2, [r0], #4
                bcc     bss_loop
                

                /* コンストラクタ呼び出し */
                ldr     r4, =___ctors
                ldr     r5, =___ctors_end
ctors_loop:     
                cmp     r4, r5
                ldrcc   r0, [r4], #4
                blxcc   r0
                bcc     ctors_loop
                
                /* main関数の呼び出し */
                bl      main

                /* デストラクタ呼び出し */
                ldr     r4, =___dtors
                ldr     r5, =___dtors_end
dtors_loop:     
                cmp     r4, r5
                ldrcc   r0, [r4], #4
                blxcc   r0
                bcc     dtors_loop

                /* 無限ループ */
end_loop:
                b       end_loop


__main:
                bx      lr


                .end


/* end of file */
