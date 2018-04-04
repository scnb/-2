// ϰ��3-6.cpp : �������̨Ӧ�ó������ڵ㡣
//
/* ��һ��bug����input1.txt�е�������������ʱ����Ϊ����Ǹ�*�ŵ����ã�������һ�����С�
 *
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize (10)

char crosswords[maxSize][maxSize];

void Across(char input[maxSize][maxSize], int r, int c);
void Down(char input[maxSize][maxSize], int r, int c);

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fin;
	fin = fopen("input1.txt", "rb");
	int r, c;
	char temp;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fscanf(fin, "%c", &temp);
			crosswords[i][j] = temp;
		}
	}
	Across(crosswords, r, c);
	Down(crosswords, r, c);
	system("pause");
	return 0;
}

/* ������к���ĵ��� */
void Across(char input[maxSize][maxSize], int r, int c)
{
	int flag = 0;
	printf("Acorss\n");
	for (int i = 0; i < r; i++)
	{
		flag = 0;
		printf("   ");
		for (int j = 0; j < c; j++)
		{
			int k = j;
			while (k < c && input[i][k] != '*')
			{
				printf("%c", input[i][k]);
				k++;
				flag = 1;
			}
			j = k;
			if (j != c && flag == 1)
			{
				printf("\n   ");
			}
		}
		printf("\n");
	}
}



void Down(char input[maxSize][maxSize], int r, int c)
{
	int flag = 0;
	printf("Down\n   ");
	for (int i = 0; i < r; i++)
	{
		/*if (flag == 1)
		{
			printf("   ");
		}*/
		for (int j = 0; j < c; j++)
		{
			flag = 0;
			if (i == 0 || input[i - 1][j] == '*')
			{
				int k = i;
				while (k < r && input[k][j] != '*')
				{
					printf("%c", input[k][j]);
					k++;
					flag = 1;
				}
			}
			if (flag == 1)
			{
				printf("\n   ");
			}
		}
	}
}