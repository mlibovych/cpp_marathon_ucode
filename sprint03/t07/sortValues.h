#pragma once

#include <iostream>
#include <iterator>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    for (RandomAccessIterator i = begin; i != end; ++i) {
        for (RandomAccessIterator j = i; j != end; ++j) {
            if (*j < *i) {
                typename RandomAccessIterator::value_type tmp = *j;
                *j = *i;
                *i = tmp;
            }
        }
    }

    return begin;
}