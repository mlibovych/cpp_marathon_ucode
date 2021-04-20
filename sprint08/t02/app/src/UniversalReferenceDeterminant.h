#pragma once

#include <iostream>
#include <string>
#include <typeinfo>
#include <cstring>

namespace UniversalReferenceDeterminant {

template <typename T>
void determineReference(T&& obj) {
    std::cout << typeid(obj).name() << " is ";
    if (std::is_lvalue_reference<T>::value) {
        std::cout << "l";
    }
    else {
        std::cout << "r";
    }
    std::cout << "-value reference" << std::endl;
}
} // end namespace UniversalReferenceDeterminant
