# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

define NEW-LINES

	
endef


$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) $(OBJS) $(LIBS) -o $(TARGET_EXE)


$(TARGET_ASC): $(TARGET_EXE)
	$(CMD_OBJCNV) -O srec $(TARGET_EXE) $(TARGET_ASC)


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	$(foreach obj,$(OBJS),$(CMD_LIBR) -a $(TARGET_LIB) $(obj)$(NEW-LINES))

# %jp{Cコンパイル}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	$(CMD_CC) $(CFLAGS) -c $< -o $@

# %jp{アセンブル}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(AFLAGS) -c $< -o $@


# end of file
