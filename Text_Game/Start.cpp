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
		cout << "         1. 캐릭터 스텟 보기         " << endl;
		cout << "         2. 마을로 가기              " << endl;
		cout << "         3. 초보자 사냥터            " << endl;
		cout << "         4. 던전                     " << endl;
		cout << "         5. 게임 종료                " << endl; 
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
			cout << ">> 마을에서 체력을 회복합니다." << endl;
			hero->health = hero->maxHealth;
			break;

		case BEGINNER_FIELD:
			cout << ">> 초보자 사냥터로 출발!" << endl;
			GameManager::battle(hero);
			break;

		case DUNGEON:
			cout << ">> 던전으로 이동합니다!" << endl;
			GameManager::battle(hero);
			break;

		case EXIT: 
			cout << "게임을 종료합니다. 감사합니다!" << endl;
			return; 

		default:
			cout << ">> 잘못된 입력입니다. 다시 선택하세요." << endl;
		}

		if (hero->health <= 0) {
			cout << hero->name << "가 사망했습니다. 게임 오버!" << endl;
			break;
		}

	system("cls");

	cout << "게임 종료" << endl;
	cout << "=====================================" << endl;
	system("pause");
	return 0;
}