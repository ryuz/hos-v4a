
/* ユーザープロセスから使っても良いAPIを一括読み込み */

#ifndef __HOS__hosaplfw_h__
#define __HOS__hosaplfw_h__


#include "system/handle/handle.h"
#include "system/memory/memory.h"
#include "system/event/event.h"
#include "system/mutex/mutex.h"
#include "system/time/time.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/file/file.h"
#include "system/file/stdfile.h"


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

