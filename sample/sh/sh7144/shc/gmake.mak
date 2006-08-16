

TARGET ?= sample.abs

INC_DIR = ../../../../kernel/include

# Tools
CC     = shc
ASM    = asmsh
LINK   = optlnk
DEPEND = depend
LINT   = splint
AWK    = gawk

CFLAGS = -CPu=sh2 -I=$(INC_DIR)
AFLAGS = -CPu=sh2 
LFLAGS = 

ifeq ($DEBUG),Yes)
OS_LIBS = ../../../../kernel/build/sh/sh2/shc/libhosv4adbg.lib
AFLAGS += -DEBug
CFLAGS += -DEBug -OP=0
else
OS_LIBS = ../../../../kernel/build/sh/sh2/shc/libhosv4a.lib
AFLAGS += 
CFLAGS += -OP=1
endif

OS_CFG  = ../../../../cfgrtr/build/gcc/h4acfg-sh2.exe


OBJS_DIR = objs

OBJS  = $(OBJS_DIR)/vcttbl.obj		\
        $(OBJS_DIR)/dbsct.obj		\
        $(OBJS_DIR)/startup.obj		\
        $(OBJS_DIR)/kernel_cfg.obj	\
        $(OBJS_DIR)/main.obj		\
        $(OBJS_DIR)/sample.obj		\
        $(OBJS_DIR)/ostimer.obj

# シミュレータ有効時、SCI出力を入れ替える
ifeq ($(SIM),Yes)
OBJS += $(OBJS_DIR)/sim_io.obj
else
OBJS += $(OBJS_DIR)/sci1.obj
endif


STD_LIBS = stdlib.lib

VPATH = ..

all: mkdir_objs mk_kernel $(TARGET)


# メモリ配置
ifeq ($(ROM),Yes)
SECTION_VECT ?= 000000000
SECTION_ROM  ?= 000000400
SECTION_RAM  ?= 0FFFFE000
else
SECTION_VECT ?= 000400000
SECTION_ROM  ?= 000400400
SECTION_RAM  ?= 000410000
endif


$(TARGET): $(OBJS) $(STD_LIBS) $(OS_LIBS)
	echo rom D=R                         > $(OBJS_DIR)/subcmd.txt
	echo list sample.map                >> $(OBJS_DIR)/subcmd.txt
	echo SHow SY,R,X                    >> $(OBJS_DIR)/subcmd.txt
	echo -Input=$(OBJS) | sed "s/ /,/g" >> $(OBJS_DIR)/subcmd.txt
	echo -LIB=$(OS_LIBS),$(STD_LIBS)    >> $(OBJS_DIR)/subcmd.txt
	echo "-start=VECTTBL/$(SECTION_VECT),P,C,C\$$BSEC,C\$$DSEC,D/$(SECTION_ROM),B,R/$(SECTION_RAM),S/0FFFFFBF0" >> $(OBJS_DIR)/subcmd.txt
	echo -output=$(TARGET)              >> $(OBJS_DIR)/subcmd.txt
	echo end                            >> $(OBJS_DIR)/subcmd.txt
	echo -input=$(TARGET)               >> $(OBJS_DIR)/subcmd.txt
	echo form stype                     >> $(OBJS_DIR)/subcmd.txt
	echo output sample.mot              >> $(OBJS_DIR)/subcmd.txt
	echo -exit                          >> $(OBJS_DIR)/subcmd.txt
	$(RM) -f $(TARGET)
	$(LINK) -SU=$(OBJS_DIR)/subcmd.txt

$(STD_LIBS):
	lbgsh -OUTPut=$(STD_LIBS) $(CFLAGS)
#	lbgsh -OUTPut=$(STD_LIBS) $(CFLAGS) -REent

mk_kernel:
	make -C ../../../../kernel/build/sh/sh2/shc -f gmake.mak

mkdir_objs:
	@mkdir -p $(OBJS_DIR)

clean:
	rm -f $(OBJS) $(TARGET) ../kernel_cfg.c ../kernel_id.h

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(OS_CFG) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


$(OBJS_DIR)/sample.obj: ../kernel_id.h

$(OBJS_DIR)/%.obj :: %.c
	$(CC) $(CFLAGS) $< -OB=$@ -List=$(@:%.obj=%.lst)

$(OBJS_DIR)/%.obj :: %.src
	$(ASM) $(AFLAGS) $< -OB=$@


