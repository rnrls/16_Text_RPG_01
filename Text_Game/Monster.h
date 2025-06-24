#pragma once
#include<iostream>
#include<string>
#include <cstdlib>

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
	virtual int getAttack()
	{
		int damage_variance = (rand() % 11);
		int final_damage = attack + damage_variance;

		return final_damage;
	}
	virtual void takeDamage(int damage)
	{
		health -= damage;
		if (health < 0)
		{
			health = 0;
		}
	}
	virtual bool isDead() const { return health <= 0; }

	virtual ~Monster() {}
};

// Àú·¾ 
class Goblin : public Monster
{
public:
	Goblin(int level);
};

class Wereworf : public Monster
{
public:
	Wereworf(int level);
};

class Lizardeman : public Monster
{
public:
	Lizardeman(int level);
};

class Harpy : public Monster
{
public:
	Harpy(int level);
};

// °í·¾ 
class Irongorem : public Monster
{
public:
	Irongorem(int level);
};

class Lich : public Monster
{
public:
	Lich(int level);
};

class Griffon : public Monster
{
public:
	Griffon(int level);
};

class Nightmare : public Monster
{
public:
	Nightmare(int level);
};

