#pragma once

#include "Character.h"
#include "Monster.h"

class Gamemanager {
public:
    Monster* Generatemonster(int level);
    void Battle(Character* player);
    void DisplayInventory(Character* player);
    int GetRandomInt(int min, int max);
};

