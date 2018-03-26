// ����3-5.cpp : �������̨Ӧ�ó������ڵ㡣
//�������Ԫ
/*����Ԫ��һ�����������ϣ��ĸ���λ�ϵ����ֵõ����֣���������֣������֣�������Ԫ��
 *���磺y = 216, ��x = 198����216��һ������Ԫ
 *����һ������n������������С����Ԫ����������������0.
*/

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int get_single_sum(int i);

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int flag;
	while (scanf("%d", &n) == 1)
	{
		flag = 0;
		for (int i = 0; i < n; i++)
		{
			int single_sum = get_single_sum(i);
			if (i + single_sum == n)
			{
				printf("%d\n", i);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("%d\n", 0);
		}
	}
	return 0;
}

int get_single_sum(int i)
{
	int ret = 0;
	while (i > 0)
	{
		ret += i % 10;
		i = i / 10;
	}
	return ret;
}