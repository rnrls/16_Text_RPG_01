#include "Monster.h"

using namespace std;

//����
Goblin::Goblin(int playerlevel) : Monster("���",  1000 + (2 * playerlevel), 5 + (4 * playerlevel)) {}


Wereworf::Wereworf(int playerlevel) : Monster("���� ����", 1000 + (2 * playerlevel), 10 + (4 * playerlevel)) {}


Lizardeman::Lizardeman(int playerlevel) : Monster("���ڵ��", 1000 + (2 * playerlevel), 15 + (4 * playerlevel)) {}


Harpy::Harpy(int playerlevel) : Monster("����", 75 + (2 * playerlevel), 1000 + (4 * playerlevel)) {}



//��
Irongorem::Irongorem(int playerlevel) : Monster("���̾� ��",  250 + (2 * playerlevel), 10 + (4 * playerlevel)) {}


Lich::Lich(int playerlevel) : Monster("��ġ", 100 + (2 * playerlevel), 25 + (4 * playerlevel)) {}


Griffon::Griffon(int playerlevel) : Monster("�׸���", 170 + (2 * playerlevel), 20 + (4 * playerlevel)) {}


Nightmare::Nightmare(int playerlevel) : Monster("����Ʈ �޾�", 150 + (2 * playerlevel), 30 + (4 * playerlevel)) {}



