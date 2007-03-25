# ----------------------------------------------------------------------------
#  makefile for ARM V4T
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# %jp{ターゲット名}
TARGET ?= hosaplfw

# %jp{ツール定義}
GCC_SYS  ?= elf
CMD_CC   ?= arm-$(GCC_SYS)-gcc
CMD_ASM  ?= arm-$(GCC_SYS)-gcc
CMD_LIBR ?= arm-$(GCC_SYS)-ar

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
AFLAGS += -march=armv4t -mthumb-interwork
CFLAGS += -march=armv4t -mthumb-interwork
LFLAGS += 


# アセンブラファイルの追加
ASRCS += 

# C言語ファイルの追加
CSRCS += 

all: makelib_all

clean: makelib_clean
	$(RM) -f *.lst


# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_d.inc

# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc
include $(APLFW_MKINK_DIR)/aplfwsrc.inc


# %jp{gcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/gcc_r.inc

# %jp{依存関係定義読込み}
include $(APLFW_MKINK_DIR)/aplfwdep.inc

# end of file
