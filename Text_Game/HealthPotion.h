#pragma once
#include "Item.h"
#include "Character.h"

#include <iostream>

class HealthPotion : public Item {
public:
    HealthPotion() : Item("ü�� ����") {}
    void use(Character* character) override;
};
