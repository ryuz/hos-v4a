# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance  Application Framework
#    common include file for GNU make
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------------------
#  Default setting
# --------------------------------------------------

# System
LINK_SYSTEM           ?= Yes
LINK_SYSAPI           ?= Yes
LINK_HANDLE           ?= Yes
LINK_MEMORY           ?= Yes
LINK_TIME             ?= Yes
LINK_PROCESS          ?= Yes
LINK_EVENT            ?= Yes
LINK_FILE             ?= Yes
LINK_COMMAND          ?= Yes

# Librarys
LINK_MEMPOL           ?= Yes
LINK_ASSOC            ?= Yes
LINK_LIST             ?= Yes
LINK_STREAMBUF        ?= Yes
LINK_PACKETBUF        ?= Yes
LINK_IPCHECKSUM       ?= Yes
LINK_CRC16            ?= Yes
LINK_STRINGFORMAT     ?= Yes

# Device Drivers
LINK_VT100            ?= Yes
LINK_TCPIP            ?= Yes
LINK_IPETHER          ?= Yes
LINK_NE2000           ?= No
LINK_LAN9000          ?= No
LINK_LAN9118          ?= No
LINK_PC16550          ?= Yes
LINK_AT91USART        ?= No
LINK_RENESASSCI       ?= No
LINK_MX1UART          ?= No
LINK_MN103SC          ?= No
LINK_WINSOCK          ?= No
LINK_FATVOL           ?= Yes

# Applications
LINK_SHELL            ?= Yes
LINK_PROCESSLIST      ?= Yes
LINK_COMMANDLIST      ?= Yes
LINK_MEMDUMP          ?= Yes
LINK_MEMWRITE         ?= Yes
LINK_MEMTEST          ?= Yes
LINK_KEYTEST          ?= Yes
LINK_TIMECMD          ?= Yes
LINK_FILELIST         ?= Yes
LINK_FILECAT          ?= Yes
LINK_FILECOPY         ?= Yes
LINK_FILEDUMP         ?= Yes
LINK_FLASHCMD         ?= Yes
LINK_ETHERSNOOP       ?= Yes
LINK_HELLO            ?= Yes



# --------------------------------------------------
#  Include
# --------------------------------------------------

# Include directories
INC_DIRS += $(HOSAPLFW_DIR)



# --------------------------------------------------
#  System
# --------------------------------------------------

# System
ifeq ($(LINK_SYSTEM),Yes)
SYSTEM_DIR = $(HOSAPLFW_DIR)/system/system
SRC_DIRS += $(SYSTEM_DIR)
CSRCS += $(SYSTEM_DIR)/system_initialize.c
CSRCS += $(SYSTEM_DIR)/system_requestproc.c
CSRCS += $(SYSTEM_DIR)/system_process.c
CSRCS += $(SYSTEM_DIR)/system_getnextprocess.c
endif


# System API
ifeq ($(LINK_SYSAPI),Yes)
SYSAPI_DIR = $(HOSAPLFW_DIR)/system/sysapi
SRC_DIRS += $(SYSAPI_DIR)
CSRCS += $(SYSAPI_DIR)/sysapi_initialize.c
CSRCS += $(SYSAPI_DIR)/sysctx_isisr.c
CSRCS += $(SYSAPI_DIR)/sysloc_lock.c
CSRCS += $(SYSAPI_DIR)/sysloc_unlock.c
CSRCS += $(SYSAPI_DIR)/sysevt_clear.c
CSRCS += $(SYSAPI_DIR)/sysevt_create.c
CSRCS += $(SYSAPI_DIR)/sysevt_delete.c
CSRCS += $(SYSAPI_DIR)/sysevt_set.c
CSRCS += $(SYSAPI_DIR)/sysevt_wait.c
CSRCS += $(SYSAPI_DIR)/sysint_clear.c
CSRCS += $(SYSAPI_DIR)/sysint_disable.c
CSRCS += $(SYSAPI_DIR)/sysint_enable.c
CSRCS += $(SYSAPI_DIR)/sysisr_create.c
CSRCS += $(SYSAPI_DIR)/sysisr_delete.c
CSRCS += $(SYSAPI_DIR)/sysmem_alloc.c
CSRCS += $(SYSAPI_DIR)/sysmem_free.c
CSRCS += $(SYSAPI_DIR)/sysmem_getmemif.c
CSRCS += $(SYSAPI_DIR)/sysmem_getsize.c
CSRCS += $(SYSAPI_DIR)/sysmem_realloc.c
CSRCS += $(SYSAPI_DIR)/sysmtx_create.c
CSRCS += $(SYSAPI_DIR)/sysmtx_delete.c
CSRCS += $(SYSAPI_DIR)/sysmtx_lock.c
CSRCS += $(SYSAPI_DIR)/sysmtx_unlock.c
CSRCS += $(SYSAPI_DIR)/sysprc_create.c
CSRCS += $(SYSAPI_DIR)/sysprc_delete.c
CSRCS += $(SYSAPI_DIR)/sysprc_terminate.c
CSRCS += $(SYSAPI_DIR)/sysprc_suspend.c
CSRCS += $(SYSAPI_DIR)/sysprc_resume.c
CSRCS += $(SYSAPI_DIR)/sysprc_getparam.c
CSRCS += $(SYSAPI_DIR)/sysprc_getcurrenthandle.c
CSRCS += $(SYSAPI_DIR)/systim_signal.c
CSRCS += $(SYSAPI_DIR)/systim_wait.c
CSRCS += $(SYSAPI_DIR)/systim_getsystemtime.c
CSRCS += $(SYSAPI_DIR)/systim_getcputime.c
CSRCS += $(SYSAPI_DIR)/systim_cputimetosecond.c
CSRCS += $(SYSAPI_DIR)/systim_cputimetonanosecond.c
CSRCS += $(SYSAPI_DIR)/syshos_hook.c
endif


# Handle Object
ifeq ($(LINK_HANDLE),Yes)
HANDLE_DIR = $(HOSAPLFW_DIR)/system/handle
SRC_DIRS += $(HANDLE_DIR)
CSRCS += $(HANDLE_DIR)/handle_close.c
CSRCS += $(HANDLE_DIR)/handleobj_create.c
CSRCS += $(HANDLE_DIR)/handleobj_delete.c
CSRCS += $(HANDLE_DIR)/handleobj_constructor.c
CSRCS += $(HANDLE_DIR)/handleobj_destructor.c
endif


# Memory
ifeq ($(LINK_MEMORY),Yes)
MEMORY_DIR = $(HOSAPLFW_DIR)/system/memory
SRC_DIRS += $(MEMORY_DIR)
CSRCS += $(MEMORY_DIR)/memory.c
endif


# Time
ifeq ($(LINK_TIME),Yes)
TIME_DIR = $(HOSAPLFW_DIR)/system/time
SRC_DIRS += $(TIME_DIR)
CSRCS += $(TIME_DIR)/time_getsystemtime.c
CSRCS += $(TIME_DIR)/time_wait.c
endif


# Process
ifeq ($(LINK_PROCESS),Yes)
PROCESS_DIR = $(HOSAPLFW_DIR)/system/process
SRC_DIRS += $(PROCESS_DIR)
CSRCS += $(PROCESS_DIR)/process_create.c
CSRCS += $(PROCESS_DIR)/process_delete.c
CSRCS += $(PROCESS_DIR)/process_constructor.c
CSRCS += $(PROCESS_DIR)/process_destructor.c
CSRCS += $(PROCESS_DIR)/process_getcurrenthandle.c
CSRCS += $(PROCESS_DIR)/process_exit.c
CSRCS += $(PROCESS_DIR)/process_waitexit.c
CSRCS += $(PROCESS_DIR)/process_getexitcode.c
CSRCS += $(PROCESS_DIR)/process_getparam.c
CSRCS += $(PROCESS_DIR)/process_setparam.c
CSRCS += $(PROCESS_DIR)/process_setcurrentdir.c
CSRCS += $(PROCESS_DIR)/process_getcurrentdir.c
CSRCS += $(PROCESS_DIR)/process_getparentprocess.c
CSRCS += $(PROCESS_DIR)/process_getexecutiontime.c
CSRCS += $(PROCESS_DIR)/process_getcommandline.c
CSRCS += $(PROCESS_DIR)/process_setterminal.c
CSRCS += $(PROCESS_DIR)/process_getterminal.c
CSRCS += $(PROCESS_DIR)/process_setconsole.c
CSRCS += $(PROCESS_DIR)/process_getconsole.c
CSRCS += $(PROCESS_DIR)/process_setstdin.c
CSRCS += $(PROCESS_DIR)/process_getstdin.c
CSRCS += $(PROCESS_DIR)/process_setstdout.c
CSRCS += $(PROCESS_DIR)/process_getstdout.c
CSRCS += $(PROCESS_DIR)/process_setstderr.c
CSRCS += $(PROCESS_DIR)/process_getstderr.c
endif


# Event
ifeq ($(LINK_EVENT),Yes)
EVENT_DIR = $(HOSAPLFW_DIR)/system/event
SRC_DIRS += $(EVENT_DIR)
CSRCS += $(EVENT_DIR)/event_create.c
CSRCS += $(EVENT_DIR)/event_delete.c
CSRCS += $(EVENT_DIR)/event_set.c
CSRCS += $(EVENT_DIR)/event_clear.c
CSRCS += $(EVENT_DIR)/event_wait.c
endif


# File
ifeq ($(LINK_FILE),Yes)
FILE_DIR = $(HOSAPLFW_DIR)/system/file
SRC_DIRS += $(FILE_DIR)
CSRCS += $(FILE_DIR)/console_getch.c
CSRCS += $(FILE_DIR)/drvobj_close.c
CSRCS += $(FILE_DIR)/drvobj_constructor.c
CSRCS += $(FILE_DIR)/drvobj_destructor.c
CSRCS += $(FILE_DIR)/drvobj_flush.c
CSRCS += $(FILE_DIR)/drvobj_iocontrol.c
CSRCS += $(FILE_DIR)/drvobj_open.c
CSRCS += $(FILE_DIR)/drvobj_read.c
CSRCS += $(FILE_DIR)/drvobj_seek.c
CSRCS += $(FILE_DIR)/drvobj_write.c
CSRCS += $(FILE_DIR)/fileobj_constructor.c
CSRCS += $(FILE_DIR)/fileobj_create.c
CSRCS += $(FILE_DIR)/fileobj_delete.c
CSRCS += $(FILE_DIR)/fileobj_destructor.c
CSRCS += $(FILE_DIR)/file_adddevice.c
CSRCS += $(FILE_DIR)/file_addvolume.c
CSRCS += $(FILE_DIR)/file_close.c
CSRCS += $(FILE_DIR)/file_getchar.c
CSRCS += $(FILE_DIR)/file_getstring.c
CSRCS += $(FILE_DIR)/file_initialize.c
CSRCS += $(FILE_DIR)/file_iocontrol.c
CSRCS += $(FILE_DIR)/file_open.c
CSRCS += $(FILE_DIR)/file_putchar.c
CSRCS += $(FILE_DIR)/file_putstring.c
CSRCS += $(FILE_DIR)/file_read.c
CSRCS += $(FILE_DIR)/file_readdir.c
CSRCS += $(FILE_DIR)/file_seek.c
CSRCS += $(FILE_DIR)/file_write.c
CSRCS += $(FILE_DIR)/file_printformat.c
CSRCS += $(FILE_DIR)/file_printformatv.c
CSRCS += $(FILE_DIR)/stdio_printformat.c
CSRCS += $(FILE_DIR)/syncdrv_constructor.c
CSRCS += $(FILE_DIR)/syncdrv_destructor.c
CSRCS += $(FILE_DIR)/syncdrv_endprocess.c
CSRCS += $(FILE_DIR)/syncdrv_iocontrol.c
CSRCS += $(FILE_DIR)/syncdrv_sendsignal.c
CSRCS += $(FILE_DIR)/syncdrv_startprocess.c
CSRCS += $(FILE_DIR)/syncfile_constructor.c
CSRCS += $(FILE_DIR)/syncfile_create.c
CSRCS += $(FILE_DIR)/syncfile_delete.c
CSRCS += $(FILE_DIR)/syncfile_destructor.c
CSRCS += $(FILE_DIR)/syncfile_setsignal.c
CSRCS += $(FILE_DIR)/sysvolfile_constructor.c
CSRCS += $(FILE_DIR)/sysvolfile_create.c
CSRCS += $(FILE_DIR)/sysvolfile_delete.c
CSRCS += $(FILE_DIR)/sysvolfile_destructor.c
CSRCS += $(FILE_DIR)/sysvol_adddevice.c
CSRCS += $(FILE_DIR)/sysvol_close.c
CSRCS += $(FILE_DIR)/sysvol_constructor.c
CSRCS += $(FILE_DIR)/sysvol_create.c
CSRCS += $(FILE_DIR)/sysvol_delete.c
CSRCS += $(FILE_DIR)/sysvol_destructor.c
CSRCS += $(FILE_DIR)/sysvol_iocontrol.c
CSRCS += $(FILE_DIR)/sysvol_open.c
CSRCS += $(FILE_DIR)/volumeobj_constructor.c
CSRCS += $(FILE_DIR)/volumeobj_create.c
CSRCS += $(FILE_DIR)/volumeobj_delete.c
CSRCS += $(FILE_DIR)/volumeobj_destructor.c
CSRCS += $(FILE_DIR)/volumeobj_makedir.c
CSRCS += $(FILE_DIR)/volumeobj_remove.c
endif


# Command
ifeq ($(LINK_COMMAND),Yes)
COMMAND_DIR = $(HOSAPLFW_DIR)/system/command
SRC_DIRS += $(COMMAND_DIR)
CSRCS += $(COMMAND_DIR)/command.c
endif



# --------------------------------------------------
#  Librarys
# --------------------------------------------------

# Memory Pool
ifeq ($(LINK_MEMPOL),Yes)
MEMPOL_DIR = $(HOSAPLFW_DIR)/library/container/mempol
SRC_DIRS += $(MEMPOL_DIR)
CSRCS += $(MEMPOL_DIR)/mempol.c
endif


# Association Array
ifeq ($(LINK_ASSOC),Yes)
ASSOC_DIR = $(HOSAPLFW_DIR)/library/container/assoc
SRC_DIRS += $(ASSOC_DIR)
CSRCS += $(ASSOC_DIR)/assoc.c
endif


# List
ifeq ($(LINK_LIST),Yes)
LIST_DIR = $(HOSAPLFW_DIR)/library/container/list
SRC_DIRS += $(LIST_DIR)
CSRCS += $(LIST_DIR)/list_create.c
CSRCS += $(LIST_DIR)/list_createex.c
CSRCS += $(LIST_DIR)/list_addtail.c
CSRCS += $(LIST_DIR)/list_getat.c
CSRCS += $(LIST_DIR)/list_getheadpos.c
CSRCS += $(LIST_DIR)/list_getnextpos.c
CSRCS += $(LIST_DIR)/list_getprevpos.c
CSRCS += $(LIST_DIR)/list_gettailpos.c
CSRCS += $(LIST_DIR)/list_remove.c
endif


# Stream Buffer
ifeq ($(LINK_STREAMBUF),Yes)
STREAMBUF_DIR = $(HOSAPLFW_DIR)/library/container/streambuf
SRC_DIRS += $(STREAMBUF_DIR)
CSRCS += $(STREAMBUF_DIR)/streambuf_create.c
CSRCS += $(STREAMBUF_DIR)/streambuf_getbuf.c
CSRCS += $(STREAMBUF_DIR)/streambuf_sendbuf.c
CSRCS += $(STREAMBUF_DIR)/streambuf_senddata.c
CSRCS += $(STREAMBUF_DIR)/streambuf_sendchar.c
CSRCS += $(STREAMBUF_DIR)/streambuf_recvbuf.c
CSRCS += $(STREAMBUF_DIR)/streambuf_relbuf.c
CSRCS += $(STREAMBUF_DIR)/streambuf_recvdata.c
CSRCS += $(STREAMBUF_DIR)/streambuf_recvchar.c
CSRCS += $(STREAMBUF_DIR)/streambuf_clear.c
CSRCS += $(STREAMBUF_DIR)/streambuf_refdatasize.c
CSRCS += $(STREAMBUF_DIR)/streambuf_reffreesize.c
endif


# Packet Buffer
ifeq ($(LINK_PACKETBUF),Yes)
PACKETBUF_DIR = $(HOSAPLFW_DIR)/library/container/packetbuf
SRC_DIRS += $(PACKETBUF_DIR)
CSRCS += $(PACKETBUF_DIR)/packetbuf_create.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_getbuf.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_sendbuf.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_senddata.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_recvbuf.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_relbuf.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_recvdata.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_clear.c
endif


# IP check-sum
ifeq ($(LINK_IPCHECKSUM),Yes)
IPCHECKSUM_DIR = $(HOSAPLFW_DIR)/library/algorithm/ipchecksum
SRC_DIRS += $(IPCHECKSUM_DIR)
CSRCS += $(IPCHECKSUM_DIR)/ipchecksum_getdigest.c
CSRCS += $(IPCHECKSUM_DIR)/ipchecksum_update.c
endif


# 16bit CRC
ifeq ($(LINK_CRC16),Yes)
CRC16_DIR = $(HOSAPLFW_DIR)/library/algorithm/crc16
SRC_DIRS += $(CRC16_DIR)
CSRCS += $(CRC16_DIR)/crc16_getdigest.c
CSRCS += $(CRC16_DIR)/crc16_update.c
CSRCS += $(CRC16_DIR)/crc16_reset.c
CSRCS += $(CRC16_DIR)/crc16_table.c
endif


# String Format
ifeq ($(LINK_STRINGFORMAT),Yes)
STRINGFORMAT_DIR = $(HOSAPLFW_DIR)/library/algorithm/stringformat
SRC_DIRS += $(STRINGFORMAT_DIR)
CSRCS += $(STRINGFORMAT_DIR)/stringformat_formatstring.c
CSRCS += $(STRINGFORMAT_DIR)/stringformat_formatstringv.c
CSRCS += $(STRINGFORMAT_DIR)/stringformat_format.c
CSRCS += $(STRINGFORMAT_DIR)/stringformat_formatv.c
CSRCS += $(STRINGFORMAT_DIR)/stringformat_string.c
CSRCS += $(STRINGFORMAT_DIR)/stringformat_decimal.c
CSRCS += $(STRINGFORMAT_DIR)/stringformat_hexadecimal.c
CSRCS += $(STRINGFORMAT_DIR)/stringformat_nibble.c
endif



# --------------------------------------------------
#  Device Drivers
# --------------------------------------------------

# VT100
ifeq ($(LINK_VT100),Yes)
VT100_DIR = $(HOSAPLFW_DIR)/driver/console/vt100
SRC_DIRS += $(VT100_DIR)
CSRCS += $(VT100_DIR)/vt100drv_create.c
CSRCS += $(VT100_DIR)/vt100drv_delete.c
CSRCS += $(VT100_DIR)/vt100drv_constructor.c
CSRCS += $(VT100_DIR)/vt100drv_destructor.c
CSRCS += $(VT100_DIR)/vt100drv_open.c
CSRCS += $(VT100_DIR)/vt100drv_close.c
CSRCS += $(VT100_DIR)/vt100drv_iocontrol.c
CSRCS += $(VT100_DIR)/vt100drv_seek.c
CSRCS += $(VT100_DIR)/vt100drv_read.c
CSRCS += $(VT100_DIR)/vt100drv_write.c
CSRCS += $(VT100_DIR)/vt100drv_flush.c
CSRCS += $(VT100_DIR)/vt100drv_getch.c
endif


# TCP/IP
ifeq ($(LINK_TCPIP),Yes)
TCPIP_DIR = $(HOSAPLFW_DIR)/driver/tcpip/tcpip
SRC_DIRS += $(TCPIP_DIR)
CSRCS += $(TCPIP_DIR)/tcpip_create.c
CSRCS += $(TCPIP_DIR)/tcpip_delete.c
CSRCS += $(TCPIP_DIR)/tcpip_constructor.c
CSRCS += $(TCPIP_DIR)/tcpip_destructor.c
CSRCS += $(TCPIP_DIR)/tcpip_open.c
CSRCS += $(TCPIP_DIR)/tcpip_close.c
CSRCS += $(TCPIP_DIR)/tcpip_iocontrol.c
CSRCS += $(TCPIP_DIR)/tcpip_seek.c
CSRCS += $(TCPIP_DIR)/tcpip_read.c
CSRCS += $(TCPIP_DIR)/tcpip_write.c
CSRCS += $(TCPIP_DIR)/tcpip_flush.c
CSRCS += $(TCPIP_DIR)/tcpip_recv.c
CSRCS += $(TCPIP_DIR)/tcpipfile_create.c
CSRCS += $(TCPIP_DIR)/tcpipfile_delete.c
CSRCS += $(TCPIP_DIR)/tcpipfile_constructor.c
CSRCS += $(TCPIP_DIR)/tcpipfile_destructor.c
endif


# IpEther
ifeq ($(LINK_IPETHER),Yes)
IPETHER_DIR = $(HOSAPLFW_DIR)/driver/tcpip/ipether
SRC_DIRS += $(IPETHER_DIR)
CSRCS += $(IPETHER_DIR)/ipether_create.c
CSRCS += $(IPETHER_DIR)/ipether_delete.c
CSRCS += $(IPETHER_DIR)/ipether_constructor.c
CSRCS += $(IPETHER_DIR)/ipether_destructor.c
CSRCS += $(IPETHER_DIR)/ipether_open.c
CSRCS += $(IPETHER_DIR)/ipether_close.c
CSRCS += $(IPETHER_DIR)/ipether_iocontrol.c
CSRCS += $(IPETHER_DIR)/ipether_seek.c
CSRCS += $(IPETHER_DIR)/ipether_read.c
CSRCS += $(IPETHER_DIR)/ipether_write.c
CSRCS += $(IPETHER_DIR)/ipether_recv.c
CSRCS += $(IPETHER_DIR)/ipether_flush.c
CSRCS += $(IPETHER_DIR)/ipether_getmacaddr.c
endif


# NE2000
ifeq ($(LINK_NE2000),Yes)
NE2000_DIR = $(HOSAPLFW_DIR)/driver/ether/ne2000
SRC_DIRS += $(NE2000_DIR)
CSRCS += $(NE2000_DIR)/ne2000drv.c
CSRCS += $(NE2000_DIR)/ne2000hal.c
endif


# LAN91C111
ifeq ($(LINK_LAN9000),Yes)
LAN9000_DIR = $(HOSAPLFW_DIR)/driver/ether/lan9000
SRC_DIRS += $(LAN9000_DIR)
CSRCS += $(LAN9000_DIR)/lan9000drv_close.c
CSRCS += $(LAN9000_DIR)/lan9000drv_create.c
CSRCS += $(LAN9000_DIR)/lan9000drv_delete.c
CSRCS += $(LAN9000_DIR)/lan9000drv_constructor.c
CSRCS += $(LAN9000_DIR)/lan9000drv_destructor.c
CSRCS += $(LAN9000_DIR)/lan9000drv_flush.c
CSRCS += $(LAN9000_DIR)/lan9000drv_iocontrol.c
CSRCS += $(LAN9000_DIR)/lan9000drv_isr.c
CSRCS += $(LAN9000_DIR)/lan9000drv_open.c
CSRCS += $(LAN9000_DIR)/lan9000drv_read.c
CSRCS += $(LAN9000_DIR)/lan9000drv_seek.c
CSRCS += $(LAN9000_DIR)/lan9000drv_write.c
CSRCS += $(LAN9000_DIR)/lan9000hal_create.c
CSRCS += $(LAN9000_DIR)/lan9000hal_delete.c
CSRCS += $(LAN9000_DIR)/lan9000hal_getinterruptstatus.c
CSRCS += $(LAN9000_DIR)/lan9000hal_getphysicaladdr.c
CSRCS += $(LAN9000_DIR)/lan9000hal_mii.c
CSRCS += $(LAN9000_DIR)/lan9000hal_phyregread.c
CSRCS += $(LAN9000_DIR)/lan9000hal_phyregwrite.c
CSRCS += $(LAN9000_DIR)/lan9000hal_recv.c
CSRCS += $(LAN9000_DIR)/lan9000hal_send.c
CSRCS += $(LAN9000_DIR)/lan9000hal_setinterruptmask.c
CSRCS += $(LAN9000_DIR)/lan9000hal_setup.c
CSRCS += $(LAN9000_DIR)/lan9000hal_stop.c
endif


# LAN91C111
ifeq ($(LINK_LAN9118),Yes)
LAN9118_DIR = $(HOSAPLFW_DIR)/driver/ether/lan9118
SRC_DIRS += $(LAN9118_DIR)
CSRCS += $(LAN9118_DIR)/lan9118drv_create.c
CSRCS += $(LAN9118_DIR)/lan9118drv_delete.c
CSRCS += $(LAN9118_DIR)/lan9118drv_open.c
CSRCS += $(LAN9118_DIR)/lan9118drv_close.c
CSRCS += $(LAN9118_DIR)/lan9118drv_iocontrol.c
CSRCS += $(LAN9118_DIR)/lan9118drv_seek.c
CSRCS += $(LAN9118_DIR)/lan9118drv_read.c
CSRCS += $(LAN9118_DIR)/lan9118drv_write.c
CSRCS += $(LAN9118_DIR)/lan9118drv_flush.c
CSRCS += $(LAN9118_DIR)/lan9118drv_isr.c
endif


# 16550A
ifeq ($(LINK_PC16550),Yes)
PC16550_DIR = $(HOSAPLFW_DIR)/driver/serial/pc16550
SRC_DIRS += $(PC16550_DIR)
CSRCS += $(PC16550_DIR)/pc16550drv_create.c
CSRCS += $(PC16550_DIR)/pc16550drv_delete.c
CSRCS += $(PC16550_DIR)/pc16550drv_constructor.c
CSRCS += $(PC16550_DIR)/pc16550drv_destructor.c
CSRCS += $(PC16550_DIR)/pc16550drv_open.c
CSRCS += $(PC16550_DIR)/pc16550drv_close.c
CSRCS += $(PC16550_DIR)/pc16550drv_iocontrol.c
CSRCS += $(PC16550_DIR)/pc16550drv_seek.c
CSRCS += $(PC16550_DIR)/pc16550drv_read.c
CSRCS += $(PC16550_DIR)/pc16550drv_write.c
CSRCS += $(PC16550_DIR)/pc16550drv_flush.c
CSRCS += $(PC16550_DIR)/pc16550drv_isr.c
CSRCS += $(PC16550_DIR)/pc16550hal_create.c
CSRCS += $(PC16550_DIR)/pc16550hal_delete.c
CSRCS += $(PC16550_DIR)/pc16550hal_setup.c
CSRCS += $(PC16550_DIR)/pc16550hal_stop.c
CSRCS += $(PC16550_DIR)/pc16550hal_setspeed.c
CSRCS += $(PC16550_DIR)/pc16550hal_recvchar.c
CSRCS += $(PC16550_DIR)/pc16550hal_sendchar.c
CSRCS += $(PC16550_DIR)/pc16550hal_enableinterrupt.c
CSRCS += $(PC16550_DIR)/pc16550hal_getinterruptstatus.c
CSRCS += $(PC16550_DIR)/pc16550hal_getstatus.c
endif


# Atmel AT91 USART
ifeq ($(LINK_AT91USART),Yes)
AT91USART_DIR = $(HOSAPLFW_DIR)/driver/serial/at91
SRC_DIRS += $(AT91USART_DIR)
CSRCS += $(AT91USART_DIR)/at91usartdrv_create.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_delete.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_constructor.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_destructor.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_open.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_close.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_iocontrol.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_seek.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_read.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_write.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_flush.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_isr.c
endif


# Renesas SCI
ifeq ($(LINK_RENESASSCI),Yes)
RENESASSCI_DIR = $(HOSAPLFW_DIR)/driver/serial/renesas
SRC_DIRS += $(RENESASSCI_DIR)
CSRCS += $(RENESASSCI_DIR)/scidrv_create.c
CSRCS += $(RENESASSCI_DIR)/scidrv_delete.c
CSRCS += $(RENESASSCI_DIR)/scidrv_constructor.c
CSRCS += $(RENESASSCI_DIR)/scidrv_destructor.c
CSRCS += $(RENESASSCI_DIR)/scidrv_open.c
CSRCS += $(RENESASSCI_DIR)/scidrv_close.c
CSRCS += $(RENESASSCI_DIR)/scidrv_iocontrol.c
CSRCS += $(RENESASSCI_DIR)/scidrv_seek.c
CSRCS += $(RENESASSCI_DIR)/scidrv_read.c
CSRCS += $(RENESASSCI_DIR)/scidrv_write.c
CSRCS += $(RENESASSCI_DIR)/scidrv_flush.c
CSRCS += $(RENESASSCI_DIR)/scidrv_isrrxerr.c
CSRCS += $(RENESASSCI_DIR)/scidrv_isrrx.c
CSRCS += $(RENESASSCI_DIR)/scidrv_isrtx.c
CSRCS += $(RENESASSCI_DIR)/scidrv_isrtxend.c
CSRCS += $(RENESASSCI_DIR)/scihal_create.c
CSRCS += $(RENESASSCI_DIR)/scihal_delete.c
CSRCS += $(RENESASSCI_DIR)/scihal_enableinterrupt.c
CSRCS += $(RENESASSCI_DIR)/scihal_recvchar.c
CSRCS += $(RENESASSCI_DIR)/scihal_sendchar.c
CSRCS += $(RENESASSCI_DIR)/scihal_setspeed.c
CSRCS += $(RENESASSCI_DIR)/scihal_setup.c
CSRCS += $(RENESASSCI_DIR)/scihal_stop.c
endif


# Freescale MX1 UART
ifeq ($(LINK_MX1UART),Yes)
MX1UART_DIR = $(HOSAPLFW_DIR)/driver/serial/mx1
SRC_DIRS += $(MX1UART_DIR)
CSRCS += $(MX1UART_DIR)/mx1uartdrv_create.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_delete.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_constructor.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_destructor.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_open.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_close.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_iocontrol.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_seek.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_read.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_write.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_flush.c
CSRCS += $(MX1UART_DIR)/mx1uartdrv_isr.c
endif


# Panasonic MN103 SC
ifeq ($(LINK_MN103SC),Yes)
MN103SC_DIR = $(HOSAPLFW_DIR)/driver/serial/mn103
SRC_DIRS += $(MN103SC_DIR)
CSRCS += $(MN103SC_DIR)/mn103scdrv_create.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_delete.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_constructor.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_destructor.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_open.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_close.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_iocontrol.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_seek.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_read.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_write.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_flush.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_isrtx.c
CSRCS += $(MN103SC_DIR)/mn103scdrv_isrrx.c
endif


# WinSock
ifeq ($(LINK_WINSOCK),Yes)
WINSOCK_DIR = $(HOSAPLFW_DIR)/driver/serial/winsock
SRC_DIRS += $(WINSOCK_DIR)
CSRCS += $(WINSOCK_DIR)/winsockdrv.c
endif


# FAT volume
ifeq ($(LINK_FATVOL),Yes)
FATVOL_DIR = $(HOSAPLFW_DIR)/driver/volume/fat
SRC_DIRS += $(FATVOL_DIR)
CSRCS += $(FATVOL_DIR)/fatvol_create.c
CSRCS += $(FATVOL_DIR)/fatvol_delete.c
CSRCS += $(FATVOL_DIR)/fatvol_constructor.c
CSRCS += $(FATVOL_DIR)/fatvol_destructor.c
CSRCS += $(FATVOL_DIR)/fatvol_open.c
CSRCS += $(FATVOL_DIR)/fatvol_close.c
CSRCS += $(FATVOL_DIR)/fatvol_iocontrol.c
CSRCS += $(FATVOL_DIR)/fatvol_seek.c
CSRCS += $(FATVOL_DIR)/fatvol_read.c
CSRCS += $(FATVOL_DIR)/fatvol_write.c
CSRCS += $(FATVOL_DIR)/fatvol_flush.c
CSRCS += $(FATVOL_DIR)/fatvol_makedir.c
CSRCS += $(FATVOL_DIR)/fatvol_remove.c
CSRCS += $(FATVOL_DIR)/fatvol_clusterread.c
CSRCS += $(FATVOL_DIR)/fatvol_clusterwrite.c
CSRCS += $(FATVOL_DIR)/fatvol_flushclusterbuf.c
CSRCS += $(FATVOL_DIR)/fatvol_flushfat.c
CSRCS += $(FATVOL_DIR)/fatvol_getclusterbuf.c
CSRCS += $(FATVOL_DIR)/fatvol_relclusterbuf.c
CSRCS += $(FATVOL_DIR)/fatvol_getnewcluster.c
CSRCS += $(FATVOL_DIR)/fatvol_getnextcluster.c
CSRCS += $(FATVOL_DIR)/fatvol_setnextcluster.c
CSRCS += $(FATVOL_DIR)/fatvol_syncfilesize.c
CSRCS += $(FATVOL_DIR)/fatfile_create.c
CSRCS += $(FATVOL_DIR)/fatfile_delete.c
CSRCS += $(FATVOL_DIR)/fatfile_constructor.c
CSRCS += $(FATVOL_DIR)/fatfile_destructor.c
endif



# --------------------------------------------------
#  Applications
# --------------------------------------------------

# Shell
ifeq ($(LINK_SHELL),Yes)
SHELL_DIR = $(HOSAPLFW_DIR)/application/syscmd/shell
SRC_DIRS += $(SHELL_DIR)
CSRCS += $(SHELL_DIR)/shell_main.c
CSRCS += $(SHELL_DIR)/shell_create.c
CSRCS += $(SHELL_DIR)/shell_delete.c
CSRCS += $(SHELL_DIR)/shell_executecommand.c
CSRCS += $(SHELL_DIR)/shell_executescript.c
CSRCS += $(SHELL_DIR)/shell_inputline.c
CSRCS += $(SHELL_DIR)/shell_interactive.c
CSRCS += $(SHELL_DIR)/shell_putchar.c
CSRCS += $(SHELL_DIR)/shell_curright.c
CSRCS += $(SHELL_DIR)/shell_curleft.c
CSRCS += $(SHELL_DIR)/shell_replaceline.c
endif


# Process List
ifeq ($(LINK_PROCESSLIST),Yes)
PROCESSLIST_DIR = $(HOSAPLFW_DIR)/application/syscmd/processlist
SRC_DIRS += $(PROCESSLIST_DIR)
CSRCS += $(PROCESSLIST_DIR)/processlist_main.c
endif


# Command List
ifeq ($(LINK_COMMANDLIST),Yes)
COMMANDLIST_DIR = $(HOSAPLFW_DIR)/application/syscmd/commandlist
SRC_DIRS += $(COMMANDLIST_DIR)
CSRCS += $(COMMANDLIST_DIR)/commandlist_main.c
endif


# Memory Dump
ifeq ($(LINK_MEMDUMP),Yes)
MEMDUMP_DIR = $(HOSAPLFW_DIR)/application/utility/memdump
SRC_DIRS += $(MEMDUMP_DIR)
CSRCS += $(MEMDUMP_DIR)/memdump_main.c
endif


# Memory Write
ifeq ($(LINK_MEMWRITE),Yes)
MEMWRITE_DIR = $(HOSAPLFW_DIR)/application/utility/memwrite
SRC_DIRS += $(MEMWRITE_DIR)
CSRCS += $(MEMWRITE_DIR)/memwrite_main.c
endif


# Memory Test
ifeq ($(LINK_MEMTEST),Yes)
MEMTEST_DIR = $(HOSAPLFW_DIR)/application/utility/memtest
SRC_DIRS += $(MEMTEST_DIR)
CSRCS += $(MEMTEST_DIR)/memtest_main.c
endif


# Key Test
ifeq ($(LINK_KEYTEST),Yes)
KEYTEST_DIR = $(HOSAPLFW_DIR)/application/utility/keytest
SRC_DIRS += $(KEYTEST_DIR)
CSRCS += $(KEYTEST_DIR)/keytest_main.c
endif


# Time Command
ifeq ($(LINK_TIMECMD),Yes)
TIMECMD_DIR = $(HOSAPLFW_DIR)/application/utility/timecmd
SRC_DIRS += $(TIMECMD_DIR)
CSRCS += $(TIMECMD_DIR)/timecmd_main.c
endif


# File List
ifeq ($(LINK_FILELIST),Yes)
FILELIST_DIR = $(HOSAPLFW_DIR)/application/filecmd/filelist
SRC_DIRS += $(FILELIST_DIR)
CSRCS += $(FILELIST_DIR)/filelist_main.c
endif


# File Cat
ifeq ($(LINK_FILECAT),Yes)
FILECAT_DIR = $(HOSAPLFW_DIR)/application/filecmd/filecat
SRC_DIRS += $(FILECAT_DIR)
CSRCS += $(FILECAT_DIR)/filecat_main.c
endif


# File Copy
ifeq ($(LINK_FILECOPY),Yes)
FILECOPY_DIR = $(HOSAPLFW_DIR)/application/filecmd/filecopy
SRC_DIRS += $(FILECOPY_DIR)
CSRCS += $(FILECOPY_DIR)/filecopy_main.c
endif


# File Dump
ifeq ($(LINK_FILEDUMP),Yes)
FILEDUMP_DIR = $(HOSAPLFW_DIR)/application/filecmd/filedump
SRC_DIRS += $(FILEDUMP_DIR)
CSRCS += $(FILEDUMP_DIR)/filedump_main.c
endif


# Flash Command
ifeq ($(LINK_FLASHCMD),Yes)
FLASHCMD_DIR = $(HOSAPLFW_DIR)/application/flashcmd/norflashcmd
SRC_DIRS += $(FLASHCMD_DIR)
CSRCS += $(FLASHCMD_DIR)/norflashcmd_main.c
endif


# Ether Snoopt
ifeq ($(LINK_ETHERSNOOP),Yes)
ETHERSNOOP_DIR = $(HOSAPLFW_DIR)/application/netcmd/ethersnoop
SRC_DIRS += $(ETHERSNOOP_DIR)
CSRCS += $(ETHERSNOOP_DIR)/ethersnoop_main.c
endif


# Hello World
ifeq ($(LINK_HELLO),Yes)
HELLO_DIR = $(HOSAPLFW_DIR)/application/example/hello
SRC_DIRS += $(HELLO_DIR)
CSRCS += $(HELLO_DIR)/hello_main.c
endif


# end of file
