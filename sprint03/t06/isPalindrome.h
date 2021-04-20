#pragma once

#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    int size = std::distance(begin, end);
    int half = size / 2;

    if(!size) {
        return 0;
    }
    for (int i = half; i > 0; --i) {
        if (*begin++ != *--end) {
            return 0;
        }
    }
    return 1;
}