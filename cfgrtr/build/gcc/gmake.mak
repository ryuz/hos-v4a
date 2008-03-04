# -----------------------------------------------------------------------------
#  HOS-V4a configulator
#
#                                       Copyright (C) 1998-2006 by Project HOS 
#                                       http://sourceforge.jp/projects/hos/
# -----------------------------------------------------------------------------



# ツール
CC   = g++
LINK = g++

# ディレクトリ
KERNEL_INC_DIR  = ../../../kernel/include
KERNEL_PROC_DIR = $(KERNEL_INC_DIR)/arch/proc/$(ARCH_PROC)
KERNEL_IRC_DIR  = $(KERNEL_INC_DIR)/arch/irc/$(ARCH_IRC)
CSRC_DIR        = ../../source
INC_DIR         = ../../include
OBJS_DIR        = objs_$(TARGET)


# オプション
CFLAGS  = -O2 -pipe -Wall -I$(INC_DIR) -I$(KERNEL_INC_DIR) -I$(KERNEL_PROC_DIR) -I$(KERNEL_IRC_DIR)
LNFLAGS = 

# ターゲット
TARGET ?= h4acfg


# 実行ファイルの拡張子
ifeq ($(OS),Windows_NT)
EXT_EXE = .exe
else
EXT_EXE =
endif




# オブジェクトファイル
OBJS = $(OBJS_DIR)/h4acfg.o  \
       $(OBJS_DIR)/analyze.o \
       $(OBJS_DIR)/parpack.o \
       $(OBJS_DIR)/read.o    \
       $(OBJS_DIR)/defercd.o \
       $(OBJS_DIR)/intstk.o  \
       $(OBJS_DIR)/dpcque.o  \
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
       $(OBJS_DIR)/cremtx.o  \
       $(OBJS_DIR)/crempf.o  \
       $(OBJS_DIR)/crembf.o  \
       $(OBJS_DIR)/timtic.o  \
       $(OBJS_DIR)/crecyc.o  \
       $(OBJS_DIR)/crealm.o  \
       $(OBJS_DIR)/defexc.o  \
       $(OBJS_DIR)/attini.o  \
       $(OBJS_DIR)/definh.o  \
       $(OBJS_DIR)/attisr.o


VPATH=$(CSRC_DIR)


TARGET_EXE = $(TARGET)$(EXT_EXE)

# all
.PHONY : all
all: mkdir_objs $(TARGET_EXE)

# target
$(TARGET_EXE): $(OBJS)
	$(LINK) $(LNFLAGS) $(OBJS) -o $(TARGET)$(EXT_EXE)

# makedir
.PHONY : mkdir_objs
mkdir_objs:
	mkdir -p $(OBJS_DIR)

# clean
.PHONY : clean
clean:
	rm -f $(TARGET_EXE) $(OBJS)


$(OBJS_DIR)/%.o :: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@



# Header files
HEADERS = $(KERNEL_INC_DIR)/itron.h									\
          $(KERNEL_INC_DIR)/kernel.h								\
          $(KERNEL_INC_DIR)/parser/parssys.h						\
          $(KERNEL_INC_DIR)/parser/parsknl.h						\
          $(KERNEL_INC_DIR)/parser/parserr.h						\
          $(KERNEL_INC_DIR)/parser/parshok.h						\
          $(KERNEL_INC_DIR)/config/cfgsys.h							\
          $(KERNEL_INC_DIR)/config/cfgknl.h							\
          $(KERNEL_INC_DIR)/config/cfgerr.h							\
          $(KERNEL_INC_DIR)/config/cfghok.h							\
          $(KERNEL_INC_DIR)/core/adtq.h								\
          $(KERNEL_INC_DIR)/core/basetyp.h							\
          $(KERNEL_INC_DIR)/core/chkptr.h							\
          $(KERNEL_INC_DIR)/core/cmpl.h								\
          $(KERNEL_INC_DIR)/core/core.h								\
          $(KERNEL_INC_DIR)/core/dsp.h								\
          $(KERNEL_INC_DIR)/core/hep.h								\
          $(KERNEL_INC_DIR)/core/objhdl.h							\
          $(KERNEL_INC_DIR)/core/objid.h							\
          $(KERNEL_INC_DIR)/core/que.h								\
          $(KERNEL_INC_DIR)/core/rdq.h								\
          $(KERNEL_INC_DIR)/core/sys.h								\
          $(KERNEL_INC_DIR)/core/tmq.h								\
          $(KERNEL_INC_DIR)/core/toq.h								\
          $(KERNEL_INC_DIR)/core/dpc.h								\
          $(KERNEL_PROC_DIR)/proc.h									\
          $(KERNEL_PROC_DIR)/procatr.h								\
          $(KERNEL_IRC_DIR)/irc.h									\
          $(KERNEL_IRC_DIR)/ircatr.h								\
          $(KERNEL_INC_DIR)/object/tskobj.h							\
          $(KERNEL_INC_DIR)/object/semobj.h							\
          $(KERNEL_INC_DIR)/object/flgobj.h							\
          $(KERNEL_INC_DIR)/object/dtqobj.h							\
          $(KERNEL_INC_DIR)/object/mbxobj.h							\
          $(KERNEL_INC_DIR)/object/mtxobj.h							\
          $(KERNEL_INC_DIR)/object/mpfobj.h							\
          $(KERNEL_INC_DIR)/object/inhobj.h							\
          $(KERNEL_INC_DIR)/object/isrobj.h							\
          $(INC_DIR)/analyze.h										\
          $(INC_DIR)/apidef.h										\
          $(INC_DIR)/apiinc.h										\
          $(INC_DIR)/attini.h										\
          $(INC_DIR)/attisr.h										\
          $(INC_DIR)/crealm.h										\
          $(INC_DIR)/crecyc.h										\
          $(INC_DIR)/credtq.h										\
          $(INC_DIR)/creflg.h										\
          $(INC_DIR)/crembf.h										\
          $(INC_DIR)/crembx.h										\
          $(INC_DIR)/crempf.h										\
          $(INC_DIR)/cremtx.h										\
          $(INC_DIR)/cresem.h										\
          $(INC_DIR)/cretsk.h										\
          $(INC_DIR)/defercd.h										\
          $(INC_DIR)/defexc.h										\
          $(INC_DIR)/definh.h										\
          $(INC_DIR)/deftex.h										\
          $(INC_DIR)/dpcque.h										\
          $(INC_DIR)/idlstk.h										\
          $(INC_DIR)/intstk.h										\
          $(INC_DIR)/knlheap.h										\
          $(INC_DIR)/maxtmout.h										\
          $(INC_DIR)/maxtpri.h										\
          $(INC_DIR)/parpack.h										\
          $(INC_DIR)/read.h											\
          $(INC_DIR)/readcfg.h										\
          $(INC_DIR)/timtic.h


$(OBJS_DIR)/h4acfg.o  : $(HEADERS)
$(OBJS_DIR)/analyze.o : $(HEADERS)
$(OBJS_DIR)/parpack.o : $(HEADERS)
$(OBJS_DIR)/read.o    : $(HEADERS)
$(OBJS_DIR)/defercd.o : $(HEADERS)
$(OBJS_DIR)/intstk.o  : $(HEADERS)
$(OBJS_DIR)/dpcque.o  : $(HEADERS)
$(OBJS_DIR)/idlstk.o  : $(HEADERS)
$(OBJS_DIR)/knlheap.o : $(HEADERS)
$(OBJS_DIR)/maxtpri.o : $(HEADERS)
$(OBJS_DIR)/apidef.o  : $(HEADERS)
$(OBJS_DIR)/apiinc.o  : $(HEADERS)
$(OBJS_DIR)/cretsk.o  : $(HEADERS)
$(OBJS_DIR)/deftex.o  : $(HEADERS)
$(OBJS_DIR)/cresem.o  : $(HEADERS)
$(OBJS_DIR)/creflg.o  : $(HEADERS)
$(OBJS_DIR)/credtq.o  : $(HEADERS)
$(OBJS_DIR)/crembx.o  : $(HEADERS)
$(OBJS_DIR)/cremtx.o  : $(HEADERS)
$(OBJS_DIR)/crempf.o  : $(HEADERS)
$(OBJS_DIR)/crembf.o  : $(HEADERS)
$(OBJS_DIR)/timtic.o  : $(HEADERS)
$(OBJS_DIR)/crecyc.o  : $(HEADERS)
$(OBJS_DIR)/crealm.o  : $(HEADERS)
$(OBJS_DIR)/defexc.o  : $(HEADERS)
$(OBJS_DIR)/attini.o  : $(HEADERS)
$(OBJS_DIR)/definh.o  : $(HEADERS)
$(OBJS_DIR)/attisr.o  : $(HEADERS)



# end of file
