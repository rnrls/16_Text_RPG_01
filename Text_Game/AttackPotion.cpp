#include "AttackPotion.h"
#include "Character.h"

void AttackPotion::use(Character* character) {
    character->AddAttack(30);
    std::cout << "[아이템 사용] 공격력이 30 증가했습니다!" << std::endl;
}