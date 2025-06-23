#pragma once
#include "Item.h"


class HealthPotion : public Item {
public:
    HealthPotion() : Item("체력 포션") {}
    void use(Character* character) override;
};
