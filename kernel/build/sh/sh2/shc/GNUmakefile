# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for SH2
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# --------------------------------------
#  %jp{各種設定}%en{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= libhosv4a


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= sh2
ARCH_PROC ?= sh/sh2
ARCH_IRC  ?= simple
ARCH_CC   ?= shc


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR           = ../../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
INC_PROC_DIR      = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)
INC_IRC_DIR       = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)
SRC_PROC_DIR      = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)
SRC_PROC_CC_DIR   = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR       = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)
SRC_IRC_CC_DIR    = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)/$(ARCH_CC)
CFGRTR_DIR        = $(TOP_DIR)/cfgrtr/build/gcc


# %jp{コンフィギュレータ定義}%en{kernel configurator}
CFGRTR = h4acfg-$(ARCH_NAME)


# %jp{カーネル指定}%en{kernel flag}
KERNEL = Yes


# %jp{共通定義読込み}%en{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{パス設定}%en{add source directories}
INC_DIRS += $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS += $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_CC_DIR)


# %jp{オプションフラグ}%en{option flags}
CFLAGS  = -CPu=sh2
AFLAGS  = -CPu=sh2
ARFLAGS = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------


ifeq ($(FAST_VECTOR),Yes)
A_DEFS += _KERNEL_FAST_INTVEC="ON"
endif


# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.src
ASRCS += $(SRC_PROC_CC_DIR)/kena_int.src
ASRCS += $(SRC_PROC_CC_DIR)/kwai_int.src
ASRCS += $(SRC_PROC_CC_DIR)/kcre_ctx.src
ASRCS += $(SRC_PROC_CC_DIR)/krst_ctx.src
ASRCS += $(SRC_PROC_CC_DIR)/kswi_ctx.src
ASRCS += $(SRC_PROC_CC_DIR)/kint_hdr.src
ASRCS += $(SRC_PROC_CC_DIR)/kexc_hdr.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_dmy.src

ifneq ($(FAST_VECTOR),Yes)
ASRCS += $(SRC_PROC_CC_DIR)/vect_004.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_005.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_006.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_007.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_008.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_009.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_010.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_011.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_012.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_013.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_014.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_015.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_016.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_017.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_018.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_019.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_020.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_021.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_022.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_023.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_024.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_025.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_026.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_027.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_028.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_029.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_030.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_031.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_032.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_033.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_034.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_035.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_036.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_037.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_038.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_039.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_040.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_041.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_042.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_043.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_044.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_045.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_046.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_047.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_048.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_049.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_050.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_051.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_052.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_053.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_054.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_055.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_056.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_057.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_058.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_059.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_060.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_061.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_062.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_063.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_064.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_065.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_066.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_067.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_068.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_069.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_070.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_071.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_072.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_073.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_074.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_075.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_076.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_077.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_078.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_079.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_080.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_081.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_082.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_083.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_084.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_085.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_086.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_087.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_088.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_089.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_090.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_091.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_092.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_093.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_094.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_095.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_096.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_097.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_098.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_099.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_100.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_101.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_102.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_103.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_104.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_105.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_106.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_107.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_108.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_109.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_110.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_111.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_112.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_113.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_114.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_115.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_116.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_117.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_118.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_119.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_120.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_121.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_122.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_123.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_124.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_125.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_126.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_127.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_128.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_129.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_130.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_131.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_132.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_133.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_134.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_135.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_136.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_137.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_138.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_139.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_140.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_141.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_142.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_143.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_144.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_145.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_146.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_147.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_148.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_149.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_150.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_151.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_152.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_153.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_154.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_155.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_156.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_157.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_158.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_159.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_160.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_161.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_162.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_163.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_164.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_165.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_166.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_167.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_168.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_169.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_170.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_171.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_172.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_173.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_174.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_175.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_176.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_177.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_178.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_179.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_180.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_181.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_182.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_183.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_184.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_185.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_186.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_187.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_188.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_189.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_190.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_191.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_192.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_193.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_194.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_195.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_196.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_197.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_198.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_199.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_200.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_201.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_202.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_203.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_204.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_205.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_206.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_207.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_208.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_209.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_210.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_211.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_212.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_213.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_214.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_215.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_216.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_217.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_218.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_219.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_220.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_221.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_222.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_223.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_224.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_225.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_226.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_227.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_228.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_229.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_230.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_231.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_232.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_233.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_234.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_235.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_236.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_237.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_238.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_239.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_240.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_241.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_242.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_243.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_244.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_245.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_246.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_247.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_248.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_249.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_250.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_251.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_252.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_253.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_254.src
ASRCS += $(SRC_PROC_CC_DIR)/vect_255.src
endif


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += $(SRC_PROC_DIR)/val_int.c
CSRCS += $(SRC_IRC_DIR)/ena_int.c
CSRCS += $(SRC_IRC_DIR)/dis_int.c
CSRCS += $(SRC_IRC_DIR)/clr_int.c
CSRCS += $(SRC_IRC_DIR)/get_imsk.c
CSRCS += $(SRC_IRC_DIR)/chg_imsk.c
CSRCS += $(SRC_IRC_DIR)/chg_ilv.c
CSRCS += $(SRC_IRC_DIR)/get_ilv.c


# %jp{カーネル共通ソースの追加}%en{kernel common sources}
include $(KERNEL_MAKINC_DIR)/knlsrc.inc




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: makelib_all
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}%en{clean}
.PHONY : clean
clean: makelib_clean
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(RM) -f *.lst

# %jp{依存関係更新}%en{make depend}
.PHONY : depend
depend: makelib_depend

# %jp{ソース一括コピー}%en{source files copy}
.PHONY : srccpy
srccpy: makelib_srccpy


# %jp{ライブラリ生成用設定読込み}%en{rules for library}
include $(KERNEL_MAKINC_DIR)/maklib_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

# %jp{カーネル依存関係読込み}{dependency list of kernel sources}
include $(KERNEL_MAKINC_DIR)/knldep.inc



# end of file
