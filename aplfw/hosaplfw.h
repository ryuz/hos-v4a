
/* ユーザープロセスから使っても良いAPIを一括読み込み */

#ifndef __HOS__hosaplfw_h__
#define __HOS__hosaplfw_h__


#include "system/system/system.h"
#include "system/handle/handle.h"
#include "system/memory/memory.h"
#include "system/event/event.h"
/* #include "system/mutex/mutex.h" */
#include "system/time/time.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/file/file.h"
#include "system/file/volume.h"
#include "system/file/stdfile.h"

#include "library/algorithm/stringformat/stringformat.h"
#include "library/utility/memutil/memutil.h"



#define _DEBUG_PRINTF	StdIo_PrintFormat

#ifdef _DEBUG
#define _ASSERT(x)									do { if (!(x)) { for(;;) ; } } while (0)
#define _DEBUG_PRINT0(x)							do { _DEBUG_PRINTF((x)); } while (0)
#define _DEBUG_PRINT1(x, p1)						do { _DEBUG_PRINTF((x), (p1)); } while (0)
#define _DEBUG_PRINT2(x, p1, p2)					do { _DEBUG_PRINTF((x), (p1), (p2)); } while (0)
#define _DEBUG_PRINT3(x, p1, p2, p3)				do { _DEBUG_PRINTF((x), (p1), (p2), (p3)); } while (0)
#define _DEBUG_PRINT4(x, p1, p2, p3, p4)			do { _DEBUG_PRINTF((x), (p1), (p2), (p3), (p4)); } while (0)
#define _DEBUG_PRINT5(x, p1, p2, p3, p4, p5)		do { _DEBUG_PRINTF((x), (p1), (p2), (p3), (p4), (p5)); } while (0)
#define _DEBUG_PRINT6(x, p1, p2, p3, p4, p5, p6)	do { _DEBUG_PRINTF((x), (p1), (p2), (p3), (p4), (p5), (p6)); } while (0)
#else
#define _ASSERT(x)									do {} while (0)
#define _DEBUG_PRINT0(x)							do {} while (0)
#define _DEBUG_PRINT1(x, p1)						do {} while (0)
#define _DEBUG_PRINT2(x, p1, p2)					do {} while (0)
#define _DEBUG_PRINT3(x, p1, p2, p3)				do {} while (0)
#define _DEBUG_PRINT4(x, p1, p2, p3, p4)			do {} while (0)
#define _DEBUG_PRINT5(x, p1, p2, p3, p4, p5)		do {} while (0)
#define _DEBUG_PRINT6(x, p1, p2, p3, p4, p5, p6)	do {} while (0)
#endif


/* InternetProtocol バイトオーダー変換マクロ */

#define IP_SET_HALFWORD(p, h)												\
	do {																	\
		((unsigned char *)(p))[0] = (unsigned char)(((h) >> 8) & 0xff);		\
		((unsigned char *)(p))[1] = (unsigned char)(((h) >> 0) & 0xff);		\
	} while (0)

#define IP_GET_HALFWORD(p)													\
	((unsigned short)(														\
		  (((unsigned char *)(p))[0] << 8)									\
		+ (((unsigned char *)(p))[1] << 0)									\
	))

#define IP_SET_WORD(p, w)													\
	do {																	\
		((unsigned char *)(p))[0] = (unsigned char)(((w) >> 24) & 0xff);	\
		((unsigned char *)(p))[1] = (unsigned char)(((w) >> 16) & 0xff);	\
		((unsigned char *)(p))[2] = (unsigned char)(((w) >>  8) & 0xff);	\
		((unsigned char *)(p))[3] = (unsigned char)(((w) >>  0) & 0xff);	\
	} while (0)

#define IP_GET_WORD(p)														\
	((unsigned long)(														\
		  (((unsigned char *)(p))[0] << 24)									\
		+ (((unsigned char *)(p))[1] << 16)									\
		+ (((unsigned char *)(p))[2] << 8)									\
		+ (((unsigned char *)(p))[3] << 0)									\
	))



#endif /* __HOS__hosaplfw_h__ */

