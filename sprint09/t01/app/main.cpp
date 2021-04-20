/* app/main.cpp */
#include <iostream>
#include "MultithreadedClass.h"
#include "Worker.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "usage: ./calc [toAdd] [toSub] [count]" << std::endl;
        return -1;
    }
    auto toAdd = std::atoi(argv[1]);
    auto toSub = std::atoi(argv[2]);
    auto count = std::atoi(argv[3]);
    MultithreadedClass obj;
    Worker worker;

    if ((toAdd < 0 || toAdd > 2000) || (toSub < 0 || toSub > 2000) ||
        (count < 5 || count > 10)) {
        std::cerr << "Incorrect values" << std::endl;
        return -1;
    }
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::add, &obj, toAdd);
    }
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::subtract, &obj, toSub);
    }
    worker.joinAllThreads();
    std::cout << obj.getInt() << std::endl;
    return 0;
}
