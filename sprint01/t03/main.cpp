#include "src/libsrc.h"

int main() {
    std::list<Rabbit> rabbits;
    std::random_device rd;

    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        rabbits.push_back(Create(rd));
    }
    while (1) {
        std::chrono::milliseconds dura(1000);

        Print(rabbits);
        if (!rabbits.size() || rabbits.size() > 1000) {
            break;
        }
        std::this_thread::sleep_for(dura);
        Bite(rabbits);
        Reproduction(rabbits, rd);
        Death(rabbits);
        AddYear(rabbits);
        std::cout << std::endl;
    }
}
