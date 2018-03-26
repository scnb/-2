// ����3-5_���ϵĺ��㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (100005)

int ans[MAXN];

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	int n;
	/* ͨ��memset������ans���鸳��ֵΪ0 */
	memset(ans, 0, sizeof(ans));
	for (int m = 1; m < MAXN; m++)
	{
		int original_number = m;
		int sum = m;
		/* ͨ��ѭ������m�����λ�ϵ�����֮�� */
		while (original_number > 0)
		{
			sum += original_number % 10;
			original_number = original_number / 10;
		}
		/* ��������Ԫ�ػ�û�д�����ݣ����ߵ�ǰ���������Ԫ����С�ģ���ô�ͱ��������Ԫ */
		if (ans[sum] == 0 || m < ans[sum])
		{
			ans[sum] = m;
		}
	}

	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	system("pause");
	return 0;
}

