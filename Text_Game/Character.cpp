#include "Character.h"
#include <iostream>
#include <algorithm>

using namespace std;

Character* Character::instance = nullptr;

Character::Character(const string& Name)
    : Name(Name), Level(1), MaxHealth(200), Health(200),
    Attack(30), Exp(0), Gold(0), defeatedMonsters(0) {
    cout << "\n" << "[" << Name << "]" << endl;
    cout << "레벨: " << Level << endl;
    cout << "체력: " << Health << endl;
    cout << "공격력: " << Attack << endl;
}

Character* Character::GetInstance(const string& name) {
    if (!instance)
        instance = new Character(name);
    return instance;
}

void Character::DisplayStatus() {  // 대문자 D
    cout << "===== 캐릭터 상태 =====" << endl;
    cout << "이름: " << Name << endl;
    cout << "레벨: " << Level << endl;
    cout << "체력: " << Health << "/" << MaxHealth << endl;
    cout << "공격력: " << Attack << endl;
    cout << "경험치: " << Exp << "/100" << endl;
    cout << "골드: " << Gold << endl;
    cout << "처치한 몬스터: " << defeatedMonsters << "마리" << endl;

    cout << "보유 아이템:\n";
    if (Inventory.empty()) {
        cout << " - 없음\n";
    }
    else {
        for (size_t i = 0; i < Inventory.size(); ++i) {
            cout << i + 1 << ". " << Inventory[i]->GetName() << "\n";
        }
    }
    cout << "========================" << endl;
}

void Character::IncrementDefeatedMonstersCount() {
    defeatedMonsters++;
}

int Character::GetDefeatedMonstersCount() const {
    return defeatedMonsters;
}

void Character::LevelUp() {
    if (Level >= 10) return;

    Level++;
    MaxHealth += Level * 20;
    Attack += Level * 5;
    Health = MaxHealth;

    cout << "[레벨업!]" << endl;
    cout << "레벨: " << Level << endl;
    cout << "체력: " << Health << endl;
    cout << "공격력: " << Attack << endl;
}

void Character::UseItem(int index) {
    if (index < 0 || index >= (int)Inventory.size()) {
        cout << "잘못된 인덱스입니다." << endl;
        return;
    }
    Inventory[index]->use(this);
    delete Inventory[index];
    Inventory.erase(Inventory.begin() + index);
}

void Character::RemoveItem(int index) {  
    delete Inventory[index];
    Inventory.erase(Inventory.begin() + index);
}

void Character::AddItem(Item* NewItem) {
    Inventory.push_back(NewItem);
}

void Character::Heal(int Amount) {
    Health = min(Health + Amount, MaxHealth);
}

void Character::AddAttack(int amount) {
    Attack += amount;
}

int Character::GetGold() const {
    return Gold;
}

void Character::AddGold(int Amount) {
    Gold += Amount;
}

bool Character::SpendGold(int Amount) {
    if (Gold >= Amount) {
        Gold -= Amount;
        return true;
    }
    return false;
}

int Character::GetMaxHealth() const {
    return MaxHealth;
}

const vector<Item*>& Character::GetInventory() const {
    return Inventory;
}

bool Character::isDead() const {
    return Health <= 0;
}

void Character::AddExp(int amount) {
    Exp += amount;
    cout << "[EXP +" << amount << "] 현재 경험치: " << Exp << endl;

    while (Exp >= 100) {
        Exp -= 100;
        LevelUp();
    }
}

void Character::takeDamage(int amount) {
    Health -= amount;
    if (Health < 0) Health = 0;
}

void Character::fullHeal() {
    Health = MaxHealth;
}

void Character::useItemByName(const std::string& itemName) {
    bool found = false;
    for (int i = 0; i < (int)Inventory.size(); ++i) {
        if (Inventory[i]->GetName() == itemName) {
            UseItem(i);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "해당 아이템을 보유하고 있지 않습니다.\n";
    }
}
