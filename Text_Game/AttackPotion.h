#pragma once
#include "Item.h"
#include "Character.h"
#include <iostream>

class AttackPotion : public Item {
public:
    AttackPotion() : Item("���� ����") {}
    void use(Character* character) override;
};