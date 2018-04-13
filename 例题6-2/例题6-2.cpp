// ����6-2.cpp : �������̨Ӧ�ó������ڵ㡣
//���죨Rails������n�ڳ����A����ʻ�복վ������վ˳����1-n���ж��ܷ������ǰ���ĳ���ض���˳�����B����ĳ�վ��
/*	������ص���Ǹ��ݳ�ջ��˳�����ж��Ƿ���������ջ��
 *  �����ݽṹ��������Щ���ƣ� ������һ����վ�����У� ��һ����Щ��ջ˳����ȷ��
 *  �����ջ˳��5 4 1 2 3�� ��1����ط������˴�����5��4�ȳ�ջ����˵��֮ǰ1 2 3һ���Ѿ���վ
 *  ��1��ջ�ף�����1���Բ�����4֮���ջ��
*/


#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

#define maxSize (1000+10)

int n, target[maxSize];

int _tmain(int argc, _TCHAR* argv[])
{
	while (scanf("%d", &n) == 1)
	{
		stack<int> s;
		/* B����ָ��ǰ���ĸ���ջԪ�أ� A������¼��Ԫ��֮ǰ����ȷ��ջ˳�� */
		int A = 1, B = 1;
		/* �����ջ��˳�� */
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &target[i]);
		}
		int ok = 1;
		/* ����whileѭ����˼·�ǳ�ţ�������ж�һ����ջԪ��֮ǰ�Ľ�վ˳�� */
		while (B <= n)
		{
			if (A == target[B])
			{
				A++;
				B++;
			}
			else if (!s.empty() && s.top() == target[B])
			{
				s.pop();
				B++;
			}
			else if (A <= n)
			{
				s.push(A++);
			}
			else
			{
				ok = 0;
				break;
			}
		}
		printf("%s\n", ok ? "yes" : "no");
	}
	system("pause");
	return 0;
}

