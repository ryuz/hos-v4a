# ----------------------------------------------------------------------------
# Hyper Operating System  Application Framework
#
# Copyright (C) 2007-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= sample

# %jp{ディレクトリ}
TOP_DIR             = ../../../../..
KERNEL_DIR          = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR   = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR   = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR    = $(KERNEL_DIR)/build/sh/sh2/shc
HOSAPLFW_DIR        = $(TOP_DIR)/aplfw
HOSAPLFW_INC_DIR    = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR  = $(HOSAPLFW_DIR)/build/sh/sh2/shc
OBJS_DIR            = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-sh2


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfw.$(EXT_LIB)
STD_LIBS  = stdlib.lib


# %jp{メモリマップ}
ifeq ($(MEMMAP),ext)
# %jp{外部メモリ}
TARGET       := $(TARGET)ext
SECTION_VECT ?= 00400000
SECTION_RO  ?= 00400400
SECTION_RW  ?= 00410000
else
# %jp{内蔵ROMメモリ}
SECTION_VECT ?= 00000000
SECTION_RO  ?= 00000400
SECTION_RW  ?= 00400000
endif


# %jp{デバッグ版の定義変更}
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfwdbg.$(EXT_LIB)
endif


# %jp{フラグ設定}
CFLAGS  += -CP=sh2 -DEBug -NOLOGO
AFLAGS  += -CP=sh2 -DEBug -NOLOGO
LNFLAGS += 


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)


# %jp{実行ファイル生成用の設定読込み}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc

# %jp{shc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/shc_d.inc


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
         ../boot.c			\
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
	lbgsh -OUTPut=$(STD_LIBS) -CP=sh2
#	lbgsh -OUTPut=$(STD_LIBS) -CP=sh2 -REent 


../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



# %jp{実行ファイル生成用ルール読込み}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{shc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/shc_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file
