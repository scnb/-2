// ����5-8.cpp : �������̨Ӧ�ó������ڵ㡣
//Unix is ����
/* ����������n�Լ�n���ļ���������������ȵķ�ʽ����������
 * �ٶ���ļ�����M���ַ�������������M���ַ��������ж���M+2�ַ���
 */

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

vector<string> file;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int M = 0;
	int len = 0;
	string temp;
	ifstream fin("input.txt");
	/* �����ļ����� */
	cin >> n;
	/* �����ļ��������������ļ������� */
	while (getline(fin,temp))
	{
		len = temp.length();
		if (len > M)
		{
			M = len;
		}
		file.push_back(temp);
	}
	/* ���ļ����������� */
	sort(file.begin(), file.end());

	/* ���ļ���������䣬ʹ���һ����M���ַ�����������M+2���ַ� */
	for (int i = 0;i < n;i++)
	{
		/* �����Ҫ����λ�� */
		int add = M - file[i].length();
		if ((i + 1) % 5 == 0)
		{
			for (int k = 0;k < add;k++)
			{
				file[i] += ' ';
			}
		}
		else
		{
			add += 2;
			for (int k = 0;k < add;k++)
			{ 
				file[i] += ' ';
			}
		}
	}

	/* 1�����5���ļ��� */
	int cnt = 5;
	int row;
	if (n%cnt == 0)
	{
		row = n / cnt;
	}
	else
	{
		row = n / cnt + 1;
	}
	int base = 5;
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{	
		if (n - i*cnt < cnt)
		{
			cnt = n - i*cnt;
		}
		for (j = 0; j < cnt; j++)
		{
			printf("%s", file[i * base + j].c_str());
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

