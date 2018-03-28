// ����4-2.cpp : �������̨Ӧ�ó������ڵ㡣
//��������Ϸ
/* ��Ϊ�������Ŀ��û�п���������ֱ�ӿ��Ĵ𰸣����ڸ��ݶԴ𰸵���⣬�Լ�ʵ��һ�顣
 */

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (256)

/* �ֱ�����ȷ�Ĵ𰸣��û��Ĳ²� */
char ans[MAXN], str[MAXN];

/* �ֱ����û���ʣ���λ��ᣬ��ʣ������ĸû�в¶� */
int chance, left;

/* �ֱ����û��¶ԺͲ´�ı�־λ */
int win = 0, lose = 0;

/* �ж��Ӻ������ж��û��²�ĸ���ĸ�Ƿ���ȷ */
void Guess(char ch);

int _tmain(int argc, _TCHAR* argv[])
{
	/* ��ǰ��Ϸ���� */
	int rnd = 0;
	while (((scanf("%d%s%s", &rnd, ans, str) == 3) && rnd != -1))
	{
		printf("Round %d\n", rnd);
		/* ÿ����Ϸ֮ǰ����Ҫ����chance��left���Լ�win��lose */
		chance = 7;
		left = strlen(ans);
		win = lose = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			Guess(str[i]);
			/* ����һ������λ�� ���˳� */
			if (win || lose)
			{
				break;
			}
		}
		if (win)
		{
			printf("You win\n");
		}
		else if (lose)
		{
			printf("You lose\n");
		}
		else
		{
			printf("You chickened out\n");
		}
	}
	return 0;
}

void Guess(char ch)
{
	int len = strlen(ans);
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (ch == ans[i])
		{
			/* ����Ҫ�µ���ĸ������һ */
			--left;
			ans[i] = ' ';
			flag = 1;
			break;
		}
	}
	if (flag = 1)
	{
		/* ֻ���ڲ´��ʱ��ʣ�����Ż��1 */
		--chance;
	}
	/* ��left��Ϊ0�������ȫ������ */
	if (!left)
	{
		win = 1;
	}
	/* �����õĻ����Ϊ0�� ������û����� */
	if (!chance)
	{
		lose = 1;
	}
}