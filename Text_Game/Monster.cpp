#include "Monster.h"

using namespace std;

Irongorem::Irongorem(int level) : Monster("아이언 골렘", 7 * level, 5 * level) {}


Lich::Lich(int level) : Monster("리치", 8 * level, 6 * level) {}


Griffon::Griffon(int level) : Monster("그리폰", 9 * level, 7 * level) {}


Nightmare::Nightmare(int level) : Monster("나이트 메어", 10 * level, 9 * level) {}




