#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "CBLVector.h"

struct Drums final {
    int badum;
    double tss;
};

bool operator==(const Drums& lhs, const Drums& rhs) {
    return lhs.badum == rhs.badum && lhs.tss == rhs.tss; }

template <class Collection>
void printV(const Collection& vec, const bool printCapacity) {
    std::cout << "< ";
    for (auto &i : vec) {
        std::cout << "'" << i << "' ";
    }
    std::cout << "> s=" << vec.size();
    if (printCapacity)
        std::cout << " c=" << vec.capacity();
    std::cout << std::endl;
}

template <class T>
void insertTest(CBL::Vector<T>& vec, typename CBL::Vector<T>::iterator pos, const T& value) {
    std::cout << "\nbefore: ";
    printV(vec, false);
    auto returned_iter = vec.insert(pos, value);
    std::cout << "after:  ";
    printV(vec, false);
    if (returned_iter == vec.end())
        std::cout << "[returned end()]" << std::endl;
    else
        std::cout << "[returned iter to '" << *returned_iter << "']" << std::endl;
}

template <class T>
void erase_test(CBL::Vector<T>& vec, typename CBL::Vector<T>::iterator pos) {
    std::cout << "\nbefore: ";
    printV(vec, true);
    auto returned_iter = vec.erase(pos);
    std::cout << "after:  ";
    printV(vec, true);
    if (returned_iter == vec.end())
        std::cout << "[returned end()]" << std::endl;
    else
        std::cout << "[returned iter to '" << *returned_iter << "']" << std::endl;
}

void    algoTest() {
    CBL::Vector<int> vecOfInts{1, 2, 3, 4, 5, 5};
    std::vector<int> stdVecOfInts{1, 2, 3, 4, 5, 5};
    CBL::Vector<int> unsorted{4, 7, 2, 0, -1, 60, 20, -1, 7};
    CBL::Vector<Drums> vecOfDrums{Drums{10, 6.6}, Drums{100, 666.6}, Drums{100, 999.9}, Drums{9000, 2000.05},
                                 Drums{100500, 0.3}};

    auto it = std::find(vecOfInts.begin(), vecOfInts.end(), 3);
    auto stdIt = std::find(stdVecOfInts.begin(), stdVecOfInts.end(), 3);
    assert(*it == *stdIt && it != vecOfInts.end());
    it = std::find(vecOfInts.begin(), vecOfInts.end(), 10);
    assert(it == vecOfInts.end());

    std::remove_if(vecOfDrums.begin(), vecOfDrums.end(),
        [](Drums drum) { return drum.badum == 9000; });
    assert(std::find_if(vecOfDrums.begin(), vecOfDrums.end(),
        [](Drums drum) { return drum.badum == 9000; }) == vecOfDrums.end());

    std::sort(unsorted.begin(), unsorted.end());
    assert(std::is_sorted(unsorted.begin(), unsorted.end()));
}

void    sizeCapTest() {
    CBL::Vector<std::string> v = {"one", "two", "three"};
    std::vector<std::string> stdV = {"one", "two", "three"}; // std::vector

    std::cout << "\n------------ size and capacity ------------" << std::endl;
    printV(v, true); // < 'one' 'two' 'three' > s=3 c=3

// case: assign a vector with smaller size
    v = {"other", "values"};
    stdV = {"other", "values"};
// result: size changes to the new smaller size, but capacity stays the same (no reallocation)
    printV(v, true); // < 'other' 'values' > s=2 c=3
    assert(v.size() == stdV.size() && v.capacity() == stdV.capacity());

// case: assign a vector with larger size
    v = {"this", "vector", "is", "larger"};
    stdV = {"this", "vector", "is", "larger"};
// result: both size and capacity increase (reallocation)
    printV(v, true); // < 'this' 'vector' 'is' 'larger' > s=4 c=4
    assert(v.size() == stdV.size() && v.capacity() == stdV.capacity());

// resize
    size_t new_size = 10;
    size_t new_cap = new_size;
    printV(v, true);
    v.resize(new_size);
    assert(v.size() == new_size && v.capacity() == new_cap);
    printV(v, true);
    new_size = 3;
    v.resize(new_size);
    assert(v.size() == new_size && v.capacity() == new_cap);
    printV(v, true);

// reserve
    size_t old_size = v.size();
    new_cap = 20;
    v.reserve(new_cap);
    assert(v.capacity() == new_cap && v.size() == old_size);
    printV(v, true);
}

void    modTest() {
    CBL::Vector<std::string> vec{"one", "two", "three", "four"};
    // std::vector<std::string> stdV{"one", "two", "three", "four"};
    std::string a = "zero";
    std::string b = "five";
    std::string c = "2.5";

    {
        auto v = vec;
        auto old_size = v.size();
        auto old_cap = v.capacity();
        std::cout << "\n------------ push_back ------------" << std::endl;
        std::cout << "\nbefore: " ;
        printV(v, false);
        std::cout << "after:  ";
        v.push_back(b);
        printV(v, false);
        assert(v.size() == old_size + 1 && v.capacity() > old_cap);

        old_size = v.size();
        old_cap = v.capacity();
        std::cout << "\n------------ pop_back ------------" << std::endl;
        std::cout << "\nbefore: " ;
        printV(v, false);
        std::cout << "after:  ";
        v.pop_back();
        printV(v, false);
        assert(v.size() == old_size - 1 && v.capacity() == old_cap);
    }

    {
        auto v = vec;
        auto old_size = v.size();
        auto old_cap = v.capacity();
        std::cout << "\n------------ insert ------------" << std::endl;
        insertTest(v, v.begin(), a);
        insertTest(v, v.end(), b);
        insertTest(v, v.begin() + 3, c);
        assert(v.size() == old_size + 3 && v.capacity() > old_cap);
    }

    {
        auto v = vec;
        auto old_cap = v.capacity();
        std::cout << "\n------------ erase ------------" << std::endl;
        erase_test(v, v.begin());
        erase_test(v, v.end() - 1);
        erase_test(v, v.begin() + 1);
        // erasing elements must not reduce capacity
        assert(old_cap == v.capacity());
        std::cout << "\n------------ clear ------------" << std::endl;
        std::cout << "\nbefore: " ;
        printV(v, true);
        v.clear();
        assert(v.isEmpty() && v.begin() == v.end() && !v.size());
        // clear must not reduce capacity
        assert(old_cap == v.capacity());
        std::cout << "after:  ";
        printV(v, true);
    }
}

int main() {
    {
        CBL::Vector<int> v{5, 6, 7, 8};
        auto i = 5;
        for (auto& item : v)
            assert(i++ == item);
        assert(*v.begin() == 5 && *(v.end() - 1) == 8);
        assert(v.size() == 4 && v.capacity() >= 4);
        assert(!v.isEmpty());
        // copy
        auto cpy = v;
        assert(cpy.size() == v.size());
        for (size_t i = 0; i < cpy.size(); ++i)
            assert(cpy[i] == v[i]);
        // comparison
        assert(v == cpy);
        auto value = 3.14;
        cpy.push_back(value);
        assert(v != cpy);
    }
    {
        // constructors
        CBL::Vector<std::string> v(5, "hi");
        printV(v, true);
        CBL::Vector<float> fv{1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
        printV(fv, true);
        auto cpy = CBL::Vector<float>(fv.begin(), fv.end() - 2);
        printV(cpy, true);
    }
    modTest();
    sizeCapTest();
    algoTest();
    return 0;
}
