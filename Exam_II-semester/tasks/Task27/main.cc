#include <iostream>
#include <vector>
#include <functional>
#include <string>

struct Player {
    std::string name;
    int hp = 100;
};

void heal(Player& p, int amount) {
    p.hp += amount;
}

void damage(Player& p, int amount) {
    p.hp -= amount;
}

// TODO: implement
class Scheduler;

int main() {
    Player p{"Knight", 100};

    Scheduler s;

    s.add(damage, p, 30);
    s.add(heal, p, 10);

    s.run_all();

    std::cout << p.name << ": " << p.hp << '\n';
}
