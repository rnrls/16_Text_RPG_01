
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
    cout << "\n!! 야생의 " << monster->getName() << "이(가) 나타났다! !!" << endl;
    system("pause");

    while (!player->isDead() && !monster->isDead()) {
        //*system("cls");
        cout << "[PLAYER TURN]\n";
        cout << "1. 공격\n2. 아이템 사용\n선택: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int playerAttack = player->getAttack();
            cout << player->getName() << "의 공격!" << endl;
            monster->takeDamage(playerAttack);
            cout << ">> " << monster->getName() << "에게 " << playerAttack << "의 데미지! (남은 체력: " << monster->getHealth() << ")" << endl;
            cout << "---------------------------------------------" << endl;
        }
        else if (choice == 2) {
            DisplayInventory(player);
            cout << "아이템이 없습니다.(EXIT: 0): ";
            string choice_exit;
            cin >> choice_exit;
            if (choice_exit == "0")
            {
                cout << "인벤토리 종료\n";
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
            cout << "잘못된 선택입니다.\n";
            continue;
        }

        if (monster->isDead()) {
            cout << monster->getName() << "을(를) 처치했다! " << endl;
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

            cout << "\n상점을 방문하시겠습니까? (Y/N): ";
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
                cout << "잘못된 선택입니다" << endl;
                continue;
			}

            break;
        }

        cout << "[MONSTER TURN]" << endl;
        int monsterAttack = monster->getAttack();
        cout << monster->getName() << "의 공격!" << endl;
        player->takeDamage(monsterAttack);
        cout << ">> " << player->getName() << "에게 " << monsterAttack << "체력 :" << player->getHealth() << ")" << endl;
        cout << "---------------------------------------------" << endl;

        if (player->isDead()) {
            cout << player->getName() << "이(가) 쓰러졌다..." << endl;
            system("pause");

            system("cls");

            cout << "\n=== [게임 오버] ===\n";
            system("pause");

            break;
        }

       //* system("pause");
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
    if (player->GetGold() >= 5) {
     
        player->SpendGold(5);

        
        player->fullHeal();

       
        cout << "마을의 여관에서 편안하게 휴식하여 모든 체력을 회복하고, 5 골드를 지불했습니다." << endl;
    }
    else {
        
        cout << "골드가 부족하여 여관에서 쉴 수 없습니다. (필요 골드: 5)" << endl;
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
    std::cout << "\n===== 게임 통계 =====\n";
    std::cout << ">> 몬스터 처치 내역\n";
    for (const auto& [name, count] : killLog) {
        std::cout << "- " << name << ": " << count << "마리\n";
    }
    std::cout << "\n>> 총 골드 획득량: " << totalGoldEarned << " G\n";
    std::cout << ">> 총 아이템 사용 횟수: " << totalItemUsed << "회\n";
}

void Gamemanager::goStore(Character* player) {
    system("cls");
    while (true) {
        cout << "==== 상점 ====" << endl;
		cout << "현재 골드: " << player->GetGold() << endl;
		cout << "1.아이템 구매" << endl;
		cout << "2.아이템 판매" << endl;
		cout << "3.상점 나가기" << endl;
        cout << "선택: ";

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
			cout << "잘못된 입력입니다." << endl;
            continue;
        }

    }
}

void Gamemanager::buyStore(Character* player) {
    system("cls");
    cout << "좋은물건을 골라보시지요" << endl;
	cout << "현재 골드: " << player->GetGold() << endl;
    cout << "1.체력 포션____10골드" << endl;
    cout << "2.힘의 영약____20골드" << endl;
    cout << "0.상점 나가기" << endl;
    cout << "선택: ";
    
    int choice;
    cin >> choice;
    if (choice == 1) {
        if (player->GetGold() >= 10) {
            player->SpendGold(10);
            player->AddItem(new HealthPotion());
            cout << "체력 포션을 구매했습니다" << endl;
        } else {
            cout << "골드가 모자라군" << endl;
        }
    } else if (choice == 2) {
        if (player->GetGold() >= 20) {
            player->SpendGold(20);
            player->AddItem(new AttackPotion());
            cout << "힘의 영약을 구매했습니다" << endl;
        } else {
            cout << "골드가 모자라군" << endl;
        }
    } else if (choice == 0) {
        return;
    } else {
        cout << "잘못된 선택입니다." << endl;
    }
}

void Gamemanager::sellStore(Character* player) {
    system("cls");
	cout << "어떤물건을 파실건가요" << endl;
	cout << "현재 골드: " << player->GetGold() << endl;
    vector<int> sellList;
    const auto& inventory = player->GetInventory();
    if (inventory.empty()) {
        cout << " - 팔 물건 없음\n";
    }
    else {
        for (size_t i = 0; i < inventory.size(); ++i) {
            if(inventory[i]->GetName() == "힘의 영약")
            {
				cout << i + 1 << ". " << inventory[i]->GetName() << "____12골드" << endl;
            }
            else if (inventory[i]->GetName() == "체력 포션")
            {
                cout << i + 1 << ". " << inventory[i]->GetName() << "____6골드" << endl;
            }
            sellList.push_back(i);
        }  
        cout << "0.상점 나가기" << endl;
        cout << "선택: ";

		int choice;
        cin >> choice;
        if(choice == 0){
            return;
        }
        else if (choice > 0 && choice <= static_cast<int>(sellList.size())) {
            int Index = sellList[choice - 1];
            Item* itemToSell = inventory[Index];
            int Price = (itemToSell->GetName() == "힘의 영약") ? 12 : 6;
            player->AddGold(Price);
			player->RemoveItem(Index);
        } else {
            cout << "잘못된 선택입니다." << endl;
		}
    }
}
