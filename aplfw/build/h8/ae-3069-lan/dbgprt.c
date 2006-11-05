#include "kernel.h"

#define REG_SCI1_SMR		((volatile UB*)0xffffffb8)
#define REG_SCI1_BRR		((volatile UB*)0xffffffb9)
#define REG_SCI1_SCR		((volatile UB*)0xffffffba)
#define REG_SCI1_TDR		((volatile UB*)0xffffffbb)
#define REG_SCI1_SSR		((volatile UB*)0xffffffbc)
#define REG_SCI1_RDR		((volatile UB*)0xffffffbd)


/* %jp{1文字出力} */
void SysDbg_PutChar(int c)
{
	while ( ((*REG_SCI1_SSR) & 0x80) != 0x80 )
		;
	
	*REG_SCI1_TDR = (UB)c;
	
	*REG_SCI1_SSR &= 0x7f;
}

