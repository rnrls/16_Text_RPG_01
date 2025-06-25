#include <iostream>
#include <string>
#include <limits>
#include "Gamemanager.h"
#include "Character.h"
#include "Monster.h"

using namespace std;

Gamemanager gameManager;

enum class start_choice
{
    START_GAME = 1,
    EXIT = 2,
};

void CreateCharacter() {
    string name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        system("cls");
        cout << "==============================\n";
        cout << "        [ĳ���� ����]         \n";
        cout << "==============================\n";

        cout << "�̸��� �Է��ϼ���: ";
        getline(cin, name);

        if (name.empty() || name.find_first_not_of(' ') == string::npos) {
            cout << "\n[����] �̸��� �������θ� ������ �� �����ϴ�. �ٽ� �Է����ּ���.\n";
            system("pause");
        }
        else {
            break;
        }
    }
    system("cls");
    cout << "[" << name << "]" << "\n" << "\nĳ���� �̸� ��� �Ϸ�!\n";
    cout << "\n�� ========== �� ========== �� ========== ��\n";
    Character* player = Character::GetInstance(name);
    cout << "\n�� ========== �� ========== �� ========== ��\n";
    system("pause");
}


bool StartGameLoop()
{
    Character* player = Character::GetInstance();

    bool isRunning = true;
    while (isRunning) {

        system("cls");

        cout << "\n===== �ؽ�Ʈ RPG =====\n";
        cout << "1. ĳ���� ���� ����\n";
        cout << "2. ������ ����\n";
        cout << "3. ����\n";
        cout << "4. �����\n";
        cout << "5. ����\n";
        cout << "6. ���� ��� ����\n";
        cout << "7. ���� ����\n";
        cout << "�޴��� �����ϼ���: ";

        int Choice;
        cin >> Choice;

        switch (Choice) {
        case 1:
            player->DisplayStatus();
            system("pause");
            break;
        case 2:
            gameManager.goToTown();
            system("pause");
            break;
        case 3:
            gameManager.goStore(player);
            system("pause");
            break;
        case 4:
        {
            Monster* monster = gameManager.GenerateMonster(player->GetLevel());
            gameManager.Battle(player, monster);

            if (player->isDead()) {
                //system("pause");
                //system("cls");
                cout << "\n����� ����Ϳ��� ���������ϴ�...\n";
                system("pause");
                return false;
            }

            delete monster;
        }
        break;
        case 5:
        {
            if (player->GetLevel() >= 1) {
                cout << "\n�������� �����մϴ�!" << endl;              
                Monster* boss = gameManager.GenerateBoss(player->GetLevel());
                gameManager.Battle(player, boss);

                if (player->isDead()) {
                    delete boss;
                    //system("pause");
                    //system("cls");
                    cout << "\n ����� �������� �й��߽��ϴ�... \n";
                    system("pause");
                    return false;
                }

                cout << "\n�����մϴ�! ������ óġ�߽��ϴ�!\n";
                system("pause");
                delete boss;
            }
            else {  
                cout << "\n������ �����Ͽ� �������� ������ �� �����ϴ�. (�ʿ� ����: 1)" << endl;
                system("pause");
            }
        }
        break;

        case 6:
            gameManager.ShowStatistics();   
            system("pause");
            break;;
        case 7:
            isRunning = false;            
            break;
        default:
            cout << "�߸��� �����Դϴ�.\n";
            system("pause");
            break;
        }
    }
    return true;
}

int main()
{
    cout << "=====================================\n";
    cout << "          <16TEAM_Text RPG>          \n";
    cout << "=====================================\n";

    system("pause");

    while (true)
    {
        system("cls");

        cout << "==============[Text RPG]=============\n";
        cout << "            1. ���ӽ���              \n";
        cout << "            2. �����ϱ�              \n";
        cout << "=====================================\n";

        int choice;
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (static_cast<start_choice>(choice))
        {
        case start_choice::START_GAME:
            CreateCharacter();

            if (!StartGameLoop()) {
                system("cls");
                cout << "=== [���� ����] ===\n";
                //system("pause");
                //system("cls");
                cout << "\n\n ���� �޴��� ���ư��ϴ�.\n\n";
                system("pause");
            }

            break;
        case start_choice::EXIT:
            return 0;
        default:
            break;
        }
    }

    return 0;
}