#pragma once
#include "Item.h"


class AttackPotion : public Item {
public:
    AttackPotion() : Item("���� ����") {}
    void use(Character* character) override;
};