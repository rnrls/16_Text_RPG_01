#include "Monster.h"


using namespace std;


Irongorem::Irongorem(int playerlevel) : Monster("아이언 골렘", 200 + (2 * playerlevel), 10 + (4 * playerlevel)) {}


Lich::Lich(int playerlevel) : Monster("리치", 75 + (2 * playerlevel), 25 + (4 * playerlevel)) {}


Griffon::Griffon(int playerlevel) : Monster("그리폰", 170 + (2 * playerlevel), 20 + (4 * playerlevel)) {}


Nightmare::Nightmare(int playerlevel) : Monster("나이트 메어", 150 + (2 * playerlevel), 30 + (4 * playerlevel)) {}




