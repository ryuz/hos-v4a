# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for H8/300H
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# ターゲット名
TARGET    ?= libhosv4a

# アーキテクチャパス
ARCH_PROC ?= h8/h8s2600a
ARCH_IRC  ?= none
ARCH_CC   ?= ch83


# ディレクトリ定義
TOP_DIR      = ../../../../..
KNL_DIR      = $(TOP_DIR)/kernel
OBJS_DIR     = objs_$(TARGET)


# %jp{カーネル指定}
KERNEL = Yes


# インクルードディレクトリ定義
INC_KNL_DIR  = $(KNL_DIR)/include
INC_PROC_DIR = $(INC_KNL_DIR)/arch/proc/$(ARCH_PROC)
INC_IRC_DIR  = $(INC_KNL_DIR)/arch/irc/$(ARCH_IRC)

# ソースディレクトリ定義
SRC_KNL_DIR      = $(KNL_DIR)/source
SRC_PROC_DIR     = $(SRC_KNL_DIR)/arch/proc/$(ARCH_PROC)
SRC_PROC_ASM_DIR = $(SRC_KNL_DIR)/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR      = $(SRC_KNL_DIR)/arch/irc/$(ARCH_IRC)
SRC_IRC_ASM_DIR  = $(SRC_KNL_DIR)/arch/irc/$(ARCH_IRC)/$(ARCH_CC)

# コンフィギュレータ定義
CFGRTR_DIR   = $(TOP_DIR)/cfgrtr/build/gcc
CFGRTR       = h4acfg-h8s2600a


# 共通設定インクルード
include $(TOP_DIR)/kernel/build/common/gmake.inc


# ターゲットライブラリファイル名
TARGET_LIB = $(TARGET).lib

# アセンブラファイルの追加
ASRCS += $(SRC_PROC_ASM_DIR)/ctxctl.src		\
         $(SRC_PROC_ASM_DIR)/intctl.src		\
         $(SRC_PROC_ASM_DIR)/vect_001.src	\
         $(SRC_PROC_ASM_DIR)/vect_002.src	\
         $(SRC_PROC_ASM_DIR)/vect_003.src	\
         $(SRC_PROC_ASM_DIR)/vect_004.src	\
         $(SRC_PROC_ASM_DIR)/vect_005.src	\
         $(SRC_PROC_ASM_DIR)/vect_006.src	\
         $(SRC_PROC_ASM_DIR)/vect_007.src	\
         $(SRC_PROC_ASM_DIR)/vect_008.src	\
         $(SRC_PROC_ASM_DIR)/vect_009.src	\
         $(SRC_PROC_ASM_DIR)/vect_010.src	\
         $(SRC_PROC_ASM_DIR)/vect_011.src	\
         $(SRC_PROC_ASM_DIR)/vect_012.src	\
         $(SRC_PROC_ASM_DIR)/vect_013.src	\
         $(SRC_PROC_ASM_DIR)/vect_014.src	\
         $(SRC_PROC_ASM_DIR)/vect_015.src	\
         $(SRC_PROC_ASM_DIR)/vect_016.src	\
         $(SRC_PROC_ASM_DIR)/vect_017.src	\
         $(SRC_PROC_ASM_DIR)/vect_018.src	\
         $(SRC_PROC_ASM_DIR)/vect_019.src	\
         $(SRC_PROC_ASM_DIR)/vect_020.src	\
         $(SRC_PROC_ASM_DIR)/vect_021.src	\
         $(SRC_PROC_ASM_DIR)/vect_022.src	\
         $(SRC_PROC_ASM_DIR)/vect_023.src	\
         $(SRC_PROC_ASM_DIR)/vect_024.src	\
         $(SRC_PROC_ASM_DIR)/vect_025.src	\
         $(SRC_PROC_ASM_DIR)/vect_026.src	\
         $(SRC_PROC_ASM_DIR)/vect_027.src	\
         $(SRC_PROC_ASM_DIR)/vect_028.src	\
         $(SRC_PROC_ASM_DIR)/vect_029.src	\
         $(SRC_PROC_ASM_DIR)/vect_030.src	\
         $(SRC_PROC_ASM_DIR)/vect_031.src	\
         $(SRC_PROC_ASM_DIR)/vect_032.src	\
         $(SRC_PROC_ASM_DIR)/vect_033.src	\
         $(SRC_PROC_ASM_DIR)/vect_034.src	\
         $(SRC_PROC_ASM_DIR)/vect_035.src	\
         $(SRC_PROC_ASM_DIR)/vect_036.src	\
         $(SRC_PROC_ASM_DIR)/vect_037.src	\
         $(SRC_PROC_ASM_DIR)/vect_038.src	\
         $(SRC_PROC_ASM_DIR)/vect_039.src	\
         $(SRC_PROC_ASM_DIR)/vect_040.src	\
         $(SRC_PROC_ASM_DIR)/vect_041.src	\
         $(SRC_PROC_ASM_DIR)/vect_042.src	\
         $(SRC_PROC_ASM_DIR)/vect_043.src	\
         $(SRC_PROC_ASM_DIR)/vect_044.src	\
         $(SRC_PROC_ASM_DIR)/vect_045.src	\
         $(SRC_PROC_ASM_DIR)/vect_046.src	\
         $(SRC_PROC_ASM_DIR)/vect_047.src	\
         $(SRC_PROC_ASM_DIR)/vect_048.src	\
         $(SRC_PROC_ASM_DIR)/vect_049.src	\
         $(SRC_PROC_ASM_DIR)/vect_050.src	\
         $(SRC_PROC_ASM_DIR)/vect_051.src	\
         $(SRC_PROC_ASM_DIR)/vect_052.src	\
         $(SRC_PROC_ASM_DIR)/vect_053.src	\
         $(SRC_PROC_ASM_DIR)/vect_054.src	\
         $(SRC_PROC_ASM_DIR)/vect_055.src	\
         $(SRC_PROC_ASM_DIR)/vect_056.src	\
         $(SRC_PROC_ASM_DIR)/vect_057.src	\
         $(SRC_PROC_ASM_DIR)/vect_058.src	\
         $(SRC_PROC_ASM_DIR)/vect_059.src	\
         $(SRC_PROC_ASM_DIR)/vect_060.src	\
         $(SRC_PROC_ASM_DIR)/vect_061.src	\
         $(SRC_PROC_ASM_DIR)/vect_062.src	\
         $(SRC_PROC_ASM_DIR)/vect_063.src	\
         $(SRC_PROC_ASM_DIR)/vect_dmy.src



# C言語ファイルの追加
# CSRCS += $(SRC_IRC_DIR)/intc.c


# 検索パスの追加
VPATH := $(VPATH):$(SRC_PROC_DIR):$(SRC_PROC_DIR):$(SRC_PROC_ASM_DIR):$(SRC_IRC_DIR):$(SRC_IRC_ASM_DIR)


# Tools
CC     = ch38
ASM    = asm38
LIBR   = optlnk
DEPEND = depend
LINT   = splint
AWK    = gawk
MKDIR  = mkdir
RM     = rm


# オプションフラグ
AFLAGS    += -CP=2600A -DEBug
CFLAGS    += -CP=2600A -DEBug -I=$(INC_KNL_DIR) -I=$(INC_PROC_DIR) -I=$(INC_IRC_DIR)
LFLAGS    += -FOrm=Library
LINTFLAGS += -weak -I$(INC_KNL_DIR) -I$(INC_PROC_DIR) -I$(INC_IRC_DIR)



# オブジェクトファイル
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .obj, $(basename $(notdir $(CSRCS)))))   \
       $(addprefix $(OBJS_DIR)/, $(addsuffix .obj, $(basename $(notdir $(ASRCS)))))


all: $(TARGET_LIB) mk_cfgrtr


$(TARGET_LIB): mkdir_objs $(OBJS)
	echo -Input=$(OBJS) | sed "s/ /,/g" > $(OBJ_DIR)/subcmd.txt
	echo -OUtput=$(TARGET_LIB) >> $(OBJ_DIR)/subcmd.txt
	echo -FOrm=Library >> $(OBJ_DIR)/subcmd.txt
	$(RM) -f $(TARGET_LIB)
	$(LIBR) -SU=$(OBJ_DIR)/subcmd.txt

mkdir_objs:
	$(MKDIR) -p $(OBJS_DIR)


mk_cfgrtr:
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

clean:
	$(RM) -f $(TARGET) $(OBJS) $(CFGRTR) $(OBJS_DIR)/*.lst
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean

#lint:
#	$(LINT) $(LINTFLAGS) $(CSRCS)

#depend:
#	$(DEPEND) $(CFLAGS) $(CSRCS) | sed 's?: ?:\t?' | sed 's?\\?\/?g' | sed 's?^?$(OBJS_DIR)\/?' | sed 's?:[\t ]+?\t?' | sed 's? ?\\ ?' > $(OBJS_DIR)/depend.inc


-include $(OBJS_DIR)/depend.inc


# 推論規則
$(OBJS_DIR)/%.obj :: %.c
	$(CC) $(CFLAGS) $< -OB=$@ -List=$(@:%.obj=%.lst)

$(OBJS_DIR)/%.obj :: %.src
	$(ASM) $(AFLAGS) $< -OB=$@


# end of file
