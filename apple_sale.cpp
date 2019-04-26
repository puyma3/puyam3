// apple.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

class apple_sale //사과 판매 클래스
{
public:
	// 멤버 변수
	void Apple_house(); // 사과 가게 (멤버 변수들이 담기는 곳)


	// 멤버 함수
	void Money_counter(); // 가격 계산,사과개수 계산 (멤버 함수들이 담기는 곳)
	void print(); // cout 출력 하는곳 print1,2,3,..() 로 늘려 갈 것임 (1은 대화, 2는 함수계산등)
};



// 위는 헤더 파일에 넣을 것들

int main()
{
	
}

void apple_sale::Apple_house()
{
	int Red_Apple;            // 빨간사과
	int Green_Apple;          // 풋사과

	int Red_Apple_Much = 600;   // 가격
	int Green_Apple_Much = 500; // 가격

	int Red_Apple_Total = 30;   // 빨간사과 보유량
	int Green_Apple_Total = 50; // 풋사과 보유량



}

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




//===================================================================================== 나중에 나눌꺼임
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
