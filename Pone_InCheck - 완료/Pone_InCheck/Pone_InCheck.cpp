#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>



#define delay(n) Sleep(n)

using namespace std;



class Twice

{

public:

	Twice(const char * name, const char * age, const char * blood)

		: T_name(name), T_age(age), T_blood(blood) { }			//생성할때 모든정보를 저장합니다.



	~Twice()												//포인터 값 초기화 및 할당시 free시켜줍니다.

	{

		T_name = nullptr;

		T_age = nullptr;

		T_blood = nullptr;



		delete T_name;

		delete T_age;

		delete T_blood;

	}



	void Info() const										//출력만 하는 함수라 const 붙혔습니다.

	{														//정보를 출력해 줍니다.

		cout << T_name << " ,  " << T_age << " ,  " << T_blood << endl;

		cout << "출근 : " << "(" << m_nPower << ")    " << endl;



		cout << endl;

	}



	void SetPower() { m_nPower = !m_nPower; }				//power를 반대로 만들어 주는 함수입니다.
														// m파워 = ! m파워(이걸 판대로 만들어 준다.)
														// false 였으니깐 트루로 바꿔 준다.





private:

	bool m_nPower = false;									//기본으로 OFF되어있고 true는 ON입니다.

	const char * T_name = nullptr;

	const char * T_blood = nullptr;

	const char * T_age = nullptr;



};



int main()

{
	int ck;
	int ck2;
	Twice TT("사나", "20살", "AB형");				//아이폰 짱짱 아이폰 쓰세여
													// 아이폰과 안드로이드의 장단점을 비교하고 간단하게 서술하세요.

	Twice TT1("다현", "20살", "B형");

	TT.Info();
	TT1.Info();

	TT.SetPower();
	TT1.SetPower();

	cout << "사나가 먼저 출근 체크를 한다. " << endl;
	cout << "출근 체크는 1번(카드체크), 다른번호는 누르지 마세요" << endl;
ck1:
	cin >> ck;
	if (ck == 1)
	{
		TT.Info();
	}
	else
	{
		cout << "삐빕~! 출근 카드에 오류 정보가 있습니다. 다시 시도해 주십시오";
		goto ck1;
	}

	cout << "다현이도 출근 체크를 한다. " << endl;
ck2:
	cin >> ck2;
	if (ck2 == 1)
	{
		TT1.Info();
	}
	else
	{
		cout << "삐빕~! 출근 카드에 오류 정보가 있습니다. 다시 시도해 주십시오";
		goto ck2;
	}

	delay(1500);

	cout << "모두 츨근 완료~~~~ 짝짝짝짝" << endl;

	getchar();												//화이팅

	return 0;

}

