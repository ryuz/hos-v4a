# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) $(OBJS) $(LIBS) $(LNFLAGS2) -o $(TARGET_EXE)


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_OBJCNV) -O srec $(TARGET_EXE) $(TARGET_MOT)


# %jp{インテルHEX形式ファイル生成}%en{Intel HEX format file}
$(TARGET_HEX): $(TARGET_EXE)
	$(CMD_OBJCNV) -O ihex $(TARGET_EXE) $(TARGET_HEX)


# %jp{プレーンバイナリ形式ファイル生成}%en{Plain Binary}
$(TARGET_BIN): $(TARGET_EXE)
	$(CMD_OBJCNV) -O binary $(TARGET_EXE) $(TARGET_BIN)


# %jp{ライブラリ生成}%en{Library}
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) -r $(TARGET_LIB) $(OBJS)

# %jp{Cコンパイル}%en{C Compile}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	$(CMD_CC) $(CFLAGS) -c $< -Fo=$@

# %jp{アセンブル}%en{Assemble}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(AFLAGS) -o $@ $<


# end of file
