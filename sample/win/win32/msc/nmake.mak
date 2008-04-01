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


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc

INC_DIRS = $(KERNEL_DIR)\include ..


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-win32


# %jp{フラグ設定}
CFLAGS   = 
AFLAGS   = 
LNFLAGS  = 


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)


# %jp{コンパイラ依存の設定読込み}
!include $(KERNEL_MAKINC_DIR)\msc_d.inc

# %jp{実行ファイル生成共通定義の読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS = $(INC_DIRS) 


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
LIBS = $(LIBS) kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib




# --------------------------------------
#  %jp{ルール}
# --------------------------------------

all: makeexe_all srcobjcp $(TARGET_EXE)

clean: makeexe_clean
	$(CMD_RM) $(TARGET_EXE) $(OBJS) ..\kernel_cfg.c ..\kernel_id.h

$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h: ..\system.cfg
	cl /E ..\system.cfg > ..\system.i
	$(KERNEL_CFGRTR) ..\system.i -c ..\kernel_cfg.c -i ..\kernel_id.h
	$(CMD_CP) ..\kernel_cfg.c $(OBJS_DIR)\


# %jp{実行ファイル生成共通ルールの読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_r.inc

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
