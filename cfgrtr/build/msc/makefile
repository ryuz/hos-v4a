# -----------------------------------------------------------------------------
#  HOS-V4a configulator
#
#                                       Copyright (C) 1998-2007 by Project HOS 
#                                       http://sourceforge.jp/projects/hos/
# -----------------------------------------------------------------------------


# ツール
CC   = cl
LINK = cl


# オプション
CFLAGS = /I..\..\include -I..\..\..\kernel\include         \
         /I..\..\..\kernel\include\arch\proc\$(ARCH_PROC)  \
         /I..\..\..\kernel\include\arch\irc\$(ARCH_IRC)    \
         /GS-
LFLAGS = 


# ターゲット
!ifndef TARGET
TARGET = h4acfg
!endif


# オブジェクトディレクトリ
OBJS_DIR = objs_$(TARGET)


# オブジェクトファイル
OBJS = $(OBJS_DIR)\h4acfg.obj  \
       $(OBJS_DIR)\analyze.obj \
       $(OBJS_DIR)\parpack.obj \
       $(OBJS_DIR)\read.obj    \
       $(OBJS_DIR)\defercd.obj \
       $(OBJS_DIR)\intstk.obj  \
       $(OBJS_DIR)\dpcque.obj  \
       $(OBJS_DIR)\idlstk.obj  \
       $(OBJS_DIR)\knlheap.obj \
       $(OBJS_DIR)\maxtpri.obj \
       $(OBJS_DIR)\apidef.obj  \
       $(OBJS_DIR)\apiinc.obj  \
       $(OBJS_DIR)\cretsk.obj  \
       $(OBJS_DIR)\deftex.obj  \
       $(OBJS_DIR)\cresem.obj  \
       $(OBJS_DIR)\creflg.obj  \
       $(OBJS_DIR)\credtq.obj  \
       $(OBJS_DIR)\crembx.obj  \
       $(OBJS_DIR)\cremtx.obj  \
       $(OBJS_DIR)\crempf.obj  \
       $(OBJS_DIR)\crembf.obj  \
       $(OBJS_DIR)\timtic.obj  \
       $(OBJS_DIR)\crecyc.obj  \
       $(OBJS_DIR)\crealm.obj  \
       $(OBJS_DIR)\defexc.obj  \
       $(OBJS_DIR)\attini.obj  \
       $(OBJS_DIR)\definh.obj  \
       $(OBJS_DIR)\attisr.obj


all: mkdir_objs $(TARGET).exe

# ターゲット生成
$(TARGET).exe: $(OBJS)
	echo $(TARGET)
	$(LINK) $(LFLAGS) $(OBJS) -o $(TARGET).exe

# ディレクトリ生成
mkdir_objs:
	@IF NOT EXIST $(OBJS_DIR) mkdir $(OBJS_DIR)

clean:
	-del $(TARGET) $(TARGET).exe $(OBJS)

{..\..\source}.cpp{$(OBJS_DIR)}.obj :
	cl $(CFLAGS) /c $< /Fo$@



# end of file
