#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "Torbo.c.h"
using namespace std;

class apple_sale //사과 판매 클래스
{
public:
	// 멤버 변수 (사과 판매점)
	int Apple_red, Apple_green; // 사과의 가격
	int Apple_Total_red, Apple_Total_green; // 사과의 총개수

	// 멤버 변수 (사과 사러 온사람)
	int Ryukeu, BaeSeol; // 사과 살 인간 2명
	int wallet; // 지갑 : 총 소지금액
	int bag; // 가방 : 총 사과 보유개수 (최대 수량 있음)
	int * apple_Selection; // 사과 뭐 선택할 껀지
	



	// 멤버 함수 (사과 판매점)

	apple_sale(); // 생성자
	apple_sale(int red, int green); // 인자가 있는 생성자
	apple_sale(int & apple_array);
	~apple_sale(); // 소멸자

	// 멤버 함수 
	int How_Much(); // 이 사과 몇개 주세요.
	

};

apple_sale::apple_sale(int red, int green)
{
	Apple_red = red;
	Apple_green = green;

}

apple_sale::apple_sale(int & apple_array)
{
	apple_Selection = new int(apple_array);
}

apple_sale::apple_sale()
{
	Apple_red = 0;
	Apple_green = 0;
}

apple_sale::~apple_sale()
{
	delete apple_Selection;
	apple_Selection = NULL;
}

int apple_sale::How_Much()
{
	int apple_Selection;
	int size;
	cout << "어서 오세요~ 어떤사과를 찾으시나요? (빨간사과= 1번, 풋사과 = 2번 을 선택하세요)" << "  ";

	cin >> apple_Selection;
	switch (apple_Selection)
	{
	case 1:
		cout << "빨간사과로 주세요." << endl;
		break;
	case 2:
		cout << "풋사과 주세요." << endl;
		break;
	default:
		cout << "저희집은 1,2번 선택지 밖에 없습니다. 다시 선택해 주세요 " << endl;
		return false;
		break;
		

	}
	
	cout << endl;
	delay(500);

	cout << "몇개나 필요 하세요?" << " " ;
	
	cin >> size;

	cout << endl << size << "개 주세요." << endl << endl;

	delay(500);


	
	int Apple_red = 100;
	int Apple_green = 200;

	switch(apple_Selection)
	{
	case 1:
		cout << "빨간 사과 100원 * " << size << "개= " <<  Apple_red * size << "원 입니다. " << endl;
		break;
	case 2:
		cout << "풋 사과 200원 * " << size << "개= " << Apple_green * size << "원 입니다. " << endl;
		break;
	return 0;
	}
}






/*

void apple_sale::Money_counter()
{
	// 손님이 낸돈 - (사과 개수 * 사과 가격) = 거스름돈;
	// bool로 거래가 성립하는지 판별 (돈이 모자르거나, 사과가 부족하거나 등등) 
	// 현재 사과 개수 : 총 사과 개수 - 판매한 사과 개수

}

void apple_sale::print()
{

	cout << "저희 가게는 빨간 사과와, 풋사과를 판매하고 있습니다요.";

}




//================================================================================= 나중에 나눌꺼임

// 밑에 부터는 사과를 사러오는 손님 클래스

class customer //손님 클래스
{
public:
	// 멤버 변수
	void Death_note_Ryukeu(); // 사신 류크 (인간세계의 사과를 좋아하는 류크. 사신계의 사과는 맛이 없다고 한다.)
	void BaegSeol_Princess(); // 백설공주 (왕비가 준 '독'(마약)사과를 맛보더니 사과의 맛에 빠져들었다고 한다.)



	// 멤버 함수
	void printt(); // 손님들이 할 법한 말을 출력할 것이다.
	void How_Much(); // 가격 계산,사과개수 계산 (멤버 함수들이 담기는 곳)
};

void customer::Death_note_Ryukeu()
{
	int Ryukeu_wallet; // 지갑 : 전체금액, 소비후 금액 등이 담길 변수
	int Ryukeu_Money = 10000; // 소지한 돈
	int Ryukeu_bag = 10; // 사과를 담을수 있는 가방 (최대 10개 까지 넣을수 있다.)
	int Ryukeu_Red_Apple = 0; // 사과 소지 개수
	int Ryukeu_Green_Apple = 0; // 사과 소지 개수


}

void customer::BaegSeol_Princess()
{
	int BaegSeol_wallet; // 지갑 : 전체금액, 소비후 금액 등이 담길 변수
	int BaegSeol_Money = 20000; // 소지한 돈
	int BaegSeol_bag = 20; // 사과를 담을수 있는 가방 (최대 20개 까지 넣을수 있다.)
	int BaegSeol_Red_Apple = 0; // 사과 소지 개수
	int BaegSeol_Green_Apple = 0; // 사과 소지 개수

}



void customer::printt()
{
	cout << "아저씨 이 사과 얼마에요?"; //손님에 따라 출력하는 말이 틀리도록 바꿀것이다.
}

void customer::How_Much()
{
	// 현재 가지고 있는 돈 - (사과개수 * 가격) = 거스름돈 얼마 받을지
	// bool로 거래가 성립하는지 판별 (돈이 모자르거나, 사과가 부족하거나, 가방 공간이 부족하거나 등등) 
	// 현재 사과 개수 : 현재 몇개 있는지 / 가방에 공간이 충분한지 등.
}


int main()
{

}

*/

int main()
{
	apple_sale pp;

	
	

	pp.How_Much();

	
	


}