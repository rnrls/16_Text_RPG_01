/*#include "Gamemanager.h"
#include "Monster.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

Monster* generateMonster(int level) {
    vector<string> names = { "Goblin", "Orc", "Troll", "Slime" };
    int idx = rand() % names.size();
    int baseHealth = 100 + (level * 10);
    int baseAttack = 10 + (level * 2);

    return new Monster(names[idx], baseHealth, baseAttack);

    void Gamemanager::displayInventory(Character * player)
    {
        // �κ��丮 ���
        cout << "Inventory:" << endl;
        for (size_t i = 0; i < player->inventory.size(); ++i) {
            cout << i << ": " << player->inventory[i]->getName() << endl;
        }
        cout << "=========================\n";
    }*/
