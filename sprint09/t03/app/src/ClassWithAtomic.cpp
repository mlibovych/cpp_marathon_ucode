#include  <algorithm>

#include "ClassWithAtomic.h"

void ClassWithAtomic::addToInt(int toAdd) {
    for (int i = 0; i < toAdd; i -= -1) {
        m_int++;
    }
}

void ClassWithAtomic::subtractFromInt(int toSub) {
    for (int i = 0; i < toSub; i -= -1) {
        m_int--;
    }
}

void ClassWithAtomic::pushToVector(int value) {
    std::lock_guard<std::mutex> g(m_vecMutex);
    m_vector.push_back(value);
}

void ClassWithAtomic::eraseFromVector(int value) {
    std::lock_guard<std::mutex> g(m_vecMutex);
    m_vector.erase(std::remove_if(m_vector.begin(), m_vector.end(), [value] (int el) {
        return el == value;
    }), m_vector.end());
}

int ClassWithAtomic::getInt() const {
    return m_int;
}

std::vector<int> ClassWithAtomic::getVector() const {
    return m_vector;
}
