
#include "Gamemanager.h"
#include "Character.h"
#include "Monster.h"
#include "HealthPotion.h"
#include "AttackPotion.h"
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
    system("pause");

    while (!player->isDead() && !monster->isDead()) {
        system("cls");
        cout << "[PLAYER TURN]\n";
        cout << "1. 공격\n2. 아이템 사용\n선택: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int playerAttack = player->getAttack();
            cout << player->getName() << "의 공격!" << endl;
            monster->takeDamage(playerAttack);
            cout << ">> " << monster->getName() << "에게 " << playerAttack << "의 데미지! (남은 체력: " << monster->getHealth() << ")" << endl;
        }
        else if (choice == 2) {
            DisplayInventory(player);
            cout << "사용할 아이템 번호 선택: ";
            int itemIndex;
            cin >> itemIndex;
            --itemIndex;
            player->UseItem(itemIndex);
        }
        else {
            cout << "잘못된 선택입니다.\n";
            continue;
        }

        if (monster->isDead()) {
            cout << monster->getName() << "을(를) 처치했다! " << endl;
            player->AddExp(50);
            int gold = (rand() % 11 + 20);
            player->AddGold(gold);

            int itemType = rand() % 2;
            if (itemType == 0)
                player->AddItem(new HealthPotion());
            else
                player->AddItem(new AttackPotion());

            break;
        }

        cout << "\n[MONSTER TURN]" << endl;
        int monsterAttack = monster->getAttack();
        cout << monster->getName() << "의 공격!" << endl;
        player->takeDamage(monsterAttack);
        cout << ">> " << player->getName() << "에게 " << monsterAttack << "의 데미지!" << endl;

        if (player->isDead()) {
            cout << player->getName() << "이(가) 쓰러졌다..." << endl;
            cout << "\n=== [게임 오버] ===\n";
            system("pause");
            break;
        }

        system("pause");
    }

    showPlayerStatus(player);
    system("pause");
}


void Gamemanager::showPlayerStatus(Character* player) {
    cout << "\n--- 내 정보 ---\n";
    player->DisplayStatus();
    cout << "---------------\n";
}

void Gamemanager::DisplayInventory(Character* player) {
    cout << "\n--- 인벤토리 ---\n";
    const auto& inventory = player->GetInventory();
    if (inventory.empty()) {
        cout << "가방이 비어있습니다." << endl;
    }
    else {
        for (size_t i = 0; i < inventory.size(); ++i) {
            cout << i + 1 << ". " << inventory[i]->GetName() << endl;
        }
    }
    cout << "----------------\n";
}

void Gamemanager::goToTown() {
    Character* player = Character::GetInstance();
    player->fullHeal();
    cout << "마을의 여관에서 편안하게 휴식하여 모든 체력을 회복했습니다." << endl;
    showPlayerStatus(player);
}