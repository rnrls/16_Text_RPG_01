
#include "Gamemanager.h"
#include "Character.h"
#include "Monster.h"
#include "HealthPotion.h"
#include "AttackPotion.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <map>
#include <string>

using namespace std;

Gamemanager::Gamemanager() {
    srand(static_cast<unsigned int>(time(0)));
}

Monster* Gamemanager::GenerateMonster(int level) {
    Monster* monster = nullptr;
    int monsterType = rand() % 4;
    if (level < 5)
    {
        switch (monsterType){
        case 0: monster = new Goblin(level); break;
        case 1: monster = new Wereworf(level); break;
        case 2: monster = new Lizardeman(level); break;
        case 3: monster = new Harpy(level); break;
        }
    }
    else if (level < 8)
    {
        switch (monsterType) {
        case 0: monster = new Gargoyle(level); break;
        case 1: monster = new Dryad(level); break;
        case 2: monster = new Lich(level); break;
        case 3: monster = new Vampire(level); break;
        }
    }
    else
    {
        switch (monsterType){
        case 0: monster = new Irongorem(level); break;
        case 1: monster = new Manticore(level); break;
        case 2: monster = new Griffon(level); break;
        case 3: monster = new Nightmare(level); break;
        }
    }
    return monster;
}

Monster* Gamemanager::GenerateBoss(int level)
{
    Monster* monster = nullptr;
    monster = new Boss(level);
    return monster;
}

void Gamemanager::Battle(Character* player, Monster* monster) {
    cout << "\n!! �߻��� " << monster->getName() << "��(��) ��Ÿ����! !!" << endl;
    system("pause");

    while (!player->isDead() && !monster->isDead()) {
        //*system("cls");
        cout << "[PLAYER TURN]\n";
        cout << "1. ����\n2. ������ ���\n����: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int playerAttack = player->getAttack();
            cout << player->getName() << "�� ����!" << endl;
            monster->takeDamage(playerAttack);
            cout << ">> " << monster->getName() << "���� " << playerAttack << "�� ������! (���� ü��: " << monster->getHealth() << ")" << endl;
            cout << "---------------------------------------------" << endl;
        }
        else if (choice == 2) {
            DisplayInventory(player);
            cout << "�������� �����ϴ�.(EXIT: 0): ";
            string choice_exit;
            cin >> choice_exit;
            if (choice_exit == "0")
            {
                cout << "�κ��丮 ����\n";
                continue;
            }
            else
            {
                cin.ignore();
                int itemIndex = stoi(choice_exit);
                --itemIndex;
                player->UseItem(itemIndex);
                addItemUseLog();
            }
        }
        else {
            cout << "�߸��� �����Դϴ�.\n";
            continue;
        }

        if (monster->isDead()) {
            cout << monster->getName() << "��(��) óġ�ߴ�! " << endl;
            player->IncrementDefeatedMonstersCount();
            incrementKillLog(monster->getName());
            int exp = (rand() % 21 + 35);
            player->AddExp(exp);
            int gold = (rand() % 11 + 20);
            player->AddGold(gold);
            addGoldLog(gold);

            int itemType = rand() % 2;
            if (itemType == 0)
                player->AddItem(new HealthPotion());
            else
                player->AddItem(new AttackPotion());

            cout << "\n������ �湮�Ͻðڽ��ϱ�? (Y/N): ";
            char storeChoice;
            cin >> storeChoice;
            if (storeChoice == 'Y' || storeChoice == 'y')
            {
				goStore(player);
            }else if (storeChoice == 'N' || storeChoice == 'n')
            {
                break;
            }
            else
            {
                cout << "�߸��� �����Դϴ�" << endl;
                continue;
			}

            break;
        }

        cout << "[MONSTER TURN]" << endl;
        int monsterAttack = monster->getAttack();
        cout << monster->getName() << "�� ����!" << endl;
        player->takeDamage(monsterAttack);
        cout << ">> " << player->getName() << "���� " << monsterAttack << "ü�� :" << player->getHealth() << ")" << endl;
        cout << "---------------------------------------------" << endl;

        if (player->isDead()) {
            cout << player->getName() << "��(��) ��������..." << endl;
            system("pause");

            system("cls");

            cout << "\n=== [���� ����] ===\n";
            system("pause");

            break;
        }

       //* system("pause");
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
    if (player->GetGold() >= 5) {
     
        player->SpendGold(5);

        
        player->fullHeal();

       
        cout << "������ �������� ����ϰ� �޽��Ͽ� ��� ü���� ȸ���ϰ�, 5 ��带 �����߽��ϴ�." << endl;
    }
    else {
        
        cout << "��尡 �����Ͽ� �������� �� �� �����ϴ�. (�ʿ� ���: 5)" << endl;
    }
    showPlayerStatus(player);
}

void Gamemanager::incrementKillLog(const std::string& name) {
    killLog[name]++;
}

void Gamemanager::addGoldLog(int amount) {
    totalGoldEarned += amount;
}

void Gamemanager::addItemUseLog() {
    totalItemUsed++;
}

void Gamemanager::ShowStatistics() const {
    std::cout << "\n===== ���� ��� =====\n";
    std::cout << ">> ���� óġ ����\n";
    for (const auto& [name, count] : killLog) {
        std::cout << "- " << name << ": " << count << "����\n";
    }
    std::cout << "\n>> �� ��� ȹ�淮: " << totalGoldEarned << " G\n";
    std::cout << ">> �� ������ ��� Ƚ��: " << totalItemUsed << "ȸ\n";
}

void Gamemanager::goStore(Character* player) {
    system("cls");
    while (true) {
        cout << "==== ���� ====" << endl;
		cout << "���� ���: " << player->GetGold() << endl;
		cout << "1.������ ����" << endl;
		cout << "2.������ �Ǹ�" << endl;
		cout << "3.���� ������" << endl;
        cout << "����: ";

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            buyStore(player);
            system("cls");
			continue;
        }
        else if (choice == 2)
        {
            sellStore(player);
            system("cls");
			continue;
        }
        else if (choice == 3)
        {
            return;
        }
        else
        {
			cout << "�߸��� �Է��Դϴ�." << endl;
            continue;
        }

    }
}

void Gamemanager::buyStore(Character* player) {
    system("cls");
    cout << "���������� ��󺸽�����" << endl;
	cout << "���� ���: " << player->GetGold() << endl;
    cout << "1.ü�� ����____10���" << endl;
    cout << "2.���� ����____20���" << endl;
    cout << "0.���� ������" << endl;
    cout << "����: ";
    
    int choice;
    cin >> choice;
    if (choice == 1) {
        if (player->GetGold() >= 10) {
            player->SpendGold(10);
            player->AddItem(new HealthPotion());
            cout << "ü�� ������ �����߽��ϴ�" << endl;
        } else {
            cout << "��尡 ���ڶ�" << endl;
        }
    } else if (choice == 2) {
        if (player->GetGold() >= 20) {
            player->SpendGold(20);
            player->AddItem(new AttackPotion());
            cout << "���� ������ �����߽��ϴ�" << endl;
        } else {
            cout << "��尡 ���ڶ�" << endl;
        }
    } else if (choice == 0) {
        return;
    } else {
        cout << "�߸��� �����Դϴ�." << endl;
    }
}

void Gamemanager::sellStore(Character* player) {
    system("cls");
	cout << "������� �Ľǰǰ���" << endl;
	cout << "���� ���: " << player->GetGold() << endl;
    vector<int> sellList;
    const auto& inventory = player->GetInventory();
    if (inventory.empty()) {
        cout << " - �� ���� ����\n";
    }
    else {
        for (size_t i = 0; i < inventory.size(); ++i) {
            if(inventory[i]->GetName() == "���� ����")
            {
				cout << i + 1 << ". " << inventory[i]->GetName() << "____12���" << endl;
            }
            else if (inventory[i]->GetName() == "ü�� ����")
            {
                cout << i + 1 << ". " << inventory[i]->GetName() << "____6���" << endl;
            }
            sellList.push_back(i);
        }  
        cout << "0.���� ������" << endl;
        cout << "����: ";

		int choice;
        cin >> choice;
        if(choice == 0){
            return;
        }
        else if (choice > 0 && choice <= static_cast<int>(sellList.size())) {
            int Index = sellList[choice - 1];
            Item* itemToSell = inventory[Index];
            int Price = (itemToSell->GetName() == "���� ����") ? 12 : 6;
            player->AddGold(Price);
			player->RemoveItem(Index);
        } else {
            cout << "�߸��� �����Դϴ�." << endl;
		}
    }
}
