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


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{インクルードパス設定}
INC_DIRS = $(INC_DIRS) $(KERNEL_DIR)\include


# %jp{オプションフラグ}
CFLAGS  = 
AFLAGS  = 
ARFLAGS = 


# %jp{リンク制御対象制御}
LINK_MN103SC = Yes


# %jp{コンパイラ依存の設定読込み}
!include $(KERNEL_MAKINC_DIR)\cc103_d.inc

# %jp{共通設定読込み}
!include $(KERNEL_MAKINC_DIR)\maklib_d.inc


all: makelib_all

clean: makelib_clean
	-$(CMD_RM) *.lst


# %jp{HOS-APLFWソース設定読込み}
!include $(HOSAPLFW_MKINK_DIR)\aplfwsrc.inc

# %jp{共通設定読込み}
!include $(KERNEL_MAKINC_DIR)\maklib_r.inc

# %jpMコンパイラ依存のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\cc103_r.inc

# %jp{依存関係定義読込み}
!include $(HOSAPLFW_MKINK_DIR)\aplfwdep.inc


# end of file
