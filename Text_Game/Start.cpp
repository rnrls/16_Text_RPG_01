#include <iostream>

using namespace std;

enum start_choice
{
	VIEW_STATS = 1,
	TOWN = 2,
	BEGINNER_FIELD = 3,
	DUNGEON = 4,
	EXIT = 5
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
		cout << "         1. ĳ���� ���� ����         " << endl;
		cout << "         2. ������ ����              " << endl;
		cout << "         3. �ʺ��� �����            " << endl;
		cout << "         4. ����                     " << endl;
		cout << "         5. ���� ����                " << endl; 
		cout << "=====================================" << endl;

		int choice;
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (static_cast<start_choice>(choice)) {
		case VIEW_STATS:
			hero->displayStatus();
			break;

		case TOWN:
			cout << ">> �������� ü���� ȸ���մϴ�." << endl;
			hero->health = hero->maxHealth;
			break;

		case BEGINNER_FIELD:
			cout << ">> �ʺ��� ����ͷ� ���!" << endl;
			GameManager::battle(hero);
			break;

		case DUNGEON:
			cout << ">> �������� �̵��մϴ�!" << endl;
			GameManager::battle(hero);
			break;

		case EXIT: 
			cout << "������ �����մϴ�. �����մϴ�!" << endl;
			return; 

		default:
			cout << ">> �߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
		}

		if (hero->health <= 0) {
			cout << hero->name << "�� ����߽��ϴ�. ���� ����!" << endl;
			break;
		}

	system("cls");

	cout << "���� ����" << endl;
	cout << "=====================================" << endl;
	system("pause");
	return 0;
}