

TARGET ?= sample.abs

INC_DIR = ../../../../kernel/include

# Tools
CC     = ch38
ASM    = asm38
LINK   = optlnk
DEPEND = depend
LINT   = splint
AWK    = gawk

CFLAGS = -CP=300HA -DEBug -I=$(INC_DIR)
AFLAGS = -CP=300HA -DEBug
LFLAGS = 

OBJS_DIR = objs

OBJS = $(OBJS_DIR)/main.obj			\
       $(OBJS_DIR)/sample.obj		\
       $(OBJS_DIR)/ostimer.obj		\
       $(OBJS_DIR)/kernel_cfg.obj	\
       $(OBJS_DIR)/dbsct.obj		\
       $(OBJS_DIR)/startup.obj		\
       $(OBJS_DIR)/vcttbl.obj		\
       $(OBJS_DIR)/lowlvl.obj		\
       $(OBJS_DIR)/lowsrc.obj		\
       $(OBJS_DIR)/sbrk.obj			\



OS_LIBS = ../../../../kernel/build/h8/h8300ha/ch38/libhosv4a.lib
OS_CFG  = ../../../../cfgrtr/build/gcc/h4acfg-h8300ha.exe

STD_LIBS = stdlib.lib

VPATH = ..

all: mkdir_objs mk_kernel $(TARGET)


$(TARGET): $(OBJS) $(STD_LIBS) $(OS_LIBS)
	echo rom D=R                         > $(OBJS_DIR)/subcmd.txt
	echo list smp.map                   >> $(OBJS_DIR)/subcmd.txt
	echo -Input=$(OBJS) | sed "s/ /,/g" >> $(OBJS_DIR)/subcmd.txt
	echo -LIB=$(OS_LIBS),$(STD_LIBS)    >> $(OBJS_DIR)/subcmd.txt
	echo "-start=VECTTBL,P,C,C\$$BSEC,C\$$DSEC,D/00,B,R/0200000,S/000FFBF20" >> $(OBJS_DIR)/subcmd.txt
	echo -output=$(TARGET)              >> $(OBJS_DIR)/subcmd.txt
	echo end                            >> $(OBJS_DIR)/subcmd.txt
	echo -input=$(TARGET)               >> $(OBJS_DIR)/subcmd.txt
	echo form stype                     >> $(OBJS_DIR)/subcmd.txt
	echo output smp.mot                 >> $(OBJS_DIR)/subcmd.txt
	echo -exit                          >> $(OBJS_DIR)/subcmd.txt
	$(LINK) -SU=$(OBJS_DIR)/subcmd.txt

$(STD_LIBS):
	lbg38 -OUTPut=$(STD_LIBS) $(CFLAGS) -REent 

mk_kernel:
	make -C ../../../../kernel/build/h8/h8300ha/ch38 -f gmake.mak

mkdir_objs:
	@mkdir -p $(OBJS_DIR)

clean:
	rm -f $(OBJS) $(TARGET) ../kernel_cfg.c ../kernel_id.h

$(OBJS_DIR)/sample.obj: sample.c ../kernel_id.h

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(OS_CFG) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



$(OBJS_DIR)/%.obj :: %.c
	$(CC) $(CFLAGS) $< -OB=$@ -List=$(@:%.obj=%.lst)

$(OBJS_DIR)/%.obj :: %.src
	$(ASM) $(AFLAGS) $< -OB=$@


