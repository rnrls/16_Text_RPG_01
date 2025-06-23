/*#pragma once

#include "Item.h"

#include <string>
#include <vector>



class Character {
private:
	
	static Character* instance;

	std::string name;
	int level;
	int maxHelth;
	int helth;
	int attack;
	int exp;
	int gold;
	std::vector<Item>inventory;


public:

	static Character* getInstance(const std::string& name = "");

	void displayStatus();
	void levelUp();
	void useItem(int index);

};*/