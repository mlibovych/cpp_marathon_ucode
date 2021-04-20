/* app/main.cpp */
#include <iostream>
#include "ClassWithAtomic.h"
#include "Worker.h"

int main(int argc, char **argv) {
    if (argc == 4) {
        int toAdd = std::atoi(argv[1]);
        int toSub = std::atoi(argv[2]);
        int pushSize = std::atoi(argv[3]);
        if (toAdd < 0 || toSub < 0 || pushSize < 0) {
            std::cerr << "Incorrect values\n";
            return -1;
        }

        Worker worker;
        ClassWithAtomic obj;

        worker.startNewThread(&ClassWithAtomic::addToInt, &obj, toAdd);
        worker.startNewThread(&ClassWithAtomic::subtractFromInt, &obj, toSub);

        for (auto i = 0; i < pushSize; ++i) {
            worker.startNewThread(&ClassWithAtomic::pushToVector, &obj, i);
        }
        for (auto i = 1; i <= pushSize; ++i) {
            if (i % 2 == 0) {
                worker.startNewThread(&ClassWithAtomic::eraseFromVector, &obj, i);
            }
        }
        worker.joinAllThreads();
        std::cout << "Result: " << obj.getInt() << std::endl;
        auto vec = obj.getVector();
        std::cout << "Size of vector: " << vec.size() << std::endl;

        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i != vec.size() - 1) {
                std::cout << " ";
            } else {
                std::cout << std::endl;
            }
        }
    } else {
        std::cerr << "usage: ./classWithAtomic [toAdd] [toSub] [size]\n";
        return -1;
    }
    return 0;
}
