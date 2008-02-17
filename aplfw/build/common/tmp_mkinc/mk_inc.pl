#! /usr/bin/perl


# sources
@sources =
(
	[
		"System",
		[
			"System",									# comment
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",	# depend
			"\$(HOSAPLFW_DIR)/system/system",			# path
			"SYSTEM",									# def_name
			"Yes",										# link
			[
				"system.h",
				"system_local.h",
			],
			[
				"system_initialize.c",
				"system_requestproc.c",
				"system_process.c",
				"system_getnextprocess.c",
			],
		],
		[
			"System API",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/system/sysapi",
			"SYSAPI",
			"Yes",
			[
				"sysapi.h",
				"sysapi_local.h",
			],
			[
				"sysapi_initialize.c",
				"sysctx_isisr.c",
				"sysloc_lock.c",
				"sysloc_unlock.c",
				"sysevt_clear.c",
				"sysevt_create.c",
				"sysevt_delete.c",
				"sysevt_set.c",
				"sysevt_wait.c",
				"sysint_clear.c",
				"sysint_disable.c",
				"sysint_enable.c",
				"sysisr_create.c",
				"sysisr_delete.c",
				"sysmem_alloc.c",
				"sysmem_free.c",
				"sysmem_getmemif.c",
				"sysmem_getsize.c",
				"sysmem_realloc.c",
				"sysmtx_create.c",
				"sysmtx_delete.c",
				"sysmtx_lock.c",
				"sysmtx_unlock.c",
				"sysprc_create.c",
				"sysprc_delete.c",
				"sysprc_terminate.c",
				"sysprc_suspend.c",
				"sysprc_resume.c",
				"sysprc_getparam.c",
				"sysprc_getcurrenthandle.c",
				"systim_wait.c",
				"systim_getsystemtime.c",
				"systim_getcputime.c",
				"systim_cputimetosecond.c",
				"systim_cputimetonanosecond.c",
				"syshos_hook.c",
			],
		],
		[
			"Handle Object",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/system/handle",
			"HANDLE",
			"Yes",
			[
				"handle.h",
				"handleobj.h",
				"handleobj_local.h",
			],
			[
				"handle_close.c",
				"handleobj_create.c",
				"handleobj_delete.c",
				"handleobj_constructor.c",
				"handleobj_destructor.c",
			]
		],
		[
			"Memory",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/system/memory",
			"MEMORY",
			"Yes",
			[
				"memory.h",
			],
			[
				"memory.c",
			]
		],
		[
			"Time",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/system/time",
			"TIME",
			"Yes",
			[
				"time.h",
			],
			[
				"time_getsystemtime.c",
				"time_wait.c",
			],
		],
		[
			"Process",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/system/process",
			"PROCESS",
			"Yes",
			[
				"process.h",
				"process_local.h",
			],
			[
				"process_create.c",
				"process_delete.c",
				"process_constructor.c",
				"process_destructor.c",
				"process_getcurrenthandle.c",
				"process_exit.c",
				"process_waitexit.c",
				"process_getexitcode.c",
				"process_setcurrentdir.c",
				"process_getcurrentdir.c",
				"process_getparentprocess.c",
				"process_getexecutiontime.c",
				"process_getcommandline.c",
				"process_setterminal.c",
				"process_getterminal.c",
				"process_setconsole.c",
				"process_getconsole.c",
				"process_setstdin.c",
				"process_getstdin.c",
				"process_setstdout.c",
				"process_getstdout.c",
				"process_setstderr.c",
				"process_getstderr.c",
			],
		],
		[
			"Event",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/system/event",
			"EVENT",
			"Yes",
			[
				"event.h",
				"event_local.h",
			],
			[
				"event_create.c",
				"event_delete.c",
				"event_set.c",
				"event_wait.c",
			]
		],
		[
			"File",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/system/file",
			"FILE",
			"Yes",
			[
				"console.h",
				"drvobj.h",
				"drvobj_local.h",
				"file.h",
				"fileobj.h",
				"fileobj_local.h",
				"file_local.h",
				"stdfile.h",
				"syncdrv.h",
				"syncdrv_local.h",
				"syncfile.h",
				"syncfile_local.h",
				"sysvol.h",
				"sysvolfile.h",
				"sysvolfile_local.h",
				"sysvol_local.h",
				"volume.h",
				"volumeobj.h",
				"volumeobj_local.h",
			],
			[
				"console_getch.c",
				"drvobj_close.c",
				"drvobj_constructor.c",
				"drvobj_destructor.c",
				"drvobj_flush.c",
				"drvobj_iocontrol.c",
				"drvobj_open.c",
				"drvobj_read.c",
				"drvobj_seek.c",
				"drvobj_write.c",
				"filefmt.c",
				"fileobj_constructor.c",
				"fileobj_create.c",
				"fileobj_delete.c",
				"fileobj_destructor.c",
				"file_adddevice.c",
				"file_addvolume.c",
				"file_close.c",
				"file_getchar.c",
				"file_getstring.c",
				"file_initialize.c",
				"file_iocontrol.c",
				"file_open.c",
				"file_putchar.c",
				"file_putstring.c",
				"file_read.c",
				"file_readdir.c",
				"file_seek.c",
				"file_write.c",
				"stdfile.c",
				"syncdrv_constructor.c",
				"syncdrv_destructor.c",
				"syncdrv_endprocess.c",
				"syncdrv_iocontrol.c",
				"syncdrv_sendsignal.c",
				"syncdrv_startprocess.c",
				"syncfile_constructor.c",
				"syncfile_create.c",
				"syncfile_delete.c",
				"syncfile_destructor.c",
				"syncfile_setsignal.c",
				"sysvolfile_constructor.c",
				"sysvolfile_create.c",
				"sysvolfile_delete.c",
				"sysvolfile_destructor.c",
				"sysvol_adddevice.c",
				"sysvol_close.c",
				"sysvol_constructor.c",
				"sysvol_create.c",
				"sysvol_delete.c",
				"sysvol_destructor.c",
				"sysvol_iocontrol.c",
				"sysvol_open.c",
				"volumeobj_constructor.c",
				"volumeobj_create.c",
				"volumeobj_delete.c",
				"volumeobj_destructor.c",
				"volumeobj_makedir.c",
				"volumeobj_remove.c",
			],
		],
		[
			"Command",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/system/command",
			"COMMAND",
			"Yes",
			[
				"command.h",
			],
			[
				"command.c",
			]
		],
	],
	[
		"Librarys",
		[
			"Memory Pool",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/library/container/mempol",
			"MEMPOL",
			"Yes",
			[
				"mempol.h",
			],
			[
				"mempol.c",
			]
		],
		[
			"Association Array",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/library/container/assoc",
			"ASSOC",
			"Yes",
			[
				"assoc.h",
			],
			[
				"assoc.c",
			]
		],
		[
			"List",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/library/container/list",
			"LIST",
			"Yes",
			[
				"list.h",
				"list_local.h",
			],
			[
				"list_create.c",
				"list_createex.c",
				"list_addtail.c",
				"list_getat.c",
				"list_getheadpos.c",
				"list_getnextpos.c",
				"list_getprevpos.c",
				"list_gettailpos.c",
				"list_remove.c",
			]
		],
		[
			"Stream Buffer",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/library/container/streambuf",
			"STREAMBUF",
			"Yes",
			[
				"streambuf.h",
				"streambuf_local.h",
			],
			[
				"streambuf_create.c",
				"streambuf_getbuf.c",
				"streambuf_sendbuf.c",
				"streambuf_senddata.c",
				"streambuf_sendchar.c",
				"streambuf_recvbuf.c",
				"streambuf_relbuf.c",
				"streambuf_recvdata.c",
				"streambuf_recvchar.c",
				"streambuf_clear.c",
				"streambuf_refdatasize.c",
				"streambuf_reffreesize.c",
			],
		],
		[
			"Packet Buffer",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/library/container/packetbuf",
			"PACKETBUF",
			"Yes",
			[
				"packetbuf.h",
				"packetbuf_local.h",
			],
			[
				"packetbuf_create.c",
				"packetbuf_getbuf.c",
				"packetbuf_sendbuf.c",
				"packetbuf_senddata.c",
				"packetbuf_recvbuf.c",
				"packetbuf_relbuf.c",
				"packetbuf_recvdata.c",
				"packetbuf_clear.c",
			],
		],
		[
			"IP check-sum",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/library/algorithm/ipchecksum",
			"IPCHECKSUM",
			"Yes",
			[
				"ipchecksum.h",
				"ipchecksum_local.h",
			],
			[
				"ipchecksum_getdigest.c",
				"ipchecksum_update.c",
			],
		],
		[
			"16bit CRC",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/library/algorithm/crc16",
			"CRC16",
			"Yes",
			[
				"crc16.h",
				"crc16_local.h",
			],
			[
				"crc16_getdigest.c",
				"crc16_update.c",
				"crc16_reset.c",
				"crc16_table.c",
			],
		],
	],
	[
		"Device Drivers",
		[
			"VT100",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/console/vt100",
			"VT100",
			"Yes",
			[
				"vt100drv.h",
				"vt100drv_local.h",
			],
			[
				"vt100drv_create.c",
				"vt100drv_delete.c",
				"vt100drv_constructor.c",
				"vt100drv_destructor.c",
				"vt100drv_open.c",
				"vt100drv_close.c",
				"vt100drv_iocontrol.c",
				"vt100drv_seek.c",
				"vt100drv_read.c",
				"vt100drv_write.c",
				"vt100drv_flush.c",
				"vt100drv_getch.c",
			],
		],
		[
			"TCP/IP",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/tcpip/tcpip",
			"TCPIP",
			"Yes",
			[
				"tcpip.h",
				"tcpip_local.h",
				"tcpipfile.h",
				"tcpipfile_local.h",
			],
			[
				"tcpip_create.c",
				"tcpip_delete.c",
				"tcpip_constructor.c",
				"tcpip_destructor.c",
				"tcpip_open.c",
				"tcpip_close.c",
				"tcpip_iocontrol.c",
				"tcpip_seek.c",
				"tcpip_read.c",
				"tcpip_write.c",
				"tcpip_flush.c",
				"tcpip_recv.c",
				"tcpipfile_create.c",
				"tcpipfile_delete.c",
				"tcpipfile_constructor.c",
				"tcpipfile_destructor.c",
			],
		],
		[
			"IpEther",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/tcpip/ipether",
			"IPETHER",
			"Yes",
			[
				"ipether.h",
				"ipether_local.h",
			],
			[
				"ipether_create.c",
				"ipether_delete.c",
				"ipether_constructor.c",
				"ipether_destructor.c",
				"ipether_open.c",
				"ipether_close.c",
				"ipether_iocontrol.c",
				"ipether_seek.c",
				"ipether_read.c",
				"ipether_write.c",
				"ipether_recv.c",
				"ipether_flush.c",
				"ipether_getmacaddr.c",
			],
		],
		[
			"NE2000",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/ether/ne2000",
			"NE2000",
			"No",
			[
				"ne2000drv.h",
				"ne2000hal.h",
			],
			[
				"ne2000drv.c",
				"ne2000hal.c",
			],
		],
		[
			"LAN91C111",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/ether/lan9000",
			"LAN9000",
			"No",
			[
				"lan9000drv.h",
				"lan9000drv_local.h",
				"lan9000hal.h",
				"lan9000hal_local.h",
			],
			[
				"lan9000drv_close.c",
				"lan9000drv_create.c",
				"lan9000drv_delete.c",
				"lan9000drv_constructor.c",
				"lan9000drv_destructor.c",
				"lan9000drv_flush.c",
				"lan9000drv_iocontrol.c",
				"lan9000drv_isr.c",
				"lan9000drv_open.c",
				"lan9000drv_read.c",
				"lan9000drv_seek.c",
				"lan9000drv_write.c",
				"lan9000hal_create.c",
				"lan9000hal_delete.c",
				"lan9000hal_getinterruptstatus.c",
				"lan9000hal_getphysicaladdr.c",
				"lan9000hal_mii.c",
				"lan9000hal_phyregread.c",
				"lan9000hal_phyregwrite.c",
				"lan9000hal_recv.c",
				"lan9000hal_send.c",
				"lan9000hal_setinterruptmask.c",
				"lan9000hal_setup.c",
				"lan9000hal_stop.c",
			]
		],
		[
			"LAN91C111",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/ether/lan9118",
			"LAN9118",
			"No",
			[
				"lan9118drv.h",
			],
			[
				"lan9118drv_create.c",
				"lan9118drv_delete.c",
				"lan9118drv_open.c",
				"lan9118drv_close.c",
				"lan9118drv_iocontrol.c",
				"lan9118drv_seek.c",
				"lan9118drv_read.c",
				"lan9118drv_write.c",
				"lan9118drv_flush.c",
				"lan9118drv_isr.c",
			],
		],
		[
			"16550A",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/serial/pc16550",
			"PC16550",
			"Yes",
			[
				"pc16550drv.h",
				"pc16550drv_local.h",
				"pc16550hal.h",
				"pc16550hal_local.h",
			],
			[
				"pc16550drv_create.c",
				"pc16550drv_delete.c",
				"pc16550drv_constructor.c",
				"pc16550drv_destructor.c",
				"pc16550drv_open.c",
				"pc16550drv_close.c",
				"pc16550drv_iocontrol.c",
				"pc16550drv_seek.c",
				"pc16550drv_read.c",
				"pc16550drv_write.c",
				"pc16550drv_flush.c",
				"pc16550drv_isr.c",
				"pc16550hal_create.c",
				"pc16550hal_delete.c",
				"pc16550hal_setup.c",
				"pc16550hal_stop.c",
				"pc16550hal_setspeed.c",
				"pc16550hal_recvchar.c",
				"pc16550hal_sendchar.c",
				"pc16550hal_enableinterrupt.c",
				"pc16550hal_getinterruptstatus.c",
				"pc16550hal_getstatus.c",
			],
		],
		[
			"Atmel AT91 USART",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/serial/at91",
			"AT91USART",
			"No",
			[
				"at91usartdrv.h",
				"at91usartdrv_local.h",
			],
			[
				"at91usartdrv_create.c",
				"at91usartdrv_delete.c",
				"at91usartdrv_constructor.c",
				"at91usartdrv_destructor.c",
				"at91usartdrv_open.c",
				"at91usartdrv_close.c",
				"at91usartdrv_iocontrol.c",
				"at91usartdrv_seek.c",
				"at91usartdrv_read.c",
				"at91usartdrv_write.c",
				"at91usartdrv_flush.c",
				"at91usartdrv_isr.c",
			],
		],
		[
			"Renesas SCI",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/serial/renesas",
			"RENESASSCI",
			"No",
			[
				"scidrv.h",
				"scidrv_local.h",
				"scihal.h",
				"scihal_local.h",
			],
			[
				"scidrv_create.c",
				"scidrv_delete.c",
				"scidrv_constructor.c",
				"scidrv_destructor.c",
				"scidrv_open.c",
				"scidrv_close.c",
				"scidrv_iocontrol.c",
				"scidrv_seek.c",
				"scidrv_read.c",
				"scidrv_write.c",
				"scidrv_flush.c",
				"scidrv_isrrxerr.c",
				"scidrv_isrrx.c",
				"scidrv_isrtx.c",
				"scidrv_isrtxend.c",
				"scihal_create.c",
				"scihal_delete.c",
				"scihal_enableinterrupt.c",
				"scihal_recvchar.c",
				"scihal_sendchar.c",
				"scihal_setspeed.c",
				"scihal_setup.c",
				"scihal_stop.c",
			]
		],
		[
			"Freescale MX1 UART",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/serial/mx1",
			"MX1UART",
			"No",
			[
				"mx1uartdrv.h",
				"mx1uartdrv_local.h",
			],
			[
				"mx1uartdrv_create.c",
				"mx1uartdrv_delete.c",
				"mx1uartdrv_constructor.c",
				"mx1uartdrv_destructor.c",
				"mx1uartdrv_open.c",
				"mx1uartdrv_close.c",
				"mx1uartdrv_iocontrol.c",
				"mx1uartdrv_seek.c",
				"mx1uartdrv_read.c",
				"mx1uartdrv_write.c",
				"mx1uartdrv_flush.c",
				"mx1uartdrv_isr.c",
			],
		],
		[
			"Panasonic MN103 SC",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/serial/mn103",
			"MN103SC",
			"No",
			[
				"mn103scdrv.h",
				"mn103scdrv_local.h",
			],
			[
				"mn103scdrv_create.c",
				"mn103scdrv_delete.c",
				"mn103scdrv_constructor.c",
				"mn103scdrv_destructor.c",
				"mn103scdrv_open.c",
				"mn103scdrv_close.c",
				"mn103scdrv_iocontrol.c",
				"mn103scdrv_seek.c",
				"mn103scdrv_read.c",
				"mn103scdrv_write.c",
				"mn103scdrv_flush.c",
				"mn103scdrv_isrtx.c",
				"mn103scdrv_isrrx.c",
			],
		],
		[
			"WinSock",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/serial/winsock",
			"WINSOCK",
			"No",
			[
				"winsockdrv.h",
			],
			[
				"winsockdrv.c",
			],
		],
		[
			"FAT volume",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/driver/volume/fat",
			"FATVOL",
			"Yes",
			[
				"fatvol.h",
				"fatvol_local.h",
				"fatfile.h",
				"fatfile_local.h",
			],
			[
				"fatvol_create.c",
				"fatvol_delete.c",
				"fatvol_constructor.c",
				"fatvol_destructor.c",
				"fatvol_open.c",
				"fatvol_close.c",
				"fatvol_iocontrol.c",
				"fatvol_seek.c",
				"fatvol_read.c",
				"fatvol_write.c",
				"fatvol_flush.c",
				"fatvol_makedir.c",
				"fatvol_remove.c",
				"fatvol_clusterread.c",
				"fatvol_clusterwrite.c",
				"fatvol_flushclusterbuf.c",
				"fatvol_flushfat.c",
				"fatvol_getclusterbuf.c",
				"fatvol_relclusterbuf.c",
				"fatvol_getnewcluster.c",
				"fatvol_getnextcluster.c",
				"fatvol_setnextcluster.c",
				"fatvol_syncfilesize.c",
				"fatfile_create.c",
				"fatfile_delete.c",
				"fatfile_constructor.c",
				"fatfile_destructor.c",
			],
		],
	],
	[
		"Applications",
		[
			"Shell",
			"\$(COMMON_HEADERS) \$(SYSTEM_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/syscmd/shell",
			"SHELL",
			"Yes",
			[
				"shell.h",
				"shell_local.h",
			],
			[
				"shell_main.c",
				"shell_create.c",
				"shell_delete.c",
				"shell_executecommand.c",
				"shell_executescript.c",
				"shell_inputline.c",
				"shell_interactive.c",
				"shell_putchar.c",
				"shell_curright.c",
				"shell_curleft.c",
				"shell_replaceline.c",
			]
		],
		[
			"Process List",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/syscmd/processlist",
			"PROCESSLIST",
			"Yes",
			[
				"processlist.h",
			],
			[
				"processlist_main.c",
			],
		],
		[
			"Memory Dump",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/utility/memdump",
			"MEMDUMP",
			"Yes",
			[
				"memdump.h",
			],
			[
				"memdump_main.c",
			],
		],
		[
			"Memory Write",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/utility/memwrite",
			"MEMWRITE",
			"Yes",
			[
				"memwrite.h",
			],
			[
				"memwrite_main.c",
			]
		],
		[
			"Memory Test",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/utility/memtest",
			"MEMTEST",
			"Yes",
			[
				"memtest.h",
			],
			[
				"memtest_main.c",
			],
		],
		[
			"Key Test",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/utility/keytest",
			"KEYTEST",
			"Yes",
			[
				"keytest.h",
			],
			[
				"keytest_main.c",
			],
		],
		[
			"Time Command",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/utility/timecmd",
			"TIMECMD",
			"Yes",
			[
				"timecmd.h",
			],
			[
				"timecmd_main.c",
			],
		],
		[
			"File List",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/filecmd/filelist",
			"FILELIST",
			"Yes",
			[
				"filelist.h",
			],
			[
				"filelist_main.c",
			],
		],
		[
			"File Cat",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/filecmd/filecat",
			"FILECAT",
			"Yes",
			[
				"filecat.h",
			],
			[
				"filecat_main.c",
			],
		],
		[
			"File Copy",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/filecmd/filecopy",
			"FILECOPY",
			"Yes",
			[
				"filecopy.h",
			],
			[
				"filecopy_main.c",
			],
		],
		[
			"File Dump",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/filecmd/filedump",
			"FILEDUMP",
			"Yes",
			[
				"filedump.h",
			],
			[
				"filedump_main.c",
			],
		],
		[
			"Flash Command",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/flashcmd/norflashcmd",
			"FLASHCMD",
			"Yes",
			[
				"norflashcmd.h",
			],
			[
				"norflashcmd_main.c",
			],
		],
		[
			"Ether Snoopt",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/netcmd/ethersnoop",
			"ETHERSNOOP",
			"Yes",
			[
				"ethersnoop.h",
			],
			[
				"ethersnoop_main.c",
			],
		],
		[
			"Hello World",
			"\$(COMMON_HEADERS)",
			"\$(HOSAPLFW_DIR)/application/example/hello",
			"HELLO",
			"Yes",
			[
				"hello.h",
			],
			[
				"hello_main.c",
			],
		],
	],
);



# --------------------------------------------------
#  gmake source
# --------------------------------------------------

open(OUT, "> ../gmake/aplfwsrc.inc");

print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "#  Hyper Operating System V4 Advance  Application Framework\n");
print(OUT "#    common include file for GNU make\n");
print(OUT "#\n");
print(OUT "#  Copyright (C) 1998-2007 by Project HOS\n");
print(OUT "#  http://sourceforge.jp/projects/hos/\n");
print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");


print(OUT "# --------------------------------------------------\n");
print(OUT "#  Default setting\n");
print(OUT "# --------------------------------------------------\n");
foreach $s ( @sources )
{
	@sys_list = @{$s};
	$subsystem = shift(@sys_list);
	
	print(OUT "\n");
	print(OUT "# $subsystem\n");
	
	foreach $s ( @sys_list )
	{
		@list = @{$s};
		
		$comment  = shift(@list);
		$depend   = shift(@list);
		$path     = shift(@list);
		$def_name = shift(@list);
		$link     = shift(@list);
		
		printf(OUT "LINK_%-16s ?= %s\n", $def_name, $link);
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# --------------------------------------------------\n");
print(OUT "#  Include\n");
print(OUT "# --------------------------------------------------\n");
print(OUT "\n");
print(OUT "# Include directories\n");
print(OUT "INC_DIRS += \$(HOSAPLFW_DIR)\n");


foreach $s ( @sources )
{
	@sys_list = @{$s};
	$subsystem = shift(@sys_list);
	
	print(OUT "\n");
	print(OUT "\n");
	print(OUT "\n");
	print(OUT "# --------------------------------------------------\n");
	print(OUT "#  $subsystem\n");
	print(OUT "# --------------------------------------------------");
	
	foreach $s ( @sys_list )
	{
		@list = @{$s};
		
		$comment  = shift(@list);
		$depend   = shift(@list);
		$path     = shift(@list);
		$def_name = shift(@list);
		$link     = shift(@list);
		@hdrs     = @{shift(@list)};
		@srcs     = @{shift(@list)};
		
		$dir_name = $def_name . "_DIR";
		
		print(OUT "\n\n");
		print(OUT "# $comment\n");
		print(OUT "ifeq (\$(LINK_$def_name),Yes)\n");
		print(OUT "$dir_name = $path\n");
		print(OUT "SRC_DIRS += \$($dir_name)\n");
		foreach $file ( @srcs )
		{
			print(OUT "CSRCS += \$($dir_name)/$file\n");
		}
		print(OUT "endif\n");
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "# end of file\n");

close(OUT);



# --------------------------------------------------
#  gmake depend
# --------------------------------------------------

open(OUT, "> ../gmake/aplfwdep.inc");

print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "#  Hyper Operating System V4 Advance  Application Framework\n");
print(OUT "#    common depend file for GNU make\n");
print(OUT "#\n");
print(OUT "#  Copyright (C) 1998-2007 by Project HOS\n");
print(OUT "#  http://sourceforge.jp/projects/hos/\n");
print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");

foreach $s ( @sources )
{
	@sys_list = @{$s};
	$subsystem = shift(@sys_list);
	
	foreach $s ( @sys_list )
	{
		@list = @{$s};
		
		$comment  = shift(@list);
		$depend   = shift(@list);
		$path     = shift(@list);
		$def_name = shift(@list);
		$link     = shift(@list);
		@hdrs     = @{shift(@list)};
		@srcs     = @{shift(@list)};
		
		$dir_name = $def_name . "_DIR";
		
		foreach $file ( @srcs )
		{
			$objfile = $file;
			$objfile =~ s/\.c/\./;
			print(OUT "\$(OBJS_DIR)/$objfile\$(EXT_OBJ):\t\$($dir_name)/$file\t$depend\n");
		}
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "# end of file\n");

close(OUT);



# --------------------------------------------------
#  nmake source
# --------------------------------------------------

open(OUT, "> ../nmake/aplfwsrc.inc");

print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "#  Hyper Operating System V4 Advance  Application Framework\n");
print(OUT "#    common include file for nmake\n");
print(OUT "#\n");
print(OUT "#  Copyright (C) 1998-2007 by Project HOS\n");
print(OUT "#  http://sourceforge.jp/projects/hos/\n");
print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");


print(OUT "# --------------------------------------------------\n");
print(OUT "#  Default setting\n");
print(OUT "# --------------------------------------------------\n");
foreach $s ( @sources )
{
	@sys_list = @{$s};
	$subsystem = shift(@sys_list);
	
	print(OUT "\n");
	print(OUT "# $subsystem\n");
	
	foreach $s ( @sys_list )
	{
		@list = @{$s};
		
		$comment  = shift(@list);
		$depend   = shift(@list);
		$path     = shift(@list);
		$def_name = shift(@list);
		$link     = shift(@list);
		@hdrs     = @{shift(@list)};
		@srcs     = @{shift(@list)};
		
		print(OUT  "!ifndef LINK_$def_name\n");
		printf(OUT "LINK_%-16s = %s\n", $def_name, $link);
		print(OUT  "!endif\n");
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# --------------------------------------------------\n");
print(OUT "#  Include\n");
print(OUT "# --------------------------------------------------\n");
print(OUT "\n");
print(OUT "# Include directories\n");
print(OUT "INC_DIRS = \$(INC_DIRS) \$(HOSAPLFW_DIR)\n");


foreach $s ( @sources )
{
	@sys_list = @{$s};
	$subsystem = shift(@sys_list);
	
	print(OUT "\n");
	print(OUT "\n");
	print(OUT "\n");
	print(OUT "# --------------------------------------------------\n");
	print(OUT "#  $subsystem\n");
	print(OUT "# --------------------------------------------------");
	
	foreach $s ( @sys_list )
	{
		@list = @{$s};
		
		$comment  = shift(@list);
		$depend   = shift(@list);
		$path     = shift(@list);
		$def_name = shift(@list);
		$link     = shift(@list);
		@hdrs     = @{shift(@list)};
		@srcs     = @{shift(@list)};
		
		$path   =~ s/\//\\/g;
		
		$dir_name = $def_name . "_DIR";
		
		print(OUT "\n\n");
		print(OUT "# $comment\n");
		print(OUT "!if \"\$(LINK_$def_name)\" == \"Yes\"\n");
		print(OUT "$dir_name = $path\n");
		foreach $file ( @hdrs )
		{
			print(OUT "HEADERS = \$(HEADERS) \$(OBJS_DIR)\\$file\n");
		}
		foreach $file ( @srcs )
		{
			$file_base = $file;
			$file_base =~ s/\.c//g;
			print(OUT "CSRCS = \$(CSRCS) \$($dir_name)\\$file\n");
			print(OUT "OBJS  = \$(OBJS)  \$(OBJS_DIR)\\$file_base\.\$(EXT_OBJ)\n");
		}
		print(OUT "!endif\n");
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "# end of file\n");

close(OUT);



# --------------------------------------------------
#  nmake depend
# --------------------------------------------------

open(OUT, "> ../nmake/aplfwdep.inc");

print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "#  Hyper Operating System V4 Advance  Application Framework\n");
print(OUT "#    common depend file for nmake\n");
print(OUT "#\n");
print(OUT "#  Copyright (C) 1998-2007 by Project HOS\n");
print(OUT "#  http://sourceforge.jp/projects/hos/\n");
print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# ----------------------------------\n");
print(OUT "#  source copy\n");
print(OUT "# ----------------------------------\n");
print(OUT "makelib_srcobjcp: \$(HEADERS)\n\n");


foreach $s ( @sources )
{
	@sys_list = @{$s};
	$subsystem = shift(@sys_list);
	foreach $s ( @sys_list )
	{
		@list = @{$s};
		
		$comment  = shift(@list);
		$depend   = shift(@list);
		$path     = shift(@list);
		$def_name = shift(@list);
		$link     = shift(@list);
		@hdrs     = @{shift(@list)};
		@srcs     = @{shift(@list)};
		
		$depend =~ s/\//\\/g;
		$path   =~ s/\//\\/g;
		
		$dir_name = $def_name . "_DIR";
		
		print(OUT "\n");
		foreach $file ( @hdrs )
		{
			print(OUT "\$(OBJS_DIR)\\$file : \$($dir_name)\\$file\n");
			print(OUT "\t\$(CMD_CP) \$($dir_name)\\$file \$(OBJS_DIR)\\\n");
			print(OUT "\n");
		}
		foreach $file ( @srcs )
		{
			print(OUT "\$(OBJS_DIR)\\$file : \$($dir_name)\\$file\n");
			print(OUT "\t\$(CMD_CP) \$($dir_name)\\$file \$(OBJS_DIR)\\\n");
			print(OUT "\n");
		}
	}
}

print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# ----------------------------------\n");
print(OUT "#  depend\n");
print(OUT "# ----------------------------------\n");

foreach $s ( @sources )
{
	@sys_list = @{$s};
	$subsystem = shift(@sys_list);
	foreach $s ( @sys_list )
	{
		@list = @{$s};
		
		$comment  = shift(@list);
		$depend   = shift(@list);
		$path     = shift(@list);
		$def_name = shift(@list);
		$link     = shift(@list);
		@hdrs     = @{shift(@list)};
		@srcs     = @{shift(@list)};
		
		$depend =~ s/\//\\/g;
		$path   =~ s/\//\\/g;
		
		$dir_name = $def_name . "_DIR";
		
		print(OUT "\n");
		foreach $file ( @srcs )
		{
			$objfile = $file;
			$objfile =~ s/\.c//g;
			print(OUT "\$(OBJS_DIR)\\$objfile.\$(EXT_OBJ):\t\$(OBJS_DIR)\\$file\t$depend\n");
		}
	}
}

print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# end of file\n");

close(OUT);

exit(0);

