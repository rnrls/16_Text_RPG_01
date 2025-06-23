#include "Item.h"
#include "Character.h"
#include <iostream>

Item::Item(const std::string& name) : Name(name) {}

std::string Item::GetName() const {
    return Name;
}

void Item::use(Character* character) {
    std::cout << "[아이템 사용] 효과가 없는 아이템입니다." << std::endl;
}