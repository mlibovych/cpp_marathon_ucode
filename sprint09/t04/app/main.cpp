/* app/main.cpp */
#include <iostream>
#include <string>
#include <unistd.h>
#include "AsyncWorker.h"

int main() {
    AsyncWorker worker;
    const auto mathLambda = [](int k) {
        k += 10;
        return k;
    };
    const auto appendLambda = [](std::string s) {
        s.append(" *~ this was appended ~*");
        return s;
    };

    auto fut1 = worker.startAsync(mathLambda, 1);
    auto fut2 = worker.startAsync(appendLambda, "str");
    auto res1 = fut1.get();
    auto res2 = fut2.get();

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;

    auto fut3 = worker.startAsync(mathLambda, -5);
    sleep(1);
    auto fut4 = worker.startAsync(appendLambda, "hello");
    auto res3 = fut3.get();
    auto res4 = fut4.get();
    sleep(1);
    std::cout << res3 << std::endl;
    std::cout << res4 << std::endl;
    return 0;
}
