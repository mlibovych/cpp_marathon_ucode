/* app/src/ClassWithAtomic.h */
#pragma once
#include <atomic>
#include <mutex>
#include <vector>

class ClassWithAtomic {
public:
    ClassWithAtomic() = default;
    ~ClassWithAtomic() = default;

    void addToInt(int toAdd);
    void subtractFromInt(int toSub);

    void pushToVector(int value);
    void eraseFromVector(int value);

    int getInt() const;
    std::vector<int> getVector() const;

private:
    std::mutex m_vecMutex;
    std::atomic<int> m_int;
    std::vector<int> m_vector;
};
