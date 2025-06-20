#include "Monster.h"

using namespace std;

Monster1::Monster1(int level) : name("name"), health(1 * level), attack(1 * level) {} // 이름과 수치는 상의 후 결정

string Monster1::getName() { return name; }
int Monster1::getHealth() { return health; }
int Monster1::getAttack() { return attack; }
void Monster1::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

Monster2::Monster2(int level) : name("name"), health(1 * level), attack(1 * level) {}

string Monster2::getName() { return name; }
int Monster2::getHealth() { return health; }
int Monster2::getAttack() { return attack; }
void Monster2::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

Monster3::Monster3(int level) : name("name"), health(1 * level), attack(1 * level) {}

string Monster3::getName() { return name; }
int Monster3::getHealth() { return health; }
int Monster3::getAttack() { return attack; }
void Monster3::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

Monster4::Monster4(int level) : name("name"), health(1 * level), attack(1 * level) {}

string Monster4::getName() { return name; }
int Monster4::getHealth() { return health; }
int Monster4::getAttack() { return attack; }
void Monster4::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

Monster5::Monster5(int level) : name("name"), health(1 * level), attack(1 * level) {}

string Monster5::getName() { return name; }
int Monster5::getHealth() { return health; }
int Monster5::getAttack() { return attack; }
void Monster5::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}