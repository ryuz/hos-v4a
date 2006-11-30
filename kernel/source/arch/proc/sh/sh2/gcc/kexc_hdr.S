/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.global	__kernel_exc_hdr



				.text


/************************************************
   高速割り込みベクタ利用時、bra で分岐可能な
 位置にベクタ入り口を設置。ただし未使用の
 ベクタまでリンクされてしまう。
 ************************************************/

#ifdef _KERNEL_FAST_EXCVEC

				.global	__kernel_vector_004
				.global	__kernel_vector_005
				.global	__kernel_vector_006
				.global	__kernel_vector_007
				.global	__kernel_vector_008
				.global	__kernel_vector_009
				.global	__kernel_vector_010
				.global	__kernel_vector_011
				.global	__kernel_vector_012
				.global	__kernel_vector_013
				.global	__kernel_vector_014
				.global	__kernel_vector_015
				.global	__kernel_vector_016
				.global	__kernel_vector_017
				.global	__kernel_vector_018
				.global	__kernel_vector_019
				.global	__kernel_vector_020
				.global	__kernel_vector_021
				.global	__kernel_vector_022
				.global	__kernel_vector_023
				.global	__kernel_vector_024
				.global	__kernel_vector_025
				.global	__kernel_vector_026
				.global	__kernel_vector_027
				.global	__kernel_vector_028
				.global	__kernel_vector_029
				.global	__kernel_vector_030
				.global	__kernel_vector_031
				.global	__kernel_vector_032
				.global	__kernel_vector_033
				.global	__kernel_vector_034
				.global	__kernel_vector_035
				.global	__kernel_vector_036
				.global	__kernel_vector_037
				.global	__kernel_vector_038
				.global	__kernel_vector_039
				.global	__kernel_vector_040
				.global	__kernel_vector_041
				.global	__kernel_vector_042
				.global	__kernel_vector_043
				.global	__kernel_vector_044
				.global	__kernel_vector_045
				.global	__kernel_vector_046
				.global	__kernel_vector_047
				.global	__kernel_vector_048
				.global	__kernel_vector_049
				.global	__kernel_vector_050
				.global	__kernel_vector_051
				.global	__kernel_vector_052
				.global	__kernel_vector_053
				.global	__kernel_vector_054
				.global	__kernel_vector_055
				.global	__kernel_vector_056
				.global	__kernel_vector_057
				.global	__kernel_vector_058
				.global	__kernel_vector_059
				.global	__kernel_vector_060
				.global	__kernel_vector_061
				.global	__kernel_vector_062
				.global	__kernel_vector_063

__kernel_vector_004:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#4, r4

__kernel_vector_005:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#5, r4

__kernel_vector_006:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#6, r4

__kernel_vector_007:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#7, r4

__kernel_vector_008:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#8, r4

__kernel_vector_009:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#9, r4

__kernel_vector_010:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#10, r4

__kernel_vector_011:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#11, r4

__kernel_vector_012:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#12, r4

__kernel_vector_013:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#13, r4

__kernel_vector_014:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#14, r4

__kernel_vector_015:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#15, r4

__kernel_vector_016:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#16, r4

__kernel_vector_017:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#17, r4

__kernel_vector_018:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#18, r4

__kernel_vector_019:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#19, r4

__kernel_vector_020:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#20, r4

__kernel_vector_021:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#21, r4

__kernel_vector_022:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#22, r4

__kernel_vector_023:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#23, r4

__kernel_vector_024:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#24, r4

__kernel_vector_025:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#25, r4

__kernel_vector_026:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#26, r4

__kernel_vector_027:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#27, r4

__kernel_vector_028:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#28, r4

__kernel_vector_029:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#29, r4

__kernel_vector_030:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#30, r4

__kernel_vector_031:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#31, r4

__kernel_vector_032:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#32, r4

__kernel_vector_033:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#33, r4

__kernel_vector_034:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#34, r4

__kernel_vector_035:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#35, r4

__kernel_vector_036:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#36, r4

__kernel_vector_037:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#37, r4

__kernel_vector_038:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#38, r4

__kernel_vector_039:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#39, r4

__kernel_vector_040:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#40, r4

__kernel_vector_041:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#41, r4

__kernel_vector_042:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#42, r4

__kernel_vector_043:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#43, r4

__kernel_vector_044:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#44, r4

__kernel_vector_045:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#45, r4

__kernel_vector_046:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#46, r4

__kernel_vector_047:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#47, r4

__kernel_vector_048:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#48, r4

__kernel_vector_049:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#49, r4

__kernel_vector_050:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#50, r4

__kernel_vector_051:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#51, r4

__kernel_vector_052:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#52, r4

__kernel_vector_053:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#53, r4

__kernel_vector_054:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#54, r4

__kernel_vector_055:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#55, r4

__kernel_vector_056:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#56, r4

__kernel_vector_057:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#57, r4

__kernel_vector_058:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#58, r4

__kernel_vector_059:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#59, r4

__kernel_vector_060:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#60, r4

__kernel_vector_061:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#61, r4

__kernel_vector_062:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#62, r4

__kernel_vector_063:
				mov.l	r4, @-r15
				bra		__kernel_exc_hdr
				mov		#63, r4

#endif


/************************************************
  CPU例外ハンドラ

  r4をスタックに積んだ後、r4に割り込み番号を
  格納してここに分岐するものとする
************************************************/
__kernel_exc_hdr:
			/* まだ未実装 */

				mov.l	@r15+, r4
				rte
				nop


				.end


/* end of file */
