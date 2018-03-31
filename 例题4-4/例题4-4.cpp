// ����4-4.cpp : �������̨Ӧ�ó������ڵ㡣
//��Ϣ���룺�������ɿ�������ſ������Ƚϸ��ӣ�����ǿ��˴𰸲��е�о��ġ�

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readchar();
int readint(int c);

int code[8][1 << 8];	// 1<<8��ʾ2^8
int readcodes();

int _tmain(int argc, _TCHAR* argv[])
{
	/* ѭ��������� */
	while (readcodes())
	{
		for (;;)
		{
			/* ������ȡ�������������֣������С����ÿ������ĳ��� */
			int len = readint(3);
			/* �����볤��Ϊ0ʱ���˳����� */
			if (len == 0)
			{
				break;
			}
			for (;;)
			{
				int v = readint(len);
				/* (1<<len) - 1����˸�С�ڱ���Ľ�������
				 * ����len = 2�� ���������Ϊ��1<<2 = ������(100) = ʮ����(4)
				 * �� 4 - 1 = 3���õ����������� ������(011) = ʮ����(3)
				*/
				if (v == (1 << len) - 1)
				{
					break;
				}
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	system("pause");
	return 0;
}

int readchar()
{
	for (;;)
	{
		int ch = getchar();
		/* ��������ַ����ǻ��з�ʱ���򷵻ض�����ַ� */
		if (ch != '\n' && ch != '\r')
		{
			return ch;
		}
	}
}

int readint(int c)
{
	int v = 0;
	/* ��������c�����������֣���������ʮ����ֵ 
	 * ���磺c = 3������3������������010
	 * c = 3: v = 0 * 2 + 0 - 0 = 0
	 * c = 2: v = 0 * 2 + 1 - 0 = 1
	 * c = 1: v = 1 * 2 + 0 - 0 = 2
	*/
	while (c--)
	{
		v = v * 2 + readchar() - '0';
	}
	return v;
}

int readcodes()
{
	/* ��ÿһ�ֶ������֮ǰ����Ҫ��������� */
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for (int len = 2; len <= 7; len++)
	{
		for (int i = 0; i < (1 << len) - 1; i++)
		{
			int ch = getchar();
			/* ����û�и���ı��룬�򷵻�0���˳�whileѭ�� */
			if (ch == EOF)
			{
				return 0;
			}
			/* ���������ǻ��з�����������滹�����ݣ�����1��������ȡ���� */
			if (ch == '\n' || ch == '\r')
			{
				return 1;
			}
			code[len][i] = ch;
		}
	}
	return 1;
}