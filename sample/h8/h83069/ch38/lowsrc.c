/***********************************************************************/
/*                                                                     */
/*  FILE        :lowsrc.c                                              */
/*  DATE        :Tue, Mar 04, 2003                                     */
/*  DESCRIPTION :Program of I/O Stream                                 */
/*  CPU TYPE    :H8/SH                                                 */
/*                                                                     */
/***********************************************************************/
                  
// SH・H8共用ファイル


#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "lowsrc.h"

/* H8のみno_float.hをインクルード */
#if   defined( __2000N__ ) || defined( __2600N__ ) || defined( __300HN__ ) || defined( __2000A__ ) || defined( __2600A__ ) || defined( __300HA__ ) || defined( __300__ ) || defined( __300L__ )
#include <no_float.h>
#endif

/* ファイル番号 */
#define STDIN  0					/* 標準入力           (コンソール) */
#define STDOUT 1					/* 標準出力           (コンソール) */
#define STDERR 2					/* 標準エラー出力     (コンソール) */

#define FLMIN  0					/* 最小のファイル番号              */

/* ファイルフラグ	*/
#define O_RDONLY 0x0001		/* 読み込み専用にオープン。						*/
#define O_WRONLY 0x0002		/* 書き出し専用にオープン。						*/
#define O_RDWR   0x0004		/* 読み書き、両用にオープン。					*/
#define O_CREAT  0x0008		/* ファイルが存在しない場合、新規作成。			*/
#define O_TRUNC  0x0010		/* ファイルが存在する場合、ファイルサイズを0に。*/
#define O_APPEND 0x0020		/* 次に読み書きを行うファイル内の位置を設定。	*/
							/* 0：ファイルの先頭。 1：ファイルの最後。		*/


/* 特殊文字コード */
#define CR 0x0d						/* 復帰                            */
#define LF 0x0a						/* 改行                            */

const int _nfiles = IOSTREAM;		/* 入出力ファイル数を指定。        */
struct _iobuf _iob[IOSTREAM];
unsigned char sml_buf[IOSTREAM];


/* H8ノーマルモード・SH */
#if   defined( __2000N__ ) || defined( __2600N__ ) || defined( __300HN__ ) || defined( _SH1 ) || defined( _SH2 ) || defined( _SH2E ) || defined( _SH3 ) || defined( _SH4 )
/* 標準入力からの1文字入力処理  */
extern void charput(char);
/* 標準出力への1文字出力処理    */
extern char charget(void);
/* ファイルへの1文字出力処理  	*/
extern char fcharput(char, unsigned char);
/* ファイルからの1文字入力処理	*/
extern char fcharget(char*, unsigned char);
/* ファイルのオープン			*/
extern char fileopen(char*, unsigned char, unsigned char*);
/* ファイルのクローズ         	*/
extern char fileclose(unsigned char);
/* ファイルポインタの移動 		*/
extern char fpseek(unsigned char, long, unsigned char);
/* ファイルポインタの取得		*/
extern char fptell(unsigned char, long*);

/* H8アドバンストモード */
#elif defined( __2000A__ ) || defined( __2600A__ ) || defined( __300HA__ )
/* 標準入力からの1文字入力処理  */
extern void charput(char);
/* 標準出力への1文字出力処理    */
extern char charget(void);
/* ファイルへの1文字出力処理  	*/
extern char fcharput(char, unsigned char);
/* ファイルからの1文字入力処理	*/
extern char fcharget(char*, unsigned char);
/* ファイルのオープン			*/
/* 引数格納レジスタ3指定。		*/
extern char __regparam3 fileopen(char*, unsigned char, unsigned char*);
/* ファイルのクローズ         	*/
extern char fileclose(unsigned char);
/* ファイルポインタの移動 		*/
extern char fpseek(unsigned char, long, unsigned char);
/* ファイルポインタの取得		*/
extern char fptell(unsigned char, long*);

/* H8300・H8300L */
#elif defined( __300__ ) || defined( __300L__ )
/* 標準入力からの1文字入力処理  */
extern void charput(char);
/* 標準出力への1文字出力処理    */
extern char charget(void);
/* ファイルへの1文字出力処理  	*/
extern char fcharput(char, unsigned char);
/* ファイルからの1文字入力処理	*/
extern char fcharget(char*, unsigned char);
/* ファイルのオープン			*/
/* 引数格納レジスタ3指定。		*/
extern char __regparam3 fileopen(char*, unsigned char, unsigned char*);
/* ファイルのクローズ         	*/
extern char fileclose(unsigned char);
/* ファイルポインタの移動 		*/
/* 引数格納レジスタ3指定。		*/
extern char __regparam3 fpseek(unsigned char, long, unsigned char);
/* ファイルポインタの取得		*/
extern char fptell(unsigned char, long*);
#endif

char flmod[IOSTREAM];			  /* オープンしたファイルのモード設定場所 */     


/**************************************************************************/
/*       open:file open                                                   */
/*          Return value:File number (Pass)                               */
/*                       -1          (Failure)                            */
/**************************************************************************/
open(char *name,						/* ファイル名					  */
     int  mode,							/* オープンモード				  */
     int  flg)							/* オープンフラグ				  */
{
    char 			rcode    = 0;		/* fileopen()の戻り値   	      */
	unsigned char	fileno   = 0;		/* ファイル番号                   */
	unsigned char	openmode = 0;		/* シミュレータ用オープンモード	  */


    if(strcmp(name,"stdin")==0){          /* 標準入力ファイル   */
             if((mode&O_RDONLY)==0){
                      return -1;
             }
             flmod[STDIN] = mode;
             return STDIN;
       }

       else if(strcmp(name,"stdout")==0){   /* 標準出力ファイル */
             if((mode&O_WRONLY)==0){
                      return -1;
             }
             flmod[STDOUT] = mode;
             return STDOUT;
       }

       else if(strcmp(name,"stderr")==0){   /* 標準エラー出力ファイル */
             if((mode&O_WRONLY)==0){
                      return -1;
             }
             flmod[STDERR] = mode;
             return STDERR;
       }


	flg = 0777;							/* フラグの設定					  */

    /* ファイル名に従ってモードをチェックし、ファイル番号を返す。	      */
	/* fileopen()でオープン処理を行い、得られたファイル番号を返す。		  */

	/*  引数で与えられたオープンモードをシミュレータ用に変換。		  	  */

	if( mode == O_RDONLY )								/*  "r"   */ 
	{
		openmode = 0x00;
	}
	else if( mode == (O_WRONLY | O_CREAT | O_TRUNC) )	/*  "w"   */
	{
		openmode = 0x01;
	}
	else if( mode == (O_WRONLY | O_CREAT | O_APPEND) )	/*  "a"   */
	{
		openmode = 0x02;
	}
	else if( mode == O_RDWR )							/*  "r+"  */
	{
		openmode = 0x03;
	}
	else if( mode == (O_RDWR | O_CREAT | O_TRUNC) )		/*  "w+"  */
	{
		openmode = 0x04;
	}
	else if( mode == (O_RDWR | O_CREAT | O_APPEND) )	/*  "a+"  */
	{
		openmode = 0x05;
	}
	else												/* 対象外 */
	{	
		return -1;
	}

    rcode=fileopen( name, openmode, &fileno );
    if( rcode==0 )						/* オープン処理成功。             */
    {
        flmod[fileno] = mode;         	/* モードを設定。              	  */
		if( fileno == 0 )
		{
			flmod[fileno] = O_RDONLY;
		}
        return fileno;              	/* ファイル番号を返却。        	  */
    }
    else                           		/* オープン処理失敗。          	  */
    {
        return -1;             			/* エラー。					  	  */
    }
}

/**************************************************************************/
/*   close:File close                                                     */
/*     Return value: 0 (pass)                                             */
/*                  -1 (Failure)                                          */
/**************************************************************************/
close(int fileno)						/* ファイル番号					  */
{
    char rcode = 0;                  	/* fclose()の戻り値     	      */

	/* ファイル番号をチェックし、fileclose()でファイルをクローズする。	  */

	/* 最小ファイル番号、最大ファイル番号チェック。						  */
	if( (fileno < FLMIN) || (IOSTREAM <= fileno) )				
	{
		return -1;						/* エラー。						  */
	}
	else
	{
		if( flmod[fileno] != 0 )		/* ファイルのオープンチェック。	  */
		{
			rcode = fileclose( fileno );
	        if( rcode == 0 )           	/* クローズ処理成功。	          */
	        {   
	            flmod[fileno] = 0;   	/* ファイルモードのリセット。	  */
	            return 0;
	        }
	        else                    	/* クローズ処理失敗。	          */
	        {
	            return -1;				/* エラー。						  */
	        }		
		}
		else							/* オープンされていない。	 	  */
		{
			return -1;					/* エラー。				   		  */

		}
	}
}

/**************************************************************************/
/* read:Data read                                                         */
/*  Return value:Number of read characters (Pass)                         */
/*               -1                        (Failure)                      */
/**************************************************************************/
read(int  fileno,						/* ファイル番号     			  */
     char *buf,							/* 転送先バッファアドレス 		  */
     int  count)						/* 読み込む文字数          		  */
{
      unsigned int i;					/* カウント用変数			  	  */
      char         rcode   = 0;     	/* fcharget()の戻り値          	  */
	  char*		   tmppt   = NULL;		/* 先頭アドレスの保持		  	  */
	  int		   datanum = 0;			/* 読み込んだデータ数		  	  */

    /* ファイルのモードをチェックし、一文字づつ読み込みバッファに格納。	  */

    /* 読み込み専用 or 読み込み書き出し両用にオープンされているか判定。   */
    if(flmod[fileno]&O_RDONLY||flmod[fileno]&O_RDWR)
    {
        /* ファイル番号を比較。                         				  */
        /* 標準入力(stdin)の時 		⇒ charget()をコール。  			  */
		/* 標準出力(stdout・stderr)	⇒ エラーを返却。					  */
        /* それ以外            		⇒ fcharget()をコール。				  */

        if( fileno == STDIN )			/* 標準入力                       */
        {
            for(i=count; i>0; --i)
            {
                *buf = charget();
                  if( *buf == CR )      /* 改行文字の置き換え。           */
                    *buf=LF;
                  buf++;
            }
			return count;				/* 読み込んだ文字数返却。		  */
        } 
        else if( (fileno == STDOUT) ||
			 	 (fileno == STDERR) )	/* 標準出力						  */
		{
			return -1;
        }
        else                            /* ファイル入力                   */
        {
			tmppt = buf;				/* 先頭アドレスの保持。			  */
		    for( i=count; i>0; --i )
            {
                rcode = fcharget( buf, fileno );
                if( rcode == 0 )        /* 処理成功                       */
                {
                    if( *buf == CR )    /* 改行文字の置き換え。           */
                    {
						*buf = LF;
					}
					datanum++;			/* 取得文字数のインクリメント。	  */
					buf++;				/* 出力先ポインタのインクリメント。*/
                }
                else                    /* EOF検出(-1)                    */
                {
					break;				/* 処理終了						  */
                }
            }
			buf = tmppt;				/* 先頭アドレスの設定。			  */
        }
		return datanum;					/* 読み込んだ文字数返却。		  */
    }
    else
    {
        return -1;                      /* エラー。                       */
    }
}

/**************************************************************************/
/* write:Data write                                                       */
/*  Return value:Number of write characters (Pass)                        */
/*               -1                         (Failure)                     */
/**************************************************************************/
write(int  fileno,						/* ファイル番号					  */
      char *buf,						/* 転送先バッファアドレス		  */
      int  count)						/* 書き出し文字数          		  */
{
    unsigned int	i;					/* カウント用変数 				  */ 
    char 			c;					/* 出力文字 	  				  */
    char  			rcode   = 0;		/* fcaharget()戻り値			  */
	int		   		datanum = 0;		/* 書き出したデータ数		  	  */

    /* ファイルのモードをチェックし、一文字づつ出力。			  		  */

    /* 書き出し専用 or 読み込み書き出し両用にオープンされているか判定。	  */
    if(flmod[fileno]&O_WRONLY || flmod[fileno]&O_RDWR)
    {
        /* ファイル番号を比較。                             			  */
        /* 標準出力(stdout・stderr)の時	⇒ charput()をコール。      	  */
		/* 標準入力(stdin)の時			⇒ エラーを返却。				  */
		/* それ以外             		⇒ fcharput()をコール。     	  */

		if( fileno == STDIN )			/* 標準入力                       */
		{
			return -1;
		}
        else if( (fileno == STDOUT) ||
				 (fileno == STDERR) )   /* 標準出力     				  */
        {
            for( i = count; i > 0; --i )
            {
                c = *buf++;
                charput(c);
            }
	        return count;				/* 書き出した文字数返却。		  */
        }
        else                            /* ファイル出力 				  */
        {
            for( i = count; i > 0; --i )
            {
                c = *buf++;
                rcode = fcharput( c, fileno );
                if( rcode != 0 )        /* 処理失敗     				  */
                {
                    return -1;
                }
				datanum++;				/* 出力文字数のインクリメント。	  */
            }
			return datanum;				/* 書き出した文字数返却。		  */
        }
    }
    else
	{
        return -1;                      /* エラー                         */
	}
}

/**************************************************************************/
/* lseek:Definition of file read/write position                           */
/*  Return value:Offset from the top of file read/whrte position(Pass)    */
/*               -1              (Failure)                                */
/*  (lseek is not supported in the console input/output)                  */
/**************************************************************************/
long lseek(int  fileno,					/* ファイル番号					  */
           long offset,					/* 読み込み/書き出し位置		  */
           int  base)					/* オフセットの起点				  */
{
	char	rcode      = 0;				/* fpseek()の戻り値				  */
	long 	new_offset = 0;				/* 新しいオフセット値			  */				

    /* ファイル番号を比較。                             			  	  */
    /* 標準入出力(stdin・stdout・stderr)の時	⇒ エラーを返却。      	  	  */
	/* ファイルの時							⇒ fpseek()をコール。		  */
	/*		fpseek() 成功 ⇒ fptell()により、新しいオフセット値の取得。	  */
	/*			取得したオフセット値 < 0	⇒ エラーを返却。			  */
	/*			それ以外					⇒ オフセット値返却。		  */
	/*		fpseek() 失敗 ⇒ エラーを返却。								  */

	if( (fileno == STDIN)  ||
	    (fileno == STDOUT) ||
		(fileno == STDERR) )			/* 標準入出力の場合 			  */ 
	{
    	return -1;						/* エラー。						  */
	}
	else								/* 標準入出力以外 				  */
	{
		rcode = fpseek( fileno, offset, base );
		if( rcode == 0 ) 				/* ポインタ移動処理成功 		  */
		{
			/* fptell()で新しいオフセット値の取得。						  */
			rcode = fptell( fileno,	&new_offset );	
			if( rcode == 0 )			/* オフセット取得成功			  */
			{
				if( new_offset < 0 )	/* オフセット値判定。			  */
				{
					return -1;			/* エラー。						  */
				}
				else
				{
					return new_offset;	/* 新しいオフセットの返却。		  */
				}
			}
			else
			{
				return -1;				/* エラー。						  */
			}
		}
		else							/* ポインタ移動処理失敗。		  */
		{
			return -1;					/* エラー。		    			  */
		}
	}
}

/****************************************************************************/
/* _INIT_IOLIB                                                              */
/*  Initialize C library Functions, if necessary.                           */
/*  Define USES_SIMIO on Assembler Option.                                  */
/****************************************************************************/
void _INIT_IOLIB(void)
{
FILE *fp;

    for( fp = _iob; fp < _iob + _nfiles; fp++ )	/* ファイル型データの初期設定           */
     {
        fp->_bufptr = NULL;                     /* バッファへのポインタ                 */
        fp->_bufcnt = 0;                        /* バッファカウント                     */
        fp->_buflen = 0;                        /* バッファ長            				*/
        fp->_bufbase = NULL;                    /* バッファへのベースポインタ           */
        fp->_ioflag1 = 0;                       /* I/Oフラグ                            */
        fp->_ioflag2 = 0;                       /* I/Oフラグ                            */
        fp->_iofd = 0;                          /* ファイル番号                         */
     }

	// 標準入出力用ファイルをオープン。
	// "stdin"・"stdout"・"stderr"は、ファイルが存在しなくても自動生成されます。
	// "stdin"は、実際は"r"でオープンしなくてはならないが、
	// 自動生成するために"w"でオープンした後I/Oフラグに"r"を設定しています。
   if(freopen( "stdin",  "r", stdin )==NULL)	/* 標準入力ファイルをオープン。         */
        stdin->_ioflag1 = 0xff;                 				/* オープン失敗時のアクセス禁止。       */
	stdin->_ioflag1  = _IOREAD;									/* "r"でオープンしたことにします。		*/
    stdin->_ioflag1 |= _IOUNBUF;                				/* データのバッファリングなしに設定。   */
    if(freopen( "stdout", "w", stdout )==NULL) /* 標準出力ファイルをオープン。         */
        stdout->_ioflag1 = 0xff;                				/* オープン失敗時のアクセス禁止。       */
    stdout->_ioflag1 |= _IOUNBUF;               				/* オープンのバッファリングなしに設定。 */
    if(freopen( "stderr", "w", stderr )==NULL) /* 標準エラーファイルをオープン。       */
        stderr->_ioflag1 = 0xff;                				/* オープン失敗時のアクセス禁止。       */
    stderr->_ioflag1 |= _IOUNBUF;         
}

/****************************************************************************/
/* _CLOSEALL                                                                */
/****************************************************************************/

void _CLOSEALL(void)
{
int i;

    for( i=0; i < _nfiles; i++ )
	{
		/* ファイルがオープンしているかチェック。	*/
        if( _iob[i]._ioflag1 & (_IOREAD | _IOWRITE | _IORW ) )
			/* ファイルをクローズする。				*/ 
            fclose( & _iob[i] );
	}
}

