# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= sample

# %jp{ディレクトリ定義}
OS_DIR            = ../../../..
KERNEL_DIR        = $(OS_DIR)/kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/arm/lpc2000/armcc
OBJS_DIR          = objs_$(TARGET)

# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# デバッグ版のターゲット名変更
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
endif

# %jp{メモリマップ}
ifeq ($(MEMMAP),ext)
# %jp{外部メモリ}
TARGET       := $(TARGET)ext
SECTION_RO  ?= 0x80000000
SECTION_RW  ?= 0x80010000
else
ifeq ($(MEMMAP),ram)
# %jp{内蔵RAM}
SECTION_RO  ?= 0x00000000
SECTION_RW  ?= 0x80010000
else
# %jp{内蔵ROM}
SECTION_RO  ?= 0x00000000
SECTION_RW  ?= 0x80010000
endif
endif


# %jp{フラグ設定}
CFLAGS  = --cpu=ARM7TDMI-S --apcs=inter --thumb
AFLAGS  = --cpu=ARM7TDMI-S --apcs=inter --thumb
LNFLAGS = --ro_base=$(SECTION_RO) --rw_base=$(SECTION_RW) --first=vectors.o --entry=$(SECTION_RO)


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-lpc2000


# 出力ファイル名
TARGET_EXE = $(TARGET).axf
TARGET_MOT = $(TARGET).mot
TARGET_HEX = $(TARGET).hex


# %jp{armcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/armcc_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc


# ソースディレクトリ
SRC_DIRS += . ..

# アセンブラファイルの追加
ASRCS += ./vectors.s		\
         ./startup.s		\
         ./uish.s


# %jp{C言語ファイルの追加}
CSRCS += ../kernel_cfg.c	\
         ../main.c			\
         ../sample.c		\
         ../ostimer.c		\
         ../uart.c



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: kernel_make makeexe_all $(TARGET_EXE) $(TARGET_MOT) $(TARGET_HEX)

clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{armcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/armcc_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file

