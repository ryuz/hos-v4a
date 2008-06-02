# ----------------------------------------------------------------------------
# Hyper Operating System  Application Framework
#  makefile for MN103S
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= hosaplfw


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= mn103s
ARCH_CC   ?= cc103


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR            = ../../../../..
KERNEL_DIR         = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)/build/common/gmake
HOSAPLFW_DIR       = $(TOP_DIR)/aplfw
HOSAPLFW_MKINK_DIR = $(HOSAPLFW_DIR)/build/common/gmake


# %jp{共通定義読込み}%en{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{パス設定}%en{add source directories}
INC_DIRS += $(APLFW_DIR) $(KERNEL_DIR)/include
SRC_DIRS += 


# %jp{オプションフラグ}%en{option flags}
AFLAGS  =
CFLAGS  =
ARFLAGS =

# %jp{リンク制御対象制御}
LINK_MN103SC = Yes


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS +=

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS +=


# %jp{HOSAPLFW共通ソースファイル定義}%en{HOSAPLFW common sorce files}
include $(HOSAPLFW_MKINK_DIR)/aplfwsrc.inc




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: makelib_all

# %jp{クリーン}%en{clean}
.PHONY : clean
clean: makelib_clean

# %jp{依存関係更新}%en{make depend}
.PHONY : depend
depend: makelib_depend

# %jp{ソース一括コピー}%en{source files copy}
.PHONY : srccpy
srccpy: makelib_srccpy


# %jp{ライブラリ生成用設定読込み}%en{rules for library}
include $(KERNEL_MAKINC_DIR)/maklib_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc



# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------


# %jp{HOSAPLFW共通依存関係定義}%en{HOSAPLFW depend}
include $(HOSAPLFW_MKINK_DIR)/aplfwdep.inc


# end of file
