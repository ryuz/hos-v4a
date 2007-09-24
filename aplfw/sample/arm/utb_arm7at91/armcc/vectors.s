

				IMPORT	Reset_Handler
				IMPORT	Undefined_Handler
				IMPORT	Swi_Handler
				IMPORT	Prefetch_Handler
				IMPORT	Abort_Handler
				IMPORT	_kernel_irq_hdr
				IMPORT	_kernel_fiq_hdr


				CODE32

				PRESERVE8
				AREA	Init, CODE, READONLY

				ENTRY

		IF :DEF: ROM_AT_ADDRESS_ZERO

				ldr     pc, Reset_Addr
				ldr     pc, Undefined_Addr
				ldr     pc, Swi_Addr
				ldr     pc, Prefetch_Addr
				ldr     pc, Abort_Addr
				nop
				ldr     pc, Irq_Addr
				ldr     pc, Fiq_Addr

		ELSE

				mov 	r8, #0
				adr 	r9, Vector_Init_Block
				ldmia	r9!, {r0-r7}
				stmia	r8!, {r0-r7}
				ldmia	r9!, {r0-r7}
				stmia	r8!, {r0-r7}

Vector_Init_Block
				ldr 	pc, Reset_Addr
				ldr 	pc, Undefined_Addr
				ldr 	pc, Swi_Addr
				ldr 	pc, Prefetch_Addr
				ldr 	pc, Abort_Addr
				nop
				ldr 	pc, Irq_Addr
				ldr 	pc, Fiq_Addr

		ENDIF



Reset_Addr		dcd		Reset_Handler
Undefined_Addr	dcd		Undefined_Handler
Swi_Addr		dcd		Swi_Handler
Prefetch_Addr	dcd		Prefetch_Handler
Abort_Addr		dcd		Abort_Handler
Irq_Addr		dcd		_kernel_irq_hdr
Fiq_Addr		dcd		_kernel_fiq_hdr



				END



; end of file
