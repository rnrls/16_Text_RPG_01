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
	virtual int getAttack();
	virtual void takeDamage(int damage);
	virtual bool isDead() const;

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


//Áß°£
class Gargoyle : public Monster
{
public:
	Gargoyle(int level);
};

class Dryad : public Monster
{
public:
	Dryad(int level);
};

class Lich : public Monster
{
public:
	Lich(int level);
};

class Vampire : public Monster
{
public:
	Vampire(int level);
};



// °í·¾ 
class Irongorem : public Monster
{
public:
	Irongorem(int level);
};

class Manticore : public Monster
{
public:
	Manticore(int level);
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



class Boss :public Monster
{
public:
	Boss(int level);
};