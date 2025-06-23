#pragma once

#include "Item.h"

class HealingPotion : public Item {
public:
    HealingPotion(std::string name = "정령의 가호");
    std::string getName() const override;
    void use(Character* character) override;
};
