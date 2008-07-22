/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "tcpip_local.h"


FILE_ERR TcpIp_StringToAddr(T_TCPIP_ADDRESS *pAddr, const char *pszString)
{
	int iState = 0;
	int	c;

	/* 初期化 */
	pAddr->ubAddress[0] = 0;
	pAddr->ubAddress[1] = 0;
	pAddr->ubAddress[2] = 0;
	pAddr->ubAddress[3] = 0;
	pAddr->uhPort       = 0;
	
	while ( (c = *pszString++) != '\0' )
	{
		if ( c == '.' )
		{
			if ( iState >= 3 )
			{
				return FILE_ERR_NG;
			}
			iState++;
		}
		else if ( c == ':' )
		{
			iState = 4;
		}
		else if ( c >= '0' && c <= '9' )
		{
			if ( iState < 4 )
			{
				pAddr->ubAddress[iState] = (c - '0') + (pAddr->ubAddress[iState] * 10);
			}
			else
			{
				pAddr->uhPort = (c - '0') + (pAddr->uhPort * 10);
			}
		}
		else
		{
			return FILE_ERR_NG;
		}
	}	
	
	return FILE_ERR_OK;
}


/* endof file */
