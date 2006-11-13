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
#{$(VPATH: =,)}.c{$(OBJS_DIR)}.obj :
#	$(CMD_CC) $(CFLAGS) $< -OB=$@

{..\..\..\..\..\kernel\source\core\que,..\..\..\..\..\kernel\source\core\dsp,$(VPATH)}.c{$(OBJS_DIR)}.obj :
	$(CMD_CC) $(CFLAGS) $< -OB=$@

{..\..\..\..\..\kernel\source\arch\proc\h8/h8300ha/ch38}.src{$(OBJS_DIR)}.obj :
	$(CMD_ASM) $(AFLAGS) $< -OB=$@


#.c.obj:
#	$(CMD_CC) $(CFLAGS) $< -OB=$@

#.src.obj:
#	$(CMD_ASM) $(AFLAGS) $< -OB=$@


# %jp{アセンブル}
#{$(VPATH: =,)}.src{$(OBJS_DIR)}.obj :
#	$(CMD_ASM) $(AFLAGS) $< -OB=$@


# end of file
