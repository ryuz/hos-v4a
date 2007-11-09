# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) -o $(TARGET_EXE) $(OBJS) $(patsubst %,-l%,$(LIBS)) $(patsubst %,-l%,$(STD_LIBS))


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	$(CMD_RM) -f $(TARGET_LIB)
	$(CMD_LIBR) $(TARGET_LIB) -c $(OBJS)


# %jp{Cコンパイル}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	$(CMD_CC)  $(CFLAGS) $< -o $@


# %jp{アセンブル}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(AFLAGS) $< -o $@


# end of file
