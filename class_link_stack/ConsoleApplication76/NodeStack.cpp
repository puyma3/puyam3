

// 링크드 리스크와 스택 조합

// ConsoleApplication75.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include "Node.h"
#include "Stack.h"
using namespace std;

int main()
{
	Stack *stack = new Stack();
	stack->push(1);
	stack->push(3);
	stack->push(5);
	stack->push(7);
	stack->push(9);
	stack->printAll();
	delete stack;
}
