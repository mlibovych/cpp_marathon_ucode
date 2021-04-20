#pragma once

#include <iostream>
#include <iterator>

template<typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> output(std::cout, "\n");

    for (auto it : container) {
        *output++ = it;
    }
}