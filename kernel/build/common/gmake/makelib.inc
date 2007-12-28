# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{オプション解析}
# --------------------------------------

ifeq ($(DEBUG),Yes)
# %jp{デバッグ指定があればデバッグ版作成}
TARGET := $(TARGET)dbg
CFLAGS += $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
AFLAGS += $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
C_DEFS += _KERNEL_DEBUG
A_DEFS += _KERNEL_DEBUG
else
ifeq ($(OPT_SPEED),Yes)
# %jp{速度最適化指定があれば速度優先}%en{optimize speed}
CFLAGS += $(CFLAGS_OPT_SPEED)
AFLAGS += $(AFLAGS_OPT_SPEED)
else
ifeq ($(OPT_SIZE),Yes)
# %jp{サイズ優先適化指定があればサイズ優先}%en{optimize size}
CFLAGS += $(CFLAGS_OPT_SIZE)
AFLAGS += $(AFLAGS_OPT_SIZE)
else
# %jp{デフォルトで通常の最適化}%en{optimize}
CFLAGS += $(CFLAGS_OPT_NORMAL)
AFLAGS += $(AFLAGS_OPT_NORMAL)
endif
endif
endif


# %jp{エラーレベル指定}%en{error check level}
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
#  %jp{各種設定}%en{Target}
# --------------------------------------


# %jp{ターゲットライブラリファイル名}
TARGET_LIB = $(TARGET).$(EXT_LIB)


# %jp{オブジェクトファイル}
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(CSRCS)))))   \
       $(addprefix $(OBJS_DIR)/, $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(ASRCS)))))



# %jp{サーチパス設定}
VPATH = $(subst $(space),:,$(SRC_DIRS))



# --------------------------------------
#  %jp{ルール}%en{Rules}
# --------------------------------------

# %jp{ライブラリ生成}%en{library}
.PHONY : makelib_all
makelib_all: $(CSRCS) $(ASRCS) makelib_mkobjsdir $(TARGET_LIB)


# %jp{クリーンナップ}%en{clean}
.PHONY : makelib_clean
makelib_clean:
	$(CMD_RM) -f $(TARGET_LIB) $(OBJS)


# %jp{依存関係の生成}%en{depend}
DEPFLAGS += -MM $(patsubst %,-I%,$(INC_DIRS))
.PHONY : makelib_depend
makelib_depend: makelib_mkobjsdir
	$(CMD_DEPEND) $(DEPFLAGS) $(CSRCS) | sed -e 's?^\(.*\):?$(OBJS_DIR)/\1:?g' > $(OBJS_DIR)/depend.inc

-include $(OBJS_DIR)/depend.inc


# %jp{オブジェクト出力ディレクトリ作成}%en{objects directory}
.PHONY : makelib_mkobjsdir
makelib_mkobjsdir:
	$(CMD_MKDIR) -p $(OBJS_DIR)


# %jp{ソースのコピー}%en{spurce files copy}
ifdef SRCCPYDIR
.PHONY : makelib_srccpy
makelib_srccpy:
	$(CMD_CP) -t $(SRCCPYDIR) $(ASRCS) $(CSRCS)
endif



# end of file
