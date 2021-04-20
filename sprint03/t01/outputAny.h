#pragma once

#include <iostream>
#include <utility>

template <class Container>
void outputAny(const Container& c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << std::endl;
    }
}
