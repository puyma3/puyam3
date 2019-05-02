#pragma once
class Node
{
public:
	int data; // 변수 선언
	Node* next; // 변수 선언

	Node();
	Node(int i, Node* ptr);
	~Node();

};