// ����6-6.cpp : �������̨Ӧ�ó������ڵ㡣
//С�����䣨Dropping Balls������һ�ö�������������ΪD��������Ҷ����ȶ���ͬ�������������������ڵ���Ϊ1�����������š�
//ÿ���ڽڵ��϶���һ�����أ���ʼȫ���رգ���ÿ����һ��С���䵽һ��������ʱ��״̬����ı䡣��С�򵽴�һ���ڽڵ��ʱ��
//����ýڵ�ʱ�أ��������ߣ����������ߣ�֪���ߵ�Ҷ�ӽڵ㡣

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int D, I;
	while (scanf("%d %d", &D, &I) == 2)
	{
		int Size = pow(2, D);
		int pos = 1;
		int *tree = new int[Size];
		memset(tree, 0, Size*sizeof(int));
		for (int i = 0; i < I;i++)
		{
			pos = 1;
			while (pos * 2 < Size)
			{
				/* 0����رգ���С������������ */
				if (tree[pos] == 0)
				{
					tree[pos] = !tree[pos];
					pos = pos * 2;
				}
				/* ����С������������ */
				else
				{
					tree[pos] = !tree[pos];
					pos = pos * 2 + 1;
				}
			}
		}
		cout << pos << endl;
	}
	return 0;
}

