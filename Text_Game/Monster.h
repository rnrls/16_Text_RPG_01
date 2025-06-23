#pragma once
#include<iostream>
#include<string>

class Monster
{
protected:
	std::string name;
	int health;
	int attack;

	Monster(std::string n, int h, int a) : name(n), health(h), attack(a) {}

public:
	virtual std::string getName() { return name; }
	virtual int getHealth() { return health; }
	virtual int getAttack() { return attack; }
	virtual void takeDamage(int damage)
	{
		health -= damage;
		if (health < 0)
		{
			health = 0;
		}
	}
	
	virtual ~Monster() {}
};

class Irongorem : public Monster
{
	Irongorem(int lavel);
};

class Lich : public Monster
{
	Lich(int lavel);
};

class Griffon : public Monster
{
	Griffon(int lavel);
};

class Nightmare : public Monster
{
	Nightmare(int lavel);
};


