#include "Monster.h"

using namespace std;

Irongorem::Irongorem(int level) : Monster("���̾� ��", 20 * level, 5 * level) {}


Lich::Lich(int level) : Monster("��ġ", 30 * level, 6 * level) {}


Griffon::Griffon(int level) : Monster("�׸���", 40 * level, 7 * level) {}


Nightmare::Nightmare(int level) : Monster("����Ʈ �޾�", 60* level, 9 * level) {}




