# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# %jp{ライブラリ生成}%en{Library}
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) /OUT:$(TARGET_LIB) $(OBJS)


# %jp{Cコンパイル}
{$(OBJS_DIR)}.c{$(OBJS_DIR)}.obj :
	$(CMD_CC) $(CFLAGS) $< /Fo$@


# %jp{アセンブル}
{$(OBJS_DIR)}.asm{$(OBJS_DIR)}.obj :
	$(CMD_ASM) $(AFLAGS) $< -OB=$@



# end of file
