# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	$(CMD_RM) -f $(TARGET_LIB)
	$(CMD_LIBR) $(TARGET_LIB) -c $(OBJS)


# %jp{Cコンパイル}
$(OBJS_DIR)/%.$(OBJ_EXT) :: %.$(C_EXT)
	$(CMD_CC)  $(CFLAGS) $< -o $@


# %jp{アセンブル}
$(OBJS_DIR)/%.$(OBJ_EXT) :: %.$(ASM_EXT)
	$(CMD_ASM) $(AFLAGS) $< -o $@


# end of file
