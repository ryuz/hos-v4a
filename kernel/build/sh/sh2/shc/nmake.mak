# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for SH2
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = libhosv4a


# %jp{アーキテクチャ定義}
ARCH_PROC = sh\sh2
ARCH_IRC  = simple
ARCH_CC   = shc


# %jp{ディレクトリ定義}
TOP_DIR           = ..\..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake
OBJS_DIR          = objs_$(TARGET)


# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)\cfgrtr\build\msc
CFGRTR     = h4acfg-sh2


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャパス}
INC_PROC_DIR    = $(KERNEL_DIR)\include\arch\proc\$(ARCH_PROC)
INC_IRC_DIR     = $(KERNEL_DIR)\include\arch\irc\$(ARCH_IRC)
SRC_PROC_DIR    = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)
SRC_PROC_CC_DIR = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)\$(ARCH_CC)
SRC_IRC_DIR     = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)
SRC_IRC_CC_DIR  = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)\$(ARCH_CC)


# %jp{パス設定}
INC_DIRS = $(INC_DIRS) $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS = $(SRC_DIRS) $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_CC_DIR)


# %jp{オプションフラグ}
CFLAGS  = $(CFLAGS) -CPu=sh2
AFLAGS  = $(AFLAGS) -CPu=sh2
ARFLAGS = $(ARFLAGS)


!if "$(FAST_VECTOR)" == "Yes"
A_DEFS = $(A_DEFS) _KERNEL_FAST_INTVEC="ON"
!endif



# %jp{オブジェクトファイル定義}
OBJS   = $(OBJS)						\
         $(OBJS_DIR)\val_int.obj		\
         $(OBJS_DIR)\ena_int.obj		\
         $(OBJS_DIR)\dis_int.obj		\
         $(OBJS_DIR)\clr_int.obj		\
         $(OBJS_DIR)\chg_imsk.obj		\
         $(OBJS_DIR)\get_imsk.obj		\
         $(OBJS_DIR)\chg_ilv.obj		\
         $(OBJS_DIR)\get_ilv.obj		\
         $(OBJS_DIR)\kena_int.obj		\
         $(OBJS_DIR)\kdis_int.obj		\
         $(OBJS_DIR)\kwai_int.obj		\
         $(OBJS_DIR)\kcre_ctx.obj		\
         $(OBJS_DIR)\krst_ctx.obj		\
         $(OBJS_DIR)\kswi_ctx.obj		\
         $(OBJS_DIR)\kint_hdr.obj		\
         $(OBJS_DIR)\vect_dmy.obj

!ifndef FAST_VECTOR
OBJS   = $(OBJS)						\
         $(OBJS_DIR)\vect_004.obj		\
         $(OBJS_DIR)\vect_005.obj		\
         $(OBJS_DIR)\vect_006.obj		\
         $(OBJS_DIR)\vect_007.obj		\
         $(OBJS_DIR)\vect_008.obj		\
         $(OBJS_DIR)\vect_009.obj		\
         $(OBJS_DIR)\vect_010.obj		\
         $(OBJS_DIR)\vect_011.obj		\
         $(OBJS_DIR)\vect_012.obj		\
         $(OBJS_DIR)\vect_013.obj		\
         $(OBJS_DIR)\vect_014.obj		\
         $(OBJS_DIR)\vect_015.obj		\
         $(OBJS_DIR)\vect_016.obj		\
         $(OBJS_DIR)\vect_017.obj		\
         $(OBJS_DIR)\vect_018.obj		\
         $(OBJS_DIR)\vect_019.obj		\
         $(OBJS_DIR)\vect_020.obj		\
         $(OBJS_DIR)\vect_021.obj		\
         $(OBJS_DIR)\vect_022.obj		\
         $(OBJS_DIR)\vect_023.obj		\
         $(OBJS_DIR)\vect_024.obj		\
         $(OBJS_DIR)\vect_025.obj		\
         $(OBJS_DIR)\vect_026.obj		\
         $(OBJS_DIR)\vect_027.obj		\
         $(OBJS_DIR)\vect_028.obj		\
         $(OBJS_DIR)\vect_029.obj		\
         $(OBJS_DIR)\vect_030.obj		\
         $(OBJS_DIR)\vect_031.obj		\
         $(OBJS_DIR)\vect_032.obj		\
         $(OBJS_DIR)\vect_033.obj		\
         $(OBJS_DIR)\vect_034.obj		\
         $(OBJS_DIR)\vect_035.obj		\
         $(OBJS_DIR)\vect_036.obj		\
         $(OBJS_DIR)\vect_037.obj		\
         $(OBJS_DIR)\vect_038.obj		\
         $(OBJS_DIR)\vect_039.obj		\
         $(OBJS_DIR)\vect_040.obj		\
         $(OBJS_DIR)\vect_041.obj		\
         $(OBJS_DIR)\vect_042.obj		\
         $(OBJS_DIR)\vect_043.obj		\
         $(OBJS_DIR)\vect_044.obj		\
         $(OBJS_DIR)\vect_045.obj		\
         $(OBJS_DIR)\vect_046.obj		\
         $(OBJS_DIR)\vect_047.obj		\
         $(OBJS_DIR)\vect_048.obj		\
         $(OBJS_DIR)\vect_049.obj		\
         $(OBJS_DIR)\vect_050.obj		\
         $(OBJS_DIR)\vect_051.obj		\
         $(OBJS_DIR)\vect_052.obj		\
         $(OBJS_DIR)\vect_053.obj		\
         $(OBJS_DIR)\vect_054.obj		\
         $(OBJS_DIR)\vect_055.obj		\
         $(OBJS_DIR)\vect_056.obj		\
         $(OBJS_DIR)\vect_057.obj		\
         $(OBJS_DIR)\vect_058.obj		\
         $(OBJS_DIR)\vect_059.obj		\
         $(OBJS_DIR)\vect_060.obj		\
         $(OBJS_DIR)\vect_061.obj		\
         $(OBJS_DIR)\vect_062.obj		\
         $(OBJS_DIR)\vect_063.obj		\
         $(OBJS_DIR)\vect_064.obj		\
         $(OBJS_DIR)\vect_065.obj		\
         $(OBJS_DIR)\vect_066.obj		\
         $(OBJS_DIR)\vect_067.obj		\
         $(OBJS_DIR)\vect_068.obj		\
         $(OBJS_DIR)\vect_069.obj		\
         $(OBJS_DIR)\vect_070.obj		\
         $(OBJS_DIR)\vect_071.obj		\
         $(OBJS_DIR)\vect_072.obj		\
         $(OBJS_DIR)\vect_073.obj		\
         $(OBJS_DIR)\vect_074.obj		\
         $(OBJS_DIR)\vect_075.obj		\
         $(OBJS_DIR)\vect_076.obj		\
         $(OBJS_DIR)\vect_077.obj		\
         $(OBJS_DIR)\vect_078.obj		\
         $(OBJS_DIR)\vect_079.obj		\
         $(OBJS_DIR)\vect_080.obj		\
         $(OBJS_DIR)\vect_081.obj		\
         $(OBJS_DIR)\vect_082.obj		\
         $(OBJS_DIR)\vect_083.obj		\
         $(OBJS_DIR)\vect_084.obj		\
         $(OBJS_DIR)\vect_085.obj		\
         $(OBJS_DIR)\vect_086.obj		\
         $(OBJS_DIR)\vect_087.obj		\
         $(OBJS_DIR)\vect_088.obj		\
         $(OBJS_DIR)\vect_089.obj		\
         $(OBJS_DIR)\vect_090.obj		\
         $(OBJS_DIR)\vect_091.obj		\
         $(OBJS_DIR)\vect_092.obj		\
         $(OBJS_DIR)\vect_093.obj		\
         $(OBJS_DIR)\vect_094.obj		\
         $(OBJS_DIR)\vect_095.obj		\
         $(OBJS_DIR)\vect_096.obj		\
         $(OBJS_DIR)\vect_097.obj		\
         $(OBJS_DIR)\vect_098.obj		\
         $(OBJS_DIR)\vect_099.obj		\
         $(OBJS_DIR)\vect_100.obj		\
         $(OBJS_DIR)\vect_101.obj		\
         $(OBJS_DIR)\vect_102.obj		\
         $(OBJS_DIR)\vect_103.obj		\
         $(OBJS_DIR)\vect_104.obj		\
         $(OBJS_DIR)\vect_105.obj		\
         $(OBJS_DIR)\vect_106.obj		\
         $(OBJS_DIR)\vect_107.obj		\
         $(OBJS_DIR)\vect_108.obj		\
         $(OBJS_DIR)\vect_109.obj		\
         $(OBJS_DIR)\vect_110.obj		\
         $(OBJS_DIR)\vect_111.obj		\
         $(OBJS_DIR)\vect_112.obj		\
         $(OBJS_DIR)\vect_113.obj		\
         $(OBJS_DIR)\vect_114.obj		\
         $(OBJS_DIR)\vect_115.obj		\
         $(OBJS_DIR)\vect_116.obj		\
         $(OBJS_DIR)\vect_117.obj		\
         $(OBJS_DIR)\vect_118.obj		\
         $(OBJS_DIR)\vect_119.obj		\
         $(OBJS_DIR)\vect_120.obj		\
         $(OBJS_DIR)\vect_121.obj		\
         $(OBJS_DIR)\vect_122.obj		\
         $(OBJS_DIR)\vect_123.obj		\
         $(OBJS_DIR)\vect_124.obj		\
         $(OBJS_DIR)\vect_125.obj		\
         $(OBJS_DIR)\vect_126.obj		\
         $(OBJS_DIR)\vect_127.obj		\
         $(OBJS_DIR)\vect_128.obj		\
         $(OBJS_DIR)\vect_129.obj		\
         $(OBJS_DIR)\vect_130.obj		\
         $(OBJS_DIR)\vect_131.obj		\
         $(OBJS_DIR)\vect_132.obj		\
         $(OBJS_DIR)\vect_133.obj		\
         $(OBJS_DIR)\vect_134.obj		\
         $(OBJS_DIR)\vect_135.obj		\
         $(OBJS_DIR)\vect_136.obj		\
         $(OBJS_DIR)\vect_137.obj		\
         $(OBJS_DIR)\vect_138.obj		\
         $(OBJS_DIR)\vect_139.obj		\
         $(OBJS_DIR)\vect_140.obj		\
         $(OBJS_DIR)\vect_141.obj		\
         $(OBJS_DIR)\vect_142.obj		\
         $(OBJS_DIR)\vect_143.obj		\
         $(OBJS_DIR)\vect_144.obj		\
         $(OBJS_DIR)\vect_145.obj		\
         $(OBJS_DIR)\vect_146.obj		\
         $(OBJS_DIR)\vect_147.obj		\
         $(OBJS_DIR)\vect_148.obj		\
         $(OBJS_DIR)\vect_149.obj		\
         $(OBJS_DIR)\vect_150.obj		\
         $(OBJS_DIR)\vect_151.obj		\
         $(OBJS_DIR)\vect_152.obj		\
         $(OBJS_DIR)\vect_153.obj		\
         $(OBJS_DIR)\vect_154.obj		\
         $(OBJS_DIR)\vect_155.obj		\
         $(OBJS_DIR)\vect_156.obj		\
         $(OBJS_DIR)\vect_157.obj		\
         $(OBJS_DIR)\vect_158.obj		\
         $(OBJS_DIR)\vect_159.obj		\
         $(OBJS_DIR)\vect_160.obj		\
         $(OBJS_DIR)\vect_161.obj		\
         $(OBJS_DIR)\vect_162.obj		\
         $(OBJS_DIR)\vect_163.obj		\
         $(OBJS_DIR)\vect_164.obj		\
         $(OBJS_DIR)\vect_165.obj		\
         $(OBJS_DIR)\vect_166.obj		\
         $(OBJS_DIR)\vect_167.obj		\
         $(OBJS_DIR)\vect_168.obj		\
         $(OBJS_DIR)\vect_169.obj		\
         $(OBJS_DIR)\vect_170.obj		\
         $(OBJS_DIR)\vect_171.obj		\
         $(OBJS_DIR)\vect_172.obj		\
         $(OBJS_DIR)\vect_173.obj		\
         $(OBJS_DIR)\vect_174.obj		\
         $(OBJS_DIR)\vect_175.obj		\
         $(OBJS_DIR)\vect_176.obj		\
         $(OBJS_DIR)\vect_177.obj		\
         $(OBJS_DIR)\vect_178.obj		\
         $(OBJS_DIR)\vect_179.obj		\
         $(OBJS_DIR)\vect_180.obj		\
         $(OBJS_DIR)\vect_181.obj		\
         $(OBJS_DIR)\vect_182.obj		\
         $(OBJS_DIR)\vect_183.obj		\
         $(OBJS_DIR)\vect_184.obj		\
         $(OBJS_DIR)\vect_185.obj		\
         $(OBJS_DIR)\vect_186.obj		\
         $(OBJS_DIR)\vect_187.obj		\
         $(OBJS_DIR)\vect_188.obj		\
         $(OBJS_DIR)\vect_189.obj		\
         $(OBJS_DIR)\vect_190.obj		\
         $(OBJS_DIR)\vect_191.obj		\
         $(OBJS_DIR)\vect_192.obj		\
         $(OBJS_DIR)\vect_193.obj		\
         $(OBJS_DIR)\vect_194.obj		\
         $(OBJS_DIR)\vect_195.obj		\
         $(OBJS_DIR)\vect_196.obj		\
         $(OBJS_DIR)\vect_197.obj		\
         $(OBJS_DIR)\vect_198.obj		\
         $(OBJS_DIR)\vect_199.obj		\
         $(OBJS_DIR)\vect_200.obj		\
         $(OBJS_DIR)\vect_201.obj		\
         $(OBJS_DIR)\vect_202.obj		\
         $(OBJS_DIR)\vect_203.obj		\
         $(OBJS_DIR)\vect_204.obj		\
         $(OBJS_DIR)\vect_205.obj		\
         $(OBJS_DIR)\vect_206.obj		\
         $(OBJS_DIR)\vect_207.obj		\
         $(OBJS_DIR)\vect_208.obj		\
         $(OBJS_DIR)\vect_209.obj		\
         $(OBJS_DIR)\vect_210.obj		\
         $(OBJS_DIR)\vect_211.obj		\
         $(OBJS_DIR)\vect_212.obj		\
         $(OBJS_DIR)\vect_213.obj		\
         $(OBJS_DIR)\vect_214.obj		\
         $(OBJS_DIR)\vect_215.obj		\
         $(OBJS_DIR)\vect_216.obj		\
         $(OBJS_DIR)\vect_217.obj		\
         $(OBJS_DIR)\vect_218.obj		\
         $(OBJS_DIR)\vect_219.obj		\
         $(OBJS_DIR)\vect_220.obj		\
         $(OBJS_DIR)\vect_221.obj		\
         $(OBJS_DIR)\vect_222.obj		\
         $(OBJS_DIR)\vect_223.obj		\
         $(OBJS_DIR)\vect_224.obj		\
         $(OBJS_DIR)\vect_225.obj		\
         $(OBJS_DIR)\vect_226.obj		\
         $(OBJS_DIR)\vect_227.obj		\
         $(OBJS_DIR)\vect_228.obj		\
         $(OBJS_DIR)\vect_229.obj		\
         $(OBJS_DIR)\vect_230.obj		\
         $(OBJS_DIR)\vect_231.obj		\
         $(OBJS_DIR)\vect_232.obj		\
         $(OBJS_DIR)\vect_233.obj		\
         $(OBJS_DIR)\vect_234.obj		\
         $(OBJS_DIR)\vect_235.obj		\
         $(OBJS_DIR)\vect_236.obj		\
         $(OBJS_DIR)\vect_237.obj		\
         $(OBJS_DIR)\vect_238.obj		\
         $(OBJS_DIR)\vect_239.obj		\
         $(OBJS_DIR)\vect_240.obj		\
         $(OBJS_DIR)\vect_241.obj		\
         $(OBJS_DIR)\vect_242.obj		\
         $(OBJS_DIR)\vect_243.obj		\
         $(OBJS_DIR)\vect_244.obj		\
         $(OBJS_DIR)\vect_245.obj		\
         $(OBJS_DIR)\vect_246.obj		\
         $(OBJS_DIR)\vect_247.obj		\
         $(OBJS_DIR)\vect_248.obj		\
         $(OBJS_DIR)\vect_249.obj		\
         $(OBJS_DIR)\vect_250.obj		\
         $(OBJS_DIR)\vect_251.obj		\
         $(OBJS_DIR)\vect_252.obj		\
         $(OBJS_DIR)\vect_253.obj		\
         $(OBJS_DIR)\vect_254.obj		\
         $(OBJS_DIR)\vect_255.obj
!endif



# %jp{コンパイラ依存定義}%en{definitions of compiler dependence}
!include $(KERNEL_MAKINC_DIR)/shc_d.inc


# %jp{カーネル共通ソースの追加}%en{definitions of kernel source files}
!include $(KERNEL_MAKINC_DIR)\knlsrc.inc



# %jp{ALL}%en{all}
all: makelib_all
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) /F nmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)


# %jp{クリーン}
clean: makelib_clean
	-$(CMD_RM) *.lst
	-$(CMD_RM) $(OBJS_DIR)\*.*
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) /F nmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(CMD_CD) $(MAKEDIR)



# %jp{ライブラリ生成用設定読込み}%en{rules of library}
!include $(KERNEL_MAKINC_DIR)/makelib.inc


# %jp{コンパイラ依存ルール}%en{rules of compiler dependence}
!include $(KERNEL_MAKINC_DIR)/shc_r.inc


# %jp{カーネル依存関係読込み}%en{dependence}
!include $(KERNEL_MAKINC_DIR)/knldep.inc


# %jp{コピー}%en{source files copy}

$(OBJS_DIR)\val_imsk.c : $(SRC_IRC_DIR)\val_imsk.c
	$(CMD_CP) $(SRC_IRC_DIR)\val_imsk.c $(OBJS_DIR)\

$(OBJS_DIR)\chg_imsk.c : $(SRC_IRC_DIR)\chg_imsk.c
	$(CMD_CP) $(SRC_IRC_DIR)\chg_imsk.c $(OBJS_DIR)\

$(OBJS_DIR)\get_imsk.c : $(SRC_IRC_DIR)\get_imsk.c
	$(CMD_CP) $(SRC_IRC_DIR)\get_imsk.c $(OBJS_DIR)\

$(OBJS_DIR)\ena_int.c : $(SRC_IRC_DIR)\ena_int.c
	$(CMD_CP) $(SRC_IRC_DIR)\ena_int.c $(OBJS_DIR)\

$(OBJS_DIR)\dis_int.c : $(SRC_IRC_DIR)\dis_int.c
	$(CMD_CP) $(SRC_IRC_DIR)\dis_int.c $(OBJS_DIR)\

$(OBJS_DIR)\clr_int.c : $(SRC_IRC_DIR)\clr_int.c
	$(CMD_CP) $(SRC_IRC_DIR)\clr_int.c $(OBJS_DIR)\

$(OBJS_DIR)\chg_ilv.c : $(SRC_IRC_DIR)\chg_ilv.c
	$(CMD_CP) $(SRC_IRC_DIR)\chg_ilv.c $(OBJS_DIR)\

$(OBJS_DIR)\get_ilv.c : $(SRC_IRC_DIR)\get_ilv.c
	$(CMD_CP) $(SRC_IRC_DIR)\get_ilv.c $(OBJS_DIR)\

$(OBJS_DIR)\val_int.c: 
	$(CMD_CP) $(SRC_PROC_DIR)\val_int.c $(OBJS_DIR)\

$(OBJS_DIR)\kena_int.src : $(SRC_PROC_CC_DIR)\kena_int.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\kena_int.src $(OBJS_DIR)\

$(OBJS_DIR)\kdis_int.src : $(SRC_PROC_CC_DIR)\kdis_int.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\kdis_int.src $(OBJS_DIR)\

$(OBJS_DIR)\kwai_int.src : $(SRC_PROC_CC_DIR)\kwai_int.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\kwai_int.src $(OBJS_DIR)\

$(OBJS_DIR)\kcre_ctx.src : $(SRC_PROC_CC_DIR)\kcre_ctx.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\kcre_ctx.src $(OBJS_DIR)\

$(OBJS_DIR)\krst_ctx.src : $(SRC_PROC_CC_DIR)\krst_ctx.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\krst_ctx.src $(OBJS_DIR)\

$(OBJS_DIR)\kswi_ctx.src : $(SRC_PROC_CC_DIR)\kswi_ctx.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\kswi_ctx.src $(OBJS_DIR)\

$(OBJS_DIR)\kint_hdr.src : $(SRC_PROC_CC_DIR)\kint_hdr.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\kint_hdr.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_dmy.src : $(SRC_PROC_CC_DIR)\vect_dmy.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_dmy.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_004.src: $(SRC_PROC_CC_DIR)\vect_004.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_004.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_005.src: $(SRC_PROC_CC_DIR)\vect_005.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_005.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_006.src: $(SRC_PROC_CC_DIR)\vect_006.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_006.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_007.src: $(SRC_PROC_CC_DIR)\vect_007.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_007.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_008.src: $(SRC_PROC_CC_DIR)\vect_008.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_008.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_009.src: $(SRC_PROC_CC_DIR)\vect_009.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_009.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_010.src: $(SRC_PROC_CC_DIR)\vect_010.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_010.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_011.src: $(SRC_PROC_CC_DIR)\vect_011.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_011.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_012.src: $(SRC_PROC_CC_DIR)\vect_012.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_012.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_013.src: $(SRC_PROC_CC_DIR)\vect_013.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_013.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_014.src: $(SRC_PROC_CC_DIR)\vect_014.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_014.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_015.src: $(SRC_PROC_CC_DIR)\vect_015.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_015.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_016.src: $(SRC_PROC_CC_DIR)\vect_016.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_016.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_017.src: $(SRC_PROC_CC_DIR)\vect_017.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_017.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_018.src: $(SRC_PROC_CC_DIR)\vect_018.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_018.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_019.src: $(SRC_PROC_CC_DIR)\vect_019.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_019.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_020.src: $(SRC_PROC_CC_DIR)\vect_020.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_020.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_021.src: $(SRC_PROC_CC_DIR)\vect_021.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_021.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_022.src: $(SRC_PROC_CC_DIR)\vect_022.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_022.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_023.src: $(SRC_PROC_CC_DIR)\vect_023.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_023.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_024.src: $(SRC_PROC_CC_DIR)\vect_024.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_024.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_025.src: $(SRC_PROC_CC_DIR)\vect_025.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_025.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_026.src: $(SRC_PROC_CC_DIR)\vect_026.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_026.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_027.src: $(SRC_PROC_CC_DIR)\vect_027.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_027.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_028.src: $(SRC_PROC_CC_DIR)\vect_028.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_028.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_029.src: $(SRC_PROC_CC_DIR)\vect_029.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_029.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_030.src: $(SRC_PROC_CC_DIR)\vect_030.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_030.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_031.src: $(SRC_PROC_CC_DIR)\vect_031.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_031.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_032.src: $(SRC_PROC_CC_DIR)\vect_032.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_032.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_033.src: $(SRC_PROC_CC_DIR)\vect_033.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_033.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_034.src: $(SRC_PROC_CC_DIR)\vect_034.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_034.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_035.src: $(SRC_PROC_CC_DIR)\vect_035.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_035.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_036.src: $(SRC_PROC_CC_DIR)\vect_036.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_036.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_037.src: $(SRC_PROC_CC_DIR)\vect_037.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_037.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_038.src: $(SRC_PROC_CC_DIR)\vect_038.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_038.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_039.src: $(SRC_PROC_CC_DIR)\vect_039.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_039.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_040.src: $(SRC_PROC_CC_DIR)\vect_040.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_040.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_041.src: $(SRC_PROC_CC_DIR)\vect_041.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_041.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_042.src: $(SRC_PROC_CC_DIR)\vect_042.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_042.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_043.src: $(SRC_PROC_CC_DIR)\vect_043.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_043.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_044.src: $(SRC_PROC_CC_DIR)\vect_044.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_044.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_045.src: $(SRC_PROC_CC_DIR)\vect_045.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_045.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_046.src: $(SRC_PROC_CC_DIR)\vect_046.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_046.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_047.src: $(SRC_PROC_CC_DIR)\vect_047.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_047.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_048.src: $(SRC_PROC_CC_DIR)\vect_048.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_048.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_049.src: $(SRC_PROC_CC_DIR)\vect_049.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_049.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_050.src: $(SRC_PROC_CC_DIR)\vect_050.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_050.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_051.src: $(SRC_PROC_CC_DIR)\vect_051.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_051.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_052.src: $(SRC_PROC_CC_DIR)\vect_052.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_052.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_053.src: $(SRC_PROC_CC_DIR)\vect_053.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_053.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_054.src: $(SRC_PROC_CC_DIR)\vect_054.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_054.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_055.src: $(SRC_PROC_CC_DIR)\vect_055.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_055.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_056.src: $(SRC_PROC_CC_DIR)\vect_056.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_056.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_057.src: $(SRC_PROC_CC_DIR)\vect_057.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_057.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_058.src: $(SRC_PROC_CC_DIR)\vect_058.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_058.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_059.src: $(SRC_PROC_CC_DIR)\vect_059.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_059.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_060.src: $(SRC_PROC_CC_DIR)\vect_060.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_060.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_061.src: $(SRC_PROC_CC_DIR)\vect_061.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_061.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_062.src: $(SRC_PROC_CC_DIR)\vect_062.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_062.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_063.src: $(SRC_PROC_CC_DIR)\vect_063.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_063.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_064.src: $(SRC_PROC_CC_DIR)\vect_064.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_064.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_065.src: $(SRC_PROC_CC_DIR)\vect_065.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_065.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_066.src: $(SRC_PROC_CC_DIR)\vect_066.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_066.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_067.src: $(SRC_PROC_CC_DIR)\vect_067.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_067.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_068.src: $(SRC_PROC_CC_DIR)\vect_068.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_068.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_069.src: $(SRC_PROC_CC_DIR)\vect_069.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_069.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_070.src: $(SRC_PROC_CC_DIR)\vect_070.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_070.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_071.src: $(SRC_PROC_CC_DIR)\vect_071.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_071.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_072.src: $(SRC_PROC_CC_DIR)\vect_072.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_072.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_073.src: $(SRC_PROC_CC_DIR)\vect_073.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_073.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_074.src: $(SRC_PROC_CC_DIR)\vect_074.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_074.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_075.src: $(SRC_PROC_CC_DIR)\vect_075.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_075.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_076.src: $(SRC_PROC_CC_DIR)\vect_076.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_076.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_077.src: $(SRC_PROC_CC_DIR)\vect_077.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_077.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_078.src: $(SRC_PROC_CC_DIR)\vect_078.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_078.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_079.src: $(SRC_PROC_CC_DIR)\vect_079.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_079.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_080.src: $(SRC_PROC_CC_DIR)\vect_080.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_080.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_081.src: $(SRC_PROC_CC_DIR)\vect_081.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_081.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_082.src: $(SRC_PROC_CC_DIR)\vect_082.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_082.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_083.src: $(SRC_PROC_CC_DIR)\vect_083.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_083.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_084.src: $(SRC_PROC_CC_DIR)\vect_084.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_084.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_085.src: $(SRC_PROC_CC_DIR)\vect_085.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_085.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_086.src: $(SRC_PROC_CC_DIR)\vect_086.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_086.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_087.src: $(SRC_PROC_CC_DIR)\vect_087.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_087.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_088.src: $(SRC_PROC_CC_DIR)\vect_088.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_088.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_089.src: $(SRC_PROC_CC_DIR)\vect_089.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_089.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_090.src: $(SRC_PROC_CC_DIR)\vect_090.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_090.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_091.src: $(SRC_PROC_CC_DIR)\vect_091.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_091.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_092.src: $(SRC_PROC_CC_DIR)\vect_092.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_092.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_093.src: $(SRC_PROC_CC_DIR)\vect_093.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_093.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_094.src: $(SRC_PROC_CC_DIR)\vect_094.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_094.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_095.src: $(SRC_PROC_CC_DIR)\vect_095.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_095.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_096.src: $(SRC_PROC_CC_DIR)\vect_096.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_096.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_097.src: $(SRC_PROC_CC_DIR)\vect_097.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_097.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_098.src: $(SRC_PROC_CC_DIR)\vect_098.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_098.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_099.src: $(SRC_PROC_CC_DIR)\vect_099.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_099.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_100.src: $(SRC_PROC_CC_DIR)\vect_100.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_100.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_101.src: $(SRC_PROC_CC_DIR)\vect_101.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_101.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_102.src: $(SRC_PROC_CC_DIR)\vect_102.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_102.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_103.src: $(SRC_PROC_CC_DIR)\vect_103.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_103.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_104.src: $(SRC_PROC_CC_DIR)\vect_104.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_104.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_105.src: $(SRC_PROC_CC_DIR)\vect_105.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_105.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_106.src: $(SRC_PROC_CC_DIR)\vect_106.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_106.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_107.src: $(SRC_PROC_CC_DIR)\vect_107.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_107.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_108.src: $(SRC_PROC_CC_DIR)\vect_108.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_108.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_109.src: $(SRC_PROC_CC_DIR)\vect_109.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_109.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_110.src: $(SRC_PROC_CC_DIR)\vect_110.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_110.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_111.src: $(SRC_PROC_CC_DIR)\vect_111.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_111.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_112.src: $(SRC_PROC_CC_DIR)\vect_112.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_112.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_113.src: $(SRC_PROC_CC_DIR)\vect_113.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_113.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_114.src: $(SRC_PROC_CC_DIR)\vect_114.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_114.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_115.src: $(SRC_PROC_CC_DIR)\vect_115.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_115.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_116.src: $(SRC_PROC_CC_DIR)\vect_116.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_116.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_117.src: $(SRC_PROC_CC_DIR)\vect_117.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_117.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_118.src: $(SRC_PROC_CC_DIR)\vect_118.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_118.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_119.src: $(SRC_PROC_CC_DIR)\vect_119.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_119.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_120.src: $(SRC_PROC_CC_DIR)\vect_120.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_120.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_121.src: $(SRC_PROC_CC_DIR)\vect_121.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_121.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_122.src: $(SRC_PROC_CC_DIR)\vect_122.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_122.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_123.src: $(SRC_PROC_CC_DIR)\vect_123.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_123.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_124.src: $(SRC_PROC_CC_DIR)\vect_124.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_124.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_125.src: $(SRC_PROC_CC_DIR)\vect_125.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_125.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_126.src: $(SRC_PROC_CC_DIR)\vect_126.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_126.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_127.src: $(SRC_PROC_CC_DIR)\vect_127.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_127.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_128.src: $(SRC_PROC_CC_DIR)\vect_128.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_128.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_129.src: $(SRC_PROC_CC_DIR)\vect_129.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_129.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_130.src: $(SRC_PROC_CC_DIR)\vect_130.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_130.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_131.src: $(SRC_PROC_CC_DIR)\vect_131.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_131.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_132.src: $(SRC_PROC_CC_DIR)\vect_132.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_132.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_133.src: $(SRC_PROC_CC_DIR)\vect_133.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_133.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_134.src: $(SRC_PROC_CC_DIR)\vect_134.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_134.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_135.src: $(SRC_PROC_CC_DIR)\vect_135.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_135.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_136.src: $(SRC_PROC_CC_DIR)\vect_136.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_136.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_137.src: $(SRC_PROC_CC_DIR)\vect_137.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_137.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_138.src: $(SRC_PROC_CC_DIR)\vect_138.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_138.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_139.src: $(SRC_PROC_CC_DIR)\vect_139.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_139.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_140.src: $(SRC_PROC_CC_DIR)\vect_140.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_140.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_141.src: $(SRC_PROC_CC_DIR)\vect_141.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_141.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_142.src: $(SRC_PROC_CC_DIR)\vect_142.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_142.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_143.src: $(SRC_PROC_CC_DIR)\vect_143.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_143.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_144.src: $(SRC_PROC_CC_DIR)\vect_144.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_144.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_145.src: $(SRC_PROC_CC_DIR)\vect_145.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_145.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_146.src: $(SRC_PROC_CC_DIR)\vect_146.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_146.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_147.src: $(SRC_PROC_CC_DIR)\vect_147.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_147.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_148.src: $(SRC_PROC_CC_DIR)\vect_148.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_148.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_149.src: $(SRC_PROC_CC_DIR)\vect_149.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_149.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_150.src: $(SRC_PROC_CC_DIR)\vect_150.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_150.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_151.src: $(SRC_PROC_CC_DIR)\vect_151.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_151.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_152.src: $(SRC_PROC_CC_DIR)\vect_152.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_152.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_153.src: $(SRC_PROC_CC_DIR)\vect_153.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_153.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_154.src: $(SRC_PROC_CC_DIR)\vect_154.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_154.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_155.src: $(SRC_PROC_CC_DIR)\vect_155.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_155.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_156.src: $(SRC_PROC_CC_DIR)\vect_156.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_156.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_157.src: $(SRC_PROC_CC_DIR)\vect_157.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_157.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_158.src: $(SRC_PROC_CC_DIR)\vect_158.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_158.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_159.src: $(SRC_PROC_CC_DIR)\vect_159.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_159.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_160.src: $(SRC_PROC_CC_DIR)\vect_160.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_160.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_161.src: $(SRC_PROC_CC_DIR)\vect_161.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_161.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_162.src: $(SRC_PROC_CC_DIR)\vect_162.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_162.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_163.src: $(SRC_PROC_CC_DIR)\vect_163.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_163.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_164.src: $(SRC_PROC_CC_DIR)\vect_164.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_164.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_165.src: $(SRC_PROC_CC_DIR)\vect_165.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_165.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_166.src: $(SRC_PROC_CC_DIR)\vect_166.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_166.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_167.src: $(SRC_PROC_CC_DIR)\vect_167.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_167.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_168.src: $(SRC_PROC_CC_DIR)\vect_168.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_168.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_169.src: $(SRC_PROC_CC_DIR)\vect_169.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_169.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_170.src: $(SRC_PROC_CC_DIR)\vect_170.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_170.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_171.src: $(SRC_PROC_CC_DIR)\vect_171.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_171.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_172.src: $(SRC_PROC_CC_DIR)\vect_172.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_172.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_173.src: $(SRC_PROC_CC_DIR)\vect_173.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_173.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_174.src: $(SRC_PROC_CC_DIR)\vect_174.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_174.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_175.src: $(SRC_PROC_CC_DIR)\vect_175.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_175.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_176.src: $(SRC_PROC_CC_DIR)\vect_176.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_176.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_177.src: $(SRC_PROC_CC_DIR)\vect_177.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_177.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_178.src: $(SRC_PROC_CC_DIR)\vect_178.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_178.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_179.src: $(SRC_PROC_CC_DIR)\vect_179.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_179.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_180.src: $(SRC_PROC_CC_DIR)\vect_180.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_180.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_181.src: $(SRC_PROC_CC_DIR)\vect_181.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_181.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_182.src: $(SRC_PROC_CC_DIR)\vect_182.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_182.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_183.src: $(SRC_PROC_CC_DIR)\vect_183.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_183.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_184.src: $(SRC_PROC_CC_DIR)\vect_184.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_184.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_185.src: $(SRC_PROC_CC_DIR)\vect_185.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_185.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_186.src: $(SRC_PROC_CC_DIR)\vect_186.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_186.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_187.src: $(SRC_PROC_CC_DIR)\vect_187.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_187.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_188.src: $(SRC_PROC_CC_DIR)\vect_188.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_188.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_189.src: $(SRC_PROC_CC_DIR)\vect_189.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_189.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_190.src: $(SRC_PROC_CC_DIR)\vect_190.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_190.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_191.src: $(SRC_PROC_CC_DIR)\vect_191.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_191.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_192.src: $(SRC_PROC_CC_DIR)\vect_192.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_192.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_193.src: $(SRC_PROC_CC_DIR)\vect_193.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_193.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_194.src: $(SRC_PROC_CC_DIR)\vect_194.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_194.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_195.src: $(SRC_PROC_CC_DIR)\vect_195.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_195.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_196.src: $(SRC_PROC_CC_DIR)\vect_196.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_196.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_197.src: $(SRC_PROC_CC_DIR)\vect_197.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_197.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_198.src: $(SRC_PROC_CC_DIR)\vect_198.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_198.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_199.src: $(SRC_PROC_CC_DIR)\vect_199.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_199.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_200.src: $(SRC_PROC_CC_DIR)\vect_200.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_200.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_201.src: $(SRC_PROC_CC_DIR)\vect_201.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_201.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_202.src: $(SRC_PROC_CC_DIR)\vect_202.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_202.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_203.src: $(SRC_PROC_CC_DIR)\vect_203.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_203.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_204.src: $(SRC_PROC_CC_DIR)\vect_204.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_204.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_205.src: $(SRC_PROC_CC_DIR)\vect_205.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_205.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_206.src: $(SRC_PROC_CC_DIR)\vect_206.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_206.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_207.src: $(SRC_PROC_CC_DIR)\vect_207.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_207.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_208.src: $(SRC_PROC_CC_DIR)\vect_208.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_208.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_209.src: $(SRC_PROC_CC_DIR)\vect_209.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_209.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_210.src: $(SRC_PROC_CC_DIR)\vect_210.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_210.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_211.src: $(SRC_PROC_CC_DIR)\vect_211.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_211.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_212.src: $(SRC_PROC_CC_DIR)\vect_212.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_212.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_213.src: $(SRC_PROC_CC_DIR)\vect_213.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_213.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_214.src: $(SRC_PROC_CC_DIR)\vect_214.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_214.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_215.src: $(SRC_PROC_CC_DIR)\vect_215.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_215.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_216.src: $(SRC_PROC_CC_DIR)\vect_216.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_216.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_217.src: $(SRC_PROC_CC_DIR)\vect_217.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_217.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_218.src: $(SRC_PROC_CC_DIR)\vect_218.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_218.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_219.src: $(SRC_PROC_CC_DIR)\vect_219.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_219.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_220.src: $(SRC_PROC_CC_DIR)\vect_220.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_220.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_221.src: $(SRC_PROC_CC_DIR)\vect_221.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_221.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_222.src: $(SRC_PROC_CC_DIR)\vect_222.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_222.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_223.src: $(SRC_PROC_CC_DIR)\vect_223.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_223.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_224.src: $(SRC_PROC_CC_DIR)\vect_224.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_224.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_225.src: $(SRC_PROC_CC_DIR)\vect_225.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_225.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_226.src: $(SRC_PROC_CC_DIR)\vect_226.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_226.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_227.src: $(SRC_PROC_CC_DIR)\vect_227.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_227.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_228.src: $(SRC_PROC_CC_DIR)\vect_228.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_228.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_229.src: $(SRC_PROC_CC_DIR)\vect_229.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_229.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_230.src: $(SRC_PROC_CC_DIR)\vect_230.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_230.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_231.src: $(SRC_PROC_CC_DIR)\vect_231.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_231.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_232.src: $(SRC_PROC_CC_DIR)\vect_232.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_232.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_233.src: $(SRC_PROC_CC_DIR)\vect_233.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_233.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_234.src: $(SRC_PROC_CC_DIR)\vect_234.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_234.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_235.src: $(SRC_PROC_CC_DIR)\vect_235.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_235.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_236.src: $(SRC_PROC_CC_DIR)\vect_236.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_236.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_237.src: $(SRC_PROC_CC_DIR)\vect_237.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_237.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_238.src: $(SRC_PROC_CC_DIR)\vect_238.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_238.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_239.src: $(SRC_PROC_CC_DIR)\vect_239.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_239.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_240.src: $(SRC_PROC_CC_DIR)\vect_240.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_240.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_241.src: $(SRC_PROC_CC_DIR)\vect_241.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_241.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_242.src: $(SRC_PROC_CC_DIR)\vect_242.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_242.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_243.src: $(SRC_PROC_CC_DIR)\vect_243.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_243.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_244.src: $(SRC_PROC_CC_DIR)\vect_244.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_244.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_245.src: $(SRC_PROC_CC_DIR)\vect_245.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_245.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_246.src: $(SRC_PROC_CC_DIR)\vect_246.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_246.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_247.src: $(SRC_PROC_CC_DIR)\vect_247.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_247.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_248.src: $(SRC_PROC_CC_DIR)\vect_248.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_248.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_249.src: $(SRC_PROC_CC_DIR)\vect_249.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_249.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_250.src: $(SRC_PROC_CC_DIR)\vect_250.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_250.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_251.src: $(SRC_PROC_CC_DIR)\vect_251.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_251.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_252.src: $(SRC_PROC_CC_DIR)\vect_252.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_252.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_253.src: $(SRC_PROC_CC_DIR)\vect_253.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_253.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_254.src: $(SRC_PROC_CC_DIR)\vect_254.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_254.src $(OBJS_DIR)\

$(OBJS_DIR)\vect_255.src: $(SRC_PROC_CC_DIR)\vect_255.src
	$(CMD_CP) $(SRC_PROC_CC_DIR)\vect_255.src $(OBJS_DIR)\



# end of file
