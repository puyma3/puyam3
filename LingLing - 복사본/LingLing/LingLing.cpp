#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
#define delay(n) Sleep(n)

using namespace std;

typedef struct NODE {
	int data;
	struct NODE*next;
}node;

int main()
{
	
	//헤드(시작)노드 생성
	node*head = (node*)malloc(sizeof(node));
	head->next = NULL;

	node* node4 = (node*)malloc(sizeof(node));

	node4->data = 4;
	node4->next = head->next;
	head->next = node4;

	node* node3 = (node*)malloc(sizeof(node));
	node3->data = 3;
	node3->next = head->next;
	head->next = node3;

	node* node2 = (node*)malloc(sizeof(node));
	node2->data = 2;
	node2->next = head->next;
	head->next = node2;

	node* node1 = (node*)malloc(sizeof(node));
	node1->data = 1;
	node1->next = head->next;
	head->next = node1;

	cout << "달리기 대회 시작 ~ 하지만 이미 승부는 정해져 있다." << endl;
	

	node* curr = head->next;
	while (curr != NULL) {
		delay(1000);
		cout << curr->data << endl;
		curr = curr->next;
	}

	cout << "예상대로 1등이 부터 4등이 까지 순서대로 들어왔다." << endl;
	delay(1500);
	cout << "4등이가 1등을 하도록 바꿔 주자!!~ head->next = node4(4등이)" << endl << endl;

	
	
	head->next = NULL;

	

	
	node3->next = head->next;
	head->next = node3;

	
	node2->next = head->next;
	head->next = node2;

	
	node1->next = head->next;
	head->next = node1;

	
	node4->next = head->next;
	head->next = node4;

	node* currr = head->next;
	while (currr != NULL) {
		delay(1000);
		cout << currr->data << endl;
		currr = currr->next;
	}
	cout << endl;
	cout << "매일 4등만 하던 4등이가 1등을 하여 감격의 눈물을 흘렸다 ㅠ ㅠ " << endl;

	delay(1000);

	cout << "끝~~~~~~!!" << endl;








	// head > node2(20) > node1(10)
	// 0이 아닐때가지 반복 이니깐
	// head에는 NULL값이 보관되어 있어 종료


	free(head);
	free(node1);
	free(node2);
	free(node3);
	free(node4);


}