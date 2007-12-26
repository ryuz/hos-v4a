# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2-sample
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

# %jp{ターゲット名}
TARGET ?= sample

# %jp{ツール定義}
GCC_SYS    ?= elf
CMD_CC     ?= sh-$(GCC_SYS)-gcc
CMD_ASM    ?= sh-$(GCC_SYS)-gcc
CMD_LINK   ?= sh-$(GCC_SYS)-gcc
CMD_OBJCNV ?= sh-$(GCC_SYS)-objcopy


# %jp{ディレクトリ定義}
TOP_DIR            = ../../../../..
KERNEL_DIR         = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR  = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)/build/sh/sh2/gcc
HOSAPLFW_DIR       = $(TOP_DIR)/aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)/build/sh/sh2/gcc
OBJS_DIR           = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-sh2


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfw.$(EXT_LIB)


# %jp{メモリマップ}
ifeq ($(MEMMAP),ext)
# %jp{外部メモリ(モニタプログラム利用を想定)}
TARGET     := $(TARGET)ext
LINK_SCRIPT = link_ext.x
else
# %jp{ROM実行}
LINK_SCRIPT = link_rom.x
endif


# %jp{デバッグ版の定義変更}
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfwdbg.$(EXT_LIB)
endif


# %jp{フラグ設定}
CFLAGS  = -m2
AFLAGS  = -m2
LNFLAGS = -m2 -nostartfiles -Wl,-Map,$(TARGET).map,-T$(LINK_SCRIPT)


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)


# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS += $(HOSAPLFW_INC_DIR)


# %jp{ソースディレクトリ}
SRC_DIRS += . ..


# %jp{アセンブラファイルの追加}
ASRCS += ./vector.S			\
         ./crt0.S

# %jp{C言語ファイルの追加}
CSRCS += ../kernel_cfg.c	\
         ../main.c			\
         ../sample.c		\
         ../ostimer.c

# %jp{ライブラリの追加}
LIBS  += $(HOSAPLFW_LIB)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: make_libs makeexe_all $(TARGET_EXE) $(TARGET_MOT)

.PHONY : make_libs
make_libs:
	make -C $(HOSAPLFW_BUILD_DIR) -f gmake.mak

.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

.PHONY : mostlyclean
mostlyclean: clean kernel_clean
	make -C $(HOSAPLFW_BUILD_DIR) -f gmake.mak clean

.PHONY : depend
depend: makeexe_depend

.PHONY : mostlydepend
mostlydepend: depend kernel_depend
	make -C $(HOSAPLFW_BUILD_DIR) -f gmake.mak depend

.PHONY : srccpy
srccpy: makeexe_srccpy
	make -C $(KERNEL_BUILD_DIR) -f gmake.mak srccpy
	make -C $(HOSAPLFW_BUILD_DIR) -f gmake.mak srccpy

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makeexe.inc


# %jp{shc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/gcc_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.$(EXT_OBJ): ../sample.c ../kernel_id.h


# end of file

