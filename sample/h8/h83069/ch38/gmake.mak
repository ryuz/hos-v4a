
OS_DIR = ../../../..

TARGET ?= sample

ifeq ($(ROM),Yes)
TARGET := $(TARGET)_rom
ADDR_VECT = 0
ADDR_ROM  = 0100
ADDR_RAM  = 0FFE140
else
ADDR_VECT = 0FFC040
ADDR_ROM  = 0FFC140
ADDR_RAM  = 0FFE140
endif


INC_DIR = $(OS_DIR)/kernel/include

# Tools
CC     = ch38
ASM    = asm38
LINK   = optlnk

CFLAGS = -CP=300HA -DEBug -I=$(INC_DIR)
AFLAGS = -CP=300HA -DEBug
LFLAGS = 

OBJS_DIR = objs

OBJS = $(OBJS_DIR)/vcttbl.obj		\
       $(OBJS_DIR)/startup.obj		\
       $(OBJS_DIR)/dbsct.obj		\
       $(OBJS_DIR)/kernel_cfg.obj	\
       $(OBJS_DIR)/main.obj			\
       $(OBJS_DIR)/sample.obj		\
       $(OBJS_DIR)/ostimer.obj		\
       $(OBJS_DIR)/sci1.obj			\



OS_LIBS = $(OS_DIR)/kernel/build/h8/h8300ha/ch38/libhosv4a.lib
OS_CFG  = $(OS_DIR)/cfgrtr/build/gcc/h4acfg-h8300ha.exe

STD_LIBS = stdlib.lib

VPATH = ..

all: mkdir_objs mk_kernel $(TARGET).abs


$(TARGET).abs: $(OBJS) $(STD_LIBS) $(OS_LIBS)
	echo rom D=R                         > $(OBJS_DIR)/subcmd.txt
	echo list $(TARGET).map             >> $(OBJS_DIR)/subcmd.txt
	echo -Input=$(OBJS) | sed "s/ /,/g" >> $(OBJS_DIR)/subcmd.txt
	echo -LIB=$(OS_LIBS),$(STD_LIBS)    >> $(OBJS_DIR)/subcmd.txt
	echo "-start=VECTTBL/$(ADDR_VECT),P,C,C\$$BSEC,C\$$DSEC,D/$(ADDR_ROM),B,R,S/$(ADDR_RAM)" >> $(OBJS_DIR)/subcmd.txt
	echo -output=$(TARGET).abs          >> $(OBJS_DIR)/subcmd.txt
	echo end                            >> $(OBJS_DIR)/subcmd.txt
	echo -input=$(TARGET).abs           >> $(OBJS_DIR)/subcmd.txt
	echo form stype                     >> $(OBJS_DIR)/subcmd.txt
	echo output $(TARGET).mot           >> $(OBJS_DIR)/subcmd.txt
	echo -exit                          >> $(OBJS_DIR)/subcmd.txt
	$(LINK) -SU=$(OBJS_DIR)/subcmd.txt

$(STD_LIBS):
	lbg38 -OUTPut=$(STD_LIBS) $(CFLAGS) -REent 

mk_kernel:
	make -C $(OS_DIR)/kernel/build/h8/h8300ha/ch38 -f gmake.mak

mkdir_objs:
	@mkdir -p $(OBJS_DIR)

clean:
	rm -f $(OBJS) $(TARGET) ../kernel_cfg.c ../kernel_id.h

mostlyclean: clean
	make -C $(OS_DIR)/kernel/build/h8/h8300ha/ch38 -f gmake.mak clean

$(OBJS_DIR)/sample.obj: sample.c ../kernel_id.h

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(OS_CFG) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



$(OBJS_DIR)/%.obj :: %.c
	$(CC) $(CFLAGS) $< -OB=$@ -List=$(@:%.obj=%.lst)

$(OBJS_DIR)/%.obj :: %.src
	$(ASM) $(AFLAGS) $< -OB=$@


