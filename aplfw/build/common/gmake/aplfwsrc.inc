# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# Include directories
INC_DIRS += $(APLFW_DIR)



# --------------------------------------------------
#  Systems
# --------------------------------------------------

SYSTEM_DIR     = $(APLFW_DIR)/system/system
SRC_DIRS      += $(SYSTEM_DIR)
CSRCS         += $(SYSTEM_DIR)/system_initialize.c					\
                 $(SYSTEM_DIR)/system_boot.c						\
                 $(SYSTEM_DIR)/system_requestproc.c					\
                 $(SYSTEM_DIR)/system_process.c


# System API
SYSAPI_DIR     = $(APLFW_DIR)/system/sysapi
SRC_DIRS      += $(SYSAPI_DIR)
CSRCS         += $(SYSAPI_DIR)/sysapi_initialize.c					\
                 $(SYSAPI_DIR)/sysloc_lock.c						\
                 $(SYSAPI_DIR)/sysloc_unlock.c						\
                 $(SYSAPI_DIR)/sysevt_clear.c						\
                 $(SYSAPI_DIR)/sysevt_create.c						\
                 $(SYSAPI_DIR)/sysevt_delete.c						\
                 $(SYSAPI_DIR)/sysevt_set.c							\
                 $(SYSAPI_DIR)/sysevt_wait.c						\
                 $(SYSAPI_DIR)/sysint_clear.c						\
                 $(SYSAPI_DIR)/sysint_disable.c						\
                 $(SYSAPI_DIR)/sysint_enable.c						\
                 $(SYSAPI_DIR)/sysisr_create.c						\
                 $(SYSAPI_DIR)/sysisr_delete.c						\
                 $(SYSAPI_DIR)/sysmem_alloc.c						\
                 $(SYSAPI_DIR)/sysmem_free.c						\
                 $(SYSAPI_DIR)/sysmem_getmemif.c					\
                 $(SYSAPI_DIR)/sysmem_getsize.c						\
                 $(SYSAPI_DIR)/sysmem_realloc.c						\
                 $(SYSAPI_DIR)/sysmtx_create.c						\
                 $(SYSAPI_DIR)/sysmtx_delete.c						\
                 $(SYSAPI_DIR)/sysmtx_lock.c						\
                 $(SYSAPI_DIR)/sysmtx_unlock.c						\
                 $(SYSAPI_DIR)/sysprc_create.c						\
                 $(SYSAPI_DIR)/sysprc_delete.c						\
                 $(SYSAPI_DIR)/sysprc_exit.c						\
                 $(SYSAPI_DIR)/sysprc_getcurrenthandle.c			\
                 $(SYSAPI_DIR)/sysprc_start.c						\
                 $(SYSAPI_DIR)/systim_getsystemtime.c				\
                 $(SYSAPI_DIR)/systim_wait.c


# Handle Object
HANDLE_DIR     = $(APLFW_DIR)/system/handle
SRC_DIRS      += $(HANDLE_DIR)
CSRCS         += $(HANDLE_DIR)/handle_close.c						\
                 $(HANDLE_DIR)/handleobj_create.c					\
                 $(HANDLE_DIR)/handleobj_delete.c


# Memory
MEMORY_DIR     = $(APLFW_DIR)/system/memory
SRC_DIRS      += $(MEMORY_DIR)
CSRCS         += $(MEMORY_DIR)/memory.c


# Time
TIME_DIR       = $(APLFW_DIR)/system/time
SRC_DIRS      += $(TIME_DIR)
CSRCS         += $(TIME_DIR)/time_getsystemtime.c					\
                 $(TIME_DIR)/time_wait.c


# Process
PROCESS_DIR    = $(APLFW_DIR)/system/process
SRC_DIRS      += $(PROCESS_DIR)
CSRCS         += $(PROCESS_DIR)/process.c							\
                 $(PROCESS_DIR)/procobj.c


# File
FILE_DIR       = $(APLFW_DIR)/system/file
SRC_DIRS      += $(FILE_DIR)
CSRCS         += $(FILE_DIR)/file_initialize.c						\
                 $(FILE_DIR)/file_open.c							\
                 $(FILE_DIR)/file_close.c							\
                 $(FILE_DIR)/file_iocontrol.c						\
                 $(FILE_DIR)/file_seek.c							\
                 $(FILE_DIR)/file_read.c							\
                 $(FILE_DIR)/file_write.c							\
                 $(FILE_DIR)/file_readdir.c							\
                 $(FILE_DIR)/file_getchar.c							\
                 $(FILE_DIR)/file_getstring.c						\
                 $(FILE_DIR)/file_putchar.c							\
                 $(FILE_DIR)/file_putstring.c						\
                 $(FILE_DIR)/file_adddevice.c						\
                 $(FILE_DIR)/file_addvolume.c						\
                 $(FILE_DIR)/drvobj_create.c						\
                 $(FILE_DIR)/drvobj_delete.c						\
                 $(FILE_DIR)/drvobj_open.c							\
                 $(FILE_DIR)/drvobj_close.c							\
                 $(FILE_DIR)/drvobj_iocontrol.c						\
                 $(FILE_DIR)/drvobj_seek.c							\
                 $(FILE_DIR)/drvobj_read.c							\
                 $(FILE_DIR)/drvobj_write.c							\
                 $(FILE_DIR)/drvobj_flush.c							\
                 $(FILE_DIR)/fileobj_create.c						\
                 $(FILE_DIR)/fileobj_delete.c						\
                 $(FILE_DIR)/volumeobj_create.c						\
                 $(FILE_DIR)/volumeobj_makedir.c					\
                 $(FILE_DIR)/volumeobj_remove.c						\
                 $(FILE_DIR)/chrdrv_create.c						\
                 $(FILE_DIR)/chrdrv_delete.c						\
                 $(FILE_DIR)/chrfile_create.c						\
                 $(FILE_DIR)/chrfile_delete.c						\
                 $(FILE_DIR)/sysvol_create.c						\
                 $(FILE_DIR)/sysvol_delete.c						\
                 $(FILE_DIR)/sysvol_open.c							\
                 $(FILE_DIR)/sysvol_close.c							\
                 $(FILE_DIR)/sysvol_iocontrol.c						\
                 $(FILE_DIR)/sysvol_adddevice.c						\
                 $(FILE_DIR)/console_getch.c						\
                 $(FILE_DIR)/filefmt.c								\
                 $(FILE_DIR)/stdfile.c


# Command
COMMAND_DIR    = $(APLFW_DIR)/system/command
SRC_DIRS      += $(COMMAND_DIR)
CSRCS         += $(COMMAND_DIR)/command.c


# Shell
SHELL_DIR      = $(APLFW_DIR)/system/shell
SRC_DIRS      += $(SHELL_DIR)
CSRCS         += $(SHELL_DIR)/shell.c




# --------------------------------------------------
#  Librarys
# --------------------------------------------------

# Memory Pool
MEMPOL_DIR     = $(APLFW_DIR)/library/container/mempol
SRC_DIRS      += $(MEMPOL_DIR)
CSRCS         += $(MEMPOL_DIR)/mempol.c	


# Association Array
ASSOC_DIR      = $(APLFW_DIR)/library/container/assoc
SRC_DIRS      += $(ASSOC_DIR)
CSRCS         += $(ASSOC_DIR)/assoc.c


# List
LIST_DIR       = $(APLFW_DIR)/library/container/list
SRC_DIRS      += $(LIST_DIR)
CSRCS         += $(LIST_DIR)/list_create.c							\
                 $(LIST_DIR)/list_createex.c						\
                 $(LIST_DIR)/list_addtail.c							\
                 $(LIST_DIR)/list_getat.c							\
                 $(LIST_DIR)/list_getheadpos.c						\
                 $(LIST_DIR)/list_getnextpos.c						\
                 $(LIST_DIR)/list_getprevpos.c						\
                 $(LIST_DIR)/list_gettailpos.c						\
                 $(LIST_DIR)/list_remove.c


# Stream Buffer
STREAMBUF_DIR  = $(APLFW_DIR)/library/container/streambuf
SRC_DIRS      += $(STREAMBUF_DIR)
CSRCS         += $(STREAMBUF_DIR)/streambuf_create.c				\
                 $(STREAMBUF_DIR)/streambuf_getbuf.c				\
                 $(STREAMBUF_DIR)/streambuf_sendbuf.c				\
                 $(STREAMBUF_DIR)/streambuf_senddata.c				\
                 $(STREAMBUF_DIR)/streambuf_sendchar.c				\
                 $(STREAMBUF_DIR)/streambuf_recvbuf.c				\
                 $(STREAMBUF_DIR)/streambuf_relbuf.c				\
                 $(STREAMBUF_DIR)/streambuf_recvdata.c				\
                 $(STREAMBUF_DIR)/streambuf_recvchar.c				\
                 $(STREAMBUF_DIR)/streambuf_clear.c					\
                 $(STREAMBUF_DIR)/streambuf_refdatasize.c			\
                 $(STREAMBUF_DIR)/streambuf_reffreesize.c


# Packet Buffer
PACKETBUF_DIR  = $(APLFW_DIR)/library/container/packetbuf
SRC_DIRS      += $(PACKETBUF_DIR)
CSRCS         += $(PACKETBUF_DIR)/packetbuf_create.c				\
                 $(PACKETBUF_DIR)/packetbuf_getbuf.c				\
                 $(PACKETBUF_DIR)/packetbuf_sendbuf.c				\
                 $(PACKETBUF_DIR)/packetbuf_senddata.c				\
                 $(PACKETBUF_DIR)/packetbuf_recvbuf.c				\
                 $(PACKETBUF_DIR)/packetbuf_relbuf.c				\
                 $(PACKETBUF_DIR)/packetbuf_recvdata.c				\
                 $(PACKETBUF_DIR)/packetbuf_clear.c


# IP check-sum
IPCHECKSUM_DIR = $(APLFW_DIR)/library/algorithm/ipchecksum
SRC_DIRS      += $(IPCHECKSUM_DIR)
CSRCS         += $(IPCHECKSUM_DIR)/ipchecksum_getdigest.c			\
                 $(IPCHECKSUM_DIR)/ipchecksum_update.c				\


# --------------------------------------------------
#  Device Drivers
# --------------------------------------------------

# TCP/IP
TCPIP_DIR      = $(APLFW_DIR)/driver/tcpip/tcpip
SRC_DIRS      += $(TCPIP_DIR)
CSRCS         += $(TCPIP_DIR)/tcpip_create.c						\
                 $(TCPIP_DIR)/tcpip_delete.c						\
                 $(TCPIP_DIR)/tcpip_open.c							\
                 $(TCPIP_DIR)/tcpip_clese.c							\
                 $(TCPIP_DIR)/tcpip_iocontrol.c						\
                 $(TCPIP_DIR)/tcpip_seek.c							\
                 $(TCPIP_DIR)/tcpip_read.c							\
                 $(TCPIP_DIR)/tcpip_write.c							\
                 $(TCPIP_DIR)/tcpip_flush.c							\
                 $(TCPIP_DIR)/tcpip_recv.c


# IpEther
IPETHER_DIR    = $(APLFW_DIR)/driver/tcpip/ipether
SRC_DIRS      += $(IPETHER_DIR)
CSRCS         += $(IPETHER_DIR)/ipether_create.c					\
                 $(IPETHER_DIR)/ipether_delete.c					\
                 $(IPETHER_DIR)/ipether_open.c						\
                 $(IPETHER_DIR)/ipether_clese.c						\
                 $(IPETHER_DIR)/ipether_iocontrol.c					\
                 $(IPETHER_DIR)/ipether_seek.c						\
                 $(IPETHER_DIR)/ipether_read.c						\
                 $(IPETHER_DIR)/ipether_write.c						\
                 $(IPETHER_DIR)/ipether_recv.c						\
                 $(IPETHER_DIR)/ipether_flush.c						\
                 $(IPETHER_DIR)/ipether_getmacaddr.c				\


# LAN9118
LAN9118DRV_DIR = $(APLFW_DIR)/driver/ether/lan9118
SRC_DIRS      += $(LAN9118DRV_DIR)
CSRCS         += $(LAN9118DRV_DIR)/lan9118drv_create.c				\
                 $(LAN9118DRV_DIR)/lan9118drv_delete.c				\
                 $(LAN9118DRV_DIR)/lan9118drv_open.c				\
                 $(LAN9118DRV_DIR)/lan9118drv_close.c				\
                 $(LAN9118DRV_DIR)/lan9118drv_iocontrol.c			\
                 $(LAN9118DRV_DIR)/lan9118drv_seek.c				\
                 $(LAN9118DRV_DIR)/lan9118drv_read.c				\
                 $(LAN9118DRV_DIR)/lan9118drv_write.c				\
                 $(LAN9118DRV_DIR)/lan9118drv_flush.c				\
                 $(LAN9118DRV_DIR)/lan9118drv_isr.c


# VT100
VT100_DIR      = $(APLFW_DIR)/driver/console/vt100
SRC_DIRS      += $(VT100_DIR)
CSRCS         += $(VT100_DIR)/vt100drv_create.c						\
                 $(VT100_DIR)/vt100drv_delete.c						\
                 $(VT100_DIR)/vt100drv_open.c						\
                 $(VT100_DIR)/vt100drv_close.c						\
                 $(VT100_DIR)/vt100drv_iocontrol.c					\
                 $(VT100_DIR)/vt100drv_seek.c						\
                 $(VT100_DIR)/vt100drv_read.c						\
                 $(VT100_DIR)/vt100drv_write.c						\
                 $(VT100_DIR)/vt100drv_flush.c						\
                 $(VT100_DIR)/vt100drv_getch.c


# PC16550
PC16550_DIR    = $(APLFW_DIR)/driver/serial/pc16550
SRC_DIRS      += $(PC16550_DIR)
CSRCS         += $(PC16550_DIR)/pc16550drv_create.c					\
                 $(PC16550_DIR)/pc16550drv_delete.c					\
                 $(PC16550_DIR)/pc16550drv_open.c					\
                 $(PC16550_DIR)/pc16550drv_close.c					\
                 $(PC16550_DIR)/pc16550drv_iocontrol.c				\
                 $(PC16550_DIR)/pc16550drv_seek.c					\
                 $(PC16550_DIR)/pc16550drv_read.c					\
                 $(PC16550_DIR)/pc16550drv_write.c					\
                 $(PC16550_DIR)/pc16550drv_flush.c					\
                 $(PC16550_DIR)/pc16550drv_isr.c					\
                 $(PC16550_DIR)/pc16550hal_create.c					\
                 $(PC16550_DIR)/pc16550hal_delete.c					\
                 $(PC16550_DIR)/pc16550hal_setup.c					\
                 $(PC16550_DIR)/pc16550hal_stop.c					\
                 $(PC16550_DIR)/pc16550hal_setspeed.c				\
                 $(PC16550_DIR)/pc16550hal_recvchar.c				\
                 $(PC16550_DIR)/pc16550hal_sendchar.c				\
                 $(PC16550_DIR)/pc16550hal_enableinterrupt.c		\
                 $(PC16550_DIR)/pc16550hal_getinterruptstatus.c		\
                 $(PC16550_DIR)/pc16550hal_getstatus.c


# AT91USART
AT91USART_DIR  = $(APLFW_DIR)/driver/serial/at91
SRC_DIRS      += $(AT91USART_DIR)
CSRCS         += $(AT91USART_DIR)/at91usartdrv_create.c				\
                 $(AT91USART_DIR)/at91usartdrv_delete.c				\
                 $(AT91USART_DIR)/at91usartdrv_open.c				\
                 $(AT91USART_DIR)/at91usartdrv_close.c				\
                 $(AT91USART_DIR)/at91usartdrv_iocontrol.c			\
                 $(AT91USART_DIR)/at91usartdrv_seek.c				\
                 $(AT91USART_DIR)/at91usartdrv_read.c				\
                 $(AT91USART_DIR)/at91usartdrv_write.c				\
                 $(AT91USART_DIR)/at91usartdrv_flush.c				\
                 $(AT91USART_DIR)/at91usartdrv_isr.c				\



# --------------------------------------------------
#  Applications
# --------------------------------------------------


# Hello World
HELLO_DIR      = $(APLFW_DIR)/application/example/hello
SRC_DIRS      += $(HELLO_DIR)
CSRCS         += $(HELLO_DIR)/hello.c


# File List
FILELIST_DIR   = $(APLFW_DIR)/application/filecmd/filelist
SRC_DIRS      += $(FILELIST_DIR)
CSRCS         += $(FILELIST_DIR)/filelist_main.c

# File Cat
FILECAT_DIR    = $(APLFW_DIR)/application/filecmd/filecat
SRC_DIRS      += $(FILECAT_DIR)
CSRCS         += $(FILECAT_DIR)/filecat_main.c

# File Copy
FILECOPY_DIR   = $(APLFW_DIR)/application/filecmd/filecopy
SRC_DIRS      += $(FILECOPY_DIR)
CSRCS         += $(FILECOPY_DIR)/filecopy_main.c

# File Dump
FILEDUMP_DIR   = $(APLFW_DIR)/application/filecmd/filedump
SRC_DIRS      += $(FILEDUMP_DIR)
CSRCS         += $(FILEDUMP_DIR)/filedump_main.c


# Memory Dump
MEMDUMP_DIR    = $(APLFW_DIR)/application/utility/memdump
SRC_DIRS      += $(MEMDUMP_DIR)
CSRCS         += $(MEMDUMP_DIR)/memdump_main.c

# Memory Write
MEMWRITE_DIR   = $(APLFW_DIR)/application/utility/memwrite
SRC_DIRS      += $(MEMWRITE_DIR)
CSRCS         += $(MEMWRITE_DIR)/memwrite_main.c

# Memory Test
MEMTEST_DIR    = $(APLFW_DIR)/application/utility/memtest
SRC_DIRS      += $(MEMTEST_DIR)
CSRCS         += $(MEMTEST_DIR)/memtest_main.c

# Key Test
KEYTEST_DIR    = $(APLFW_DIR)/application/utility/keytest
SRC_DIRS      += $(KEYTEST_DIR)
CSRCS         += $(KEYTEST_DIR)/keytest_main.c

# Time Command
TIMECMD_DIR    = $(APLFW_DIR)/application/utility/timecmd
SRC_DIRS      += $(TIMECMD_DIR)
CSRCS         += $(TIMECMD_DIR)/timecmd_main.c


# Ether Snoopt
ETHERSNOOP_DIR = $(APLFW_DIR)/application/netcmd/ethersnoop
SRC_DIRS      += $(ETHERSNOOP_DIR)
CSRCS         += $(ETHERSNOOP_DIR)/ethersnoop_main.c


# end of file
