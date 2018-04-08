// ����5-7.cpp : �������̨Ӧ�ó������ڵ㡣
//����(Ugly number)��������ָ���ܱ�2,3,5�����������������������
/* ������Ҫ�������ȶ��е�ʹ�ã����ȶ��У����ӵ�Ԫ�ز��Ƕ��׵�Ԫ�أ��������ȼ���ߵ�Ԫ�أ�
 * Ĭ�ϣ�Խ���Ԫ�����ȼ�Խ��������Ҳ����ͨ���ڶ���ʱָ������ʹԽС��Ԫ�����ȼ�Խ�ߡ�
 * ˼·����x�ǳ�������2x��3x��5xҲ���ǳ��������Կ���ͨ����С�ĳ���1���������еĳ�����
 * ÿ�δ����ȶ�����ȡ����С������Ȼ��ֱ����3��ϵ�����жϲ��ظ����ٴ������ȶ����У�
 * �ظ���һ����ֱ����1500��ѭ����
 * ����˼·�ܸ�Ч������ڴ�1����ѭ�����ж�ÿ�����ǲ��ǳ�����
*/

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
#include <functional>

using namespace std;

typedef long long LL;
/* ϵ������ */
const int coeff[3] = { 2, 3, 5 };


int _tmain(int argc, _TCHAR* argv[])
{
	/* ����ȽϺ���greater��ָ��Ԫ��С�����ȼ��� */
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> s;
	pq.push(1);
	s.insert(1);
	for (int i = 1;; i++)
	{
		LL x = pq.top();
		pq.pop();
		if (i == 1500)
		{
			cout << "The 1500'th ugly number is :" << x << endl;
		}
		for (int j = 0; j < 3; j++)
		{
			LL x2 = x*coeff[j];
			/* ���x2�ǲ����ظ����� */
			if (!s.count(x2))
			{
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	system("pause");
	return 0;
}

