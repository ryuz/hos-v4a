# -----------------------------------------------------------------------------
#  Hyper Operating System V4  コンフィギュレーター                             
#   Borland-C++ Version 5.5 用 メイクファイル                                  
#                                                                              
#                                       Copyright (C) 1998-2006 by Project HOS 
#                                       http://sourceforge.jp/projects/hos/    
# -----------------------------------------------------------------------------


# ツール
CC   = bcc32
LINK = bcc32


# オプション
CFLAGS = -c -O2 -I..\..\include -I..\..\..\kernel\include -I..\..\..\kernel\include\arch\proc\$(ARCH_PROC) -I..\..\..\kernel\include\arch\irc\$(ARCH_IRC)
LFLAGS = 


# ターゲット
!ifndef TARGET
TARGET   = h4acfg
!endif

OBJS_DIR = objs\$(TARGET)


# オブジェクトファイル
OBJS = $(OBJS_DIR)\hos4cfg.obj	\
       $(OBJS_DIR)\analyze.obj	\
       $(OBJS_DIR)\parpack.obj	\
       $(OBJS_DIR)\read.obj		\
       $(OBJS_DIR)\defercd.obj	\
       $(OBJS_DIR)\intstk.obj	\
       $(OBJS_DIR)\idlstk.obj	\
       $(OBJS_DIR)\knlheap.obj	\
       $(OBJS_DIR)\maxtpri.obj	\
       $(OBJS_DIR)\apidef.obj	\
       $(OBJS_DIR)\apiinc.obj	\
       $(OBJS_DIR)\cretsk.obj	\
       $(OBJS_DIR)\deftex.obj	\
       $(OBJS_DIR)\cresem.obj	\
       $(OBJS_DIR)\creflg.obj	\
       $(OBJS_DIR)\credtq.obj	\
       $(OBJS_DIR)\crembx.obj	\
       $(OBJS_DIR)\crempf.obj	\
       $(OBJS_DIR)\crembf.obj	\
       $(OBJS_DIR)\timtic.obj	\
       $(OBJS_DIR)\crecyc.obj	\
       $(OBJS_DIR)\crealm.obj	\
       $(OBJS_DIR)\defexc.obj	\
       $(OBJS_DIR)\attini.obj	\
       $(OBJS_DIR)\definh.obj	\
       $(OBJS_DIR)\attisr.obj

.path.cpp = ..\..\source
.path.obj = $(OBJS_DIR)

.suffixes:
.suffixes: .cpp


# ターゲット生成
$(TARGET): mkdir_objs $(OBJS)
	$(LINK) -e$(TARGET) $(OBJS)

mkdir_objs:
	-mkdir objs
	-mkdir $(OBJS_DIR)


# クリーンアップ
clean:
	del $(OBJS) $(TARGET)

# 推論規則
.cpp.obj:
	$(CC) $(CFLAGS) -o$@ $< 


# -----------------------------------------------------------------------------
#  Copyright (C) 1998-2006 by Project HOS                                      
# -----------------------------------------------------------------------------
