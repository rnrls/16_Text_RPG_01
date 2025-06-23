#include <iostream>

using namespace std;

enum start_choice
{
	START_GAME = 1,
	OPTION = 2,
	EXIT = 3
};

void StartGameLoop();

int main()
{
	cout << "=====================================" << endl;
	cout << "          <16TEAM_Text RPG>          " << endl;
	cout << "=====================================" << endl;

	system("pause");

	while (true)
	{
		system("cls");

		cout << "==============[Text RPG)=============" << endl;
		cout << "            1. ���ӽ���              " << endl;
		cout << "            2. �����ϱ�              " << endl;
		cout << "=====================================" << endl;

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
			StartGameLoop();
			break;
		case start_choice::OPTION:
			break;
		case start_choice::EXIT:
			break;
		default:
			break;
		}
	}

	system("cls");

	cout << "���� ����" << endl;
	cout << "=====================================" << endl;
	system("pause");
	return 0;
}