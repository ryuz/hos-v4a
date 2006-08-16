#include <stdio.h>
#include <string.h>


#define BUF_SIZE					4096

#define MAIN_ST_CODE				0
#define MAIN_ST_COMMENT1			1
#define MAIN_ST_COMMENT2			2

#define COMMENT_ST_NORMAL			0
#define COMMENT_ST_FILTER_CHECK		1
#define COMMENT_ST_FILTER_OK		2
#define COMMENT_ST_FILTER_NG		3


char szBuf[BUF_SIZE];
int  iBufSize      = 0;
int  iMainState    = MAIN_ST_CODE;
int  iCommentState = COMMENT_ST_NORMAL;
FILE *fpIn         = stdin;
FILE *fpOut        = stdout;
char *pszFilter    = "en";
int  c;


static void CommentState(void);
static void FlushBuffer(void);


int main(int argc, char *argv[])
{
	
	while ( (c = fgetc(fpIn)) != EOF )
	{
		szBuf[iBufSize++] = c;
		if ( iBufSize <= 1 )
		{
			continue;
		}

		switch ( iMainState )
		{
		case MAIN_ST_CODE:
			if ( iBufSize > 1 )
			{
				if ( szBuf[0] == '/' && szBuf[1] == '*' )
				{
					FlushBuffer();
					iMainState    = MAIN_ST_COMMENT1;
					iCommentState = COMMENT_ST_NORMAL;
				}
				else if ( szBuf[0] == '/' && szBuf[1] == '/' )
				{
					FlushBuffer();
					iMainState    = MAIN_ST_COMMENT2;
					iCommentState = COMMENT_ST_NORMAL;
				}
				else
				{
					fputc(szBuf[0], fpOut);
					szBuf[0] = szBuf[1];
					iBufSize = 1;
				}
			}
			break;

		case MAIN_ST_COMMENT1:
			if ( szBuf[iBufSize - 2] == '*' && szBuf[iBufSize - 1] == '/' )
			{
				FlushBuffer();
				iMainState = MAIN_ST_CODE;
			}
			else
			{
				CommentState();
			}
			break;

		case MAIN_ST_COMMENT2:
			if ( szBuf[iBufSize - 1] == '\n' )
			{
				FlushBuffer();
				iMainState = MAIN_ST_CODE;
			}
			else
			{
				CommentState();
			}
			break;
		}
	}

	return 0;
}


void CommentState(void)
{
	switch ( iCommentState )
	{
	case COMMENT_ST_NORMAL:
		if ( iBufSize > 1 )
		{
			if ( szBuf[0] == '%' )
			{
				if ( szBuf[1] != '%' )
				{
					iCommentState = COMMENT_ST_FILTER_CHECK;
					szBuf[0] = szBuf[1];
					iBufSize = 1;
				}
				else
				{
					fputc('%', fpOut);
					iBufSize = 0;
				}
			}
			else
			{
				fputc(szBuf[0], fpOut);
				szBuf[0] = szBuf[1];
				iBufSize = 1;
			}
		}
		break;

	case COMMENT_ST_FILTER_CHECK:
		if ( szBuf[iBufSize - 1] == '{' )
		{
			szBuf[iBufSize - 1] = '\0';
			if ( strcmp(szBuf, pszFilter) == 0 )
			{
				iCommentState = COMMENT_ST_FILTER_OK;
			}
			else
			{
				iCommentState = COMMENT_ST_FILTER_NG;
			}
			iBufSize = 0;
		}
		break;
	
	case COMMENT_ST_FILTER_OK:
		if ( szBuf[1] == '}' )
		{
			fputc(szBuf[0], fpOut);
			iBufSize = 0;
			iCommentState = COMMENT_ST_NORMAL;
		}
		else
		{
			fputc(szBuf[0], fpOut);
			szBuf[0] = szBuf[1];
			iBufSize = 1;
		}
		break;

	case COMMENT_ST_FILTER_NG:
		if ( szBuf[1] == '}' )
		{
			iBufSize = 0;
			iCommentState = COMMENT_ST_NORMAL;
		}
		else
		{
			szBuf[0] = szBuf[1];
			iBufSize = 1;
		}
		break;
	}
}



void FlushBuffer(void)
{
	szBuf[iBufSize] = '\0';
	fputs(szBuf, fpOut);
	iBufSize = 0;
}
