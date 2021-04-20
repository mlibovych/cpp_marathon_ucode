/* app/main.cpp */
#include <iostream>
#include <string>
#include <thread>
#include "Worker.h"

class Dog {
 public:
    Dog() = default;
    ~Dog() = default;

    void bark() { std::cout << "Woof!" << " [from Dog.bark]" << std::endl; }
    void howl(int n) { std::cout << std::string("Aah-o").append(n, 'o') + "h!"
            << " [from Dog.howl]" << std::endl; }
};

int main() {
    const auto strLambda = [](std::string&& str) {
        std::cout << str << " [from strLambda]" << std::endl; };
    const auto loopLambda = []() { std::cout << "lo";
        for (auto i = 0; i < 1000; i += 2)
            --i;
        std::cout << "op [from loopLambda]" << std::endl; };
    Dog fluffy;
    Worker bob;
    Worker ziggy;

    std::cout << "   +++ bob 1 start (strLambda,'Bob thread 1') +++" << std::endl;
    bob.startWorker(strLambda, "Bob thread 1");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "   --- bob join thread call ---" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    bob.joinThread();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "   +++ bob 2 start (strLambda,'Bob thread 2') +++" << std::endl;
    bob.startWorker(strLambda, "Bob thread 2");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "   +++ ziggy 1 start (strLambda,'Ziggy thread 1') +++" << std::endl;
    ziggy.startWorker(strLambda, "Ziggy thread 1");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "   +++ bob 3 start (strLambda,'Bob thread 3') +++" << std::endl;
    bob.startWorker(strLambda, "Bob thread 3");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "   +++ bob 4 start (strLambda,'Bob thread 4') +++" << std::endl;
    bob.startWorker(strLambda, "Bob thread 4");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "   +++ ziggy 2 start (strLambda,'Ziggy thread 2') +++" << std::endl;
    ziggy.startWorker(strLambda, "Ziggy thread 2");

    std::cout << "   --- bob join thread call ---" << std::endl;
    bob.joinThread();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "   +++ bob 5 start (loopLambda) +++" << std::endl;
    bob.startWorker(loopLambda);

    std::cout << "   +++ bob 6 start (&Dog::bark, &fluffy) +++" << std::endl;
    bob.startWorker(&Dog::bark, &fluffy);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "   +++ bob 7 start (&Dog::howl, &fluffy, 10) +++" << std::endl;
    bob.startWorker(&Dog::howl, &fluffy, 10);

    std::cout << "   *** loop lambda call ***" << std::endl;
    loopLambda();
    return 0;
}
