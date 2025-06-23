#pragma once

#include <string>

class Character; // 전방 선언

class Item {
protected:
    std::string Name;

public:
    Item(const std::string& name);
    virtual ~Item() = default;

    virtual std::string getName() const;
    virtual void use(Character* character); // 기본 구현 (힘의 포션용)
};
