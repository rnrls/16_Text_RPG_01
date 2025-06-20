#pragma once

#include "Item.h"

#include <string>
#include <vector>

using namespace std;

class Character {
public:
	static Character& Getinstance() {
		return instance;
	}
private:
	static Character instance;
	Character();
	string Name;
	int Level;
	int MaxHelth;
	int Helth;
	int Attack;
	int Exp;
	int Gold;
	vector<Item>inventory;

};