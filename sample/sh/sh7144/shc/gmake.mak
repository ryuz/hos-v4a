# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2-sample
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

# %jp{ターゲット名}
TARGET ?= sample

# %jp{ディレクトリ定義}
OS_DIR            = ../../../..
KERNEL_DIR        = $(OS_DIR)/kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/sh/sh2/shc
OBJS_DIR          = objs_$(TARGET)

# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# デバッグ版のターゲット名変更
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
endif

ifeq ($(RAM),Yes)
# %jp{RAM実行(モニタプログラム利用を想定)}
TARGET := $(TARGET)_ram
SECTION_VECT ?= 000400000
SECTION_ROM  ?= 000400400
SECTION_RAM  ?= 000410000
else
# %jp{ROM焼きする場合}
TARGET := $(TARGET)
SECTION_VECT ?= 000000000
SECTION_ROM  ?= 000000400
SECTION_RAM  ?= 0FFFFE000
endif


# %jp{フラグ設定}
CFLAGS  = -CPu=sh2
AFLAGS  = -CPu=sh2
LNFLAGS = 


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-sh2

# Cライブラリ名の指定
STD_LIBS = stdlib.lib

# 出力ファイル名
TARGET_EXE = $(TARGET).abs
TARGET_ASC = $(TARGET).mot


# %jp{shc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/shc_def.inc

# ソースディレクトリ
SRC_DIRS += . ..

# アセンブラファイルの追加
ASRCS += ./vcttbl.src		\
         ./startup.src		\

#         ./sim_io.src

# %jp{C言語ファイルの追加}
CSRCS += ./dbsct.c			\
         ../kernel_cfg.c	\
         ../main.c			\
         ../sample.c		\
         ../ostimer.c		\
         ../sci1.c

# %jp{ライブラリの追加}
LIBS  += $(STD_LIBS)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: makeexe_all $(TARGET_EXE) $(TARGET_ASC)

clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

$(STD_LIBS):
	lbgsh -OUTPut=$(STD_LIBS) -CPu=sh2 -REent

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makeexe.inc

# %jp{shc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/shc_rul.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file

