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
TOP_DIR            = ..\..\..\..\..
KERNEL_DIR         = $(TOP_DIR)\kernel
KERNEL_CFGRTR_DIR  = $(TOP_DIR)\cfgrtr\build\msc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)\build\common\nmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)\build\win\win32\msc
HOSAPLFW_DIR       = $(TOP_DIR)\aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)\build\win\win32\msc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)\h4acfg-$(ARCH_NAME)


# %jp{共通定義読込み}%jp{common setting}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{ライブラリ定義}%en{library}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfw.lib

# %jp{デバッグ版の定義変更}%en{debug mode}
!if "$(DEBUG)" == "Yes"
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)\hosaplfwdbg.lib
!endif


# %jp{パス設定}%en{add source directories}
INC_DIRS = . .. $(HOSAPLFW_INC_DIR)
SRC_DIRS = . ..


# %jp{オプションフラグ}%en{option flags}
AFLAGS  = 
CFLAGS  = 
LNFLAGS = /MTd


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
ASRCS = $(ASRCS)


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS = $(CSRCS) ..\kernel_cfg.c
CSRCS = $(CSRCS) ..\main.c
CSRCS = $(CSRCS) ..\boot.c
CSRCS = $(CSRCS) ..\ostimer.c
CSRCS = $(CSRCS) ..\wintimer.c


# %jp{オブジェクトファイルの追加}
OBJS = $(OBJS) $(OBJS_DIR)\kernel_cfg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\main.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\boot.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ostimer.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\wintimer.$(EXT_OBJ)


# %jp{ライブラリファイルの追加}
LIBS = $(LIBS) $(HOSAPLFW_LIB) user32.lib winmm.lib ws2_32.lib


# LIBS = $(LIBS) $(HOSAPLFW_LIB) kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib ws2_32.lib




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
all: make_subproject makeexe_all $(OBJS_DIR)\kernel_cfg.c srcobjcp $(TARGET_EXE)

# %jp{サブプロジェクトメイク}%en{subprojects}
make_subproject:
	$(CMD_CD) $(HOSAPLFW_BUILD_DIR)
	$(MAKE)
	$(CMD_CD) $(MAKEDIR)

# %jp{クリーン}%en{clean}
clean: makeexe_clean
	-$(CMD_RM) $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ..\kernel_cfg.c ..\kernel_id.h

# %jp{サブプロジェクトごとクリーン}%en{mostlyclean}
mostlyclean: clean kernel_clean
	$(CMD_CD) $(HOSAPLFW_BUILD_DIR)
	$(MAKE) clean
	$(CMD_CD) $(MAKEDIR)


# %jp{コンフィギュレータ実行}%en{configurator}
..\kernel_cfg.c ..\kernel_id.h: ..\system.cfg
	cl /E ..\system.cfg > ..\system.i
	$(KERNEL_CFGRTR) ..\system.i -c ..\kernel_cfg.c -i ..\kernel_id.h

$(OBJS_DIR)\kernel_cfg.c: ..\kernel_cfg.c
	$(CMD_CP) ..\kernel_cfg.c $(OBJS_DIR)
	$(CMD_CP) ..\kernel_id.h $(OBJS_DIR)

# %jp{コピー}%en{copy}
srcobjcp:
	$(CMD_CP) ..\*.* $(OBJS_DIR)


# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
!include $(KERNEL_MAKINC_DIR)\makexe_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_r.inc




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

$(OBJS_DIR)\kernel_cfg.obj	:	$(OBJS_DIR)\kernel_cfg.c ..\kernel_id.h
$(OBJS_DIR)\main.obj		:	$(OBJS_DIR)\main.c       ..\kernel_id.h
$(OBJS_DIR)\sample.obj		:	$(OBJS_DIR)\sample.c     ..\kernel_id.h ..\sample.h
$(OBJS_DIR)\ostimer.obj		:	$(OBJS_DIR)\ostimer.c    ..\kernel_id.h ..\ostimer.h
$(OBJS_DIR)\wintimer.obj	:	$(OBJS_DIR)\wintimer.c   ..\kernel_id.h ..\wintimer.h



# end of file
