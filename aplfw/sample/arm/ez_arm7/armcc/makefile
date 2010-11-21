# ----------------------------------------------------------------------------
# Hyper Operating System
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = sample

# %jp{ディレクトリ}
OS_DIR             = ..\..\..\..\..
KERNEL_DIR         = $(OS_DIR)\kernel
KERNEL_CFGRTR_DIR  = $(OS_DIR)\cfgrtr\build\msc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)\build\common\nmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)\build\arm\lpc2000\armcc
HOSAPLFW_DIR       = $(OS_DIR)\aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)\build\arm\arm_v4t\armcc


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-lpc2000


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfw.$(EXT_LIB)


# %jp{デバッグ版の定義変更}
!if "$(DEBUG)" == "Yes"
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfwdbg.$(EXT_LIB)
!endif


# %jp{メモリマップ}
!if "$(MEMMAP)" == "ext"
# %jp{外部メモリ}
TARGET      = $(TARGET)ext
SECTION_RO = 0x80008000
SECTION_RW = 0x80010000
!else
!if "$(MEMMAP)" == "ram"
# %jp{内蔵RAM}
SECTION_RO = 0x00000000
SECTION_RW = 0x80010000
!else
# %jp{内蔵ROM}
AFLAGS      = $(AFLAGS) --predefine="ROM_AT_ADDRESS_ZERO SETL {TRUE}"
SECTION_RO = 0x00000000
SECTION_RW = 0x80010000
!endif
!endif



# %jp{フラグ設定}
CFLAGS  = --cpu=ARM7TDMI-S --apcs=inter --thumb
AFLAGS  = --cpu=ARM7TDMI-S --apcs=inter --thumb
LNFLAGS = --ro_base=$(SECTION_RO) --rw_base=$(SECTION_RW) --first=vectors.o --entry=$(SECTION_RO)


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_BIN = $(TARGET).$(EXT_BIN)
TARGET_HEX = $(TARGET).$(EXT_HEX)


# %jp{コンパイラ依存の設定読込み}
!include $(KERNEL_MAKINC_DIR)\armcc_d.inc

# %jp{実行ファイル生成共通定義の読込み}
!include $(KERNEL_MAKINC_DIR)\makexe_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS = $(INC_DIRS) $(HOSAPLFW_INC_DIR)


# %jp{ソースディレクトリ}
SRC_DIRS = $(SRC_DIRS) . ..


# %jp{アセンブラファイルの追加}
ASRCS = $(ASRCS) .\vectors.s
ASRCS = $(ASRCS) .\startup.s
ASRCS = $(ASRCS) .\uish.s


# %jp{C言語ファイルの追加}
CSRCS = $(CSRCS) ..\kernel_cfg.c
CSRCS = $(CSRCS) ..\main.c
CSRCS = $(CSRCS) ..\boot.c
CSRCS = $(CSRCS) ..\ostimer.c


# %jp{オブジェクトファイルの追加}
OBJS = $(OBJS) $(OBJS_DIR)\vectors.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\startup.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\uish.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kernel_cfg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\main.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\boot.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ostimer.$(EXT_OBJ)


# %jp{ライブラリファイルの追加}
LIBS = $(LIBS) $(HOSAPLFW_LIB)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

all: make_subproject kernel_make make_subprj makeexe_all $(OBJS_DIR)\kernel_cfg.c srcobjcp $(TARGET_EXE)

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
!include $(KERNEL_MAKINC_DIR)\armcc_r.inc



# %jp{コピー}
srcobjcp:
	$(CMD_CP) ..\*.c $(OBJS_DIR)
	$(CMD_CP) .\*.s $(OBJS_DIR)



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)\vectors.$(EXT_OBJ)		:	$(OBJS_DIR)\vectors.s
$(OBJS_DIR)\startup.$(EXT_OBJ)		:	$(OBJS_DIR)\startup.s
$(OBJS_DIR)\uish.$(EXT_OBJ)			:	$(OBJS_DIR)\uish.s
$(OBJS_DIR)\kernel_cfg.$(EXT_OBJ)	:	$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h
$(OBJS_DIR)\main.$(EXT_OBJ)			:	$(OBJS_DIR)\main.c       ..\kernel_id.h
$(OBJS_DIR)\boot.$(EXT_OBJ)			:	$(OBJS_DIR)\boot.c       ..\kernel_id.h ..\boot.h
$(OBJS_DIR)\ostimer.$(EXT_OBJ)		:	$(OBJS_DIR)\ostimer.c    ..\kernel_id.h ..\ostimer.h


# end of file
