#include "MultithreadedClass.h"

int MultithreadedClass::getInt() const {
    return m_int;
}

void MultithreadedClass::add(int toAdd) {
    m_mutex.lock();
    for (int i = 0; i < toAdd; ++i) {
        m_int++;
    }
    m_mutex.unlock();
}

void MultithreadedClass::subtract(int toSub) {
    std::lock_guard<std::mutex> g(m_mutex);
    for (int i = 0; i < toSub; ++i) {
        m_int--;
    }
}
