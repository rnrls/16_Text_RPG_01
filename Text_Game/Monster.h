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
	//isDead() Ãß°¡
	virtual bool isDead() const { return health <= 0; }

	virtual ~Monster() {}
};

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


