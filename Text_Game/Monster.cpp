#include "Monster.h"

using namespace std;

//저렙
Goblin::Goblin(int playerlevel) : Monster("고블린",  35 + (2 * playerlevel), 5 + (4 * playerlevel)) {}


Wereworf::Wereworf(int playerlevel) : Monster("웨어 울프", 45 + (2 * playerlevel), 10 + (4 * playerlevel)) {}


Lizardeman::Lizardeman(int playerlevel) : Monster("리자드맨", 60 + (2 * playerlevel), 15 + (4 * playerlevel)) {}


Harpy::Harpy(int playerlevel) : Monster("하피", 75 + (2 * playerlevel), 20 + (4 * playerlevel)) {}



//고렙
Irongorem::Irongorem(int playerlevel) : Monster("아이언 골렘",  250 + (2 * playerlevel), 10 + (4 * playerlevel)) {}


Lich::Lich(int playerlevel) : Monster("리치", 100 + (2 * playerlevel), 25 + (4 * playerlevel)) {}


Griffon::Griffon(int playerlevel) : Monster("그리폰", 170 + (2 * playerlevel), 20 + (4 * playerlevel)) {}


Nightmare::Nightmare(int playerlevel) : Monster("나이트 메어", 150 + (2 * playerlevel), 30 + (4 * playerlevel)) {}



