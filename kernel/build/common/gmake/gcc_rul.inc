# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) $(OBJS) $(LIBS) -o $(TARGET_EXE)


$(TARGET_ASC): $(TARGET_EXE)
	$(CMD_OBJCNV) -O srec $(TARGET_EXE) $(TARGET_ASC)


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) -r $(TARGET_LIB) $(OBJS)

# %jp{Cコンパイル}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	$(CMD_CC) $(CFLAGS) -c $< -o $@

# %jp{アセンブル}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(CFLAGS) -c $< -o $@


# end of file
