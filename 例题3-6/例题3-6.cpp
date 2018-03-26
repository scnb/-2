// ����3-6.cpp : �������̨Ӧ�ó������ڵ㡣
//��״���У�
/* ����Ϊn�Ļ�״����n�б�ʾ�����������ֵ�����С�ĳ�Ϊ����С��ʾ��
 * �ֵ��򣺶��������ַ������ӵ�һ���ַ���ʼ�Ƚϣ���ĳһλ�õ��ַ���ͬʱ����λ���ַ���С�Ĵ����ֵ����С��
 * ����һ����״DNA���У��������С��ʾ��
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (105)

char str[MAXN];

int Is_less(const char *s, int p, int q);

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	int ans = 0;	//��С�������
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", str);
		ans = 0;
		int len = strlen(str);
		for (int i = 1; i < len; i++)
		{
			if (Is_less(str, i, ans))
			{
				ans = i;
			}
		}

		for (int i = ans; i < ans + len; i++)
		{
			printf("%c", str[i%len]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

/* p����ǰ�ַ�������ʼλ�ã�q������С������ʼλ�� */
int Is_less(const char *s, int p, int q)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[(p + i)%len] != s[(q + i)%len])
		{
			return s[(p+i)%len] < s[(q+i)%len];
		}
	}
}