# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common include file for library file
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{ルール}%en{Rules}
# --------------------------------------

# %jp{ライブラリ生成}%en{library}
makelib_all: mkdir_objs makelib_srcobjcp $(TARGET_LIB)


# %jp{クリーンナップ}
makelib_clean:
	-$(CMD_RM) $(TARGET_LIB)
	-$(CMD_RM) $(OBJS_DIR)\*.$(EXT_OBJ)


# %jp{オブジェクト出力ディレクトリ作成}%en{objects directory}
mkdir_objs:
	IF NOT EXIST $(OBJS_DIR) $(CMD_MKDIR) $(OBJS_DIR)



# end of file
