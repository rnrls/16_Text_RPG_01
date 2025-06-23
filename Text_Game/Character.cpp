#include "Character.h"

#include <iostream>
#include <algorithm>

using namespace std;


Character* Character::instance = nullptr;


Character::Character(const string& Name)
	: Name(Name), Level(1), MaxHelth(200), Helth(200),
	Attack(30), Exp(0), Gold(0) 
{
	cout <<  Name << " 생성 완료! " << endl;
	cout << "레벨: " << Level << endl;
	cout << "체력: " << Helth << endl;
	cout << "공격력: " << Attack << endl;
}


Character* Character::GetInstance(const string& name) 
{
	if (!instance)
		instance = new Character(name);
	return instance;
}

void Character::DisplayStatus() 
{
	cout << "===== 캐릭터 상태 =====" << endl;
	cout << "이름: " << Name << endl;
	cout << "레벨: " << Level << endl;
	cout << "체력: " << Helth << "/" << MaxHelth << endl;
	cout << "공격력: " << Attack << endl;
	cout << "경험치: " << Exp << "/100" << endl;
	cout << "골드: " << Gold << endl;
	cout << "========================";
}

void Character::LevelUp() 
{
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

void Character::UseItem(int Index) 
{
	if (Index < 0 || Index >= Inventory.size()) {
		cout << "잘못된 인덱스입니다." << endl;
		return;
	}
	Inventory[Index]->use(this);
	delete Inventory[Index];
	Inventory.erase(Inventory.begin() + Index);
}

void Character::AddItem(Item* NewItem) 
{
	Inventory.push_back(NewItem);
}

void Character::Heal(int Amount) 
{
	Helth = min(Helth + Amount, MaxHelth);
}

void Character::AddAttack(int amount) {
	Attack += amount;
}

int Character::GetGold() const 
{
	return Gold;
}

void Character::AddGold(int Amount) 
{
	Gold += Amount;
}

bool Character::SpendGold(int Amount) 
{
	if (Gold >= Amount) {
		Gold -= Amount;
		return true;
	}
	return false;
}

int Character::GetMaxHelth() const 
{
	return MaxHelth;
}

const vector<Item*>& Character::GetInventory() const 
{
	return Inventory;
}

bool Character::isDead() const {
	return Helth <= 0;
}