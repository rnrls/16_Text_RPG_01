#include "Gamemanager.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Gamemanager::displayInventory(Character* player)
{
    // 인벤토리 목록
    cout << "Inventory:" << endl;
    for (size_t i = 0; i < player->inventory.size(); ++i) {
        cout << i << ": " << player->inventory[i]->getName() << endl;
    }
    cout << "=========================\n";
}

