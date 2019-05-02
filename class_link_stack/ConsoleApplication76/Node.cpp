#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include "Node.h"
using namespace std;



Node::Node() // 변수 초기화
{
	next = NULL;
	data = 0;
}

Node::Node(int i, Node* ptr)
{
	data = i;
	next = ptr->next;
	ptr->next = this;
}

Node::~Node()
{

}