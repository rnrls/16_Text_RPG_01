#pragma once

#include "Item.h"
#include <string>
#include <vector>

class Character {
private:
    static Character* instance;

    std::string Name;
    int Level;
    int MaxHelth;
    int Helth;
    int Attack;
    int Exp;
    int Gold;
    std::vector<Item*> Inventory;

public:
    static Character* GetInstance(const std::string& name = "");

    void DisplayStatus();
    void LevelUp();
    bool isDead();

    void UseItem(int index);
    void AddItem(Item* newItem);
    void Heal(int amount);
    void AddAttack(int amount);  // 힘의 포션용

    void AddGold(int amount);
    int GetGold() const;
    bool SpendGold(int amount);

    int GetMaxHelth() const;
    const std::vector<Item*>& GetInventory() const;

    void AddExp(int amount);  // 경험치 추가
};
