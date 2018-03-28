// ����4-1.cpp : �������̨Ӧ�ó������ڵ㡣
//����������
/* ��������������ͬ�Ҳ�����100���ַ������ж��Ƿ��ܰ�����һ���ַ����ĸ�����ĸ���ţ�Ȼ���ÿ����ĸ����һһӳ�䣬ʹ�������ַ�����ͬ��
 * ˼·������������ֱ�ͳ�������ַ����и�����ĸ���ֵĴ�����
 *       Ȼ�󣬶��������������������������ͬ����˵��
 *       ����һ���ַ���һ���ܹ�ͨ�����Ų�ӳ�������һ�ַ�����ͬ��
 *
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAXN (100)

int cnt1[26] = { 0 };
int cnt2[26] = { 0 };

int cmp(const void * a, const void * b);

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[MAXN];
	char str2[MAXN];
	while (1)
	{
		int flag = 1;
		scanf("%s", str1);
		scanf("%s", str2);
		/* �����ַ���������ͬ */
		int len = strlen(str1);
		for (int i = 0; i < len; i++)
		{
			cnt1[str1[i] - 'A']++;
			cnt2[str2[i] - 'A']++;
		}
		qsort(cnt1, 26, sizeof(int), cmp);
		qsort(cnt2, 26, sizeof(int), cmp);
		
		for (int i = 0; i < 26; i++)
		{
			if (cnt1[i] != cnt2[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			printf("NO\n");
		}
		else 
		{
			printf("YES\n");
		}
	}
	system("pause");
	return 0;
}

int cmp(const void *a, const void *b)
{
	/* �ȶ�a��b����ǿ������ת�� */
	/*	a>b����������
	 *  a<b�����ظ���
	 *  a=b������0
	*/
	return *(int *)a - *(int *)b;
}