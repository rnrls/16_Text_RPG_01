#pragma once
#include "Item.h"


class HealthPotion : public Item {
public:
    HealthPotion() : Item("ü�� ����") {}
    void use(Character* character) override;
};
