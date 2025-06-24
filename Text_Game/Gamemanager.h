#pragma once


class Character;
class Monster;

class Gamemanager {
public:
    Gamemanager(); 

    
    Monster* GenerateMonster(int level);
    void Battle(Character* player, Monster* monster);
    void DisplayInventory(Character* player);
    void showPlayerStatus(Character* player);
    void goToTown();
    void goStore(Character* player);
	void buyStore(Character* player);
    void sellStore(Character* player);
};


