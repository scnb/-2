// ����6-5.cpp : �������̨Ӧ�ó������ڵ㡣
//�ƶ����ӣ�Boxes in Line������һ�к��ӣ�������һ�α��Ϊ1,2,3����n������ִ������4�����
//��1 X Y ��ʾ�Ѻ���X�ƶ�������Y����� ���Ѿ����������Ը����
//��2 X Y ��ʾ�Ѻ���X�ƶ�������Y���ұ� ���Ѿ����ұ�����Ը����
//��3 X Y ��ʾ��������X��Y��λ��
//��4     ��ʾ��ת����
/*	˼·��������˫������˳��洢����ʵ�֡���left[i]��right[i]�ֱ��ʾ���Ϊi�ĺ����������ߵĺ��ӱ��
 *  ���⣬��ת����Ĳ����ȼ�ռ��ʱ�䣬���Կ�����һ���������ʾ�Ƿ�ת����������inv=1ʱ����ʾ������ת
 *  ���ٴη�תinv=0���ֻص���ԭ����״̬��������ת��һ��ʱ��Ĳ�������������ִ�С�
 *  ������Ҫע����ǣ�������inv��ǣ�����Щ��������1��2����Ҫ����ע�⣬���緭ת֮������1����ʵ���Ͼ�Ҫ���������൱��
 *  ִ��2������ִ��2����Ҳ��ͬ�����ԣ���inv=1ʱ��op=3-op
*/

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>

#define maxSize (100000+10)

/* �ֱ��ʾ��i���������Һ��ӵı�� */
int left[maxSize];
int right[maxSize];

/* �������ڵ��໥���� */
void link(int L, int R)
{
	right[L] = R;
	left[R] = L;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int m, kase = 0;
	int n;
	/* n��ʾ���Ӹ�����m��ʾָ������� */
	while (scanf("%d %d", &n, &m) == 2)
	{
		/* �������໥���� */
		for (int i = 1; i <= n; i++)
		{
			left[i] = i - 1;
			right[i] = (i + 1) % (n + 1);
		}
		left[0] = n;
		right[0] = 1;
		int op, X, Y, inv = 0;
		while (m--)
		{
			scanf("%d", &op);
			if (op == 4)
			{
				/* ������ת */
				inv = !inv;
			}
			else
			{
				scanf("%d %d", &X, &Y);
				/* ����ת��������ò����Ѿ���ԭ���Ĳ������෴�� */
				if (op != 3 && inv)
				{
					op = 3 - op;
				}
				/* ������Ϊ1�� ��X�Ѿ���Y���ұ��ˣ������������� */
				if (op == 1 && left[Y] == X)
				{
					continue;
				}
				if (op == 2 && right[Y] == X)
				{
					continue;
				}

				int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
				if (op == 1)
				{
					link(LX, RX);
					link(LY, X);
					link(X, Y);
				}
				else if (op == 2)
				{
					link(LX, RX);
					link(Y, X);
					link(X, RY);
				}
				else if (op == 3)
				{
					if (right[X] == Y)
					{
						link(LX, Y);
						link(Y, X);
						link(X, RY);
					}
					else if (right[Y] == X)
					{
						link(LY, X);
						link(X, Y);
						link(Y, RX);
					}
					else
					{
						link(LX, Y);
						link(Y, RX);
						link(LY, X);
						link(X, RY);
					}
				}
			}
		}
		int b = 0;
		long long ans = 0;
		/* ��������λ���ϵĺ� */
		for (int i = 1; i <= n; i++)
		{
			b = right[b];
			if (i % 2 == 1)
			{
				ans += b;
			}
		}
		/* �������ת���ˣ� ������ż����Ԫ�أ� ��ans�����������ĺͼ�ȥans */
		if (inv && n % 2 == 0)
		{
			ans = (long long)n*(n + 1) / 2 - ans;
		}
		printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
}

