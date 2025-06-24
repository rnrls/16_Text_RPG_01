#pragma once
#include "Item.h"


class AttackPotion : public Item {
public:
    AttackPotion() : Item("ÈûÀÇ ¿µ¾à") {}
    void use(Character* character) override;
};