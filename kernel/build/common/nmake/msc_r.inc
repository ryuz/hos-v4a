# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# %jp{実行ファイル生成}%en{Executable file}
!ifdef TARGET_EXE
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) $(OBJS) $(LIBS) /Fe$(TARGET_EXE)
!endif


# %jp{ライブラリ生成}%en{Library}
!ifdef TARGET_LIB
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) /OUT:$(TARGET_LIB) $(OBJS)
!endif


# %jp{Cコンパイル}%en{C Compile}
{$(OBJS_DIR)}.c{$(OBJS_DIR)}.obj :
	$(CMD_CC) $(CFLAGS) $< /Fo$@


# %jp{アセンブル}%en{Assemble}
{$(OBJS_DIR)}.asm{$(OBJS_DIR)}.obj :
	$(CMD_ASM) $(AFLAGS) $< /Fo=$@



# end of file
