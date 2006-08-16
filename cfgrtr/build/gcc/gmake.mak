# -----------------------------------------------------------------------------
#  HOS-V4a configulator
#
#                                       Copyright (C) 1998-2006 by Project HOS 
#                                       http://sourceforge.jp/projects/hos/
# -----------------------------------------------------------------------------



# ツール
CC   = g++
LINK = g++


# オプション
CFLAGS = -O2 -pipe -Wall -I../../include -I../../../kernel/include -I../../../kernel/include/arch/proc/$(ARCH_PROC) -I../../../kernel/include/arch/irc/$(ARCH_IRC)
LFLAGS = 


# ターゲット
TARGET ?= h4acfg

# オブジェクトディレクトリ
OBJS_DIR = objs_$(TARGET)


# オブジェクトファイル
OBJS = $(OBJS_DIR)/hos4cfg.o \
       $(OBJS_DIR)/analyze.o \
       $(OBJS_DIR)/parpack.o \
       $(OBJS_DIR)/read.o    \
       $(OBJS_DIR)/defercd.o \
       $(OBJS_DIR)/intstk.o  \
       $(OBJS_DIR)/idlstk.o  \
       $(OBJS_DIR)/knlheap.o \
       $(OBJS_DIR)/maxtpri.o \
       $(OBJS_DIR)/apidef.o  \
       $(OBJS_DIR)/apiinc.o  \
       $(OBJS_DIR)/cretsk.o  \
       $(OBJS_DIR)/deftex.o  \
       $(OBJS_DIR)/cresem.o  \
       $(OBJS_DIR)/creflg.o  \
       $(OBJS_DIR)/credtq.o  \
       $(OBJS_DIR)/crembx.o  \
       $(OBJS_DIR)/crempf.o  \
       $(OBJS_DIR)/crembf.o  \
       $(OBJS_DIR)/timtic.o  \
       $(OBJS_DIR)/crecyc.o  \
       $(OBJS_DIR)/crealm.o  \
       $(OBJS_DIR)/defexc.o  \
       $(OBJS_DIR)/attini.o  \
       $(OBJS_DIR)/definh.o  \
       $(OBJS_DIR)/attisr.o


VPATH=../../source


# ターゲット生成
$(TARGET): mkdir_objs $(OBJS)
	$(LINK) $(LFLAGS) $(OBJS) -o $(TARGET)

mkdir_objs:
	mkdir -p $(OBJS_DIR)

clean:
	rm -f $(TARGET) $(TARGET).exe $(OBJS)

$(OBJS_DIR)/%.o :: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@



# end of file
