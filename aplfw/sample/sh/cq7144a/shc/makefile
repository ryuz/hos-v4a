# ----------------------------------------------------------------------------
# Hyper Operating System  Application Framework
#
# Copyright (C) 2007-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}%en{target name}
TARGET = sample

# %jp{ディレクトリ}{directories}
OS_DIR             = ..\..\..\..\..
KERNEL_DIR         = $(OS_DIR)\kernel
KERNEL_CFGRTR_DIR  = $(OS_DIR)\cfgrtr\build\msc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)\build\common\nmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)\build\sh\sh2\shc
HOSAPLFW_DIR       = $(OS_DIR)\aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)\build\sh\sh2\shc


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-sh2


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfw.$(EXT_LIB)
STD_LIBS     = stdlib.lib


# %jp{デバッグ版の定義変更}
!if "$(DEBUG)" == "Yes"
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfwdbg.$(EXT_LIB)
!endif


# %jp{メモリマップ}
!if "$(MEMMAP)" == "ext"
# %jp{外部メモリ}
TARGET       = $(TARGET)ext
SECTION_VECT = 00400000
SECTION_RO  = 00400400
SECTION_RW  = 00410000
!else
# %jp{内蔵ROMメモリ}
SECTION_VECT = 00000000
SECTION_RO  = 00000400
SECTION_RW  = 00400000
!endif



# %jp{フラグ設定}
CFLAGS  = $(CFLAGS) -CP=sh2 -DEBug -NOLOGO
AFLAGS  = $(AFLAGS) -CP=sh2 -DEBug -NOLOGO
LNFLAGS = $(LNFLAGS)


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)


# %jp{コンパイラ依存の設定読込み}
!include $(KERNEL_MAKINC_DIR)\shc_d.inc

# %jp{実行ファイル生成共通定義の読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS = $(INC_DIRS) $(HOSAPLFW_INC_DIR)


# %jp{ソースディレクトリ}
SRC_DIRS = $(SRC_DIRS) . ..


# %jp{アセンブラファイルの追加}
ASRCS = $(ASRCS) .\vcttbl.src
ASRCS = $(ASRCS) .\startup.src


# %jp{C言語ファイルの追加}
CSRCS = $(CSRCS) .\dbsct.c
CSRCS = $(CSRCS) ..\kernel_cfg.c
CSRCS = $(CSRCS) ..\main.c
CSRCS = $(CSRCS) ..\boot.c
CSRCS = $(CSRCS) ..\ostimer.c


# %jp{オブジェクトファイルの追加}
OBJS = $(OBJS) $(OBJS_DIR)\vcttbl.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\startup.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kernel_cfg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\main.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\boot.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ostimer.$(EXT_OBJ)


# %jp{ライブラリファイルの追加}
LIBS = $(LIBS) $(HOSAPLFW_LIB) $(STD_LIBS)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

all: make_subproject makeexe_all $(OBJS_DIR)\kernel_cfg.c srcobjcp $(TARGET_EXE) $(TARGET_MOT)

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

$(STD_LIBS):
	lbgsh -OUTPut=$(STD_LIBS) -CP=sh2


# %jp{実行ファイル生成共通ルールの読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_r.inc

# %jp{コンパイラ依存のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\shc_r.inc



# %jp{コピー}
srcobjcp:
	$(CMD_CP) .\*.src $(OBJS_DIR)
	$(CMD_CP) .\*.c $(OBJS_DIR)
	$(CMD_CP) ..\*.c $(OBJS_DIR)
	$(CMD_CP) ..\*.h $(OBJS_DIR)



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)\kernel_cfg.$(EXT_OBJ)	:	$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h
$(OBJS_DIR)\main.$(EXT_OBJ)			:	$(OBJS_DIR)\main.c       ..\kernel_id.h
$(OBJS_DIR)\boot.$(EXT_OBJ)			:	$(OBJS_DIR)\boot.c       ..\kernel_id.h ..\boot.h
$(OBJS_DIR)\ostimer.$(EXT_OBJ)		:	$(OBJS_DIR)\ostimer.c    ..\kernel_id.h ..\ostimer.h
$(OBJS_DIR)\wintimer.$(EXT_OBJ)		:	$(OBJS_DIR)\wintimer.c   ..\kernel_id.h ..\wintimer.h



# end of file
