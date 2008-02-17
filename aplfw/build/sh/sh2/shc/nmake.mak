# ----------------------------------------------------------------------------
# Hyper Operating System  Application Framework
#
# Copyright (C) 2007-2008 by Project HOS
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
LINK_RENESUSSCI = Yes


# %jp{コンパイラ依存の設定読込み}
!include $(KERNEL_MAKINC_DIR)\shc_d.inc

# %jp{共通設定読込み}
!include $(HOSAPLFW_MKINK_DIR)\aplfwsrc.inc


# %jp{ALL}%en{all}
all: makelib_all


# %jp{クリーン}%en{clean}
clean: makelib_clean



# %jp{ライブラリ生成用設定読込み}%en{rules of library}
!include $(KERNEL_MAKINC_DIR)\makelib.inc

# %jpMコンパイラ依存のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\shc_r.inc

# %jp{依存関係定義読込み}
!include $(HOSAPLFW_MKINK_DIR)\aplfwdep.inc


# end of file
