#include "HealingPotion.h"
#include "Character.h"
#include <iostream>

HealingPotion::HealingPotion(std::string name)
    : Item(name) {
}

std::string HealingPotion::getName() const {
    return Name;
}

void HealingPotion::use(Character* character) {
    int maxHP = character->GetMaxHelth();
    character->Heal(maxHP);
    std::cout << Name << " 사용! 체력이 전부 회복되었습니다." << std::endl;
}
