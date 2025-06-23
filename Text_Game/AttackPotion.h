#pragma once
#include "Item.h"


class AttackPotion : public Item {
public:
    AttackPotion() : Item("ÈûÀÇ Æ÷¼Ç") {}
    void use(Character* character) override;
};