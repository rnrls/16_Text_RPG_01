
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
    cout << "\n!! �߻��� " << monster->getName() << "��(��) ��Ÿ����! !!" << endl;
    system("pause");

    while (!player->isDead() && !monster->isDead()) {
        system("cls");
        cout << "[PLAYER TURN]\n";
        cout << "1. ����\n2. ������ ���\n����: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int playerAttack = player->getAttack();
            cout << player->getName() << "�� ����!" << endl;
            monster->takeDamage(playerAttack);
            cout << ">> " << monster->getName() << "���� " << playerAttack << "�� ������! (���� ü��: " << monster->getHealth() << ")" << endl;
        }
        else if (choice == 2) {
            DisplayInventory(player);
            cout << "�������� �����ϴ�.(EXIT: 0): ";
            string choice_exit;
            cin >> choice_exit;
            if (choice_exit == "0")
            {
                cout << "�������� ���������ʾ� �������� �Ѿ�ϴ�.\n";
                continue;
            }
            else
            {
                cin.ignore();
                int itemIndex = stoi(choice_exit);
                --itemIndex;
                player->UseItem(itemIndex);
            }
        }
        else {
            cout << "�߸��� �����Դϴ�.\n";
            continue;
        }

        if (monster->isDead()) {
            cout << monster->getName() << "��(��) óġ�ߴ�! " << endl;
            int exp = (rand() % 21 + 40);
            player->AddExp(exp);
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
        cout << monster->getName() << "�� ����!" << endl;
        player->takeDamage(monsterAttack);
        cout << ">> " << player->getName() << "���� " << monsterAttack << "ü�� :" << player->getHealth() << ")" << endl;

        if (player->isDead()) {
            cout << player->getName() << "��(��) ��������..." << endl;
            break;
        }

        system("pause");
    }

    showPlayerStatus(player);
    system("pause");
}


void Gamemanager::showPlayerStatus(Character* player) {
    cout << "\n--- �� ���� ---\n";
    player->DisplayStatus();
    cout << "---------------\n";
}

void Gamemanager::DisplayInventory(Character* player) {
    cout << "\n--- �κ��丮 ---\n";
    const auto& inventory = player->GetInventory();
    if (inventory.empty()) {
        cout << "������ ����ֽ��ϴ�." << endl;
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
    cout << "������ �������� ����ϰ� �޽��Ͽ� ��� ü���� ȸ���߽��ϴ�." << endl;
    showPlayerStatus(player);
}
//