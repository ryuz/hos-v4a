# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for H8/300H advanced mode
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}%en{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= libhosv4a


# %jp{ツール定義}%jp{tools}
GCC_ARCH ?= h8300-elf-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= h8300ha
ARCH_PROC ?= h8/h8300ha
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


# %jp{オプションフラグ}%en{option flags}
AFLAGS = -mh
CFLAGS = -mh
LFLAGS = 

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
AFLAGS  = -mh
CFLAGS  = -mh
ARFLAGS = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += $(SRC_PROC_CC_DIR)/kini_prc.S
ASRCS += $(SRC_PROC_CC_DIR)/kena_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kwai_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kcre_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/krst_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kswi_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kint_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_dmy.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_001.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_002.S
ASRCS += $(SRC_PROC_CC_DIR)/vect_003.S
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

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += $(SRC_PROC_DIR)/val_int.c
CSRCS += $(SRC_PROC_DIR)/chg_imsk.c
CSRCS += $(SRC_PROC_DIR)/get_imsk.c
CSRCS += $(SRC_IRC_DIR)/ena_int.c
CSRCS += $(SRC_IRC_DIR)/dis_int.c
CSRCS += $(SRC_IRC_DIR)/clr_int.c
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
