# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= sample

# %jp{ディレクトリ}
TOP_DIR             = ../../../../..
KERNEL_DIR          = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR   = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR   = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR    = $(KERNEL_DIR)/build/mn103/mn103s/cc103
HOSAPLFW_DIR        = $(TOP_DIR)/aplfw
HOSAPLFW_INC_DIR    = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR  = $(HOSAPLFW_DIR)/build/mn103/mn103s/cc103
OBJS_DIR            = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-mn103s


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfw.$(EXT_LIB)



# %jp{デバッグ版の定義変更}
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfwdbg.$(EXT_LIB)
endif


# %jp{フラグ設定}
CFLAGS  = 
AFLAGS  = 
LNFLAGS = -g -Qld=-m -Qld=-Rl -Qld=-T@CODE=0x40000000 -Qld=-T@DATA=0x00000004


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_BIN = $(TARGET).$(EXT_BIN)


# %jp{実行ファイル生成用の設定読込み}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc

# %jp{コンパイラ依存の設定読込み}
include $(KERNEL_MAKINC_DIR)/cc103_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS += $(HOSAPLFW_INC_DIR)

# %jp{ソースディレクトリ}
SRC_DIRS += . ..


# %jp{アセンブラファイルの追加}
ASRCS += ./startup.as		\


# %jp{C言語ファイルの追加}
CSRCS += ../kernel_cfg.c	\
         ../main.c			\
         ../boot.c			\
         ../ostimer.c


# %jp{ライブラリファイルの追加}
LIBS     += $(HOSAPLFW_LIB)
STD_LIBS += C:/PanaX/CC103S/LIB/CC103S.L



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: make_libs makeexe_all $(TARGET_EXE)


.PHONY : make_libs
make_libs:
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR)

.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../system.i ../kernel_cfg.c ../kernel_id.h

.PHONY : mostlyclean
mostlyclean: clean kernel_clean
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) clean

.PHONY : depend
depend: makeexe_depend

.PHONY : mostlydepend
mostlydepend: depend kernel_depend
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) depend

.PHONY : srccpy
srccpy: makeexe_srccpy

.PHONY : mostlysrccpy
mostlysrccpy: srccpy srccpy
	$(MAKE) -C $(KERNEL_BUILD_DIR) srccpy
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) srccpy


../kernel_cfg.c ../kernel_id.h: ../system.cfg $(KERNEL_CFGRTR)
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



# %jp{実行ファイル生成用ルール読込み}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{コンパイラ依存ルール定義読込み}
include $(KERNEL_MAKINC_DIR)/cc103_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h



# end of file
