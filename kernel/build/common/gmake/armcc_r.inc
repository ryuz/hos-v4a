# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) -o $(TARGET_EXE) $(OBJS) $(LIBS)


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_OBJCNV) --m32 --output $(TARGET_MOT) $(TARGET_EXE)


# %jp{インテルHEX形式ファイル生成}%en{Intel HEX format file}
$(TARGET_HEX): $(TARGET_EXE)
	$(CMD_OBJCNV) --i32 --output $(TARGET_HEX) $(TARGET_EXE)


# %jp{プレーンバイナリ形式ファイル生成}%en{Plain Binary}
$(TARGET_BIN): $(TARGET_EXE)
	$(CMD_OBJCNV) --bin --output $(TARGET_BIN) $(TARGET_EXE)


# %jp{ライブラリ生成}%en{Library}
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) $(ARFLAGS) --create $(TARGET_LIB) $(OBJS)


# %jp{Cコンパイル}%en{C Compile}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	$(CMD_CC) $(CFLAGS) -c $< -o $@


# %jp{アセンブル}%en{Assemble}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(AFLAGS) $< -o $@


# end of file
