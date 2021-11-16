# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    register offset depend file for GNU make
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

#
# Directories
#

# %jp{ツール格納先ディレクトリ}
TOOLS_DIR  ?= $(TOP_DIR)/tools

# %jp{アセンブラ用データ構造オフセットアドレス算出ツール格納先ディレクトリ}
TOOLS_ASMOFF_DIR  ?= $(TOOLS_DIR)/asm_offset

# %jp{データ構造内オフセットアドレス算出用Cマクロ定義ヘッダ格納先ディレクトリ}
INC_TOOLS_ASMOFF_DIR ?= $(TOOLS_ASMOFF_DIR)/include

#
# File names
#

# %jp{アセンブラ用データ構造オフセットアドレス算出ツールファイル名}
ASMOFF_TOOL_NAME ?= asm-offset.py

#
# File path
#

# %jp{アセンブラ用データ構造オフセットアドレス算出ツールファイルパス}
CMD_ASMOFF_TOOL ?= $(TOOLS_ASMOFF_DIR)/$(ASMOFF_TOOL_NAME)

#
# %jp{関数定義}
#

# @brief オフセットファイルの依存関係生成(共通処理)
# @param[in] $1 生成するオフセットファイル(ヘッダファイル)のパス
# @param[in] $2 オフセットファイル生成時の入力となるCソースファイルへのパス
# @param[in] $3 生成するオフセットファイルの多重インクルード
#               回避マクロ定義に使用するディレクトリへのパス($(TOP_DIR)など)
define __bld_gmk_asmoff_create_depend_common
	$(CMD_CC) $(CFLAGS) -I$(INC_TOOLS_ASMOFF_DIR) -S \
		-o "$(OBJS_DIR)/$(notdir $(patsubst %.c,%.s, $2))" "$<"
	$(CMD_ASMOFF_TOOL) "$(OBJS_DIR)/$(notdir $(patsubst %.c,%.s, $2))" "$1" "$3"
	$(CMD_RM) "$(OBJS_DIR)/$(notdir $(patsubst %.c,%.s, $2))"
endef


# @brief オフセットファイルの依存関係生成
# @param[in] $1 生成するオフセットファイル(ヘッダファイル)のパス
# @param[in] $2 オフセットファイル生成時の入力となるCソースファイルへのパス
# @note  ターゲット($@)にオフセットファイルヘッダファイルのパス名
#        依存ファイルの第1パラメタ($<)にオフセットファイル生成元
#        Cソースファイルのパス名を指定してMakefile中以下のように使用する
#  offset.h: offset.c
#	$(call _bld_gmk_asmoff_create_depend,$@,$<)
define _bld_gmk_asmoff_create_depend
	$(call __bld_gmk_asmoff_create_depend_common,$@,$<,$(TOP_DIR))
endef



# end of file
