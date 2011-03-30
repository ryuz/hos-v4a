# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= sample


# %jp{ディレクトリ}
TOP_DIR            = ../../../../..
KERNEL_DIR         = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR  = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)/build/h8/h8300ha/ch38
HOSAPLFW_DIR       = $(TOP_DIR)/aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)/build/h8/h8300ha/ch38
OBJS_DIR           = objs_$(TARGET)

# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc

# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-h8300ha


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfw.$(EXT_LIB)
STD_LIBS  = stdlib.lib


# %jp{メモリマップ}
ifeq ($(MEMMAP),ext)
# %jp{外部メモリ}
TARGET := $(TARGET)ext
ADDR_VECT = 0FFC040
ADDR_ROM  = 0400000
ADDR_RAM  = 0410000
else
# %jp{内蔵ROMメモリ}
ADDR_VECT = 0000000
ADDR_ROM  = 0000100
ADDR_RAM  = 0400000
endif


# %jp{デバッグ版の定義変更}
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfwdbg.$(EXT_LIB)
endif


# %jp{フラグ設定}
CFLAGS  = -CP=300HA:24
AFLAGS  = -CP=300HA:24
LNFLAGS = 



# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)


# %jp{実行ファイル生成用の設定読込み}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc

# %jp{ch38用の設定読込み}
include $(KERNEL_MAKINC_DIR)/ch38_d.inc



# %jp{インクルードディレクトリ}
INC_DIRS += $(HOSAPLFW_INC_DIR)

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
         ../ostimer.c


# %jp{ライブラリファイルの追加}
LIBS += $(HOSAPLFW_LIB) $(STD_LIBS)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: make_libs makeexe_all $(TARGET_EXE) $(TARGET_MOT)


.PHONY : make_libs
make_libs:
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR)

.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

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
	$(MAKE) -C $(KERNEL_BUILD_DIR) srccpy
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) srccpy


$(STD_LIBS):
	lbg38 -OUTPut=$(STD_LIBS) $(CFLAGS) -REent 


../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



# %jp{実行ファイル生成用ルール読込み}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{ch38用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/ch38_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file
