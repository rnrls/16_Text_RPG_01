#include "Monster.h"


using namespace std;


Irongorem::Irongorem(int playerlevel) : Monster("���̾� ��", 200 + (2 * playerlevel), 10 + (4 * playerlevel)) {}


Lich::Lich(int playerlevel) : Monster("��ġ", 75 + (2 * playerlevel), 25 + (4 * playerlevel)) {}


Griffon::Griffon(int playerlevel) : Monster("�׸���", 170 + (2 * playerlevel), 20 + (4 * playerlevel)) {}


Nightmare::Nightmare(int playerlevel) : Monster("����Ʈ �޾�", 150 + (2 * playerlevel), 30 + (4 * playerlevel)) {}




