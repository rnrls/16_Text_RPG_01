#include "Character.h"

#include <iostream>
#include <algorithm>

using namespace std;

/*
Character* Character::instance = nullptr;

Character* Character::getInstance(const string& inputName) {
    if (instance == nullptr) {
        string name = inputName;

        while (name.empty() || all_of(name.begin(), name.end(), [](char c) { return isspace(c); })) {
            cout << "이름이 빈칸입니다. 다시 입력하세요: ";
            getline(cin, name);
        }

        instance = new Character();
        instance->name = name;
        instance->level = 1;
        instance->maxHelth = 200;
        instance->helth = 200;
        instance->attack = 30;
        instance->exp = 0;
        instance->gold = 0;

        cout << "캐릭터 " << name << " 생성 완료! "
             << "레벨: " << instance->level
             << ", 체력: " << instance->helth
             << ", 공격력: " << instance->attack << endl;
    }

    return instance;
}

void Character::displayStatus() {
	cout << "===== 캐릭터 상태 =====" << endl;
	cout << "이름: " << name << endl;
	cout << "레벨: " << level << endl;
	cout << "체력: " << helth << "/" << MaxHelth << endl;
	cout << "공격력: " << attack << endl;
	cout << "경험치: " << exp << "/100" << endl;
	cout << "골드: " << gold << endl;
	cout << "========================";
}

void Character::levelUp() {
	if (Level >= 10) return;

	level++;
	maxHelth += level * 20;
	attack += level * 5;
	helth = maxHelth;

	cout << "[레벨업!]" << endl;
	cout << "레벨: " << level << endl;
	cout << "체력: " << helth << endl;
	cout << "공격력: " << attack << endl;
}
*/

