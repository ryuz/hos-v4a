# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for H8/300H advanced mode
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

.SUFFIXES :
.SUFFIXES : .obj .c .src


# %jp{ターゲット名}
TARGET = libhosv4a

# %jp{アーキテクチャパス}
ARCH_PROC = h8/h8300ha
ARCH_IRC  = simple
ARCH_CC   = ch38


# %jp{ディレクトリ定義}
TOP_DIR           = ..\..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake
OBJS_DIR          = objs_$(TARGET)


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャパス定義}
INC_PROC_DIR     = $(KERNEL_DIR)\include\arch\proc\$(ARCH_PROC)
INC_IRC_DIR      = $(KERNEL_DIR)\include\arch\irc\$(ARCH_IRC)
SRC_PROC_DIR     = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)
SRC_PROC_ASM_DIR = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)\$(ARCH_CC)
SRC_IRC_DIR      = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)
SRC_IRC_ASM_DIR  = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)\$(ARCH_CC)

# %jp{パス設定}
INC_DIRS = $(INC_DIRS) $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS = $(SRC_DIRS) $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_ASM_DIR) $(SRC_IRC_DIR) $(SRC_IRC_ASM_DIR)

# %jp{オプションフラグ}
CFLAGS = $(CFLAGS) -CP=300HA:24
AFLAGS = $(AFLAGS) -CP=300HA:24
LFLAGS = 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)\cfgrtr\build\gcc
CFGRTR     = h4acfg-h8300ha


# C言語ファイルの追加
# CSRCS += $(SRC_IRC_DIR)/intc.c

# アセンブラファイルの追加
ASRCS  = $(ASRCS)								\
         $(SRC_PROC_ASM_DIR)/ctxctl.src			\
         $(SRC_PROC_ASM_DIR)/intctl.src			\
         $(SRC_PROC_ASM_DIR)/vect_dmy.src		\
         $(SRC_PROC_ASM_DIR)/vect_001.src		\
         $(SRC_PROC_ASM_DIR)/vect_002.src		\
         $(SRC_PROC_ASM_DIR)/vect_003.src		\
         $(SRC_PROC_ASM_DIR)/vect_004.src		\
         $(SRC_PROC_ASM_DIR)/vect_005.src		\
         $(SRC_PROC_ASM_DIR)/vect_006.src		\
         $(SRC_PROC_ASM_DIR)/vect_007.src		\
         $(SRC_PROC_ASM_DIR)/vect_008.src		\
         $(SRC_PROC_ASM_DIR)/vect_009.src		\
         $(SRC_PROC_ASM_DIR)/vect_010.src		\
         $(SRC_PROC_ASM_DIR)/vect_011.src		\
         $(SRC_PROC_ASM_DIR)/vect_012.src		\
         $(SRC_PROC_ASM_DIR)/vect_013.src		\
         $(SRC_PROC_ASM_DIR)/vect_014.src		\
         $(SRC_PROC_ASM_DIR)/vect_015.src		\
         $(SRC_PROC_ASM_DIR)/vect_016.src		\
         $(SRC_PROC_ASM_DIR)/vect_017.src		\
         $(SRC_PROC_ASM_DIR)/vect_018.src		\
         $(SRC_PROC_ASM_DIR)/vect_019.src		\
         $(SRC_PROC_ASM_DIR)/vect_020.src		\
         $(SRC_PROC_ASM_DIR)/vect_021.src		\
         $(SRC_PROC_ASM_DIR)/vect_022.src		\
         $(SRC_PROC_ASM_DIR)/vect_023.src		\
         $(SRC_PROC_ASM_DIR)/vect_024.src		\
         $(SRC_PROC_ASM_DIR)/vect_025.src		\
         $(SRC_PROC_ASM_DIR)/vect_026.src		\
         $(SRC_PROC_ASM_DIR)/vect_027.src		\
         $(SRC_PROC_ASM_DIR)/vect_028.src		\
         $(SRC_PROC_ASM_DIR)/vect_029.src		\
         $(SRC_PROC_ASM_DIR)/vect_030.src		\
         $(SRC_PROC_ASM_DIR)/vect_031.src		\
         $(SRC_PROC_ASM_DIR)/vect_032.src		\
         $(SRC_PROC_ASM_DIR)/vect_033.src		\
         $(SRC_PROC_ASM_DIR)/vect_034.src		\
         $(SRC_PROC_ASM_DIR)/vect_035.src		\
         $(SRC_PROC_ASM_DIR)/vect_036.src		\
         $(SRC_PROC_ASM_DIR)/vect_037.src		\
         $(SRC_PROC_ASM_DIR)/vect_038.src		\
         $(SRC_PROC_ASM_DIR)/vect_039.src		\
         $(SRC_PROC_ASM_DIR)/vect_040.src		\
         $(SRC_PROC_ASM_DIR)/vect_041.src		\
         $(SRC_PROC_ASM_DIR)/vect_042.src		\
         $(SRC_PROC_ASM_DIR)/vect_043.src		\
         $(SRC_PROC_ASM_DIR)/vect_044.src		\
         $(SRC_PROC_ASM_DIR)/vect_045.src		\
         $(SRC_PROC_ASM_DIR)/vect_046.src		\
         $(SRC_PROC_ASM_DIR)/vect_047.src		\
         $(SRC_PROC_ASM_DIR)/vect_048.src		\
         $(SRC_PROC_ASM_DIR)/vect_049.src		\
         $(SRC_PROC_ASM_DIR)/vect_050.src		\
         $(SRC_PROC_ASM_DIR)/vect_051.src		\
         $(SRC_PROC_ASM_DIR)/vect_052.src		\
         $(SRC_PROC_ASM_DIR)/vect_053.src		\
         $(SRC_PROC_ASM_DIR)/vect_054.src		\
         $(SRC_PROC_ASM_DIR)/vect_055.src		\
         $(SRC_PROC_ASM_DIR)/vect_056.src		\
         $(SRC_PROC_ASM_DIR)/vect_057.src		\
         $(SRC_PROC_ASM_DIR)/vect_058.src		\
         $(SRC_PROC_ASM_DIR)/vect_059.src		\
         $(SRC_PROC_ASM_DIR)/vect_060.src		\
         $(SRC_PROC_ASM_DIR)/vect_061.src		\
         $(SRC_PROC_ASM_DIR)/vect_062.src		\
         $(SRC_PROC_ASM_DIR)/vect_063.src


# %jp{オブジェクトファイル}
OBJS   = $(OBJS)						\
         $(OBJS_DIR)/ctxctl.obj			\
         $(OBJS_DIR)/intctl.obj			\
         $(OBJS_DIR)/vect_dmy.obj		\
         $(OBJS_DIR)/vect_001.obj		\
         $(OBJS_DIR)/vect_002.obj		\
         $(OBJS_DIR)/vect_003.obj		\
         $(OBJS_DIR)/vect_004.obj		\
         $(OBJS_DIR)/vect_005.obj		\
         $(OBJS_DIR)/vect_006.obj		\
         $(OBJS_DIR)/vect_007.obj		\
         $(OBJS_DIR)/vect_008.obj		\
         $(OBJS_DIR)/vect_009.obj		\
         $(OBJS_DIR)/vect_010.obj		\
         $(OBJS_DIR)/vect_011.obj		\
         $(OBJS_DIR)/vect_012.obj		\
         $(OBJS_DIR)/vect_013.obj		\
         $(OBJS_DIR)/vect_014.obj		\
         $(OBJS_DIR)/vect_015.obj		\
         $(OBJS_DIR)/vect_016.obj		\
         $(OBJS_DIR)/vect_017.obj		\
         $(OBJS_DIR)/vect_018.obj		\
         $(OBJS_DIR)/vect_019.obj		\
         $(OBJS_DIR)/vect_020.obj		\
         $(OBJS_DIR)/vect_021.obj		\
         $(OBJS_DIR)/vect_022.obj		\
         $(OBJS_DIR)/vect_023.obj		\
         $(OBJS_DIR)/vect_024.obj		\
         $(OBJS_DIR)/vect_025.obj		\
         $(OBJS_DIR)/vect_026.obj		\
         $(OBJS_DIR)/vect_027.obj		\
         $(OBJS_DIR)/vect_028.obj		\
         $(OBJS_DIR)/vect_029.obj		\
         $(OBJS_DIR)/vect_030.obj		\
         $(OBJS_DIR)/vect_031.obj		\
         $(OBJS_DIR)/vect_032.obj		\
         $(OBJS_DIR)/vect_033.obj		\
         $(OBJS_DIR)/vect_034.obj		\
         $(OBJS_DIR)/vect_035.obj		\
         $(OBJS_DIR)/vect_036.obj		\
         $(OBJS_DIR)/vect_037.obj		\
         $(OBJS_DIR)/vect_038.obj		\
         $(OBJS_DIR)/vect_039.obj		\
         $(OBJS_DIR)/vect_040.obj		\
         $(OBJS_DIR)/vect_041.obj		\
         $(OBJS_DIR)/vect_042.obj		\
         $(OBJS_DIR)/vect_043.obj		\
         $(OBJS_DIR)/vect_044.obj		\
         $(OBJS_DIR)/vect_045.obj		\
         $(OBJS_DIR)/vect_046.obj		\
         $(OBJS_DIR)/vect_047.obj		\
         $(OBJS_DIR)/vect_048.obj		\
         $(OBJS_DIR)/vect_049.obj		\
         $(OBJS_DIR)/vect_050.obj		\
         $(OBJS_DIR)/vect_051.obj		\
         $(OBJS_DIR)/vect_052.obj		\
         $(OBJS_DIR)/vect_053.obj		\
         $(OBJS_DIR)/vect_054.obj		\
         $(OBJS_DIR)/vect_055.obj		\
         $(OBJS_DIR)/vect_056.obj		\
         $(OBJS_DIR)/vect_057.obj		\
         $(OBJS_DIR)/vect_058.obj		\
         $(OBJS_DIR)/vect_059.obj		\
         $(OBJS_DIR)/vect_060.obj		\
         $(OBJS_DIR)/vect_061.obj		\
         $(OBJS_DIR)/vect_062.obj		\
         $(OBJS_DIR)/vect_063.obj


# %jp{ALL}
all: all_makelib

#	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}
clean: clean_makelib
	$(CMD_RM) *.lst

#	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean

# %jp{ch38用の設定読込み}
!include $(KERNEL_MAKINC_DIR)/ch38_def.inc

# カーネル共通ソースの追加
!include $(KERNEL_MAKINC_DIR)\knlsrc.inc

# %jp{ライブラリ生成用設定読込み}
!include $(KERNEL_MAKINC_DIR)/makelib.inc

test:
	echo $(VPATH)

# %jp{ch38用のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)/ch38_rul.inc

# %jp{カーネル依存関係読込み}
!include $(KERNEL_MAKINC_DIR)/knldep.inc


# %jp{依存関係}
$(OBJS_DIR)\ctxctl.obj:   $(SRC_PROC_ASM_DIR)\ctxctl.src
$(OBJS_DIR)\intctl.obj:   $(SRC_PROC_ASM_DIR)\intctl.src
$(OBJS_DIR)\vect_dmy.obj: $(SRC_PROC_ASM_DIR)\vect_dmy.src
$(OBJS_DIR)\vect_001.obj: $(SRC_PROC_ASM_DIR)\vect_001.src
$(OBJS_DIR)\vect_002.obj: $(SRC_PROC_ASM_DIR)\vect_002.src
$(OBJS_DIR)\vect_003.obj: $(SRC_PROC_ASM_DIR)\vect_003.src
$(OBJS_DIR)\vect_004.obj: $(SRC_PROC_ASM_DIR)\vect_004.src
$(OBJS_DIR)\vect_005.obj: $(SRC_PROC_ASM_DIR)\vect_005.src
$(OBJS_DIR)\vect_006.obj: $(SRC_PROC_ASM_DIR)\vect_006.src
$(OBJS_DIR)\vect_007.obj: $(SRC_PROC_ASM_DIR)\vect_007.src
$(OBJS_DIR)\vect_008.obj: $(SRC_PROC_ASM_DIR)\vect_008.src
$(OBJS_DIR)\vect_009.obj: $(SRC_PROC_ASM_DIR)\vect_009.src
$(OBJS_DIR)\vect_010.obj: $(SRC_PROC_ASM_DIR)\vect_010.src
$(OBJS_DIR)\vect_011.obj: $(SRC_PROC_ASM_DIR)\vect_011.src
$(OBJS_DIR)\vect_012.obj: $(SRC_PROC_ASM_DIR)\vect_012.src
$(OBJS_DIR)\vect_013.obj: $(SRC_PROC_ASM_DIR)\vect_013.src
$(OBJS_DIR)\vect_014.obj: $(SRC_PROC_ASM_DIR)\vect_014.src
$(OBJS_DIR)\vect_015.obj: $(SRC_PROC_ASM_DIR)\vect_015.src
$(OBJS_DIR)\vect_016.obj: $(SRC_PROC_ASM_DIR)\vect_016.src
$(OBJS_DIR)\vect_017.obj: $(SRC_PROC_ASM_DIR)\vect_017.src
$(OBJS_DIR)\vect_018.obj: $(SRC_PROC_ASM_DIR)\vect_018.src
$(OBJS_DIR)\vect_019.obj: $(SRC_PROC_ASM_DIR)\vect_019.src
$(OBJS_DIR)\vect_020.obj: $(SRC_PROC_ASM_DIR)\vect_020.src
$(OBJS_DIR)\vect_021.obj: $(SRC_PROC_ASM_DIR)\vect_021.src
$(OBJS_DIR)\vect_022.obj: $(SRC_PROC_ASM_DIR)\vect_022.src
$(OBJS_DIR)\vect_023.obj: $(SRC_PROC_ASM_DIR)\vect_023.src
$(OBJS_DIR)\vect_024.obj: $(SRC_PROC_ASM_DIR)\vect_024.src
$(OBJS_DIR)\vect_025.obj: $(SRC_PROC_ASM_DIR)\vect_025.src
$(OBJS_DIR)\vect_026.obj: $(SRC_PROC_ASM_DIR)\vect_026.src
$(OBJS_DIR)\vect_027.obj: $(SRC_PROC_ASM_DIR)\vect_027.src
$(OBJS_DIR)\vect_028.obj: $(SRC_PROC_ASM_DIR)\vect_028.src
$(OBJS_DIR)\vect_029.obj: $(SRC_PROC_ASM_DIR)\vect_029.src
$(OBJS_DIR)\vect_030.obj: $(SRC_PROC_ASM_DIR)\vect_030.src
$(OBJS_DIR)\vect_031.obj: $(SRC_PROC_ASM_DIR)\vect_031.src
$(OBJS_DIR)\vect_032.obj: $(SRC_PROC_ASM_DIR)\vect_032.src
$(OBJS_DIR)\vect_033.obj: $(SRC_PROC_ASM_DIR)\vect_033.src
$(OBJS_DIR)\vect_034.obj: $(SRC_PROC_ASM_DIR)\vect_034.src
$(OBJS_DIR)\vect_035.obj: $(SRC_PROC_ASM_DIR)\vect_035.src
$(OBJS_DIR)\vect_036.obj: $(SRC_PROC_ASM_DIR)\vect_036.src
$(OBJS_DIR)\vect_037.obj: $(SRC_PROC_ASM_DIR)\vect_037.src
$(OBJS_DIR)\vect_038.obj: $(SRC_PROC_ASM_DIR)\vect_038.src
$(OBJS_DIR)\vect_039.obj: $(SRC_PROC_ASM_DIR)\vect_039.src
$(OBJS_DIR)\vect_040.obj: $(SRC_PROC_ASM_DIR)\vect_040.src
$(OBJS_DIR)\vect_041.obj: $(SRC_PROC_ASM_DIR)\vect_041.src
$(OBJS_DIR)\vect_042.obj: $(SRC_PROC_ASM_DIR)\vect_042.src
$(OBJS_DIR)\vect_043.obj: $(SRC_PROC_ASM_DIR)\vect_043.src
$(OBJS_DIR)\vect_044.obj: $(SRC_PROC_ASM_DIR)\vect_044.src
$(OBJS_DIR)\vect_045.obj: $(SRC_PROC_ASM_DIR)\vect_045.src
$(OBJS_DIR)\vect_046.obj: $(SRC_PROC_ASM_DIR)\vect_046.src
$(OBJS_DIR)\vect_047.obj: $(SRC_PROC_ASM_DIR)\vect_047.src
$(OBJS_DIR)\vect_048.obj: $(SRC_PROC_ASM_DIR)\vect_048.src
$(OBJS_DIR)\vect_049.obj: $(SRC_PROC_ASM_DIR)\vect_049.src
$(OBJS_DIR)\vect_050.obj: $(SRC_PROC_ASM_DIR)\vect_050.src
$(OBJS_DIR)\vect_051.obj: $(SRC_PROC_ASM_DIR)\vect_051.src
$(OBJS_DIR)\vect_052.obj: $(SRC_PROC_ASM_DIR)\vect_052.src
$(OBJS_DIR)\vect_053.obj: $(SRC_PROC_ASM_DIR)\vect_053.src
$(OBJS_DIR)\vect_054.obj: $(SRC_PROC_ASM_DIR)\vect_054.src
$(OBJS_DIR)\vect_055.obj: $(SRC_PROC_ASM_DIR)\vect_055.src
$(OBJS_DIR)\vect_056.obj: $(SRC_PROC_ASM_DIR)\vect_056.src
$(OBJS_DIR)\vect_057.obj: $(SRC_PROC_ASM_DIR)\vect_057.src
$(OBJS_DIR)\vect_058.obj: $(SRC_PROC_ASM_DIR)\vect_058.src
$(OBJS_DIR)\vect_059.obj: $(SRC_PROC_ASM_DIR)\vect_059.src
$(OBJS_DIR)\vect_060.obj: $(SRC_PROC_ASM_DIR)\vect_060.src
$(OBJS_DIR)\vect_061.obj: $(SRC_PROC_ASM_DIR)\vect_061.src
$(OBJS_DIR)\vect_062.obj: $(SRC_PROC_ASM_DIR)\vect_062.src
$(OBJS_DIR)\vect_063.obj: $(SRC_PROC_ASM_DIR)\vect_063.src


# end of file
