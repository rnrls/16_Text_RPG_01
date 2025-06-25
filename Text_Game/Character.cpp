#include "Character.h"
#include <iostream>
#include <algorithm>

using namespace std;

Character* Character::instance = nullptr;

Character::Character(const string& Name)
    : Name(Name), Level(1), MaxHealth(200), Health(200),
    Attack(30), Exp(0), Gold(0), defeatedMonsters(0) {
    cout << "\n" << "[" << Name << "]" << endl;
    cout << "����: " << Level << endl;
    cout << "ü��: " << Health << endl;
    cout << "���ݷ�: " << Attack << endl;
}

Character* Character::GetInstance(const string& name) {
    if (!instance)
        instance = new Character(name);
    return instance;
}

void Character::DisplayStatus() {  // �빮�� D
    cout << "===== ĳ���� ���� =====" << endl;
    cout << "�̸�: " << Name << endl;
    cout << "����: " << Level << endl;
    cout << "ü��: " << Health << "/" << MaxHealth << endl;
    cout << "���ݷ�: " << Attack << endl;
    cout << "����ġ: " << Exp << "/100" << endl;
    cout << "���: " << Gold << endl;
    cout << "óġ�� ����: " << defeatedMonsters << "����" << endl;

    cout << "���� ������:\n";
    if (Inventory.empty()) {
        cout << " - ����\n";
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

    cout << "[������!]" << endl;
    cout << "����: " << Level << endl;
    cout << "ü��: " << Health << endl;
    cout << "���ݷ�: " << Attack << endl;
}

void Character::UseItem(int index) {
    if (index < 0 || index >= (int)Inventory.size()) {
        cout << "�߸��� �ε����Դϴ�." << endl;
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
    cout << "[EXP +" << amount << "] ���� ����ġ: " << Exp << endl;

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
        cout << "�ش� �������� �����ϰ� ���� �ʽ��ϴ�.\n";
    }
}
