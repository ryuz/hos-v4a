# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
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
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/h8/h8300ha/ch38
OBJS_DIR          = objs_$(TARGET)
KERNEL_CFGRTR     = $(KERNEL_CFGRTR_DIR)/h4acfg-h8300ha

# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


ifeq ($(MEMMAP),ram)
# %jp{RAM実行(モニタプログラム利用を想定)}
TARGET := $(TARGET)_ram
SECTION_VECT = 0FFC040
SECTION_RO  = 0FFC140
SECTION_RW  = 0FFE140
else
SECTION_VECT = 0
SECTION_RO  = 0100
SECTION_RW  = 0FFE140
endif

# %jp{フラグ設定}
CFLAGS  = -CP=300HA -DEBug
AFLAGS  = -CP=300HA -DEBug
LNFLAGS = 


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)

# %jp{標準ライブラリ}
STD_LIB = stdlib.lib

# %jp{ch38用の設定読込み}
include $(KERNEL_MAKINC_DIR)/ch38_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc


# --------------------------------------
#  %jp{ファイル設定}
# --------------------------------------

# %jp{ソースディレクトリ}
SRC_DIRS += . ..

# %jp{アセンブラファイルの追加}
ASRCS += ./vcttbl.src		\
         ./startup.src		\


# %jp{C言語ファイルの追加}
CSRCS += ./dbsct.c			\
         ../kernel_cfg.c	\
         ../main.c			\
         ../sample.c		\
         ../ostimer.c		\
         ../sci1.c


# %jp{ライブラリの追加}
LIBS  += $(STD_LIB)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: makeexe_all $(TARGET_EXE) $(TARGET_MOT)


.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_MOT) $(OBJS) ../kernel_cfg.c ../kernel_id.h


.PHONY : mostlyclean
mostlyclean: clean clean_kernel

$(STD_LIB):
	lbg38 -OUTPut=$(STD_LIB) $(CFLAGS) -REent 

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{ch38用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/ch38_r.inc


# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.$(EXT_OBJ): ../sample.c ../kernel_id.h



# end of file
