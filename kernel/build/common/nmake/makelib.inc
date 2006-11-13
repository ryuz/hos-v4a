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

!ifdef DEBUG
# %jp{デバッグ指定があればデバッグ版作成}
TARGET = $(TARGET)dbg
AFLAGS = $(AFLAGS) $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
CFLAGS = $(CFLAGS) $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
!elseifdef OPT_SPEED
# %jp{速度最適化指定があれば速度優先}
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_SPEED)
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_SPEED)
!elseifdef OPT_SIZE
# %jp{サイズ優先適化指定があればサイズ優先}
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_SIZE)
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_SIZE)
!else
# %jp{デフォルトで通常の最適化}
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_NORMAL)
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_NORMAL)
!endif


# --------------------------------------
#  %jp{各種マクロ文字の正規化}
# --------------------------------------

ASRC_DIRS = $(ASRC_DIRS:	= )
ASRC_DIRS = $(ASRC_DIRS:  = )
ASRC_DIRS = $(ASRC_DIRS:  = )
ASRC_DIRS = $(ASRC_DIRS:  = )
ASRC_DIRS = @$(ASRC_DIRS)@
ASRC_DIRS = $(ASRC_DIRS:@ =)
ASRC_DIRS = $(ASRC_DIRS: @=)
ASRC_DIRS = $(ASRC_DIRS:@=)

CSRC_DIRS = $(CSRC_DIRS:	= )
CSRC_DIRS = $(CSRC_DIRS:  = )
CSRC_DIRS = $(CSRC_DIRS:  = )
CSRC_DIRS = $(CSRC_DIRS:  = )
CSRC_DIRS = @$(CSRC_DIRS)@
CSRC_DIRS = $(CSRC_DIRS:@ =)
CSRC_DIRS = $(CSRC_DIRS: @=)
CSRC_DIRS = $(CSRC_DIRS:@=)

CSRC1_DIRS = $(CSRC1_DIRS:	= )
CSRC1_DIRS = $(CSRC1_DIRS:  = )
CSRC1_DIRS = $(CSRC1_DIRS:  = )
CSRC1_DIRS = $(CSRC1_DIRS:  = )
CSRC1_DIRS = @$(CSRC1_DIRS)@
CSRC1_DIRS = $(CSRC1_DIRS:@ =)
CSRC1_DIRS = $(CSRC1_DIRS: @=)
CSRC1_DIRS = $(CSRC1_DIRS:@=)

CSRC2_DIRS = $(CSRC2_DIRS:	= )
CSRC2_DIRS = $(CSRC2_DIRS:  = )
CSRC2_DIRS = $(CSRC2_DIRS:  = )
CSRC2_DIRS = $(CSRC2_DIRS:  = )
CSRC2_DIRS = @$(CSRC2_DIRS)@
CSRC2_DIRS = $(CSRC2_DIRS:@ =)
CSRC2_DIRS = $(CSRC2_DIRS: @=)
CSRC2_DIRS = $(CSRC2_DIRS:@=)

CSRC3_DIRS = $(CSRC3_DIRS:	= )
CSRC3_DIRS = $(CSRC3_DIRS:  = )
CSRC3_DIRS = $(CSRC3_DIRS:  = )
CSRC3_DIRS = $(CSRC3_DIRS:  = )
CSRC3_DIRS = @$(CSRC3_DIRS)@
CSRC3_DIRS = $(CSRC3_DIRS:@ =)
CSRC3_DIRS = $(CSRC3_DIRS: @=)
CSRC3_DIRS = $(CSRC3_DIRS:@=)

CSRC4_DIRS = $(CSRC4_DIRS:	= )
CSRC4_DIRS = $(CSRC4_DIRS:  = )
CSRC4_DIRS = $(CSRC4_DIRS:  = )
CSRC4_DIRS = $(CSRC4_DIRS:  = )
CSRC4_DIRS = @$(CSRC4_DIRS)@
CSRC4_DIRS = $(CSRC4_DIRS:@ =)
CSRC4_DIRS = $(CSRC4_DIRS: @=)
CSRC4_DIRS = $(CSRC4_DIRS:@=)

CSRC5_DIRS = $(CSRC5_DIRS:	= )
CSRC5_DIRS = $(CSRC5_DIRS:  = )
CSRC5_DIRS = $(CSRC5_DIRS:  = )
CSRC5_DIRS = $(CSRC5_DIRS:  = )
CSRC5_DIRS = @$(CSRC5_DIRS)@
CSRC5_DIRS = $(CSRC5_DIRS:@ =)
CSRC5_DIRS = $(CSRC5_DIRS: @=)
CSRC5_DIRS = $(CSRC5_DIRS:@=)

OBJS = $(OBJS:	= )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = @$(OBJS)@
OBJS = $(OBJS:@ =)
OBJS = $(OBJS: @=)
OBJS = $(OBJS:@=)



# --------------------------------------
#  %jp{各種設定}
# --------------------------------------

# 基本オプション設定
CFLAGS = $(CFLAGS) $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS = $(AFLAGS) $(AFLAGS_INC) $(AFLAGS_DEF)

# %jp{サーチパス設定}
VPATH = $(SRC_DIRS: =,)

# %jp{ターゲットライブラリファイル名}
TARGET_LIB = $(TARGET).$(LIB_EXT)


# --------------------------------------
#  %jp{ルール}
# --------------------------------------

# %jp{all処理}
all_makelib: $(CSRCS) $(ASRCS) mkdir_objs $(TARGET_LIB)
	echo $(TARGET_LIB)

# %jp{クリーンナップ}
clean_makelib:
	-$(CMD_RM) $(TARGET_LIB) $(OBJS)

# %jp{オブジェクト出力ディレクトリ作成}
mkdir_objs:
	-$(CMD_MKDIR) $(OBJS_DIR)



# end of file
