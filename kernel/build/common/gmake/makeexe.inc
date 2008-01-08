# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{オプション解析}
# --------------------------------------

ifeq ($(DEBUG),Yes)
# %jp{デバッグ指定があればデバッグ版作成}
AFLAGS += $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
CFLAGS += $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
else
ifeq ($(OPT_SPEED),Yes)
# %jp{速度最適化指定があれば速度優先}
AFLAGS += $(AFLAGS_OPT_SPEED)
CFLAGS += $(CFLAGS_OPT_SPEED)
else
ifeq ($(OPT_SIZE),Yes)
# %jp{サイズ優先適化指定があればサイズ優先}
AFLAGS += $(AFLAGS_OPT_SIZE)
CFLAGS += $(CFLAGS_OPT_SIZE)
else
# %jp{デフォルトで通常の最適化}
AFLAGS += $(AFLAGS_OPT_NORMAL)
CFLAGS += $(CFLAGS_OPT_NORMAL)
endif
endif
endif



# --------------------------------------
#  %jp{カーネルライブラリの選択}
# --------------------------------------

KERNEL_LIB    ?= libhosv4a
KERNEL_MAKOPT ?=

# %jp{デバッグ指定}
KERNEL_MAKOPT += DEBUG=$(KERNEL_DEBUG)
ifeq ($(KERNEL_DEBUG),Yes)
KERNEL_LIB := $(KERNEL_LIB)dbg
endif


# %jp{エラーレベル指定}
KERNEL_MAKOPT += ERRLEVEL=$(KERNEL_ERRLEVEL)
ifeq ($(KERNEL_ERRLEVEL),0)
KERNEL_LIB := $(KERNEL_LIB)er0
endif
ifeq ($(KERNEL_ERRLEVEL),1)
KERNEL_LIB := $(KERNEL_LIB)er1
endif
ifeq ($(KERNEL_ERRLEVEL),2)
KERNEL_LIB := $(KERNEL_LIB)er2
endif
ifeq ($(KERNEL_ERRLEVEL),3)
KERNEL_LIB := $(KERNEL_LIB)er3
endif
ifeq ($(KERNEL_ERRLEVEL),4)
KERNEL_LIB := $(KERNEL_LIB)er4
endif


# %jp{カーネルフック指定}%en{kernel hook}
KERNEL_MAKOPT += HOK_TSK=$(KERNEL_HOK_TSK)
ifeq ($(KERNEL_HOK_TSK),Yes)
KERNEL_LIB := $(KERNEL_LIB)tsk
endif
KERNEL_MAKOPT += HOK_INH=$(KERNEL_HOK_INH)
ifeq ($(KERNEL_HOK_INH),Yes)
KERNEL_LIB := $(KERNEL_LIB)inh
endif
KERNEL_MAKOPT += HOK_INT=$(KERNEL_HOK_INT)
ifeq ($(KERNEL_HOK_INT),Yes)
KERNEL_LIB := $(KERNEL_LIB)isr
endif



# --------------------------------------
#  %jp{カーネル利用の設定}
# --------------------------------------

INC_DIRS += $(KERNEL_DIR)/include
LIBS     += $(KERNEL_BUILD_DIR)/$(KERNEL_LIB).$(EXT_LIB)



# --------------------------------------
#  %jp{各種設定}
# --------------------------------------

# 基本オプション設定
CFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)


# %jp{サーチパス設定}
VPATH = $(subst $(space),:,$(SRC_DIRS))


# %jp{オブジェクトファイル}
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(ASRCS)))))	\
       $(addprefix $(OBJS_DIR)/, $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(CSRCS)))))



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

# %jp{ライブラリ生成}
.PHONY : makeexe_all
makeexe_all: kernel_make makeexe_mkobjsdir $(CSRCS) $(ASRCS)


# %jp{クリーンナップ}
.PHONY : makeexe_clean
makeexe_clean:
	$(CMD_RM) -f $(TARGET_LIB) $(OBJS)


# %jp{オブジェクト出力ディレクトリ作成}
.PHONY : makeexe_mkobjsdir
makeexe_mkobjsdir:
	$(CMD_MKDIR) -p $(OBJS_DIR)


# %jp{依存関係の生成}
DEPFLAGS += -MM $(patsubst %,-I%,$(INC_DIRS))
.PHONY : makeexe_depend
makeexe_depend: makeexe_mkobjsdir
	$(CMD_DEPEND) $(DEPFLAGS) $(CSRCS) | sed -e 's?^\(.*\):?$(OBJS_DIR)/\1:?g' > $(OBJS_DIR)/depend.inc

-include $(OBJS_DIR)/depend.inc


# %jp{ソースのコピー}
ifdef SRCCPYDIR
.PHONY : makeexe_srccpy
makeexe_srccpy:
	$(CMD_CP) -t $(SRCCPYDIR) $(ASRCS) $(CSRCS)
endif


# %jp{カーネル生成}
.PHONY : kernel_make
kernel_make:
	make -C $(KERNEL_BUILD_DIR) -f gmake.mak $(KERNEL_MAKOPT)

# %jp{カーネルクリーン}
.PHONY : kernel_clean
kernel_clean:
	make -C $(KERNEL_BUILD_DIR) -f gmake.mak $(KERNEL_MAKOPT)clean

# %jp{カーネルdepend}
.PHONY : kernel_depend
kernel_depend:
	make -C $(KERNEL_BUILD_DIR) -f gmake.mak $(KERNEL_MAKOPT) depend



# end of file
