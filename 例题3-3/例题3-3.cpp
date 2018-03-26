// ����3-3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

char mirror[] = "A   3  HIL JM O   2TUVWX51SE Z  8 ";
#define  buffer_size (80)

int is_Palindromes(const char *s);
int is_Mirror(const char *s);

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fin;
	fin = fopen("input.txt", "rb");
	/* ����ʹ�� char *s;����û������s�Ĵ�С�Ļ���fgets�ᱨ�� */
	char s[buffer_size] = "";
	while (fgets(s, buffer_size, fin)!=NULL)
	{
		char temp[buffer_size] = "";
		/* �����ļ��е����һ��������Ҫ�ر�ע�⣬��Ϊ���к���û�� \r\n */
		if (s[strlen(s) - 1] == '\n' || s[strlen(s) - 1] == '\r')
		{
			strncpy(temp, s, strlen(s) - 2);
		}
		else
		{
			strncpy(temp, s, strlen(s));
		}
		if (is_Palindromes(temp))
		{
			if (is_Mirror(temp))
			{
				printf("%s -- is a mirrored palindrome\n", temp);
			}
			else
			{
				printf("%s -- is a regular palindrome\n", temp);
			}
		}
		else
		{
			if (is_Mirror(temp))
			{
				printf("%s -- is a mirrored string\n", temp);
			}
			else
			{
				printf("%s -- is not a palindrome\n", temp);
			}
		}
	}
	getchar();
	return 0;
}

/*���жϸ��ַ����ǲ��ǻ����ַ�����*/
int is_Palindromes(const char *s)
{
	/* ����string.h�е�strrev���� */
	char temp[buffer_size] = "";
	/* ����Ҫ����s����ʹ�����ݸı� */
	strcpy(temp, s);
	_strrev(temp);
	/* ����ʹ�� == ���ж��ַ����Ƿ���ȣ������ÿ⺯�� */
	if (!strcmp(temp, s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*���жϸ��ַ����ǲ��Ǿ����ַ�����*/
int is_Mirror(const char *s)
{
	char temp[buffer_size] = "";
	strcpy(temp, s);
	_strrev(temp);
	int len = strlen(temp);
	int middle_odd = len / 2;
	for (int i = 0; i < len; i++)
	{
		if (i == middle_odd && middle_odd % 2 == 1)
		{
			continue;
		}
		if (mirror[s[i] - 'A'] == temp[i] || mirror[temp[i] - '0' + 25] == s[i])
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}