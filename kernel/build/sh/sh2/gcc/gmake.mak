# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2
#
# $Id: gmake.mak,v 1.1 2006-08-16 16:27:03 ryuz Exp $
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# ターゲット名
TARGET    ?= libhosv4a

# アーキテクチャパス
ARCH_PROC ?= sh/sh2
ARCH_IRC  ?= none
ARCH_CC   ?= gcc

# ディレクトリ定義
TOP_DIR      = ../../../../..
KNL_DIR      = $(TOP_DIR)/kernel
OBJS_DIR     = objs_$(TARGET)

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
CFGRTR       = h4acfg-sh2


# 共通設定インクルード
include $(TOP_DIR)/kernel/build/common/gmake.inc


# ターゲットライブラリファイル名
TARGET_LIB = $(TARGET).a

# アセンブラファイルの追加
ASRCS += $(SRC_PROC_ASM_DIR)/ctxctl.S		\
         $(SRC_PROC_ASM_DIR)/intctl.S


# C言語ファイルの追加
# CSRCS += $(SRC_IRC_DIR)/intc.c


# 検索パスの追加
VPATH := $(VPATH):$(SRC_PROC_DIR):$(SRC_PROC_DIR):$(SRC_PROC_ASM_DIR):$(SRC_IRC_DIR):$(SRC_IRC_ASM_DIR)


# Tools
CC     = sh-elf-gcc
ASM    = sh-elf-gcc
LIBR   = sh-elf-ar
DEPEND = sh-elf-gcc -M
LINT   = splint
AWK    = gawk
MKDIR  = mkdir
RM     = rm


# オプションフラグ
AFLAGS    += -c -m2
CFLAGS    += -c -m2 -Wall -I$(INC_KNL_DIR) -I$(INC_PROC_DIR) -I$(INC_IRC_DIR)
LFLAGS    += 
LINTFLAGS += -weak -I$(INC_KNL_DIR) -I$(INC_PROC_DIR) -I$(INC_IRC_DIR)



# オブジェクトファイル
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(notdir $(CSRCS)))))   \
       $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(notdir $(ASRCS)))))


all: $(TARGET_LIB) mk_cfgrtr


$(TARGET_LIB): mkdir_objs $(OBJS)
	$(LIBR) -r $(TARGET_LIB) $(OBJS)

mkdir_objs:
	$(MKDIR) -p $(OBJS_DIR)


mk_cfgrtr:
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

clean:
	$(RM) -f $(TARGET) $(OBJS) $(CFGRTR)
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean

lint:
	$(LINT) $(LINTFLAGS) $(CSRCS)

depend:
	$(DEPEND) $(CFLAGS) $(CSRCS) | sed 's?: ?:\t?' | sed 's?\\?\/?g' | sed 's?^?$(OBJS_DIR)\/?' | sed 's?:[\t ]+?\t?' | sed 's? ?\\ ?' > $(OBJS_DIR)/depend.inc


-include $(OBJS_DIR)/depend.inc


# 推論規則
$(OBJS_DIR)/%.o :: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJS_DIR)/%.o :: %.S
	$(ASM) $(AFLAGS) $< -o $@


# end of file
