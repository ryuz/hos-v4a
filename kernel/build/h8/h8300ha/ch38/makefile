# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for H8/300H advanced mode
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = libhosv4a


# %jp{アーキテクチャ定義}
ARCH_PROC = h8\h8300ha
ARCH_IRC  = simple
ARCH_CC   = ch38


# %jp{ディレクトリ定義}
TOP_DIR           = ..\..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake


# %jp{カーネル指定}
KERNEL = Yes


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャパス}
INC_PROC_DIR     = $(KERNEL_DIR)\include\arch\proc\$(ARCH_PROC)
INC_IRC_DIR      = $(KERNEL_DIR)\include\arch\irc\$(ARCH_IRC)
SRC_PROC_DIR     = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)
SRC_PROC_ASM_DIR = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)\$(ARCH_CC)
SRC_IRC_DIR      = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)
SRC_IRC_ASM_DIR  = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)\$(ARCH_CC)


# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)\cfgrtr\build\msc
CFGRTR     = h4acfg-h8300ha


# %jp{パス設定}
INC_DIRS = $(INC_DIRS) $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS = $(SRC_DIRS) $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_ASM_DIR) $(SRC_IRC_DIR) $(SRC_IRC_ASM_DIR)



# %jp{オプションフラグ}
CFLAGS = $(CFLAGS) -CP=300HA:24
AFLAGS = $(AFLAGS) -CP=300HA:24
LFLAGS = 



# %jp{コンパイラ依存定義}%en{definitions of compiler dependence}
!include $(KERNEL_MAKINC_DIR)/ch38_d.inc

# %jp{ライブラリ生成共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\maklib_d.inc



# %jp{オブジェクトファイル定義}
OBJS = $(OBJS) $(OBJS_DIR)\val_int.obj
OBJS = $(OBJS) $(OBJS_DIR)\chg_imsk.obj
OBJS = $(OBJS) $(OBJS_DIR)\get_imsk.obj
OBJS = $(OBJS) $(OBJS_DIR)\ena_int.obj
OBJS = $(OBJS) $(OBJS_DIR)\dis_int.obj
OBJS = $(OBJS) $(OBJS_DIR)\clr_int.obj
OBJS = $(OBJS) $(OBJS_DIR)\chg_ilv.obj
OBJS = $(OBJS) $(OBJS_DIR)\get_ilv.obj
OBJS = $(OBJS) $(OBJS_DIR)\kini_prc.obj
OBJS = $(OBJS) $(OBJS_DIR)\kena_int.obj
OBJS = $(OBJS) $(OBJS_DIR)\kdis_int.obj
OBJS = $(OBJS) $(OBJS_DIR)\kwai_int.obj
OBJS = $(OBJS) $(OBJS_DIR)\kcre_ctx.obj
OBJS = $(OBJS) $(OBJS_DIR)\krst_ctx.obj
OBJS = $(OBJS) $(OBJS_DIR)\kswi_ctx.obj
OBJS = $(OBJS) $(OBJS_DIR)\kint_hdr.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_dmy.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_001.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_002.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_003.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_004.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_005.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_006.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_007.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_008.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_009.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_010.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_011.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_012.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_013.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_014.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_015.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_016.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_017.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_018.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_019.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_020.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_021.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_022.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_023.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_024.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_025.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_026.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_027.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_028.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_029.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_030.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_031.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_032.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_033.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_034.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_035.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_036.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_037.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_038.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_039.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_040.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_041.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_042.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_043.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_044.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_045.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_046.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_047.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_048.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_049.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_050.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_051.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_052.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_053.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_054.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_055.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_056.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_057.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_058.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_059.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_060.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_061.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_062.obj
OBJS = $(OBJS) $(OBJS_DIR)\vect_063.obj



# %jp{ALL}%en{all}
all: mkdir_objs srcobjcp makelib_all
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)


# %jp{クリーン}%en{clean}
clean: makelib_clean
	-$(CMD_RM) /Q *.lst
	-$(CMD_RM) /Q $(OBJS_DIR)\*.*
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean


# カーネル共通ソースの追加
!include $(KERNEL_MAKINC_DIR)\knlsrc.inc


# %jp{ライブラリ生成用設定読込み}
!include $(KERNEL_MAKINC_DIR)/maklib_r.inc


# %jp{コンパイラ依存ルール}%en{rules of compiler dependence}
!include $(KERNEL_MAKINC_DIR)/ch38_r.inc


# %jp{カーネル依存関係読込み}
!include $(KERNEL_MAKINC_DIR)/knldep.inc



# %jp{コピー}
srcobjcp:
	$(CMD_CP) $(SRC_PROC_DIR)\*.c       $(OBJS_DIR)
	$(CMD_CP) $(SRC_IRC_DIR)\*.c        $(OBJS_DIR)
	$(CMD_CP) $(SRC_PROC_ASM_DIR)\*.src $(OBJS_DIR)


# %jp{依存関係}
$(OBJS_DIR)\val_int.obj : $(OBJS_DIR)\val_int.c
$(OBJS_DIR)\val_imsk.obj: $(OBJS_DIR)\val_imsk.c
$(OBJS_DIR)\chg_imsk.obj: $(OBJS_DIR)\chg_imsk.c
$(OBJS_DIR)\get_imsk.obj: $(OBJS_DIR)\get_imsk.c
$(OBJS_DIR)\ena_int.obj : $(OBJS_DIR)\ena_int.c	
$(OBJS_DIR)\dis_int.obj : $(OBJS_DIR)\dis_int.c	
$(OBJS_DIR)\clr_int.obj : $(OBJS_DIR)\clr_int.c	
$(OBJS_DIR)\chg_ilv.obj : $(OBJS_DIR)\chg_ilv.c	
$(OBJS_DIR)\get_ilv.obj : $(OBJS_DIR)\get_ilv.c	
$(OBJS_DIR)\kini_prc.obj: $(OBJS_DIR)\kini_prc.src
$(OBJS_DIR)\kena_int.obj: $(OBJS_DIR)\kena_int.src
$(OBJS_DIR)\kdis_int.obj: $(OBJS_DIR)\kdis_int.src
$(OBJS_DIR)\kwai_int.obj: $(OBJS_DIR)\kwai_int.src
$(OBJS_DIR)\kcre_ctx.obj: $(OBJS_DIR)\kcre_ctx.src
$(OBJS_DIR)\krst_ctx.obj: $(OBJS_DIR)\krst_ctx.src
$(OBJS_DIR)\kswi_ctx.obj: $(OBJS_DIR)\kswi_ctx.src
$(OBJS_DIR)\kint_hdr.obj: $(OBJS_DIR)\kint_hdr.src
$(OBJS_DIR)\vect_dmy.obj: $(OBJS_DIR)\vect_dmy.src
$(OBJS_DIR)\vect_001.obj: $(OBJS_DIR)\vect_001.src
$(OBJS_DIR)\vect_002.obj: $(OBJS_DIR)\vect_002.src
$(OBJS_DIR)\vect_003.obj: $(OBJS_DIR)\vect_003.src
$(OBJS_DIR)\vect_004.obj: $(OBJS_DIR)\vect_004.src
$(OBJS_DIR)\vect_005.obj: $(OBJS_DIR)\vect_005.src
$(OBJS_DIR)\vect_006.obj: $(OBJS_DIR)\vect_006.src
$(OBJS_DIR)\vect_007.obj: $(OBJS_DIR)\vect_007.src
$(OBJS_DIR)\vect_008.obj: $(OBJS_DIR)\vect_008.src
$(OBJS_DIR)\vect_009.obj: $(OBJS_DIR)\vect_009.src
$(OBJS_DIR)\vect_010.obj: $(OBJS_DIR)\vect_010.src
$(OBJS_DIR)\vect_011.obj: $(OBJS_DIR)\vect_011.src
$(OBJS_DIR)\vect_012.obj: $(OBJS_DIR)\vect_012.src
$(OBJS_DIR)\vect_013.obj: $(OBJS_DIR)\vect_013.src
$(OBJS_DIR)\vect_014.obj: $(OBJS_DIR)\vect_014.src
$(OBJS_DIR)\vect_015.obj: $(OBJS_DIR)\vect_015.src
$(OBJS_DIR)\vect_016.obj: $(OBJS_DIR)\vect_016.src
$(OBJS_DIR)\vect_017.obj: $(OBJS_DIR)\vect_017.src
$(OBJS_DIR)\vect_018.obj: $(OBJS_DIR)\vect_018.src
$(OBJS_DIR)\vect_019.obj: $(OBJS_DIR)\vect_019.src
$(OBJS_DIR)\vect_020.obj: $(OBJS_DIR)\vect_020.src
$(OBJS_DIR)\vect_021.obj: $(OBJS_DIR)\vect_021.src
$(OBJS_DIR)\vect_022.obj: $(OBJS_DIR)\vect_022.src
$(OBJS_DIR)\vect_023.obj: $(OBJS_DIR)\vect_023.src
$(OBJS_DIR)\vect_024.obj: $(OBJS_DIR)\vect_024.src
$(OBJS_DIR)\vect_025.obj: $(OBJS_DIR)\vect_025.src
$(OBJS_DIR)\vect_026.obj: $(OBJS_DIR)\vect_026.src
$(OBJS_DIR)\vect_027.obj: $(OBJS_DIR)\vect_027.src
$(OBJS_DIR)\vect_028.obj: $(OBJS_DIR)\vect_028.src
$(OBJS_DIR)\vect_029.obj: $(OBJS_DIR)\vect_029.src
$(OBJS_DIR)\vect_030.obj: $(OBJS_DIR)\vect_030.src
$(OBJS_DIR)\vect_031.obj: $(OBJS_DIR)\vect_031.src
$(OBJS_DIR)\vect_032.obj: $(OBJS_DIR)\vect_032.src
$(OBJS_DIR)\vect_033.obj: $(OBJS_DIR)\vect_033.src
$(OBJS_DIR)\vect_034.obj: $(OBJS_DIR)\vect_034.src
$(OBJS_DIR)\vect_035.obj: $(OBJS_DIR)\vect_035.src
$(OBJS_DIR)\vect_036.obj: $(OBJS_DIR)\vect_036.src
$(OBJS_DIR)\vect_037.obj: $(OBJS_DIR)\vect_037.src
$(OBJS_DIR)\vect_038.obj: $(OBJS_DIR)\vect_038.src
$(OBJS_DIR)\vect_039.obj: $(OBJS_DIR)\vect_039.src
$(OBJS_DIR)\vect_040.obj: $(OBJS_DIR)\vect_040.src
$(OBJS_DIR)\vect_041.obj: $(OBJS_DIR)\vect_041.src
$(OBJS_DIR)\vect_042.obj: $(OBJS_DIR)\vect_042.src
$(OBJS_DIR)\vect_043.obj: $(OBJS_DIR)\vect_043.src
$(OBJS_DIR)\vect_044.obj: $(OBJS_DIR)\vect_044.src
$(OBJS_DIR)\vect_045.obj: $(OBJS_DIR)\vect_045.src
$(OBJS_DIR)\vect_046.obj: $(OBJS_DIR)\vect_046.src
$(OBJS_DIR)\vect_047.obj: $(OBJS_DIR)\vect_047.src
$(OBJS_DIR)\vect_048.obj: $(OBJS_DIR)\vect_048.src
$(OBJS_DIR)\vect_049.obj: $(OBJS_DIR)\vect_049.src
$(OBJS_DIR)\vect_050.obj: $(OBJS_DIR)\vect_050.src
$(OBJS_DIR)\vect_051.obj: $(OBJS_DIR)\vect_051.src
$(OBJS_DIR)\vect_052.obj: $(OBJS_DIR)\vect_052.src
$(OBJS_DIR)\vect_053.obj: $(OBJS_DIR)\vect_053.src
$(OBJS_DIR)\vect_054.obj: $(OBJS_DIR)\vect_054.src
$(OBJS_DIR)\vect_055.obj: $(OBJS_DIR)\vect_055.src
$(OBJS_DIR)\vect_056.obj: $(OBJS_DIR)\vect_056.src
$(OBJS_DIR)\vect_057.obj: $(OBJS_DIR)\vect_057.src
$(OBJS_DIR)\vect_058.obj: $(OBJS_DIR)\vect_058.src
$(OBJS_DIR)\vect_059.obj: $(OBJS_DIR)\vect_059.src
$(OBJS_DIR)\vect_060.obj: $(OBJS_DIR)\vect_060.src
$(OBJS_DIR)\vect_061.obj: $(OBJS_DIR)\vect_061.src
$(OBJS_DIR)\vect_062.obj: $(OBJS_DIR)\vect_062.src
$(OBJS_DIR)\vect_063.obj: $(OBJS_DIR)\vect_063.src


# end of file
