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
#define KETA_DEFAULT (8)    /* �p�X���[�h�f�t�H���g���� */
/* �p�X���[�h�Ƃ��Ďg�p�\�ȕ����͈ȉ��̒ʂ�            */
/* 0x21�`0x7E�F�����A�p���啶���A���p�L��                */
#define PASSCHAR_MIN (0x21) /* �p�X���[�h���e�����ŏ��l */
#define PASSCHAR_MAX (0x7E) /* �p�X���[�h���e�����ő�l */

/* �v���g�^�C�v */
char GetPassChar();
char GetPassCharAlphabet();

/* �又�� */
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

    srand((unsigned)time(NULL)); /* ���������� */

    printf("�p�X���[�h�͂���\n");
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
    printf("\n");/* �p�X���[�h�o�͍s�̉��s */
    printf("--------------------\n");

    return 0;
}


/* �p�X���[�h�����o�� */
char GetPassChar()
{
    int tmp = 0;

    while(1)
    {
        tmp = rand() % 128; /* ASCII�R�[�h�𐶐� */

        if( PASSCHAR_MIN <= tmp && tmp <= PASSCHAR_MAX )
        {
            return (char)tmp;
        }
    }

}

/* �p�X���[�h�����o�� */
char GetPassCharAlphabet()
{
    int tmp = 0;

    while(1)
    {
        tmp = rand() % 128; /* ASCII�R�[�h�𐶐� */

        if(    (0x30 <= tmp && tmp <= 0x39)  /* �����@�@ */
			|| (0x41 <= tmp && tmp <= 0x5A)  /* �p�啶�� */
			|| (0x61 <= tmp && tmp <= 0x7A)  /* �p������ */
          )
        {
            return (char)tmp;
        }
    }

}
