// ����5-6.cpp : �������̨Ӧ�ó������ڵ㡣
//�������(Team Queue)����t���Ŷӵ���������һ�����ӡ�ÿ������һ����ʱ����������������Ķ��ѣ�
//						�����������һ�����ѵĺ��棬���������ڶ��������档
//						����ÿ���Ŷ������ж�Ա�ı�ţ����ʹ��֧����������ָ�
//						��ENQUEUE x�����Ϊx���˽��볤��
//						��DEQUQUE�����ӵĶ��׳��ӣ�����������ӵ��˵ı��
//						��STOP��ֹͣģ��
/*
 *	˼·�����ڱ��⣬�����������У�
 *			��һ������ģ��������е����������һ����3���Ŷӣ��Ҷ��������Ŷӣ����������Ϊ��{3,1,2}��3��1��2�ֱ�Ϊ�Ӻ�
 *          ����һ�������а���t��С���У�ÿ��С���м�¼���Ŷ������������Ŷӵ��˵ı��
 */

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

/* ����Ŷ��� */
const int maxt = 1000 + 10;

int main()
{
	int t, round = 0;
	while (scanf("%d", &t) == 1 && t)
	{
		printf("Scenario #%d\n", ++round);
		/* ��map��¼�������˵��Ŷӱ��
		 * team[x]��ʾ���Ϊx�������ڵĶ�����
		 */
		map<int, int> team;
		for (int i = 0; i < t; i++)
		{
			int n, x; 
			scanf("%d", &n);
			while (n--)
			{
				scanf("%d", &x);
				team[x] = i;
			}
		}

		/* ģ�������� */
		queue<int> q, q2[maxt];
		for (;;)
		{
			int x;
			char cmd[10];
			/* ����ָ�� */
			scanf("%s", cmd);
			/* STOP��ֹͣģ�� */
			if (cmd[0] == 'S')
			{
				break;
			}
			/* DEQUEUE�����ӣ�����������˵ı�� */
			else if (cmd[0] == 'D')
			{
				if (q.size() == 0)
				{
					printf("Empty list!\n");
					continue;
				}
				/* ������ڶ�����ǰ���˵Ķ���� */
				int t = q.front();
				/* ��������˵ı�ţ��ٴӸö�����ɾ����ǰ����� */
				printf("%d\n", q2[t].front());
				q2[t].pop();
				/* ������˳��Ӻ󣬸ö����������Ŷӣ�������������ɾ���ö���� */
				if (q2[t].empty())
				{
					q.pop();
				}
			}
			/* ENQUEUE����� */
			else if (cmd[0] == 'E')
			{
				int x;
				/* ��������˵ı�� */
				scanf("%d", &x);
				/* �������˵Ķ���� */
				int t = team[x];
				/* ��֮ǰ���Ŷ���û�������Ŷӣ������������Ŷ��ˣ��Ѷ���żӵ���������� */
				if (q2[t].empty())
				{
					q.push(t);
				}
				/* ���������������ڵ��ŶӵĶ����� */
				q2[t].push(x);
			}
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

