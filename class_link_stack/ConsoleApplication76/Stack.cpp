#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include "Stack.h"
using namespace std;

Stack::Stack()
{ //������
	head = new Node(); //���̳��
	count = 0;
}

Stack::~Stack()
{ //�Ҹ���
	while (count != 0)
	{
		pop();
	}
	delete head;
}

void Stack::pop() // ������ ����
{
	Node *tmp = head;
	head = head->next;
	delete tmp;
	count--;
}


void Stack::push(int i) //������ ����
{
	new Node(i, head);
	count++;
}

void Stack::printAll() //��� ���
{
	Node *cur = head;
	while (cur->next) {
		cur = cur->next;
		cout << cur->data << endl;

	}

}