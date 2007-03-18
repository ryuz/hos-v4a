# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= libhosv4a


# %jp{ディレクトリ定義}
HOSV4A_DIR        = ../../../../..
KERNEL_DIR        = $(HOSV4A_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
OBJS_DIR          = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャ定義}
ARCH_PROC ?= sh/sh2
ARCH_IRC  ?= simple
ARCH_CC   ?= shc

# %jp{アーキテクチャパス}
INC_PROC_DIR    = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)
INC_IRC_DIR     = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)
SRC_PROC_DIR    = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)
SRC_PROC_CC_DIR = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR     = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)
SRC_IRC_CC_DIR  = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)/$(ARCH_CC)

# %jp{パス設定}
INC_DIRS += $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS += $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_ASM_DIR)

# %jp{オプションフラグ}
AFLAGS  += -CPu=sh2
CFLAGS  += -CPu=sh2
ARFLAGS += 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(HOSV4A_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-sh2


# %jp{shc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/shc_def.inc



# %jp{C言語ファイルの追加}
CSRCS += $(SRC_PROC_DIR)/val_int.c			\
         $(SRC_IRC_DIR)/chg_ilv.c			\
         $(SRC_IRC_DIR)/chg_imsk.c			\
         $(SRC_IRC_DIR)/clr_int.c			\
         $(SRC_IRC_DIR)/dis_int.c			\
         $(SRC_IRC_DIR)/ena_int.c			\
         $(SRC_IRC_DIR)/get_ilv.c			\
         $(SRC_IRC_DIR)/get_imsk.c

# %jp{アセンブラファイルの追加}
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.src	\
         $(SRC_PROC_CC_DIR)/kena_int.src	\
         $(SRC_PROC_CC_DIR)/kwai_int.src	\
         $(SRC_PROC_CC_DIR)/kcre_ctx.src	\
         $(SRC_PROC_CC_DIR)/krst_ctx.src	\
         $(SRC_PROC_CC_DIR)/kswi_ctx.src	\
         $(SRC_PROC_CC_DIR)/kint_hdr.src	\
         $(SRC_PROC_CC_DIR)/kexc_hdr.src	\
         $(SRC_PROC_CC_DIR)/vect_dmy.src

ifneq ($(FAST_VECTOR),Yes)
ASRCS += $(SRC_PROC_CC_DIR)/vect_004.src	\
         $(SRC_PROC_CC_DIR)/vect_005.src	\
         $(SRC_PROC_CC_DIR)/vect_006.src	\
         $(SRC_PROC_CC_DIR)/vect_007.src	\
         $(SRC_PROC_CC_DIR)/vect_008.src	\
         $(SRC_PROC_CC_DIR)/vect_009.src	\
         $(SRC_PROC_CC_DIR)/vect_010.src	\
         $(SRC_PROC_CC_DIR)/vect_011.src	\
         $(SRC_PROC_CC_DIR)/vect_012.src	\
         $(SRC_PROC_CC_DIR)/vect_013.src	\
         $(SRC_PROC_CC_DIR)/vect_014.src	\
         $(SRC_PROC_CC_DIR)/vect_015.src	\
         $(SRC_PROC_CC_DIR)/vect_016.src	\
         $(SRC_PROC_CC_DIR)/vect_017.src	\
         $(SRC_PROC_CC_DIR)/vect_018.src	\
         $(SRC_PROC_CC_DIR)/vect_019.src	\
         $(SRC_PROC_CC_DIR)/vect_020.src	\
         $(SRC_PROC_CC_DIR)/vect_021.src	\
         $(SRC_PROC_CC_DIR)/vect_022.src	\
         $(SRC_PROC_CC_DIR)/vect_023.src	\
         $(SRC_PROC_CC_DIR)/vect_024.src	\
         $(SRC_PROC_CC_DIR)/vect_025.src	\
         $(SRC_PROC_CC_DIR)/vect_026.src	\
         $(SRC_PROC_CC_DIR)/vect_027.src	\
         $(SRC_PROC_CC_DIR)/vect_028.src	\
         $(SRC_PROC_CC_DIR)/vect_029.src	\
         $(SRC_PROC_CC_DIR)/vect_030.src	\
         $(SRC_PROC_CC_DIR)/vect_031.src	\
         $(SRC_PROC_CC_DIR)/vect_032.src	\
         $(SRC_PROC_CC_DIR)/vect_033.src	\
         $(SRC_PROC_CC_DIR)/vect_034.src	\
         $(SRC_PROC_CC_DIR)/vect_035.src	\
         $(SRC_PROC_CC_DIR)/vect_036.src	\
         $(SRC_PROC_CC_DIR)/vect_037.src	\
         $(SRC_PROC_CC_DIR)/vect_038.src	\
         $(SRC_PROC_CC_DIR)/vect_039.src	\
         $(SRC_PROC_CC_DIR)/vect_040.src	\
         $(SRC_PROC_CC_DIR)/vect_041.src	\
         $(SRC_PROC_CC_DIR)/vect_042.src	\
         $(SRC_PROC_CC_DIR)/vect_043.src	\
         $(SRC_PROC_CC_DIR)/vect_044.src	\
         $(SRC_PROC_CC_DIR)/vect_045.src	\
         $(SRC_PROC_CC_DIR)/vect_046.src	\
         $(SRC_PROC_CC_DIR)/vect_047.src	\
         $(SRC_PROC_CC_DIR)/vect_048.src	\
         $(SRC_PROC_CC_DIR)/vect_049.src	\
         $(SRC_PROC_CC_DIR)/vect_050.src	\
         $(SRC_PROC_CC_DIR)/vect_051.src	\
         $(SRC_PROC_CC_DIR)/vect_052.src	\
         $(SRC_PROC_CC_DIR)/vect_053.src	\
         $(SRC_PROC_CC_DIR)/vect_054.src	\
         $(SRC_PROC_CC_DIR)/vect_055.src	\
         $(SRC_PROC_CC_DIR)/vect_056.src	\
         $(SRC_PROC_CC_DIR)/vect_057.src	\
         $(SRC_PROC_CC_DIR)/vect_058.src	\
         $(SRC_PROC_CC_DIR)/vect_059.src	\
         $(SRC_PROC_CC_DIR)/vect_060.src	\
         $(SRC_PROC_CC_DIR)/vect_061.src	\
         $(SRC_PROC_CC_DIR)/vect_062.src	\
         $(SRC_PROC_CC_DIR)/vect_063.src	\
         $(SRC_PROC_CC_DIR)/vect_064.src	\
         $(SRC_PROC_CC_DIR)/vect_065.src	\
         $(SRC_PROC_CC_DIR)/vect_066.src	\
         $(SRC_PROC_CC_DIR)/vect_067.src	\
         $(SRC_PROC_CC_DIR)/vect_068.src	\
         $(SRC_PROC_CC_DIR)/vect_069.src	\
         $(SRC_PROC_CC_DIR)/vect_070.src	\
         $(SRC_PROC_CC_DIR)/vect_071.src	\
         $(SRC_PROC_CC_DIR)/vect_072.src	\
         $(SRC_PROC_CC_DIR)/vect_073.src	\
         $(SRC_PROC_CC_DIR)/vect_074.src	\
         $(SRC_PROC_CC_DIR)/vect_075.src	\
         $(SRC_PROC_CC_DIR)/vect_076.src	\
         $(SRC_PROC_CC_DIR)/vect_077.src	\
         $(SRC_PROC_CC_DIR)/vect_078.src	\
         $(SRC_PROC_CC_DIR)/vect_079.src	\
         $(SRC_PROC_CC_DIR)/vect_080.src	\
         $(SRC_PROC_CC_DIR)/vect_081.src	\
         $(SRC_PROC_CC_DIR)/vect_082.src	\
         $(SRC_PROC_CC_DIR)/vect_083.src	\
         $(SRC_PROC_CC_DIR)/vect_084.src	\
         $(SRC_PROC_CC_DIR)/vect_085.src	\
         $(SRC_PROC_CC_DIR)/vect_086.src	\
         $(SRC_PROC_CC_DIR)/vect_087.src	\
         $(SRC_PROC_CC_DIR)/vect_088.src	\
         $(SRC_PROC_CC_DIR)/vect_089.src	\
         $(SRC_PROC_CC_DIR)/vect_090.src	\
         $(SRC_PROC_CC_DIR)/vect_091.src	\
         $(SRC_PROC_CC_DIR)/vect_092.src	\
         $(SRC_PROC_CC_DIR)/vect_093.src	\
         $(SRC_PROC_CC_DIR)/vect_094.src	\
         $(SRC_PROC_CC_DIR)/vect_095.src	\
         $(SRC_PROC_CC_DIR)/vect_096.src	\
         $(SRC_PROC_CC_DIR)/vect_097.src	\
         $(SRC_PROC_CC_DIR)/vect_098.src	\
         $(SRC_PROC_CC_DIR)/vect_099.src	\
         $(SRC_PROC_CC_DIR)/vect_100.src	\
         $(SRC_PROC_CC_DIR)/vect_101.src	\
         $(SRC_PROC_CC_DIR)/vect_102.src	\
         $(SRC_PROC_CC_DIR)/vect_103.src	\
         $(SRC_PROC_CC_DIR)/vect_104.src	\
         $(SRC_PROC_CC_DIR)/vect_105.src	\
         $(SRC_PROC_CC_DIR)/vect_106.src	\
         $(SRC_PROC_CC_DIR)/vect_107.src	\
         $(SRC_PROC_CC_DIR)/vect_108.src	\
         $(SRC_PROC_CC_DIR)/vect_109.src	\
         $(SRC_PROC_CC_DIR)/vect_110.src	\
         $(SRC_PROC_CC_DIR)/vect_111.src	\
         $(SRC_PROC_CC_DIR)/vect_112.src	\
         $(SRC_PROC_CC_DIR)/vect_113.src	\
         $(SRC_PROC_CC_DIR)/vect_114.src	\
         $(SRC_PROC_CC_DIR)/vect_115.src	\
         $(SRC_PROC_CC_DIR)/vect_116.src	\
         $(SRC_PROC_CC_DIR)/vect_117.src	\
         $(SRC_PROC_CC_DIR)/vect_118.src	\
         $(SRC_PROC_CC_DIR)/vect_119.src	\
         $(SRC_PROC_CC_DIR)/vect_120.src	\
         $(SRC_PROC_CC_DIR)/vect_121.src	\
         $(SRC_PROC_CC_DIR)/vect_122.src	\
         $(SRC_PROC_CC_DIR)/vect_123.src	\
         $(SRC_PROC_CC_DIR)/vect_124.src	\
         $(SRC_PROC_CC_DIR)/vect_125.src	\
         $(SRC_PROC_CC_DIR)/vect_126.src	\
         $(SRC_PROC_CC_DIR)/vect_127.src	\
         $(SRC_PROC_CC_DIR)/vect_128.src	\
         $(SRC_PROC_CC_DIR)/vect_129.src	\
         $(SRC_PROC_CC_DIR)/vect_130.src	\
         $(SRC_PROC_CC_DIR)/vect_131.src	\
         $(SRC_PROC_CC_DIR)/vect_132.src	\
         $(SRC_PROC_CC_DIR)/vect_133.src	\
         $(SRC_PROC_CC_DIR)/vect_134.src	\
         $(SRC_PROC_CC_DIR)/vect_135.src	\
         $(SRC_PROC_CC_DIR)/vect_136.src	\
         $(SRC_PROC_CC_DIR)/vect_137.src	\
         $(SRC_PROC_CC_DIR)/vect_138.src	\
         $(SRC_PROC_CC_DIR)/vect_139.src	\
         $(SRC_PROC_CC_DIR)/vect_140.src	\
         $(SRC_PROC_CC_DIR)/vect_141.src	\
         $(SRC_PROC_CC_DIR)/vect_142.src	\
         $(SRC_PROC_CC_DIR)/vect_143.src	\
         $(SRC_PROC_CC_DIR)/vect_144.src	\
         $(SRC_PROC_CC_DIR)/vect_145.src	\
         $(SRC_PROC_CC_DIR)/vect_146.src	\
         $(SRC_PROC_CC_DIR)/vect_147.src	\
         $(SRC_PROC_CC_DIR)/vect_148.src	\
         $(SRC_PROC_CC_DIR)/vect_149.src	\
         $(SRC_PROC_CC_DIR)/vect_150.src	\
         $(SRC_PROC_CC_DIR)/vect_151.src	\
         $(SRC_PROC_CC_DIR)/vect_152.src	\
         $(SRC_PROC_CC_DIR)/vect_153.src	\
         $(SRC_PROC_CC_DIR)/vect_154.src	\
         $(SRC_PROC_CC_DIR)/vect_155.src	\
         $(SRC_PROC_CC_DIR)/vect_156.src	\
         $(SRC_PROC_CC_DIR)/vect_157.src	\
         $(SRC_PROC_CC_DIR)/vect_158.src	\
         $(SRC_PROC_CC_DIR)/vect_159.src	\
         $(SRC_PROC_CC_DIR)/vect_160.src	\
         $(SRC_PROC_CC_DIR)/vect_161.src	\
         $(SRC_PROC_CC_DIR)/vect_162.src	\
         $(SRC_PROC_CC_DIR)/vect_163.src	\
         $(SRC_PROC_CC_DIR)/vect_164.src	\
         $(SRC_PROC_CC_DIR)/vect_165.src	\
         $(SRC_PROC_CC_DIR)/vect_166.src	\
         $(SRC_PROC_CC_DIR)/vect_167.src	\
         $(SRC_PROC_CC_DIR)/vect_168.src	\
         $(SRC_PROC_CC_DIR)/vect_169.src	\
         $(SRC_PROC_CC_DIR)/vect_170.src	\
         $(SRC_PROC_CC_DIR)/vect_171.src	\
         $(SRC_PROC_CC_DIR)/vect_172.src	\
         $(SRC_PROC_CC_DIR)/vect_173.src	\
         $(SRC_PROC_CC_DIR)/vect_174.src	\
         $(SRC_PROC_CC_DIR)/vect_175.src	\
         $(SRC_PROC_CC_DIR)/vect_176.src	\
         $(SRC_PROC_CC_DIR)/vect_177.src	\
         $(SRC_PROC_CC_DIR)/vect_178.src	\
         $(SRC_PROC_CC_DIR)/vect_179.src	\
         $(SRC_PROC_CC_DIR)/vect_180.src	\
         $(SRC_PROC_CC_DIR)/vect_181.src	\
         $(SRC_PROC_CC_DIR)/vect_182.src	\
         $(SRC_PROC_CC_DIR)/vect_183.src	\
         $(SRC_PROC_CC_DIR)/vect_184.src	\
         $(SRC_PROC_CC_DIR)/vect_185.src	\
         $(SRC_PROC_CC_DIR)/vect_186.src	\
         $(SRC_PROC_CC_DIR)/vect_187.src	\
         $(SRC_PROC_CC_DIR)/vect_188.src	\
         $(SRC_PROC_CC_DIR)/vect_189.src	\
         $(SRC_PROC_CC_DIR)/vect_190.src	\
         $(SRC_PROC_CC_DIR)/vect_191.src	\
         $(SRC_PROC_CC_DIR)/vect_192.src	\
         $(SRC_PROC_CC_DIR)/vect_193.src	\
         $(SRC_PROC_CC_DIR)/vect_194.src	\
         $(SRC_PROC_CC_DIR)/vect_195.src	\
         $(SRC_PROC_CC_DIR)/vect_196.src	\
         $(SRC_PROC_CC_DIR)/vect_197.src	\
         $(SRC_PROC_CC_DIR)/vect_198.src	\
         $(SRC_PROC_CC_DIR)/vect_199.src	\
         $(SRC_PROC_CC_DIR)/vect_200.src	\
         $(SRC_PROC_CC_DIR)/vect_201.src	\
         $(SRC_PROC_CC_DIR)/vect_202.src	\
         $(SRC_PROC_CC_DIR)/vect_203.src	\
         $(SRC_PROC_CC_DIR)/vect_204.src	\
         $(SRC_PROC_CC_DIR)/vect_205.src	\
         $(SRC_PROC_CC_DIR)/vect_206.src	\
         $(SRC_PROC_CC_DIR)/vect_207.src	\
         $(SRC_PROC_CC_DIR)/vect_208.src	\
         $(SRC_PROC_CC_DIR)/vect_209.src	\
         $(SRC_PROC_CC_DIR)/vect_210.src	\
         $(SRC_PROC_CC_DIR)/vect_211.src	\
         $(SRC_PROC_CC_DIR)/vect_212.src	\
         $(SRC_PROC_CC_DIR)/vect_213.src	\
         $(SRC_PROC_CC_DIR)/vect_214.src	\
         $(SRC_PROC_CC_DIR)/vect_215.src	\
         $(SRC_PROC_CC_DIR)/vect_216.src	\
         $(SRC_PROC_CC_DIR)/vect_217.src	\
         $(SRC_PROC_CC_DIR)/vect_218.src	\
         $(SRC_PROC_CC_DIR)/vect_219.src	\
         $(SRC_PROC_CC_DIR)/vect_220.src	\
         $(SRC_PROC_CC_DIR)/vect_221.src	\
         $(SRC_PROC_CC_DIR)/vect_222.src	\
         $(SRC_PROC_CC_DIR)/vect_223.src	\
         $(SRC_PROC_CC_DIR)/vect_224.src	\
         $(SRC_PROC_CC_DIR)/vect_225.src	\
         $(SRC_PROC_CC_DIR)/vect_226.src	\
         $(SRC_PROC_CC_DIR)/vect_227.src	\
         $(SRC_PROC_CC_DIR)/vect_228.src	\
         $(SRC_PROC_CC_DIR)/vect_229.src	\
         $(SRC_PROC_CC_DIR)/vect_230.src	\
         $(SRC_PROC_CC_DIR)/vect_231.src	\
         $(SRC_PROC_CC_DIR)/vect_232.src	\
         $(SRC_PROC_CC_DIR)/vect_233.src	\
         $(SRC_PROC_CC_DIR)/vect_234.src	\
         $(SRC_PROC_CC_DIR)/vect_235.src	\
         $(SRC_PROC_CC_DIR)/vect_236.src	\
         $(SRC_PROC_CC_DIR)/vect_237.src	\
         $(SRC_PROC_CC_DIR)/vect_238.src	\
         $(SRC_PROC_CC_DIR)/vect_239.src	\
         $(SRC_PROC_CC_DIR)/vect_240.src	\
         $(SRC_PROC_CC_DIR)/vect_241.src	\
         $(SRC_PROC_CC_DIR)/vect_242.src	\
         $(SRC_PROC_CC_DIR)/vect_243.src	\
         $(SRC_PROC_CC_DIR)/vect_244.src	\
         $(SRC_PROC_CC_DIR)/vect_245.src	\
         $(SRC_PROC_CC_DIR)/vect_246.src	\
         $(SRC_PROC_CC_DIR)/vect_247.src	\
         $(SRC_PROC_CC_DIR)/vect_248.src	\
         $(SRC_PROC_CC_DIR)/vect_249.src	\
         $(SRC_PROC_CC_DIR)/vect_250.src	\
         $(SRC_PROC_CC_DIR)/vect_251.src	\
         $(SRC_PROC_CC_DIR)/vect_252.src	\
         $(SRC_PROC_CC_DIR)/vect_253.src	\
         $(SRC_PROC_CC_DIR)/vect_254.src	\
         $(SRC_PROC_CC_DIR)/vect_255.src
endif


# カーネル共通ソースの追加
include $(KERNEL_MAKINC_DIR)/knlsrc.inc


# %jp{ALL}
.PHONY : all
all: makelib_all
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}
.PHONY : clean
clean: makelib_clean
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(RM) -f *.lst


# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc

# %jp{shc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/shc_rul.inc

# %jp{カーネル依存関係読込み}
include $(KERNEL_MAKINC_DIR)/knldep.inc



# end of file
