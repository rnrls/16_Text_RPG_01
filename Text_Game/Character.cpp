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
            cout << "�̸��� ��ĭ�Դϴ�. �ٽ� �Է��ϼ���: ";
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

        cout << "ĳ���� " << name << " ���� �Ϸ�! "
             << "����: " << instance->level
             << ", ü��: " << instance->helth
             << ", ���ݷ�: " << instance->attack << endl;
    }

    return instance;
}

void Character::displayStatus() {
	cout << "===== ĳ���� ���� =====" << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << level << endl;
	cout << "ü��: " << helth << "/" << MaxHelth << endl;
	cout << "���ݷ�: " << attack << endl;
	cout << "����ġ: " << exp << "/100" << endl;
	cout << "���: " << gold << endl;
	cout << "========================";
}

void Character::levelUp() {
	if (Level >= 10) return;

	level++;
	maxHelth += level * 20;
	attack += level * 5;
	helth = maxHelth;

	cout << "[������!]" << endl;
	cout << "����: " << level << endl;
	cout << "ü��: " << helth << endl;
	cout << "���ݷ�: " << attack << endl;
}
*/

