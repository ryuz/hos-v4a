# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}%en{target name}
TARGET = sample

# %jp{ディレクトリ}{directories}
OS_DIR             = ..\..\..\..\..
KERNEL_DIR         = $(OS_DIR)\kernel
KERNEL_CFGRTR_DIR  = $(OS_DIR)\cfgrtr\build\msc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)\build\common\nmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)\build\mn103\mn103s\cc103
HOSAPLFW_DIR       = $(OS_DIR)\aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)\build\mn103\mn103s\cc103


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-mn103s


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfw.l


# %jp{デバッグ版の定義変更}
!if "$(DEBUG)" == "Yes"
TARGET       = $(TARGET)dbg
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfwdbg.l
!endif



# %jp{フラグ設定}
CFLAGS  = $(CFLAGS)
AFLAGS  = $(AFLAGS)
LNFLAGS = $(LNFLAGS) -g -Qld=-m -Qld=-Rl -Qld=-T@CODE=0x40000000 -Qld=-T@DATA=0x00000004


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_BIN = $(TARGET).$(EXT_BIN)


# %jp{コンパイラ依存の設定読込み}
!include $(KERNEL_MAKINC_DIR)\cc103_d.inc

# %jp{実行ファイル生成共通定義の読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS = $(INC_DIRS) $(HOSAPLFW_INC_DIR)


# %jp{ソースディレクトリ}
SRC_DIRS = $(SRC_DIRS) . ..


# %jp{アセンブラファイルの追加}
ASRCS = $(ASRCS) .\startup.as


# %jp{C言語ファイルの追加}
CSRCS = $(CSRCS) ..\kernel_cfg.c
CSRCS = $(CSRCS) ..\main.c
CSRCS = $(CSRCS) ..\boot.c
CSRCS = $(CSRCS) ..\ostimer.c


# %jp{オブジェクトファイルの追加}
OBJS = $(OBJS) $(OBJS_DIR)\kernel_cfg.ro
OBJS = $(OBJS) $(OBJS_DIR)\main.ro
OBJS = $(OBJS) $(OBJS_DIR)\boot.ro
OBJS = $(OBJS) $(OBJS_DIR)\ostimer.ro


# %jp{ライブラリファイルの追加}
LIBS = $(LIBS) $(HOSAPLFW_LIB)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

all: make_subproject makeexe_all $(OBJS_DIR)\kernel_cfg.c srcobjcp $(TARGET_EXE)

make_subproject:
	$(CMD_CD) $(HOSAPLFW_BUILD_DIR)
	$(MAKE)
	$(CMD_CD) $(MAKEDIR)

clean: makeexe_clean
	-$(CMD_RM) $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ..\kernel_cfg.c ..\kernel_id.h

mostlyclean: clean kernel_clean
	$(CMD_CD) $(HOSAPLFW_BUILD_DIR)
	$(MAKE) clean
	$(CMD_CD) $(MAKEDIR)


..\kernel_cfg.c ..\kernel_id.h: ..\system.cfg
	cl /E ..\system.cfg > ..\system.i
	$(KERNEL_CFGRTR) ..\system.i -c ..\kernel_cfg.c -i ..\kernel_id.h

$(OBJS_DIR)\kernel_cfg.c: ..\kernel_cfg.c
	$(CMD_CP) ..\kernel_cfg.c $(OBJS_DIR)
	$(CMD_CP) ..\kernel_id.h $(OBJS_DIR)


# %jp{実行ファイル生成共通ルールの読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_r.inc

# %jp{コンパイラ依存のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\cc103_r.inc



# %jp{コピー}
srcobjcp:
	$(CMD_CP) ..\*.* $(OBJS_DIR)



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)\kernel_cfg.ro	:	$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h
$(OBJS_DIR)\main.ro			:	$(OBJS_DIR)\main.c       ..\kernel_id.h
$(OBJS_DIR)\boot.ro			:	$(OBJS_DIR)\boot.c       ..\kernel_id.h ..\boot.h
$(OBJS_DIR)\ostimer.ro		:	$(OBJS_DIR)\ostimer.c    ..\kernel_id.h ..\ostimer.h
$(OBJS_DIR)\wintimer.ro		:	$(OBJS_DIR)\wintimer.c   ..\kernel_id.h ..\wintimer.h



# end of file
