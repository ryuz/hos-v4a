/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  μITRON4.0仕様 Real-Time OS                  */
/*    プロセッサ抽象化コンポーネント (日立 SH2用)                           */
/*    割り込みハンドラ                                                      */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.global	_kernel_vecter004
				.global	_kernel_vecter005
				.global	_kernel_vecter006
				.global	_kernel_vecter007
				.global	_kernel_vecter008
				.global	_kernel_vecter009
				.global	_kernel_vecter010
				.global	_kernel_vecter011
				.global	_kernel_vecter012
				.global	_kernel_vecter013
				.global	_kernel_vecter014
				.global	_kernel_vecter015
				.global	_kernel_vecter016
				.global	_kernel_vecter017
				.global	_kernel_vecter018
				.global	_kernel_vecter019
				.global	_kernel_vecter020
				.global	_kernel_vecter021
				.global	_kernel_vecter022
				.global	_kernel_vecter023
				.global	_kernel_vecter024
				.global	_kernel_vecter025
				.global	_kernel_vecter026
				.global	_kernel_vecter027
				.global	_kernel_vecter028
				.global	_kernel_vecter029
				.global	_kernel_vecter030
				.global	_kernel_vecter031
				.global	_kernel_vecter032
				.global	_kernel_vecter033
				.global	_kernel_vecter034
				.global	_kernel_vecter035
				.global	_kernel_vecter036
				.global	_kernel_vecter037
				.global	_kernel_vecter038
				.global	_kernel_vecter039
				.global	_kernel_vecter040
				.global	_kernel_vecter041
				.global	_kernel_vecter042
				.global	_kernel_vecter043
				.global	_kernel_vecter044
				.global	_kernel_vecter045
				.global	_kernel_vecter046
				.global	_kernel_vecter047
				.global	_kernel_vecter048
				.global	_kernel_vecter049
				.global	_kernel_vecter050
				.global	_kernel_vecter051
				.global	_kernel_vecter052
				.global	_kernel_vecter053
				.global	_kernel_vecter054
				.global	_kernel_vecter055
				.global	_kernel_vecter056
				.global	_kernel_vecter057
				.global	_kernel_vecter058
				.global	_kernel_vecter059
				.global	_kernel_vecter060
				.global	_kernel_vecter061
				.global	_kernel_vecter062
				.global	_kernel_vecter063
				.global	_kernel_vecter064
				.global	_kernel_vecter065
				.global	_kernel_vecter066
				.global	_kernel_vecter067
				.global	_kernel_vecter068
				.global	_kernel_vecter069
				.global	_kernel_vecter070
				.global	_kernel_vecter071
				.global	_kernel_vecter072
				.global	_kernel_vecter073
				.global	_kernel_vecter074
				.global	_kernel_vecter075
				.global	_kernel_vecter076
				.global	_kernel_vecter077
				.global	_kernel_vecter078
				.global	_kernel_vecter079
				.global	_kernel_vecter080
				.global	_kernel_vecter081
				.global	_kernel_vecter082
				.global	_kernel_vecter083
				.global	_kernel_vecter084
				.global	_kernel_vecter085
				.global	_kernel_vecter086
				.global	_kernel_vecter087
				.global	_kernel_vecter088
				.global	_kernel_vecter089
				.global	_kernel_vecter090
				.global	_kernel_vecter091
				.global	_kernel_vecter092
				.global	_kernel_vecter093
				.global	_kernel_vecter094
				.global	_kernel_vecter095
				.global	_kernel_vecter096
				.global	_kernel_vecter097
				.global	_kernel_vecter098
				.global	_kernel_vecter099
				.global	_kernel_vecter100
				.global	_kernel_vecter101
				.global	_kernel_vecter102
				.global	_kernel_vecter103
				.global	_kernel_vecter104
				.global	_kernel_vecter105
				.global	_kernel_vecter106
				.global	_kernel_vecter107
				.global	_kernel_vecter108
				.global	_kernel_vecter109
				.global	_kernel_vecter110
				.global	_kernel_vecter111
				.global	_kernel_vecter112
				.global	_kernel_vecter113
				.global	_kernel_vecter114
				.global	_kernel_vecter115
				.global	_kernel_vecter116
				.global	_kernel_vecter117
				.global	_kernel_vecter118
				.global	_kernel_vecter119
				.global	_kernel_vecter120
				.global	_kernel_vecter121
				.global	_kernel_vecter122
				.global	_kernel_vecter123
				.global	_kernel_vecter124
				.global	_kernel_vecter125
				.global	_kernel_vecter126
				.global	_kernel_vecter127
				.global	_kernel_vecter128
				.global	_kernel_vecter129
				.global	_kernel_vecter130
				.global	_kernel_vecter131
				.global	_kernel_vecter132
				.global	_kernel_vecter133
				.global	_kernel_vecter134
				.global	_kernel_vecter135
				.global	_kernel_vecter136
				.global	_kernel_vecter137
				.global	_kernel_vecter138
				.global	_kernel_vecter139
				.global	_kernel_vecter140
				.global	_kernel_vecter141
				.global	_kernel_vecter142
				.global	_kernel_vecter143
				.global	_kernel_vecter144
				.global	_kernel_vecter145
				.global	_kernel_vecter146
				.global	_kernel_vecter147
				.global	_kernel_vecter148
				.global	_kernel_vecter149
				.global	_kernel_vecter150
				.global	_kernel_vecter151
				.global	_kernel_vecter152
				.global	_kernel_vecter153
				.global	_kernel_vecter154
				.global	_kernel_vecter155
				.global	_kernel_vecter156


				.text


/************************************************
  割り込みハンドラ
************************************************/
_kernel_vecter004:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#4, r4

_kernel_vecter005:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#5, r4

_kernel_vecter006:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#6, r4

_kernel_vecter007:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#7, r4

_kernel_vecter008:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#8, r4

_kernel_vecter009:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#9, r4

_kernel_vecter010:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#10, r4

_kernel_vecter011:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#11, r4

_kernel_vecter012:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#12, r4

_kernel_vecter013:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#13, r4

_kernel_vecter014:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#14, r4

_kernel_vecter015:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#15, r4

_kernel_vecter016:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#16, r4

_kernel_vecter017:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#17, r4

_kernel_vecter018:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#18, r4

_kernel_vecter019:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#19, r4

_kernel_vecter020:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#20, r4

_kernel_vecter021:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#21, r4

_kernel_vecter022:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#22, r4

_kernel_vecter023:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#23, r4

_kernel_vecter024:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#24, r4

_kernel_vecter025:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#25, r4

_kernel_vecter026:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#26, r4

_kernel_vecter027:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#27, r4

_kernel_vecter028:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#28, r4

_kernel_vecter029:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#29, r4

_kernel_vecter030:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#30, r4

_kernel_vecter031:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#31, r4

_kernel_vecter032:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#32, r4

_kernel_vecter033:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#33, r4

_kernel_vecter034:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#34, r4

_kernel_vecter035:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#35, r4

_kernel_vecter036:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#36, r4

_kernel_vecter037:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#37, r4

_kernel_vecter038:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#38, r4

_kernel_vecter039:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#39, r4

_kernel_vecter040:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#40, r4

_kernel_vecter041:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#41, r4

_kernel_vecter042:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#42, r4

_kernel_vecter043:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#43, r4

_kernel_vecter044:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#44, r4

_kernel_vecter045:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#45, r4

_kernel_vecter046:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#46, r4

_kernel_vecter047:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#47, r4

_kernel_vecter048:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#48, r4

_kernel_vecter049:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#49, r4

_kernel_vecter050:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#50, r4

_kernel_vecter051:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#51, r4

_kernel_vecter052:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#52, r4

_kernel_vecter053:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#53, r4

_kernel_vecter054:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#54, r4

_kernel_vecter055:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#55, r4

_kernel_vecter056:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#56, r4

_kernel_vecter057:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#57, r4

_kernel_vecter058:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#58, r4

_kernel_vecter059:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#59, r4

_kernel_vecter060:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#60, r4

_kernel_vecter061:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#61, r4

_kernel_vecter062:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#62, r4

_kernel_vecter063:
				mov.l	r4, @-r15
				bra		_kernel_exc_hdr
				mov		#63, r4



_kernel_vecter064:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#64, r4

_kernel_vecter065:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#65, r4

_kernel_vecter066:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#66, r4

_kernel_vecter067:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#67, r4

_kernel_vecter068:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#68, r4

_kernel_vecter069:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#69, r4

_kernel_vecter070:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#70, r4

_kernel_vecter071:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#71, r4

_kernel_vecter072:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#72, r4

_kernel_vecter073:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#73, r4

_kernel_vecter074:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#74, r4

_kernel_vecter075:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#75, r4

_kernel_vecter076:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#76, r4

_kernel_vecter077:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#77, r4

_kernel_vecter078:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#78, r4

_kernel_vecter079:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#79, r4

_kernel_vecter080:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#80, r4

_kernel_vecter081:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#81, r4

_kernel_vecter082:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#82, r4

_kernel_vecter083:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#83, r4

_kernel_vecter084:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#84, r4

_kernel_vecter085:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#85, r4

_kernel_vecter086:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#86, r4

_kernel_vecter087:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#87, r4

_kernel_vecter088:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#88, r4

_kernel_vecter089:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#89, r4

_kernel_vecter090:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#90, r4

_kernel_vecter091:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#91, r4

_kernel_vecter092:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#92, r4

_kernel_vecter093:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#93, r4

_kernel_vecter094:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#94, r4

_kernel_vecter095:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#95, r4

_kernel_vecter096:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#96, r4

_kernel_vecter097:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#97, r4

_kernel_vecter098:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#98, r4

_kernel_vecter099:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#99, r4

_kernel_vecter100:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#100, r4

_kernel_vecter101:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#101, r4

_kernel_vecter102:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#102, r4

_kernel_vecter103:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#103, r4

_kernel_vecter104:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#104, r4

_kernel_vecter105:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#105, r4

_kernel_vecter106:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#106, r4

_kernel_vecter107:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#107, r4

_kernel_vecter108:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#108, r4

_kernel_vecter109:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#109, r4

_kernel_vecter110:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#110, r4

_kernel_vecter111:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#111, r4

_kernel_vecter112:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#112, r4

_kernel_vecter113:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#113, r4

_kernel_vecter114:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#114, r4

_kernel_vecter115:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#115, r4

_kernel_vecter116:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#116, r4

_kernel_vecter117:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#117, r4

_kernel_vecter118:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#118, r4

_kernel_vecter119:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#119, r4

_kernel_vecter120:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#120, r4

_kernel_vecter121:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#121, r4

_kernel_vecter122:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#122, r4

_kernel_vecter123:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#123, r4

_kernel_vecter124:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#124, r4

_kernel_vecter125:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#125, r4

_kernel_vecter126:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#126, r4

_kernel_vecter127:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#127, r4

_kernel_vecter128:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#128, r4

_kernel_vecter129:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#129, r4

_kernel_vecter130:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#130, r4

_kernel_vecter131:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#131, r4

_kernel_vecter132:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#132, r4

_kernel_vecter133:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#133, r4

_kernel_vecter134:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#134, r4

_kernel_vecter135:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#135, r4

_kernel_vecter136:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#136, r4

_kernel_vecter137:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#137, r4

_kernel_vecter138:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#138, r4

_kernel_vecter139:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#139, r4

_kernel_vecter140:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#140, r4

_kernel_vecter141:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#141, r4

_kernel_vecter142:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#142, r4

_kernel_vecter143:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#143, r4

_kernel_vecter144:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#144, r4

_kernel_vecter145:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#145, r4

_kernel_vecter146:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#146, r4

_kernel_vecter147:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#147, r4

_kernel_vecter148:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#148, r4

_kernel_vecter149:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#149, r4

_kernel_vecter150:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#150, r4

_kernel_vecter151:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#151, r4

_kernel_vecter152:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#152, r4

_kernel_vecter153:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#153, r4

_kernel_vecter154:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#154, r4

_kernel_vecter155:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#155, r4

_kernel_vecter156:
				mov.l	r4, @-r15
				bra		_kernel_int_hdr
				mov		#156, r4


/************************************************
  CPU例外ハンドラ
  r4をスタックに積んだ後、r4に割り込み番号を
  格納してここに分岐するものとする
************************************************/
_kernel_exc_hdr:
				rte
				nop


/************************************************
  割り込みハンドラ

  r4をスタックに積んだ後、r4に割り込み番号を
  格納してここに分岐するものとする
************************************************/
				.align	2
_kernel_int_hdr:
				/* レジスタ退避(r0-r1) */
				mov.l	r0, @-r15
				mov.l	r1, @-r15
				
				/* 割り込みマスク設定 */
				stc		sr, r0
				mov		r0, r1
				or		#0xf0, r0	/* 割り込み全マスク設定 */
				ldc		r0, sr
				
				/* 割り込みマスクの保存 */
				mov		r1, r0
				and		#0xf0, r0
				mov.l	imsk_addr, r1
				mov.l	r0, @r1
				
				/* 割り込み番号の符号拡張をクリア */
				extu.b	r4, r4
				
				/* レジスタ保存(r2-r7,mach,macl,pr) */
				mov.l	r2, @-r15
				mov.l	r3, @-r15
				mov.l	r5, @-r15
				mov.l	r6, @-r15
				mov.l	r7, @-r15
				sts.l	mach, @-r15
				sts.l	macl, @-r15
				sts.l	pr, @-r15
				
				/* 多重割り込み判定 */
				mov.l	int_cnt_addr, r1
				mov.l	@r1, r0
				cmp/eq	#0, r0
				bf/s	int_multi
				add		#1, r0
				
				/* 単独割り込み時 */
				mov.l	r0, @r1				/* 割り込みネスト値を設定 */
				
				/* スタック入れ替え */
				mov.l	save_sp_addr, r0
				mov.l	r15, @r0			/* 現在のスタックを退避 */
				mov.l	int_sp_addr, r0
				mov.l	@r0, r15			/* 割り込み用スタックを設定 */
				
				mov.l	r4, @-r15			/* 割り込み番号を退避 */
				
				/* 割り込み開始処理呼び出し */
				mov.l	sta_int_addr, r1
				jsr		@r1
				nop
				
				/* 割り込み実行処理呼び出し */
				mov.l	exe_int_addr, r1
				jsr		@r1
				mov.l	@r15+, r4			/* 割り込み番号を引数とする */
				
				/* スタックの復帰 */
				mov.l	save_sp_addr, r0
				mov.l	@r0, r15
				
				/* 割り込みカウンタのクリア */
				mov.l	int_cnt_addr, r1
				xor		r0, r0
				mov.l	r0, @r1
				
				/* ベースマスク値に戻す */
				mov.l	imsk_base_addr, r0
				mov.l	@r0, r1
				mov.l	imsk_addr, r0
				mov.l	r1, @r0
				
				/* 割り込み終了処理呼び出し */
				mov.l	end_int_addr, r1
				jsr		@r1
				nop
				
				/* レジスタ復帰 */
				lds.l	@r15+, pr
				lds.l	@r15+, macl
				lds.l	@r15+, mach
				mov.l	@r15+, r7
				mov.l	@r15+, r6
				mov.l	@r15+, r5
				mov.l	@r15+, r3
				mov.l	@r15+, r2
				mov.l	@r15+, r1
				
				/* 復帰時割り込みマスクの設定 */
				mov.l	imsk_addr, r4
				mov.l	@r4, r4					/* マスク値取得 */
				mov.l	@(8, r15), r0
				or		r4, r0
				mov.l	r0, @(8, r15)			/* 復帰時SRのマスク設定 */
				
				mov.l	@r15+, r0
				mov.l	@r15+, r4
				rte
				nop

				/* 多重割り込み処理 */
int_multi:		
				mov.l	r0, @r1				/* 割り込みネスト値を設定 */
				
				/* 割り込み実行処理呼び出し */
				mov.l	exe_int_addr, r1
				jsr		@r1			/* 割り込み番号を引数とする */
				nop
				
				/* 割り込みカウンタの減算 */
				mov.l	int_cnt_addr, r1
				mov.l	@r1, r0
				add		#-1, r0
				mov.l	r0, @r1
				
				/* レジスタ復帰 */
				lds.l	@r15+, pr
				lds.l	@r15+, macl
				lds.l	@r15+, mach
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


				.align	2

imsk_addr:
				.long	_kernel_sh_imsk			/* 割り込みマスク */

imsk_base_addr:
				.long	_hospac_sh_imsk_base	/* 割り込みマスクベース値 */

int_cnt_addr:
				.long	_kernel_int_cnt			/* 割り込みネスト回数 */

save_sp_addr:
				.long	_kernel_int_ssp			/* 割り込み用スタックポインタ退避 */

int_sp_addr:
				.long	_kernel_int_sp			/* 割り込み用スタックポインタ */

sta_int_addr:
				.long	_kernel_sta_int			/* 割り込み開始処理 */

end_int_addr:
				.long	_kernel_end_int			/* 割り込み終了処理 */

exe_int_addr:
				.long	_kernel_exe_int			/* 割り込み実行処理 */



				.end


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
