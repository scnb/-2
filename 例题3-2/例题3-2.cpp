// ����3-2.cpp : �������̨Ӧ�ó������ڵ㡣
//�޸������������

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char key_table[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fin;
	fin = fopen("input.txt", "rb");
	int c;
	int i;
	while ((c = fgetc(fin)) != EOF)
	{
		if (c == '\n' || c == ' ')
		{
			printf("%c", c);
		}
		else
		{
			/* ͨ��ѭ�����ҵ����ַ��������е����� */
			for (i = 0; key_table[i] && c != key_table[i]; i++);
			/* �޸������ϵ�BUG����` Q A Z���ĸ�������λ�ã����������������ַ������λ���µ� */
			if (key_table[i] && i!=0 && i!=13 && i!=26 && i!=37)
			{
				printf("%c", key_table[i - 1]);
			}
			else
			{
				putchar(c);
			}
		}
	}
	getchar();
	return 0;
}

