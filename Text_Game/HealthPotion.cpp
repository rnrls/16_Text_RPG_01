#include "HealthPotion.h"
#include "Character.h"

void HealthPotion::use(Character* character) {
    character->Heal(character->GetMaxHealth());
    std::cout << "[������ ���] ü���� ��� ȸ���Ǿ����ϴ�!" << std::endl;
}
