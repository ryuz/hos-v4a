# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= libhosv4a


# %jp{ツール定義}%jp{tools}
GCC_ARCH ?= sh-elf-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= sh2
ARCH_PROC ?= sh/sh2
ARCH_IRC  ?= simple
ARCH_CC   ?= gcc


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


# %jp{ベクタの高速化}%en{fast vector}
ifeq ($(FAST_VECTOR),Yes)
A_DEFS += _KERNEL_FAST_INTVEC="ON"
endif


# %jp{オプションフラグ}
AFLAGS  = -m2
CFLAGS  = -m2
ARFLAGS = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kena_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kwai_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kcre_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/krst_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kswi_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kint_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/kexc_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_dmy.S

ifneq ($(FAST_VECTOR),Yes)
ASRCS += $(SRC_PROC_CC_DIR)/vect_004.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_005.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_006.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_007.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_008.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_009.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_010.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_011.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_012.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_013.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_014.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_015.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_016.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_017.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_018.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_019.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_020.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_021.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_022.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_023.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_024.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_025.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_026.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_027.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_028.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_029.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_030.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_031.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_032.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_033.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_034.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_035.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_036.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_037.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_038.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_039.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_040.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_041.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_042.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_043.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_044.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_045.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_046.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_047.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_048.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_049.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_050.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_051.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_052.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_053.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_054.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_055.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_056.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_057.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_058.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_059.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_060.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_061.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_062.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_063.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_064.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_065.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_066.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_067.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_068.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_069.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_070.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_071.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_072.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_073.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_074.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_075.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_076.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_077.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_078.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_079.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_080.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_081.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_082.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_083.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_084.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_085.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_086.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_087.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_088.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_089.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_090.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_091.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_092.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_093.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_094.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_095.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_096.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_097.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_098.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_099.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_100.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_101.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_102.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_103.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_104.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_105.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_106.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_107.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_108.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_109.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_110.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_111.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_112.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_113.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_114.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_115.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_116.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_117.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_118.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_119.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_120.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_121.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_122.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_123.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_124.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_125.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_126.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_127.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_128.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_129.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_130.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_131.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_132.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_133.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_134.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_135.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_136.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_137.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_138.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_139.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_140.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_141.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_142.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_143.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_144.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_145.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_146.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_147.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_148.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_149.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_150.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_151.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_152.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_153.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_154.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_155.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_156.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_157.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_158.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_159.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_160.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_161.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_162.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_163.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_164.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_165.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_166.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_167.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_168.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_169.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_170.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_171.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_172.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_173.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_174.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_175.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_176.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_177.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_178.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_179.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_180.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_181.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_182.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_183.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_184.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_185.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_186.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_187.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_188.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_189.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_190.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_191.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_192.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_193.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_194.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_195.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_196.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_197.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_198.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_199.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_200.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_201.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_202.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_203.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_204.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_205.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_206.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_207.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_208.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_209.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_210.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_211.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_212.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_213.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_214.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_215.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_216.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_217.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_218.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_219.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_220.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_221.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_222.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_223.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_224.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_225.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_226.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_227.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_228.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_229.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_230.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_231.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_232.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_233.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_234.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_235.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_236.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_237.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_238.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_239.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_240.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_241.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_242.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_243.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_244.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_245.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_246.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_247.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_248.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_249.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_250.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_251.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_252.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_253.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_254.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_255.S
endif


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += $(SRC_PROC_DIR)/val_int.c
CSRCS += $(SRC_IRC_DIR)/chg_ilv.c
CSRCS += $(SRC_IRC_DIR)/chg_imsk.c
CSRCS += $(SRC_IRC_DIR)/clr_int.c
CSRCS += $(SRC_IRC_DIR)/dis_int.c
CSRCS += $(SRC_IRC_DIR)/ena_int.c
CSRCS += $(SRC_IRC_DIR)/get_ilv.c
CSRCS += $(SRC_IRC_DIR)/get_imsk.c


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


$(OBJS_DIR)/val_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/chg_ilv.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/clr_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/dis_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/ena_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/get_ilv.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/chg_imsk.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/get_imsk.$(EXT_OBJ)	:	$(COMMON_HEADERS)



# end of file
