/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  vt100drv.h
 * @brief %jp{VT100 ターミナルドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "vt100drv_local.h"
#include "system/sysapi/sysapi.h"



/* １文字取得 */
int Vt100Drv_GetCh(C_VT100DRV *self)
{
	int c;
	
	for ( ; ; )
	{
		/* １文字取り込み */
		c = File_GetChar(self->hTty);
		if ( c < 0 )
		{
			return c;
		}
		
		/* ヌル文字 */
		if ( c == '\x00' )
		{
			continue;
		}
		
		/* \n */
		if ( c == '\n' )
		{
			continue;
		}
		
		/* \r -> \n */
		if ( c == '\r' )
		{
			return '\n';
		}

		/* BS */
		if ( c == '\x08' )
		{
			return CONSOLE_KEY_BACKSPACE;
		}
		
		/* エスケープシーケンス開始 */
		if ( c == '\x1b' )
		{
			self->iEscState = VT100DRV_ESC_ESC1;
			self->iEscNum   = 0;
			continue;
		}
		
		/* エスケープシーケンス解析 */
		switch ( self->iEscState )
		{
		case VT100DRV_ESC_IDLE:
			return c;

		case VT100DRV_ESC_ESC1:
			if ( c == '[' )
			{
				self->iEscState = VT100DRV_ESC_ESC2;
			}
			else
			{
				self->iEscState = VT100DRV_ESC_IDLE;
			}
			break;

		case VT100DRV_ESC_ESC2:
			if ( c == 'A' )
			{
				self->iEscState = VT100DRV_ESC_IDLE;
				return CONSOLE_KEY_UP;
			}
			else if ( c == 'B' )
			{
				self->iEscState = VT100DRV_ESC_IDLE;
				return CONSOLE_KEY_DOWN;
			}
			else if ( c == 'C' )
			{
				self->iEscState = VT100DRV_ESC_IDLE;
				return CONSOLE_KEY_RIGHT;
			}
			else if ( c == 'D' )
			{
				self->iEscState = VT100DRV_ESC_IDLE;
				return CONSOLE_KEY_LEFT;
			}
			else if ( c >= '0' && c <= '9' )
			{
				self->iEscState = VT100DRV_ESC_FUNC;
				self->iEscNum = c - '0';
			}
			else
			{
				self->iEscState = VT100DRV_ESC_IDLE;
			}
			break;
		
		case VT100DRV_ESC_FUNC:
			if ( c >= '0' && c <= '9' )
			{
				self->iEscNum = self->iEscNum * 10 + c - '0';
			}
			if ( c == '~' )
			{
				self->iEscState = VT100DRV_ESC_IDLE;

				switch ( self->iEscNum )
				{
				case 1:
					return CONSOLE_KEY_INS;

				case 2:
					return CONSOLE_KEY_HOME;

				case 4:
					return CONSOLE_KEY_DEL;

				case 5:
					return CONSOLE_KEY_END;

				case 3:
					return CONSOLE_KEY_PAGEUP;

				case 6:
					return CONSOLE_KEY_PAGEDOWN;

				case 11:
					return CONSOLE_KEY_F1;

				case 12:
					return CONSOLE_KEY_F2;

				case 13:
					return CONSOLE_KEY_F3;
				
				case 14:
					return CONSOLE_KEY_F4;
				
				case 15:
					return CONSOLE_KEY_F5;
				
				case 17:
					return CONSOLE_KEY_F6;
				
				case 18:
					return CONSOLE_KEY_F7;
				
				case 19:
					return CONSOLE_KEY_F8;
				
				case 20:
					return CONSOLE_KEY_F9;
				
				case 21:
					return CONSOLE_KEY_F10;
				
				case 23:
					return CONSOLE_KEY_F11;
				
				case 24:
					return CONSOLE_KEY_F12;
				}
			}
			break;
		
		default:
			self->iEscState = VT100DRV_ESC_IDLE;
			break;
		}
	}
}


/* end of file */
