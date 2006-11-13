# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{共通設定}
# --------------------------------------

# %jp{特殊文字定義}
comma:= ,
empty:=
space:= $(empty) $(empty)

# %jp{ツール定義}%en{Tools}
ECHO  = echo
MKDIR = mkdir
RM    = rm



# --------------------------------------
#  %jp{オプション解析}
# --------------------------------------

ifeq ($(DEBUG),Yes)
# %jp{デバッグ指定があればデバッグ版作成}
TARGET := $(TARGET)dbg
AFLAGS += $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
CFLAGS += $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
else
ifeq ($(OPT_SPEED),Yes)
# %jp{速度最適化指定があれば速度優先}
AFLAGS += $(AFLAGS_OPT_SPEED)
CFLAGS += $(AFLAGS_OPT_SPEED)
else
ifeq ($(OPT_SIZE),Yes)
# %jp{サイズ優先適化指定があればサイズ優先}
AFLAGS += $(AFLAGS_OPT_SIZE)
CFLAGS += $(AFLAGS_OPT_SIZE)
else
# %jp{デフォルトで通常の最適化}
AFLAGS += $(AFLAGS_OPT_NORMAL)
CFLAGS += $(AFLAGS_OPT_NORMAL)
endif
endif
endif

# %jp{エラーレベル指定}
ifeq ($(ERRLEVEL),0)
TARGET := $(TARGET)er0
C_DEFS += _KERNEL_ERRLEVEL=0
endif
ifeq ($(ERRLEVEL),1)
TARGET := $(TARGET)er1
C_DEFS += _KERNEL_ERRLEVEL=1
endif
ifeq ($(ERRLEVEL),2)
TARGET := $(TARGET)er2
C_DEFS += _KERNEL_ERRLEVEL=2
endif
ifeq ($(ERRLEVEL),3)
TARGET := $(TARGET)er3
C_DEFS += _KERNEL_ERRLEVEL=3
endif
ifeq ($(ERRLEVEL),4)
TARGET := $(TARGET)er4
C_DEFS += _KERNEL_ERRLEVEL=4
endif


# --------------------------------------
#  %jp{各種設定}
# --------------------------------------

# 基本オプション設定
CFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)

# %jp{サーチパス設定}
VPATH = $(subst $(space),:,$(SRC_DIRS))

# %jp{ターゲットライブラリファイル名}
TARGET_LIB = $(TARGET).$(LIB_EXT)

# %jp{オブジェクトファイル}
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .$(OBJ_EXT), $(basename $(notdir $(CSRCS)))))   \
       $(addprefix $(OBJS_DIR)/, $(addsuffix .$(OBJ_EXT), $(basename $(notdir $(ASRCS)))))


# --------------------------------------
#  %jp{ルール}
# --------------------------------------

# %jp{all処理}
.PHONY : all_makelib
all_makelib: $(CSRCS) $(ASRCS) mkdir_objs $(TARGET_LIB)

# %jp{クリーンナップ}
.PHONY : clean_makelib
clean_makelib:
	$(RM) -f $(TARGET_LIB) $(OBJS)
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean

# %jp{オブジェクト出力ディレクトリ作成}
.PHONY : mkdir_objs
mkdir_objs:
	$(MKDIR) -p $(OBJS_DIR)



# end of file
