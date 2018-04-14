// ����6-3.cpp : �������̨Ӧ�ó������ڵ㡣
//��������(Matrix Chain Multiplication)������n�������ά�Ⱥ�һЩ���˱��ʽ���ж��ܹ����г˷��� ����������˷�����Ĵ�����
/*	������Ҫ�Ĺ������ǽ������ʽ��������ջ����ɸò�����
 *  ע�⣺ǰ��������ı��ʽ��ʽ������ȷ�ġ�ֻ��Ҫ�жϽ��г˷���������������Ƿ������˼��ɡ�
 *  ɨ����ʽ��������ĸ����ջ��������������������ջ����Ԫ�ؽ������㣬���������ٴ���ջ�С�
*/

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum { A, B, C, D, E, F, G, H, I, J };

#define maxSize (10)

typedef struct matrix
{
	int row = 0;
	int col = 0;
}Matrix;

stack<Matrix> expr;

Matrix mat[maxSize];

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int r, c;
		/* ����þ����ά�� */
		scanf("%d %d", &r, &c);
		mat[A+i].row = r;
		mat[A+i].col = c;
	}
	/* �������˱��ʽ */
	string str;
	Matrix A, B;
	while (cin >> str)
	{
		int sum = 0;
		int flag = 0;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			if (isalpha(str[i]))
			{
				expr.push(mat[str[i]-'A']);
			}
			else if (str[i] == ')')
			{
				B = expr.top();
				expr.pop();
				A = expr.top();
				expr.pop();
				if (A.col == B.row)
				{
					Matrix temp;
					temp.row = A.row;
					temp.col = B.col;
					expr.push(temp);
					sum += A.row * A.col * B.col;
				}
				else
				{
					cout << "Error!\n";
					flag = 1;
					break;
				}
			}
		}
		if (flag != 1)
		{
			cout << "total multipication is:" << sum << endl;
		}
	}
	return 0;
}

