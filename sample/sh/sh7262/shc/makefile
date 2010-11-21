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
ARCH_NAME = sh2
ARCH_CC   = shc


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR           = ..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_CFGRTR_DIR = $(TOP_DIR)\cfgrtr\build\msc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)\build\sh\sh2\shc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-$(ARCH_NAME)


# %jp{共通定義読込み}%jp{common setting}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{メモリマップ}
!if "$(MEMMAP)" == "ram"
# %jp{外部メモリ}
TARGET       = $(TARGET)_ram
SECTION_VECT = 0FFFFE160
SECTION_RO  = 000400400
SECTION_RW  = 000410000
!else
# %jp{内蔵ROMメモリ}
SECTION_VECT = 000000000
SECTION_RO  = 000000400
SECTION_RW  = 0FFFFE000
!endif


# %jp{パス設定}%en{add source directories}
INC_DIRS = . ..
SRC_DIRS = . ..


# %jp{オプションフラグ}%en{option flags}
AFLAGS   = -CPu=sh2
CFLAGS   = -CPu=sh2
LNFLAGS  = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
!include $(KERNEL_MAKINC_DIR)\makexe_d.inc


# %jp{出力ファイル名}%en{output files}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)

# %jp{Cライブラリ名の指定}%en{std library}
STD_LIBS = stdlib.lib



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS = $(ASRCS) .\vcttbl.src
ASRCS = $(ASRCS) .\startup.src

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS = $(CSRCS) .\dbsct.c
CSRCS = $(CSRCS) ..\kernel_cfg.c
CSRCS = $(CSRCS) ..\main.c
CSRCS = $(CSRCS) ..\sample.c
CSRCS = $(CSRCS) ..\ostimer.c
CSRCS = $(CSRCS) ..\sci1.c


# %jp{オブジェクトファイルの追加}%en{object files}
OBJS = $(OBJS) $(OBJS_DIR)\vcttbl.obj
OBJS = $(OBJS) $(OBJS_DIR)\startup.obj
OBJS = $(OBJS) $(OBJS_DIR)\kernel_cfg.obj
OBJS = $(OBJS) $(OBJS_DIR)\main.obj
OBJS = $(OBJS) $(OBJS_DIR)\sample.obj
OBJS = $(OBJS) $(OBJS_DIR)\ostimer.obj
OBJS = $(OBJS) $(OBJS_DIR)\sci1.obj


# %jp{ライブラリの追加}
LIBS = $(LIBS) $(STD_LIBS)




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
all: makeexe_all srcobjcp $(TARGET_EXE) $(TARGET_MOT)

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

$(STD_LIBS):
	lbgsh -OUTPut=$(STD_LIBS) -CP=sh2


# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
!include $(KERNEL_MAKINC_DIR)\makexe_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_r.inc


# %jp{コピー}%en{copy}
srcobjcp:
	$(CMD_CP) ..\*.c $(OBJS_DIR)
	$(CMD_CP) .\*.src $(OBJS_DIR)



# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

$(OBJS_DIR)\vcttbl.obj		:	$(OBJS_DIR)\vcttbl.src
$(OBJS_DIR)\startup.obj		:	$(OBJS_DIR)\startup.src
$(OBJS_DIR)\kernel_cfg.obj	:	$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h
$(OBJS_DIR)\main.obj		:	$(OBJS_DIR)\main.c       ..\kernel_id.h
$(OBJS_DIR)\sample.obj		:	$(OBJS_DIR)\sample.c     ..\kernel_id.h
$(OBJS_DIR)\ostimer.obj		:	$(OBJS_DIR)\ostimer.c    ..\kernel_id.h
$(OBJS_DIR)\sci1.obj		:	$(OBJS_DIR)\sci1.c       ..\kernel_id.h



# end of file
