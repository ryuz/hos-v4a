# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{特殊文字定義}
comma:= ,
empty:=
space:= $(empty) $(empty)

# %jp{ツール定義}%en{Tools}
ECHO  = echo
MKDIR = mkdir
RM    = rm

# %jp{共通ソース定義読込み}
include $(MAKE_INC_DIR)/source.inc

# %jp{オプション設定読込み}
include $(MAKE_INC_DIR)/option.inc


# %jp{サーチパス設定}
VPATH = $(subst $(space),:,$(SRC_DIRS))

# %jp{ターゲットライブラリファイル名}
TARGET_LIB = $(TARGET).$(LIB_EXT)

# %jp{オブジェクトファイル}
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .$(OBJ_EXT), $(basename $(notdir $(CSRCS)))))   \
       $(addprefix $(OBJS_DIR)/, $(addsuffix .$(OBJ_EXT), $(basename $(notdir $(ASRCS)))))


# %jp{all処理}
all: $(CSRCS) $(ASRCS) mkdir_objs $(TARGET_LIB) mk_cfgrtr

# %jp{オブジェクト出力ディレクトリ作成}
mkdir_objs:
	$(MKDIR) -p $(OBJS_DIR)

# %jp{コンフィギュレータ作成}
mk_cfgrtr:
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

clean_common:
	$(RM) -f $(TARGET_LIB) $(OBJS)
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean


include $(MAKE_INC_DIR)/depend.inc


# end of file
