# ----------------------------------------------------------------------------
#
#
#
# ----------------------------------------------------------------------------



# ターゲット名
TARGET    ?= libhosv4a

# アーキテクチャパス
ARCH_PROC ?= arm_v4t
ARCH_IRC  ?= arm/ADuC7026



# ディレクトリ定義
TOP_DIR      = ../../../../..
KNL_DIR      = $(TOP_DIR)/kernel
OBJS_DIR     = objs_$(TARGET)

# インクルードディレクトリ定義
INC_KNL_DIR  = $(KNL_DIR)/include
INC_PROC_DIR = $(INC_KNL_DIR)/arch/proc/$(ARCH_PROC)
INC_IRC_DIR  = $(INC_KNL_DIR)/arch/irc/$(ARCH_IRC)

# ソースディレクトリ定義
SRC_KNL_DIR  = $(KNL_DIR)/source
SRC_PROC_DIR = $(SRC_KNL_DIR)/arch/proc/$(ARCH_PROC)
SRC_IRC_DIR  = $(SRC_KNL_DIR)/arch/irc/$(ARCH_IRC)

# コンフィギュレータ定義
CFGRTR_DIR   = $(TOP_DIR)/cfgrtr/build/gcc
CFGRTR       = h4acfg-$(ARCH_PROC)


# 共通設定インクルード
include $(TOP_DIR)/kernel/build/common/gmake.inc


# ターゲットライブラリファイル名
TARGET_LIB = $(TARGET).a

# アセンブラファイルの追加
ASRCS += $(SRC_PROC_DIR)/rvds/armctx.s		\
         $(SRC_PROC_DIR)/rvds/armirq.s


# C言語ファイルの追加
CSRCS += $(SRC_IRC_DIR)/armintc.c


# 検索パスの追加
VPATH := $(VPATH):$(SRC_PROC_DIR):$(SRC_PROC_DIR)/rvct:$(SRC_IRC_DIR)


# Tools
CC     = armcc --thumb
ASM    = armasm
LIBR   = armar
DEPEND = armcc -M
LINT   = splint
MKDIR  = mkdir
RM     = rm


# オプションフラグ
AFLAGS    += --cpu=ARM7TDMI
CFLAGS    += -I$(INC_KNL_DIR) -I$(INC_PROC_DIR) -I$(INC_IRC_DIR) --thumb --apcs /interwork --cpu=ARM7TDMI
LFLAGS    += 
LINTFLAGS += -I$(INC_KNL_DIR) -I$(INC_PROC_DIR) -I$(INC_IRC_DIR) -weak 


# オブジェクトファイル
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(notdir $(CSRCS)))))   \
       $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(notdir $(ASRCS)))))


all: $(TARGET_LIB) $(CFGRTR)


$(TARGET_LIB): mkdir_objs $(OBJS)
	$(LIBR) -r $(TARGET_LIB) $(OBJS)

mkdir_objs:
	$(MKDIR) -p $(OBJS_DIR)


$(CFGRTR):
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC)
	cp $(CFGRTR_DIR)/$(CFGRTR) .

clean:
	$(RM) -f $(TARGET) $(OBJS) $(CFGRTR)
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) clean

lint:
	$(LINT) $(LINTFLAGS) $(CSRCS)

depend:
	$(DEPEND) $(CFLAGS) $(CSRCS) | sed 's?: ?:\t?' | sed 's?\\?\/?g' | sed 's?^?$(OBJS_DIR)\/?' | sed 's?:[\t ]+?\t?' | sed 's? ?\\ ?' > $(OBJS_DIR)/depend.inc


-include $(OBJS_DIR)/depend.inc


# 推論規則
$(OBJS_DIR)/%.o :: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o :: %.s
	$(ASM) $(AFLAGS) $< -o $@


# end of file
