#pragma once
class Node
{
public:
	int data; // ���� ����
	Node* next; // ���� ����

	Node();
	Node(int i, Node* ptr);
	~Node();

};