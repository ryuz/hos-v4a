# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2-sample
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = sample

# %jp{ディレクトリ定義}
OS_DIR            = ..\..\..\..
KERNEL_DIR        = $(OS_DIR)\kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)\cfgrtr\build\msc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)\build\win\win32\msc
OBJS_DIR          = objs_$(TARGET)

# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc

INC_DIRS = $(KERNEL_DIR)\include ..

# %jp{フラグ設定}
CFLAGS   = 
AFLAGS   = 
LNFLAGS  = winmm.lib


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-win32

# 出力ファイル名
TARGET_EXE = $(TARGET).$(EXT_EXE)


# %jp{gcc用の設定読込み}
!include $(KERNEL_MAKINC_DIR)\msc_d.inc

# %jp{ソースディレクトリ}
SRC_DIRS = $(SRC_DIRS) . ..

# %jp{オブジェクトファイルの追加}
OBJS = $(OBJS)						\
       $(OBJS_DIR)\kernel_cfg.obj	\
       $(OBJS_DIR)\main.obj			\
       $(OBJS_DIR)\sample.obj		\
       $(OBJS_DIR)\ostimer.obj		\
       $(OBJS_DIR)\wintimer.obj


# %jp{ライブラリの追加}
LIBS = $(LIBS)						\
       



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

all: makeexe_all srcobjcp $(TARGET_EXE)

clean: makeexe_clean
	$(CMD_RM) $(TARGET_EXE) $(OBJS) ..\kernel_cfg.c ..\kernel_id.h

..\kernel_cfg.c ..\kernel_id.h: ..\system.cfg
	cl /E ..\system.cfg > ..\system.i
	$(KERNEL_CFGRTR) ..\system.i -c ..\kernel_cfg.c -i ..\kernel_id.h


# %jp{ライブラリ生成用設定読込み}
!include $(KERNEL_MAKINC_DIR)\makeexe.inc

# %jp{shc用のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\msc_r.inc


# %jp{コピー}
srcobjcp:
	$(CMD_CP) ..\*.c $(OBJS_DIR)



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)\kernel_cfg.obj	:	$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h
$(OBJS_DIR)\main.obj		:	$(OBJS_DIR)\main.c       ..\kernel_id.h
$(OBJS_DIR)\sample.obj		:	$(OBJS_DIR)\sample.c     ..\kernel_id.h
$(OBJS_DIR)\ostimer.obj		:	$(OBJS_DIR)\ostimer.c    ..\kernel_id.h
$(OBJS_DIR)\wintimer.obj	:	$(OBJS_DIR)\wintimer.c   ..\kernel_id.h


# end of file

