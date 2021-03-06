# ----------------------------------------------------------------------------
# Hyper Operating System  Application Framework
#  makefile for Jelly
#
# Copyright (C) 1998-2011 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# --------------------------------------
#  %jp{各種設定}%en{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= hosaplfw


# %jp{ツール定義}%jp{tools}
GCC_ARCH ?= mips-elf-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR            = ../../../../..
KERNEL_DIR         = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)/build/common/gmake
HOSAPLFW_DIR       = $(TOP_DIR)/aplfw
HOSAPLFW_MKINK_DIR = $(HOSAPLFW_DIR)/build/common/gmake


# %jp{共通定義読込み}%en{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{パス設定}%en{add source directories}
INC_DIRS += $(HOSAPLFW_DIR) $(KERNEL_DIR)/include
SRC_DIRS += $(DRV_SERIAL_DIR)


# %jp{オプションフラグ}%en{option flags}
AFLAGS  = -march=mips1 -msoft-float -G 0
CFLAGS  = -march=mips1 -msoft-float -G 0
ARFLAGS = 

# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/gcc_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += 

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS +=


# %jp{リンク制御対象制御}
LINK_JELLYUART     = Yes
LINK_JELLYI2C      = Yes
LINK_XILINXUARTDRV = Yes

# %jp{共通ソース}
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
	$(RM) -f *.lst

# %jp{依存関係更新}%en{make depend}
.PHONY : depend
depend: makelib_depend

# %jp{ソース一括コピー}%en{source files copy}
.PHONY : srccpy
srccpy: makelib_srccpy


# %jp{ライブラリ生成用設定読込み}%en{rules for library}
include $(KERNEL_MAKINC_DIR)/maklib_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/gcc_r.inc



# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------


# %jp{依存関係定義読込み}
include $(HOSAPLFW_MKINK_DIR)/aplfwdep.inc


# end of file
