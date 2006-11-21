# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for H8/300H advanced mode
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= libhosv4a

# %jp{アーキテクチャパス}
ARCH_PROC ?= h8/h8300ha
ARCH_IRC  ?= simple
ARCH_CC   ?= gcc

# %jp{ツール定義}
GCC_SYS  ?= elf
CMD_CC   ?= h8300-$(GCC_SYS)-gcc
CMD_ASM  ?= h8300-$(GCC_SYS)-gcc
CMD_LIBR ?= h8300-$(GCC_SYS)-ar


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
AFLAGS += -mh
CFLAGS += -mh
LFLAGS += 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-h8300ha


# C言語ファイルの追加
# CSRCS += $(SRC_IRC_DIR)/intc.c

# アセンブラファイルの追加
ASRCS += $(SRC_PROC_ASM_DIR)/ctxctl.S		\
         $(SRC_PROC_ASM_DIR)/intctl.S		\
         $(SRC_PROC_ASM_DIR)/vect_dmy.S		\
         $(SRC_PROC_ASM_DIR)/vect_001.S		\
         $(SRC_PROC_ASM_DIR)/vect_002.S		\
         $(SRC_PROC_ASM_DIR)/vect_003.S		\
         $(SRC_PROC_ASM_DIR)/vect_004.S		\
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
         $(SRC_PROC_ASM_DIR)/vect_063.S

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
