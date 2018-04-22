// ����6-10.cpp : �������̨Ӧ�ó������ڵ㡣
//�������Ҷ��The falling leaves������һ�ö�������ÿһ���ڵ㶼��һ��ˮƽλ�ã����ӽڵ�
//�������1����λ�����ֽڵ������ұ�һ����λ�������������ÿ��ˮƽλ�õ����нڵ��Ȩֵ֮��

#include "stdafx.h"
#include <iostream>

using namespace std;

/* ���������鿪�Ĵ�һ�㣬 ��ֹ���ر���б */
const int maxn = 100;

int sum[maxn];

void build(int p)
{
	int v;
	cin >> v;
	if (v == -1)
	{
		return;
	}
	sum[p] += v;	//pλ��������һ��ֵ
	build(p - 1);	//�ȴ�����������������һ��
	build(p + 1);	//�ٴ�����������������һ��
}

bool init()
{
	int v;
	cin >> v;
	if (v == -1)
	{
		return false;
	}
	/* һ��Ҫ��һ������ǰ��0������ᵼ�µ�һ�������Ժ��ͳ�Ƴ������� */
	memset(sum, 0, sizeof(sum));
	int pos = maxn / 2;
	sum[pos] = v;			//��������
	build(pos - 1);
	build(pos + 1);
	/* ������return true��������벻ͨ�� */
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int kase = 0;
	while (init())
	{
		int p = 0;
		while (sum[p] == 0)
		{
			p++;
		}
		cout << "Case " << ++kase << ":\n" << sum[p];
		while (sum[++p] != 0)
		{
			cout << " " << sum[p];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

