// ����6-9_���ϵ��㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//������Ϊ���ϵ��㷨��˼·���ҵ��㷨��һ���ģ������õݹ��������Ĺ������ж������Ƿ�ƽ�⡣
//�������ϵ��㷨�ڴ���return true�������úܺá�
//���⣬��if�жϲ���Ҳ����ࡣ

#include "stdafx.h"
#include <iostream>

using namespace std;

bool solve(int &w)
{
	int wl, dl, wr, dr;
	bool a = true, b = true;
	cin >> wl >> dl >> wr >> dr;
	if (!wl)
	{
		a = solve(wl);
	}
	if (!wr)
	{
		b = solve(wr);
	}
	w = wl + wr;
	return a && b && (wl*dl == wr*dr);
}

int main()
{
	int w = 0;
	if (solve(w))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
    return 0;
}

