# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for win32
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= libhosv4a

# %jp{拡張子設定}
EXT_EXE = exe

# %jp{アーキテクチャパス}
ARCH_PROC ?= win/win32
ARCH_IRC  ?= simple
ARCH_CC   ?= gcc


# %jp{ツール定義}
GCC_ARCH ?=
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


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
AFLAGS  += 
CFLAGS  += 
ARFLAGS += 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-win32


# %jp{C言語ファイルの追加}
CSRCS += $(SRC_PROC_DIR)/ctxctl.c


# アセンブラファイルの追加
ASRCS += 


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


# %jp{コンパイラ依存の設定読込み}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc


# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc


# %jp{コンパイラ依存ルール定義読込み}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc


# %jp{カーネル依存関係読込み}
include $(KERNEL_MAKINC_DIR)/knldep.inc


# end of file
