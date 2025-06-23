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
    // �⺻ ������ ȿ�� (���� ����)
    if (Name == "���� ����") {
        character->AddAttack(30);
        std::cout << "[������ ���] ���ݷ��� 30 �����߽��ϴ�!" << std::endl;
    }
    else {
        std::cout << "[������ ���] ȿ���� ���� �������Դϴ�." << std::endl;
    }
}

