#pragma once

#include "Item.h"
#include <string>
#include <vector>

class Character {
private:
    static Character* instance;

    std::string Name;
    int Level;
    int MaxHealth;
    int Health;
    int Attack;
    int Exp;
    int Gold;
    std::vector<Item*> Inventory;

    Character(const std::string& Name);

public:
    static Character* GetInstance(const std::string& name = "");

    void DisplayStatus();       
    void LevelUp();
    bool isDead() const;

    void UseItem(int index);    
    void AddItem(Item* newItem);
    void Heal(int amount);
    void AddAttack(int amount);

    void AddGold(int amount);
    int GetGold() const;
    bool SpendGold(int amount);

    int GetMaxHealth() const;
    const std::vector<Item*>& GetInventory() const;

    void AddExp(int amount);

    const std::string& getName() const { return Name; }
    int getHealth() const { return Health; }
    int getAttack() const { return Attack; }
    void takeDamage(int amount);
    void fullHeal();
    int GetLevel() const { return Level; }
    void useItemByName(const std::string& itemName);
};
