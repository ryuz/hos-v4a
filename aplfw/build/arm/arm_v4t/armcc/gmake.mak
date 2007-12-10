# ----------------------------------------------------------------------------
#  makefile for ARM V4T
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= hosaplfw


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
INC_DIRS += $(KERNEL_DIR)/include


# %jp{オプションフラグ}
AFLAGS += --cpu=4T --apcs=inter --thumb
CFLAGS += --cpu=4T --apcs=inter --thumb
LFLAGS += 


# %jp{リンク制御対象制御}
LINK_AT91USART = Yes
LINK_MX1UART   = Yes


all: makelib_all

clean: makelib_clean
	$(RM) -f *.lst


# %jp{armcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/armcc_d.inc

# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc
include $(HOSAPLFW_MKINK_DIR)/aplfwsrc.inc


# %jp{armcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/armcc_r.inc

# %jp{依存関係定義読込み}
include $(HOSAPLFW_MKINK_DIR)/aplfwdep.inc


# end of file
