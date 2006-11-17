# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{特殊文字定義}
comma:= ,
empty:=
space:= $(empty) $(empty)


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) -r $(TARGET_LIB) $(OBJS)

# %jp{Cコンパイル}
$(OBJS_DIR)/%.$(OBJ_EXT) :: %.$(C_EXT)
	$(CMD_CC) $(CFLAGS) -c $< -o $@

# %jp{アセンブル}
$(OBJS_DIR)/%.$(OBJ_EXT) :: %.$(ASM_EXT)
	$(CMD_ASM) $(CFLAGS) -c $< -o $@


# end of file
