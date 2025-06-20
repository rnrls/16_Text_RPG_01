#pragma once

#include "Item.h"

#include <string>
#include <vector>

using namespace std;

class Character {
public:

private:
	string Name;
	int Level;
	int MaxHp;
	int CurrentHp;
	int Attack;
	int Exp;
	int Gold;
	vector<Item>inventory;

};