#include "AttackPotion.h"
#include "Character.h"
#include <iostream>

void AttackPotion::use(Character* character) {
    character->AddAttack(20);
    std::cout << "[������ ���] ���ݷ��� 20 �����߽��ϴ�!" << std::endl;
}
/**/