// ����3-1.cpp : �������̨Ӧ�ó������ڵ㡣
//�滻�ı��е�����

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fin;
	fin = fopen("input.txt", "rb");
	int c;
	int q = 1;
	while ((c = fgetc(fin)) != EOF)
	{
		if (c == '"')
		{
			printf("%s", q ? "��" : "��");
			q = !q;								//q��Ϊһ����־��������ָʾ�����������Ż���������
		}
		else
		{
			printf("%c", c);
		}
	}
	getchar();
	return 0;
}

