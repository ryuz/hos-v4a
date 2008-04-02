# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲット名}%en{target name}
TARGET = sample


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME = win32
ARCH_CC   = msc


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR           = ..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_CFGRTR_DIR = $(TOP_DIR)\cfgrtr\build\msc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)\build\win\win32\msc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-$(ARCH_NAME)


# %jp{共通定義読込み}%jp{common setting}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{パス設定}%en{add source directories}
INC_DIRS = . ..
SRC_DIRS = . ..


# %jp{オプションフラグ}%en{option flags}
AFLAGS   = 
CFLAGS   = 
LNFLAGS  = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
!include $(KERNEL_MAKINC_DIR)\makexe_d.inc


# %jp{出力ファイル名}%en{output files}
TARGET_EXE = $(TARGET).$(EXT_EXE)




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS = $(CSRCS) ..\kernel_cfg.c
CSRCS = $(CSRCS) ..\main.c
CSRCS = $(CSRCS) ..\sample.c
CSRCS = $(CSRCS) ..\ostimer.c
CSRCS = $(CSRCS) ..\wintimer.c


# %jp{オブジェクトファイルの追加}%en{object files}
OBJS = $(OBJS) $(OBJS_DIR)\kernel_cfg.obj
OBJS = $(OBJS) $(OBJS_DIR)\main.obj
OBJS = $(OBJS) $(OBJS_DIR)\sample.obj
OBJS = $(OBJS) $(OBJS_DIR)\ostimer.obj
OBJS = $(OBJS) $(OBJS_DIR)\wintimer.obj


# %jp{ライブラリの追加}
LIBS = $(LIBS) user32.lib winmm.lib




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
all: makeexe_all srcobjcp $(TARGET_EXE)

# %jp{クリーン}%en{clean}
clean: makeexe_clean
	$(CMD_RM) $(TARGET_EXE) $(OBJS) ..\kernel_cfg.c ..\kernel_id.h

# %jp{カーネルごとクリーン}%en{mostlyclean}
mostlyclean: clean kernel_clean


# %jp{コンフィギュレータ実行}%en{configurator}
..\kernel_cfg.c ..\kernel_id.h: ..\system.cfg
	cl /E ..\system.cfg > ..\system.i
	$(KERNEL_CFGRTR) ..\system.i -c ..\kernel_cfg.c -i ..\kernel_id.h
	$(CMD_CP) ..\kernel_cfg.c $(OBJS_DIR)\


# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
!include $(KERNEL_MAKINC_DIR)\makexe_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_r.inc


# %jp{コピー}%en{copy}
srcobjcp:
	$(CMD_CP) ..\*.c $(OBJS_DIR)



# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

$(OBJS_DIR)\kernel_cfg.obj	:	$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h
$(OBJS_DIR)\main.obj		:	$(OBJS_DIR)\main.c       ..\kernel_id.h
$(OBJS_DIR)\sample.obj		:	$(OBJS_DIR)\sample.c     ..\kernel_id.h
$(OBJS_DIR)\ostimer.obj		:	$(OBJS_DIR)\ostimer.c    ..\kernel_id.h
$(OBJS_DIR)\wintimer.obj	:	$(OBJS_DIR)\wintimer.c   ..\kernel_id.h



# end of file
