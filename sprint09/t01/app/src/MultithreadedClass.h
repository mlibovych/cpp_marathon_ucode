/* app/src/MultithreadedClass.h */
#pragma once

#include <mutex>

class MultithreadedClass {
 public:
    MultithreadedClass() = default;
    ~MultithreadedClass() = default;

    int getInt() const;

    void add(int toAdd);

    void subtract(int toSub);

 private:
    int m_int{0};
    std::mutex m_mutex;
};

// use this file as is (without any changes)
