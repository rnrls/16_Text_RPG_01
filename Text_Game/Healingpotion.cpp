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
    std::cout << Name << " ���! ü���� ���� ȸ���Ǿ����ϴ�." << std::endl;
}
