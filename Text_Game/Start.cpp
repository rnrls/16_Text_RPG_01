#include <iostream>
#include <string>
#include <limits>

using namespace std;

enum class start_choice
{
    START_GAME = 1,
    EXIT = 2,
};

void CreateCharacter() {
    string name;

    while (true) {
        system("cls");
        cout << "==============================\n";
        cout << "        [캐릭터 생성]         \n";
        cout << "==============================\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    cout << "\n캐릭터 이름 등록 완료!\n";
    cout << "이름: " << name << "\n\n";

    system("pause");
}


void StartGameLoop()
{
    bool isRunning = true;
    while (isRunning) {
        system("cls");
        cout << "\n===== 텍스트 RPG =====\n";
        cout << "1. 캐릭터 스탯 보기\n";
        cout << "2. 마을로 가기\n";
        cout << "3. 초보자 사냥터\n";
        cout << "4. 던전 도전\n";
        cout << "5. 게임 종료\n";
        cout << "메뉴를 선택하세요: ";

        int Choice;
        cin >> Choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (Choice) {
        case 1:
            cout << "[캐릭터 스탯 보기] 기능 실행\n";
            break;
        case 2:
            cout << "[마을로 이동] 기능 실행\n";
            break;
        case 3:
            cout << "[초보자 사냥터 입장] 기능 실행\n";
            break;
        case 4:
            cout << "[던전 도전] 기능 실행\n";
            break;
        case 5:
            cout << "게임을 종료합니다.\n";
            isRunning = false;
            break;
        default:
            cout << "잘못된 선택입니다.\n";
            break;
        }

        system("pause");
    }
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
            StartGameLoop();
            break;
        case start_choice::EXIT:
            return 0;
        default:
            break;
        }
    }

    return 0;
}
