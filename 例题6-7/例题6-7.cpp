// ����6-7.cpp : �������̨Ӧ�ó������ڵ㡣
//�������Ĳ�α�����Trees on the level��
//����һ�ö������������ϵ��£������ҵ�˳�������������ֵ��
//ÿ����㰴�մӸ��ڵ㵽�����ƶ����и������磺(5,LL)��ʾ���ý���ֵ��5���Ӹ�����������󵽴�ý�㡣
//�������У�ÿ��������������֮��û�пո����ڽ��֮����һ���ո������
//ÿ������������һ������"()"������

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

#define maxn (256)

char s[maxn];

/* ���ṹ�� */
struct Node
{
	bool have_value;	//��¼�Ƿ񱻸�ֵ��
	int v;
	Node *left, *right;
	Node() :have_value(false), left(NULL), right(NULL) {}	//���캯��
};

Node *root;				//�����
bool failed = false;	//����������Ƿ��д���Ľ����Ϣ

/* �����½�� */
Node *newnode()
{
	return new Node();
}

/* �ڶ���������ӽ�� */
void addnode(int v, char *s)
{
	int len = strlen(s);
	Node *u = root;
	/* �����ƶ������ҵ��ý���λ�� */
	for (int i = 0; i < len; i++)
	{
		/* ������ */
		if (s[i] == 'L')
		{
			/* �������������ڣ��򴴽��������ĸ���� */
			if (u->left == NULL)
			{
				u->left = newnode();
			}
			u = u->left;
		}
		else if (s[i] == 'R')
		{
			/* �������������ڣ��򴴽��������ĸ���� */
			if (u->right == NULL)
			{
				u->right = newnode();
			}
			u = u->right;
		}
	}
	/* ����Ƿ��ظ���ֵ */
	if (u->have_value == true)
	{
		failed = true;
	}
	u->v = v;
	/* ��Ǹý���ѱ�����ֵ */
	u->have_value = true;

}

/* ����������ĸ������ */
bool read_input()
{
	failed = false;
	root = newnode();
	FILE *fin = fopen("input.txt", "rb");
	for (;;)
	{
		if (fscanf(fin, "%s", s) != 1)
		{
			return false;
		}
		if (!strcmp(s, "()"))
		{
			break;
		}
		int v;
		/* s[1]��һ���ַ�������s�ַ����е��±�Ϊ1���ַ���ʼ����'\0'���� */
		sscanf(&s[1], "%d", &v);
		/* strchr()��������s�ַ����е�һ��','�ַ���ָ�� */
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}

/* ʹ�ÿ�����ȱ������Զ��������в�α��� */
bool BFS(vector<int>& ans)		//vector����������Ľ��ֵ
{
	/* ����һ�����������в�α��� */
	queue<Node *>q;
	ans.clear();
	q.push(root);
	while (!q.empty())
	{
		Node *u = q.front();
		q.pop();
		if (!u->have_value)
		{
			return false;
		}
		ans.push_back(u->v);
		/* ����ǰ��������������Ϊ�գ�������� */
		if (u->left != NULL)
		{
			q.push(u->left);
		}
		if (u->right != NULL)
		{
			q.push(u->right);
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ans;
	/* ��������н����Ϣ�����⣬�����-1 */
	read_input();
	if (failed)
	{
		cout << -1 << endl;
		system("pause");
		return 0;
	}
	BFS(ans);
	int size = ans.size();

	for (int i = 0; i < size; i++)
	{
		cout << ans[i] << " ";
	}
	system("pause");
	return 0;
}

