// ����6-8.cpp : �������̨Ӧ�ó������ڵ㡣
//����Tree������һ�ý���Ȩ�Ķ�����������ͺ���������У���һ��Ҷ�ӽ��ʹ����������·���ϵ�Ȩ����С��
//����ж�⣬��Ҷ�ӱ����ȨֵӦ������С��
//������ÿ���б�ʾһ��������һ��Ϊ����������ڶ���Ϊ���������

/*	���õ����飬���Կ�������������ʾ���������������
*/

#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct BTNode
{
	int data;
	struct BTNode *left;
	struct BTNode *right;
}BTNode;

BTNode *root = new BTNode;


const int maxv = 1000 + 10;

/* �ֱ����������У� �������У���ǰ��������������㣬 ��ǰ��������������� */
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];

int n;

/* Ŀǰ�����Ž�Ͷ�Ӧ��Ȩֵ�� */
int best, best_sum;

/* �������� */
bool read_list(int *a)
{
	string line;
	if (!getline(cin, line))
	{
		return false;
	}
	stringstream ss(line);
	n = 0;
	int x;
	while (ss >> x)
	{
		a[n++] = x;
	}
	return x > 0;
}


/* ��������������кͺ���������й���һ���� */
int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1)
	{
		return 0;
	}
	/* ȡ�õ�ǰ���ĸ���� */
	int root = post_order[R2];
	int p = L1;
	while (in_order[p] != root)
	{
		p++;
	}
	/* ���㵱ǰ�����������Ľ����� */
	int cnt = p - L1;
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
	return root;
}

void DFS(int u, int sum)
{
	sum += u;
	/* ����ǰ��Ҷ�ӽ�� */
	if (!lch[u] && !rch[u])
	{
		/* ����ҪʹȨֵ����С����Ҫ����ʹҶ�ӽ���ȨֵҲҪС */
		if (sum < best_sum || (sum == best_sum && u < best))
		{
			best = u;
			best_sum = sum;
		}
	}
	if (lch[u])
	{
		DFS(lch[u], sum);
	}
	if (rch[u])
	{
		DFS(rch[u], sum);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	while (read_list(in_order))
	{
		read_list(post_order);
		build(0, n - 1, 0, n - 1);
		best_sum = 1000000;
		DFS(post_order[n - 1], 0);
		cout << "best = " << best << endl;
		cout << "best_sum = " << best_sum << endl;
	}
	system("pause");
	return 0;
}

