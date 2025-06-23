#include "Character.h"

#include <iostream>
#include <algorithm>

using namespace std;

Character::Character(const string& Name)
	: Name(Name), Level(1), MaxHelth(200), Helth(200),
	Attack(30), Exp(0), Gold(0) 
{
	cout <<  Name << " ���� �Ϸ�! " << endl;
	cout << "����: " << Level << endl;
	cout << "ü��: " << Helth << endl;
	cout << "���ݷ�: " << Attack << endl;
}

void Character::DisplayStatus() {
	cout << "===== ĳ���� ���� =====" << endl;
	cout << "�̸�: " << Name << endl;
	cout << "����: " << Level << endl;
	cout << "ü��: " << Helth << "/" << MaxHelth << endl;
	cout << "���ݷ�: " << Attack << endl;
	cout << "����ġ: " << Exp << "/100" << endl;
	cout << "���: " << Gold << endl;
	cout << "========================";
}

void Character::LevelUp() {
	if (Level >= 10) return;

	Level++;
	MaxHelth += Level * 20;
	Attack += Level * 5;
	Helth = MaxHelth;

	cout << "[������!]" << endl;
	cout << "����: " << Level << endl;
	cout << "ü��: " << Helth << endl;
	cout << "���ݷ�: " << Attack << endl;
}
//�׽�Ʈ

