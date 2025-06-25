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
        cout << "        [Ä³¸¯ÅÍ »ý¼º]         \n";
        cout << "==============================\n";

        cout << "ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ";
        getline(cin, name);

        if (name.empty() || name.find_first_not_of(' ') == string::npos) {
            cout << "\n[¿À·ù] ÀÌ¸§Àº °ø¹éÀ¸·Î¸¸ ±¸¼ºµÉ ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇØÁÖ¼¼¿ä.\n";
            system("pause");
        }
        else {
            break;
        }
    }
    system("cls");
    cout << "[" << name << "]" << "\n" << "\nÄ³¸¯ÅÍ ÀÌ¸§ µî·Ï ¿Ï·á!\n";
    cout << "\n¡Ú ========== ¡Ú ========== ¡Ú ========== ¡Ú\n";
    Character* player = Character::GetInstance(name);
    cout << "\n¡Ú ========== ¡Ú ========== ¡Ú ========== ¡Ú\n";
    system("pause");
}


bool StartGameLoop()
{
    Character* player = Character::GetInstance();

    bool isRunning = true;
    while (isRunning) {
        system("cls");
<<<<<<< HEAD
        cout << "\n===== ?ìŠ¤??RPG =====\n";
        cout << "1. ìºë¦­???¤íƒ¯ ë³´ê¸°\n";
        cout << "2. ë§ˆì„ë¡?ê°€ê¸?n";
        cout << "3. ì´ˆë³´???¬ëƒ¥??n";
        cout << "4. ?˜ì „ ?„ì „\n";
        cout << "5. ?„íˆ¬ ê¸°ë¡ ë³´ê¸°\n";        
        cout << "6. ê²Œìž„ ì¢…ë£Œ\n";
        cout << "ë©”ë‰´ë¥?? íƒ?˜ì„¸?? ";
=======
        cout << "\n===== ÅØ½ºÆ® RPG =====\n";
        cout << "1. Ä³¸¯ÅÍ ½ºÅÈ º¸±â\n";
        cout << "2. ¸¶À»·Î °¡±â\n";
        cout << "3. »ç³ÉÅÍ °¡±â\n";
        cout << "4. º¸½º µµÀü\n";
        cout << "5. °ÔÀÓ Á¾·á\n";
        cout << "¸Þ´º¸¦ ¼±ÅÃÇÏ¼¼¿ä: ";
>>>>>>> 43481e40e472be141afcbdd6726212efbad299d0

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
<<<<<<< HEAD
            
            break;
=======
        {

            if (player->GetLevel() >= 10) {
                cout << "\nº¸½º¿¡°Ô µµÀüÇÕ´Ï´Ù!!" << endl;
                Monster* boss = gameManager.GenerateBoss(player->GetLevel());
                gameManager.Battle(player, boss);
                delete boss;
            }
            else {

                cout << "\n·¹º§ÀÌ ºÎÁ·ÇÏ¿© º¸½º¿¡°Ô µµÀüÇÒ ¼ö ¾ø½À´Ï´Ù. (ÇÊ¿ä ·¹º§: 10)" << endl;
                system("pause");
            }
        }
        break;
>>>>>>> 43481e40e472be141afcbdd6726212efbad299d0
        case 5:
            gameManager.ShowStatistics();   
            system("pause");
            break;;
        case 6:
            isRunning = false;            
            break;
        default:
            cout << "Àß¸øµÈ ¼±ÅÃÀÔ´Ï´Ù.\n";
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
        cout << "            1. °ÔÀÓ½ÃÀÛ              \n";
        cout << "            2. Á¾·áÇÏ±â              \n";
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
                cout << "\n\n  °ÔÀÓ ¿À¹ö! ¸ÞÀÎ ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.\n\n";
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