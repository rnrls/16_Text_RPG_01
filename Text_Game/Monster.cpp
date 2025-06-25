#include "Monster.h"

using namespace std;

//저렙
Goblin::Goblin(int playerlevel) : Monster("고블린",  35 + (5 * playerlevel), 5 + (10 * playerlevel)) {}


Wereworf::Wereworf(int playerlevel) : Monster("웨어 울프", 45 + (5 * playerlevel), 10 + (10 * playerlevel)) {}


Lizardeman::Lizardeman(int playerlevel) : Monster("리자드맨",  60 + (5 * playerlevel), 15 + (10 * playerlevel)) {}


Harpy::Harpy(int playerlevel) : Monster("하피", 75 + (5 * playerlevel), 20 + (10 * playerlevel)) {}




//중간
Gargoyle::Gargoyle(int playerlevel) : Monster("가고일", 250 + (3 * playerlevel), 60 + (6 * playerlevel)) {}


Dryad::Dryad(int playerlevel) : Monster("드라이어드", 200 + (3 * playerlevel), 75 + (6 * playerlevel)) {}


Lich::Lich(int playerlevel) : Monster("리치", 180 + (3 * playerlevel), 85 + (6 * playerlevel)) {}


Vampire::Vampire(int playerlevel) : Monster("뱀파이어", 220 + (3 * playerlevel), 65 + (6 * playerlevel)) {}






//고렙
Irongorem::Irongorem(int playerlevel) : Monster("아이언 골렘",  650 + (2 * playerlevel), 90 + (4 * playerlevel)) {}


Griffon::Griffon(int playerlevel) : Monster("그리폰", 400 + (2 * playerlevel), 110 + (4 * playerlevel)) {}


Nightmare::Nightmare(int playerlevel) : Monster("나이트 메어", 380 + (2 * playerlevel), 120 + (4 * playerlevel)) {}


Manticore::Manticore(int playerlevel) : Monster("만티코어", 550 + (2 * playerlevel), 120 + (4 * playerlevel)) {}



Boss::Boss(int playerlevel) : Monster("미켈라의 칼날 말레니아", 1000, 240)
{
	cout << "몸은 금빛을 잃고, 피는 부패하니...." << "[" << getName() << "]" << "패배를 모르는 싸움을.\n";
}