/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

				.global	__kernel_int_hdr
				.global	__kernel_ictxcb
				.global	__kernel_sta_inh
				.global	__kernel_exe_inh
				.global	__kernel_end_inh


				.text



#ifdef _KERNEL_FAST_INTVEC

/************************************************
    高速割り込みベクタ利用時、bra で分岐可能な
  位置にベクタ入り口を設置。ただし未使用の
  ベクタまでリンクされてしまう。
 ************************************************/

				.global	__kernel_vector_064
				.global	__kernel_vector_065
				.global	__kernel_vector_066
				.global	__kernel_vector_067
				.global	__kernel_vector_068
				.global	__kernel_vector_069
				.global	__kernel_vector_070
				.global	__kernel_vector_071
				.global	__kernel_vector_072
				.global	__kernel_vector_073
				.global	__kernel_vector_074
				.global	__kernel_vector_075
				.global	__kernel_vector_076
				.global	__kernel_vector_077
				.global	__kernel_vector_078
				.global	__kernel_vector_079
				.global	__kernel_vector_080
				.global	__kernel_vector_081
				.global	__kernel_vector_082
				.global	__kernel_vector_083
				.global	__kernel_vector_084
				.global	__kernel_vector_085
				.global	__kernel_vector_086
				.global	__kernel_vector_087
				.global	__kernel_vector_088
				.global	__kernel_vector_089
				.global	__kernel_vector_090
				.global	__kernel_vector_091
				.global	__kernel_vector_092
				.global	__kernel_vector_093
				.global	__kernel_vector_094
				.global	__kernel_vector_095
				.global	__kernel_vector_096
				.global	__kernel_vector_097
				.global	__kernel_vector_098
				.global	__kernel_vector_099
				.global	__kernel_vector_100
				.global	__kernel_vector_101
				.global	__kernel_vector_102
				.global	__kernel_vector_103
				.global	__kernel_vector_104
				.global	__kernel_vector_105
				.global	__kernel_vector_106
				.global	__kernel_vector_107
				.global	__kernel_vector_108
				.global	__kernel_vector_109
				.global	__kernel_vector_110
				.global	__kernel_vector_111
				.global	__kernel_vector_112
				.global	__kernel_vector_113
				.global	__kernel_vector_114
				.global	__kernel_vector_115
				.global	__kernel_vector_116
				.global	__kernel_vector_117
				.global	__kernel_vector_118
				.global	__kernel_vector_119
				.global	__kernel_vector_120
				.global	__kernel_vector_121
				.global	__kernel_vector_122
				.global	__kernel_vector_123
				.global	__kernel_vector_124
				.global	__kernel_vector_125
				.global	__kernel_vector_126
				.global	__kernel_vector_127
				.global	__kernel_vector_128
				.global	__kernel_vector_129
				.global	__kernel_vector_130
				.global	__kernel_vector_131
				.global	__kernel_vector_132
				.global	__kernel_vector_133
				.global	__kernel_vector_134
				.global	__kernel_vector_135
				.global	__kernel_vector_136
				.global	__kernel_vector_137
				.global	__kernel_vector_138
				.global	__kernel_vector_139
				.global	__kernel_vector_140
				.global	__kernel_vector_141
				.global	__kernel_vector_142
				.global	__kernel_vector_143
				.global	__kernel_vector_144
				.global	__kernel_vector_145
				.global	__kernel_vector_146
				.global	__kernel_vector_147
				.global	__kernel_vector_148
				.global	__kernel_vector_149
				.global	__kernel_vector_150
				.global	__kernel_vector_151
				.global	__kernel_vector_152
				.global	__kernel_vector_153
				.global	__kernel_vector_154
				.global	__kernel_vector_155
				.global	__kernel_vector_156
				.global	__kernel_vector_157
				.global	__kernel_vector_158
				.global	__kernel_vector_159
				.global	__kernel_vector_160
				.global	__kernel_vector_161
				.global	__kernel_vector_162
				.global	__kernel_vector_163
				.global	__kernel_vector_164
				.global	__kernel_vector_165
				.global	__kernel_vector_166
				.global	__kernel_vector_167
				.global	__kernel_vector_168
				.global	__kernel_vector_169
				.global	__kernel_vector_170
				.global	__kernel_vector_171
				.global	__kernel_vector_172
				.global	__kernel_vector_173
				.global	__kernel_vector_174
				.global	__kernel_vector_175
				.global	__kernel_vector_176
				.global	__kernel_vector_177
				.global	__kernel_vector_178
				.global	__kernel_vector_179
				.global	__kernel_vector_180
				.global	__kernel_vector_181
				.global	__kernel_vector_182
				.global	__kernel_vector_183
				.global	__kernel_vector_184
				.global	__kernel_vector_185
				.global	__kernel_vector_186
				.global	__kernel_vector_187
				.global	__kernel_vector_188
				.global	__kernel_vector_189
				.global	__kernel_vector_190
				.global	__kernel_vector_191
				.global	__kernel_vector_192
				.global	__kernel_vector_193
				.global	__kernel_vector_194
				.global	__kernel_vector_195
				.global	__kernel_vector_196
				.global	__kernel_vector_197
				.global	__kernel_vector_198
				.global	__kernel_vector_199
				.global	__kernel_vector_200
				.global	__kernel_vector_201
				.global	__kernel_vector_202
				.global	__kernel_vector_203
				.global	__kernel_vector_204
				.global	__kernel_vector_205
				.global	__kernel_vector_206
				.global	__kernel_vector_207
				.global	__kernel_vector_208
				.global	__kernel_vector_209
				.global	__kernel_vector_210
				.global	__kernel_vector_211
				.global	__kernel_vector_212
				.global	__kernel_vector_213
				.global	__kernel_vector_214
				.global	__kernel_vector_215
				.global	__kernel_vector_216
				.global	__kernel_vector_217
				.global	__kernel_vector_218
				.global	__kernel_vector_219
				.global	__kernel_vector_220
				.global	__kernel_vector_221
				.global	__kernel_vector_222
				.global	__kernel_vector_223
				.global	__kernel_vector_224
				.global	__kernel_vector_225
				.global	__kernel_vector_226
				.global	__kernel_vector_227
				.global	__kernel_vector_228
				.global	__kernel_vector_229
				.global	__kernel_vector_230
				.global	__kernel_vector_231
				.global	__kernel_vector_232
				.global	__kernel_vector_233
				.global	__kernel_vector_234
				.global	__kernel_vector_235
				.global	__kernel_vector_236
				.global	__kernel_vector_237
				.global	__kernel_vector_238
				.global	__kernel_vector_239
				.global	__kernel_vector_240
				.global	__kernel_vector_241
				.global	__kernel_vector_242
				.global	__kernel_vector_243
				.global	__kernel_vector_244
				.global	__kernel_vector_245
				.global	__kernel_vector_246
				.global	__kernel_vector_247
				.global	__kernel_vector_248
				.global	__kernel_vector_249
				.global	__kernel_vector_250
				.global	__kernel_vector_251
				.global	__kernel_vector_252
				.global	__kernel_vector_253
				.global	__kernel_vector_254
				.global	__kernel_vector_255


				.align	2
__kernel_vector_064:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#64, r4

__kernel_vector_065:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#65, r4

__kernel_vector_066:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#66, r4

__kernel_vector_067:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#67, r4

__kernel_vector_068:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#68, r4

__kernel_vector_069:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#69, r4

__kernel_vector_070:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#70, r4

__kernel_vector_071:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#71, r4

__kernel_vector_072:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#72, r4

__kernel_vector_073:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#73, r4

__kernel_vector_074:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#74, r4

__kernel_vector_075:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#75, r4

__kernel_vector_076:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#76, r4

__kernel_vector_077:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#77, r4

__kernel_vector_078:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#78, r4

__kernel_vector_079:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#79, r4

__kernel_vector_080:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#80, r4

__kernel_vector_081:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#81, r4

__kernel_vector_082:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#82, r4

__kernel_vector_083:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#83, r4

__kernel_vector_084:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#84, r4

__kernel_vector_085:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#85, r4

__kernel_vector_086:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#86, r4

__kernel_vector_087:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#87, r4

__kernel_vector_088:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#88, r4

__kernel_vector_089:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#89, r4

__kernel_vector_090:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#90, r4

__kernel_vector_091:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#91, r4

__kernel_vector_092:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#92, r4

__kernel_vector_093:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#93, r4

__kernel_vector_094:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#94, r4

__kernel_vector_095:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#95, r4

__kernel_vector_096:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#96, r4

__kernel_vector_097:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#97, r4

__kernel_vector_098:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#98, r4

__kernel_vector_099:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#99, r4

__kernel_vector_100:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#100, r4

__kernel_vector_101:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#101, r4

__kernel_vector_102:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#102, r4

__kernel_vector_103:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#103, r4

__kernel_vector_104:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#104, r4

__kernel_vector_105:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#105, r4

__kernel_vector_106:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#106, r4

__kernel_vector_107:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#107, r4

__kernel_vector_108:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#108, r4

__kernel_vector_109:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#109, r4

__kernel_vector_110:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#110, r4

__kernel_vector_111:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#111, r4

__kernel_vector_112:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#112, r4

__kernel_vector_113:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#113, r4

__kernel_vector_114:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#114, r4

__kernel_vector_115:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#115, r4

__kernel_vector_116:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#116, r4

__kernel_vector_117:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#117, r4

__kernel_vector_118:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#118, r4

__kernel_vector_119:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#119, r4

__kernel_vector_120:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#120, r4

__kernel_vector_121:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#121, r4

__kernel_vector_122:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#122, r4

__kernel_vector_123:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#123, r4

__kernel_vector_124:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#124, r4

__kernel_vector_125:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#125, r4

__kernel_vector_126:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#126, r4

__kernel_vector_127:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#127, r4

__kernel_vector_128:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#128, r4

__kernel_vector_129:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#129, r4

__kernel_vector_130:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#130, r4

__kernel_vector_131:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#131, r4

__kernel_vector_132:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#132, r4

__kernel_vector_133:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#133, r4

__kernel_vector_134:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#134, r4

__kernel_vector_135:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#135, r4

__kernel_vector_136:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#136, r4

__kernel_vector_137:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#137, r4

__kernel_vector_138:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#138, r4

__kernel_vector_139:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#139, r4

__kernel_vector_140:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#140, r4

__kernel_vector_141:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#141, r4

__kernel_vector_142:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#142, r4

__kernel_vector_143:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#143, r4

__kernel_vector_144:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#144, r4

__kernel_vector_145:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#145, r4

__kernel_vector_146:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#146, r4

__kernel_vector_147:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#147, r4

__kernel_vector_148:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#148, r4

__kernel_vector_149:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#149, r4

__kernel_vector_150:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#150, r4

__kernel_vector_151:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#151, r4

__kernel_vector_152:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#152, r4

__kernel_vector_153:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#153, r4

__kernel_vector_154:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#154, r4

__kernel_vector_155:
				mov.l	r4, @-r15
				bra		__kernel_int_hdr
				mov		#155, r4

__kernel_vector_156:
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



#define ICTXCB_IMSK		0
#define ICTXCB_INTCNT	2
#define ICTXCB_ISP		4


/************************************************
  割込みハンドラ

  r4をスタックに積んだ後、r4に割り込み番号を
  格納してここに分岐するものとする

  以下、大急ぎで割り込みマスクした後は、メモリ
  アクセス命令が偶数番地に配置されるように頑張る
 ************************************************/
				.align	2
__kernel_int_hdr:
		/* ---- 多重割り込みをマスク */
				mov.l	r0, @-r15					/* r0 退避(割込み元のスタック) */
				stc		sr, r0
				mov.l	r1, @-r15					/* r1 退避(割込み元のスタック) */
				mov		r0, r1						/* sr 保存 */
				or		#0xf0, r0
				ldc		r0, sr						/* 全割り込みマスク */

		/* ---- レジスタ保存(r2-r7,pr) */
				mov.l	r2, @-r15					/* r2 退避(割込み元のスタック) */
				mov		r1, r0						/* srを移動 */
				mov.l	r3, @-r15					/* r3 退避(割込み元のスタック) */
				and		#0xf0, r0					/* 割り込みマスクレベル取り出し */
				mov.l	r5, @-r15					/* r5 退避(割込み元のスタック) */
				mov		r0, r2						/* r2に新しい割込みマスク値格納 */
				mov.l	r6, @-r15					/* r6 退避(割込み元のスタック) */
				extu.b	r4, r4						/* 割込み番号の符号拡張をクリア */
				mov.l	r7, @-r15					/* r7 退避(割込み元のスタック) */
				mov.l	addr_ictxcb, r1
				sts.l	pr, @-r15					/* pr 退避(割込み元のスタック) */

		/* ---- 割り込みマスク値の設定＆多重割り込み判定 */
				mov.b	@(ICTXCB_INTCNT, r1), r0	/* 割込みネストカウンタ取り出し */
				cmp/eq	#0, r0						/* 初回割込み判定 */
				mov.w	@r1, r3						/* r3に古い割込みマスク値格納 */
				add		#1, r0						/* 割込みネストカウンタ加算 */
				mov.w	r2, @r1						/* 新しい割込みマスク値設定 */
				bf/s	multiple_int				/* 多重割込み処理へ分岐 */
				mov.b	r0, @(ICTXCB_INTCNT, r1)	/* 割り込みネスト値を設定(遅延スロット) */

		/* ==== 初回割り込みの処理 */

		/* ---- スタック入れ替え */
				mov		r15, r0						/* 現在のスタックを退避 */
				mov.l	@(ICTXCB_ISP, r1), r15		/* 割込み用スタックを設定 */
				mov.l	r0, @-r15					/* 割込み前のスタックポインタを保存 */
				
		/* ---- 古いマスク値を保存 */
				mov.l	r3, @-r15					/* 古いマスク値を保存 */
				
		/* ---- 割り込み開始処理呼び出し */
				mov.l	addr_sta_inh, r1
				jsr		@r1
				mov.l	r4, @-r15					/* 割込み番号を退避(遅延スロット) */
				
		/* ---- 割り込み実行処理呼び出し */
				mov.l	addr_exe_inh, r1
				jsr		@r1
				mov.l	@r15+, r4					/* 割込み番号を引数とする(遅延スロット) */
				
		/* ---- 古いマスク値を取り出し */
				mov.l	@r15+, r3					/* 古い割込みマスク値を取り出し */
				
		/* ---- スタックの復帰 */
				mov.l	@r15, r15
				
		/* ---- 割込みカウンタのクリア */
				mov.l	addr_ictxcb, r1
				xor		r0, r0
				mov.b	r0, @(ICTXCB_INTCNT, r1)
				
		/* ---- 割込みマスク値復帰 */
				mov.l	@(40, r15), r0		/* 割込み前の sr を取り出し */
				and		#0xf0, r0			/* 割込みマスク値取り出し */
				cmp/eq	r0, r3				/* 古い割込みマスク値と比較 */
				bf/s	return_int			/* 不一致なら既に割込み処理中とみなす */
				mov.w	r3, @r1				/* 割込み前の状態に割込みマスク値を設定(遅延スロット) */
				
		/* ---- 割込み終了処理呼び出し */
				mov.l	addr_end_inh, r2
				jsr		@r2
				nop
				
		/* ---- 復帰時割り込みマスクの設定 */
				mov.l	@(40, r15), r0		/* 割込み前の sr を取り出し */
				or		#0xf0, r0			/* 割込みマスク部分クリアの前処理(一旦ビットを立てる) */
				mov.l	addr_ictxcb, r1
				xor		#0xf0, r0			/* 割込みマスク部分クリア(立てといて反転させる) */
				mov.w	@r1, r1				/* マスク値取得 */
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
				.ALIGN	4
multiple_int:
		/* ---- 割込み実行処理呼び出し */
				mov.l	addr_exe_inh, r1
				jsr		@r1					/* 割り込み番号(r4)を引数とする */
				mov.l	r3, @-r15			/* 古いマスク値を保存 */
				
		/* ---- 割込みカウンタの減算 */
				mov.l	addr_ictxcb, r1
				mov.b	@(ICTXCB_INTCNT, r1), r0
				add		#-1, r0
				mov.b	r0, @(ICTXCB_INTCNT, r1)
				
		/* ---- 割込みマスク値の復帰 */
				mov.l	@r15+, r3			/* 古いマスク値を復帰 */
				bra		return_int
				mov.w	r3, @r1


				.align	2
addr_ictxcb:
				.long	__kernel_ictxcb			/* 割込みコンテキスト制御ブロック */

addr_sta_inh:
				.long	__kernel_sta_inh		/* 割り込み開始処理 */

addr_exe_inh:
				.long	__kernel_exe_inh		/* 割り込み実行処理 */

addr_end_inh:
				.long	__kernel_end_inh		/* 割り込み終了処理 */


				.end


/* end of file */
