#include "Item.h"
#include "Character.h"
#include <iostream>

Item::Item(const std::string& name) : Name(name) {}

std::string Item::GetName() const {
    return Name;
}

void Item::use(Character* character) {
    std::cout << "[������ ���] ȿ���� ���� �������Դϴ�." << std::endl;
}