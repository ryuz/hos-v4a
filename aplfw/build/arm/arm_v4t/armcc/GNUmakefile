# ----------------------------------------------------------------------------
# Hyper Operating System  Application Framework
#  makefile for ARM V4T
#
# Copyright (C) 1998-2008 by Project HOS
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
CFLAGS  = --cpu=4T --apcs=inter --thumb
AFLAGS  = --cpu=4T --apcs=inter --thumb
ARFLAGS = 


# %jp{リンク制御対象制御}
LINK_AT91USART = Yes
LINK_MX1UART   = Yes



.PHONY : all
all: makelib_all

.PHONY : clean
clean: makelib_clean
	$(RM) -f *.lst

.PHONY : depend
depend: makelib_depend



# %jp{armcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/armcc_d.inc

# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc

include $(HOSAPLFW_MKINK_DIR)/aplfwsrc.inc

include $(KERNEL_MAKINC_DIR)/maklib_r.inc

# %jp{armcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/armcc_r.inc

# %jp{依存関係定義読込み}
include $(HOSAPLFW_MKINK_DIR)/aplfwdep.inc


# end of file
