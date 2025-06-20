#pragma once

#include "Item.h"

#include <string>
#include <vector>


class Character {
public:

	Character(const std::string& Name);
	static Character& Getinstance();
		void DisplayStatus();
		void LevelUp();
		void UseItem(int index);
	
private:
	static Character instance;
	Character();
	std::string Name;
	int Level;
	int MaxHelth;
	int Helth;
	int Attack;
	int Exp;
	int Gold;
	std::vector<Item>inventory;
};