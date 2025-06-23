#include "HealthPotion.h"
#include "Character.h"
#include <iostream>

void HealthPotion::use(Character* character) {
    character->Heal(character->GetMaxHealth());
    std::cout << "[아이템 사용] 체력이 모두 회복되었습니다!" << std::endl;
}
