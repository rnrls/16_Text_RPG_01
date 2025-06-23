
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
    cout << "\n!! �߻��� " << monster->getName() << "��(��) ��Ÿ����! !!" << endl;
    cout << "�̸�: " << monster->getName() << " | ü��: " << monster->getHealth() << " | ���ݷ�: " << monster->getAttack() << endl;
    system("pause");

    while (true) {
        system("cls");

        cout << "\n[PLAYER TURN]" << endl;


        if (!player->getInventory().empty() && (rand() % 4 == 0)) {
            cout << ">> " << player->getName() << "��(��) �������� ����Ѵ�!" << endl;
            int itemIndex = rand() % player->getInventory().size();
            player->useItem(itemIndex);
            cout << endl;
        }


        int playerAttack = player->getAttack();
        cout << player->getName() << "�� ����!" << endl;
        monster->takeDamage(playerAttack);
        cout << ">> " << monster->getName() << "���� " << playerAttack << "�� ������! (���� ü��: " << monster->getHealth() << ")" << endl;

        if (monster->isDead()) {
            cout << monster->getName() << "��(��) óġ�ߴ�! " << endl;
            player->addExperience(50);
            int gold = (rand() % 11+20);
            player->addGold(gold);

            int itemType = rand() % 2;
            if (itemType == 0)
            {
                player->addItem(new HealthPotion());
            }
            else
            {
                player->addItem(new AttackBoost());
            }
            
            break;
        }

        cout << endl;
        showPlayerStatus(player);
        system("pause");

        while (true) {
            system("cls");
            cout << "\n--- ���� ���� ---" << endl;
            cout << "������ �������ϴ�. �������� ����Ͻðڽ��ϱ�?" << endl;
            cout << "1. ü�� ���� ���" << endl;
            cout << "2. ���ݷ� �ν�Ʈ ���" << endl;
            cout << "3. �׳� �����ϱ�" << endl;
            cout << "����: ";

            int choice;
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                choice = 0;
            }

            if (choice == 1) {
                player->useItemByName("ü�� ����");
                showPlayerStatus(player);
                system("pause");
            }
            else if (choice == 2) {
                player->useItemByName("���ݷ� �ν�Ʈ");
                showPlayerStatus(player); 
                system("pause");
            }
            else if (choice == 3) {
                break; 
            }
            else {
                cout << "�߸��� �Է��Դϴ�." << endl;
                system("pause");
            }
        }
       

        break; 
    }

    cout << endl;
    showPlayerStatus(player);
    system("pause");



        cout << "\n[MONSTER TURN]" << endl;
        int monsterAttack = monster->getAttack();
        cout << monster->getName() << "�� ����!" << endl;
        player->takeDamage(monsterAttack);
        cout << ">> " << player->getName() << "���� " << monsterAttack << "�� ������!" << endl;

        if (player->isDead()) {
            cout << "\n�ᱹ " << player->getName() << "��(��) �������� ���Ҵ�..." << endl;
            break;
        }
        cout << endl;
        showPlayerStatus(player);
        system("pause");
    }


void Gamemanager::showPlayerStatus(Character* player) {
    cout << "\n--- �� ���� ---\n";
    player->displayStatus();
    cout << "---------------\n";
}

void Gamemanager::DisplayInventory(Character* player) {
    cout << "\n--- �κ��丮 ---\n";
    const auto& inventory = player->getInventory();
    if (inventory.empty()) {
        cout << "������ ����ֽ��ϴ�." << endl;
    }
    else {
        for (size_t i = 0; i < inventory.size(); ++i) {
            cout << i + 1 << ". " << inventory[i]->getName() << endl;
        }
    }
    cout << "----------------\n";
}

void Gamemanager::goToTown() {
    Character* player = Character::getInstance();
    player->fullHeal();
    cout << "������ �������� ����ϰ� �޽��Ͽ� ��� ü���� ȸ���߽��ϴ�." << endl;
    showPlayerStatus(player);
}