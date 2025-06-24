#include "AttackPotion.h"
#include "Character.h"
#include <iostream>

void AttackPotion::use(Character* character) {
    character->AddAttack(20);
    std::cout << "[아이템 사용] 공격력이 20 증가했습니다!" << std::endl;
}
/**/