//사과 수정중 2

// ConsoleApplication72.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include <windows.h>

using namespace std;

#define delay(n) Sleep(n)	





// 클래스 사과 


class Apple
{


public:
	
	int asize;
	// 멤버 변수
	string apple_name; //사과파는 인간 이름
	int apple_much; // 사과 가격
	int apple_max; // 사과 최대 개수

	// 멤버 함수

	int APPLE_PRINT(); // 장사맨 출력
	int APPLE_PRINT1(); // 맨트 출력
	int APPLE_PRINT2(); // 맨트 출력 2
	int APPLE_MUCH(); // 돈 계산



	// 생성자 소멸자
	Apple();
	Apple(const string & name, int much, int max);
	~Apple();

};

int Apple::APPLE_PRINT()
{
	cout << "(" << apple_name << ")" << endl;
	cout << "사과 보유량 = " << apple_max << "  ,  " << "사과 가격 = " << apple_much << endl << endl;

	return 0;

}

int Apple::APPLE_PRINT1()
{
	cout << endl;
	delay(2000);
	cout << "(" << apple_name << ") : " << "사과를 선택해 주세요 = 빨간사과: (1) , 풋사과: (2) " << " ";
	cout << endl << endl;
	return 0;
}

int Apple::APPLE_PRINT2()
{
	
	delay(2000);
	cout << "(" << apple_name << ") : " << "몇개 드릴까요?" << endl;

	return 0;
}

int Apple::APPLE_MUCH()
{
	// 참조 잘 안되서 일단 그냥 합니다. 하아...
	delay(2000);
	
	cout << "(" << apple_name << ") : " << "잔돈을 얼마 줘야 되지?... 내가 계산이 안되네" << endl << endl;

	return 0;
}




Apple::Apple()
{
	apple_much = 0;
	apple_max = 0;
}

Apple::Apple(const string & name, int much, int max)
{
	apple_name = name;
	apple_much = much;
	apple_max = max;
}

Apple::~Apple()
{

}

// =========================================================================================



class Person //사람
{
public:
	//멤버 변수
	string person_name; // 손님 이름
	int person_much; // 손님 소지돈
	int person_max; // 사과 최대 개수
	int asize;

	// 멤버함수

	int PERSON_PRINT(); // 사과 사먹는 사람1 출력
	int PERSON_PRINT1(Apple& a); // 사는 맨트 출력
	int PERSON_PRINT2(); // 사는 맨트 출력 (size 개 주세요)
	int PERSON_MUCH(); // 돈 계산
	int PERSON_MUCH1(); // 잔돈은 됬어요 아저씨!



	//생성자 소멸자
	Person();
	Person(const string & name, int much, int max);
	~Person();

};




int Person::PERSON_PRINT()
{
	cout << "(" << person_name << ")" << endl;
	cout << "소지 금액 = " << person_much << "  ,  " << "사과 가방 = " << person_max << endl;


	return 0;
}

int Person::PERSON_PRINT1(Apple& a)
{
	gogo:
	int size;
	cin >> size;
	delay(1000);
	if (size == 1)
		cout << "(" << person_name << ") : " << "빨간사과 주세요" << endl << endl;
	else if (size == 2)
		cout << "(" << person_name << ") : " << "풋사과 주세요" << endl << endl;
	else
	{
		cout << "(" << a.apple_name << ") : " << "잘못 선택 하셨습니다. 다시 선택하세요" << endl << endl;
		goto gogo;
	}
	return 0;

}

int Person::PERSON_PRINT2()
{
	int size;
	ddasi:
	cin >> size;
	asize = size;
	
	if (size <= 5)
	cout << "(" << person_name << ") : " << size << "개 주세요 " << endl << endl;

	else if (size > 5)
	{
		cout << "난 5천원 밖에 없는데... 6개 이상은 못사 다시 생각해보자 ";
	goto ddasi;
	}
		

	return 0;
}

int Person::PERSON_MUCH()
{
	delay(1000);
	cout << "(" << person_name << ") : "<< "\" "<< person_much << "원을 주인에게 건냈다. " << "\" " << endl
		<< endl;
	
	return 0;
}

int Person::PERSON_MUCH1()
{
	delay(2500);

	cout << "(" << person_name << ") : " << "\" 나 계산 못하는데 나한테 물어보네... 잠시 생각에 잠긴다. \""
		<< endl << endl;
	delay(2500);
	cout << "아저씨~ ! 잔돈은 됬습니다 하하하하... " << endl << endl << endl << endl;

	delay(2000);

	cout << "죄송합니다. 일단 완성부터 하려고 이렇게 만들었습니다." << endl << endl; 

	return 0;
}

Person::Person()
{
	person_much = 0;
	person_max = 0;
}

Person::Person(const string & name, int much, int max)
{
	person_name = name;
	person_much = much;
	person_max = max;

}

Person::~Person()
{

}



int main()
{
	Person ps("사과만 먹는 자연인", 5000, 0);
	Apple ap("사과쟁이", 1000, 30);

	ap.APPLE_PRINT(); // 장사맨 출력
	ps.PERSON_PRINT(); // 사과 사먹는 인간 1 출력

	ap.APPLE_PRINT1(); // 장사 맨트 출력
	ps.PERSON_PRINT1(ap); // 손님 멘트 출력

	ap.APPLE_PRINT2(); // 장사 멘트 출력 (몇개 줄까?)
	ps.PERSON_PRINT2(); // size개 주세요

	ps.PERSON_MUCH(); // 돈 내는거
	ap.APPLE_MUCH(); // 잔돈 주는거 

	ps.PERSON_MUCH1(); //잔돈은 됬습니다.

	return 0;
	



}
