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


# %jp{オプションフラグ}
CFLAGS = $(CFLAGS)
AFLAGS = $(AFLAGS)
LFLAGS = $(LFLAGS)


# %jp{リンク制御対象制御}
LINK_WINSOCK = Yes



all: makelib_all

clean: makelib_clean
	$(RM) -f *.lst


# %jp{MS-C用の設定読込み}
!include $(KERNEL_MAKINC_DIR)\msc_d.inc

# %jp{共通設定読込み}
!include $(KERNEL_MAKINC_DIR)\makelib.inc
!include $(HOSAPLFW_MKINK_DIR)\aplfwsrc.inc


# %jp{MS-C用のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\msc_r.inc

# %jp{依存関係定義読込み}
!include $(HOSAPLFW_MKINK_DIR)\aplfwdep.inc


# end of file
