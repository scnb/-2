// ����3-3_���Ϻõ��㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE (30)

char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char *msg[] = { "not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome" };

char mirrored_char(char ch)
{
	if (!isalpha(ch))
	{
		return rev[ch - '0' + 25];
	}
	else
	{
		return rev[ch - 'A'];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	/* ʹ��scanf�����ַ���Ҫ�����s��Ҫ��ǰָ����С������ʹ�� char *s�ǲ��Ե� */
	char s[BUFFER_SIZE];
	/* ʹ��scanf��һ���ô��ǣ�û���ַ�����β\r\n�ַ��ķ��� */
	while ((scanf("%s", s) == 1))
	{
		int len = strlen(s);
		/* ����������־���ֱ��ʾ�ǻ��Ĵ����Ǿ��� */
		int p = 1, m = 1;
		for (int i = 0; i < (len + 1) / 2; i++)
		{
			if (s[i] != s[len - i - 1])
			{
				/*�����ǻ��Ĵ���*/
				p = 0;
			}
			if (mirrored_char(s[i]) != s[len - i - 1])
			{
				/*�����Ǿ��񴮡�*/
				m = 0;
			}
		}
		/* �����������ǳ��򵥣�ֻҪһ����������������������Ϣ */
		printf("%s -- %s.\n", s, msg[m * 2 + p]);
	}
	getchar();
	return 0;
}

