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
        cout << "        [ĳ���� ����]         \n";
        cout << "==============================\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    cout << "\nĳ���� �̸� ��� �Ϸ�!\n";
    cout << "�̸�: " << name << "\n\n";

    system("pause");
}


void StartGameLoop()
{
    bool isRunning = true;
    while (isRunning) {
        system("cls");
        cout << "\n===== �ؽ�Ʈ RPG =====\n";
        cout << "1. ĳ���� ���� ����\n";
        cout << "2. ������ ����\n";
        cout << "3. �ʺ��� �����\n";
        cout << "4. ���� ����\n";
        cout << "5. ���� ����\n";
        cout << "�޴��� �����ϼ���: ";

        int Choice;
        cin >> Choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (Choice) {
        case 1:
            cout << "[ĳ���� ���� ����] ��� ����\n";
            break;
        case 2:
            cout << "[������ �̵�] ��� ����\n";
            break;
        case 3:
            cout << "[�ʺ��� ����� ����] ��� ����\n";
            break;
        case 4:
            cout << "[���� ����] ��� ����\n";
            break;
        case 5:
            cout << "������ �����մϴ�.\n";
            isRunning = false;
            break;
        default:
            cout << "�߸��� �����Դϴ�.\n";
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
