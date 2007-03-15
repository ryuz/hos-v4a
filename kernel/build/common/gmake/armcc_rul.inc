# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) -o $(TARGET_EXE) $(OBJS) $(LIBS)


# %jp{ASCII形式ファイル生成}%en{ASCII file}
$(TARGET_ASC): $(TARGET_EXE)
	$(CMD_OBJCNV) --m32 --output $(TARGET_ASC) $(TARGET_EXE)


# %jp{プレーンバイナリ形式ファイル生成}%en{Plain Binary}
$(TARGET_BIN): $(TARGET_EXE)
	$(CMD_OBJCNV) --bin --output $(TARGET_ASC) $(TARGET_EXE)


# %jp{ライブラリ生成}%en{Library}
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) $(ARFLAGS) --create $(TARGET_LIB) $(OBJS)


# %jp{Cコンパイル}%en{C Compile}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	$(CMD_CC) $(CFLAGS) -c $< -o $@


# %jp{アセンブル}%en{Assemble}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(AFLAGS) $< -o $@


# %jp{依存関係}%en{makedepend}
depend:
	$(CMD_DEPEND) $(DEPFLAGS) $(CSRCS) | sed -e 's?^\(.*\):?$(OBJS_DIR)/\1:?g' > $(OBJS_DIR)/depend.inc


# end of file
