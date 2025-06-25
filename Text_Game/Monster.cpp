#include "Monster.h"

using namespace std;

//����
Goblin::Goblin(int playerlevel) : Monster("���",  35 + (5 * playerlevel), 5 + (10 * playerlevel)) {}


Wereworf::Wereworf(int playerlevel) : Monster("���� ����", 45 + (5 * playerlevel), 10 + (10 * playerlevel)) {}


Lizardeman::Lizardeman(int playerlevel) : Monster("���ڵ��",  60 + (5 * playerlevel), 15 + (10 * playerlevel)) {}


Harpy::Harpy(int playerlevel) : Monster("����", 75 + (5 * playerlevel), 20 + (10 * playerlevel)) {}




//�߰�
Gargoyle::Gargoyle(int playerlevel) : Monster("������", 250 + (3 * playerlevel), 60 + (6 * playerlevel)) {}


Dryad::Dryad(int playerlevel) : Monster("����̾��", 200 + (3 * playerlevel), 75 + (6 * playerlevel)) {}


Lich::Lich(int playerlevel) : Monster("��ġ", 180 + (3 * playerlevel), 85 + (6 * playerlevel)) {}


Vampire::Vampire(int playerlevel) : Monster("�����̾�", 220 + (3 * playerlevel), 65 + (6 * playerlevel)) {}






//��
Irongorem::Irongorem(int playerlevel) : Monster("���̾� ��",  650 + (2 * playerlevel), 90 + (4 * playerlevel)) {}


Griffon::Griffon(int playerlevel) : Monster("�׸���", 400 + (2 * playerlevel), 110 + (4 * playerlevel)) {}


Nightmare::Nightmare(int playerlevel) : Monster("����Ʈ �޾�", 380 + (2 * playerlevel), 120 + (4 * playerlevel)) {}


Manticore::Manticore(int playerlevel) : Monster("��Ƽ�ھ�", 550 + (2 * playerlevel), 120 + (4 * playerlevel)) {}



Boss::Boss(int playerlevel) : Monster("���̶��� Į�� �����Ͼ�", 1000, 240)
{
	cout << "���� �ݺ��� �Ұ�, �Ǵ� �����ϴ�...." << "[" << getName() << "]" << "�й踦 �𸣴� �ο���.\n";
}