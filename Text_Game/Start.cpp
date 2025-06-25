#include <iostream>
#include <string>
#include <limits>
#include "Gamemanager.h"
#include "Character.h"

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
        cout << "        [캐릭터 생성]         \n";
        cout << "==============================\n";

        cout << "이름을 입력하세요: ";
        getline(cin, name);

        if (name.empty() || name.find_first_not_of(' ') == string::npos) {
            cout << "\n[오류] 이름은 공백으로만 구성될 수 없습니다. 다시 입력해주세요.\n";
            system("pause");
        }
        else {
            break;
        }
    }
    system("cls");
    cout << "[" << name << "]" << "\n" << "\n캐릭터 이름 등록 완료!\n";
    cout << "\n★ ========== ★ ========== ★ ========== ★\n";
    Character* player = Character::GetInstance(name);
    cout << "\n★ ========== ★ ========== ★ ========== ★\n";
    system("pause");
}


bool StartGameLoop()
{
    Character* player = Character::GetInstance();

    bool isRunning = true;
    while (isRunning) {
        system("cls");
        cout << "\n===== 텍스트 RPG =====\n";
        cout << "1. 캐릭터 스탯 보기\n";
        cout << "2. 마을로 가기\n";
        cout << "3. 사냥터 가기\n";
        cout << "4. 보스 도전\n";
        cout << "5. 게임 종료\n";
        cout << "메뉴를 선택하세요: ";

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
        {
            Monster* monster = gameManager.GenerateMonster(player->GetLevel());
            gameManager.Battle(player, monster);

            if (player->isDead()) {
                delete monster;
                return false;
            }
        }
        break;
        case 4:
        {

            if (player->GetLevel() >= 10) {
                cout << "\n보스에게 도전합니다!!" << endl;
                Monster* boss = gameManager.GenerateBoss(player->GetLevel());
                gameManager.Battle(player, boss);
                delete boss;
            }
            else {

                cout << "\n레벨이 부족하여 보스에게 도전할 수 없습니다. (필요 레벨: 10)" << endl;
                system("pause");
            }
        }
        break;
        case 5:
            isRunning = false;
            break;
        default:
            cout << "잘못된 선택입니다.\n";
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
        cout << "            1. 게임시작              \n";
        cout << "            2. 종료하기              \n";
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
                cout << "\n\n  게임 오버! 메인 메뉴로 돌아갑니다.\n\n";
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