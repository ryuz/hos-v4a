# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= libhosv4a

# %jp{アーキテクチャパス}
ARCH_PROC ?= sh/sh2
ARCH_IRC  ?= simple
ARCH_CC   ?= gcc

# %jp{ツール定義}
GCC_SYS  ?= elf
CMD_CC   ?= sh-$(GCC_SYS)-gcc
CMD_ASM  ?= sh-$(GCC_SYS)-gcc
CMD_LIBR ?= sh-$(GCC_SYS)-ar


# %jp{ディレクトリ定義}
TOP_DIR           = ../../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
OBJS_DIR          = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャパス定義}
INC_PROC_DIR     = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)
INC_IRC_DIR      = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)
SRC_PROC_DIR     = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)
SRC_PROC_ASM_DIR = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR      = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)
SRC_IRC_ASM_DIR  = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)/$(ARCH_CC)

# %jp{パス設定}
INC_DIRS += $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS += $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_ASM_DIR) $(SRC_IRC_DIR) $(SRC_IRC_ASM_DIR)

# %jp{オプションフラグ}
AFLAGS  += -m2
CFLAGS  += -m2
ARFLAGS += 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-sh2


# C言語ファイルの追加
# CSRCS += $(SRC_IRC_DIR)/intc.c

# アセンブラファイルの追加
ASRCS += $(SRC_PROC_ASM_DIR)/ctxctl.S		\
         $(SRC_PROC_ASM_DIR)/exchdr.S		\
         $(SRC_PROC_ASM_DIR)/inthdr.S		\
         $(SRC_PROC_ASM_DIR)/vect_dmy.S


ifneq ($(FAST_VECTOR),Yes)
ASRCS += $(SRC_PROC_ASM_DIR)/vect_004.S		\
         $(SRC_PROC_ASM_DIR)/vect_005.S		\
         $(SRC_PROC_ASM_DIR)/vect_006.S		\
         $(SRC_PROC_ASM_DIR)/vect_007.S		\
         $(SRC_PROC_ASM_DIR)/vect_008.S		\
         $(SRC_PROC_ASM_DIR)/vect_009.S		\
         $(SRC_PROC_ASM_DIR)/vect_010.S		\
         $(SRC_PROC_ASM_DIR)/vect_011.S		\
         $(SRC_PROC_ASM_DIR)/vect_012.S		\
         $(SRC_PROC_ASM_DIR)/vect_013.S		\
         $(SRC_PROC_ASM_DIR)/vect_014.S		\
         $(SRC_PROC_ASM_DIR)/vect_015.S		\
         $(SRC_PROC_ASM_DIR)/vect_016.S		\
         $(SRC_PROC_ASM_DIR)/vect_017.S		\
         $(SRC_PROC_ASM_DIR)/vect_018.S		\
         $(SRC_PROC_ASM_DIR)/vect_019.S		\
         $(SRC_PROC_ASM_DIR)/vect_020.S		\
         $(SRC_PROC_ASM_DIR)/vect_021.S		\
         $(SRC_PROC_ASM_DIR)/vect_022.S		\
         $(SRC_PROC_ASM_DIR)/vect_023.S		\
         $(SRC_PROC_ASM_DIR)/vect_024.S		\
         $(SRC_PROC_ASM_DIR)/vect_025.S		\
         $(SRC_PROC_ASM_DIR)/vect_026.S		\
         $(SRC_PROC_ASM_DIR)/vect_027.S		\
         $(SRC_PROC_ASM_DIR)/vect_028.S		\
         $(SRC_PROC_ASM_DIR)/vect_029.S		\
         $(SRC_PROC_ASM_DIR)/vect_030.S		\
         $(SRC_PROC_ASM_DIR)/vect_031.S		\
         $(SRC_PROC_ASM_DIR)/vect_032.S		\
         $(SRC_PROC_ASM_DIR)/vect_033.S		\
         $(SRC_PROC_ASM_DIR)/vect_034.S		\
         $(SRC_PROC_ASM_DIR)/vect_035.S		\
         $(SRC_PROC_ASM_DIR)/vect_036.S		\
         $(SRC_PROC_ASM_DIR)/vect_037.S		\
         $(SRC_PROC_ASM_DIR)/vect_038.S		\
         $(SRC_PROC_ASM_DIR)/vect_039.S		\
         $(SRC_PROC_ASM_DIR)/vect_040.S		\
         $(SRC_PROC_ASM_DIR)/vect_041.S		\
         $(SRC_PROC_ASM_DIR)/vect_042.S		\
         $(SRC_PROC_ASM_DIR)/vect_043.S		\
         $(SRC_PROC_ASM_DIR)/vect_044.S		\
         $(SRC_PROC_ASM_DIR)/vect_045.S		\
         $(SRC_PROC_ASM_DIR)/vect_046.S		\
         $(SRC_PROC_ASM_DIR)/vect_047.S		\
         $(SRC_PROC_ASM_DIR)/vect_048.S		\
         $(SRC_PROC_ASM_DIR)/vect_049.S		\
         $(SRC_PROC_ASM_DIR)/vect_050.S		\
         $(SRC_PROC_ASM_DIR)/vect_051.S		\
         $(SRC_PROC_ASM_DIR)/vect_052.S		\
         $(SRC_PROC_ASM_DIR)/vect_053.S		\
         $(SRC_PROC_ASM_DIR)/vect_054.S		\
         $(SRC_PROC_ASM_DIR)/vect_055.S		\
         $(SRC_PROC_ASM_DIR)/vect_056.S		\
         $(SRC_PROC_ASM_DIR)/vect_057.S		\
         $(SRC_PROC_ASM_DIR)/vect_058.S		\
         $(SRC_PROC_ASM_DIR)/vect_059.S		\
         $(SRC_PROC_ASM_DIR)/vect_060.S		\
         $(SRC_PROC_ASM_DIR)/vect_061.S		\
         $(SRC_PROC_ASM_DIR)/vect_062.S		\
         $(SRC_PROC_ASM_DIR)/vect_063.S		\
         $(SRC_PROC_ASM_DIR)/vect_064.S		\
         $(SRC_PROC_ASM_DIR)/vect_065.S		\
         $(SRC_PROC_ASM_DIR)/vect_066.S		\
         $(SRC_PROC_ASM_DIR)/vect_067.S		\
         $(SRC_PROC_ASM_DIR)/vect_068.S		\
         $(SRC_PROC_ASM_DIR)/vect_069.S		\
         $(SRC_PROC_ASM_DIR)/vect_070.S		\
         $(SRC_PROC_ASM_DIR)/vect_071.S		\
         $(SRC_PROC_ASM_DIR)/vect_072.S		\
         $(SRC_PROC_ASM_DIR)/vect_073.S		\
         $(SRC_PROC_ASM_DIR)/vect_074.S		\
         $(SRC_PROC_ASM_DIR)/vect_075.S		\
         $(SRC_PROC_ASM_DIR)/vect_076.S		\
         $(SRC_PROC_ASM_DIR)/vect_077.S		\
         $(SRC_PROC_ASM_DIR)/vect_078.S		\
         $(SRC_PROC_ASM_DIR)/vect_079.S		\
         $(SRC_PROC_ASM_DIR)/vect_080.S		\
         $(SRC_PROC_ASM_DIR)/vect_081.S		\
         $(SRC_PROC_ASM_DIR)/vect_082.S		\
         $(SRC_PROC_ASM_DIR)/vect_083.S		\
         $(SRC_PROC_ASM_DIR)/vect_084.S		\
         $(SRC_PROC_ASM_DIR)/vect_085.S		\
         $(SRC_PROC_ASM_DIR)/vect_086.S		\
         $(SRC_PROC_ASM_DIR)/vect_087.S		\
         $(SRC_PROC_ASM_DIR)/vect_088.S		\
         $(SRC_PROC_ASM_DIR)/vect_089.S		\
         $(SRC_PROC_ASM_DIR)/vect_090.S		\
         $(SRC_PROC_ASM_DIR)/vect_091.S		\
         $(SRC_PROC_ASM_DIR)/vect_092.S		\
         $(SRC_PROC_ASM_DIR)/vect_093.S		\
         $(SRC_PROC_ASM_DIR)/vect_094.S		\
         $(SRC_PROC_ASM_DIR)/vect_095.S		\
         $(SRC_PROC_ASM_DIR)/vect_096.S		\
         $(SRC_PROC_ASM_DIR)/vect_097.S		\
         $(SRC_PROC_ASM_DIR)/vect_098.S		\
         $(SRC_PROC_ASM_DIR)/vect_099.S		\
         $(SRC_PROC_ASM_DIR)/vect_100.S		\
         $(SRC_PROC_ASM_DIR)/vect_101.S		\
         $(SRC_PROC_ASM_DIR)/vect_102.S		\
         $(SRC_PROC_ASM_DIR)/vect_103.S		\
         $(SRC_PROC_ASM_DIR)/vect_104.S		\
         $(SRC_PROC_ASM_DIR)/vect_105.S		\
         $(SRC_PROC_ASM_DIR)/vect_106.S		\
         $(SRC_PROC_ASM_DIR)/vect_107.S		\
         $(SRC_PROC_ASM_DIR)/vect_108.S		\
         $(SRC_PROC_ASM_DIR)/vect_109.S		\
         $(SRC_PROC_ASM_DIR)/vect_110.S		\
         $(SRC_PROC_ASM_DIR)/vect_111.S		\
         $(SRC_PROC_ASM_DIR)/vect_112.S		\
         $(SRC_PROC_ASM_DIR)/vect_113.S		\
         $(SRC_PROC_ASM_DIR)/vect_114.S		\
         $(SRC_PROC_ASM_DIR)/vect_115.S		\
         $(SRC_PROC_ASM_DIR)/vect_116.S		\
         $(SRC_PROC_ASM_DIR)/vect_117.S		\
         $(SRC_PROC_ASM_DIR)/vect_118.S		\
         $(SRC_PROC_ASM_DIR)/vect_119.S		\
         $(SRC_PROC_ASM_DIR)/vect_120.S		\
         $(SRC_PROC_ASM_DIR)/vect_121.S		\
         $(SRC_PROC_ASM_DIR)/vect_122.S		\
         $(SRC_PROC_ASM_DIR)/vect_123.S		\
         $(SRC_PROC_ASM_DIR)/vect_124.S		\
         $(SRC_PROC_ASM_DIR)/vect_125.S		\
         $(SRC_PROC_ASM_DIR)/vect_126.S		\
         $(SRC_PROC_ASM_DIR)/vect_127.S		\
         $(SRC_PROC_ASM_DIR)/vect_128.S		\
         $(SRC_PROC_ASM_DIR)/vect_129.S		\
         $(SRC_PROC_ASM_DIR)/vect_130.S		\
         $(SRC_PROC_ASM_DIR)/vect_131.S		\
         $(SRC_PROC_ASM_DIR)/vect_132.S		\
         $(SRC_PROC_ASM_DIR)/vect_133.S		\
         $(SRC_PROC_ASM_DIR)/vect_134.S		\
         $(SRC_PROC_ASM_DIR)/vect_135.S		\
         $(SRC_PROC_ASM_DIR)/vect_136.S		\
         $(SRC_PROC_ASM_DIR)/vect_137.S		\
         $(SRC_PROC_ASM_DIR)/vect_138.S		\
         $(SRC_PROC_ASM_DIR)/vect_139.S		\
         $(SRC_PROC_ASM_DIR)/vect_140.S		\
         $(SRC_PROC_ASM_DIR)/vect_141.S		\
         $(SRC_PROC_ASM_DIR)/vect_142.S		\
         $(SRC_PROC_ASM_DIR)/vect_143.S		\
         $(SRC_PROC_ASM_DIR)/vect_144.S		\
         $(SRC_PROC_ASM_DIR)/vect_145.S		\
         $(SRC_PROC_ASM_DIR)/vect_146.S		\
         $(SRC_PROC_ASM_DIR)/vect_147.S		\
         $(SRC_PROC_ASM_DIR)/vect_148.S		\
         $(SRC_PROC_ASM_DIR)/vect_149.S		\
         $(SRC_PROC_ASM_DIR)/vect_150.S		\
         $(SRC_PROC_ASM_DIR)/vect_151.S		\
         $(SRC_PROC_ASM_DIR)/vect_152.S		\
         $(SRC_PROC_ASM_DIR)/vect_153.S		\
         $(SRC_PROC_ASM_DIR)/vect_154.S		\
         $(SRC_PROC_ASM_DIR)/vect_155.S		\
         $(SRC_PROC_ASM_DIR)/vect_156.S		\
         $(SRC_PROC_ASM_DIR)/vect_157.S		\
         $(SRC_PROC_ASM_DIR)/vect_158.S		\
         $(SRC_PROC_ASM_DIR)/vect_159.S		\
         $(SRC_PROC_ASM_DIR)/vect_160.S		\
         $(SRC_PROC_ASM_DIR)/vect_161.S		\
         $(SRC_PROC_ASM_DIR)/vect_162.S		\
         $(SRC_PROC_ASM_DIR)/vect_163.S		\
         $(SRC_PROC_ASM_DIR)/vect_164.S		\
         $(SRC_PROC_ASM_DIR)/vect_165.S		\
         $(SRC_PROC_ASM_DIR)/vect_166.S		\
         $(SRC_PROC_ASM_DIR)/vect_167.S		\
         $(SRC_PROC_ASM_DIR)/vect_168.S		\
         $(SRC_PROC_ASM_DIR)/vect_169.S		\
         $(SRC_PROC_ASM_DIR)/vect_170.S		\
         $(SRC_PROC_ASM_DIR)/vect_171.S		\
         $(SRC_PROC_ASM_DIR)/vect_172.S		\
         $(SRC_PROC_ASM_DIR)/vect_173.S		\
         $(SRC_PROC_ASM_DIR)/vect_174.S		\
         $(SRC_PROC_ASM_DIR)/vect_175.S		\
         $(SRC_PROC_ASM_DIR)/vect_176.S		\
         $(SRC_PROC_ASM_DIR)/vect_177.S		\
         $(SRC_PROC_ASM_DIR)/vect_178.S		\
         $(SRC_PROC_ASM_DIR)/vect_179.S		\
         $(SRC_PROC_ASM_DIR)/vect_180.S		\
         $(SRC_PROC_ASM_DIR)/vect_181.S		\
         $(SRC_PROC_ASM_DIR)/vect_182.S		\
         $(SRC_PROC_ASM_DIR)/vect_183.S		\
         $(SRC_PROC_ASM_DIR)/vect_184.S		\
         $(SRC_PROC_ASM_DIR)/vect_185.S		\
         $(SRC_PROC_ASM_DIR)/vect_186.S		\
         $(SRC_PROC_ASM_DIR)/vect_187.S		\
         $(SRC_PROC_ASM_DIR)/vect_188.S		\
         $(SRC_PROC_ASM_DIR)/vect_189.S		\
         $(SRC_PROC_ASM_DIR)/vect_190.S		\
         $(SRC_PROC_ASM_DIR)/vect_191.S		\
         $(SRC_PROC_ASM_DIR)/vect_192.S		\
         $(SRC_PROC_ASM_DIR)/vect_193.S		\
         $(SRC_PROC_ASM_DIR)/vect_194.S		\
         $(SRC_PROC_ASM_DIR)/vect_195.S		\
         $(SRC_PROC_ASM_DIR)/vect_196.S		\
         $(SRC_PROC_ASM_DIR)/vect_197.S		\
         $(SRC_PROC_ASM_DIR)/vect_198.S		\
         $(SRC_PROC_ASM_DIR)/vect_199.S		\
         $(SRC_PROC_ASM_DIR)/vect_200.S		\
         $(SRC_PROC_ASM_DIR)/vect_201.S		\
         $(SRC_PROC_ASM_DIR)/vect_202.S		\
         $(SRC_PROC_ASM_DIR)/vect_203.S		\
         $(SRC_PROC_ASM_DIR)/vect_204.S		\
         $(SRC_PROC_ASM_DIR)/vect_205.S		\
         $(SRC_PROC_ASM_DIR)/vect_206.S		\
         $(SRC_PROC_ASM_DIR)/vect_207.S		\
         $(SRC_PROC_ASM_DIR)/vect_208.S		\
         $(SRC_PROC_ASM_DIR)/vect_209.S		\
         $(SRC_PROC_ASM_DIR)/vect_210.S		\
         $(SRC_PROC_ASM_DIR)/vect_211.S		\
         $(SRC_PROC_ASM_DIR)/vect_212.S		\
         $(SRC_PROC_ASM_DIR)/vect_213.S		\
         $(SRC_PROC_ASM_DIR)/vect_214.S		\
         $(SRC_PROC_ASM_DIR)/vect_215.S		\
         $(SRC_PROC_ASM_DIR)/vect_216.S		\
         $(SRC_PROC_ASM_DIR)/vect_217.S		\
         $(SRC_PROC_ASM_DIR)/vect_218.S		\
         $(SRC_PROC_ASM_DIR)/vect_219.S		\
         $(SRC_PROC_ASM_DIR)/vect_220.S		\
         $(SRC_PROC_ASM_DIR)/vect_221.S		\
         $(SRC_PROC_ASM_DIR)/vect_222.S		\
         $(SRC_PROC_ASM_DIR)/vect_223.S		\
         $(SRC_PROC_ASM_DIR)/vect_224.S		\
         $(SRC_PROC_ASM_DIR)/vect_225.S		\
         $(SRC_PROC_ASM_DIR)/vect_226.S		\
         $(SRC_PROC_ASM_DIR)/vect_227.S		\
         $(SRC_PROC_ASM_DIR)/vect_228.S		\
         $(SRC_PROC_ASM_DIR)/vect_229.S		\
         $(SRC_PROC_ASM_DIR)/vect_230.S		\
         $(SRC_PROC_ASM_DIR)/vect_231.S		\
         $(SRC_PROC_ASM_DIR)/vect_232.S		\
         $(SRC_PROC_ASM_DIR)/vect_233.S		\
         $(SRC_PROC_ASM_DIR)/vect_234.S		\
         $(SRC_PROC_ASM_DIR)/vect_235.S		\
         $(SRC_PROC_ASM_DIR)/vect_236.S		\
         $(SRC_PROC_ASM_DIR)/vect_237.S		\
         $(SRC_PROC_ASM_DIR)/vect_238.S		\
         $(SRC_PROC_ASM_DIR)/vect_239.S		\
         $(SRC_PROC_ASM_DIR)/vect_240.S		\
         $(SRC_PROC_ASM_DIR)/vect_241.S		\
         $(SRC_PROC_ASM_DIR)/vect_242.S		\
         $(SRC_PROC_ASM_DIR)/vect_243.S		\
         $(SRC_PROC_ASM_DIR)/vect_244.S		\
         $(SRC_PROC_ASM_DIR)/vect_245.S		\
         $(SRC_PROC_ASM_DIR)/vect_246.S		\
         $(SRC_PROC_ASM_DIR)/vect_247.S		\
         $(SRC_PROC_ASM_DIR)/vect_248.S		\
         $(SRC_PROC_ASM_DIR)/vect_249.S		\
         $(SRC_PROC_ASM_DIR)/vect_250.S		\
         $(SRC_PROC_ASM_DIR)/vect_251.S		\
         $(SRC_PROC_ASM_DIR)/vect_252.S		\
         $(SRC_PROC_ASM_DIR)/vect_253.S		\
         $(SRC_PROC_ASM_DIR)/vect_254.S		\
         $(SRC_PROC_ASM_DIR)/vect_255.S
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



# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_def.inc

# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc


# %jp{ch38用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/gcc_rul.inc

# %jp{カーネル依存関係読込み}
include $(KERNEL_MAKINC_DIR)/knldep.inc


# end of file
