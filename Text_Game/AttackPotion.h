#pragma once
#include "Item.h"
#include "Character.h"
#include <iostream>

class AttackPotion : public Item {
public:
    AttackPotion() : Item("ÈûÀÇ Æ÷¼Ç") {}
    void use(Character* character) override;
};