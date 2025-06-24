#include "Monster.h"

using namespace std;

//����
Goblin::Goblin(int playerlevel) : Monster("���",  35 + (5 * playerlevel), 5 + (10 * playerlevel)) {}


Wereworf::Wereworf(int playerlevel) : Monster("���� ����", 45 + (5 * playerlevel), 10 + (10 * playerlevel)) {}


Lizardeman::Lizardeman(int playerlevel) : Monster("���ڵ��",  60 + (5 * playerlevel), 15 + (10 * playerlevel)) {}


Harpy::Harpy(int playerlevel) : Monster("����", 75 + (5 * playerlevel), 20 + (10 * playerlevel)) {}


//�߰�
Gargoyle::Gargoyle(int playerlevel) : Monster("������", 170 + (3 * playerlevel), 60 + (6 * playerlevel)) {}


Dryad::Dryad(int playerlevel) : Monster("����̾��",  150 + (2 * playerlevel), 15 + (4 * playerlevel)) {}


Lich::Lich(int playerlevel) : Monster("��ġ", 120 + (3 * playerlevel), 80 + (6 * playerlevel)) {}


Vampire::Vampire(int playerlevel) : Monster("�����̾�", 60 + (3 * playerlevel), 65 + (6 * playerlevel)) {}


//�� 
Irongorem::Irongorem(int playerlevel) : Monster("���̾� ��",  600 + (2 * playerlevel), 90 + (3 * playerlevel)) {}


Griffon::Griffon(int playerlevel) : Monster("�׸���", 400 + (2 * playerlevel), 105 + (3 * playerlevel)) {}


Nightmare::Nightmare(int playerlevel) : Monster("����Ʈ �޾�", 300 + (2 * playerlevel), 100 + (3 * playerlevel)) {}


Manticore::Manticore(int playerlevel) : Monster("��Ƽ�ھ�", 550 + (2 * playerlevel), 120 + (3 * playerlevel)) {}


