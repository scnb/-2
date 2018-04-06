// ����5-3.cpp : �������̨Ӧ�ó������ڵ㡣
//���ϵĵ�һ���ֵ䣺����һ���ı��������ҳ����в�ͬ�ĵ��ʣ������ִ�Сд���������ֵ����С��������
/*
 * ����ֻҪ������˵��set�����ϣ����÷�
 */

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

/* ����һ�����ϣ������е�ÿ��Ԫ����һ��string */
set<string> dict;


int _tmain(int argc, _TCHAR* argv[])
{
	string s, buf;
	while (cin >> s)
	{
		/* һ��ֻ����һ���ַ��� */
		for (int i = 0; i < s.length(); i++)
		{
			/* ���ַ�����ת����Сд��ĸ�����Ҳ��ǰѷ���ĸ���ַ���ɿո� */
			/* isalpha���������ж��ǲ�����ĸ */
			if (isalpha(s[i]))
			{
				s[i] = tolower(s[i]);
			}
			else
			{
				s[i] = ' ';
			}
		}
	 	stringstream ss(s);
		/* ���ַ������뵽buf�� */
		while (ss >> buf)
		{
			dict.insert(buf);
		}
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}

