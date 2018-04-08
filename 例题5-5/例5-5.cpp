// ��5-5.cpp : �������̨Ӧ�ó������ڵ㡣
//����ջ�����������������е��ԣ����������ܿ�����ֻ���õ�����Ԫ���е㲻�����������ϵļ���
//������Ҫ����ջ��ʹ��
//���´��������ϵĴ���

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set, int>IDcache;			//���ݼ���ȡ����ID
vector<Set> Setcache;			//����ID�ļ���ȡ���ü���


/* ���Ҹ������ϵ�ID�� ���Ҳ����������һ����ID */
int ID(Set x)
{
	if (IDcache.count(x))
	{
		return IDcache[x];
	}
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/* ջ��ߴ���Ǽ��ϵ�ID */
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string op;
		cin >> op;
		if (op[0] == 'P')
		{
			s.push(ID(Set()));
		}
		else if (op[0] == 'D')
		{
			s.push(s.top());
		}
		else
		{
			/* ���²����Ĺ�ͬ���Ƕ�Ҫ�ȳ�ջ����ջ��Ԫ�� */
			Set x1 = Setcache[s.top()];
			s.pop();
			Set x2 = Setcache[s.top()];
			s.pop();
			Set x;
			/* Union����ջ�������ϣ����䲢����ջ */
			if (op[0] == 'U')
			{
				set_union(ALL(x1), ALL(x2), INS(x));
			}
			/* Insersection����ջ�������ϣ����佻����ջ */
			else if (op[0] == 'I')
			{
				set_intersection(ALL(x1), ALL(x2), INS(x));
			}
			/* Add����ջ�������ϣ����ȳ�ջ�ļ��ϼ��뵽���ջ�ļ����� */
			else if (op[0] == 'A')
			{
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}
	return 0;
}

