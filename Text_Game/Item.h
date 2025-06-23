#pragma once

#include <string>

class Character; // ���� ����

class Item {
protected:
    std::string Name;

public:
    Item(const std::string& name);
    virtual ~Item() = default;

    virtual std::string getName() const;
    virtual void use(Character* character); // �⺻ ���� (���� ���ǿ�)
};
