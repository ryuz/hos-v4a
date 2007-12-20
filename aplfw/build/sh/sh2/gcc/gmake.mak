# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance   Application Framework
#  makefile for SH2
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# %jp{ターゲット名}
TARGET ?= hosaplfw


# %jp{ツール定義}
GCC_SYS  ?= elf
CMD_CC   ?= sh-$(GCC_SYS)-gcc
CMD_ASM  ?= sh-$(GCC_SYS)-gcc
CMD_LIBR ?= sh-$(GCC_SYS)-ar


# %jp{ディレクトリ定義}
TOP_DIR            = ../../../../..
KERNEL_DIR         = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)/build/common/gmake
HOSAPLFW_DIR       = $(TOP_DIR)/aplfw
HOSAPLFW_MKINK_DIR = $(HOSAPLFW_DIR)/build/common/gmake
OBJS_DIR           = objs_$(TARGET)


# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{インクルードパス設定}
INC_DIRS += $(HOSAPLFW_DIR) $(KERNEL_DIR)/include


# %jp{オプションフラグ}
CFLAGS  += -m2
AFLAGS  += -m2
ARFLAGS += 


# %jp{リンク制御対象制御}
LINK_RENESASSCI = Yes



.PHONY : all
all: makelib_all

.PHONY : clean
clean: makelib_clean
	$(RM) -f *.lst

.PHONY : depend
depend: makelib_depend

.PHONY : srccpy
srccpy: makelib_srccpy



# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_d.inc

# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc
include $(HOSAPLFW_MKINK_DIR)/aplfwsrc.inc


# %jp{gcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/gcc_r.inc

# %jp{依存関係定義読込み}
include $(HOSAPLFW_MKINK_DIR)/aplfwdep.inc


# end of file
