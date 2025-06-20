#pragma once

#include<iostream>
#include<string>

using namespace std;

class Monster
{
public:
	virtual string getName() = 0;
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual void takeDamage(int damage) = 0;
	virtual ~Monster() {}
};

class Monster1 : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Monster1(int level);
	string getName() override;
	int getHealth() override;
	int getAttack() override;
	void takeDamage(int damage) override;
};

class Monster2 : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Monster2(int level);
	string getName() override;
	int getHealth() override;
	int getAttack() override;
	void takeDamage(int damage) override;
};

class Monster3 : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Monster3(int level);
	string getName() override;
	int getHealth() override;
	int getAttack() override;
	void takeDamage(int damage) override;
};

class Monster4 : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Monster4(int level);
	string getName() override;
	int getHealth() override;
	int getAttack() override;
	void takeDamage(int damage) override;
};
