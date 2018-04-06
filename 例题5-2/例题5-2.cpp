// ����5-2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

const int maxn = 30;
int n;

/* ����һ�����飬�������е�ÿһ��Ԫ������һ��vector */
/* ����pile���Կ���һ����ά���飬����һά�Ĵ�С�ǹ̶��ģ�����ά�Ĵ�С�ǿɱ�� */
vector<int> pile[maxn];

/* �ҵ�ľ��a���ڵĶѣ����ҵ�ľ��a�ڸö��еĸ߶ȣ��������õ���ʽ���� */
void find_block(int a, int &p, int &h)
{
	for (p = 0; p < n; p++)
	{
		for (h = 0; h < pile[p].size(); h++)
		{
			if (pile[p][h] == a)
			{
				return;
			}
		}
	}
}

/* �ѵ�p�Ѹ߶�Ϊh��ľ���Ϸ�������ľ�鶼�ƻ�ԭλ */
void clear_above(int p, int h)
{
	for (int i = h+1; i < pile[p].size(); i++)
	{
		int temp = pile[p][i];
		/* �����Ϊtemp��ľ���ƻص���temp�� */
		pile[temp].push_back(temp);
	}
	/* ����resize������ʹ��p��ֻ���е�0-��h-1����ľ�� */
	pile[p].resize(h+1);
}

/* �ѵ�p�Ѹ߶�Ϊh�����Ϸ���ľ�鶼�����ƶ���p2���Ϸ� */
void pile_above(int p, int h, int p2)
{
	for (int i = h; i < pile[p].size(); i++)
	{
		pile[p2].push_back(pile[p][i]);
	}
	/* ����resize������ʹ��p��ֻ���е�0 - ��h-2����ľ�� */
	pile[p].resize(h);
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int h = 0; h < pile[i].size(); h++)
		{
			printf("%d ", pile[i][h]);
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a, b;			//�洢���ĸ�ľ��
	cin >> n;			//һ����n��ľ��
	string s1, s2;		//����
	for (int i = 0; i < n; i++)
	{
		pile[i].push_back(i);
	}
	/* ʹ��cin�ܷܺ���Ķ�ȡ��������Զ������ݺ��ַ����ֿ� */
	while (cin >> s1 >> a >> s2 >> b)
	{
		int p1, h1, p2, h2;
		find_block(a, p1, h1);
		find_block(b, p2, h2);
		if (p1 == p2)
		{
			printf("Wrong Command!\n");
			exit(-1);
		}
		/* ����onto�����Ҫ��bľ�������ľ�鶼�õ� */
		if (s2 == "onto")
		{
			clear_above(p2, h2);
		}
		/* ����move�����Ҫ��aľ�������ľ�鶼�õ� */
		if (s1 == "move")
		{
			clear_above(p1, h1);
		}
		/* ʣ�¾��ǰ�ľ��a���������ľ��(�����ѱ�����)������bľ�����ڶѵĶ���(����ֻʣbľ��) */
		pile_above(p1, h1, p2);
		print();
	}
	
	return 0;
}

