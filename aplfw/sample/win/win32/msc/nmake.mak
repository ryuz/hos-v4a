# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = sample

# %jp{ディレクトリ}
OS_DIR             = ..\..\..\..\..
KERNEL_DIR         = $(OS_DIR)\kernel
KERNEL_CFGRTR_DIR  = $(OS_DIR)\cfgrtr\build\msc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)\build\common\nmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)\build\win\win32\msc
HOSAPLFW_DIR       = $(OS_DIR)\aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)\build\win\win32\msc


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-win32


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfw.lib


# %jp{デバッグ版の定義変更}
!if "$(DEBUG)" == "Yes"
TARGET       = $(TARGET)dbg
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfwdbg.lib
!endif



# %jp{フラグ設定}
CFLAGS  = 
AFLAGS  = 
LNFLAGS = /MTd


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)


# %jp{コンパイラ依存の設定読込み}
!include $(KERNEL_MAKINC_DIR)\msc_d.inc

# %jp{実行ファイル生成共通定義の読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS = $(INC_DIRS) $(HOSAPLFW_INC_DIR)


# %jp{ソースディレクトリ}
SRC_DIRS = $(SRC_DIRS) . ..


# %jp{アセンブラファイルの追加}
ASRCS = $(ASRCS)

# %jp{C言語ファイルの追加}
CSRCS = $(CSRCS) ..\kernel_cfg.c
CSRCS = $(CSRCS) ..\main.c
CSRCS = $(CSRCS) ..\boot.c
CSRCS = $(CSRCS) ..\ostimer.c
CSRCS = $(CSRCS) ..\wintimer.c

# %jp{オブジェクトファイルの追加}
OBJS = $(OBJS) $(OBJS_DIR)\kernel_cfg.obj
OBJS = $(OBJS) $(OBJS_DIR)\main.obj
OBJS = $(OBJS) $(OBJS_DIR)\boot.obj
OBJS = $(OBJS) $(OBJS_DIR)\ostimer.obj
OBJS = $(OBJS) $(OBJS_DIR)\wintimer.obj


# %jp{ライブラリファイルの追加}
LIBS = $(LIBS) $(HOSAPLFW_LIB) kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib ws2_32.lib



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

all: make_subproject makeexe_all $(OBJS_DIR)\kernel_cfg.c srcobjcp $(TARGET_EXE)

make_subproject:
	$(CMD_CD) $(HOSAPLFW_BUILD_DIR)
	$(MAKE) -f nmake.mak
	$(CMD_CD) $(MAKEDIR)

clean: makeexe_clean
	-$(CMD_RM) $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ..\kernel_cfg.c ..\kernel_id.h

mostlyclean: clean kernel_clean
	$(CMD_CD) $(HOSAPLFW_BUILD_DIR)
	$(MAKE) -f nmake.mak clean
	$(CMD_CD) $(MAKEDIR)


..\kernel_cfg.c ..\kernel_id.h: ..\system.cfg
	cl /E ..\system.cfg > ..\system.i
	$(KERNEL_CFGRTR) ..\system.i -c ..\kernel_cfg.c -i ..\kernel_id.h

$(OBJS_DIR)\kernel_cfg.c: ..\kernel_cfg.c
	$(CMD_CP) ..\kernel_cfg.c $(OBJS_DIR)
	$(CMD_CP) ..\kernel_id.h $(OBJS_DIR)


# %jp{実行ファイル生成共通ルールの読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_r.inc

# %jp{MS-C用のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\msc_r.inc



# %jp{コピー}
srcobjcp:
	$(CMD_CP) ..\*.* $(OBJS_DIR)



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)\kernel_cfg.obj	:	$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h
$(OBJS_DIR)\main.obj		:	$(OBJS_DIR)\main.c       ..\kernel_id.h
$(OBJS_DIR)\sample.obj		:	$(OBJS_DIR)\sample.c     ..\kernel_id.h ..\sample.h
$(OBJS_DIR)\ostimer.obj		:	$(OBJS_DIR)\ostimer.c    ..\kernel_id.h ..\ostimer.h
$(OBJS_DIR)\wintimer.obj	:	$(OBJS_DIR)\wintimer.c   ..\kernel_id.h ..\wintimer.h



# end of file
