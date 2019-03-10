/*
 * MakePassWord.c
 *
 *  Created on: 2008/12/13
 *      Author: itsuka
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define KETA_DEFAULT (8)    /* パスワードデフォルト桁数 */
/* パスワードとして使用可能な文字は以下の通り            */
/* 0x21～0x7E：数字、英小大文字、半角記号                */
#define PASSCHAR_MIN (0x21) /* パスワード許容文字最小値 */
#define PASSCHAR_MAX (0x7E) /* パスワード許容文字最大値 */

/* プロトタイプ */
char GetPassChar();
char GetPassCharAlphabet();

/* 主処理 */
int main(int argc, char **argv)
{

    int keta         = 0;
    int cnt          = 0;
    int alphabet_flg = 0;

    if(argc >= 3)
    {
        if(memcmp(argv[1], "-a", 2)== 0)
        {
            alphabet_flg=1;
        }
        keta = atoi(argv[2]);
    }
    else if(argc == 2)
    {
        keta = atoi(argv[1]);
    }


    if(keta < KETA_DEFAULT)
    {
        keta = KETA_DEFAULT;
    }

    srand((unsigned)time(NULL)); /* 乱数初期化 */

    printf("パスワードはこれ\n");
    printf("--------------------\n");
    for(cnt = 0; cnt < keta; cnt++)
    {
        if(alphabet_flg == 1)
        {
            printf("%c", GetPassCharAlphabet());
        }else
        {
            printf("%c", GetPassChar());
        }
    }
    printf("\n");/* パスワード出力行の改行 */
    printf("--------------------\n");

    return 0;
}


/* パスワード文字出力 */
char GetPassChar()
{
    int tmp = 0;

    while(1)
    {
        tmp = rand() % 128; /* ASCIIコードを生成 */

        if( PASSCHAR_MIN <= tmp && tmp <= PASSCHAR_MAX )
        {
            return (char)tmp;
        }
    }

}

/* パスワード文字出力 */
char GetPassCharAlphabet()
{
    int tmp = 0;

    while(1)
    {
        tmp = rand() % 128; /* ASCIIコードを生成 */

        if(    (0x30 <= tmp && tmp <= 0x39)  /* 数字　　 */
			|| (0x41 <= tmp && tmp <= 0x5A)  /* 英大文字 */
			|| (0x61 <= tmp && tmp <= 0x7A)  /* 英小文字 */
          )
        {
            return (char)tmp;
        }
    }

}
