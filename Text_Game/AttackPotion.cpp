#include "AttackPotion.h"
#include "Character.h"

void AttackPotion::use(Character* character) {
    character->AddAttack(30);
    std::cout << "[������ ���] ���ݷ��� 30 �����߽��ϴ�!" << std::endl;
}