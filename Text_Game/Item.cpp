#include "Item.h"
#include "Character.h"
#include <iostream>

Item::Item(const std::string& name)
    : Name(name) {
}

std::string Item::getName() const {
    return Name;
}

void Item::use(Character* character) {
    // 기본 아이템 효과 (힘의 포션)
    if (Name == "힘의 포션") {
        character->AddAttack(30);
        std::cout << "[아이템 사용] 공격력이 30 증가했습니다!" << std::endl;
    }
    else {
        std::cout << "[아이템 사용] 효과가 없는 아이템입니다." << std::endl;
    }
}

