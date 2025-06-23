#include "Character.h"

#include <iostream>
#include <algorithm>

using namespace std;

Character::Character(const string& Name)
	: Name(Name), Level(1), MaxHelth(200), Helth(200),
	Attack(30), Exp(0), Gold(0) 
{
	cout <<  Name << " 생성 완료! " << endl;
	cout << "레벨: " << Level << endl;
	cout << "체력: " << Helth << endl;
	cout << "공격력: " << Attack << endl;
}

void Character::DisplayStatus() {
	cout << "===== 캐릭터 상태 =====" << endl;
	cout << "이름: " << Name << endl;
	cout << "레벨: " << Level << endl;
	cout << "체력: " << Helth << "/" << MaxHelth << endl;
	cout << "공격력: " << Attack << endl;
	cout << "경험치: " << Exp << "/100" << endl;
	cout << "골드: " << Gold << endl;
	cout << "========================";
}

void Character::LevelUp() {
	if (Level >= 10) return;

	Level++;
	MaxHelth += Level * 20;
	Attack += Level * 5;
	Helth = MaxHelth;

	cout << "[레벨업!]" << endl;
	cout << "레벨: " << Level << endl;
	cout << "체력: " << Helth << endl;
	cout << "공격력: " << Attack << endl;
}
//테스트

