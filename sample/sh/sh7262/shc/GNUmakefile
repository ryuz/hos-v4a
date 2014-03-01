# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2-sample
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲット名}%en{target name}
TARGET ?= sample


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= sh2a-fpu
ARCH_CC   ?= shc


# %jp{ディレクトリ定義}%en{directories}
OS_DIR            = ../../../..
KERNEL_DIR        = $(OS_DIR)/kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/sh/sh2a-fpu/shc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-$(ARCH_NAME)


# %jp{共通定義読込み}%jp{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


ifeq ($(MEMMAP),rom)
# %jp{ROM焼きする場合}%en{internal ROM}
TARGET := $(TARGET)_rom
SECTION_VECT ?= 000000000
SECTION_RO   ?= 000000800
SECTION_RW   ?= 01c000000
else
# %jp{RAM実行}%en{external RAM}
TARGET := $(TARGET)
SECTION_VECT ?= 01c000000
SECTION_RO   ?= 01c000800
SECTION_RW   ?= 01c028000
endif


# %jp{パス設定}%en{add source directories}
INC_DIRS += . ..
SRC_DIRS += . ..


# %jp{オプションフラグ}%en{option flags}
AFLAGS  = -CPu=sh2afpu
CFLAGS  = -CPu=sh2afpu
LNFLAGS = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc


# %jp{出力ファイル名}%en{output files}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)

# %jp{Cライブラリ名の指定}%en{std library}
STD_LIBS = stdlib.lib




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += ./vcttbl.src
ASRCS += ./startup.src


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += ./dbsct.c
CSRCS += ../kernel_cfg.c
CSRCS += ../main.c
CSRCS += ../sample.c
CSRCS += ../ostimer.c
CSRCS += ../sci1.c


# %jp{ライブラリの追加}%en{library}
LIBS  += $(STD_LIBS)




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: makeexe_all $(TARGET_EXE) $(TARGET_MOT)

# %jp{クリーン}%en{clean}
.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

# %jp{依存関係更新}%en{depend}
.PHONY : depend
depend: makeexe_depend

# %jp{ソース一括コピー}%en{source files copy}
.PHONY : srccpy
srccpy: makeexe_srccpy

# %jp{カーネルごとクリーン}%en{mostlyclean}
.PHONY : mostlyclean
mostlyclean: clean kernel_clean


# %jp{標準ライブラリ}%en{std library}
$(STD_LIBS):
	lbgsh -OUTPut=$(STD_LIBS) -CPu=sh2 -REent


# %jp{コンフィギュレータ実行}%en{configurator}
../kernel_cfg.c ../kernel_id.h: ../system.cfg $(KERNEL_CFGRTR)
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


# %jp{実行ファイル生成用設定読込み}%en{setting for execute file}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{shc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/shc_r.inc



# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file

