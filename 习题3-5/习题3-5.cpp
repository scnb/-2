// ϰ��3-5.cpp : �������̨Ӧ�ó������ڵ㡣
//����(Puzzle)
/* ������֮ǰ������һ��PAT�Ҽ���Ŀ�ǳ����������Ŀ�У���û����ȷ˵�����ֲ����᲻�ᳬ����Χ��������Ĭ��
 * �����������ǲ��ᳬ����Χ�ģ�Ҳ��û���жϱ߽�������
*/

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW (5)
#define COL (5)
#define maxSize (10)

char table[ROW][COL];
char order[maxSize];

struct Empty
{
	int x = 0;	/* �� */
	int y = 0;  /* �� */
};

Empty empty;

void Display(char output[ROW][COL]);
void UP_op(char output[ROW][COL]);
void DOWN_op(char output[ROW][COL]);
void LEFT_op(char output[ROW][COL]);
void RIGHT_op(char output[ROW][COL]);

int _tmain(int argc, _TCHAR* argv[])
{
	
	FILE *fin;

	/* Ϊ�������㣬���ļ��ж����������� */
	fin = fopen("input.txt", "rb");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			int temp;
			fscanf(fin, "%c", &temp);
			table[i][j] = temp;
			if (table[i][j] == '+')
			{
				empty.x = i;
				empty.y = j;
			}
		}
	}
	printf("%d %d\n", empty.x, empty.y);
	/* ����ָ�����У�������0���� */
	scanf("%s", order);
	int len = strlen(order) - 1;
	/* ָʾ�Ƿ��д����ָ�� */
	int bug = 0;
	for (int i = 0; i < len; i++)
	{
		switch (order[i])
		{
		case 'A':UP_op(table); break;
		case 'B':DOWN_op(table); break;
		case 'L':LEFT_op(table); break;
		case 'R':RIGHT_op(table); break;
		default: bug = 1; break;
		};
	}
	if (bug == 1)
	{
		printf("This puzzle has no final configuration!\n");
	}
	else
	{
		Display(table);
	}
	system("pause");
	return 0;
}

void Display(char output[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%c ", output[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void UP_op(char output[ROW][COL])
{
	char temp = output[empty.x][empty.y];
	output[empty.x][empty.y] = output[empty.x - 1][empty.y];
	output[empty.x - 1][empty.y] = temp;
	empty.x -= 1;
}

void DOWN_op(char output[ROW][COL])
{
	char temp = output[empty.x][empty.y];
	output[empty.x][empty.y] = output[empty.x + 1][empty.y];
	output[empty.x + 1][empty.y] = temp;
	empty.x += 1;
}

void LEFT_op(char output[ROW][COL])
{
	char temp = output[empty.x][empty.y];
	output[empty.x][empty.y] = output[empty.x][empty.y - 1];
	output[empty.x][empty.y - 1] = temp;
	empty.y -= 1;
}
void RIGHT_op(char output[ROW][COL])
{
	char temp = output[empty.x][empty.y];
	output[empty.x][empty.y] = output[empty.x][empty.y + 1];
	output[empty.x][empty.y + 1] = temp;
	empty.y += 1;
}