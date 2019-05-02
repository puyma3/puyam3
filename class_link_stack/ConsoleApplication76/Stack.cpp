#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include "Stack.h"
using namespace std;

Stack::Stack()
{ //생성자
	head = new Node(); //더미노드
	count = 0;
}

Stack::~Stack()
{ //소멸자
	while (count != 0)
	{
		pop();
	}
	delete head;
}

void Stack::pop() // 데이터 제거
{
	Node *tmp = head;
	head = head->next;
	delete tmp;
	count--;
}


void Stack::push(int i) //데이터 삽입
{
	new Node(i, head);
	count++;
}

void Stack::printAll() //모두 출력
{
	Node *cur = head;
	while (cur->next) {
		cur = cur->next;
		cout << cur->data << endl;

	}

}