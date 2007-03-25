# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	-del $(TARGET_LIB)
	$(CMD_LIBR) -subcommand=<<
-Input=$(OBJS: =,)
-OUtput=$(TARGET_LIB)
-FOrm=Library
<<


# %jp{Cコンパイル}
{$(OBJS_DIR)}.c{$(OBJS_DIR)}.obj :
	$(CMD_CC) $(CFLAGS) $< -OB=$@

# %jp{アセンブル}
{$(OBJS_DIR)}.src{$(OBJS_DIR)}.obj :
	$(CMD_ASM) $(AFLAGS) $< -OB=$@


# end of file
