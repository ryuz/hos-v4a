/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  μITRON4.0仕様 Real-Time OS                  */
/*    プロセッサ抽象化コンポーネント (日立 SH2用)                           */
/*    割り込みハンドラ                                                      */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.global	__kernel_vecter004
				.global	__kernel_vecter005
				.global	__kernel_vecter006
				.global	__kernel_vecter007
				.global	__kernel_vecter008
				.global	__kernel_vecter009
				.global	__kernel_vecter010
				.global	__kernel_vecter011
				.global	__kernel_vecter012
				.global	__kernel_vecter013
				.global	__kernel_vecter014
				.global	__kernel_vecter015
				.global	__kernel_vecter016
				.global	__kernel_vecter017
				.global	__kernel_vecter018
				.global	__kernel_vecter019
				.global	__kernel_vecter020
				.global	__kernel_vecter021
				.global	__kernel_vecter022
				.global	__kernel_vecter023
				.global	__kernel_vecter024
				.global	__kernel_vecter025
				.global	__kernel_vecter026
				.global	__kernel_vecter027
				.global	__kernel_vecter028
				.global	__kernel_vecter029
				.global	__kernel_vecter030
				.global	__kernel_vecter031
				.global	__kernel_vecter032
				.global	__kernel_vecter033
				.global	__kernel_vecter034
				.global	__kernel_vecter035
				.global	__kernel_vecter036
				.global	__kernel_vecter037
				.global	__kernel_vecter038
				.global	__kernel_vecter039
				.global	__kernel_vecter040
				.global	__kernel_vecter041
				.global	__kernel_vecter042
				.global	__kernel_vecter043
				.global	__kernel_vecter044
				.global	__kernel_vecter045
				.global	__kernel_vecter046
				.global	__kernel_vecter047
				.global	__kernel_vecter048
				.global	__kernel_vecter049
				.global	__kernel_vecter050
				.global	__kernel_vecter051
				.global	__kernel_vecter052
				.global	__kernel_vecter053
				.global	__kernel_vecter054
				.global	__kernel_vecter055
				.global	__kernel_vecter056
				.global	__kernel_vecter057
				.global	__kernel_vecter058
				.global	__kernel_vecter059
				.global	__kernel_vecter060
				.global	__kernel_vecter061
				.global	__kernel_vecter062
				.global	__kernel_vecter063
				.global	__kernel_vecter064
				.global	__kernel_vecter065
				.global	__kernel_vecter066
				.global	__kernel_vecter067
				.global	__kernel_vecter068
				.global	__kernel_vecter069
				.global	__kernel_vecter070
				.global	__kernel_vecter071
				.global	__kernel_vecter072
				.global	__kernel_vecter073
				.global	__kernel_vecter074
				.global	__kernel_vecter075
				.global	__kernel_vecter076
				.global	__kernel_vecter077
				.global	__kernel_vecter078
				.global	__kernel_vecter079
				.global	__kernel_vecter080
				.global	__kernel_vecter081
				.global	__kernel_vecter082
				.global	__kernel_vecter083
				.global	__kernel_vecter084
				.global	__kernel_vecter085
				.global	__kernel_vecter086
				.global	__kernel_vecter087
				.global	__kernel_vecter088
				.global	__kernel_vecter089
				.global	__kernel_vecter090
				.global	__kernel_vecter091
				.global	__kernel_vecter092
				.global	__kernel_vecter093
				.global	__kernel_vecter094
				.global	__kernel_vecter095
				.global	__kernel_vecter096
				.global	__kernel_vecter097
				.global	__kernel_vecter098
				.global	__kernel_vecter099
				.global	__kernel_vecter100
				.global	__kernel_vecter101
				.global	__kernel_vecter102
				.global	__kernel_vecter103
				.global	__kernel_vecter104
				.global	__kernel_vecter105
				.global	__kernel_vecter106
				.global	__kernel_vecter107
				.global	__kernel_vecter108
				.global	__kernel_vecter109
				.global	__kernel_vecter110
				.global	__kernel_vecter111
				.global	__kernel_vecter112
				.global	__kernel_vecter113
				.global	__kernel_vecter114
				.global	__kernel_vecter115
				.global	__kernel_vecter116
				.global	__kernel_vecter117
				.global	__kernel_vecter118
				.global	__kernel_vecter119
				.global	__kernel_vecter120
				.global	__kernel_vecter121
				.global	__kernel_vecter122
				.global	__kernel_vecter123
				.global	__kernel_vecter124
				.global	__kernel_vecter125
				.global	__kernel_vecter126
				.global	__kernel_vecter127
				.global	__kernel_vecter128
				.global	__kernel_vecter129
				.global	__kernel_vecter130
				.global	__kernel_vecter131
				.global	__kernel_vecter132
				.global	__kernel_vecter133
				.global	__kernel_vecter134
				.global	__kernel_vecter135
				.global	__kernel_vecter136
				.global	__kernel_vecter137
				.global	__kernel_vecter138
				.global	__kernel_vecter139
				.global	__kernel_vecter140
				.global	__kernel_vecter141
				.global	__kernel_vecter142
				.global	__kernel_vecter143
				.global	__kernel_vecter144
				.global	__kernel_vecter145
				.global	__kernel_vecter146
				.global	__kernel_vecter147
				.global	__kernel_vecter148
				.global	__kernel_vecter149
				.global	__kernel_vecter150
				.global	__kernel_vecter151
				.global	__kernel_vecter152
				.global	__kernel_vecter153
				.global	__kernel_vecter154
				.global	__kernel_vecter155
				.global	__kernel_vecter156


				.text


/************************************************
  割り込みハンドラ
************************************************/
__kernel_vecter004:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#4, r4

__kernel_vecter005:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#5, r4

__kernel_vecter006:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#6, r4

__kernel_vecter007:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#7, r4

__kernel_vecter008:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#8, r4

__kernel_vecter009:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#9, r4

__kernel_vecter010:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#10, r4

__kernel_vecter011:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#11, r4

__kernel_vecter012:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#12, r4

__kernel_vecter013:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#13, r4

__kernel_vecter014:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#14, r4

__kernel_vecter015:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#15, r4

__kernel_vecter016:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#16, r4

__kernel_vecter017:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#17, r4

__kernel_vecter018:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#18, r4

__kernel_vecter019:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#19, r4

__kernel_vecter020:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#20, r4

__kernel_vecter021:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#21, r4

__kernel_vecter022:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#22, r4

__kernel_vecter023:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#23, r4

__kernel_vecter024:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#24, r4

__kernel_vecter025:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#25, r4

__kernel_vecter026:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#26, r4

__kernel_vecter027:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#27, r4

__kernel_vecter028:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#28, r4

__kernel_vecter029:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#29, r4

__kernel_vecter030:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#30, r4

__kernel_vecter031:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#31, r4

__kernel_vecter032:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#32, r4

__kernel_vecter033:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#33, r4

__kernel_vecter034:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#34, r4

__kernel_vecter035:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#35, r4

__kernel_vecter036:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#36, r4

__kernel_vecter037:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#37, r4

__kernel_vecter038:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#38, r4

__kernel_vecter039:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#39, r4

__kernel_vecter040:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#40, r4

__kernel_vecter041:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#41, r4

__kernel_vecter042:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#42, r4

__kernel_vecter043:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#43, r4

__kernel_vecter044:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#44, r4

__kernel_vecter045:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#45, r4

__kernel_vecter046:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#46, r4

__kernel_vecter047:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#47, r4

__kernel_vecter048:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#48, r4

__kernel_vecter049:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#49, r4

__kernel_vecter050:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#50, r4

__kernel_vecter051:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#51, r4

__kernel_vecter052:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#52, r4

__kernel_vecter053:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#53, r4

__kernel_vecter054:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#54, r4

__kernel_vecter055:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#55, r4

__kernel_vecter056:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#56, r4

__kernel_vecter057:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#57, r4

__kernel_vecter058:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#58, r4

__kernel_vecter059:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#59, r4

__kernel_vecter060:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#60, r4

__kernel_vecter061:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#61, r4

__kernel_vecter062:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#62, r4

__kernel_vecter063:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#63, r4



__kernel_vecter064:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#64, r4

__kernel_vecter065:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#65, r4

__kernel_vecter066:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#66, r4

__kernel_vecter067:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#67, r4

__kernel_vecter068:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#68, r4

__kernel_vecter069:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#69, r4

__kernel_vecter070:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#70, r4

__kernel_vecter071:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#71, r4

__kernel_vecter072:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#72, r4

__kernel_vecter073:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#73, r4

__kernel_vecter074:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#74, r4

__kernel_vecter075:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#75, r4

__kernel_vecter076:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#76, r4

__kernel_vecter077:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#77, r4

__kernel_vecter078:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#78, r4

__kernel_vecter079:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#79, r4

__kernel_vecter080:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#80, r4

__kernel_vecter081:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#81, r4

__kernel_vecter082:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#82, r4

__kernel_vecter083:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#83, r4

__kernel_vecter084:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#84, r4

__kernel_vecter085:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#85, r4

__kernel_vecter086:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#86, r4

__kernel_vecter087:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#87, r4

__kernel_vecter088:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#88, r4

__kernel_vecter089:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#89, r4

__kernel_vecter090:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#90, r4

__kernel_vecter091:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#91, r4

__kernel_vecter092:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#92, r4

__kernel_vecter093:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#93, r4

__kernel_vecter094:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#94, r4

__kernel_vecter095:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#95, r4

__kernel_vecter096:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#96, r4

__kernel_vecter097:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#97, r4

__kernel_vecter098:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#98, r4

__kernel_vecter099:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#99, r4

__kernel_vecter100:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#100, r4

__kernel_vecter101:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#101, r4

__kernel_vecter102:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#102, r4

__kernel_vecter103:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#103, r4

__kernel_vecter104:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#104, r4

__kernel_vecter105:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#105, r4

__kernel_vecter106:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#106, r4

__kernel_vecter107:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#107, r4

__kernel_vecter108:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#108, r4

__kernel_vecter109:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#109, r4

__kernel_vecter110:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#110, r4

__kernel_vecter111:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#111, r4

__kernel_vecter112:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#112, r4

__kernel_vecter113:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#113, r4

__kernel_vecter114:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#114, r4

__kernel_vecter115:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#115, r4

__kernel_vecter116:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#116, r4

__kernel_vecter117:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#117, r4

__kernel_vecter118:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#118, r4

__kernel_vecter119:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#119, r4

__kernel_vecter120:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#120, r4

__kernel_vecter121:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#121, r4

__kernel_vecter122:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#122, r4

__kernel_vecter123:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#123, r4

__kernel_vecter124:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#124, r4

__kernel_vecter125:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#125, r4

__kernel_vecter126:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#126, r4

__kernel_vecter127:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#127, r4

__kernel_vecter128:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#128, r4

__kernel_vecter129:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#129, r4

__kernel_vecter130:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#130, r4

__kernel_vecter131:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#131, r4

__kernel_vecter132:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#132, r4

__kernel_vecter133:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#133, r4

__kernel_vecter134:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#134, r4

__kernel_vecter135:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#135, r4

__kernel_vecter136:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#136, r4

__kernel_vecter137:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#137, r4

__kernel_vecter138:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#138, r4

__kernel_vecter139:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#139, r4

__kernel_vecter140:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#140, r4

__kernel_vecter141:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#141, r4

__kernel_vecter142:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#142, r4

__kernel_vecter143:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#143, r4

__kernel_vecter144:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#144, r4

__kernel_vecter145:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#145, r4

__kernel_vecter146:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#146, r4

__kernel_vecter147:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#147, r4

__kernel_vecter148:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#148, r4

__kernel_vecter149:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#149, r4

__kernel_vecter150:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#150, r4

__kernel_vecter151:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#151, r4

__kernel_vecter152:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#152, r4

__kernel_vecter153:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#153, r4

__kernel_vecter154:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#154, r4

__kernel_vecter155:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#155, r4

__kernel_vecter156:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#156, r4

__kernel_vector_157:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#157, r4

__kernel_vector_158:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#158, r4

__kernel_vector_159:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#159, r4

__kernel_vector_160:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#160, r4

__kernel_vector_161:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#161, r4

__kernel_vector_162:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#162, r4

__kernel_vector_163:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#163, r4

__kernel_vector_164:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#164, r4

__kernel_vector_165:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#165, r4

__kernel_vector_166:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#166, r4

__kernel_vector_167:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#167, r4

__kernel_vector_168:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#168, r4

__kernel_vector_169:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#169, r4

__kernel_vector_170:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#170, r4

__kernel_vector_171:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#171, r4

__kernel_vector_172:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#172, r4

__kernel_vector_173:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#173, r4

__kernel_vector_174:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#174, r4

__kernel_vector_175:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#175, r4

__kernel_vector_176:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#176, r4

__kernel_vector_177:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#177, r4

__kernel_vector_178:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#178, r4

__kernel_vector_179:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#179, r4

__kernel_vector_180:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#180, r4

__kernel_vector_181:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#181, r4

__kernel_vector_182:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#182, r4

__kernel_vector_183:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#183, r4

__kernel_vector_184:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#184, r4

__kernel_vector_185:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#185, r4

__kernel_vector_186:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#186, r4

__kernel_vector_187:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#187, r4

__kernel_vector_188:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#188, r4

__kernel_vector_189:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#189, r4

__kernel_vector_190:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#190, r4

__kernel_vector_191:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#191, r4

__kernel_vector_192:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#192, r4

__kernel_vector_193:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#193, r4

__kernel_vector_194:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#194, r4

__kernel_vector_195:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#195, r4

__kernel_vector_196:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#196, r4

__kernel_vector_197:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#197, r4

__kernel_vector_198:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#198, r4

__kernel_vector_199:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#199, r4

__kernel_vector_200:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#200, r4

__kernel_vector_201:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#201, r4

__kernel_vector_202:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#202, r4

__kernel_vector_203:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#203, r4

__kernel_vector_204:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#204, r4

__kernel_vector_205:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#205, r4

__kernel_vector_206:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#206, r4

__kernel_vector_207:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#207, r4

__kernel_vector_208:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#208, r4

__kernel_vector_209:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#209, r4

__kernel_vector_210:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#210, r4

__kernel_vector_211:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#211, r4

__kernel_vector_212:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#212, r4

__kernel_vector_213:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#213, r4

__kernel_vector_214:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#214, r4

__kernel_vector_215:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#215, r4

__kernel_vector_216:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#216, r4

__kernel_vector_217:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#217, r4

__kernel_vector_218:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#218, r4

__kernel_vector_219:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#219, r4

__kernel_vector_220:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#220, r4

__kernel_vector_221:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#221, r4

__kernel_vector_222:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#222, r4

__kernel_vector_223:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#223, r4

__kernel_vector_224:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#224, r4

__kernel_vector_225:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#225, r4

__kernel_vector_226:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#226, r4

__kernel_vector_227:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#227, r4

__kernel_vector_228:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#228, r4

__kernel_vector_229:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#229, r4

__kernel_vector_230:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#230, r4

__kernel_vector_231:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#231, r4

__kernel_vector_232:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#232, r4

__kernel_vector_233:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#233, r4

__kernel_vector_234:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#234, r4

__kernel_vector_235:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#235, r4

__kernel_vector_236:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#236, r4

__kernel_vector_237:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#237, r4

__kernel_vector_238:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#238, r4

__kernel_vector_239:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#239, r4

__kernel_vector_240:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#240, r4

__kernel_vector_241:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#241, r4

__kernel_vector_242:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#242, r4

__kernel_vector_243:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#243, r4

__kernel_vector_244:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#244, r4

__kernel_vector_245:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#245, r4

__kernel_vector_246:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#246, r4

__kernel_vector_247:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#247, r4

__kernel_vector_248:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#248, r4

__kernel_vector_249:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#249, r4

__kernel_vector_250:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#250, r4

__kernel_vector_251:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#251, r4

__kernel_vector_252:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#252, r4

__kernel_vector_253:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#253, r4

__kernel_vector_254:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#254, r4

__kernel_vector_255:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#255, r4

#endif



/************************************************
  割り込みハンドラ

  r4をスタックに積んだ後、r4に割り込み番号を
  格納してここに分岐するものとする
************************************************/
				.align	2
__kernel_int_hdr:
		/* ---- 多重割り込みをマスク */
				mov.l	r0, @-r15			/* r0 退避(割込み元のスタック) */
				stc		sr, r0
				mov.l	r1, @-r15			/* r1 退避(割込み元のスタック) */
				mov		r0, r1				/* sr 保存 */
				or		#h'f0, r0
				ldc		r0, sr				/* 全割り込みマスク */

		/* ---- レジスタ保存(r2-r7,pr) */
				mov.l	r2, @-r15			/* r2 退避(割込み元のスタック) */
				mov.l	r1, r0				/* srを移動 */
				mov.l	r3, @-r15			/* r3 退避(割込み元のスタック) */
				and		#h'f0, r0			/* 割り込みマスクレベル取り出し */
				mov.l	r5, @-r15			/* r5 退避(割込み元のスタック) */
				mov.l	r0, r2				/* r2に新しい割込みマスク値格納 */
				mov.l	r6, @-r15			/* r6 退避(割込み元のスタック) */
				extu.b	r4, r4				/* 割込み番号の符号拡張をクリア */
				mov.l	r7, @-r15			/* r7 退避(割込み元のスタック) */
				mov.l	addr_int_cnt, r5
				sts.l	pr, @-r15			/* pr 退避(割込み元のスタック) */

		/* ---- 割り込みマスク値の設定＆多重割り込み判定 */
				mov.l	@r5, r0				/* 割込みネストカウンタ取り出し */
				mov.l	addr_sh_imsk, r1
				cmp/eq	#0, r0				/* 初回割込み判定 */
				mov.l	@r1, r3				/* r3に古い割込みマスク値格納 */
				add		#1, r0				/* 割込みネストカウンタ加算 */
				mov.l	r2, @r1				/* 新しい割込みマスク値設定 */
				bf/s	multiple_int		/* 多重割込み処理へ分岐 */
				mov.l	r0, @r5				/* 割り込みネスト値を設定(遅延スロット) */

		/* ==== 初回割り込みの処理 */

		/* ---- スタック入れ替え */
				mov.l	r15, r0				/* 現在のスタックを退避 */
				mov.l	addr_int_isp, r1
				mov.l	@r1, r15			/* 割込み用スタックを設定 */
				mov.l	r0, @-r15			/* 割込み前のスタックポインタを保存 */
				
		/* ---- 古いマスク値を保存 */
				mov.l	r3, @-r15			/* 古いマスク値を保存 */
				
		/* ---- 割り込み開始処理呼び出し */
				mov.l	addr_sta_inh, r1
				jsr		@r1
				mov.l	r4, @-r15			/* 割込み番号を退避(遅延スロット) */
				
		/* ---- 割り込み実行処理呼び出し */
				mov.l	addr_exe_inh, r1
				jsr		@r1
				mov.l	@r15+, r4			/* 割込み番号を引数とする(遅延スロット) */
				
		/* ---- 古いマスク値を取り出し */
				mov.l	@r15+, r3			/* 古い割込みマスク値を取り出し */
				
		/* ---- スタックの復帰 */
				mov.l	@r15, r15
				
		/* ---- 割込みカウンタのクリア */
				mov.l	addr_int_cnt, r1
				xor		r0, r0
				mov.l	r0, @r1

		/* ---- 割込みマスク値復帰 */
				mov.l	@(40, r15), r0		/* 割込み前の sr を取り出し */
				mov.l	addr_sh_imsk, r1
				and		#h'f0, r0			/* 割込みマスク値取り出し */
				cmp/eq	r0, r3				/* 古い割込みマスク値と比較 */
				bf/s	return_int			/* 不一致なら既に割込み処理中とみなす */
				mov.l	r3, @r1				/* 割込み前の状態に割込みマスク値を設定(遅延スロット) */

		/* ---- 割込み終了処理呼び出し */
				mov.l	addr_end_inh, r2
				jsr		@r2
				nop
				
		/* ---- 復帰時割り込みマスクの設定 */
				mov.l	@(40, r15), r0		/* 割込み前の sr を取り出し */
				or		#h'f0, r0			/* 割込みマスク部分クリアの前処理(一旦ビットを立てる) */
				mov.l	addr_sh_imsk, r1
				xor		#h'f0, r0			/* 割込みマスク部分クリア(立てといて反転させる) */
				mov.l	@r1, r1				/* マスク値取得 */
				or		r1, r0				/* マスク値を設定 */
				mov.l	r0, @(40, r15)		/* 復帰時SRの設定 */
				
		/* ---- レジスタ復帰 */
return_int:
				lds.l	@r15+, pr
				mov.l	@r15+, r7
				mov.l	@r15+, r6
				mov.l	@r15+, r5
				mov.l	@r15+, r3
				mov.l	@r15+, r2
				mov.l	@r15+, r1
				mov.l	@r15+, r0
				mov.l	@r15+, r4
				rte
				nop



		/* ==== 多重割込みの処理 */
				.align	2
multiple_int:
		/* ---- 割込み実行処理呼び出し*/
				mov.l	addr_exe_inh, r1
				jsr		@r1					/* 割り込み番号(r4)を引数とする */
				mov.l	r3, @-r15			/* 古いマスク値を保存 */
				
		/* ---- 割込みカウンタの減算 */
				mov.l	addr_int_cnt, r1
				mov.l	@r1, r0
				add		#-1, r0
				mov.l	r0, @r1
				
		/* ---- 割込みマスク値の復帰 */
				mov.l	r3, @-r15			; 古いマスク値を復帰 */
				mov.l	addr_sh_imsk, r1
				bra		return_int
				mov.l	r3, @r1


				.align	2

addr_sh_imsk:
				.long	_kernel_sh_imsk			/* 割り込みマスク */

addr_int_cnt:
				.long	_kernel_int_cnt			/* 割り込みネスト回数 */

addr_int_ispr:
				.long	_kernel_int_isp			/* 割り込み用スタックポインタ */

addr_sta_inh:
				.long	_kernel_sta_inh			/* 割り込み開始処理 */

addr_exe_inh:
				.long	_kernel_exe_inh			/* 割り込み実行処理 */

addr_end_inh:
				.long	_kernel_end_inh			/* 割り込み終了処理 */



				.end


/* end of file */
