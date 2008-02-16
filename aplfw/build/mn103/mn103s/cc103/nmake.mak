# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = hosaplfw


# %jp{ディレクトリ定義}
TOP_DIR            = ..\..\..\..\..
KERNEL_DIR         = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)\build\common\nmake
HOSAPLFW_DIR       = $(TOP_DIR)\aplfw
HOSAPLFW_MKINK_DIR = $(HOSAPLFW_DIR)/build\common\nmake
OBJS_DIR           = objs_$(TARGET)


# %jp{ディレクトリ定義}
TOP_DIR           = ..\..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake
OBJS_DIR          = objs_$(TARGET)


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{インクルードパス設定}
INC_DIRS = $(INC_DIRS) $(KERNEL_DIR)\include


# %jp{オプションフラグの追加}
CFLAGS  = $(CFLAGS)
AFLAGS  = $(AFLAGS)
LNFLAGS = $(LNFLAGS)


# %jp{リンク制御対象制御}
LINK_MN103SC = Yes


all: makelib_all

clean: makelib_clean
	-$(CMD_RM) -f *.lst


# %jp{コンパイラ依存の設定読込み}
!include $(KERNEL_MAKINC_DIR)\cc103_d.inc

# %jp{共通設定読込み}
!include $(KERNEL_MAKINC_DIR)\makelib.inc
!include $(HOSAPLFW_MKINK_DIR)\aplfwsrc.inc


# %jpMコンパイラ依存のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\cc103_r.inc

# %jp{依存関係定義読込み}
!include $(HOSAPLFW_MKINK_DIR)\aplfwdep.inc


# end of file
