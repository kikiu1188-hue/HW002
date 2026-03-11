//Main.cpp

#include <iostream>

//using namespace std;

class Player {
public:
    virtual void attack() = 0;

    virtual ~Player() {}
};

class Warrior : public Player {
public:
    void attack() override {
        std::cout << "대검을 크게 휘두릅니다!" << std::endl;
    }
};

class Magician : public Player {
public:
    void attack() override {
        std::cout << "스킬 화염 마법을 발동합니다!" << std::endl;
    }
};

class Thief : public Player {
public:
    void attack() override {
        std::cout << "날카로운 독 단검을 던집니다!" << std::endl;
    }
};

class Archer : public Player {
public:
    void attack() override {
        std::cout << "활시위를 당겨 화살을 쏩니다!" << std::endl;
    }
};

int main() {
    Player* player = nullptr;
    int choice = 0;

    std::cout << "======= 직업을 선택하세요 =======" << std::endl;
    std::cout << "1.전사 / 2.마법사 / 3.도적 / 4.궁수" << std::endl;
    std::cout << "선택: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        player = new Warrior();
        break;
    case 2:
        player = new Magician();
        break;
    case 3:
        player = new Thief();
        break;
    case 4:
        player = new Archer();
        break;
    default:
        std::cout << "잘못된 번호를 입력했습니다. 프로그램이 종료됩니다." << std::endl;
        return 0;
    }

    std::cout << "\n[공격 실행!]" << std::endl;
    player->attack();

    delete player;
    player = nullptr;

    return 0;
}