# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for MN1030 Series
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# ターゲット名
TARGET    ?= libhosv4a

# アーキテクチャパス
ARCH_PROC ?= mn103/mn1030
ARCH_IRC  ?= none
ARCH_CC   ?= gcc


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
CFGRTR       = h4acfg-mn1030


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
CC     = mn10300-elf-gcc
ASM    = mn10300-elf-gcc
LIBR   = mn10300-elf-ar
DEPEND = mn10300-elf-gcc -M
LINT   = splint
AWK    = gawk
LINT   = splint
MKDIR  = mkdir
RM     = rm


# オプションフラグ
AFLAGS    += -c -Wall
CFLAGS    += -I$(INC_KNL_DIR) -I$(INC_PROC_DIR) -I$(INC_IRC_DIR)	\
             -c -Wall
LFLAGS    += 
LINTFLAGS += -I$(INC_KNL_DIR) -I$(INC_PROC_DIR) -I$(INC_IRC_DIR) -weak 


# オブジェクトファイル
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(notdir $(CSRCS)))))   \
       $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(notdir $(ASRCS)))))


all: $(ASRCS) $(CSRCS) $(TARGET_LIB) $(CFGRTR)


$(TARGET_LIB): mkdir_objs $(OBJS)
	$(LIBR) -r $(TARGET_LIB) $(OBJS)

mkdir_objs:
	$(MKDIR) -p $(OBJS_DIR)


$(CFGRTR):
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

clean:
	$(RM) -f $(TARGET) $(OBJS) $(CFGRTR)
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean

lint:
	$(LINT) $(LINTFLAGS) $(CSRCS)

depend:
	$(DEPEND) $(CFLAGS) $(CSRCS) | awk '/^[^ ]/{print "$(OBJS_DIR)/"$$0} /^ /{print $$0}' > $(OBJS_DIR)/depend.inc


-include $(OBJS_DIR)/depend.inc


# 推論規則
$(OBJS_DIR)/%.o :: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o :: %.S
	$(ASM) $(AFLAGS) $< -o $@


# end of file
