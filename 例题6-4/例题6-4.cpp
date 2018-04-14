// ����6-4.cpp : �������̨Ӧ�ó������ڵ㡣
//����ļ��̣������ı�������һ������ļ��̣������ϵ����м�����������������������ʱHome������End�����Զ����¡�
//�������ڴ���ʾ���������������ı�֮ǰ��������ı��������������ʾ���Ͻ�����ʾʲô���ݣ�
/* �����ĺ��ľ��ǣ�Home�����ù���ƶ������ף���End��ʹ����ƶ�����β��������[��]֮����ı�������������ס�
 * �����������ʹ��������ʵ�֣���Ϊ�漰����Ƶ�������ı�֮������ƶ������Բ��������飬��Ϊ����Ч��̫�͡�
 * ����һ���ı�֮������ַ���ɨ�裬 �������ͨ�ַ�ֱ�Ӽӵ�����ĩβ������[�������֪��]֮ǰ���ı����ӵ������ײ�
 * �������֮��������ɡ�
*/

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

typedef struct node
{
	char c;
	struct node * next;
}Node;


int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	ifstream fin("input.txt");
	while (getline(fin, s))
	{
		int len = s.length();
		/* str��Ϊһ���ս�� */
		Node *str = (Node *)malloc(sizeof(Node));
		Node *end = str;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '[')
			{
				i++;
				Node *cur = (Node *)malloc(sizeof(Node));
				if (cur == NULL)
				{
					cout << "Allocation Error!" << endl;
					exit(0);
				}
				cur = str->next;
				if (s[i] != ']')
				{
					Node *temp = (Node *)malloc(sizeof(Node));
					if (temp == NULL)
					{
						cout << "Allocation Error!" << endl;
						exit(0);
					}
					temp->c = s[i];
					temp->next = str->next;
					str->next = temp;
					cur = temp;
					i++;
				}
				
				/* ֱ������]������������ͷ������ */
				while (s[i] != ']')
				{
					Node *temp = (Node *)malloc(sizeof(Node));
					if (temp == NULL)
					{
						cout << "Allocation Error!" << endl;
						exit(0);
					}
					temp->c = s[i];
					temp->next = cur->next;
					cur->next = temp;
					cur = temp;
					i++;
				}
			}
			/* ��ʵ���ڸ��ַ��Ĵ����Ѿ������������ */
			else if (s[i] == ']')
			{
			}
			else
			{
				Node *temp = (Node *)malloc(sizeof(Node));
				if (temp == NULL)
				{
					cout << "Allocation Error!" << endl;
					exit(0);
				}
				temp->c = s[i];
				temp->next = NULL;
				end->next = temp;
				end = temp;
			}
		}
		Node *start = str->next;
		for (start; start != NULL; start = start->next)
		{
			cout << start->c;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

