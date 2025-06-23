/*
#include "Gamemanager.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>


using namespace std;

Gamemanager::Gamemanager() {
    srand(static_cast<unsigned int>(time(0)));
}

Monster* Gamemanager::GenerateMonster(int level) {
    Monster* monster = nullptr;
    int monsterType = rand() % 4;

    switch (monsterType) {
    case 0: monster = new Irongorem(level); break;
    case 1: monster = new Lich(level); break;
    case 2: monster = new Griffon(level); break;
    case 3: monster = new Nightmare(level); break;
    }
    return monster;
}

void Gamemanager::Battle(Character* player, Monster* monster) {
    cout << "\n!! 야생의 " << monster->getName() << "이(가) 나타났다! !!" << endl;
    cout << "이름: " << monster->getName() << " | 체력: " << monster->getHealth() << " | 공격력: " << monster->getAttack() << endl;
    system("pause");

    while (true) {
        system("cls");

        cout << "\n[PLAYER TURN]" << endl;


        if (!player->getInventory().empty() && (rand() % 4 == 0)) {
            cout << ">> " << player->getName() << "이(가) 아이템을 사용한다!" << endl;
            int itemIndex = rand() % player->getInventory().size();
            player->useItem(itemIndex);
            cout << endl;
        }


        int playerAttack = player->getAttack();
        cout << player->getName() << "의 공격!" << endl;
        monster->takeDamage(playerAttack);
        cout << ">> " << monster->getName() << "에게 " << playerAttack << "의 데미지! (남은 체력: " << monster->getHealth() << ")" << endl;

        if (monster->isDead()) {
            cout << monster->getName() << "을(를) 처치했다! " << endl;
            player->addExperience(50);
            int gold = (rand() % 11) + 10;
            player->addGold(gold);

            if ((rand() % 100) < 30) {
                if (rand() % 2 == 0) player->addItem(new HealthPotion());
                else player->addItem(new AttackBoost());
            }
            break;
        }

        cout << "\n";
        system("pause");


        cout << "\n[MONSTER TURN]" << endl;
        int monsterAttack = monster->getAttack();
        cout << monster->getName() << "의 공격!" << endl;
        player->takeDamage(monsterAttack);
        cout << ">> " << player->getName() << "에게 " << monsterAttack << "의 데미지!" << endl;

        if (player->isDead()) {
            cout << "\n결국 " << player->getName() << "은(는) 쓰러지고 말았다..." << endl;
            break;
        }
        cout << endl;
        showPlayerStatus(player);
        system("pause");
    }
}

void Gamemanager::showPlayerStatus(Character* player) {
    cout << "\n--- 내 정보 ---\n";
    player->displayStatus();
    cout << "---------------\n";
}
*/
