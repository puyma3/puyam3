#pragma once

#include"Node.h"
class Stack
{
public:
	Node *head;
	int count;

	Stack();
	~Stack();

	void pop();
	void push(int i);
	void printAll();


};