#pragma once

#include "Item.h"

class HealingPotion : public Item {
public:
    HealingPotion(std::string name = "������ ��ȣ");
    std::string getName() const override;
    void use(Character* character) override;
};
