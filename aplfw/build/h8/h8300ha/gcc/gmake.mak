# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for H8/300H
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# %jp{ターゲット名}
TARGET ?= hosaplfw


# %jp{ツール定義}
GCC_ARCH ?= h8300-elf-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{ディレクトリ定義}
TOP_DIR           = ../../../../..
APLFW_DIR         = $(TOP_DIR)/aplfw
KERNEL_DIR        = $(TOP_DIR)/kernel
APLFW_MKINK_DIR   = $(APLFW_DIR)/build/common/gmake
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake

# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/common.inc

MAKE_INC_DIR   = $(KERNEL_DIR)/build/common/gmake
OBJS_DIR       = objs_$(TARGET)
DRV_SERIAL_DIR = $(APLFW_DIR)/driver/serial/renesas


# %jp{パス設定}
INC_DIRS += $(APLFW_DIR) $(KERNEL_DIR)/include
SRC_DIRS += $(DRV_SERIAL_DIR)

# %jp{オプションフラグ}
AFLAGS += -CPu=300HA:24
CFLAGS += -CPu=300HA:24
LFLAGS += 


# アセンブラファイルの追加
ASRCS += 

# C言語ファイルの追加
CSRCS += 


all: makelib_all

clean: makelib_clean
	$(RM) -f *.lst


# %jp{ch38用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_def.inc

# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc
include $(APLFW_MKINK_DIR)/aplfwsrc.inc


# %jp{ch38用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/gcc_rul.inc

# %jp{依存関係定義読込み}
include $(APLFW_MKINK_DIR)/aplfwdep.inc

# end of file
