#pragma once

#include <iostream>
#include <utility>
#include <iterator>
#include <fstream>

template <class T>
T sumFileData(const std::string& fileName) {
    T res = 0;
    std::ifstream finput(fileName);
    std::istream_iterator<T> eos;
    std::istream_iterator<T> input(finput);

    while(input != eos) {
        res += *input;
        ++input;
    }
    return res;
}
