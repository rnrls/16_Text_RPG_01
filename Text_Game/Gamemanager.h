#pragma once

#include <map>
#include <string>
class Character;
class Monster;

class Gamemanager {
private:
    std::map<std::string, int> killLog;
    int totalGoldEarned = 0;
    int totalItemUsed = 0;
public:
    Gamemanager(); 
    
    Monster* GenerateMonster(int level);
    void Battle(Character* player, Monster* monster);
    void DisplayInventory(Character* player);
    void showPlayerStatus(Character* player);
    void goToTown();
    void incrementKillLog(const std::string& name);
    void addGoldLog(int amount);
    void addItemUseLog();
    void ShowStatistics() const;
    void goStore(Character* player);
	void buyStore(Character* player);
    void sellStore(Character* player);

    Monster* GenerateBoss(int level);
};


