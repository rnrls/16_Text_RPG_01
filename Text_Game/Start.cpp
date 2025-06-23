#include <iostream>

using namespace std;

enum MM_CHOICE
{
	START_GAME = 1,
	OPTION = 2,
	EXIT = 3
};

void StartGameLoop();

int main()
{
	cout << "=====================================" << endl;
	cout << "              <Text RPG>             " << endl;
	cout << "=====================================" << endl;

	system("pause");

	// Loop
	while (true)
	{
		system("cls");

		cout << "================Main menu================" << endl;
		cout << "1. 게임 시작" << endl;
		cout << "2. 나가기" << endl;
		cout << "=========================================" << endl;

		int choice;
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (static_cast<MM_CHOICE>(choice))
		{
		case MM_CHOICE::START_GAME:
			StartGameLoop();
			break;
		case MM_CHOICE::OPTION:
			// OPTION
			break;
		case MM_CHOICE::EXIT:
			break;
		default:
			break;
		}
	}

	system("cls");

	cout << "게임 종료..." << endl;
	cout << "=====================================" << endl;
	system("pause");
	return 0;
}