// ϰ��3-4.cpp : �������̨Ӧ�ó������ڵ㡣
//���ڴ�(Periodic Strings)

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxSize (80)
char input[maxSize];

int _tmain(int argc, _TCHAR* argv[])
{
	scanf("%s", input);
	int len = strlen(input);
	/* k������¼��С���� */
	int k = 1;
	for (int i = 1; i < len; i++)
	{
		if (input[i] != input[i - k])
		{
			if (k + 1 < i + 1)
			{
				k = i;
			}
			else
			{
				k++;
			}
		}
	}
	printf("the minum period is: %d\n", k);
	system("pause");
	return 0;
}

