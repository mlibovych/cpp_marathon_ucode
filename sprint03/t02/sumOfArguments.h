#pragma once

#include <iostream>
#include <utility>

template <class Arg>
Arg sumOfArguments(Arg arg) {
    return arg;
}

template <class T, class... Ts>
T sumOfArguments(T t, Ts... args) {
    return t + sumOfArguments(args...);
}