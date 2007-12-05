# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	-del $(TARGET_LIB)
	$(CMD_LIBR) $(TARGET_LIB) -c $(OBJS)


# %jp{Cコンパイル}
{$(OBJS_DIR)}.c{$(OBJS_DIR)}.ro :
	$(CMD_CC)  $(CFLAGS) $< -o $@


# %jp{アセンブル}
{$(OBJS_DIR)}.as{$(OBJS_DIR)}.ro :
	$(CMD_ASM) $(AFLAGS) $< -o $@


# end of file
