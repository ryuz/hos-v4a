# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET = hosaplfw


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME = win32
ARCH_CC   = msc


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR            = ..\..\..\..\..
KERNEL_DIR         = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)\build\common\nmake
HOSAPLFW_DIR       = $(TOP_DIR)\aplfw
HOSAPLFW_MKINK_DIR = $(HOSAPLFW_DIR)/build\common\nmake


# %jp{共通定義読込み}%jp{common setting}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{パス設定}%en{add source directories}
SRC_DIR  = 
INC_DIRS = $(KERNEL_DIR)\include


# %jp{オプションフラグ}%en{option flags}
AFLAGS  = 
CFLAGS  = 
ARFLAGS = 


# %jp{リンク制御対象制御}%en{link subsystem}
LINK_WINSOCK = Yes



# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
!include $(KERNEL_MAKINC_DIR)\maklib_d.inc




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{HOS-APLFWソース設定読込み}%en{common source files}
!include $(HOSAPLFW_MKINK_DIR)\aplfwsrc.inc




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------


# %jp{ALL}%en{all}
all: makelib_all

# %jp{クリーン}%en{clean}
clean: makelib_clean
	-$(CMD_RM) *.lst


# %jp{ライブラリ生成用設定読込み}%en{rules for library}
!include $(KERNEL_MAKINC_DIR)\maklib_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_r.inc




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

# %jp{依存関係定義読込み}%en{dependency list}
!include $(HOSAPLFW_MKINK_DIR)\aplfwdep.inc



# end of file
